/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <fcntl.h>
#include <errno.h>
#include <math.h>
#include <poll.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/select.h>
#include <dlfcn.h>

#include <cutils/log.h>

#include "AccGyrSensor.h"


/*****************************************************************************/

AccGyrSensor::AccGyrSensor()
: SensorBase("/dev/spich", NULL)
{
	for (int i=0; i<numSensors; i++) {
		mEnabled[i] = 1;
		mDelay[i] = -1;
	}
    memset(mPendingEvents, 0, sizeof(mPendingEvents));

    mPendingEvents[Acc].version = sizeof(sensors_event_t);
    mPendingEvents[Acc].sensor = ID_A;
    mPendingEvents[Acc].type = SENSOR_TYPE_ACCELEROMETER;
    mPendingEvents[Acc].acceleration.status = SENSOR_STATUS_ACCURACY_HIGH;

    mPendingEvents[Gyr].version = sizeof(sensors_event_t);
    mPendingEvents[Gyr].sensor = ID_GY;
    mPendingEvents[Gyr].type = SENSOR_TYPE_GYROSCOPE;
    mPendingEvents[Gyr].gyro.status = SENSOR_STATUS_ACCURACY_HIGH;

    open_device();

    setInitialStat();
}

AccGyrSensor::~AccGyrSensor()
{
	for (int i=0; i<numSensors; i++) {
		setEnable(i, 0);
	}

	close_device();
}

bool AccGyrSensor::hasPendingEvents() const 
{
    return true;
}

int AccGyrSensor::setEnable(int32_t handle, int enabled)
{
	int id = handle2id(handle);
	int err = 0;
	char buffer[2];

	switch (id) {
	case Acc:

		break;
	case Gyr:

		break;
	default:
		ALOGE("AccGyrSensor: unknown handle (%d)", handle);
		return -EINVAL;
	}


	if (mEnabled[id] <= 0) {
		if(enabled) mEnabled[id] = 1 ;
	} else if (mEnabled[id] == 1) {
		if(!enabled) mEnabled[id] = 0 ;
	}

    return err;
}

int AccGyrSensor::setDelay(int32_t handle, int64_t ns)
{
	int id = handle2id(handle);
	int err = 0;
	char buffer[32];
	int bytes;

    if (ns < -1 || 2147483647 < ns) {
		ALOGE("AccGyrSensor: invalid delay (%lld)", ns);
        return -EINVAL;
	}

	switch (id) {
	case Acc:

		break;
	case Gyr:

		break;
	default:
		ALOGE("AccGyrSensor: unknown handle (%d)", handle);
		return -EINVAL;
	}

	if (ns != mDelay[id]) {
 
			mDelay[id] = ns;
			ALOGD("AccGyrSensor: set %d to %f ms.", id , ns/1000000.0f);
	}
	
    return err;
}

int64_t AccGyrSensor::getDelay(int32_t handle)
{
	int id = handle2id(handle);
	if (id >= 0) {
		return mDelay[id];
	} else {
		return 0;
	}
}

int AccGyrSensor::getEnable(int32_t handle)
{
	int id = handle2id(handle);
	if (id >= 0) {
		return mEnabled[id];
	} else {
		return 0;
	}
}

int AccGyrSensor::readEvents(sensors_event_t* data, int count)
{
    if (count < 1)
        return -EINVAL;

    return readData(data , count) ;
}

int AccGyrSensor::handle2id(int32_t handle)
{
    switch (handle) {
        case ID_A:
			return Acc;
        case ID_GY:
			return Gyr;
		default:
			ALOGE("AccGyrSensor: unknown handle (%d)", handle);
			return -EINVAL;
    }
}


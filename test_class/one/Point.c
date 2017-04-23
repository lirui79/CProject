/////////////////////////////////////////////////////
//
//   use  test c  define class like c++  Point class
//
//   author :  lirui
//
//   history :  2012-11-16 create
//
//
/////////////////////////////////////////////

#include "Point.h"


#define   CLASS_Point_METHOD                        \
            void  PointMove(Point *_this , double x , double y) ;        \
			void  PointSet(Point *_this , double x , double y)



CLASS_Point_METHOD ;


void  PointMove(Point *_this , double x , double y)
{
	printf("Point class[%s] Move  x[%f] y[%f]!\n" , _this->GetClassName(_this) , x , y) ;
	_this->x += x ;
	_this->y += y ;
}

void  PointSet(Point *_this , double x , double y)
{
	printf("Point class[%s] Set  x[%f] y[%f]!\n" , _this->GetClassName(_this) , x , y) ;
	_this->x = x ;
	_this->y = y ;
}

const char* const Point_GetClassName(Point *_this)
{
	return "Point" ;
}

void* Point_GetSubClassPtr(Point *_this , void *_sthis)
{
	return _this ;
}

void  PointPosition(Point *_this)
{
	printf("Point class[%s] Position   x[%f] y[%f]!\n" , _this->GetClassName(_this) , _this->x , _this->y) ;
}


CONSTRUCT(Point)
{
	Construct(Shape , _this) ;	//SET_METHOD(Area , ShapeArea) ;
	SET_METHOD(Position , PointPosition) ;
	SET_METHOD(GetSubClassPtr , Point_GetSubClassPtr) ;
	SET_METHOD(GetClassName , Point_GetClassName) ;

	SET_METHOD(Move , PointMove) ;
	SET_METHOD(Set , PointSet) ;
}

DESTRUCT(Shape)
{

	Destruct(Shape , _this) ;
}



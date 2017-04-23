/////////////////////////////////////////////////////
//
//   use  test c  define class like c++  Circle class
//
//   author :  lirui
//
//   history :  2012-11-16 create
//
//
/////////////////////////////////////////////


#include "Circle.h"



#define   CLASS_Circle_METHOD                          \
            void  CircleSetRadius(Circle *_this , double r)   ; \
			void  CircleAddRadius(Circle *_this , double r)   ; \
			void  SetCircle(Circle *_this , double x , double y , double r)

CLASS_Circle_METHOD ;


void  CircleSetRadius(Circle *_this , double r)
{
	printf("Circle class[%s] SetRadius  r[%f]!\n" , _this->GetClassName(_this) , r) ;
	_this->r = r ;
}

void  CircleAddRadius(Circle *_this , double r)
{
	printf("Circle class[%s] AddRadius  r[%f]!\n" , _this->GetClassName(_this) , r) ;
	_this->r += r ;
}

void  SetCircle(Circle *_this , double x , double y , double r)
{
	printf("Circle class[%s] SetCircle  x[%f] y[%f] r[%f]!\n" , _this->GetClassName(_this) , x , y , r) ;
	_this->x = x ;
	_this->y = y ;
	_this->r = r ;
}


double  CircleArea(Circle *_this)
{
	double area = _this->r * _this->r * 3.1415926 ;
	printf("Circle class[%s] Area[%f]!\n" , _this->GetClassName(_this) , area) ;
	return area ;
}

const char* const  Circle_GetClassName(Circle *_this)
{
	return "Circle" ;
}


CONSTRUCT(Circle)
{
	Construct(Point , _this) ;
	SET_METHOD(Area , CircleArea) ;
	SET_METHOD(SetRadius , CircleSetRadius) ;
	SET_METHOD(AddRadius , CircleAddRadius) ;
	SET_METHOD(GetClassName , Circle_GetClassName) ;

	SET_METHOD(SetCircle , SetCircle) ;
}

DESTRUCT(Circle)
{

	Destruct(Circle , _this) ;
}



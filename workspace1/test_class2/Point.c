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


#define   CLASS_METHOD_Point                        \
          void  Point_Move(Point *_this , double x , double y) ;        \
		  void  Point_Set(Point *_this , double x , double y)



CLASS_METHOD_Point ;


void  Point_Move(Point *_this , double x , double y)
{
	printf("Point class[%s] Move  x[%f] y[%f]!\n" , _this->GetClassName() , x , y) ;
	_this->x += x ;
	_this->y += y ;
}

void  Point_Set(Point *_this , double x , double y)
{
	printf("Point class[%s] Set  x[%f] y[%f]!\n" , _this->GetClassName() , x , y) ;
	_this->x = x ;
	_this->y = y ;
}

const char* const Point_GetClassName()
{
	return "Point" ;
}

void* Point_GetSubClassPtr(Point *_this , void *_sthis)
{
	return _this ;
}

void  Point_Position(Point *_this)
{
	printf("Point class[%s] Position   x[%f] y[%f]!\n" , _this->GetClassName() , _this->x , _this->y) ;
}


CONSTRUCT(Point)
{
	Construct(Shape , _this) ;
	_this->x = 0.0 ;
	_this->y = 0.0 ;

	SET_METHOD(Delete , CON_CAT(Point , Delete)) ;

	SET_METHOD(Position , CON_CAT(Point , Position)) ;
	SET_METHOD(GetSubClassPtr , CON_CAT(Point , GetSubClassPtr)) ;
	SET_METHOD(GetClassName , CON_CAT(Point , GetClassName)) ;
	SET_METHOD(Move , CON_CAT(Point , Move)) ;
	SET_METHOD(Set , CON_CAT(Point , Set)) ;
}

DESTRUCT(Point)
{
	Destruct(Shape , _this) ;
}



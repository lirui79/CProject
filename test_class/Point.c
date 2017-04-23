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


CLASS_METHOD(Point , Point) ;


//METHOD_Move(Point , Point)             //
void  CON_STR_CAT(Point , _ , Move)(Point *_this , double x , double y)
{
	printf("%s class[%s] Move  x[%f] y[%f]!\n" , STRING(Point) , _this->GetClassName() , x , y) ;
	_this->x += x ;
	_this->y += y ;
}

//METHOD_Set(Point , Point)              //
void  CON_STR_CAT(Point , _ , Set)(Point *_this , double x , double y)
{
	printf("%s class[%s] Set  x[%f] y[%f]!\n" , STRING(Point) , _this->GetClassName() , x , y) ;
	_this->x = x ;
	_this->y = y ;
}


//METHOD_Position(Shape , Shape)         //
void  CON_STR_CAT(Point , _ , Position)(Point *_this)
{
	printf("%s Position class[%s]!\n" , STRING(Point) , _this->GetClassName()) ; \
}

//METHOD_GetSubClassPtr(Point , Point)       //
void* CON_STR_CAT(Point , _ , GetSubClassPtr)(Point *_this , void *_sthis)
{
	return _this ;
}

//METHOD_GetClassName(Point , Point)         //
const char* const  CON_STR_CAT(Point , _ , GetClassName)()
{
	return STRING(Point) ;
}

CONSTRUCT(Point)
{
	Construct(Shape , _this) ;
	_this->x = 0.0 ;
	_this->y = 0.0 ;

	SET_METHOD(Delete , CON_STR_CAT(Point , _ , Del)) ;

	SET_METHOD(Position , CON_STR_CAT(Point , _ , Position)) ;
	SET_METHOD(GetSubClassPtr , CON_STR_CAT(Point , _ , GetSubClassPtr)) ;
	SET_METHOD(GetClassName , CON_STR_CAT(Point , _ , GetClassName)) ;
	SET_METHOD(Move , CON_STR_CAT(Point , _ , Move)) ;
	SET_METHOD(Set , CON_STR_CAT(Point , _ , Set)) ;
}

DESTRUCT(Point)
{
	Destruct(Shape , _this) ;
}



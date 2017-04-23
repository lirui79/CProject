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



CLASS_METHOD(Circle , Circle) ;

//METHOD_GetClassName(Circle , Circle)         //
const char* const  CON_STR_CAT(Circle , _ , GetClassName)()
{
	return STRING(Circle) ;
}

//METHOD_Area(Circle , Circle)             //
double  CON_STR_CAT(Circle , _ , Area)(Circle *_this)
{
	double area = _this->r * _this->r * 3.1415926 ;
	printf("%s class[%s] Area[%f]!\n" , STRING(Circle) , _this->GetClassName() , area) ;
	return area ;
}

//METHOD_SetRadius(Circle , Circle)         //
void  CON_STR_CAT(Circle , _ , SetRadius)(Circle *_this , double r)
{
	printf("%s class[%s] SetRadius  r[%f]!\n" , STRING(Circle) , _this->GetClassName() , r) ;
	_this->r = r ;
}

//METHOD_AddRadius(Circle , Circle)         //
void  CON_STR_CAT(Circle , _ , AddRadius)(Circle *_this , double r)
{
	printf("%s class[%s] AddRadius  r[%f]!\n" , STRING(Circle) , _this->GetClassName() , r) ;
	_this->r += r ;
}

//METHOD_SetCircle(Circle , Circle)         //
void  CON_STR_CAT(Circle , _ , SetCircle)(Circle *_this , double x , double y , double r)
{
	printf("%s class[%s] SetCircle  x[%f] y[%f] r[%f]!\n" , STRING(Circle) , _this->GetClassName() , x , y , r) ;
	_this->x = x ;
	_this->y = y ;
	_this->r = r ;
}


//////////////////////////////////////////////////////////

CONSTRUCT(Circle)
{
	Construct(Point , _this) ;
	_this->r = 0.0 ;

	SET_METHOD(Delete , CON_STR_CAT(Circle , _ , Del)) ;

	SET_METHOD(SetRadius , CON_STR_CAT(Circle , _ , SetRadius)) ;
	SET_METHOD(AddRadius , CON_STR_CAT(Circle , _ , AddRadius)) ;
	SET_METHOD(GetClassName , CON_STR_CAT(Circle , _ , GetClassName)) ;
	SET_METHOD(Area , CON_STR_CAT(Circle , _ , Area)) ;
	SET_METHOD(SetCircle , CON_STR_CAT(Circle , _ , SetCircle)) ;
}

DESTRUCT(Circle)
{

	Destruct(Point , _this) ;
}



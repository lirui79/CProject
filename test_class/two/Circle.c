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


#include <Circle.h>



#define   CLASS_METHOD_Circle                          \
          void  Circle_SetRadius(Circle *_this , double r)   ; \
		  void  Circle_AddRadius(Circle *_this , double r)   ; \
		  void  Circle_SetCircle(Circle *_this , double x , double y , double r) 

CLASS_METHOD_Circle ;


void  Circle_SetRadius(Circle *_this , double r) 
{
	printf("Circle class[%s] SetRadius  r[%f]!\n" , _this->GetClassName() , r) ;	
	_this->r = r ;
}

void  Circle_AddRadius(Circle *_this , double r) 
{
	printf("Circle class[%s] AddRadius  r[%f]!\n" , _this->GetClassName() , r) ;	
	_this->r += r ;	
}

void  Circle_SetCircle(Circle *_this , double x , double y , double r) 
{
	printf("Circle class[%s] SetCircle  x[%f] y[%f] r[%f]!\n" , _this->GetClassName() , x , y , r) ;
	_this->x = x ;
	_this->y = y ;	
	_this->r = r ;
}


double  Circle_Area(Circle *_this) 
{
	double area = _this->r * _this->r * 3.1415926 ;
	printf("Circle class[%s] Area[%f]!\n" , _this->GetClassName() , area) ;
	return area ;
}

const char* const  Circle_GetClassName()
{
	return "Circle" ;	
}


CONSTRUCT(Circle)
{
	Construct(Point , _this) ;	
	_this->r = 0.0 ;
	
	SET_METHOD(Delete , CON_CAT(Circle , Delete)) ;
	
	SET_METHOD(SetRadius , CON_CAT(Circle , SetRadius)) ;	
	SET_METHOD(AddRadius , CON_CAT(Circle , AddRadius)) ;
	SET_METHOD(GetClassName , CON_CAT(Circle , GetClassName)) ;	
	SET_METHOD(Area , CON_CAT(Circle , Area)) ;
	SET_METHOD(SetCircle , CON_CAT(Circle , SetCircle)) ;	
}

DESTRUCT(Circle)
{
	
	Destruct(Point , _this) ;
}



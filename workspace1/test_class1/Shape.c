/////////////////////////////////////////////////////
//
//   use  test c  define class like c++  Shape class
//
//   author :  lirui
//
//   history :  2012-11-16 create
//
//
/////////////////////////////////////////////


#include "Shape.h"



#define   CLASS_Shape_METHOD                          \
            double  ShapeArea(Shape *_this) ;        \
			void  ShapePosition(Shape *_this)

CLASS_Shape_METHOD ;


double  ShapeArea(Shape *_this)
{
	printf("Shape Area class[%s]!\n" , _this->GetClassName(_this)) ;
	return 0.0 ;
}

void  ShapePosition(Shape *_this)
{
	printf("Shape Position class[%s]!\n" , _this->GetClassName(_this)) ;
}

const char* const Shape_GetClassName(Shape *_this)
{
	return "Shape" ;
}

void* Shape_GetSubClassPtr(Shape *_this , void *_sthis)
{
	return _this ;
}


ABSTRACT_CONSTRUCT(Shape)
{
	Construct(VirBaseClass , _this) ;
	SET_METHOD(Area , ShapeArea) ;
	SET_METHOD(Position , ShapePosition) ;
	SET_METHOD(GetSubClassPtr , Shape_GetSubClassPtr) ;
	SET_METHOD(GetClassName , Shape_GetClassName) ;
//	SET_METHOD(Delete , Shape_Delete) ;
}

ABSTRACT_DESTRUCT(Shape)
{

	Destruct(VirBaseClass , _this) ;
}




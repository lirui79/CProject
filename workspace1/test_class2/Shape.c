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


#include <Shape.h>



#define   CLASS_METHOD_Shape                          \
          double  Shape_Area(Shape *_this) ;        \
		  void  Shape_Position(Shape *_this)         
			
CLASS_METHOD_Shape ;

const char* const Shape_GetClassName() 
{
	return "Shape" ;	
}

void* Shape_GetSubClassPtr(Shape *_this , void *_sthis) 
{
	return _this ;	
}


double  Shape_Area(Shape *_this) 
{
	printf("Shape Area class[%s]!\n" , _this->GetClassName()) ;
	return 0.0 ;
}

void  Shape_Position(Shape *_this)
{
	printf("Shape Position class[%s]!\n" , _this->GetClassName()) ;
}


ABSTRACT_CONSTRUCT(Shape)
{
	Construct(IMethod , _this) ;
	SET_METHOD(Position , CON_CAT(Shape , Position)) ;
	SET_METHOD(Area , CON_CAT(Shape , Area)) ;
	SET_METHOD(GetSubClassPtr , CON_CAT(Shape , GetSubClassPtr)) ;
	SET_METHOD(GetClassName , CON_CAT(Shape , GetClassName)) ;	
}

ABSTRACT_DESTRUCT(Shape)
{
	Destruct(IMethod , _this) ;
}




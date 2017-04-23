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


CLASS_METHOD(Shape , Shape) ;


//METHOD_GetClassName(Shape , Shape)         //
const char* const  CON_STR_CAT(Shape , _ , GetClassName)() 
{
	return STRING(Shape) ;
}

//METHOD_Area(Shape , Shape)             //
double  CON_STR_CAT(Shape , _ , Area)(Shape *_this)
{
	printf("%s Area class[%s]!\n" , STRING(Shape) , _this->GetClassName()) ;
	return 0.0 ; 
}

//METHOD_Position(Shape , Shape)         //
void  CON_STR_CAT(Shape , _ , Position)(Shape *_this) 
{
	printf("%s Position class[%s]!\n" , STRING(Shape) , _this->GetClassName()) ; \
}

//METHOD_GetSubClassPtr(Shape , Shape)       //
void* CON_STR_CAT(Shape , _ , GetSubClassPtr)(Shape *_this , void *_sthis) 
{
	return _this ;
}


//////////////////////////////////////////////////

ABSTRACT_CONSTRUCT(Shape)
{
	Construct(IMethod , _this) ;
	SET_METHOD(Position , CON_STR_CAT(Shape , _ , Position)) ;
	SET_METHOD(Area , CON_STR_CAT(Shape , _ , Area)) ;
	SET_METHOD(GetSubClassPtr , CON_STR_CAT(Shape , _ , GetSubClassPtr)) ;
	SET_METHOD(GetClassName , CON_STR_CAT(Shape , _ , GetClassName)) ;	
}

ABSTRACT_DESTRUCT(Shape)
{
	Destruct(IMethod , _this) ;
}




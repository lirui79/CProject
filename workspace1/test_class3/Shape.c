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



#define   CLASS_METHOD_IMPLEMENT_Shape(TYPE)           \
	double  CON_CAT(TYPE , Area)(TYPE *_this)         \
	{  \
		printf("%s Area class[%s]!\n" , #TYPE , _this->GetClassName()) ; \
		return 0.0 ; \
	}\
	\
	void   CON_CAT(TYPE , Position)(TYPE *_this) \
	{  \
		printf("%s Position class[%s]!\n" , #TYPE , _this->GetClassName()) ; \
	}\
	\
	const char* const CON_CAT(TYPE , GetClassName)() \
	{ \
		return #TYPE ;	\
	}\
	\
	void* CON_CAT(TYPE , GetSubClassPtr)(TYPE *_this , void *_sthis)\
	{ \
		return _this ;	\
	}

	CLASS_METHOD_IMPLEMENT(Shape)(Shape) ;

//////////////////////////////////////////////////

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




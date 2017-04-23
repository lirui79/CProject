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



#define   CLASS_METHOD_IMPLEMENT_Circle(TYPE)                        \
	const char* const CON_CAT(TYPE , GetClassName)()  \
	{ \
		return #TYPE ; \
	} \
	\
	double  CON_CAT(TYPE , Area)(TYPE *_this)         \
	{  \
		printf("%s Area class[%s]!\n" , #TYPE , _this->GetClassName()) ; \
		return 0.0 ; \
	}\
	\
	void  CON_CAT(TYPE , SetRadius)(TYPE *_this , double r) \
	{ \
		printf("%s class[%s] SetRadius  r[%f]!\n" , #TYPE , _this->GetClassName() , r) ;\
		_this->r = r ; \
	}\
    \
	void  CON_CAT(TYPE , AddRadius)(TYPE *_this , double r) \
	{ \
		printf("%s class[%s] AddRadius  r[%f]!\n" , #TYPE , _this->GetClassName() , r) ;\
		_this->r += r ;	\
	}\
    \
	void  CON_CAT(TYPE , SetCircle)(TYPE *_this , double x , double y , double r)\
	{ \
		printf("%s class[%s] SetCircle  x[%f] y[%f] r[%f]!\n" , #TYPE , _this->GetClassName() , x , y , r) ;\
		_this->x = x ;\
		_this->y = y ;\
		_this->r = r ;\
	}


CLASS_METHOD_IMPLEMENT(Circle)(Circle) ;



//////////////////////////////////////////////////////////

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



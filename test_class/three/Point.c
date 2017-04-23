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

#include <Point.h>


#define   CLASS_METHOD_IMPLEMENT_Point(TYPE)                      \
	void  CON_CAT(TYPE , Move)(TYPE *_this , double x , double y)       \
	{ \
		printf("%s class[%s] Move  x[%f] y[%f]!\n" , #TYPE , _this->GetClassName() , x , y) ; \
		_this->x += x ; \
		_this->y += y ; \
	} \
	\
	void  CON_CAT(TYPE , Set)(TYPE *_this , double x , double y)  \
    { \
		printf("%s class[%s] Set  x[%f] y[%f]!\n" , #TYPE , _this->GetClassName() , x , y) ; \
		_this->x = x ; \
		_this->y = y ; \
	} \
	\
	const char* const CON_CAT(TYPE , GetClassName)()  \
	{ \
		return #TYPE ; \
	} \
	\
	void* CON_CAT(TYPE , GetSubClassPtr)(TYPE *_this , void *_sthis) \
	{ \
		return _this ;	\
	} \
    \
	void  CON_CAT(TYPE , Position)(TYPE *_this) \
	{ \
		printf("%s class[%s] Position   x[%f] y[%f]!\n" , #TYPE , _this->GetClassName() , _this->x , _this->y) ; \
	} 
			

CLASS_METHOD_IMPLEMENT(Point)(Point) ;



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



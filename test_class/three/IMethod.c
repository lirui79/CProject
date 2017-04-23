/////////////////////////////////////////////////////  
// 
//   use c  define class like c++  virtual base class  IMethod
// 
//   author :  lirui
//
//   history :  2012-11-16 create
// 
//
////////////////////////////////////////////////////

#include <IMethod.h>



#define   CLASS_METHOD_IMPLEMENT_IMethod(TYPE)   \
	void  CON_CAT(TYPE , RefCount)(TYPE *_this , int type) \
	{   \
		int nCount = 0 ;\
		if (type == 1)\
		{\
			++_this->refCount ;\
			return ;\
		}\
		nCount = --_this->refCount ;\
		\
		if (nCount != 0)\
			return ;\
		Delete(_this) ;	\
	}\
	\
	void  CON_CAT(TYPE , Delete)(TYPE *_this)  \
	{   \
	}\
	\
	void* CON_CAT(TYPE , GetSubClassPtr)(TYPE *_this , void *_sthis) \
	{ \
	    return _this ; \
	}\
	\
	const char* const CON_CAT(TYPE , GetClassName)() \
	{\
		 return #TYPE ; \
	}
	

CLASS_METHOD_IMPLEMENT(IMethod)(IMethod) ;

/////////////////////////////////////////////////////////////

ABSTRACT_CONSTRUCT(IMethod)
{
	SET_METHOD(Delete , CON_CAT(IMethod , Delete)) ;
	SET_METHOD(RefCount , CON_CAT(IMethod , RefCount)) ;
	SET_METHOD(GetSubClassPtr , CON_CAT(IMethod , GetSubClassPtr)) ;
	SET_METHOD(GetClassName , CON_CAT(IMethod , GetClassName)) ;	
	_this->refCount = 0 ;
}

ABSTRACT_DESTRUCT(IMethod)
{
}


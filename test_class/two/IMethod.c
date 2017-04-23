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

#include "IMethod.h"


#define   CLASS_METHOD_IMethod   \
	void  IMethod_RefCount(IMethod *_this , int type) ; \
	\
	void  IMethod_Delete(IMethod *_this) ; \
	\
	void* IMethod_GetSubClassPtr(IMethod *_this , void *_sthis) ;\
	\
	const char* const IMethod_GetClassName()


CLASS_METHOD_IMethod ;

void  IMethod_RefCount(IMethod *_this , int type)
{
	int nCount = 0 ;
	if (type == 1)
	{
		++_this->refCount ;
		return ;
	}
	nCount = --_this->refCount ;

	if (nCount != 0)
		return ;
	Delete(_this) ; //    _this->Delete(_this) ;
}

void  IMethod_Delete(IMethod *_this)
{	}

void* IMethod_GetSubClassPtr(IMethod *_this , void *_sthis)
{
	return _this ;
}

const char* const IMethod_GetClassName()
{
	return "IMethod" ;
}




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


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



CLASS_METHOD(IMethod , IMethod) ;

//METHOD_RefCount(IMethod , IMethod)              //
void  CON_STR_CAT(IMethod , _ , RefCount)(IMethod *_this , int type)
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
	Delete(_this) ;	
}

//METHOD_Delete(IMethod , IMethod)               //
void  CON_STR_CAT(IMethod , _ , Del)(IMethod *_this) 
{
}

//METHOD_GetSubClassPtr(IMethod , IMethod)       //
void* CON_STR_CAT(IMethod , _ , GetSubClassPtr)(IMethod *_this , void *_sthis) 
{
	return _this ;
}

//METHOD_GetClassName(IMethod , IMethod)         //
const char* const  CON_STR_CAT(IMethod , _ , GetClassName)() 
{
	return STRING(IMethod) ;
}


/////////////////////////////////////////////////////////////

ABSTRACT_CONSTRUCT(IMethod)
{
	SET_METHOD(Delete , CON_STR_CAT(IMethod , _ , Del)) ;
	SET_METHOD(RefCount , CON_STR_CAT(IMethod , _ , RefCount)) ;
	SET_METHOD(GetSubClassPtr , CON_STR_CAT(IMethod , _ , GetSubClassPtr)) ;
	SET_METHOD(GetClassName , CON_STR_CAT(IMethod , _ , GetClassName)) ;	
	_this->refCount = 0 ;
}

ABSTRACT_DESTRUCT(IMethod)
{
}


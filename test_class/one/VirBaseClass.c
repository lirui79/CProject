/////////////////////////////////////////////////////  
// 
//   use c  define class like c++  virtual base class
// 
//   author :  lirui
//
//   history :  2012-11-16 create
// 
//
////////////////////////////////////////////////////

#include <VirBaseClass.h>


void  VirBaseClass_RefCount(VirBaseClass *_this , int type) ;

void  VirBaseClass_Delete(VirBaseClass *_this) ;

void* VirBaseClass_GetSubClassPtr(VirBaseClass *_this , void *_sthis) ;

const char* const VirBaseClass_GetClassName(VirBaseClass *_this)  ;



ABSTRACT_CONSTRUCT(VirBaseClass)
{
	SET_METHOD(Delete , VirBaseClass_Delete) ;
	SET_METHOD(RefCount , VirBaseClass_RefCount) ;
	SET_METHOD(GetSubClassPtr , VirBaseClass_GetSubClassPtr) ;
	SET_METHOD(GetClassName , VirBaseClass_GetClassName) ;	
	_this->refCount = 0 ;
}

ABSTRACT_DESTRUCT(VirBaseClass)
{
}



void  VirBaseClass_RefCount(VirBaseClass *_this , int type) 
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
   // _this->Delete(_this) ;		
}

void  VirBaseClass_Delete(VirBaseClass *_this)
{	
	//Destruct(VirBaseClass , _this) ;
}

void* VirBaseClass_GetSubClassPtr(VirBaseClass *_this , void *_sthis) 
{
	return _this ;	
}

const char* const VirBaseClass_GetClassName(VirBaseClass *_this)  
{
	return "VirBaseClass" ;	
}

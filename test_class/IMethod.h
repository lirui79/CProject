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


#include <class.h>

#ifndef   DEFINE_VIRTUAL_BASE_CLASS_IMETHOD_H
#define   DEFINE_VIRTUAL_BASE_CLASS_IMETHOD_H


////////////////// fun pointer
#define   METHOD_PTR_RefCount(TYPE)             void  (*RefCount)(TYPE *_this , int type)

#define   METHOD_PTR_Delete(TYPE)               void  (*Delete)(TYPE *_this) 

#define   METHOD_PTR_GetSubClassPtr(TYPE)       void*  (*GetSubClassPtr)(TYPE *_this , void *_sthis) 

#define   METHOD_PTR_GetClassName(TYPE)         const char* const  (*GetClassName)() 


#define   CLASS_METHOD_PTR_IMethod(TYPE)             \
            METHOD_PTR(RefCount , TYPE) ;            \
			\
			METHOD_PTR(Delete , TYPE) ;              \
			\
			METHOD_PTR(GetSubClassPtr , TYPE) ;      \
			\
			METHOD_PTR(GetClassName , TYPE)   
			

/////////variable table
#define   CLASS_VARIABLE_IMethod         \
            int    refCount  
 
			
/////// inherit class method and variable
#define   INHERIT_CLASS_IMethod(TYPE)         \
            CLASS_METHOD_PTR(IMethod , TYPE) ; \
			CLASS_VARIABLE(IMethod)
			
			

ABSTRACT_CLASS(IMethod)
{
	INHERIT_CLASS(IMethod , IMethod) ;	
} ;


/// ///define fun

#define   METHOD_RefCount(NAME , TYPE)             void  CON_STR_CAT(NAME , _ , RefCount)(TYPE *_this , int type)

#define   METHOD_Delete(NAME , TYPE)               void  CON_STR_CAT(NAME , _ , Del)(TYPE *_this) 

#define   METHOD_GetSubClassPtr(NAME , TYPE)       void* CON_STR_CAT(NAME , _ , GetSubClassPtr)(TYPE *_this , void *_sthis) 

#define   METHOD_GetClassName(NAME , TYPE)         const char* const  CON_STR_CAT(NAME , _ , GetClassName)() 


#define   CLASS_METHOD_IMethod(TYPE)                 \
             METHOD_RefCount(IMethod , TYPE) ;       \
			 \
			 METHOD_Delete(IMethod , TYPE) ;         \
			 \
			 METHOD_GetSubClassPtr(IMethod , TYPE) ; \
			 \
			 METHOD_GetClassName(IMethod , TYPE) 

 
// free   _this  memory
#define  Delete(PTR)       \
	   ((IMethod*)PTR)->Delete(PTR) ;  \
//  _this = NULL 



#endif
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


#include "class.h"

#ifndef   DEFINE_VIRTUAL_BASE_CLASS_IMETHOD_H
#define   DEFINE_VIRTUAL_BASE_CLASS_IMETHOD_H



#define   CLASS_METHOD_PTR_IMethod                          \
            void  (*RefCount)(IMethod *_this , int type) ;        \
			\
			void  (*Delete)(IMethod *_this) ;                      \
			\
			void* (*GetSubClassPtr)(IMethod *_this , void *_sthis) ;              \
			\
			const char* const(*GetClassName)()




#define   CLASS_VARIABLE_IMethod         \
            int    refCount




#define   INHERIT_CLASS_IMethod         \
            CLASS_METHOD_PTR(IMethod) ; \
			CLASS_VARIABLE(IMethod)



ABSTRACT_CLASS(IMethod)
{
	INHERIT_CLASS(IMethod) ;
} ;



// free   _this  memory
#define  Delete(PTR)       \
	   ((IMethod*)PTR)->Delete(PTR) ;  \
//  _this = NULL



#endif

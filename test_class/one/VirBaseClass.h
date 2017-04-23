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


#include "class.h"

#ifndef   DEFINE_VIRTUAL_BASE_CLASS_H
#define   DEFINE_VIRTUAL_BASE_CLASS_H



#define   CLASS_VirBaseClass_METHOD_PTR                          \
            void  (*RefCount)(struct VirBaseClass *_this , int type) ;        \
			void  (*Delete)(struct VirBaseClass *_this) ;                      \
			void* (*GetSubClassPtr)(struct VirBaseClass *_this , void *_sthis) ;              \
			const char* const(*GetClassName)(struct VirBaseClass *_this)




#define   CLASS_VirBaseClass_VARIABLE         \
            int    refCount




#define   INHERIT_VirBaseClass_CLASS         \
            CLASS_METHOD_PTR(VirBaseClass) ; \
			CLASS_VARIABLE(VirBaseClass)



ABSTRACT_CLASS(VirBaseClass)
{
	INHERIT_CLASS(VirBaseClass) ;
} ;




#endif

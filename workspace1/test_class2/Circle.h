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


#include "Point.h"


#ifndef   DEFINE_CLASS_CIRCLE_H
#define   DEFINE_CLASS_CIRCLE_H




#define   CLASS_METHOD_PTR_Circle                          \
            void  (*SetRadius)(Circle *_this , double r)   ; \
			void  (*AddRadius)(Circle *_this , double r)   ;  \
			void  (*SetCircle)(Circle *_this , double x , double y , double r)



#define   CLASS_VARIABLE_Circle         \
			 double  r



#define   INHERIT_CLASS_Circle         \
			INHERIT_CLASS_Point ;	  \
            CLASS_METHOD_PTR(Circle) ; \
			CLASS_VARIABLE(Circle)





CLASS(Circle)
{
	INHERIT_CLASS(IMethod) ;
	INHERIT_CLASS(Circle) ;
} ;



#endif


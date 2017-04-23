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




#define   CLASS_Circle_METHOD_PTR                          \
            void  (*SetRadius)(struct Circle *_this , double r)   ; \
			void  (*AddRadius)(struct Circle *_this , double r)   ;  \
			void  (*SetCircle)(struct Circle *_this , double x , double y , double r)



#define   CLASS_Circle_VARIABLE         \
			 double  r



#define   INHERIT_Circle_CLASS         \
			INHERIT_Point_CLASS ;	  \
            CLASS_METHOD_PTR(Circle) ; \
			CLASS_VARIABLE(Circle)





CLASS(Circle)
{
	INHERIT_CLASS(VirBaseClass) ;
	INHERIT_CLASS(Circle) ;
} ;



#endif


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


#include "Shape.h"


#ifndef   DEFINE_CLASS_POINT_H
#define   DEFINE_CLASS_POINT_H




#define   CLASS_METHOD_PTR_Point                          \
            void  (*Move)(Point *_this , double x , double y) ;        \
			void  (*Set)(Point *_this , double x , double y)




#define   CLASS_VARIABLE_Point         \
			 double  x ; \
			 double  y




#define   INHERIT_CLASS_Point         \
            INHERIT_CLASS_Shape ;     \
            CLASS_METHOD_PTR(Point) ; \
			CLASS_VARIABLE(Point)



CLASS(Point)
{
	INHERIT_CLASS(IMethod) ;
	INHERIT_CLASS(Point) ;
} ;







#endif

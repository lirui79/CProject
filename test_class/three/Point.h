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




#define   CLASS_METHOD_PTR_Point(TYPE)                          \
            void  (*Move)(TYPE *_this , double x , double y) ;        \
			void  (*Set)(TYPE *_this , double x , double y)




#define   CLASS_VARIABLE_Point         \
			 double  x ; \
			 double  y




#define   INHERIT_CLASS_Point(TYPE)         \
            INHERIT_CLASS(Shape)(TYPE) ;     \
            CLASS_METHOD_PTR(Point)(TYPE) ; \
			CLASS_VARIABLE(Point)



CLASS(Point)
{
	INHERIT_CLASS(IMethod)(Point) ;
	INHERIT_CLASS(Point)(Point) ;
} ;







#endif

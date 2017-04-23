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




#define   CLASS_Point_METHOD_PTR                          \
            void  (*Move)(struct Point *_this , double x , double y) ;        \
			void  (*Set)(struct Point *_this , double x , double y)




#define   CLASS_Point_VARIABLE         \
			 double  x ; \
			 double  y


//
//#define   INHERIT_Point_CLASS         \
//			INHERIT_CLASS(Shape) ;	  \
//            CLASS_METHOD_PTR(Point) ; \
//			CLASS_VARIABLE(Point)


#define   INHERIT_Point_CLASS         \
            INHERIT_Shape_CLASS ;     \
            CLASS_METHOD_PTR(Point) ; \
			CLASS_VARIABLE(Point)



CLASS(Point)
{
	INHERIT_CLASS(VirBaseClass) ;
	INHERIT_CLASS(Point) ;
} ;







#endif

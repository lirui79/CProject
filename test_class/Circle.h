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


////////////////// fun pointer
#define   METHOD_PTR_SetRadius(TYPE)        void  (*SetRadius)(TYPE *_this , double r)

#define   METHOD_PTR_AddRadius(TYPE)        void  (*AddRadius)(TYPE *_this , double r)

#define   METHOD_PTR_SetCircle(TYPE)        void  (*SetCircle)(TYPE *_this , double x , double y , double r)


#define   CLASS_METHOD_PTR_Circle(TYPE)             \
            METHOD_PTR(SetRadius , TYPE) ;            \
			\
            METHOD_PTR(AddRadius , TYPE) ;            \
			\
			METHOD_PTR(SetCircle , TYPE)



#define   CLASS_VARIABLE_Circle         \
			 double  r



#define   INHERIT_CLASS_Circle(TYPE)          \
			INHERIT_CLASS_Point(TYPE) ;	      \
            CLASS_METHOD_PTR(Circle , TYPE) ; \
			CLASS_VARIABLE(Circle)





CLASS(Circle)
{
	INHERIT_CLASS(IMethod , Circle) ;
	INHERIT_CLASS(Circle , Circle) ;
} ;



/// ///define fun

#define   METHOD_SetRadius(NAME , TYPE)         void  CON_STR_CAT(NAME , _ , SetRadius)(TYPE *_this , double r)

#define   METHOD_AddRadius(NAME , TYPE)         void  CON_STR_CAT(NAME , _ , AddRadius)(TYPE *_this , double r)

#define   METHOD_SetCircle(NAME , TYPE)         void  CON_STR_CAT(NAME , _ , SetCircle)(TYPE *_this , double x , double y , double r)



#define   CLASS_METHOD_Circle(TYPE)                    \
             METHOD_Area(Circle , TYPE) ;             \
			 \
             METHOD_SetRadius(Circle , TYPE) ;        \
			 \
			 METHOD_AddRadius(Circle , TYPE) ;        \
			 \
			 METHOD_SetCircle(Circle , TYPE) ;        \
			 \
			 METHOD_GetClassName(Circle , TYPE)






#endif


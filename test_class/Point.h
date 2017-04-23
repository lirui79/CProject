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


#include <Shape.h>


#ifndef   DEFINE_CLASS_POINT_H
#define   DEFINE_CLASS_POINT_H


////////////////// fun pointer
#define   METHOD_PTR_Move(TYPE)        void  (*Move)(TYPE *_this , double x , double y) 

#define   METHOD_PTR_Set(TYPE)         void  (*Set)(TYPE *_this , double x , double y)  


#define   CLASS_METHOD_PTR_Point(TYPE)             \
            METHOD_PTR(Move , TYPE) ;            \
			\
			METHOD_PTR(Set , TYPE) 


#define   CLASS_VARIABLE_Point         \
			 double  x ; \
			 double  y 
		
			

#define   INHERIT_CLASS_Point(TYPE)          \
            INHERIT_CLASS_Shape(TYPE) ;      \
            CLASS_METHOD_PTR(Point , TYPE) ; \
			CLASS_VARIABLE(Point)			
			
			

CLASS(Point)
{
	INHERIT_CLASS(IMethod , Point) ;	
	INHERIT_CLASS(Point , Point) ;	
} ;



/// ///define fun

#define   METHOD_Move(NAME , TYPE)             void  CON_STR_CAT(NAME , _ , Move)(TYPE *_this , double x , double y) 

#define   METHOD_Set(NAME , TYPE)              void  CON_STR_CAT(NAME , _ , Set)(TYPE *_this , double x , double y) 


 
#define   CLASS_METHOD_Point(TYPE)                   \
             METHOD_Move(Point , TYPE) ;             \
			 \
			 METHOD_Set(Point , TYPE) ;         \
			 \
			 METHOD_Position(Point , TYPE) ;              \
			 \
			 METHOD_GetSubClassPtr(Point , TYPE);    \
			 \
			 METHOD_GetClassName(Point , TYPE) 







#endif 

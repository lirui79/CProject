/////////////////////////////////////////////////////  
// 
//   use  test c  define class like c++  Shape class
// 
//   author :  lirui
//
//   history :  2012-11-16 create
// 
//
/////////////////////////////////////////////


#include <IMethod.h>


#ifndef   DEFINE_CLASS_SHAPE_H
#define   DEFINE_CLASS_SHAPE_H



////////////////// fun pointer
#define   METHOD_PTR_Area(TYPE)             double  (*Area)(TYPE *_this)

#define   METHOD_PTR_Position(TYPE)         void  (*Position)(TYPE *_this) 


#define   CLASS_METHOD_PTR_Shape(TYPE)             \
            METHOD_PTR(Area , TYPE) ;            \
			\
			METHOD_PTR(Position , TYPE) 


#define   CLASS_Shape_VARIABLE
			

#define   INHERIT_CLASS_Shape(TYPE)         \
            CLASS_METHOD_PTR(Shape , TYPE) 
			
//CLASS_VARIABLE(Shape)

			

ABSTRACT_CLASS(Shape)
{
	INHERIT_CLASS(IMethod , Shape) ;	
	INHERIT_CLASS(Shape , Shape) ;	
} ;


/// ///define fun

#define   METHOD_Area(NAME , TYPE)             double  CON_STR_CAT(NAME , _ , Area)(TYPE *_this)

#define   METHOD_Position(NAME , TYPE)         void  CON_STR_CAT(NAME , _ , Position)(TYPE *_this) 


 
#define   CLASS_METHOD_Shape(TYPE)                   \
             METHOD_Area(Shape , TYPE) ;             \
			 \
			 METHOD_Position(Shape , TYPE) ;         \
			 \
			 METHOD_GetSubClassPtr(Shape , TYPE);    \
			 \
			 METHOD_GetClassName(Shape , TYPE) 





#endif 
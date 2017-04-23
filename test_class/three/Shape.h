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




#define   CLASS_METHOD_PTR_Shape(TYPE)                          \
            double  (*Area)(TYPE *_this) ;        \
			void    (*Position)(TYPE *_this)          
			
			
			

//#define   CLASS_Shape_VARIABLE        
 
			

#define   INHERIT_CLASS_Shape(TYPE)         \
            CLASS_METHOD_PTR(Shape)(TYPE) 
			//	CLASS_VARIABLE(Shape)
			
			
			
			

ABSTRACT_CLASS(Shape)
{
	INHERIT_CLASS(IMethod)(Shape) ;	
	INHERIT_CLASS(Shape)(Shape) ;	
} ;











#endif 
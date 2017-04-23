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


#include <VirBaseClass.h>


#ifndef   DEFINE_CLASS_SHAPE_H
#define   DEFINE_CLASS_SHAPE_H




#define   CLASS_Shape_METHOD_PTR                          \
            double  (*Area)(struct Shape *_this) ;        \
			void  (*Position)(struct Shape *_this)          
			
			
			

//#define   CLASS_Shape_VARIABLE        
 
			

#define   INHERIT_Shape_CLASS         \
            CLASS_METHOD_PTR(Shape) 
		
//	CLASS_VARIABLE(Shape)
			
			
			
			

ABSTRACT_CLASS(Shape)
{
	INHERIT_CLASS(VirBaseClass) ;	
	INHERIT_CLASS(Shape) ;	
} ;











#endif 
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


#include <Point.h>


#ifndef   DEFINE_CLASS_CIRCLE_H
#define   DEFINE_CLASS_CIRCLE_H




#define   CLASS_METHOD_PTR_Circle(TYPE)                          \
            void  (*SetRadius)(TYPE *_this , double r)   ; \
			void  (*AddRadius)(TYPE *_this , double r)   ;  \
			void  (*SetCircle)(TYPE *_this , double x , double y , double r) 
			
			

#define   CLASS_VARIABLE_Circle         \
			 double  r 
 
			

#define   INHERIT_CLASS_Circle(TYPE)         \
			INHERIT_CLASS(Point)(TYPE) ;	  \
            CLASS_METHOD_PTR(Circle)(TYPE) ; \
			CLASS_VARIABLE(Circle)
			
			
			
			

CLASS(Circle)
{
	INHERIT_CLASS(IMethod)(Circle) ;	
	INHERIT_CLASS(Circle)(Circle) ;	
} ;



#endif 


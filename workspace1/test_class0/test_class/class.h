/////////////////////////////////////////////////////  
// 
//   use c  define class like c++
// 
//   author :  lirui
//
//   history :  2012-11-12 create
// 
// 
//

#include <stdio.h>


#ifndef   DEFINE_C_STRUCT_USE_CPLUSPLUS_CLASS_H
#define   DEFINE_C_STRUCT_USE_CPLUSPLUS_CLASS_H


// compare big and little

  #define  MAX(a , b)          (((a) > (b)) ? (a) : (b))
  
  #define  MIN(a , b)          (((a) < (b)) ? (a) : (b))
  
  
// string  

  #define STRING(TYPE)        #TYPE
  
  #define  CONCAT(TYPE , VAR)  TYPE##VAR  
  
  #define  CON_STR_CAT(TYPE , STR , VAR) TYPE##STR##VAR



//  Abstract class define
    // not include TYPE##_Delete
	// not include TYPE##_New
	// 
   #define ABSTRACT_CLASS(TYPE)                         \
           typedef  struct TYPE  TYPE ;               \
		   void  TYPE##_Construct(TYPE *_this) ;       \
		   void  TYPE##_Destruct(TYPE *_this) ;       \
		   struct TYPE
		   
  // Abstract class constructor
  #define  ABSTRACT_CONSTRUCT(TYPE)                    \
		   void   TYPE##_Construct(TYPE *_this)   
  
  // Abstract class destructor
  #define  ABSTRACT_DESTRUCT(TYPE)                     \
		   void   TYPE##_Destruct(TYPE *_this) 



// class
  //  TYPE  class not include struct 
  //  TYPE##_New  malloc struct TYPE function
  //  TYPE##_Construct  constructor init  function
  //  TYPE##_Destruct   destructor 
  //  TYPE##_Delete     free memory
  #define  CLASS(TYPE)                                  \
           typedef  struct TYPE  TYPE ;               \
		   TYPE*   TYPE##_New() ;                       \
		   void   TYPE##_Del(TYPE *_this) ;             \
		   void   TYPE##_Construct(TYPE *_this) ;       \
		   void   TYPE##_Destruct(TYPE *_this) ;       \
		   struct TYPE
	
  // class new and constructor
  #define  CONSTRUCT(TYPE)                              \
           TYPE*  TYPE##_New()                          \
		   { \
			   struct TYPE *_this = (struct TYPE*) malloc(sizeof(struct TYPE)) ; \
			   if (_this == NULL) \
				   return NULL ; \
			   Construct(TYPE , _this) ; \
			   return _this ;   \
		   }    \
		        \
		   void TYPE##_Construct(TYPE *_this)

  
  // class delete and constructor  
  #define  DESTRUCT(TYPE)           \
           void   TYPE##_Del(TYPE *_this)  \
		   {  \
		       if (_this == NULL) \
			       return  ;   \
		       Destruct(TYPE , _this) ;\
			   free(_this) ;  \
		   }  \
		      \
		   void   TYPE##_Destruct(TYPE *_this) 


  		   
  #define  Construct(TYPE , PTR)    \
           TYPE##_Construct((TYPE*)PTR)    
		   
		   
  #define  Destruct(TYPE , PTR)     \
           TYPE##_Destruct((TYPE*)PTR) 


// malloc memory
  // malloc struct TYPE  memory
  #define  New(TYPE)                \
           TYPE##_New() 


  #define  Del(TYPE , PTR)  \
           TYPE##_Del((TYPE*)PTR) 	


 
  // set method 
  #define  SET_METHOD(PTR , FUN)   _this->PTR = FUN 
  
  
  
/////////////////////////////////////////////////////////////////
// super class 
  // 
  #define  SUPER_PTR(PTR , TYPE , VAR)   ((TYPE*)(&(PTR->VAR)))
  
  #define  SUPER_CONSTRUCT(TYPE , VAR)           \
		   TYPE##_Construct((TYPE*)(&(_this->VAR))) 

  #define  SUPER_DESTRUCT(TYPE , VAR)           \
		   TYPE##_Destruct((TYPE*)(&(_this->VAR))) 

		   
// sub class 

  #define  OFFSET_OF(TYPE , VAR)   ((size_t) &((TYPE *)0)->VAR)
  
  #define  SUB_PTR(PTR , TYPE , VAR)  ((TYPE*)((char*)PTR - (size_t)(&((TYPE*)0)->VAR)))

// 
  #define  SUPER_CLASS(TYPE , VAR)   struct TYPE  VAR 
  
//
////////////////////////////////////////////////////////////////  


//
  #define  METHOD_PTR(FUN , TYPE)           CON_STR_CAT(METHOD_PTR , _ , FUN)(TYPE)
  
  #define  CLASS_METHOD_PTR(NAME , TYPE)    CON_STR_CAT(CLASS_METHOD_PTR , _ , NAME)(TYPE)
  
  #define  CLASS_VARIABLE(TYPE)             CON_STR_CAT(CLASS_VARIABLE , _ ,TYPE)
  
  #define  INHERIT_CLASS(NAME , TYPE)       CON_STR_CAT(INHERIT_CLASS , _ , NAME)(TYPE)
  

  #define  METHOD(NAME , FUN , TYPE)        CON_STR_CAT(METHOD , _ , FUN)(NAME , TYPE)  
  
  #define  CLASS_METHOD(NAME , TYPE)        CON_STR_CAT(CLASS_METHOD , _ , NAME)(TYPE)
			  
  




#endif

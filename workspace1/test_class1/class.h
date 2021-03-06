/////////////////////////////////////////////////////  
// 
//   use c  define class like c++
// 
//   author :  lirui
//
//   history :  2012-11-12 create
// 
//
//   Example One
/////
//	#include <class.h>
//
//		CLASS(Student)
//		{
//			BASE_METHOD ;
//			int age ;
//			int grade ;
//			int number ;
//			char name[20] ;
//			
//			int (*upgrade)(Student *_this) ;
//			int (*goschool)(Student *_this , char *path) ;	
//			
//			int  (*init)(Student *_this , int Age , int Grade , int Number , char *Name) ;
//			
//			int  (*show)(Student *_this) ;
//		} ;
//
//		int Grade(Student *_this)
//		{
//			printf("student %s upgrade from %d to %d \n" , _this->name , _this->grade , _this->grade + 1) ;
//			return 0 ;	
//		}
//		
//		int GoSchool(Student *_this , char *path) 
//		{
//			printf("student %d go school path %s \n" , _this->number , path) ;
//			return 0 ;
//		}
//		
//		int Init(Student *_this , int Age , int Grade , int Number , char *Name)
//		{
//			_this->age = Age ;
//			_this->grade = Grade ;
//			_this->number = Number ;
//			strcpy(_this->name  , Name) ;
//			return 1 ;		
//		}
//		
//		int  Show(Student *_this)
//		{
//			printf("student name %s , age %d number %d grade %d \n" , _this->name , _this->age , _this->number , _this->grade) ;
//			return 0 ;
//		}
//
//		CONSTRUCT(Student) 
//		{
//			SET_METHOD(upgrade , Grade) ;
//			SET_METHOD(goschool , GoSchool) ;
//			SET_METHOD(init , Init) ;
//			SET_METHOD(show , Show) ;	
//		}
//
//		DESTRUCT(Student)
//		{
//			 if (_this == NULL)
//				 return ;
//			 return ;
//		}
//
//
//
//	int main(int argc, char **argv)
//	{
//		Student *stu ;
//		stu = New(Student) ;
//		stu->init(stu , 8 , 3 , 20121213 , "stone") ;
//		stu->show(stu) ;
//		
//		stu->upgrade(stu) ;
//		stu->goschool(stu , "13 Line") ;
//		Delete(stu) ;
//		
//		printf("hello world\n");
//		return 0;
//	}
//// 
//
//
// 
// 
//

#include <stdio.h>


#ifndef   DEFINE_CLASS_H
#define   DEFINE_CLASS_H


// malloc memory
  // malloc struct TYPE  memory
  #define  New(TYPE)                \
           TYPE##_New() 
		   
		   
  #define  Construct(TYPE , PTR)    \
           TYPE##_Construct(PTR)    
		   
		   
  #define  Destruct(TYPE , PTR)     \
           TYPE##_Destruct(PTR) 


// free memory
  #define  BASE_METHOD_PTR          \
           void  (*Delete)(void *_this) 
		   
		   
  typedef struct BASE_METHOD_CLASS
  {
	  BASE_METHOD_PTR ;
  }  BASE_METHOD_CLASS ;  
  
 
  // free   _this  memory
  #define  Delete(PTR)       \
           ((BASE_METHOD_CLASS*)PTR)->Delete(PTR) ;  \
//  _this = NULL 


  #define  Del(TYPE , PTR)  \
           TYPE##_Delete(PTR) 


//  Abstract class 
   #define ABSTRACT_CLASS(TYPE)                         \
           typedef  struct TYPE  TYPE ;               \
		   void  TYPE##_Construct(TYPE *_this) ;       \
		   void  TYPE##_Destruct(TYPE *_this) ;       \
		   struct TYPE

  #define  ABSTRACT_CONSTRUCT(TYPE)                    \
		   void   TYPE##_Construct(TYPE *_this)   
  
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
		   TYPE*  TYPE##_New() ;                        \
		   void   TYPE##_Construct(TYPE *_this) ;       \
		   void   TYPE##_Destruct(TYPE *_this) ;       \
		   void   TYPE##_Delete(TYPE *_this) ;         \
		   struct TYPE
		   


		    
  #define  CONSTRUCT(TYPE)                              \
           TYPE*  TYPE##_New()                          \
		   { \
			   struct TYPE *_this = (struct TYPE*) malloc(sizeof(struct TYPE)) ; \
			   if (_this == NULL) \
				   return NULL ; \
			   TYPE##_Construct(_this) ; \
			   SET_METHOD(Delete , TYPE##_Delete) ; \
			   return _this ;   \
		   }    \
		        \
		   void TYPE##_Construct(TYPE *_this)

  
  
  #define  DESTRUCT(TYPE)           \
           void   TYPE##_Delete(TYPE *_this)  \
		   {  \
		       if (_this == NULL) \
			       return  ;   \
		       TYPE##_Destruct(_this) ;\
			   free(_this) ;  \
		   }  \
		      \
		   void   TYPE##_Destruct(TYPE *_this) 

 
  // set method 
  #define  SET_METHOD(FUN_PTR , FUN)   _this->FUN_PTR = FUN 
  



// super class 

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
  
  
  #define  INHERIT_CLASS(TYPE)     INHERIT_##TYPE##_CLASS
  
			  
  #define  CLASS_METHOD_PTR(TYPE)  CLASS_##TYPE##_METHOD_PTR 
  
			  
  #define  CLASS_METHOD(TYPE)      CLASS_##TYPE##_METHOD
  
  
  #define  CLASS_VARIABLE(TYPE)    CLASS_##TYPE##_VARIABLE
  
  


#endif

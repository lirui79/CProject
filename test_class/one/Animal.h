/////////////////////////////////////////////////////  
// 
//   use  test c  define class like c++
// 
//   author :  lirui
//
//   history :  2012-11-15 create
// 
//
/////////////////////////////////////////////


#include <class.h>

#ifndef   DEFINE_CLASS_ANIMAL_H
#define   DEFINE_CLASS_ANIMAL_H



ABSTRACT_CLASS(INTERFACE)
{
    int (*move)(INTERFACE *_this) ;
	int (*sleep)(INTERFACE *_this) ;
    int (*eat)(INTERFACE *_this , const char *food) ;
	int (*say)(INTERFACE *_this , const char *name) ;	
	int (*fight)(INTERFACE *_this , const char *name) ;		
	void (*watch)(INTERFACE *_this , const char *name) ;	
} ;




ABSTRACT_CLASS(Animal)
{	
	char  name[1024] ;
	int   age ;
	int   id ;
	char  sex[16] ;
	
	void (*setName)(Animal *_this , const char *Name) ;
	void (*setAge)(Animal *_this , int Age) ;
	void (*setId)(Animal *_this , int Id) ;
	void (*setSex)(Animal *_this , const char *Sex) ;
	
	void (*set)(Animal *_this , const char *Name , int Age , int Id , const char *Sex) ;
	
		
	char* (*getName)(Animal *_this) ;
	int   (*getAge)(Animal *_this) ;
	int   (*getId)(Animal *_this) ;			
	char* (*getSex)(Animal *_this) ; 
} ;


CLASS(Fish)
{
	BASE_METHOD_PTR ;
	SUPER_CLASS(Animal , animal) ;
	SUPER_CLASS(INTERFACE , interface) ;	
	void (*swim)(Fish *_this) ;
} ;


CLASS(Cat)
{
	BASE_METHOD_PTR ;
	SUPER_CLASS(Animal , animal) ;
	SUPER_CLASS(INTERFACE , interface) ;	
	int (*climb)(Cat *_this , const char *Name) ;		
} ;


CLASS(Dog)
{
	BASE_METHOD_PTR ;
	SUPER_CLASS(Animal , animal) ;
	SUPER_CLASS(INTERFACE , interface) ;	
	char (*smell)(Dog *_this , const char *Name , int Id) ;
} ;





#endif

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

#include "Animal.h"
#include <stdio.h>
#include <string.h>


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

int move(INTERFACE *_this)
{
	printf("interface move!\n") ;
	return 0 ;
}

int sleep(INTERFACE *_this)
{
	printf("interface sleep!\n") ;
	return 0 ;
}

int eat(INTERFACE *_this , const char *food)
{
	printf("interface eat food:%s!\n" , food) ;
	return 0 ;
}

int say(INTERFACE *_this , const char *name)
{
	printf("interface say name:%s!\n" , name) ;
	return 0 ;
}

int fight(INTERFACE *_this , const char *name)
{
	printf("interface fight against %s!\n" , name) ;
	return 0 ;
}

void watch(INTERFACE *_this , const char *name)
{
	printf("interface watch %s!\n" , name) ;
}


ABSTRACT_CONSTRUCT(INTERFACE)
{
	SET_METHOD(move , move) ;
	SET_METHOD(sleep , sleep) ;
	SET_METHOD(eat , eat) ;
	SET_METHOD(say , say) ;
	SET_METHOD(fight , fight) ;
	SET_METHOD(watch , watch) ;
}

ABSTRACT_DESTRUCT(INTERFACE)
{
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

void setName(Animal *_this , const char *Name)
{
	if ((_this == NULL) || (Name == NULL))
		return ;
    strncpy(_this->name , Name , sizeof(_this->name)) ;
}

void setAge(Animal *_this , int Age)
{
	if (_this == NULL)
		return ;
    _this->age = Age ;
}

void setId(Animal *_this , int Id)
{
	if (_this == NULL)
		return ;
    _this->id = Id ;
}


void setSex(Animal *_this , const char *Sex)
{
	if ((_this == NULL) || (Sex == NULL))
		return ;
    strncpy(_this->sex , Sex , sizeof(_this->sex)) ;
}

void set(Animal *_this , const char *Name , int Age , int Id , const char *Sex)
{
     if (_this == NULL)
         return ;
     if (Name != NULL)
       strncpy(_this->name , Name , sizeof(_this->name)) ;
	 _this->age = Age ;
	 _this->id = Id ;
     if (Sex != NULL)
       strncpy(_this->sex , Sex , sizeof(_this->sex)) ;
}


char* getName(Animal *_this)
{
   if (_this == NULL)
       return NULL;
   return _this->name ;
}

int   getAge(Animal *_this)
{
   if (_this == NULL)
       return 0;
   return _this->age ;
}

int   getId(Animal *_this)
{
   if (_this == NULL)
       return 0;
   return _this->id ;
}

char* getSex(Animal *_this)
{
   if (_this == NULL)
       return NULL;
   return _this->sex ;
}

ABSTRACT_CONSTRUCT(Animal)
{
	SET_METHOD(setName , setName) ;
	SET_METHOD(setAge , setAge) ;
	SET_METHOD(setId , setId) ;
	SET_METHOD(setSex , setSex) ;

	SET_METHOD(set , set) ;

	SET_METHOD(getName , getName) ;
	SET_METHOD(getAge , getAge) ;
	SET_METHOD(getId , getId) ;
	SET_METHOD(getSex , getSex) ;
}

ABSTRACT_DESTRUCT(Animal)
{

}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

int fish_move(INTERFACE *_this)
{
	Fish *animal = SUB_PTR(_this , Fish , interface) ;
	printf("name %s move is swimming in water!\n" , animal->animal.getName(&animal->animal)) ;
	return 0 ;
}

int fish_sleep(INTERFACE *_this)
{
	Fish *animal = SUB_PTR(_this , Fish , interface) ;
	printf("name %s sleep in the deep water!\n" , animal->animal.name) ;
	return 0 ;
}

int fish_eat(INTERFACE *_this , const char *food)
{
	Fish *animal = SUB_PTR(_this , Fish , interface) ;
	printf("name %s eat food:%s!\n" , animal->animal.getName(&animal->animal) , food) ;
	return 0 ;
}

int fish_say(INTERFACE *_this , const char *name)
{
	Fish *animal = SUB_PTR(_this , Fish , interface) ;
	printf("name %s say name:%s!\n", animal->animal.getName(&animal->animal) , name) ;
	return 0 ;
}

int fish_fight(INTERFACE *_this , const char *name)
{
	Fish *animal = SUB_PTR(_this , Fish , interface) ;
	printf("name %s fight against %s!\n" , animal->animal.getName(&animal->animal) , name) ;
	return 0 ;
}

void fish_watch(INTERFACE *_this , const char *name)
{
	Fish *animal = SUB_PTR(_this , Fish , interface) ;
	printf("name %s watch %s!\n" , animal->animal.getName(&animal->animal) , name) ;
}

void swim(Fish *_this)
{
	printf("fish %s swimming in the river or ocean!\n" , _this->animal.getName(&_this->animal)) ;
}

CONSTRUCT(Fish)
{
	SUPER_CONSTRUCT(Animal , animal) ;
	SUPER_CONSTRUCT(INTERFACE , interface) ;

	SET_METHOD(interface.move , fish_move) ;
	SET_METHOD(interface.sleep , fish_sleep) ;
	SET_METHOD(interface.eat , fish_eat) ;
//	SET_METHOD(interface.say , fish_say) ;
	SET_METHOD(interface.fight , fish_fight) ;
	SET_METHOD(interface.watch , fish_watch) ;
	SET_METHOD(swim , swim) ;
}

DESTRUCT(Fish)
{
	SUPER_DESTRUCT(Animal , animal) ;
	SUPER_DESTRUCT(INTERFACE , interface) ;
}

//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

int cat_move(INTERFACE *_this)
{
	Cat *animal = SUB_PTR(_this , Cat , interface) ;
	printf("name %s move is running on grand!\n" , animal->animal.getName(&animal->animal)) ;
	return 0 ;
}

int cat_sleep(INTERFACE *_this)
{
	Cat *animal = SUB_PTR(_this , Cat , interface) ;
	printf("name %s sleep in the bed!\n" , animal->animal.name) ;
	return 0 ;
}

int cat_eat(INTERFACE *_this , const char *food)
{
	Cat *animal = SUB_PTR(_this , Cat , interface) ;
	printf("name %s eat food:%s!\n" , animal->animal.getName(&animal->animal) , food) ;
	return 0 ;
}

int cat_say(INTERFACE *_this , const char *name)
{
	Cat *animal = SUB_PTR(_this , Cat , interface) ;
	printf("name %s say name:%s!\n", animal->animal.getName(&animal->animal) , name) ;
	return 0 ;
}

int cat_fight(INTERFACE *_this , const char *name)
{
	Cat *animal = SUB_PTR(_this , Cat , interface) ;
	printf("name %s fight against %s!\n" , animal->animal.getName(&animal->animal) , name) ;
	return 0 ;
}

void cat_watch(INTERFACE *_this , const char *name)
{
	Cat *animal = SUB_PTR(_this , Cat , interface) ;
	printf("name %s watch %s!\n" , animal->animal.getName(&animal->animal) , name) ;
}

void climb(Cat *_this , const char *Name)
{
	printf("cat %s climbing on the %s!\n" , _this->animal.getName(&_this->animal) , Name) ;
}

CONSTRUCT(Cat)
{
	SUPER_CONSTRUCT(Animal , animal) ;
	SUPER_CONSTRUCT(INTERFACE , interface) ;

	SET_METHOD(interface.move , cat_move) ;
	SET_METHOD(interface.sleep , cat_sleep) ;
	SET_METHOD(interface.eat , cat_eat) ;
	SET_METHOD(interface.say , cat_say) ;
	SET_METHOD(interface.fight , cat_fight) ;
//	SET_METHOD(interface.watch , cat_watch) ;
	SET_METHOD(climb , climb) ;
}

DESTRUCT(Cat)
{
	SUPER_DESTRUCT(Animal , animal) ;
	SUPER_DESTRUCT(INTERFACE , interface) ;
}



//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

int dog_move(INTERFACE *_this)
{
	Dog *animal = SUB_PTR(_this , Dog , interface) ;
	printf("name %s move is running on grand!\n" , animal->animal.getName(&animal->animal)) ;
	return 0 ;
}

int dog_sleep(INTERFACE *_this)
{
	Dog *animal = SUB_PTR(_this , Dog , interface) ;
	printf("name %s sleep in the bed!\n" , animal->animal.name) ;
	return 0 ;
}

int dog_eat(INTERFACE *_this , const char *food)
{
	Dog *animal = SUB_PTR(_this , Dog , interface) ;
	printf("name %s eat food:%s!\n" , animal->animal.getName(&animal->animal) , food) ;
	return 0 ;
}

int dog_say(INTERFACE *_this , const char *name)
{
	Dog *animal = SUB_PTR(_this , Dog , interface) ;
	printf("name %s say name:%s!\n", animal->animal.getName(&animal->animal) , name) ;
	return 0 ;
}

int dog_fight(INTERFACE *_this , const char *name)
{
	Dog *animal = SUB_PTR(_this , Dog , interface) ;
	printf("name %s fight against %s!\n" , animal->animal.getName(&animal->animal) , name) ;
	return 0 ;
}

void dog_watch(INTERFACE *_this , const char *name)
{
	Dog *animal = SUB_PTR(_this , Dog , interface) ;
	printf("name %s watch %s!\n" , animal->animal.getName(&animal->animal) , name) ;
}

void smell(Dog *_this , const char *Name , int Id)
{
	printf("dog %s smell the gas on the %s  times %d!\n" , _this->animal.getName(&_this->animal) , Name , Id) ;
}

CONSTRUCT(Dog)
{
	SUPER_CONSTRUCT(Animal , animal) ;
	SUPER_CONSTRUCT(INTERFACE , interface) ;

//	SET_METHOD(interface.move , cat_move) ;
	SET_METHOD(interface.sleep , cat_sleep) ;
	SET_METHOD(interface.eat , cat_eat) ;
	SET_METHOD(interface.say , cat_say) ;
	SET_METHOD(interface.fight , cat_fight) ;
	SET_METHOD(interface.watch , cat_watch) ;
	SET_METHOD(smell , smell) ;
}

DESTRUCT(Dog)
{
	SUPER_DESTRUCT(Animal , animal) ;
	SUPER_DESTRUCT(INTERFACE , interface) ;
}

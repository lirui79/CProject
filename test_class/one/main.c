#include <stdio.h>

#include "class.h"

#include "Animal.h"

#include "Circle.h"


	CLASS(Student)
	{
		BASE_METHOD_PTR ;
		int age ;
		int grade ;
		int number ;
		char name[20] ;

		int (*upgrade)(Student *_this) ;
		int (*goschool)(Student *_this , char *path) ;

		int  (*init)(Student *_this , int Age , int Grade , int Number , char *Name) ;

		int  (*show)(Student *_this) ;
	} ;

	int Grade(Student *_this)
	{
	    printf("student %s upgrade from %d to %d \n" , _this->name , _this->grade , _this->grade + 1) ;
        return 0 ;
	}

	int GoSchool(Student *_this , char *path)
	{
		printf("student %d go school path %s \n" , _this->number , path) ;
		return 0 ;
	}

	int Init(Student *_this , int Age , int Grade , int Number , char *Name)
	{
		_this->age = Age ;
		_this->grade = Grade ;
		_this->number = Number ;
		strcpy(_this->name  , Name) ;
		return 1 ;
	}

	int  Show(Student *_this)
	{
		printf("student name %s , age %d number %d grade %d \n" , _this->name , _this->age , _this->number , _this->grade) ;
		return 0 ;
	}

	CONSTRUCT(Student)
	{
		SET_METHOD(upgrade , Grade) ;
		SET_METHOD(goschool , GoSchool) ;
		SET_METHOD(init , Init) ;
		SET_METHOD(show , Show) ;
	}

	DESTRUCT(Student)
	{
		 if (_this == NULL)
			 return ;
		 return ;
	}


//	struct Point
//	{
//		union
//		{
//			double v[3] ;
//			struct
//			{
//				double x ;
//				double y ;
//				double z ;
//			} ;
//		}
//
////		char r ;
////		char g ;
////		char b ;
//	} ;

void test_one()
{
	Student *stu ;
	stu = New(Student) ;
	stu->init(stu , 8 , 3 , 20121213 , "stone") ;
	stu->show(stu) ;

	stu->upgrade(stu) ;
	stu->goschool(stu , "13 Line") ;
	Delete(stu) ;

	printf("hello world\n");


//	struct Point point = { 0 , 1 , 3 , 250 , 100 , 10} ;
//	printf("%f , %f , %f %d %d %d\n" , point.x , point.y , point.z) ; // , point.r , point.g , point.b) ;

}

void test_two()
{
	Animal *animal ;
	INTERFACE *interface ;
	Fish *fish ;
	Cat  *cat ;
	Dog  *dog ;

	fish = New(Fish) ;
	animal = SUPER_PTR(fish , Animal , animal) ;
	animal->set(animal , "fish one" , 120 , 2001 , "female") ;

	printf("animal name [%s]  age [%d]  id [%d]  sex [%s] \n" , animal->getName(animal) , animal->getAge(animal) , animal->getId(animal) , animal->getSex(animal)) ;
	interface = SUPER_PTR(fish , INTERFACE , interface) ;
	interface->move(interface) ;
	interface->sleep(interface) ;
	interface->eat(interface , "grass") ;
	interface->say(interface , "I love you") ;
	interface->fight(interface , "another fish") ;
	interface->watch(interface , "boat") ;
	fish->swim(fish) ;


	cat = New(Cat) ;
	animal = SUPER_PTR(cat , Animal , animal) ;
	animal->set(animal , "Cat zero" , 201 , 1002 , "male") ;

	printf("animal name [%s]  age [%d]  id [%d]  sex [%s] \n" , animal->getName(animal) , animal->getAge(animal) , animal->getId(animal) , animal->getSex(animal)) ;
	interface = SUPER_PTR(cat , INTERFACE , interface) ;
	interface->move(interface) ;
	interface->sleep(interface) ;
	interface->eat(interface , "fish") ;
	interface->say(interface , "I think you") ;
	interface->fight(interface , "dog") ;
	interface->watch(interface , "fish in the water") ;

	cat->climb(cat , "the tree on the left of river") ;

	dog = New(Dog) ;
	animal = SUPER_PTR(dog , Animal , animal) ;
	animal->set(animal , "Dog two zero" , 201 , 1002 , "male") ;

	printf("animal name [%s]  age [%d]  id [%d]  sex [%s] \n" , animal->getName(animal) , animal->getAge(animal) , animal->getId(animal) , animal->getSex(animal)) ;
	interface = SUPER_PTR(dog , INTERFACE , interface) ;
	interface->move(interface) ;
	interface->sleep(interface) ;
	interface->eat(interface , "some thing") ;
	interface->say(interface , "ooh ooh beeking") ;
	interface->fight(interface , "Cat") ;
	interface->watch(interface , "the tree") ;

	dog->smell(dog , "the tree on the left of river" , 10) ;

	Delete(fish) ;
	Delete(cat) ;
	Delete(dog) ;
}

void test_three()
{
	Circle *circle ;
	Point  *point ;
	Shape  *shape ;
	VirBaseClass  *ptr ;
	double area = 0.0 ;
	circle = New(Circle) ;

	circle->Set(circle , 10.0 , 20.0) ;
	circle->Move(circle , 100.0 , 300.0) ;

	circle->Position(circle) ;

	circle->SetRadius(circle , 30.0) ;
	area = circle->Area(circle) ;

	circle->SetCircle(circle , 1.0 , 2.0 , 3.0) ;

	shape = circle ;
	shape->Position(shape) ;
	area = shape->Area(shape) ;

	point = circle ;
	point->Move(point , 1000.0 , 2000.0) ;
	point->Position(point) ;

	circle->AddRadius(circle , 50.0) ;
	area = point->Area(point) ;

	ptr = circle ;
	Delete(ptr) ;

}


int main(int argc, char **argv)
{
	test_one() ;

	test_two() ;

	return 0;
}

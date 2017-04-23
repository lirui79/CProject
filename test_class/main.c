#include "vector.h"
#include <stdio.h>


#include <Circle.h>
#include <vector.h>



CLASS_VECTOR(int) 



void test_three()
{
	Circle   *circle ;
	Point    *point ;
	Shape    *shape ;
	IMethod  *ptr ;
	double area = 0.0 ;
	circle = New(Circle) ;
	
	circle->Set(circle , 10.0 , 20.0) ;
	circle->Move(circle , 100.0 , 300.0) ;
	
	circle->Position(circle) ;
	
	circle->SetRadius(circle , 30.0) ;
	area = circle->Area(circle) ;
	
	circle->SetCircle(circle , 1.0 , 2.0 , 3.0) ;
	
	shape = (Shape*)circle ;
	shape->Position(shape) ;
	area = shape->Area(shape) ;
	
	point = (Point*)circle ;
	point->Move(point , 1000.0 , 2000.0) ;
	point->Position(point) ;
	
	circle->AddRadius(circle , 50.0) ;
	area = point->Area(point) ;
	
	ptr = (IMethod*)circle ;
//	area = ptr->Area() ;
    ptr->GetClassName() ;
	Delete(ptr) ;
		
}

#define TEST(FUN , ...)  FUN(__VA_ARGS__) 

void test_one(int a , double b , char *name)
{
     printf("a = [%d]  b = [%f]  name = [%s] \n" , a , b , name) ;	
}

void test_two()
{
	printf("test two!\n") ;
}

int main(int argc, char **argv)
{
	VECTOR(int , vInt1) ;
	vector(int) *vInt2 = vector_New(int) ;
	
	vInt1.assign(&vInt1 , 10 , 0x10) ;
	size_t sz = vInt1.size(&vInt1) ;
	vInt1.push_back(&vInt1 , 0x20) ;
	size_t sz1 = vInt1.size(&vInt1) ;
	vInt1.push_front(&vInt1 , 0x30) ;
	size_t sz2 = vInt1.size(&vInt1) ;
	vInt1.copy(&vInt1 , vInt2) ;
	
	//vector(int) vInt1 ;
//	Construct(vector(int) , &vInt1) ;
//	vector_int_Construct((vector(int) *)&vInt1) ;
//	VECTOR_CONSTRUCT(int , &vInt1) ;

	TEST(test_one , 1 , 100.0 , "I learn arg!") ;
	TEST(test_two) ;
	test_three() ;

	return 0;
}

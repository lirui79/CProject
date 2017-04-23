#include <stdio.h>


#include <Circle.h>

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
	Delete(ptr) ;
		
}


int main(int argc, char **argv)
{

	test_three() ;

	return 0;
}

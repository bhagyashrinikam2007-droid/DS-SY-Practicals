#include<iostream>
using namespace std;

void test(int *x , int y)
{  
	*x+=6;
	y*=2;
	cout<<*x <<y;
} 
int main()
{ 
	int a=5 , b=4; 
	test(&a , b);
	cout<<a<<b;
}       

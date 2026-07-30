#include<iostream>
using namespace std;

int main() 
{   
	int a=20,b=20;
	int temp=a;
	a=b;
	b=temp;
	
	cout<<"After swapping:"<<endl;
	cout<<"a="<<a<<endl;
	cout<<"b="<<b<<endl;
	
	return 0;
} 

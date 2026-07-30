#include<iostream>
using namespace std;
	
int main()
{
	int marks;
	int *ptr;
	
	ptr= &marks;
	
	cout<<"enter the students marks:";
	cin>>*ptr;
	
	cout<<"Students marks="<<*ptr<<endl;
	
	return 0;
}

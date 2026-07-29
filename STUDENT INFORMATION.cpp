#include<iostream>
using namespace std;

class Student
{
	char name[50];
	char address[50];
	int prn;
	float marks;
	
	public:
		
		void setData()
		{
			cout<<"\n Enter Students Details"<<endl;
			
			cout<<"\n Enter Student Name:";
			cin>>name;
			
			cout<<"\n Enter Student Address:";
			cin>>address;
			
			cout<<"\n Enter Srudent PRN:";
			cin>>prn;
			
			cout<<"\n Enter Student Marks:";
			cin>>marks;
		}
		
	void showData()
	{
		cout<<"\n---------STUDENT INFORMATION---------";
		
		
		cout<<"\n Student Name:"<<name<<endl; 
		cout<<"\n Student Address:"<<address<<endl; 
		cout<<"\n Student PRN:"<<prn<<endl; 
		cout<<"\n Student Marks:"<<marks<<endl;
	}
};

int main()
{
	Student s[100];
	Student *ptr;
	ptr=s;
	
	int n;
	cout<<"\n Enter No Of Students:";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		(ptr+i)->setData();
	}
	for(int i=0;i<n;i++)
	{
		(ptr+i)->showData();
	}
}
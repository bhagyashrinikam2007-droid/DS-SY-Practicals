#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node	
{
	int data ;
	Node *Previous;
    Node *Next ;
};
	
int main()
{
    Node *first = (Node*)malloc(sizeof(Node));
	first->data = 10;
	first->Previous = NULL;
	first->Next = NULL ;
	
	Node *second = (Node*)malloc(sizeof(Node));
	second->data = 40;
	second->Previous = first;
	second->Next = NULL  ;
	
	Node *third = (Node*)malloc(sizeof(Node));
    third->data = 90;
	third->Previous = second;
	third->Next = NULL ;
	
    first->Next = second;
    second->Next = third;
	
	cout<<"First Node Data="<<first->data<<endl; 
	cout<<"Second Node Data="<<second->data<<endl;
	cout<<"Third Node Data="<<third->data<<endl;
	
	free(first);
    free(second);
    free(third);
	
	
	return 0;
}

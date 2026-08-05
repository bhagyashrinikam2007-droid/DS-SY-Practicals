#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node	
{
	int data ;
	struct Node *Previous;
	struct Node *Next ;
};
	
int main()
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 10;
	newNode->Previous = NULL;
	newNode->Next = NULL;
	
	cout<<newNode->data<<endl;
	cout<<"Next Node="<<newNode ->Next<<endl;
	
	return 0;
}

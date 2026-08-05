#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node	
{
	int data ;
	struct Node *Next ;
};
	
int main()
{
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 10;
	newNode->Next = NULL;
	
	cout<<newNode->data;
	
	return 0;
}

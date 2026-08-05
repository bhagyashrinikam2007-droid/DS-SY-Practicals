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
	struct Node *head = NULL;
	
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = 30;
	newNode->Next = head;
	head = newNode;
	
	cout<<"Node created with data: " << head->data << endl;
	free(head);
	
	return 0;
}

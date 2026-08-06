#include<iostream> 
#include<stdlib.h> 
using namespace std; 

struct Node { 
    int data ; 
    struct Node *Next ; 
}; 

int main() { 
    struct Node *head = (struct Node*)malloc(sizeof(struct Node)); 
    head->data = 10; 
    head->Next = NULL; 

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = 20; 
    
    newNode->Next = NULL; 
    struct Node *temp = head; 
    
    while(temp->Next != NULL) 
    { 
        temp = temp->Next; 
    } 
    temp->Next = newNode; 
    
    struct Node *printTemp = head;
    while(printTemp != NULL) {
        cout << printTemp->data << " -> ";
        printTemp = printTemp->Next;
    }
    cout << "NULL" << endl;

    return 0; 
}
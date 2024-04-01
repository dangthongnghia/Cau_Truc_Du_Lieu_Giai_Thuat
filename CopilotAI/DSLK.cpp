#include<stdio.h>
#include<iostream>
struct node
{
    int data;
    node *next;
};
//typedef struct node node;
node* makeNode(int x){
    node *newNode = new node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}
void duyet(node *head){
    while(head != NULL){
       std:: cout << head->data << " ";
        head = head->next;      //  head->next dia chi cua node ke tiep
    }
}
// In ra so luong node trong DSLK
int count(node *head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head->next;
    }
    return count;
}
// Them 1 node vao dau  DSLK
void addHead(node **head, int x){
    node *newNode = makeNode(x);
    newNode->next = *head;
    *head = newNode;
}
// Add 1 node vao cuoi DSLK
void addTail(node **head, int x){
    node *newNode = makeNode(x);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}   

int main(){
    node *head = NULL;
    for (int i = 1; i <= 10; i++ )
{
   // addTail(&head, i);
}
    duyet(head);
    //std::cout << count(head);   
    return 0;
}


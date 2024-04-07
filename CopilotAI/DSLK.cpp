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

int NODE(){
    Node *head = NULL;
    Node *tail = NULL;
    Node *p = NULL;
    void addlist(Node **head, int x);
    int n;
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout << "Nhap gia tri cho phan tu thu " << i + 1 << ": ";
        cin >> x;
        addlist(&head, x);
    }
    p = head;
    cout << "Danh sach lien ket la: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    // Thêm 1 node vào cuối DSLK
    void addTail(Node **head, int x);
    int x;
    cout << "Nhap gia tri can them vao cuoi DSLK: ";
    cin >> x;
    addTail(&head, x);
    p = head;
    cout << "Danh sach sau khi them vao cuoi DSLK la: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
    // Thêm 1 node vào đầu DSLK
   void addHead(Node **head, int x); 
    cout << "Nhap gia tri can them vao dau DSLK: ";
    cin >> x;
    addHead(&head, x);
    p = head;
    cout << "Danh sach sau khi them vao dau DSLK la: ";
    printList(head);
    // Thêm 1 node vào giữa DSLK
    void addMid(Node **head, int x, int pos);
    int pos;
    cout << "Nhap vi tri can them vao DSLK: ";
    cin >> pos;
    cout << "Nhap gia tri can them vao DSLK: ";
    cin >> x;
    addMid(&head, x, pos);
    p = head;
    cout << "Danh sach sau khi them vao giua DSLK la: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;

    return 0;
}
// Xóa 1 node bất kì trong DSLK
void deleteNode(Node **head, int pos)
{
    if (*head == NULL)
    {
        return;
    }
    Node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        delete temp;
        return;
    }
    for (int i = 0; temp != NULL && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        return;
    }
    Node *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}
// Menu
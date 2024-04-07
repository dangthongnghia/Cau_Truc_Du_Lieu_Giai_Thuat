// danh sách liên kết đơn
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void duyet(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}
// Tạo một danh sách liên kết
void addlist(Node **head, int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Thêm 1 node vào cuối DSLK
void addTail(Node **head, int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}
// Thêm 1 node vào đầu DSLK
void addHead(Node **head, int x)
{
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = *head;
    *head = newNode;
}
// thêm 1 node vào giữa DSLK
void addMid(Node **head, int x, int pos)
{
    Node *newNode = new Node;
    newNode->data = x;
    if (pos == 0)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *temp = *head;
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
// In ra danh sach sau khi chinh sua
void printList(Node *head)
{
    Node *p = head;
    cout << "Danh sach lien ket la: ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Xoa 1 node trong DSLK
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

void Menu(Node *head)
{
    
    Node *tail = NULL;
    Node *p = NULL;
    while (true)
    {
        cout << "\n\nCHUONG TRINH QUAN LY DANH SACH LIEN KET DON";
        cout << "\n1. Nhap du lieu";
        cout << "\n2. Them 1 node vao cuoi DSLK";
        cout << "\n3. Them 1 node vao dau DSLK";
        cout << "\n4. Them 1 node vao giua DSLK";
        cout << "\n5. Xoa 1 node trong DSLK";
        cout << "\n6. In ra DSLK";
        cout << "\n0. Ket thuc";
        int luachon;
        cout << "\nNhap vao lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 6)
        {
            cout << "\nLua chon khong hop le: ";
        }
        else if (luachon == 1)
        {
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
        }
        
        else if (luachon == 2)
        {
            int x;
            cout << "\nNhap gia tri can them vao cuoi DSLK: ";
            cin >> x;
            addTail(&head, x);
        
        p = head;
        cout << "Danh sach lien ket la: ";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        
        }
        else if (luachon == 3)
        {
            int x;
            cout << "\nNhap gia tri can them vao dau DSLK: ";
            cin >> x;
            addHead(&head, x);
        cout << "Danh sach lien ket la: ";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        }
        else if (luachon == 4)
        {
            int x, pos;
            cout << "\nNhap vi tri can them vao DSLK: ";
            cin >> pos;
            cout << "\nNhap gia tri can them vao DSLK: ";
            cin >> x;
            addMid(&head, x, pos);
        cout << "Danh sach lien ket la: ";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        }
        else if (luachon == 5)
        {
            int pos;
            cout << "\nNhap vi tri can xoa trong DSLK: ";
            cin >> pos;
            deleteNode(&head, pos);
        cout << "Danh sach lien ket la: ";
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        }
        else if (luachon == 6)
        {
            cout << "\nDanh sach lien ket la: ";
            duyet(head);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    Node *head = NULL;
    Menu(head);
    return 0;
}
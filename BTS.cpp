#include <iostream>
using namespace std;


struct node
{
    /* data */
    int data; // Dữ liệu của node==> Dữ liệu mà node sẽ lưu trữ
    struct node *pleft;    // node liên kết bên trái của cây 
    struct node *pright;   // node liên kết bên phải của cây
};
typedef struct node NODE;
typedef NODE* TREE;

void addHead(node **head, int x)
{
    node *newNode = new node();
    newNode->data = x;
    newNode->pleft = NULL;
    *head = newNode;
}
// Khởi tạo cây
void KhoiTaoCay(TREE &t)
{
    t = NULL; // Cây rỗng
}
void NodeCay(TREE &t, int x)
{
    if ( t == NULL)
    {
        NODE *p = new NODE;
        p ->data = x;
        p ->pleft = NULL;
        p ->pright = NULL;
        t = p;   
    }
    else 
    {
        // Nếu phần tử thêm vào mà nhỏ hơn gốc sẽ nằm ở bên trái
        if (t ->data > x)
        {
            NodeCay(t ->pleft, x);   // duyet qua ben phai them pt x
        }
        else if (t->data < x)
        {
            NodeCay(t ->pright, x);   // duyet qua ben phai them pt x
        }
           
    }
    
    
}
// hàm lấy node trong danh sách làm gốc
void getHead(node *head)
{
    while (head != NULL && head->pleft != NULL)
    {
        head = head->pleft;
    }
    return ;
}
node *getTail(node *head)
{
    while (head != NULL && head->pright != NULL)
    {
        head = head->pright;
    }
    return head;
}
// hàm thêm node vào danh sách
void addNode(node **head, int data)
{
    node *newNode = new node();
    newNode->data = data;
    newNode->pleft = NULL;
    newNode->pright = NULL;
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        node *tail = getTail(*head);
        tail->pright = newNode;
        newNode->pleft = tail;
    }
}
// hàm duyệt danh sách từ đầu đến cuối
void duyet(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->pright;
    }
} 
// hàm xóa node khỏi danh sách
void deleteNode(node **head, node *del)
{
    if (*head == NULL || del == NULL)
    {
        return;
    }
    if (*head == del)
    {
        *head = del->pright;
    }
    if (del->pright != NULL)
    {
        del->pright->pleft = del->pleft;
    }
    if (del->pleft != NULL)
    {
        del->pleft->pright = del->pright;
    }
    delete del;
}
// hàm duyệt theo kiểu NLR
void Duyet_NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t ->data << " ";
        Duyet_NLR(t->pleft);
        Duyet_NLR(t->pright);
    }
    
}
void Duyet_LNR(TREE t)
{
    if (t != NULL)
    {
        Duyet_LNR(t->pleft);
        cout << t ->data << " ";
        Duyet_LNR(t->pright);
    }
    
}
void Duyet_LRN(TREE t)
{
    if (t != NULL)
    {
        Duyet_LRN(t->pleft);
        Duyet_LRN(t->pright);
        cout << t ->data << " ";
    }
    
}
// menu
void menu()
{
    cout << "\n\t\t\t\tMENU\n";
    cout << "1. Khoi tao cac node cho cay\n";
    cout << "2. Them node vao cay \n";
    cout << "3. Xoa node khoi cay  \n";
    cout << "4. In ra danh sach cac node trong cay\n";
    cout << "5. Duyet cay theo NLR\n";
    cout << "6. Duyet cay theo LNR \n";
    cout << "7. Duyet cay theo LRN\n";
    cout << "8. Lay node lam goc\n";
    cout << "9. Thoat\n";
}

int main()
{
    TREE t;
    KhoiTaoCay(t);
    int luachon;
    do
    {
        menu();
        cout << "Nhap lua chon: ";
        cin >> luachon;
        if (luachon < 0 || luachon > 9)
        {
            cout << "Lua chon khong hop le: ";
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
                NodeCay(t, x);
            }
        }
        else if (luachon == 2)
        {
                int x;
        cout << "\n Lay node bat ki lam goc: ";
        cin >> x;
        NodeCay(t, x);
        }
        else if (luachon == 3)
        {
            int x;
            cout << "Nhap gia tri can xoa khoi cay: ";
            cin >> x;
            NodeCay(t, x);
        }
        else if (luachon == 4)
        {
            cout << "Danh sach cac node trong cay la: ";
            Duyet_NLR(t);
        }
        else if (luachon == 5)
        {
            cout << "Duyet cay theo NLR: ";
            Duyet_NLR(t);
        }
        else if (luachon == 6)
        {
            cout << "Duyet cay theo LNR: ";
            Duyet_LNR(t);
        }
        else if (luachon == 7)
        {
            cout << "Duyet cay theo LRN: ";
            Duyet_LRN(t);
        }
        else if (luachon == 8)
        {
            int x;
            cout << "Nhap gia tri can them vao cay: ";
            cin >> x;
            NodeCay(t, x);
        
        }
        else
        {
            cout << "Tam biet!";
        }
    } while (luachon != 0);
    return 0;
}
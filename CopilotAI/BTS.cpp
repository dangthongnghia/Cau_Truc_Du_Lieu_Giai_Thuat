#include <iostream>
using namespace std;
void NhapMang()
{
int n;
cout << "Nhap so phan tu cua day so: ";
cin >> n;
int a[n];
for (int i = 0; i < n; i++) {
cout << "Nhap phan tu thu " << i << ": ";
cin >> a[i];
}
cout << "Day so nguyen vua nhap la: ";
for (int i = 0; i < n; i++) {
cout << a[i] << " ";
}
cout << endl;
}

struct node
{
    /* data */
    int data; // Dữ liệu của node==> Dữ liệu mà node sẽ lưu trữ
    struct node *pleft;    // node liên kết bên trái của cây 
    struct node *pright;   // node liên kết bên phải của cây
};
typedef struct node NODE;
typedef NODE* TREE;

// Khởi tạo cây
void KhoiTaoCay(TREE &t)
{
    t = NULL; // Cây rỗng
}
void ThemNodeVaoCay(TREE &t, int x)
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
            ThemNodeVaoCay(t ->pleft, x);   // duyet qua ben phai them pt x
        }
        else if (t->data < x)
        {
            ThemNodeVaoCay(t ->pright, x);   // duyet qua ben phai them pt x
        }
           
    }
    
}


// ham xuat cay nhi phan theo NLR
void Duyet_NLR(TREE t)
{
    if (t != NULL)
    {
        cout << t ->data << " ";
        Duyet_NLR(t->pleft);
        Duyet_NLR(t->pright);
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

void Duyet_NRL(TREE t)
{
    if (t != NULL)
    {
        cout << t ->data << " ";
        Duyet_NRL(t->pright);
        Duyet_NRL(t->pleft);
    }
    
}
void Menu(TREE &t)
{
    while (true)
    {

cout << "\n1. Nhap vào mot day so bat ki: ";
cout << "\n2. Chon so muon lam goc: ";
cout << "\n3. Xuat du lieu cay kieu NLR";
cout << "\n4. Xuat du lieu cay kieu LRN";
cout << "\n5. Xuat du lieu cay kieu NRL";
cout << "\n0. Ket thuc";

int luachon;
cout << "\n Nhap vao lua chon: ";
cin >> luachon;
if (luachon < 0 || luachon > 6)
{
  cout <<"\n Lua chon khong hop le: \n";
  
}

else if(luachon == 1)
{
int n; // đcm nhớ sửa ở đây 
cout << "Nhap so phan tu cua day so: ";
cin >> n;
int a[n];
for (int i = 0; i < n; i++) {
cout << "Nhap phan tu thu " << i << ": ";
cin >> a[i];
}
cout << "Day so nguyen vua nhap la: ";
for (int i = 0; i < n; i++) {
cout << a[i] << " ";
}
cout << endl;


}

else if (luachon == 2) // m nhớ sửa ở đây luôn 
// nhớ tạo mảng và thêm mảng
{
    
    int x;
    cout << "\n Lay so bat ki trong mang: ";
    cin >> x;
    ThemNodeVaoCay(t, x);
}
else if (luachon == 3)
{
    cout << "\n Duyet qua NLR:";
    Duyet_NLR(t);
   
}
else if (luachon == 4)
{
    cout << "\n Duyet qua LRN:";
    Duyet_LRN(t);
}
else if (luachon == 5)
{
    cout << "\n Duyet qua NRL:";
    Duyet_NRL(t);
   
}
else 
{
    break;
}

    }
}

int main()
{
TREE t;
KhoiTaoCay(t);
Menu(t);

return 0;
}
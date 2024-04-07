#include <iostream>
#include <cstdlib>
using namespace std;
struct Node {
    int key;    // Dữ liệu của node==> Dữ liệu mà node sẽ lưu trữ
    Node* left;  // node liên kết bên trái của cây 
    Node* right; // node liên kết bên phải của cây
};

Node* newNode(int item) {
    Node* temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)  // Nếu phần tử thêm vào mà nhỏ hơn gốc sẽ nằm ở bên trái
        node->left = insert(node->left, key);
    else if (key > node->key) // Nếu phần tử thêm vào mà lớn hơn gốc sẽ nằm ở bên phải
        node->right = insert(node->right, key);

    return node;
}

// Add thêm nút vào cây
Node* addNode(Node* root, int data)
{
    if (root == NULL)
    {
        root = new Node;
        root->key = data;
        root->left = root->right = NULL;
    }
    else if (data < root->key)
    {
        root->left = addNode(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = addNode(root->right, data);
    }
    return root;
}
// Xóa nút bất kì khỏi cây
Node* deleteNode(Node* root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->key)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->key)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* temp = root->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
// In ra cac node trong cay



void NLR(Node* root) {
    if (root != NULL) {
        std::cout << root->key << std::endl;
        NLR(root->left);
        NLR(root->right);
    }
}
void LRN(Node* root) {
    if (root != NULL) {
        NLR(root->left);
        NLR(root->right);
        std::cout << root->key << std::endl;
    }
}

void LNR(Node* root) {
    if (root != NULL) {
        LNR(root->left);
        std::cout << root->key << std::endl;
        LNR(root->right);
    }
}
// Tạo một mảng cho người dùng nhập vào và chọn làm root gốc
void TaoMang(int* arr, int n, int chosen) {
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == chosen) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = chosen;
    }
}

void Menu(Node* root)
{
    while (true)
    {
    system("cls");
cout << "\n1. Nhap vao mot day so bat ki: ";
// cout << "\n2. Nhap du lieu";
cout << "\n2. Xuat du lieu cay kieu NLR";
cout << "\n3. Xuat du lieu cay kieu LRN";
cout << "\n4. Xuat du lieu cay kieu LRN";
cout << "\n5. Them nut vao cay";
cout << "\n6. Xoa 1 node trong cay";
cout << "\n0. Ket thuc";

int luachon;
cout << "\n Nhap vao lua chon: ";
cin >> luachon;
if (luachon < 0 || luachon > 7)
{
    cout <<"\n Lua chon khong hop le: \n";
    system("pause");
}

else if(luachon == 1)
{
    int n;
    cout << "\nTao so nut co trong cay: ";
    cin >> n;

    int* arr = new int[n];
    cout << "\nNhap cac nut cua cay: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int chosen;
    cout << "\nNhap so de lam root: ";
    cin >> chosen;
    TaoMang(arr, n, chosen);

    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }
}

else if (luachon == 2)
{   
    cout << "\n Duyet qua NLR: \n";
    NLR(root);
    system("pause");
}
else if (luachon == 3)
{   
    cout << "\n Duyet qua LRN:\n";
    LRN(root);
    system("pause");
}
else if (luachon == 4)
{   
    cout << "\n Duyet qua LNR:\n";
    LNR(root);
    system("pause");
}
else if (luachon == 5)
{
    int x;
    cout << "\nNhap gia tri can them vao cay: ";
    cin >> x;
    root = addNode(root, x);
}
else if (luachon == 6)
{
    int x;
    cout << "\nNhap gia tri can xoa khoi cay: ";
    cin >> x;
    root = deleteNode(root, x);
}
else if (luachon == 0)
{
    break;
}
    }
}
int main() 
{
Node* root = NULL;

NLR(root);
LRN(root);
LNR(root);
Menu(root);
system("pause");

return 0;
}
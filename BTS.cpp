class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

def insert(node, key):
    if node is None:
        return Node(key)

    if key < node.key:
        node.left = insert(node.left, key)
    elif key > node.key:
        node.right = insert(node.right, key)

    return node

def addNode(root, data):
    if root is None:
        return Node(data)

    if data < root.key:
        root.left = addNode(root.left, data)
    elif data > root.key:
        root.right = addNode(root.right, data)

    return root

def deleteNode(root, data):
    if root is None:
        return root

    if data < root.key:
        root.left = deleteNode(root.left, data)
    elif data > root.key:
        root.right = deleteNode(root.right, data)
    else:
        if root.left is None:
            temp = root.right
            del root
            return temp
        elif root.right is None:
            temp = root.left
            del root
            return temp
        temp = root.right
        while temp.left is not None:
            temp = temp.left
        root.key = temp.key
        root.right = deleteNode(root.right, temp.key)

    return root

def NLR(root):
    if root is not None:
        print(root.key)
        NLR(root.left)
        NLR(root.right)

def LRN(root):
    if root is not None:
        LRN(root.left)
        LRN(root.right)
        print(root.key)

def LNR(root):
    if root is not None:
        LNR(root.left)
        print(root.key)
        LNR(root.right)

def TaoMang(arr, n, chosen):
    index = -1
    for i in range(n):
        if arr[i] == chosen:
            index = i
            break
    if index != -1:
        for i in range(index, 0, -1):
            arr[i] = arr[i - 1]
        arr[0] = chosen

def Menu(root):
    while True:
        print("\n1. Nhap vao mot day so bat ki: ")
        print("2. Xuat du lieu cay kieu NLR")
        print("3. Xuat du lieu cay kieu LRN")
        print("4. Xuat du lieu cay kieu LNR")
        print("5. Them nut vao cay")
        print("6. Xoa 1 node trong cay")
        print("0. Ket thuc")

        luachon = int(input("\nNhap vao lua chon: "))
        if luachon < 0 or luachon > 7:
            print("\nLua chon khong hop le\n")
            input("Press Enter to continue...")
        elif luachon == 1:
            n = int(input("\nTao so nut co trong cay: "))
            arr = []
            print("\nNhap cac nut cua cay: ")
            for i in range(n):
                arr.append(int(input()))
            chosen = int(input("\nNhap so de lam root: "))
            TaoMang(arr, n, chosen)
            for i in range(n):
                root = insert(root, arr[i])
        elif luachon == 2:
            print("\nDuyet qua NLR: ")
            NLR(root)
            input("Press Enter to continue...")
        elif luachon == 3:
            print("\nDuyet qua LRN: ")
            LRN(root)
            input("Press Enter to continue...")
        elif luachon == 4:
            print("\nDuyet qua LNR: ")
            LNR(root)
            input("Press Enter to continue...")
        elif luachon == 5:
            x = int(input("\nNhap gia tri can them vao cay: "))
            root = addNode(root, x)
        elif luachon == 6:
            x = int(input("\nNhap gia tri can xoa khoi cay: "))
            root = deleteNode(root, x)
        elif luachon == 0:
            break

if __name__ == "__main__":
    root = None
    NLR(root)
    LRN(root)
    LNR(root)
    Menu(root)
    input("Press Enter to continue...")

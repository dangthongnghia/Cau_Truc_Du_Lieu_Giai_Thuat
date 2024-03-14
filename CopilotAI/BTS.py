class Node:
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key



class BST:
    def __init__(self):
        self.root = None

    def insert(self, key):
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)

    def _insert(self, node, key):
        if key < node.val:
            if node.left is None:
                node.left = Node(key)
            else:
                self._insert(node.left, key)
        elif key > node.val:
            if node.right is None:
                node.right = Node(key)
            else:
                self._insert(node.right, key)

    def preorder(self, node):
        if node:
            print(node.val)
            self.preorder(node.left)
            self.preorder(node.right)

    def postorder(self, node):
        if node:
            self.postorder(node.left)
            self.postorder(node.right)
            print(node.val)

    def inorder(self, node):
        if node:
            self.inorder(node.left)
            print(node.val)
            self.inorder(node.right)


bst = BST()

def menu():
    while True:
        import os 
        os.system('cls')
        print("1. Nhập dữ liệu cho cây")
        print("2. Duyệt theo kiểu NLR")
        print("3. Duyệt theo kiểu LRN")
        print("4. Duyệt theo kiểu LNR")
        print("5. Exit")
        choice = int(input("Nhập vào lựa chọn: "))
        if choice == 1:
             values = input("Nhập vào một dãy số tạo nên cây: ").split()
             for value in values:
                bst.insert(int(value))
            
        elif choice == 2:
            print("Duyệt theo kiểu NLR:")
            bst.preorder(bst.root)
            os.system('pause')
        elif choice == 3:
            print("Duyệt theo kiểu LRN:")
            bst.postorder(bst.root)
            os.system('pause')
        elif choice == 4:
            print("Duyệt theo kiểu LNR:")
            bst.inorder(bst.root)
            os.system('pause')
        elif choice == 5:
            break
        else:
            print("Invalid choice")



menu()

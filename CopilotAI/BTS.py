class Node:                    # Class Node của cây nhị phân
    def __init__(self, key):
        self.left = None
        self.right = None
        self.val = key



class CayNhiPhan:                           # Class cây nhị phân
    def __init__(self):
        self.root = None

    def insert(self, key):                      # Hàm chèn giá trị vào cây
        if self.root is None:
            self.root = Node(key)
        else:
            self._insert(self.root, key)

    def _insert(self, node, key):                       # Hàm chèn giá trị vào cây
        if key < node.val:                      # Nếu giá trị cần chèn nhỏ hơn giá trị của node
            if node.left is None:                    
                node.left = Node(key)           # Nếu node.left là None thì chèn giá trị vào đây
            else:                               
                self._insert(node.left, key)    # Nếu không thì gọi đệ quy với node.left
        elif key > node.val:                    # Nếu giá trị cần chèn lớn hơn giá trị của node
            if node.right is None:              # Nếu node.right là None thì chèn giá trị vào đây
                node.right = Node(key)
            else:
                self._insert(node.right, key)   

    def Duyet_NLR(self, node):                  # Duyệt theo kiểu NLR
        if node:
            print(node.val)
            self.Duyet_NLR(node.left)
            self.Duyet_NLR(node.right)

    def Duyet_LRN(self, node):                  # Duyệt theo kiểu LRN
        if node:
            self.Duyet_LRN(node.left)
            self.Duyet_LRN(node.right)
            print(node.val)

    def Duyet_LNR(self, node):                  # Duyệt theo kiểu LNR
        if node:
            self.Duyet_LNR(node.left)
            print(node.val)
            self.Duyet_LNR(node.right)


bst = CayNhiPhan()            #bst = binary search tree   

def menu():                             # Cái này tạo menu cho zuiii
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
            bst.Duyet_NLR(bst.root)
            os.system('pause')
        elif choice == 3:
            print("Duyệt theo kiểu LRN:")
            bst.Duyet_LRN(bst.root)
            os.system('pause')
        elif choice == 4:
            print("Duyệt theo kiểu LNR:")
            bst.Duyet_LNR(bst.root)
            os.system('pause')
        elif choice == 5:
            break
        else:
            print("Lựa chọn không hợp lệ")



menu()

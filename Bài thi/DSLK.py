class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def duyet(head):
    while head:
        print(head.data, end=" ")
        head = head.next

def addlist(head, x):
    newNode = Node(x)
    if not head:
        head = newNode
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = newNode

def addTail(head, x):
    newNode = Node(x)
    if not head:
        head = newNode
    else:
        temp = head
        while temp.next:
            temp = temp.next
        temp.next = newNode

def addHead(head, x):
    newNode = Node(x)
    newNode.next = head
    head = newNode

def addMid(head, x, pos):
    newNode = Node(x)
    if pos == 0:
        newNode.next = head
        head = newNode
    else:
        temp = head
        for i in range(pos - 1):
            temp = temp.next
        newNode.next = temp.next
        temp.next = newNode

def printList(head):
    p = head
    print("Danh sach lien ket la: ", end="")
    while p:
        print(p.data, end=" ")
        p = p.next
    print()

def deleteNode(head, pos):
    if not head:
        return
    temp = head
    if pos == 0:
        head = temp.next
        del temp
        return
    for i in range(pos - 1):
        temp = temp.next
        if not temp or not temp.next:
            return
    next = temp.next.next
    del temp.next
    temp.next = next

def Menu(head):
    tail = None
    p = None
    while True:
        print("\n\nCHUONG TRINH QUAN LY DANH SACH LIEN KET DON")
        print("1. Nhap du lieu")
        print("2. Them 1 node vao cuoi DSLK")
        print("3. Them 1 node vao dau DSLK")
        print("4. Them 1 node vao giua DSLK")
        print("5. Xoa 1 node trong DSLK")
        print("6. In ra DSLK")
        print("0. Ket thuc")
        luachon = int(input("Nhap vao lua chon: "))
        if luachon < 0 or luachon > 6:
            print("Lua chon khong hop le: ")
        elif luachon == 1:
            n = int(input("Nhap so luong phan tu: "))
            for i in range(n):
                x = int(input(f"Nhap gia tri cho phan tu thu {i + 1}: "))
                addlist(head, x)
            p = head
            print("Danh sach lien ket la: ", end="")
            while p:
                print(p.data, end=" ")
                p = p.next
        elif luachon == 2:
            x = int(input("Nhap gia tri can them vao cuoi DSLK: "))
            addTail(head, x)
            p = head
            print("Danh sach lien ket la: ", end="")
            while p:
                print(p.data, end=" ")
                p = p.next
        elif luachon == 3:
            x = int(input("Nhap gia tri can them vao dau DSLK: "))
            addHead(head, x)
            p = head
            print("Danh sach lien ket la: ", end="")
            while p:
                print(p.data, end=" ")
                p = p.next
        elif luachon == 4:
            pos = int(input("Nhap vi tri can them vao DSLK: "))
            x = int(input("Nhap gia tri can them vao DSLK: "))
            addMid(head, x, pos)
            p = head
            print("Danh sach lien ket la: ", end="")
            while p:
                print(p.data, end=" ")
                p = p.next
        elif luachon == 5:
            pos = int(input("Nhap vi tri can xoa trong DSLK: "))
            deleteNode(head, pos)
            p = head
            print("Danh sach lien ket la: ", end="")
            while p:
                print(p.data, end=" ")
                p = p.next
        elif luachon == 6:
            print("Danh sach lien ket la: ", end="")
            duyet(head)
        else:
            break

head = None
Menu(head)

class Node:
    def __init__(self, data=None, next=None):
        self.data = data
        self.next = next


class LinkedList:
    def __init__(self):
        self.head = None

    def traverse(self):
        current = self.head
        while current:
            print(current.data, end=" ")
            current = current.next

    def add_to_list(self, x):
        new_node = Node(x)
        if not self.head:
            self.head = new_node
        else:
            temp = self.head
            while temp.next:
                temp = temp.next
            temp.next = new_node

    def add_to_tail(self, x):
        self.add_to_list(x)

    def add_to_head(self, x):
        new_node = Node(x, self.head)
        self.head = new_node

    def add_to_mid(self, x, pos):
        new_node = Node(x)
        if pos == 0:
            new_node.next = self.head
            self.head = new_node
        else:
            temp = self.head
            for _ in range(pos - 1):
                temp = temp.next
            new_node.next = temp.next
            temp.next = new_node

    def delete_node(self, pos):
        if not self.head:
            return
        temp = self.head
        if pos == 0:
            self.head = temp.next
            return
        for _ in range(pos - 1):
            temp = temp.next
        if temp is None or temp.next is None:
            return
        temp.next = temp.next.next

    def menu(self):
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
                print("Lua chon khong hop le")
            elif luachon == 1:
                n = int(input("Nhap so luong phan tu: "))
                for i in range(n):
                    x = int(input(f"Nhap gia tri cho phan tu thu {i + 1}: "))
                    self.add_to_list(x)
                p = self.head
                print("Danh sach lien ket la: ", end="")
                while p:
                    print(p.data, end=" ")
                    p = p.next
            elif luachon == 2:
                x = int(input("Nhap gia tri can them vao cuoi DSLK: "))
                self.add_to_tail(x)
                p = self.head
                print("Danh sach lien ket la: ", end="")
                while p:
                    print(p.data, end=" ")
                    p = p.next
            elif luachon == 3:
                x = int(input("Nhap gia tri can them vao dau DSLK: "))
                self.add_to_head(x)
                p = self.head
                print("Danh sach lien ket la: ", end="")
                while p:
                    print(p.data, end=" ")
                    p = p.next
            elif luachon == 4:
                pos = int(input("Nhap vi tri can them vao DSLK: "))
                x = int(input("Nhap gia tri can them vao DSLK: "))
                self.add_to_mid(x, pos)
                p = self.head
                print("Danh sach lien ket la: ", end="")
                while p:
                    print(p.data, end=" ")
                    p = p.next
            elif luachon == 5:
                pos = int(input("Nhap vi tri can xoa trong DSLK: "))
                self.delete_node(pos)
                p = self.head
                print("Danh sach lien ket la: ", end="")
                while p:
                    print(p.data, end=" ")
                    p = p.next
            elif luachon == 6:
                print("Danh sach lien ket la: ", end="")
                self.traverse()
            else:
                break


def main():
    linked_list = LinkedList()
    linked_list.menu()


if __name__ == "__main__":
    main()

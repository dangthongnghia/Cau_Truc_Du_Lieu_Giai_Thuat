#include <stdio.h>
#include <stdlib.h>

void addElements(int arr[], int size, int firstElement, int lastElement) {
    int newSize = size + 2; // Mảng mới lớn hơn 2 phần tử
    int *newArr = (int *)malloc(newSize * sizeof(int)); // Cấp phát bộ nhớ động

    if (newArr == NULL) {
        printf("Không thể cấp phát bộ nhớ!\n");
        return;
    }

    newArr[0] = firstElement; // Thêm phần tử đầu
    for (int i = 0; i < size; i++) {
        newArr[i + 1] = arr[i]; // Sao chép mảng cũ vào vị trí mới
    }
    newArr[newSize - 1] = lastElement; // Thêm phần tử cuối

    // In mảng mới
    printf("Mang sau khi them: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", newArr[i]);
    }
    printf("\n");

    free(newArr); // Giải phóng bộ nhớ sau khi sử dụng
}

int main() {
    int arr[] = {2, 3, 4}; // Mảng ban đầu
    int size = sizeof(arr) / sizeof(arr[0]);

    int firstElement, lastElement;

    // Yêu cầu người dùng nhập phần tử thêm vào đầu
    printf("Nhap phan tu can them vao dau mang: ");
    scanf("%d", &firstElement);

    // Yêu cầu người dùng nhập phần tử thêm vào cuối
    printf("Nhap phan tu can them vao cuoi mang: ");
    scanf("%d", &lastElement);

    addElements(arr, size, firstElement, lastElement);

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Bài 1
typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;

/*
ListNode* findNode(ListNode *head, int i);
Trả về địa chỉ của node thứ i trong danh sách liên kết trỏ bởi head.
Node đầu tiên của danh sách liên kết là node thứ 0.
*/
ListNode *findNode(ListNode *head, int i) {
    ListNode *cur = head;
    if ((head == NULL) || (i < 0)) {
        printf("Danh sach lien ket rong hoac phan tu tim kiem khong ton tai");
        return NULL;
    }
    while (i > 0) {
        cur = cur->next;
        i = i - 1;
        if (cur == NULL) {
            printf("Phan tu tim kiem khong ton tai");
            return NULL;
        }
    }
    return cur;
}

/*
void insertNode(ListNode **pHead, int index, int value);
Chèn một nút có giá trị value vào
vị trí index trong danh sách liên kết trỏ bởi *pHead
*/
void insertNode(ListNode **pHead, int index, int value) {
    ListNode *cur, *newNode;
    if (*pHead == NULL || index == 0) {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = *pHead;
        *pHead = newNode;
    } else if ((cur = findNode(*pHead, index - 1)) != NULL) {
        newNode = malloc(sizeof(ListNode));
        newNode->num = value;
        newNode->next = cur->next;
        cur->next = newNode;
    } else
        printf("Khong the chen phan tu moi tai chi so %d!\n", index);
}

// Bài 3
/* Bubble sort
Duyệt mảng nhiều lần
So sánh các phần tử kề nhau, hoán đổi nếu sai thứ tự
Lặp lại cho đến khi mảng được sắp xếp
*/
void bubble_sort(int k[], int n) {
    int i, j, x;
    for (i = 1; i < n; i++)
        for (j = n; j > i; j--)
            if (k[j] < k[j - 1]) {
                x = k[j];
                k[j] = k[j - 1];
                k[j - 1] = x;
            }
}
// b[7] = {0, 99, 66, 22, 55, 11, 88, 77 }
// i=1 -> b[7] = {0, 11, 99, 66, 22, 55, 77, 88 }
// i=2 -> b[7] = {0, 11, 22, 99, 66, 55, 77, 88 }
// Giống nhau vì mảng được sắp xếp từ cuối tới phần tử thứ 2

// Bài 4
// Merge dùng để kết hợp hai mảng đã sắp xếp thành một mảng mới
void Merge(int b[], int h, int t, int k) {
    int c[t - h + 1];
    int i = 0, u = h, v = t + 1;

    for (i = 0; i <= t - h; i++)
        c[i] = b[h + i];

    i = 0;
    while (i <= t - h) {
        if (v <= k && b[v] < c[i]) {
            b[u] = b[v];
            u++;
            v = v + 1;
        } else {
            b[u] = c[i];
            u++;
            i = i + 1;
        }
    }
}
/*
Chia: Chia mảng thành hai nửa bằng nhau.
Trị: Đệ quy sắp xếp hai nửa mảng.
Hợp nhất: Hợp nhất hai nửa đã được sắp xếp
thành một mảng đã sắp xếp.
*/
void MergeSort(int b[], int h, int k) {
    if (k - h < 1) return;
    int t = (h + k) / 2;
    MergeSort(b, h, t);
    MergeSort(b, t + 1, k);
    Merge(b, h, t, k);
}
/*Gọi Merge(b,0,1,4) với dãy int b[5] = {11, 22, 10, 55}.
Viết kết quả mảng b và mảng c trước khi vào vòng lặp while.
Viết kết quả mảng b sau mỗi lần lặp của vòng while.

c[2] = {11, 22}
b[5] = {11, 22, 10, 55}

Lần 1: b[5] = {10, 22, 10, 55}
Lần 2: b[5] = {10, 11, 10, 55}
Lần 3: b[5] = {10, 11, 22, 55}
*/

// Bài 5
/*
Một bảng băm độ dài 7 sử dụng cơ chế địa chỉ mở và dò
tuyến tính với hàm băm h(k) = k mod 7 được sử dụng để
chèn các khóa  44, 45, 79, 55, 91, 18, 63 vào các ô
của bảng. Vị trí của khóa 18 là bao nhiêu. Giải thích.
a. 3 	b. 4 	c. 6     d. 5
*/

// h(44) = 44 mod 7 = 2
// h(45) = 45 mod 7 = 3
// h(79) = 79 mod 7 = 2
// h(55) = 55 mod 7 = 6
// h(91) = 91 mod 7 = 0
// h(63) = 63 mod 7 = 0
// h(18) = 18 mod 7 = 4

// Bảng băm có 7 ô: 0, 1, 2, 3, 4, 5, 6
// chèn 44 vào ô 2
// chèn 45 vào ô 3
// chèn 79 vào ô 2 nhưng ô 2 đã có giá trị
// i=1 -> ô 3
// i=2 -> ô 4
// chèn 79 vào ô 4
// chèn 55 vào ô 6
// chèn 91 vào ô 0
// chèn 18 vào ô 4 nhưng ô 4 đã có giá trị
// i=1 -> ô 5
// chèn 18 vào ô 5
// chèn 63 vào ô 0 nhưng ô 0 đã có giá trị
// i=1 -> ô 1
// chèn 63 vào ô 1

//  0  1  2  3  4  5  6
// 91 63 44 45 18 79 55
// Vậy vị trí của khoá 18 là 4
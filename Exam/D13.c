#include <stdio.h>
#include <stdlib.h>

// Bài 1
typedef struct _listnode {
    int num;
    struct _listnode *next;
} ListNode;
typedef struct _linkedlist {
    ListNode *head;
    int size;
} LinkedList;
typedef struct _stack {
    LinkedList ll;
} Stack;

/*
Hàm insertNode thực hiện chèn giá trị value
vào vị trí có chỉ số index trong danh sách liên
kết ptrHead được khai báo như sau:
*/
void insertNode(ListNode **ptrHead, int index, int value);
/*
Hàm removeNode thực hiện xóa nút có chỉ số index
trong danh sách liên kết ptrHead được khai báo như sau:
*/
void removeNode(ListNode **ptrHead, int index);
void push(Stack *s, int item) {
    insertNode(&(s->ll.head), 0, item);
    s->ll.size++;
}
int pop(Stack *s) {
    int item;
    if (!isEmptyStack(s)) {
        item = (s->ll.head)->num;
        removeNode(&(s->ll.head), 0);
        s->ll.size--;
        return item;
    } else {
        printf("\nNgan xep rong");
        return NULL;
    }
}

// Bài 3
/*
Khởi tạo:
Xem dãy số đã được chia thành hai phần:
phần đầu (đã được sắp xếp) và phần còn lại
(chưa được sắp xếp).
Ban đầu, phần đầu chỉ chứa phần tử đầu tiên
(vì một phần tử là đã sắp xếp).

Chèn phần tử vào vị trí đúng:
Đối với mỗi phần tử trong dãy chưa sắp xếp
(bắt đầu từ phần tử thứ hai), lấy phần tử đó và
chèn vào vị trí đúng trong phần đã sắp xếp.
Di chuyển các phần tử lớn hơn phần tử hiện tại
lên một vị trí để tạo ra không gian cho phần tử hiện tại.

Lặp lại:
Tiếp tục quá trình này cho đến khi tất cả các
phần tử đều nằm trong phần đã sắp xếp.
*/
void insert_sort(int k[], int n) {
    int i, j, x;
    k[0] = 0;
    for (i = 2; i <= n; i++) {
        x = k[i];                     // Giá trị cần chèn
        j = i - 1;                    // Vị trí so sánh
        while (j >= 0 && x < k[j]) {  // Điều kiện dừng của vòng lặp
            k[j + 1] = k[j];          // Di chuyển phần tử sang phải
            j = j - 1;                // Chuyển sang phần tử tiếp theo
        }
        k[j + 1] = x;  // Chèn giá trị vào vị trí đúng
    }
}
/*) Cho biết kết quả mảng k sau khi chạy
xong for với i = 2 và i =3 khi gọi insert_sort(b, 7)
với mảng b khai báo như sau
int b[8] = {0, 99, 66, 22, 55, 11, 88, 77 };
*/
// i=2: 0 66 99 22 55 11 88 77
// i=3: 0 22 66 99 55 11 88 77

// Bài 4
// Cho cài đặt của giải thuật Heapsort thực hiện sắp xếp
// n+1 phần tử K[0..n] theo thứ tự tăng dần như sau:
void ADJUST(int K[], int i, int n) {
    int KEY = K[i];
    int j = 2 * i + 1;
    while (j <= n) {
        if ((j < n) && (K[j] < K[j + 1]))
            j = j + 1;
        if (KEY > K[j]) {
            K[(int)floor((j - 1) / 2)] = KEY;
            return;
        }
        K[(int)floor((j - 1) / 2)] = K[j];
        j = 2 * j + 1;
    }
    K[(int)floor((j - 1) / 2)] = KEY;
}

void HeapSort(int K[], int n) {
    int i;
    // (A)
    for (i = floor((n - 1) / 2); i >= 0; i--) {
        ADJUST(K, i, n);
    }
    // (B)
    for (i = n - 1; i >= 0; i--) {
        int tmp = K[0];
        K[0] = K[i + 1];
        K[i + 1] = tmp;
        ADJUST(K, 0, i);
    }
    // (C)
}
/*
Mục đích đoạn A tới B
Xây Heap từ mảng chưa sắp xếp, từ cuối về đầu mảng
Dùng floor((n-1)/2) để xác định vị trí của nút cha cuối cùng
ADJUST đảm bảo mọi nút con từ i trở về trước
đều thoả mãn điều kiện maxheap
*/

/*
Mục đích đoạn từ B tới C
Sắp xếp mảng theo thứ tự tăng dần
Đổi chỗ phần tử đầu tiên với phần tử cuối cùng
và giảm kích thước của mảng đi 1
Sau đó, xây Heap từ phần tử đầu tiên đến phần tử thứ i
bằng ADJUST
*/

// Bài 5
/*MultiDequeue(Q){
   m = k;
   while (Q is not empty and m  > 0) {
      Dequeue(Q)
      m = m - 1
   }
}*/
/*
Q rỗng thì while ko bao giờ được thực hiện
Suy ra Θ(1)

Nếu thực hiện dãy tuần tự lệnh với Q rỗng
thì mỗi lần Dequeue(Q) sẽ mất Θ(1)
Vậy tổng là Θ(1)=Θ(n)
*/
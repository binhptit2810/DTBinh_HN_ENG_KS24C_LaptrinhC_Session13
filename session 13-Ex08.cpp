#include <stdio.h>

// khai bao ham tim uoc chung lon nhat
int timUCLN(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main() {
    int so1, so2;
    // \yeu cau nguoi dung nhap gia tri cho 2 so 
    printf("Nhap so thu nhat: ");
    scanf("%d", &so1);
    printf("Nhap so thu hai: ");
    scanf("%d", &so2);
    // goi ham tim uoc chung lon nhat 
    int ucln = timUCLN(so1, so2);
    // in ket qua ra ngoai man hinh
    printf("Uoc chung lon nhat cua %d va %d la: %d\n", so1, so2, ucln);
    return 0;
}


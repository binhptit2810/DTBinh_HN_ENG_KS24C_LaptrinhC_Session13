#include <stdio.h>

// khai bao ham nhan ma tran 
void nhapMaTran(int maTran[100][100], int soHang, int soCot) {
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &maTran[i][j]);
        }
    }
}
// khai bao ham in ma tran 
void inMaTran(int maTran[100][100], int soHang, int soCot) {
    printf("Ma tran vua nhap la:\n");
    for (int i = 0; i < soHang; i++) {
        for (int j = 0; j < soCot; j++) {
            printf("%d ", maTran[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int maTran[100][100]; 
    int soHang, soCot;

    //yeu cau nguoi dung nhap so hang va so cot
    printf("Nhap so hang: ");
    scanf("%d", &soHang);
    printf("Nhap so cot: ");
    scanf("%d", &soCot);

    // nhap va in ma tran
    nhapMaTran(maTran, soHang, soCot);
    inMaTran(maTran, soHang, soCot);

    return 0;
}


#include <stdio.h>
#include <math.h>

// ham kiem tra so nguyen to
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}
// ham de nhap mang
void nhapMang(int n, int m, int arr[100][100]) {
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}
// ham in mang theo ma tran
void inMang(int n, int m, int arr[100][100]) {
    printf("Mang theo ma tran:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
// ham in cac goc cua ma tran
void inCacGoc(int n, int m, int arr[100][100]) {
    printf("Cac phan tu o goc la:\n");
    printf("%d %d\n", arr[0][0], arr[0][m - 1]);
    printf("%d %d\n", arr[n - 1][0], arr[n - 1][m - 1]);
}
// ham in cac phan tu tren duong bien
void inDuongBien(int n, int m, int arr[100][100]) {
    printf("Cac phan tu tren duong bien:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
// ham in cac phan tu nam tren duong cheo chinh va duong cheo phu
void inDuongCheo(int n, int m, int arr[100][100]) {
    printf("Cac phan tu tren duong cheo chinh va cheo phu:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == j || i + j == m - 1) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
// Hàm in cac phan tu cua ham la so nguyen to
void inSoNguyenTo(int n, int m, int arr[100][100]) {
    printf("Cac phan tu la so nguyen to:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (laSoNguyenTo(arr[i][j])) {
                printf("%d ", arr[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}
int main() {
    int n, m;
    int arr[100][100];
    // nhap kich thuoc cua mang
    printf("Nhap so hang n: ");
    scanf("%d", &n);
    printf("Nhap so cot m: ");
    scanf("%d", &m);
    int luaChon;
    do {
        //in menu ra ngoai man hinh
        printf("\nMENU\n");
        printf("1. Nhap gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In ra cac phan tu o goc theo ma tran\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va cheo phu theo ma tran\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(n,m,arr);
                break;
            case 2:
                inMang(n,m, arr);
                break;
            case 3:
                inCacGoc(n, m,arr);
                break;
            case 4:
                inDuongBien(n,m, arr);
                break;
            case 5:
                inDuongCheo(n,m, arr);
                break;
            case 6:
                inSoNguyenTo(n,m, arr);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 7);

    return 0;
}


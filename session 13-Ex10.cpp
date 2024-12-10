#include <stdio.h>

// ham nhap so phan tu va gia tri cua phan tu
void nhapMang(int arr[], int* n) {
    printf("Nhap so phan tu (toi da 100): ");
    scanf("%d", n);
    for (int i = 0; i < *n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
// ham in cac phan tu trong mang
void inMang(int arr[], int n) {
    printf("Cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// them phan tu vao vi tri chi dinh
void themPhanTu(int arr[], int* n, int viTri, int giaTri) {
    if (viTri < 0 || viTri > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = *n; i > viTri; i--) {
        arr[i] = arr[i - 1];
    }
    arr[viTri] = giaTri;
    (*n)++;
    printf("Them phan tu thanh cong.\n");
}
// Ham sua phan tu o vi tri chi dinh
void suaPhanTu(int arr[], int n, int viTri, int giaTri) {
    if (viTri < 0 || viTri >= n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    arr[viTri] = giaTri;
    printf("Sua phan tu thanh cong.\n");
}
// ham xoa phan tu o vi tri chi dinh
void xoaPhanTu(int arr[], int* n, int viTri) {
    if (viTri < 0 || viTri >= *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }
    for (int i = viTri; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*n)--;
    printf("Xoa phan tu thanh cong.\n");
}
// Ham sap xep mang tang dan
void sapXepTangDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang da duoc sap xep tang dan.\n");
}
// ham sap xep mang giam dan
void sapXepGiamDan(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Mang da duoc sap xep giam dan.\n");
}
// ham tim kiem tuyen tinh
void timKiemTuyenTinh(int arr[], int n, int giaTri) {
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == giaTri) {
            printf("Phan tu %d tim thay tai vi tri %d.\n", giaTri, i);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", giaTri);
    }
}
// ham tim kiem nhi phan 
void timKiemNhiPhan(int arr[], int n, int giaTri) {
    int left = 0, right = n - 1, found = 0;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == giaTri) {
            printf("Phan tu %d tim thay tai vi tri %d.\n", giaTri, mid);
            found = 1;
            break;
        } else if (arr[mid] < giaTri) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", giaTri);
    }
}

int main() {
    int arr[100];
    int n = 0, luaChon;

    do {
        // in menu
        printf("\nMENU\n");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("   a. Giam dan\n");
        printf("   b. Tang dan\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("   a. Tim kiem tuyen tinh\n");
        printf("   b. Tim kiem nhi phan\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);

        switch (luaChon) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inMang(arr, n);
                break;
            case 3: {
                int viTri, giaTri;
                printf("Nhap vi tri muon them: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri muon them: ");
                scanf("%d", &giaTri);
                themPhanTu(arr, &n, viTri, giaTri);
                break;
            }
            case 4: {
                int viTri, giaTri;
                printf("Nhap vi tri muon sua: ");
                scanf("%d", &viTri);
                printf("Nhap gia tri moi: ");
                scanf("%d", &giaTri);
                suaPhanTu(arr, n, viTri, giaTri);
                break;
            }
            case 5: {
                int viTri;
                printf("Nhap vi tri muon xoa: ");
                scanf("%d", &viTri);
                xoaPhanTu(arr, &n, viTri);
                break;
            }
            case 6: {
                int subChoice;
                printf("Chon 1. Giam dan hoac 2. Tang dan: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sapXepGiamDan(arr, n);
                } else if (subChoice == 2) {
                    sapXepTangDan(arr, n);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 7: {
                int subChoice, giaTri;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &giaTri);
                printf("Chon 1. Tim tuyen tinh hoac 2. Tim nhi phan: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    timKiemTuyenTinh(arr, n, giaTri);
                } else if (subChoice == 2) {
                    timKiemNhiPhan(arr, n, giaTri);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
            }
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while (luaChon != 8);
    return 0;
}


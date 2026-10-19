#include <stdio.h>

typedef struct {
    char ma_kien_hang[20];
    float trong_luong;
    float nhiet_do_yeu_cau;
} PalletItem;

typedef struct {
    char ma_ke[20];
    float trong_luong_hien_tai;
    float tai_trong_toi_da;
    int la_kho_lanh;
} WarehouseShelf;

int kiem_tra_nhap_kho(WarehouseShelf ke, PalletItem kien) {
    if (ke.trong_luong_hien_tai + kien.trong_luong > ke.tai_trong_toi_da) {
        return 0;
    }

    if (ke.la_kho_lanh == 1) {
        if (kien.nhiet_do_yeu_cau >= -18.0 &&
            kien.nhiet_do_yeu_cau <= 5.0) {
            return 1;
        } else {
            return 0;
        }
    }

    return 1;
}

int main() {
    WarehouseShelf ke = {"KE-COLD-01", 350.0, 500.0, 1};

    PalletItem kien1 = {"PL-001", 100.0, -10.0};
    PalletItem kien2 = {"PL-002", 80.0, 25.0};
    PalletItem kien3 = {"PL-003", 200.0, 0.0};
    PalletItem kien4 = {"PL-004", 80.0, -25.0};

    printf("=== KIEM TRA NHAP KHO ===\n");

    printf("Test 1 - Nhiet do -10 do C, nang 100kg: %s\n",
           kiem_tra_nhap_kho(ke, kien1) ? "CHO PHEP" : "TU CHOI");

    printf("Test 2 - Nhiet do 25 do C, nang 80kg: %s\n",
           kiem_tra_nhap_kho(ke, kien2) ? "CHO PHEP" : "TU CHOI");

    printf("Test 3 - Nhiet do -25 do C, nang 80kg: %s\n",
           kiem_tra_nhap_kho(ke, kien4) ? "CHO PHEP" : "TU CHOI");

    printf("Test 4 - Vuot tai trong, nang 200kg: %s\n",
           kiem_tra_nhap_kho(ke, kien3) ? "CHO PHEP" : "TU CHOI");

    return 0;
}
// Loi: Dung || sai, phai dung && de nhiet do nam trong khoang [-18, 5].
// Vi nhiet do nao cung >= -18 hoac <= 5 nen dieu kien luon dung.

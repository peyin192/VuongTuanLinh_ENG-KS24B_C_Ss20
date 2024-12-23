#include <stdio.h>
#include <string.h>

typedef struct {
    char productId[20];
    char productName[100];
    float purchasePrice;
    float sellingPrice;
    int quantity;
} Product;

void addProduct(Product product[], int *n, float *revenue);
void displayProducts(Product product[], int *n);
void updateProduct(Product product[], int *n);
void sortProducts(Product product[], int *n);
void searchProduct(Product product[], int *n);
void sellProduct(Product product[], int *n, float *revenue);
void showRevenue(float revenue);

int main() {
    int option = 0;
    Product products[100];
    int n = 0;
    float revenue = 0;

    do {
        printf("\nMENU\n");
        printf("1. Nhap so luong va thong tin san pham\n");
        printf("2. Hien thi danh sach san pham\n");
        printf("3. Nhap san pham\n");
        printf("4. Cap nhat thong tin san pham\n");
        printf("5. Sap xep san pham theo gia (tang/giam)\n");
        printf("6. Tim kiem san pham\n");
        printf("7. Ban san pham\n");
        printf("8. Xem doanh thu hien tai\n");
        printf("9. Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                addProduct(products, &n, &revenue);
                break;
            case 2:
                displayProducts(products, &n);
                break;
            case 3:
                addProduct(products, &n, &revenue);
                break;
            case 4:
                updateProduct(products, &n);
                break;
            case 5:
                sortProducts(products, &n);
                break;
            case 6:
                searchProduct(products, &n);
                break;
            case 7:
                sellProduct(products, &n, &revenue);
                break;
            case 8:
                showRevenue(revenue);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (option != 9);

    return 0;
}

void addProduct(Product product[], int *n, float *revenue) {
    int found = 0;
    char productId[20];

    printf("Nhap ma san pham: ");
    getchar();  
    fgets(productId, sizeof(productId), stdin);
    productId[strcspn(productId, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(product[i].productId, productId) == 0) {
            found = 1;
            printf("San pham da ton tai. Tang so luong san pham.\n");
            printf("Nhap so luong: ");
            int quantity;
            scanf("%d", &quantity);
            product[i].quantity += quantity;
            *revenue -= quantity * product[i].purchasePrice;
            return;
        }
    }

    if (!found) {
        printf("Nhap ten san pham: ");
        fgets(product[*n].productName, sizeof(product[*n].productName), stdin);
        product[*n].productName[strcspn(product[*n].productName, "\n")] = '\0';

        printf("Nhap gia nhap: ");
        scanf("%f", &product[*n].purchasePrice);

        printf("Nhap gia ban: ");
        scanf("%f", &product[*n].sellingPrice);

        printf("Nhap so luong: ");
        scanf("%d", &product[*n].quantity);

        *revenue -= product[*n].quantity * product[*n].purchasePrice;

        (*n)++;
    }
}

void displayProducts(Product product[], int *n) {
    printf("\nDanh sach san pham:\n");
    for (int i = 0; i < *n; i++) {
        printf("San pham thu %d:\n", i + 1);
        printf("Ma san pham: %s\n", product[i].productId);
        printf("Ten san pham: %s\n", product[i].productName);
        printf("Gia nhap: %.2f\n", product[i].purchasePrice);
        printf("Gia ban: %.2f\n", product[i].sellingPrice);
        printf("So luong: %d\n", product[i].quantity);
    }
}

void updateProduct(Product product[], int *n) {
    char productId[20];
    printf("Nhap ma san pham can cap nhat: ");
    getchar();
    fgets(productId, sizeof(productId), stdin);
    productId[strcspn(productId, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(product[i].productId, productId) == 0) {
            printf("Nhap gia nhap moi: ");
            scanf("%f", &product[i].purchasePrice);

            printf("Nhap gia ban moi: ");
            scanf("%f", &product[i].sellingPrice);

            printf("Nhap so luong moi: ");
            scanf("%d", &product[i].quantity);
            return;
        }
    }

    printf("San pham khong ton tai.\n");
}

void sortProducts(Product product[], int *n) {
    int choice;
    printf("Chon cach sap xep:\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Nhap lua chon: ");
    scanf("%d", &choice);

    for (int i = 0; i < *n - 1; i++) {
        for (int j = i + 1; j < *n; j++) {
            if ((choice == 1 && product[i].sellingPrice > product[j].sellingPrice) ||
                (choice == 2 && product[i].sellingPrice < product[j].sellingPrice)) {
                Product temp = product[i];
                product[i] = product[j];
                product[j] = temp;
            }
        }
    }

    printf("Sap xep hoan tat.\n");
}

void searchProduct(Product product[], int *n) {
    char productName[100];
    printf("Nhap ten san pham can tim: ");
    getchar();
    fgets(productName, sizeof(productName), stdin);
    productName[strcspn(productName, "\n")] = '\0';

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strstr(product[i].productName, productName)) {
            printf("San pham thu %d:\n", i + 1);
            printf("Ma san pham: %s\n", product[i].productId);
            printf("Ten san pham: %s\n", product[i].productName);
            printf("Gia nhap: %.2f\n", product[i].purchasePrice);
            printf("Gia ban: %.2f\n", product[i].sellingPrice);
            printf("So luong: %d\n", product[i].quantity);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay san pham voi ten '%s'.\n", productName);
    }
}

void sellProduct(Product product[], int *n, float *revenue) {
    char productId[20];
    int quantityToSell;

    printf("Nhap ma san pham can ban: ");
    getchar();
    fgets(productId, sizeof(productId), stdin);
    productId[strcspn(productId, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(product[i].productId, productId) == 0) {
            printf("Nhap so luong can ban: ");
            scanf("%d", &quantityToSell);

            if (product[i].quantity == 0) {
                printf("San pham het hang.\n");
            } else if (quantityToSell > product[i].quantity) {
                printf("Khong co du hang de ban.\n");
            } else {
                product[i].quantity -= quantityToSell;
                *revenue += quantityToSell * product[i].sellingPrice;
                printf("Ban thanh cong %d san pham.\n", quantityToSell);
            }

            return;
        }
    }

    printf("San pham khong ton tai.\n");
}

void showRevenue(float revenue) {
    printf("Doanh thu hien tai: %.2f\n", revenue);
}


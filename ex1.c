#include <stdio.h>
#include <string.h>

typedef struct{
    char bookId[20];
    char title[100];
    char auth[50];
    float price;
    char category[50];
} Book;

void addBook(Book book[], int *n);
void displayBook(Book book[], int *n);
void addatBook(Book book[], int *n);
void deleteBook(Book book[], int *n);
void updateBook(Book book[], int *n);
void sortByPrice(Book book[], int *n);
void searchBook(Book book[], int *n);

int main() {
    int option = 0;
    Book book[100];
    int n = 0;

    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhap thong tin sach theo ma sach\n");
        printf("6. Sap xep theo gia (tang hoac giam)\n");
        printf("7. Tim kiem theo ten\n");
        printf("8. Thoat\n");

        printf("Nhap lua chon: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Nhap so luong sach: ");
                scanf("%d", &n);
                addBook(book, &n);
                break;
            case 2:
                displayBook(book, &n);
                break;
            case 3:
                addatBook(book, &n);
                break;
            case 4:
                deleteBook(book, &n);
                break;
            case 5:
                updateBook(book, &n);
                break;
            case 6:
                sortByPrice(book, &n);
                break;
            case 7:
                searchBook(book, &n);
                break;
            case 8:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (option != 8);

    return 0;
}

void addBook(Book book[], int *n) {
    for (int i = 0; i < *n; i++) {
        printf("Moi nhap thong tin cua quyen sach thu %d\n", i + 1);
        fflush(stdin);

        printf("Ma sach: ");
        fgets(book[i].bookId, sizeof(book[i].bookId), stdin);
        book[i].bookId[strcspn(book[i].bookId, "\n")] = '\0';

        printf("Ten sach: ");
        fgets(book[i].title, sizeof(book[i].title), stdin);
        book[i].title[strcspn(book[i].title, "\n")] = '\0';

        printf("Ten tac gia: ");
        fgets(book[i].auth, sizeof(book[i].auth), stdin);
        book[i].auth[strcspn(book[i].auth, "\n")] = '\0';

        printf("Gia tien: ");
        scanf("%f", &book[i].price);
        getchar();

        printf("The loai: ");
        fgets(book[i].category, sizeof(book[i].category), stdin);
        book[i].category[strcspn(book[i].category, "\n")] = '\0';
    }
}

void displayBook(Book book[], int *n) {
    printf("Danh sach sach:\n");
    for (int i = 0; i < *n; i++) {
        printf("Thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: %s\n", book[i].bookId);
        printf("Ten sach: %s\n", book[i].title);
        printf("Ten tac gia: %s\n", book[i].auth);
        printf("Gia tien: %.2f\n", book[i].price);
        printf("The Loai: %s\n", book[i].category);
    }
}

void addatBook(Book book[], int *n) {
    int position;
    printf("Nhap vi tri can them (0 den %d): ", *n);
    scanf("%d", &position);
    fflush(stdin);
    if (position < 0 || position > *n) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *n; i > position; i--) {
        book[i] = book[i - 1];
    }

    printf("Nhap thong tin sach:\n");
    printf("Ma sach: ");
    fgets(book[position].bookId, sizeof(book[position].bookId), stdin);
    book[position].bookId[strcspn(book[position].bookId, "\n")] = '\0';

    printf("Ten sach: ");
    fgets(book[position].title, sizeof(book[position].title), stdin);
    book[position].title[strcspn(book[position].title, "\n")] = '\0';

    printf("Ten tac gia: ");
    fgets(book[position].auth, sizeof(book[position].auth), stdin);
    book[position].auth[strcspn(book[position].auth, "\n")] = '\0';

    printf("Gia tien: ");
    scanf("%f", &book[position].price);
    getchar();

    printf("The loai: ");
    fgets(book[position].category, sizeof(book[position].category), stdin);

    (*n)++;
}

void deleteBook(Book book[], int *n) {
    char bookId[20];
    int found = 0;

    printf("Nhap ma sach can xoa: ");
    getchar();
    fgets(bookId, sizeof(bookId), stdin);
    bookId[strcspn(bookId, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(book[i].bookId, bookId) == 0) {
            found = 1;
            for (int j = i; j < *n - 1; j++) {
                book[j] = book[j + 1];
            }
            (*n)--;
            printf("Sach da duoc xoa.\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ma sach %s.\n", bookId);
    }
}

void updateBook(Book book[], int *n) {
    char bookId[20];
    int found = 0;

    printf("Nhap ma sach can cap nhat: ");
    getchar();
    fgets(bookId, sizeof(bookId), stdin);
    bookId[strcspn(bookId, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strcmp(book[i].bookId, bookId) == 0) {
            found = 1;

            printf("Nhap thong tin moi cho sach:\n");
            printf("Ma sach: ");
            fgets(book[i].bookId, sizeof(book[i].bookId), stdin);
            book[i].bookId[strcspn(book[i].bookId, "\n")] = '\0';

            printf("Ten sach: ");
            fgets(book[i].title, sizeof(book[i].title), stdin);
            book[i].title[strcspn(book[i].title, "\n")] = '\0';

            printf("Ten tac gia: ");
            fgets(book[i].auth, sizeof(book[i].auth), stdin);
            book[i].auth[strcspn(book[i].auth, "\n")] = '\0';

            printf("Gia tien: ");
            scanf("%f", &book[i].price);
            getchar();

            printf("The loai: ");
            fgets(book[i].category, sizeof(book[i].category), stdin);

            break;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ma sach %s.\n", bookId);
    }
}

void sortByPrice(Book book[], int *n) {
    int choice;
    printf("Chon cach sap xep:\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Nhap lua chon: ");
    scanf("%d", &choice);

    for (int i = 0; i < *n - 1; i++) {
        for (int j = i + 1; j < *n; j++) {
            if ((choice == 1 && book[i].price > book[j].price) ||
                (choice == 2 && book[i].price < book[j].price)) {
                Book temp = book[i];
                book[i] = book[j];
                book[j] = temp;
            }
        }
    }

    printf("Sap xep hoan tat.\n");
}

void searchBook(Book book[], int *n) {
    char title[100];
    int found = 0;

    printf("Nhap ten sach can tim: ");
    getchar();
    fgets(title, sizeof(title), stdin);
    title[strcspn(title, "\n")] = '\0';

    for (int i = 0; i < *n; i++) {
        if (strstr(book[i].title, title)) {
            printf("Sach thu %d:\n", i + 1);
            printf("Ma sach: %s\n", book[i].bookId);
            printf("Ten sach: %s\n", book[i].title);
            printf("Ten tac gia: %s\n", book[i].auth);
            printf("Gia tien: %.2f\n", book[i].price);
            printf("The loai: %s\n", book[i].category);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sach voi ten '%s'.\n", title);
    }
}


#include <stdio.h>
typedef struct {  
    char id[10];  
    char title[TITLE_LENGTH];  
    char author[AUTHOR_LENGTH];  
    float price;  
    char category[CATEGORY_LENGTH];  
} Book;  
Book books[MAX_BOOKS];  
int bookCount = 0;  
void displayMenu() {  
    printf("\nMENU\n");  
    printf("1. Nhap so luong va thong tin sach.\n");  
    printf("2. Hien thi thong tin sach.\n");  
    printf("3. Them sach vao vi tri.\n");  
    printf("4. Xoa sach theo ma sach.\n");  
    printf("5. Cap nhat thong tin sach theo ma sach.\n");  
    printf("6. Sap xep sach theo gia (tang/giam).\n");  
    printf("7. Tim kiem sach theo ten sach.\n");  
    printf("8. Thoat\n");  
} 
void inputBooks() {  
    int n, i;  
    printf("Nhap so luong sach (toi da %d): ", MAX_BOOKS);  
    scanf("%d", &n);    
    if (n + bookCount > MAX_BOOKS) {  
        printf("Khong the nhap them sach. Da dat gioi han toi da.\n");  
        return;  
    } 
    for (i = 0; i < n; i++) {  
        printf("Nhap ma sach: ");  
        scanf("%s", books[bookCount].id);  
        printf("Nhap ten sach: ");  
        getchar();  
        fgets(books[bookCount].title, TITLE_LENGTH, stdin);  
        books[bookCount].title[strcspn(books[bookCount].title, "\n")] = 0;  
        printf("Nhap tac gia: ");  
        fgets(books[bookCount].author, AUTHOR_LENGTH, stdin);  
        books[bookCount].author[strcspn(books[bookCount].author, "\n")] = 0;  
        printf("Nhap gia: ");  
        scanf("%f", &books[bookCount].price);  
        printf("Nhap the loai: ");  
        getchar();  
        fgets(books[bookCount].category, CATEGORY_LENGTH, stdin);  
        books[bookCount].category[strcspn(books[bookCount].category, "\n")] = 0;  
        bookCount++;  
        printf("Da them sach thu %d.\n", bookCount);  
    }  
}  
void displayBooks() {  
    if (bookCount == 0) {  
        printf("Chua co sach nao.\n");  
        return;  
    }  
    for (int i = 0; i < bookCount; i++) {  
        printf("%s\n", books[i].title);  
    }  
}  
void addBookAtPosition() {  
    if (bookCount >= MAX_BOOKS) {  
        printf("Khong the them sach. Da dat gioi han toi da.\n");  
        return;  
    }  
    int pos;  
    printf("Nhap vi tri them sach (0 - %d): ", bookCount);  
    scanf("%d", &pos);   
    if (pos < 0 || pos > bookCount) {  
        printf("Vi tri khong hop le.\n");  
        return;  
    }
    for (int i = bookCount; i > pos; i--) {  
        books[i] = books[i - 1];  
    }
    printf("Nhap ma sach: ");  
    scanf("%s", books[pos].id);  
    printf("Nhap ten sach: ");  
    getchar();  
    fgets(books[pos].title, TITLE_LENGTH, stdin);  
    books[pos].title[strcspn(books[pos].title, "\n")] = 0;  
    printf("Nhap tac gia: ");  
    fgets(books[pos].author, AUTHOR_LENGTH, stdin);  
    books[pos].author[strcspn(books[pos].author, "\n")] = 0;  
    printf("Nhap gia: ");  
    scanf("%f", &books[pos].price);  
    printf("Nhap the loai: ");  
    getchar();  
    fgets(books[pos].category, CATEGORY_LENGTH, stdin);  
    books[pos].category[strcspn(books[pos].category, "\n")] = 0;
    bookCount++;  
    printf("Da them sach vao vi tri %d.\n", pos);  
}
void deleteBookById() {  
    char id[10];  
    printf("Nhap ma sach can xoa: ");  
    scanf("%s", id);
    int found = -1;  
    for (int i = 0; i < bookCount; i++) {  
        if (strcmp(books[i].id, id) == 0) {  
            found = i;  
            break;  
        }  
    }
    if (found == -1) {  
        printf("Khong tim thay sach voi ma %s.\n", id);  
        return;  
    }
    for (int i = found; i < bookCount - 1; i++) {  
        books[i] = books[i + 1];  
    }  
    bookCount--;  
    printf("Da xoa sach voi ma %s.\n", id);  
}
void updateBookById() {  
    char id[10];  
    printf("Nhap ma sach can cap nhat: ");  
    scanf("%s", id);
    int found = -1;  
    for (int i = 0; i < bookCount; i++) {  
        if (strcmp(books[i].id, id) == 0) {  
            found = i;  
            break;  
        }  
    }
    if (found == -1) {  
        printf("Khong tim thay sach voi ma %s.\n", id);  
        return;  
    }
    printf("Nhap ten sach moi: ");  
    getchar();  
    fgets(books[found].title, TITLE_LENGTH, stdin);  
    books[found].title[strcspn(books[found].title, "\n")] = 0;  
    printf("Nhap tac gia moi: ");  
    fgets(books[found].author, AUTHOR_LENGTH, stdin);  
    books[found].author[strcspn(books[found].author, "\n")] = 0;  
    printf("Nhap gia moi: ");  
    scanf("%f", &books[found].price);  
    printf("Nhap the loai moi: ");  
    getchar();  
    fgets(books[found].category, CATEGORY_LENGTH, stdin);  
    books[found].category[strcspn(books[found].category, "\n")] = 0;  
    printf("Da cap nhat thong tin sach voi ma %s.\n", id);  
}
void sortBooksByPrice() {  
    int option;  
    printf("Chon cach sap xep: 1. Tang dan  2. Giam dan: ");  
    scanf("%d", &option);
    for (int i = 0; i < bookCount - 1; i++) {  
        for (int j = i + 1; j < bookCount; j++) {  
            if ((option == 1 && books[i].price > books[j].price) ||  
                (option == 2 && books[i].price < books[j].price)) {  
                Book temp = books[i];  
                books[i] = books[j];  
                books[j] = temp;  
            }  
        }  
    }  
    printf("Da sap xep sach theo gia.\n");  
}
void searchBookByTitle() {  
    char title[TITLE_LENGTH];  
    printf("Nhap ten sach de tim kiem: ");  
    getchar();  
    fgets(title, TITLE_LENGTH, stdin);  
    title[strcspn(title, "\n")] = 0;
    int found = 0;  
    for (int i = 0; i < bookCount; i++) {  
        if (strstr(books[i].title, title) != NULL) {  
            printf("Sach tim thay: %s\n", books[i].title);  
            found = 1;  
        }  
    }
    if (!found) {  
        printf("Khong tim thay sach nao voi ten \"%s\".\n", title);  
    }  
}
int main() {  
    int choice;  
    while (1) {  
        displayMenu();  
        printf("Lua chon cua ban: ");  
        scanf("%d", &choice);  

        switch (choice) {  
            case 1:  
                inputBooks();  
                break;  
            case 2:  
                displayBooks();  
                break;  
            case 3:  
                addBookAtPosition();  
                break;  
            case 4:  
                deleteBookById();  
                break;  
            case 5:  
                updateBookById();  
                break;  
            case 6:  
                sortBooksByPrice();  
                break;  
            case 7:  
                searchBookByTitle();  
                break;  
            case 8:  
                printf("Thoat chuong trinh.\n");  
                exit(0);  
            default:  
                printf("Lua chon khong hop le. Vui long thu lai.\n");  
        }  
    }  
    return 0;  
}

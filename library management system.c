#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

struct Book {
    char title[100];
    char author[100];
    int book_id;
    int is_available;
};

struct Book library[MAX_BOOKS];
int num_books = 0;

void add_book() {
    if (num_books >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    struct Book new_book;

    printf("Enter book title: ");
    scanf(" %[^\n]", new_book.title);

    printf("Enter author name: ");
    scanf(" %[^\n]", new_book.author);

    printf("Enter book ID: ");
    scanf("%d", &new_book.book_id);

    new_book.is_available = 1;

    library[num_books] = new_book;
    num_books++;

    printf("Book added successfully!\n");
}

void search_book() {
    char title[100];
    printf("Enter the book title to search: ");
    scanf(" %[^\n]", title);

    int found = 0;
    for (int i = 0; i < num_books; i++) {
        if (strcmp(title, library[i].title) == 0) {
            found = 1;
            printf("Book found!\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Book ID: %d\n", library[i].book_id);
            printf("Availability: %s\n", library[i].is_available ? "Available" : "Not Available");
            break;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }
}

void display_books() {
    if (num_books == 0) {
        printf("No books in the library.\n");
        return;
    }

    printf("Available Books:\n");
    for (int i = 0; i < num_books; i++) {
        if (library[i].is_available) {
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Book ID: %d\n", library[i].book_id);
            printf("Availability: Available\n");
            printf("------------------------\n");
        }
    }
}

int main() {
    int choice;

    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Search Book\n");
        printf("3. Display Available Books\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_book();
                break;
            case 2:
                search_book();
                break;
            case 3:
                display_books();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

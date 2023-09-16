/*
Attributes: Title, Author, Genre, Page Count, Checked Out
Methods: 
CheckOutBook: Sets the "Checked Out" attributr to true and records the due date.
ReturnBook: Sets the "Checked Out" attribute to false and removes the due date.
RenewBook: Extends the due dat if the book is not overdue.
IsOverdue: Checks if the books is overdue based on the due date.
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct LibraryBook {
	char title[100];
	char author[100];
	char genre[50];
	int pageCount;
	bool checkedOut;
	char dueDate[20];
};

void CheckOutBook(struct LibraryBook* book, const char* dueDate) {
	book->checkedOut = true;
	strcpy(book->dueDate, dueDate);
}

void ReturnBook(struct LibraryBook* book) {
	book->checkedOut = false;
	strcpy(book->dueDate, "");
}

void RenewBook(struct LibraryBook* book, const char* newDueDate) {
	if(!book->checkedOut) {
		printf("The book is not checked out.\n");
	} else {
		strcpy(book->dueDate, newDueDate);
	}
}

bool IsOverdue(const struct LibraryBook* book, const char* currentDate) {
	if (book->checkedOut && strcmp(book->dueDate, currentDate) < 0) {
		return true;
	}
	return false;
}

int main() {
	struct LibraryBook book1 = {"The Great Gatsby", "F. Scott Fitzgerald", "Fiction", 180, false, ""};
	CheckOutBook(&book1, "2023-10-01");
	printf("Is the book overdue? %s\n", IsOverdue(&book1, "2023-10-15") ? "Yes": "No");
	RenewBook(&book1, "2023-11-01");
	printf("Is the book overdue after renewal? %s\n", IsOverdue(&book1, "2023-10-15") ? "Yes" : "No");
	ReturnBook(&book1);
	printf("Is the book  checked out? %s\n", book1.checkedOut ? "Yes" : "No");

	return 0;
}

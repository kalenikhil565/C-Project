#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Booksystem {
	int bookid;
	char bookname[30];
	char author[30];
	int price;
	char category[20];
	double rating;
} Booksystem;

int hardCoded (Booksystem*,int);
void storeBook(Booksystem*, int*);
void displayBook(Booksystem*, int);
void searchBookId(Booksystem*, int, int);
void searchBookName(Booksystem*, int, char*);
void searchIdName(Booksystem*, int);
void searchAuthorCategory(Booksystem* bs, int ctr);
void searchByAuthor(Booksystem*,int,char*);
void searchByCategory(Booksystem*,int,char*);
void updatebook(Booksystem*,int,int);
void deletebook(Booksystem*, int*, int);
void sortByPrice(Booksystem*, int);
void sortByRating(Booksystem*, int);
void display(Booksystem*, int);

void main() {

	int size = 10;
	Booksystem* bs = (Booksystem*)malloc(sizeof(Booksystem)*size);

	int ctr = 0;
	ctr = hardCoded (bs, ctr);
	

	int choice;
	do {
		printf("\n============== Book Management System ================\n");
		printf("\n\t 1. Store book");
		printf("\n\t 2. Display all books");
		printf("\n\t 3. Search book");
		printf("\n\t 4. Show book");
		printf("\n\t 5. Update book data");
		printf("\n\t 6. Delete book");
		printf("\n\t 7. Sort book data");
		printf("\n\t 0. Exit");
		printf("\n\n=====================================================\n\n");
		
		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1: {
                if (ctr == size) {
                    size = size + 10;
                    bs = (Booksystem*)realloc(bs, sizeof(Booksystem) * size);
                    if (bs == NULL) {
                        printf("\nMemory allocation failed during reallocation!\n");
                        return;
                    }
                    printf("\nArray size increased by 10. New size: %d\n", size);
                }
                storeBook(bs, &ctr);
                break;
            }

			case 2: {
				if (ctr != 0) {
					displayBook(bs, ctr);
				} else {
					printf("\nNo books present.\n");
				}
				break;
			}

			case 3: {
				searchIdName(bs, ctr);
				break;
			}

			case 4: {
				searchAuthorCategory(bs, ctr);
				break;
			}

			case 5: {
				int bookid;
				printf("\nEnter bookid : ");
				scanf("%d",&bookid);

				updatebook(bs, ctr, bookid);
				break;
			}

			case 6: {
				int bookid;
				printf("Enter bookid : ");
				scanf("%d",&bookid);
				deletebook(bs, &ctr, bookid);
				break;
			}

			case 7: {
				int ch;
				printf("\n1. BY Price\n2. BY Rating :\t");
				scanf("%d", &ch);


				switch (ch) {
					case 1:
						sortByPrice(bs, ctr);
						break;
					case 2:
						sortByRating(bs, ctr);
						break;
					default:
						printf("\nInvalid choice. Please select either 1 or 2.\n");
						break;
				}
				break;
			}


			case 0: {
				printf("\nExiting the program.\n");
				break;
			}

			default: {
				printf("\nInvalid choice. Please try again.\n");
				break;
			}

		}
	} while (choice != 0);
	free(bs);
}
int hardCoded(Booksystem* bs, int ctr) {

    bs[ctr].bookid = 1;
    strcpy(bs[ctr].bookname, "Atomic Habits");
    strcpy(bs[ctr].author, "James Clear");
    bs[ctr].price = 500;
    strcpy(bs[ctr].category, "Science");
    bs[ctr].rating = 9.7;
    ctr++;

    bs[ctr].bookid = 2;
    strcpy(bs[ctr].bookname, "Brief Answers");
    strcpy(bs[ctr].author, "Stephen Hawking");
    bs[ctr].price = 450;
    strcpy(bs[ctr].category, "Science");
    bs[ctr].rating = 7.6;
    ctr++;

    bs[ctr].bookid = 3;
    strcpy(bs[ctr].bookname, "Silent Spring");
    strcpy(bs[ctr].author, "Rachel Carson");
    bs[ctr].price = 320;
    strcpy(bs[ctr].category, "Fiction");
    bs[ctr].rating = 8.2;
    ctr++;

    bs[ctr].bookid = 4;
    strcpy(bs[ctr].bookname, "Invisible Man");
    strcpy(bs[ctr].author, "Ralph Ellison");
    bs[ctr].price = 380;
    strcpy(bs[ctr].category, "Fiction");
    bs[ctr].rating = 6.4;
    ctr++;

    return ctr;
}


void storeBook(Booksystem* bs, int* i) {
	printf("\n--- Add New Book ---\n");

	printf("Enter bookid: ");
	scanf("%d", &bs[*i].bookid);
	printf("Enter bookname: ");
	scanf("%s", bs[*i].bookname);
	getchar();
	printf("Enter author: ");
	scanf("%s", bs[*i].author);
	getchar();
	printf("Enter price: ");
	scanf("%d", &bs[*i].price);
	printf("Enter category: ");
	scanf("%s", bs[*i].category);
	getchar();
	printf("Enter rating: ");
	scanf("%lf", &bs[*i].rating);

	(*i)++;
	printf("\nBook added successfully!\n");
	
}

void displayBook(Booksystem* bs, int n) {
	printf("\n======================================\n");
	printf("        Displaying Stored Books       \n");
	printf("======================================\n");


	printf("+------------+----------------------+----------------------+-------+-----------------+--------+\n");
	printf("| Book ID    |  Book Name           | Author               | Price | Category        | Rating |\n");
	printf("+------------+----------------------+----------------------+-------+-----------------+--------+\n");


	for (int i = 0; i < n; i++) {
		printf("| %-10d | %-20s | %-20s | %-5d | %-15s | %-6.1lf |\n",
		       bs[i].bookid,
		       bs[i].bookname,
		       bs[i].author,
		       bs[i].price,
		       bs[i].category,
		       bs[i].rating);
	}

	printf("+------------+----------------------+----------------------+-------+-----------------+--------+\n");

	printf("Total Books Stored: %d\n", n);
}


void searchBookId(Booksystem* bs, int ctr, int id) {
	int isFound = 1;

	for (int i = 0; i < ctr; i++) {
		if (bs[i].bookid == id) {
			isFound = 0;
			display(bs, i);
			printf("\n-------Book found successfully------\n");
			break;
		}
	}

	if (isFound == 1) {
		printf("\n------------Book not found------------\n");
	}
}


void display(Booksystem* bs, int i) {

	printf("+------------+----------------------+----------------------+-------+-----------------+--------+\n");
	printf("| Book ID    | Book Name            | Author               | Price | Category        | Rating |\n");
	printf("+------------+----------------------+----------------------+-------+-----------------+--------+\n");

	printf("| %-10d | %-20s | %-20s | %-5d | %-15s | %-6.1lf |\n",
	       bs[i].bookid,
	       bs[i].bookname,
	       bs[i].author,
	       bs[i].price,
	       bs[i].category,
	       bs[i].rating);

	printf("+------------+----------------------+----------------------+-------+-----------------+--------+\n\n");

}

void searchBookName(Booksystem* bs, int ctr, char* name) {
	int isfound = 1;
	for (int i = 0; i < ctr; i++) {
		if (strcasecmp(bs[i].bookname, name) == 0) {
			isfound = 0;

			display(bs,i);
			printf("\n-------Book found successfully------\n");
		}
	}

	if (isfound == 1) {
		printf("\n------------Book not found------------\n");
	}
}

void searchIdName(Booksystem* bs, int ctr) {
	int choice;
	printf("\n1. Bookid\n2. Bookname:\t");
	scanf("%d", &choice);
	if (choice == 1) {
		int id;
		printf("\nEnter bookid: ");
		scanf("%d", &id);
		searchBookId(bs, ctr, id);

	} else if (choice == 2) {
    char name[30];
    printf("\nEnter book name: ");
    getchar();  // Clear newline left from previous input
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';  // Remove the newline character

    searchBookName(bs, ctr, name);
}

}

void searchAuthorCategory(Booksystem* bs, int ctr) {
	int choice;
	printf("\n1. Author\n2. Category:\t");
	scanf("%d", &choice);
	getchar();

	if (choice == 1) {
		char author[30];
		printf("\nEnter author: ");
		fgets(author, sizeof(author), stdin);
		author[strcspn(author, "\n")] = '\0';

		searchByAuthor(bs, ctr, author);
	} else if (choice == 2) {
		char category[30];
		printf("\nEnter category: ");
		fgets(category, sizeof(category), stdin);
		category[strcspn(category, "\n")] = '\0';

		searchByCategory(bs, ctr, category);
	} else {
		printf("\nInvalid choice. Please select either 1 or 2.\n");
	}
}

void searchByAuthor(Booksystem* bs, int ctr, char* author) {
	int isfound = 1;
	for (int i = 0; i < ctr; i++) {
		if (strcasecmp(bs[i].author, author) == 0) {
			display(bs, i);
			printf("-------Book found successfully------\n");
			isfound = 0;
		}
	}

	if (isfound == 1) {
		printf("\n------------No books found by this author------------\n");
	}
}

void searchByCategory(Booksystem* bs, int ctr, char* category) {
	int isfound = 1;
	for (int i = 0; i < ctr; i++) {
		if (strcasecmp(bs[i].category, category) == 0) {
			display(bs, i);

			isfound = 0;
		}
	}

	if (isfound == 1) {
		printf("\n------------No books found in this category------------\n");
	}
}


void updatebook(Booksystem* bs, int ctr, int bookid) {
	int isfound = 1;
	for (int i = 0; i < ctr; i++) {
		if (bs[i].bookid == bookid) {
			int choice;
			printf("\nBook found. What would you like to update?\n");
			printf("1. Update Price\n");
			printf("2. Update Rating\n");
			printf("Enter your choice: ");
			scanf("%d", &choice);

			if (choice == 1) {
				printf("\nEnter new price: ");
				scanf("%d", &bs[i].price);
				printf("\nPrice updated successfully.\n");
			} else if (choice == 2) {
				printf("\nEnter new rating: ");
				scanf("%lf", &bs[i].rating);
				printf("\nRating updated successfully.\n");
			} else {
				printf("\nInvalid choice. Please select 1 or 2.\n");
			}

			isfound = 0;
			break;
		}
	}

	if (isfound == 1) {
		printf("\n------------Book not found------------\n");
	}
}

void deletebook(Booksystem* bs, int* ctr,int bookid) {

	int isfound=1;

	for(int i=0; i < (*ctr); i++) {
		if(bs[i].bookid == bookid) {

			isfound = 0;
			for(int j=i; j < (*ctr)-1; j++) {
				bs[j] = bs[j+1];
			}
			(*ctr)--;
			printf("\n-------Book deleted successfully------\n");
			break;
		}

	}

	if(isfound==1) {
		printf("\nBook not found\n");
	}

}

void sortByPrice(Booksystem* bs, int ctr) {
	int choice;
	printf("\n1. Low To High\n2. High To Low :\t");
	scanf("%d", &choice);
	getchar();

	switch (choice) {
		case 1:
			for (int i = 0; i < ctr; i++) {
				for (int j = i + 1; j < ctr; j++) {
					if (bs[i].price > bs[j].price) {
						Booksystem temp = bs[i];
						bs[i] = bs[j];
						bs[j] = temp;
					}
				}
			}
			displayBook(bs, ctr);
			break;

		case 2:
			for (int i = 0; i < ctr; i++) {
				for (int j = i + 1; j < ctr; j++) {
					if (bs[i].price < bs[j].price) {
						Booksystem temp = bs[i];
						bs[i] = bs[j];
						bs[j] = temp;
					}
				}
			}
			displayBook(bs, ctr);
			break;

		default:
			printf("\nInvalid choice. Please select either 1 or 2.\n");
			break;
	}
}

void sortByRating(Booksystem* bs, int ctr) {
    int choice;
    printf("\n1. Low To High\n2. High To Low :\t");
    scanf("%d", &choice);

    switch (choice) {
        case 1: 
            for (int i = 0; i < ctr; i++) {
                for (int j = i + 1; j < ctr; j++) {
                    if (bs[i].rating > bs[j].rating) {
                        Booksystem temp = bs[i];
                        bs[i] = bs[j];
                        bs[j] = temp;
                    }
                }
            }
            displayBook(bs, ctr);
            break;

        case 2:
            for (int i = 0; i < ctr; i++) {
                for (int j = i + 1; j < ctr; j++) {
                    if (bs[i].rating < bs[j].rating) {
                        Booksystem temp = bs[i];
                        bs[i] = bs[j];
                        bs[j] = temp;
                    }
                }
            }
            displayBook(bs, ctr);
            break;

        default: 
            printf("\nInvalid choice. Please select either 1 or 2.\n");
            break;
    }
}


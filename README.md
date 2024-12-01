# Book Management System

## Introduction
The Book Management System is a console-based C program designed to manage books in a system. It allows users to add, update, delete, search, and sort books by various attributes such as price and rating. The system uses dynamic memory allocation to store book data and ensures that the array of books grows as needed.

## Features
- **Add new books**: Users can add new books with attributes such as book ID, name, author, price, category, and rating.
- **Display books**: Displays all stored books with their complete details.
- **Search books**: Allows searching by book ID, name, author, or category.
- **Update book data**: Users can update the price or rating of a book.
- **Delete books**: Deletes a book by its ID.
- **Sort books**: Sort books by price or rating (low to high or high to low).
- **Dynamic memory management**: The program uses dynamic memory allocation to store books and reallocates memory when the number of books exceeds the initial allocation.

## Code Explanation

### Structure
The system uses a `struct Booksystem` to represent each book, which includes the following attributes:
  - `bookid`: A unique identifier for the book.
  - `bookname`: The name of the book.
  - `author`: The author of the book.
  - `price`: The price of the book.
  - `category`: The category the book belongs to.
  - `rating`: The rating of the book.

### Dynamic Memory Management
The program initializes a dynamic array of books using `malloc` and dynamically increases the size of the array using `realloc` as needed. This ensures that the array has enough space to accommodate new books as they are added.

### Operations
The main operations available in the system are:
  - **Storing Books**: Users are prompted to enter details of a book, including book ID, name, author, price, category, and rating.
  - **Displaying Books**: All books are displayed in a tabular format showing all attributes of each book.
  - **Searching Books**: Users can search for books based on their ID, name, author, or category.
  - **Sorting Books**: Books can be sorted by price or rating, in ascending or descending order.

### Switch Statement
The main loop of the program uses a `switch` statement to provide different options for users. These options include:
  - Adding new books
  - Displaying all books
  - Searching for books
  - Updating book data
  - Deleting books
  - Sorting books

### Dynamic Memory Allocation
The program uses dynamic memory allocation to store book data. If the number of books exceeds the initial allocated space, the program reallocates memory using `realloc` to ensure there is enough space for new books.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgements
The program was developed using the C programming language.

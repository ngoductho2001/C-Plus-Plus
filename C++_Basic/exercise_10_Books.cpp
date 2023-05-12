#include<stdio.h>
#include<stdint.h>
#include<vector>
#include<cstring>

using namespace std;


class Book{
    private:
        char nameArthor[100];
        char nameBook[100];
        int publishingYear;
        int quantity;
    public:
        Book();
        void setBook();
        const char* getNameBook();
        void getInformationBook();
};

Book::Book(){
    strcpy(nameArthor," ");
    strcpy(nameBook," ");
    this -> publishingYear = 0;
    this -> quantity = 0;
}

const char* Book::getNameBook(){
    return this ->nameBook;
}
void Book::setBook(){
    printf("Enter author of book:");
    scanf("%s", &(this -> nameArthor));
    printf("Enter name of book:");
    scanf("%s", &(this -> nameBook));
    printf("Enter year of publication:");
    scanf("%d" ,&(this -> publishingYear));
    printf("Enter quantity of book:");
    scanf("%d" ,&(this -> quantity));
}

void Book::getInformationBook(){
    printf("Name book:%s\tName author:%s\tPublising year:%d\tQuantity:%d\n", this-> nameBook, this -> nameArthor, this -> publishingYear, this ->quantity);
}
class ManagementBook{
    private:
        vector<Book>database;
    public:
        void addBook();
        void borrowBook();
        void showBook();
        void returnBook();
};

void ManagementBook::addBook(){
    Book book;
    book.setBook();
    database.push_back(book);
}

// void ManagementBook::borrowBook(){
//     char book[100];
//     int quantity;
//     printf("Enter name of book you want to borrow:");
//     scanf("%s",&book);
//     for(int i = 0; i < database.size(); i++){
//         if(database[i].getNameBook() == book){
//             printf("Borrow successful!!");
//         }
//     }
//     printf("Book not found");

// }
void ManagementBook::borrowBook() {
    char book[100];
    int quantity;
    bool foundBook = false;

    printf("Enter the name of the book you want to borrow: ");
    scanf("%s", book);

    for (int i = 0; i < database.size(); i++) {
        if (strcmp(database[i].getNameBook(), book) == 0) {
            foundBook = true;
            printf("Borrow successful!!");
            break;
        }
    }

    if (!foundBook) {
        printf("Book not found.");
    }
}
void ManagementBook::returnBook(){
    char book[100];
    int quantity;
    printf("Enter name of book you want to return:");
    scanf("%s",&book);
    printf("Enter quantity of book you want to return:");
    scanf("%d",&quantity);
    printf("return successful!!!");
}

void ManagementBook::showBook(){
    printf("-------------------------------\n");
    for(Book book : database){
        book.getInformationBook();
    }
}

int main(){
    ManagementBook book;
    int key = 1;
    int choice;
    printf("-----------------------------------");

    do
    {
        printf("\nThis is program ManagementBook");
        printf("\n1.AddBook\n2.BorrowBook\n3.ReturnBook\n4.ShowBook\n5.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            book.addBook();
            break;
        
        case 2:
            book.borrowBook();
            break;
        
        case 3:
            book.returnBook();
            break;
        
        case 4:
            book.showBook();
            break;
        
        case 5:
            key = 0;

        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (key);

    return 0;
}

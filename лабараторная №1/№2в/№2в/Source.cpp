#include <iostream>
#include <vector>


enum class BookType { Fiction, Technical };

class Book {
public:
    Book(std::string author, std::string title, BookType type) :
        author(author), title(title), type(type) {
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getTitle() const {
        return title;
    }

    BookType getType() const {
        return type;
    }

private:
    std::string author;
    std::string title;
    BookType type;
};

int main() {
    std::vector<Book> library;

    library.push_back(Book("Александр Пушкин", "Евгений Онегин", BookType::Fiction));
    library.push_back(Book("Иван Иванов", "Справочник программиста", BookType::Technical));
    library.push_back(Book("Лев Толстой", "Война и мир", BookType::Fiction));
    library.push_back(Book("Петр Петров", "Основы физики", BookType::Technical));
    library.push_back(Book("Аркисян", "Алгебра 9 класс ", BookType::Technical));

    int fictionCount = 0;
    int technicalCount = 0;
    for (const Book& book : library) {
        switch (book.getType()) {
        case BookType::Fiction:
            fictionCount++;
            break;
        case BookType::Technical:
            technicalCount++;
            break;
        default:
            break;
        }
    }
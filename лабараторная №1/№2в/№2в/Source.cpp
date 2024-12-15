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

    library.push_back(Book("��������� ������", "������� ������", BookType::Fiction));
    library.push_back(Book("���� ������", "���������� ������������", BookType::Technical));
    library.push_back(Book("��� �������", "����� � ���", BookType::Fiction));
    library.push_back(Book("���� ������", "������ ������", BookType::Technical));
    library.push_back(Book("�������", "������� 9 ����� ", BookType::Technical));

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
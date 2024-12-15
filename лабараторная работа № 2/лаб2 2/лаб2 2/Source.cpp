#include <iostream>
#include <string>

class Publication {
protected:
    std::string title;
    float price;

public:
    void getdata() {
        std::cout << "name: ";
        std::getline(std::cin, title);
        std::cout << "price: ";
        std::cin >> price;
        std::cin.ignore();
    }

    void putdata() const {
        std::cout << "name : " << title << ", price: " << price << std::endl;
    }
};

class Sales {
protected:
    float sales[3] = { 0.0f };

public:
    void getSalesData() {
        for (int i = 0; i < 3; ++i) {
            std::cout << "sales for 3 months " << (i + 1) << ": ";
            std::cin >> sales[i];
        }
        std::cin.ignore();
    }

    void putSalesData() const {
        for (int i = 0; i < 3; ++i) {
            std::cout << "sales for months " << (i + 1) << ": " << sales[i] << std::endl;
        }
    }
};

class Book : public Publication, public Sales {
private:
    int pages;

public:
    void getdata() {
        Publication::getdata();
        std::cout << "number of pages: ";
        std::cin >> pages;
        std::cin.ignore();
        getSalesData();
    }

    void putdata() const {
        Publication::putdata();
        std::cout << "pages: " << pages << std::endl;
        putSalesData();
    }
};

class Audio : public Publication, public Sales {
private:
    int duration;

public:
    void getdata() {
        Publication::getdata();
        std::cout << "time: ";
        std::cin >> duration;
        std::cin.ignore();
        getSalesData();
    }

    void putdata() const {
        Publication::putdata();
        std::cout << "time: " << duration << "minuts" << std::endl;
        putSalesData();
    }
};

int main() {
    Book myBook;
    myBook.getdata();
    myBook.putdata();

    Audio myAudio;
    myAudio.getdata();
    myAudio.putdata();

    return 0;
}

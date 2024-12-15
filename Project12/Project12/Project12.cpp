#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


class Person {
public:
    virtual void introduce() const = 0; 
    virtual ~Person() {};
};


class Preschooler : public Person {
public:
    void introduce() const override {
        std::cout << "im preschooler!" << std::endl;
    }
};


class Schoolboy : public Person {
public:
    void introduce() const override {
        std::cout << "im schooolboy!" << std::endl;
    }
};


class Student : public Person {
public:
    void introduce() const override {
        std::cout << "im student!" << std::endl;
    }
};


class Worker : public Person {
public:
    void introduce() const override {
        std::cout << "im worcker!" << std::endl;
    }
};


template <typename T>
class PointerArray {
private:
    std::vector<T*> arr; 

public:

    void add(T* ptr) {
        arr.push_back(ptr);
    }

    T*& operator[](size_t index) {
        if (index >= arr.size()) {
            throw std::out_of_range("Индекс вне диапазона!");
        }
        return arr[index];
    }


    size_t size() const {
        return arr.size();
    }


    ~PointerArray() {
        for (T* ptr : arr) {
            delete ptr; 
        }
    }
};

int main() {
    PointerArray<Person> people;

    people.add(new Preschooler());
    people.add(new Schoolboy());
    people.add(new Student());
    people.add(new Worker());

    for (size_t i = 0; i < people.size(); ++i) {
        people[i]->introduce(); 
    }

    return 0;
}

#include <memory>
#include <cstdlib>
#include <ctime>


class Base {
public:
    virtual void display() const {
        std::cout << "its object classa Base." << std::endl;
    }

    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void display() const override {
        std::cout << "its object classa Derived." << std::endl;
    }
};

void add(std::vector<std::unique_ptr<Base>>& storage, std::unique_ptr<Base> obj) {
    storage.push_back(std::move(obj));
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<std::unique_ptr<Base>> storage;

    for (int i = 0; i < 10; ++i) {
        int randomNum = std::rand();
        if (randomNum % 2 == 0) {
            add(storage, std::make_unique<Base>());
        }
        else {
            add(storage, std::make_unique<Derived>());
        }
    }

    for (const auto& obj : storage) {
        obj->display();
    }
    return 0;
}
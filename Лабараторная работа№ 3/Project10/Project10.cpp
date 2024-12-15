#include <iostream>
#include <vector>
#include <memory>

class Detail {
protected:
    Detail() = default;

public:
    virtual ~Detail() = default;
    virtual void display() const = 0;
};

class Assembly : public Detail {
protected:
    Assembly() = default;

public:
    void display() const override {
        std::cout << "eta sborka." << std::endl;
    }

    static std::unique_ptr<Assembly> create() {
        return std::unique_ptr<Assembly>(new Assembly());
    }
};

template<typename T>
void addDetail(std::vector<std::unique_ptr<Detail>>& storage, std::unique_ptr<T> detail) {
    storage.push_back(std::move(detail));
}

int main() {
    std::vector<std::unique_ptr<Detail>> storage;


    addDetail(storage, Assembly::create());

    for (const auto& detail : storage) {
        detail->display();
    }

    return 0;
}

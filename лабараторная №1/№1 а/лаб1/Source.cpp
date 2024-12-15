#include <iostream>
int main() {
    int n;
    std::cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "Distance of element " << arr[i] << " from the beginning of the array: " << &arr[i] - &arr[0] << std::endl;
        std::cout << &arr[i] << std::endl;
    }

    delete[] arr;

    return 0;
}
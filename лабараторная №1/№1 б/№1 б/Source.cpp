#include <iostream>
int main() {
	int* arr = new int[10];
	int i;
	for (i = 0; i < 10; i++) {
		std::cout << "Enter element " << i + 1 << ": " << std::endl;
		std::cin >> arr[i];
	}
	std::cout << &arr[0] << std::endl;
	for (i = 0; i < 10; i++) {
		std::cout << "Distance of element " << arr[i] << " from the beginning of the array: " << &arr[i] - &arr[0] << std::endl;
	}
	delete[] arr;
	return 0;
}
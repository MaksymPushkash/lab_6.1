#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime>   


void generateArray(std::vector<int>& arr, int minVal, int maxVal) {
    for (int& elem : arr) {
        elem = minVal + rand() % (maxVal - minVal + 1);
    }
}

void printArray(const std::vector<int>& arr) {
    for (const int& elem : arr) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void processArray(std::vector<int>& arr, int& sum, int& count) {
    sum = 0;
    count = 0;
    for (int& elem : arr) {
        if (elem > 0 || elem % 2 != 0) {
            sum += elem;
            count++;
            elem = 0;
        }
    }
}

int main() {
    srand(time(0));

    const int SIZE = 27;
    const int MIN_VAL = -35;
    const int MAX_VAL = 25;

    std::vector<int> arr(SIZE);

    generateArray(arr, MIN_VAL, MAX_VAL);

    std::cout << "Початковий масив: " << std::endl;
    printArray(arr);

    int sum = 0, count = 0;
    processArray(arr, sum, count);

    std::cout << "Кількість елементів, що задовольняють критерій: " << count << std::endl;
    std::cout << "Сума цих елементів: " << sum << std::endl;

    std::cout << "Модифікований масив: " << std::endl;
    printArray(arr);

    return 0;
}



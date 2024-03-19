#include <iostream>
#include <vector>

void binarySort(std::vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        int key = arr[i];
        int left = 0;
        int right = i - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = i - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    
    std::cout << "Исходный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    binarySort(arr);

    std::cout << "Отсортированный массив: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
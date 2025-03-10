// lab Task 1 and 2


// ------- Pointers---------


#include <iostream>
using namespace std;
int main() {
    int num = 10;
    int* ptr = &num;

    cout << "Initial value of num: " << num << std::endl;
    cout << "Pointer pointing to value: " << *ptr << std::endl;

    *ptr = 20;

    cout << "Modified value of num: " << num << std::endl;
    cout << "Pointer now points to value: " << *ptr << std::endl;

    return 0;
}
// lab Task 2



// ------- Big O Notation (Loops and Arrays)---------


int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

int main() {
    int arr[] = {3, 5, 1, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxValue = findMax(arr, n);
    
    cout << "Maximum value: " << maxValue << std::endl;
    return 0;
}
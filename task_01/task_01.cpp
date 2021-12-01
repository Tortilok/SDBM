#include <iostream>
#include <random>

using namespace std;

unsigned int maximum(unsigned int array[], int size) {
    unsigned int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int output(unsigned int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "array[" << i << "]= " << array[i] << "\n";
    }
    return 0;
}

int fill_array(unsigned int array[], int size) {
    random_device rd;
    mt19937_64 mersenne(rd());
    for (int i = 0; i < size; i++) {
        array[i] = mersenne();
    }
    return 0;
}

int main()
{   
    cout << "Input size of array:\n";
    int size;
    cin >> size;
    if (size > 1)
    {
        unsigned int* array = new unsigned int[size];
        fill_array(array, size);
        output(array, size);
        cout << "Maximum value in array= " << maximum(array, size) << "\n";
        delete[] array;
    }
    else
    {
        cout << "Еhe size of the array must be greater > 1\n";
    }
    system("pause");
    return 0;
}

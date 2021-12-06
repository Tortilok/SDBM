#include <iostream>
#include <random>

using namespace std;
/**
 * @brief Search MAXIMUM in array
 * 
 * @param array[]  Массив 
 * @param size  Размер массива
 * 
 * 
 */
unsigned int maximum(unsigned int array[], const int size);
/**
 * @brief Вывод массива
 *
 * @param array[]  Массив
 * @param size  Размер массива
 *
 *
 */
int output(unsigned int array[], const int size);
/**
 * @brief Заполнение массива псевдослучаныйми числами
 *
 * @param array[]  Массив
 * @param size  Размер массива
 *
 *
 */
int fill_array(unsigned int array[], const int size); 
/**
 * @brief Проверка ввода размера массива
 *
 * @param string  Сообщение которое хотим вывести перед вводом размера
 *
 *
 */
size_t get_size(const string& message);



int main()
{   
    try
    {
        int size = get_size("Input size for array:\n");
        unsigned int* array = new unsigned int[size];
        fill_array(array, size);
        output(array, size);
        cout << "Maximum value in array= " << maximum(array, size) << "\n";

        if (array != nullptr) {
            delete[] array;
            array = nullptr;
        }
    }
    catch (const std::exception& e)
    {
        cout << "Exception: " << e.what();
    }
    
        

    system("pause");
    return 0;
}

unsigned int maximum(unsigned int array[], int size) {
    unsigned int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}
int output(unsigned int array[], int size)
{
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

size_t get_size(const string& message)
{
    int size = -1;
    cout << message;
    cin >> size;

    if (size < 0)
    {
        throw out_of_range("Incorrect size. Value has to be greater or equal zero.\n");
    }

    return size;
}

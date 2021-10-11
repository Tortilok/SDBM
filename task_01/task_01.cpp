#include <iostream>
#include <random>

using namespace std;


int main()
{   
    random_device rd;
    mt19937_64 mersenne(rd());

    int size;
    unsigned int max;
    cin >> size;
    if (size > 1)
    {
       unsigned int* mas = new unsigned int[size];
        mas[0] = mersenne();
        max = mas[0];
        cout << "Origin array:\n" << "mas[0]= " << mas[0] << "\n";
        
        for (int i = 1; i < size; i++)
        {
            mas[i] = mersenne();
            cout << "mas[" << i << "]= " << mas[i] << "\n";
            if (mas[i] > max)
            {
                max = mas[i];
            }

        }
        cout << "Maximum value in array= " << max << "\n";
        delete[] mas;
    }
    else
    {
        cout << "Еhe size of the array must be greater > 1\n";
    }
    system("pause");
    return 0;
}

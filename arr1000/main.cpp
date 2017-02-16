#include <iostream>
#include <cstring>

using namespace std;

// сделать массив c первоначальным размером 10 -> заполнить 1000 значениями

int* growArray(int* p_arr, int *size, int *count);
void printArray(int p_arr[], int* count);

int main()
{
    int size =  10;
    int count = 0;
    int *p_arr = new int[size];

    while(count < 1000)
    {
        p_arr[count] = count;
        count++;

        if(count == size)
        {
            p_arr = growArray(p_arr, &size, &count);
        }

    }

    printArray(p_arr, &count);

    return 0;
}


 int* growArray(int* p_arr, int *size, int *count)
 {
    *size = (int)(*size * 1.5);

    int *p_arr2 = new int[*size];

    for(int i = 0; i < *count; i++)
    {
        p_arr2[i] = p_arr[i];
    }

    cout << "Array used: " << *size * sizeof (int) << " bytes" << endl;

    delete[] p_arr;

    return p_arr2;
}

void printArray(int p_arr[], int* count) {

  for(int i = 0; i < *count; i++ ){
        cout << p_arr[i] << endl;
    }

}

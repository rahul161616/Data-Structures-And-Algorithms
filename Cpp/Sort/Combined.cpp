#include <iostream>

using namespace std;

class Combine
{
public:
    int n;
    int *arr;

public:
    Combine() {}
    void setData(int n, int arrc[])
    {
        this->n = n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = arrc[i];
        }
    }
    void bubble_sort(int arr[], int n)
    {
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            count = 0;
            for (int j = 0; j < (n - 1 - i); j++)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    count++;
                }
            }
            if (count == 0)
            {
                break;
            }
        }
    }
    void swap(int &a, int &b)
    {
        int temp;
        temp = a;
        a = b;
        b = temp;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
int main()
{
    Combine c;
    int n;

    cout << "Enter the size of the array:" << endl;
    cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    c.setData(n, arr);
    c.bubble_sort(c.arr, n);
    c.display();
    delete[] arr;
}
#include <iostream>

using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n;
    cout << "Enter the size of the array:" << endl;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int count = 0;
    /*Main Logic*/
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
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
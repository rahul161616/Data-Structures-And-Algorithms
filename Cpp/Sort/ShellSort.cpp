#include <iostream>

using namespace std;

void shell_sort(int arr[], int n)
{
    for (int gap = n / 2; gap >= 1; gap = gap / 2)
    {
        for (int j = gap; j < n; j++)
        {
            for (int i = (j - gap); i >= 0; i = i - gap)
            {
                if (arr[i + gap] > arr[i])
                {
                    break;
                }
                else
                {
                    swap(arr[i + gap], arr[i]);
                }
            }
        }
    }
}
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    shell_sort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    delete[] arr;
}
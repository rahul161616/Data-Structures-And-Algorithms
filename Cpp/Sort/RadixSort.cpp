#include <iostream>

using namespace std;
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

void count_sort(int arr[], int n, int pos)
{
    int count[10] = {0};
    int *brr = new int[n];
    for (int i = 0; i < n; i++)
    {
        ++count[(arr[i] / pos) % 10];
    }
    for (int i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--)
    {

        brr[--count[(arr[i] / pos) % 10]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = brr[i];
    }
}

void radix_sort(int arr[], int n)
{
    int max = getMax(arr, n);
    for (int pos = 1; max / pos > 0; pos = pos * 10)
    {
        count_sort(arr, n, pos);
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
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
    radix_sort(arr, n);
    display(arr, n);
    delete[] arr;
}
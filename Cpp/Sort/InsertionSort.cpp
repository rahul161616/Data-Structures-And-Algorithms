#include <iostream>
using namespace std;
void insertion_sort(int arr[], int n)
{
    int temp;
    for (int i = 1; i < n; i++)
    {

        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && (arr[j] > temp))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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
    insertion_sort(arr, n);
    display(arr, n);
    delete[] arr;
}
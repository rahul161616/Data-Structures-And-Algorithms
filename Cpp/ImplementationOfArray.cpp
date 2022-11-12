#include <iostream>

using namespace std;

class Arr
{

    int n;
    int *arr;

public:
    Arr(int n)
    {
        this->n = n;
        arr = new int[n];
    }
    void setData(int *array)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i] = array[i];
        }
    }
    int *getdata()
    {
        return arr;
    }
    void display()
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << endl;
        }
    }
};
int main()
{
    int n, values, arr, *d;
    cout << "Enter the size of the array:" << endl;
    cin >> n;

    int s[n];
    Arr a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> values;
        s[i] = values;
    }
    a.setData(s);
    d = a.getdata();
    for (int i = 0; i < n; i++)
    {
        cout << d[i] << endl;
    }

    // a.display();
}
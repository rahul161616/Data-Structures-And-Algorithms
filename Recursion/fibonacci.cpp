#include <iostream>

using namespace std;

class Fibonacci
{
public:
    int fibo(int n)
    {
        if (n == 1 || n == 2)
            return 1;

        else
        {
            return fibo(n - 1) + fibo(n - 2);
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number:" << endl;
    cin >> n;
    Fibonacci f;
    cout << f.fibo(n);
}
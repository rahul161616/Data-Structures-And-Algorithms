#include <iostream>
#include <Windows.h>

using namespace std;

class Factorial
{
public:
    int factorial(int n)
    {
        cout << "Processing.......\r";

        Sleep(5000);
        if (n == 1 || n == 0)
        {
            return 1;
        }
        else
        {
            return n * factorial(n - 1);
        }
    }
};
int main()
{
    Factorial f;
    int n;
    cout << "Enter the number you want to fact:" << endl;
    cin >> n;
    cout << f.factorial(n) << endl;
}
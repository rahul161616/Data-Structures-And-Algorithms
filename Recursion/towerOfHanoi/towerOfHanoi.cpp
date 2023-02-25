#include <iostream>

using namespace std;
void tower_of_hanoi(int n, char start, char aux, char end)
{ //(number of discs,source,auxillar(helper),destination)
    int count = 0;
    if (n == 1)
    {
        cout << "Move " << start << " to " << end << endl;
        count++;
    }
    else
    {
        tower_of_hanoi(n - 1, start, end, aux);
        tower_of_hanoi(1, start, aux, end);
        tower_of_hanoi(n - 1, aux, start, end);
    }
}

int main()
{
    int n;
    char a, b, c;
    cout << "Enter the number of discs:" << endl;
    cin >> n;
    cout << "Tower of Hanoi of " << n << "discs" << endl;
    tower_of_hanoi(n, 'a', 'b', 'c');
}
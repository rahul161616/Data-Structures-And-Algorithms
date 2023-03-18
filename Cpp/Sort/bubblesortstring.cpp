#include <iostream>
#include <cstring>

using namespace std;

void bubble_sort(char str[])
{
    int n = strlen(str);
    // Traverse through all elements in the list
    for (int i = 0; i < n; i++)
    {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
        {
            // Swap adjacent elements if they are in wrong order
            if (str[j] > str[j + 1])
            {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}

int main()
{
    char char_list[] = "cabfde";
    bubble_sort(char_list);
    cout << char_list << endl;
    return 0;
}

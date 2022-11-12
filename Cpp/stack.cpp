#include <iostream>
#include <conio.h>

using namespace std;

class Stack
{

    int top;
    int *arr;
    int n;

public:
    Stack(int n)
    {
        this->n = n;
        top = -1;
        arr = new int[n];
    }
    void push(int x)
    {
        if (top == n - 1)
        {
            cout << "The Stack is full" << endl;
        }
        else
        {
            top++;
            arr[top] = x;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            empty_statement();
        }
        else
        {
            top--;
        }
    }
    void empty_statement()
    {
        cout << "The Stack is Empty!" << endl;
    }
    void full_statement()
    {
        cout << "The Stack is Full!" << endl;
    }
    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isFull()
    {
        if (top == n - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int topElement()
    {
        return arr[top];
    }
    void print()
    {
        if (isEmpty())
        {
            empty_statement();
        }
        else
        {
            cout << "The elements in the Stack are:" << endl;
            for (int i = 0; i <= top; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }
    int peek(int peekE)
    {
        if (isEmpty())
        {
            empty_statement();
        }
        else
        {
            return arr[peekE];
        }
    }
    int number_of_elements()
    {
        return top + 1;
    }
};
int main()
{
    int n, values, choice;
    int peek_the_element;
    cout << "Enter the size of the Stack:" << endl;
    cin >> n;
    Stack s(n);

    do
    {
        cout << "***************************************" << endl;
        cout << "Enter what you want to do?" << endl;
        cout << "1 for push!" << endl;
        cout << "2 for pop!" << endl;
        cout << "3 for display!" << endl;
        cout << "4 for clearing the screen!" << endl;
        cout << "5 to peek the desired element!" << endl;
        cout << "6 to count the total elements in the stack!" << endl;
        cout << "7 to view the top element!" << endl;
        cout << "8 to check if the stack is empty or full !" << endl;
        cout << "9 to exit the program!" << endl;
        cout << "Enter what you want to do:" << endl;
        cout << "***************************************" << endl;
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cin >> values;
                s.push(values);
            }
        }
        else if (choice == 2)
        {
            s.pop();
        }
        else if (choice == 3)
        {
            s.print();
        }
        else if (choice == 4)
        {
            system("cls");
        }
        else if (choice == 5)
        {
            cout << "Enter the element to peek:" << endl;
            cin >> peek_the_element;
            cout << "The element at " << peek_the_element << " is " << s.peek(peek_the_element) << endl;
        }
        else if (choice == 6)
        {
            cout << "The total elements in the stack is " << s.number_of_elements() << endl;
        }
        else if (choice == 7)
        {
            cout << "The top element is = " << s.topElement() << endl;
        }
        else if (choice == 8)
        {
            if (s.isEmpty())
            {
                cout << "The Stack is Empty!" << endl;
            }
            else
            {
                cout << "The Stack is Full!" << endl;
            }
        }
        else if (choice == 9)
        {
            exit(0);
        }
    } while (choice != 0);
}
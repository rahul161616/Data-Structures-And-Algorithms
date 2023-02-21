#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class StackUsingLinkedList
{
public:
    Node *top; // head
    StackUsingLinkedList() { top = NULL; }
    void push(int data_from_user)
    {
        Node *n = new Node();
        n->data = data_from_user;
        if (top == NULL)
        {
            top = n;
        }
        else
        {
            n->next = top;
            top = n;
        }
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display()
    {
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
};
int main()
{
    StackUsingLinkedList sl;
    sl.push(2);
    sl.push(3);
    sl.push(4);
    sl.push(6);
    sl.display();
    cout << endl;
    sl.pop();
    sl.display();
}
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
    }
    Node(int data)
    {
        this->data = data;
    }
};

class CList
{

    Node *tail;

public:
    CList() { tail = NULL; }
    void insert_at_last(int data_fed_by_user)
    {
        Node *n = new Node();
        n->data = data_fed_by_user;
        if (tail == NULL)
        {
            tail = n;
            tail->next = n;
        }
        else
        {
            n->next = tail->next; // update link first
            tail->next = n;       // adding new node at least
            tail = n;
        }
    }
    void insert_at_beginning(int data_from_user)
    {
        Node *temp = tail->next; // tail->next is the address of the first node it's like head
        Node *n = new Node();
        if (tail == NULL)
        {
            tail->next = n;
            n = tail;
        }
    }
    /**********************************/
    void display()
    {

        if (tail == NULL)
        {
            cout << "List Empty!" << endl;
            return;
        }
        else
        {
            Node *temp = tail->next;
            do
            {

                cout << temp->data << " --> ";
                temp = temp->next;

            } while (temp != tail->next);
            cout << temp->data << endl;
        }
    }
};

int main()
{
    CList l;
    l.insert_at_last(20);
    l.insert_at_last(30);
    l.insert_at_last(40);
    l.insert_at_last(50);
    l.insert_at_last(60);
    l.display();
}
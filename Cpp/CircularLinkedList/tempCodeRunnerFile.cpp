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
            n->next == tail->next; // update link first
            tail->next = n;        // adding new node at least
            tail = n;
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
                if (temp != NULL)
                {
                    cout << temp->data << " --> ";
                    temp = temp->next;
                }
                else
                {
                    break;
                }
            } while (temp != tail->next);
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
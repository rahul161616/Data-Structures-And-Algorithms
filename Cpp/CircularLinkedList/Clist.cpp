// tail->next acts as the head in this list
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
        Node *n = new Node(data_fed_by_user);
        if (tail == NULL)
        {
            tail = n;       // making the new node as tail
            tail->next = n; // setting the adress of the last to first (property of circular linked list)
        }
        else
        {
            n->next = tail->next; // update link first because we don't have a head pointer
            tail->next = n;       // adding new node at least
            tail = n;             // maintaining tail pointer
        }
    }
    void insert_at_beginning(int data_from_user)
    {
        Node *temp = tail->next; // tail->next is the address of the first node it's like head
        Node *n = new Node(data_from_user);
        if (tail == NULL)
        {
            tail->next = n;
            n = tail;
        }
        else
        {
            n->next = tail->next;
            tail->next = n;
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
            cout << endl;
        }
    }
    int counter()
    {
        if (tail == NULL)
        {
            return 0;
        }
        int count = 0;
        Node *temp = tail->next;
        do
        {
            count++;
            temp = temp->next;
        } while (temp != tail->next);
        return count;
    }
    void insert_at_specific_position(int index, int data_from_user)
    {
        Node *n = new Node(data_from_user);
        if (index == 1) // typecast
        {
            insert_at_beginning(data_from_user);
        }
        else if (index >= counter())
        {
            insert_at_last(data_from_user);
        }
        else
        {
            int i = 1;
            Node *temp = tail;
            while (i < index)
            {
                temp = temp->next;
                i++;
            }
            n->next = temp->next;
            temp->next = n;
        }
    }
    void delete_at_first()
    {
        Node *temp = tail->next;
        Node *backup_pointer;
        if (tail == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else if (temp->next == temp)
        {
            tail = NULL;
            free(temp);
        }
        else
        {

            tail->next = temp->next;
            free(temp);
        }
    }
    void delete_at_last()
    {
        Node *last = tail->next;
        Node *second_last;
        if (tail == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else if (last->next == last)
        {
            tail = NULL;
            free(last);
        }
        else
        {
            while (last->next != tail->next)
            {
                second_last = last;
                last = last->next;
            }
            second_last->next = tail->next;
            free(last);
            tail = second_last;
        }
    }
    void delete_at_specific_position(int index)
    {
        Node *temp = tail->next;
        Node *delptr;
        int i = 1;
        int count = counter();
        if (tail == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else if ((index < 0) || (index > count))
        {
            cout << "Out of range!" << endl;
        }
        else if (index <= 1)
        {
            delete_at_first();
        }
        else if (index == counter())
        {
            delete_at_last();
        }
        else
        {
            while (i < index)
            {
                temp = temp->next;
                i++;
            }
            delptr = temp->next;
            temp->next = delptr->next;
            free(delptr);
        }
    }
};

int main()
{
    CList l;
    l.insert_at_last(20);
    l.insert_at_last(30);
    l.insert_at_last(40);
    l.insert_at_beginning(1201);
    l.insert_at_last(50);
    l.insert_at_last(60);
    l.display();
    cout << endl;
    l.insert_at_beginning(600);
    l.display();
    cout << l.counter() << endl;
    l.insert_at_specific_position(8, 100);
    l.display();
    cout << l.counter() << endl;
    l.delete_at_first();
    l.display();
    l.delete_at_last();
    cout << l.counter() << endl;
    l.display();
    l.delete_at_specific_position(7);
    l.display();
}
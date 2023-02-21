#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class Dblist
{
public:
    Node *head, *tail;
    Dblist() { head = NULL; }
    void insertion_at_beg(int data_from_user)
    {
        Node *n = new Node();
        n->data = data_from_user;
        if (head == NULL)
        {
            head = n;
            n->next = NULL;
            n->prev = NULL;
            n = head;
            tail = n;
        }
        else
        {
            head->prev = n;
            n->next = head;
            head = n;
        }
    }
    void insertion_at_last(int data_from_user)
    {
        Node *n = new Node();
        n->data = data_from_user;
        if (head == NULL)
        {
            head = n;
            n->next = NULL;
            n->prev = NULL;
            // head = n; // temp points to where head is pointing and head points to where new iode is pointing
            tail = n;
        }
        else
        {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void insert_at(int index_at, int data_from_user)
    {
        Node *n = new Node();
        n->data = data_from_user;
        Node *temp = head;
        int i = 1;
        int length = count();
        if (index_at == 1)
        {
            insertion_at_beg(data_from_user);
        }
        else
        {

            while (i < index_at - 1)
            {
                temp = temp->next;
                i++;
            }
            n->prev = temp;
            n->next = temp->next;
            temp->next = n;
            n->next->prev = n; // setting the next of the node's previous to new node's
        }
    }
    void insert_After(int index_At, int data_from_user)
    {
        Node *n = new Node();
        n->data = data_from_user;
        Node *temp = head;
        int i = 1;
        int length = count();

        while (i < index_At)
        {
            temp = temp->next;
            i++;
        }
        n->prev = temp;
        n->next = temp->next;
        temp->next = n;
        n->next->prev = n; // setting the next of the node's previous to new node's next
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
    }
    void delete_at_beginnig()
    {
        Node *temp;
        if (head == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else
        {
            temp = head->next;
            delete head;
            head = temp;
            head->prev = NULL;
        }
    }
    void delete_at_last()
    {
        if (head == NULL && tail == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else
        {
            // Node *temp;
            // temp = tail;
            // tail->prev->next = NULL;
            delete tail;
            tail = tail->prev; // updating the tail to the position before it
        }
    }
    void delete_At(int index_At)
    {

        int i = 1, length = count();
        if (index_At == 1)
        {
            delete_at_beginnig();
        }
        else
        {
            Node *temp;
            temp = head;
            while (i < index_At)
            {
                temp = temp->next;
                i++;
            }
            temp->prev->next = temp->next;
        }
    }
    int count()
    {
        Node *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }
};

int main()
{

    Dblist db;
    db.insertion_at_beg(4);
    db.insertion_at_beg(40);
    db.insertion_at_beg(30);
    db.insertion_at_beg(50);
    db.insertion_at_beg(60);
    db.insertion_at_beg(70);
    db.insertion_at_last(10);
    db.insertion_at_last(30);
    db.insertion_at_last(50);
    db.insert_at(5, 6);
    db.insert_After(5, 9);
    db.display();
    cout << endl;
    db.delete_at_beginnig();
    db.delete_at_last();
    db.display();
    cout << endl;
    db.delete_At(4);
    db.insert_at(4, 100);
    db.display();
    cout << endl;
    db.delete_at_last();
    db.display();
}
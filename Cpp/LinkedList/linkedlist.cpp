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
        next = NULL; // head here prepresents address
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{

    Node *head;

public:
    LinkedList() { head = NULL; }
    void insert_at_beginning(int data_fed_by_user)
    {
        Node *n = new Node();
        n->data = data_fed_by_user;
        if (head == NULL)
        {
            head = n;
        }
        else
        {
            n->next = head; // the new points to (head's adress) or the location where the head was pointing
            head = n;       // making the new node n as head
        }
    }
    void insert_at_the_last(int data_fed_by_user)
    {
        Node *n = new Node();
        n->data = data_fed_by_user;
        if (head == NULL)
        {
            head = n; // head points to n
            cout << "Node Appended Succesfully!" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = n; // main logic of insertion at last n the very context
        }
    }
    void insert_at_desired_position(int position_specified_by_user, int data_sent)
    {
        Node *n = new Node();
        Node *temp = head;
        n->data = data_sent;
        for (int i = 1; i < position_specified_by_user - 1; i++)
        {
            temp = temp->next;
        }
        n->next = temp->next;
        temp->next = n;
    }
    void delete_at_last()
    {
        Node *temp;
        if (head == NULL)
        {
            cout << "List Empty" << endl;
        }
        temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    void delete_at_desired_location(int position_specified_by_user)
    {
        Node *temp = head;
        if (head == NULL)
        {
            cout << "Linked List Is Empty!" << endl;
        }
        else if (position_specified_by_user == 1)
        {
            temp = temp->next;
            head = temp;
        }
        else
        {
            int i = 1;
            while (i < position_specified_by_user - 1)
            {
                temp = temp->next;
                i++;
            }
            temp->next = temp->next->next;
        }
    }
    void delete_at_the_beginnig()
    {
        Node *temp;
        temp = head->next;
        head = temp;
    }
    void display()
    {
        if (head == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else
        {
            Node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "-->";
                temp = temp->next;
            }
            cout << "NULL";
        }
    }
    void search(int data_tb_searched)
    {
        Node *temp = head;
        int pos = 0;
        if (temp == NULL)
        {
            cout << "\nData not found" << endl;
        }
        while (temp != NULL)
        {
            if (temp->data == data_tb_searched)
            {

                cout << "\nThe data is found at " << pos + 1 << endl;

                break;
            }
            temp = temp->next;
            pos++;
        }
    }
};
int main()
{
    LinkedList l;
    l.insert_at_beginning(2);
    l.insert_at_the_last(2);
    l.insert_at_the_last(4);
    l.insert_at_the_last(5);
    l.insert_at_the_last(8);
    l.display();

    l.delete_at_last();
    l.insert_at_the_last(9);
    cout << endl;
    l.display();
    cout << endl;
    l.delete_at_desired_location(3);
    l.display();
    cout << endl;
    l.delete_at_the_beginnig();
    l.display();
    cout << endl;
    l.insert_at_the_last(4);
    l.insert_at_the_last(5);
    l.insert_at_the_last(8);
    l.display();
    cout << endl;
    l.insert_at_desired_position(2, 3);
    l.display();
    cout << endl;
    l.delete_at_desired_location(1);
    l.display();
    l.search(9);
    l.search(3);
}
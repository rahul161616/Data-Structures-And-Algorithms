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
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class QueueUsingLinkedList
{
public:
    Node *front;
    Node *rear;
    QueueUsingLinkedList()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int data_from_user)
    {
        Node *n = new Node();
        n->data = data_from_user;
        if (front == NULL && rear == NULL)
        {
            rear = n;
            front = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
    void dequeue()
    {
        if (front == NULL && rear == NULL)
        {
            cout << "List Empty!" << endl;
        }
        else
        {
            Node *temp = front;
            front = front->next;
            free(temp);
        }
    }
    void display()
    {
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
    }
};
int main()
{
    QueueUsingLinkedList ql;
    ql.enqueue(5);
    ql.enqueue(10);
    ql.enqueue(1);
    ql.enqueue(6);
    ql.display();
    cout << endl;
    ql.dequeue();
    ql.display();
}
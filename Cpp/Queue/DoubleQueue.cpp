#include <iostream>

using namespace std;
/*Double Queue are of two types
  Input restricted - Input at one end delete from both
  Output restricted - Input at both delete at one
*/
class DoubleQueue
{
    int front = -1;
    int rear = -1;
    int n;
    int *queue;

public:
    DoubleQueue(int n)
    {
        queue = new int[n];
        this->n = n;
    }
    void insertAtFront(int data_from_user)
    {
        if (isFull())
        {
            cout << "Queue Full!" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[front] = data_from_user;
        }
        else if (front == 0)
        {
            front = n - 1;
            queue[front] = data_from_user;
        }
        else
        {
            front--;
            queue[front] = data_from_user;
        }
    }
    void insertAtRear(int data_from_user)
    {
        if (isFull())
        {
            cout << "Queue Full!" << endl;
        }
        else if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = data_from_user;
        }
        else if (rear == n - 1)
        {
            rear = 0;
            queue[rear] = data_from_user;
        }
        else
        {
            rear++;
            queue[rear] = data_from_user;
        }
    }
    void deleteAtFront()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!" << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == n - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    void deleteAtRear()
    {
        if (isEmpty())
        {
            cout << "Queue Empty!" << endl;
        }
        else if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        {
            rear = n - 1;
        }
        else
        {
            rear--;
        }
    }
    bool isFull()
    {
        if ((front == 0 && rear == (n - 1)) || (front == rear + 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void display()
    {
        int i = front;
        while (i != rear)
        {
            cout << queue[i];
            i = (i + 1) % n;
        }
        cout << queue[rear];
    }
};
int main()
{

    DoubleQueue d(4);
    d.insertAtFront(5);
    d.insertAtFront(6);
    d.insertAtRear(7);
    d.insertAtRear(8);
    d.display();
    cout << endl;
    d.deleteAtFront();
    d.display();
    cout << endl;
    d.deleteAtRear();
    d.display();
}

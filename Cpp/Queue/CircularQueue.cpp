#include <iostream>

using namespace std;

class CircularQueue
{
private:
    int n;
    int *queue;
    int front;
    int rear;

public:
    CircularQueue(int n)
    {
        queue = new int[n];
        front = -1;
        rear = -1;
    }
    void enqueue(int data_to_be_enqueued)
    {
        if (isFull())
        {
            cout << "Queue Full" << endl;
        }
        else if (front == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = data_to_be_enqueued;
        }
        else if (rear == n - 1 && front != 0)
        {
            rear = 0;
            queue[rear] = data_to_be_enqueued;
        }
        else
        {
            rear++;
            queue[rear] = data_to_be_enqueued;
        }
    }
    void dequeue()
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
    bool isFull()
    {
        if ((front == 0) && (rear == n - 1) || (rear = (front) % (n - 1)))
        {
            return 1;
        }
        return 0;
    }
    bool isEmpty()
    {
        if (front == -1 && rear == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "The Queue is Full!" << endl;
        }
        else if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i];
            }
        }
        else
        {
            for (int i = front; i < rear; i++)
            {
                cout << queue[i];
            }
        }
    }
};
int main()
{
    CircularQueue qe(5);
    cout << qe.isEmpty() << endl;
    qe.enqueue(12);
    qe.enqueue(10);
    qe.enqueue(100);
    qe.enqueue(5);
    qe.enqueue(1);
    qe.enqueue(9);
    cout << qe.isFull() << endl;
    qe.display();
    qe.dequeue();
}
#include <iostream>

// isFull is facing issues (line 68s)

using namespace std;

class Queue
{
    int n;
    int *queue;
    int rear = -1;
    int front = -1;

    // data is fed from rear and taken out from front
    //              front->    |   |   |   |   |  <-rear
    // 1 for true
    // 0 for false
public:
    Queue(int n)
    {
        queue = new int[n];
    }
    void enqueue(int data_to_be_enqueued)
    {
        if (isFull())
        {
            cout << "Cannot Add Elements Queue Full!" << endl;
        }
        else if (isEmpty())
        {
            front = rear = 0;
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
        front++;
    }
    int count()
    {
        int count = 0;
        for (int i = front; i <= rear; i++)
        {
            count++;
        }
        return count;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Nothing to display Queue is Empty!" << endl;
        }
        else
        {
            cout << "The elements are: " << endl;
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << endl;
            }
        }
    }
    bool isFull()
    {
        if (rear == (n - 1))
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
        if (rear == -1 && front == -1 || rear < front)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int frontE()
    {
        return queue[front];
    }
};
int main()
{
    int N, choice, count;
    int values;
    cout << "Enter the size of the array:" << endl;
    cin >> N;

    Queue q(N);
    do
    {
        cout << "********************************" << endl;
        cout << " 1 for Enqueue " << endl;
        cout << " 2 for dequeue " << endl;
        cout << " 3 for display " << endl;
        cout << " 4 to check Empty " << endl;
        cout << " 5 for Self Destruction " << endl;
        cout << " 6 to check Full " << endl;
        cout << " 7 to view front element " << endl;
        cout << " 8 to count total number of elements in the Queue " << endl;
        cout << "********************************" << endl;
        cout << "Enter the choice:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the values to be enqueued:" << endl;
            for (int i = 0; i < N; i++)
            {
                cin >> values;
                q.enqueue(values);
            }
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            if (q.isEmpty())
            {
                cout << "Queue Empty" << endl;
            }
            else
            {
                cout << "The Queue is not Empty!" << endl;
            }
            break;
        case 5:
            exit(0);
        case 6:
            if (q.isFull())
            {
                cout << "Queue Full" << endl;
            }
            else
            {
                cout << "Queue not Full!" << endl;
            }
            break;

        case 7:
            cout << "The front element is " << q.frontE() << endl;
            break;

        case 8:
            cout << "There are " << q.count() << " elements in the Queue!" << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
            break;
        }
    } while (choice != 0);
}
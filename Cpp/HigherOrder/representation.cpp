#include <iostream>

using namespace std;

struct Node
{
    int data;
    int power1;
    int power2;
    int power3;
    Node *next;
};
struct Node *head;

void createNode(int x, int p1, int p2, int p3)
{

    Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->power1 = p1;
    n->power2 = p2;
    n->power3 = p3;
    n->next = NULL;
    if (head == NULL)
    {
        head = n;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}
void display()
{
    struct Node *temp = head;
    while (temp != NULL)
    {

        if (temp->data > 0)
        {
            if (temp == head)
            {
                cout << temp->data << " x^" << temp->power1 << "y^" << temp->power2 << "z^" << temp->power3 << " ";
            }
            cout << "+ ";
            cout << temp->data << " x^" << temp->power1 << "y^" << temp->power2 << "z^" << temp->power3 << " ";
        }
        else
        {
            cout << temp->data << " x^" << temp->power1 << "y^" << temp->power2 << "z^" << temp->power3 << " ";
        }
        temp = temp->next;
    }
}
int main()
{
    struct Node a;
    createNode(3, 3, 1, 1);
    createNode(-5, 2, 3, 0);
    createNode(5, 2, 3, 0);
    createNode(8, 0, 2, 1);
    createNode(-4, 1, 7, 3);
    createNode(2, 7, 1, 1);
    display();
}
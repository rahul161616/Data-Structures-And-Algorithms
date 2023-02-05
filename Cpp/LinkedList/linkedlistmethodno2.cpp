#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *adres;
};
void count_no_of_heads(struct node *temp)
{
    {

        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->adres;
        }
    }
}
void addAtEnd(struct node *head, int data1)
{
    node *ptr, *temp;
    ptr = head;
    temp = new struct node();
    temp->data = data1;
    temp->adres = NULL;
    while (temp->adres != NULL)
    {
        cout << temp->data << "->";
        temp = temp->adres;
    }
    ptr->adres = temp;
}
void addAtBeg(struct node *head, int data2)
{
    node *ptr;
    ptr->data = data2;
    ptr->adres = NULL;
    head = ptr;
}
int main()
{
    node *head = NULL;
    node *temp = NULL;
    node *temp2 = NULL;

    head = new node();
    temp = new node();
    temp2 = new node();

    head->data = 45;    // head can access data's value
    head->adres = temp; // and also the adress

    temp->data = 2000;
    temp->adres = temp2;

    temp2->data = 3;
    temp2->adres = NULL;

    count_no_of_heads(head);
    addAtEnd(head, 22);
    cout << "\n";
    addAtEnd(head, 1221);
    count_no_of_heads(head);
}
#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *adres;
};

int main()
{
    struct node *head = new struct node();

    /*First node*/
    head->data = 45;    // head can access data's value
    head->adres = NULL; // and also the adress

    /*Second node*/
    struct node *temp = new struct node();
    temp->data = 2000;
    temp->adres = NULL;
    head->adres = temp;

    /*third node*/
    struct node *temp3 = new struct node();
    temp3->adres = NULL;
    temp3->data = NULL;
    temp->adres = temp3;

   
        return 0;
}

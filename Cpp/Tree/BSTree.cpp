#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};
class BSTree
{
public:
    Node *root; // pointer to root node
    BSTree()
    {
        root = NULL; // creating an empty tree
    }
    Node *insert(Node *root, int data)
    {

        Node *n = new Node(data);
        if (root == nullptr)
        {
            root = n;
            return n;
        }
        else if (data <= root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
        return root;
    }
    void search(Node *root, int data)
    {
        if (root == nullptr)
        {
            cout << "No data!" << endl;
        }
        else if (root->data == data)
        {
            cout << "Data Found" << endl;
        }
        else if (data <= root->data)
        {
            return search(root->left, data); // if coming data is less than the root
                                             // control goes to left part of the data
                                             // finding the data
        }
        else
        {
            return search(root->right, data);
        }
    }
    void inOrderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            inOrderTraversal(root->left);
            cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }
    void preOrderTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            cout << root->data << " ";

            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
    void postTraversal(Node *root)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            postTraversal(root->left);
            postTraversal(root->right);
            cout << root->data << " ";
        }
    }
    Node *deleteNode(Node *root, int key)
    {
        if (root == NULL)
            return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else
        {
            // node with only one child or no child
            if (root->left == NULL)
            {
                Node *temp = root->right;
                delete (root);
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                delete (root);
                return temp;
            }
            // node with two children: get inorder successor
            Node *temp = minValueNode(root->right);
            // copy the inorder successor's content to this node
            root->data = temp->data;
            // delete the inorder successor
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current && current->left != NULL)
            current = current->left;
        return current;
    }
};
int main()
{
    BSTree t;
    t.root = t.insert(t.root, 30);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 20);
    t.root = t.insert(t.root, 40);
    t.root = t.insert(t.root, 100);
    t.search(t.root, 50);
    t.search(t.root, 100);
    t.inOrderTraversal(t.root);
    cout << endl;
    t.postTraversal(t.root);
    cout << endl;
    t.preOrderTraversal(t.root);
    return 0;
}
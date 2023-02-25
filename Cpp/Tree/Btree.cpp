#include <iostream>

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

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void addNode(int data)
    {
        Node *newNode = new Node(data);

        if (root == nullptr)
        {
            root = newNode;
        }
        else
        {
            Node *focusNode = root;
            Node *parent;

            while (true)
            {
                parent = focusNode;

                if (data < focusNode->data)
                {
                    focusNode = focusNode->left;
                    if (focusNode == nullptr)
                    {
                        parent->left = newNode;
                        return;
                    }
                }
                else
                {
                    focusNode = focusNode->right;
                    if (focusNode == nullptr)
                    {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }
    void inOrderTraversal(Node *focusNode)
    {
        if (focusNode != nullptr)
        {

            inOrderTraversal(focusNode->left);
            std::cout << focusNode->data << " ";
            inOrderTraversal(focusNode->right);
        }
    }

    void preOrderTraversal(Node *focusNode)
    {
        if (focusNode != nullptr)
        {
            std::cout << focusNode->data << " ";
            preOrderTraversal(focusNode->left);
            preOrderTraversal(focusNode->right);
        }
    }

    void postOrderTraversal(Node *focusNode)
    {
        if (focusNode != nullptr)
        {
            postOrderTraversal(focusNode->left);
            postOrderTraversal(focusNode->right);
            std::cout << focusNode->data << " ";
        }
    }
};

int main()
{
    BinaryTree tree;

    tree.addNode(50);
    tree.addNode(25);
    tree.addNode(75);
    tree.addNode(12);
    tree.addNode(37);
    tree.addNode(43);
    tree.addNode(30);

    tree.preOrderTraversal(tree.root);
    std::cout << std::endl;
    tree.inOrderTraversal(tree.root);
    std::cout << std::endl;
    tree.postOrderTraversal(tree.root);
    return 0;
}

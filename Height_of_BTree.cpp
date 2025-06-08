#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Node
{
public:
    int val;
    Node* left,*right;
    Node(int val)
    {
        this->val = val;
        left = right = nullptr;
    }
};

void create_Tree(Node* root)
{
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(6);

    root->right->left->left = new Node(5);
}

int height(Node* root)
{
    queue<Node*> Q;
    if(root == nullptr)
        return -1;

    Q.push(root);

    int ht = 0;
    while(!Q.empty())
    {
        int sz = Q.size();
        ht++;
        for(int i=0;i<sz;i++)
        {
            Node* Addr = Q.front();
            Q.pop();
            if(Addr->left)
                Q.push(Addr->left);
            if(Addr->right)
                Q.push(Addr->right);
        }
    }
    return ht;
}

int main()
{
    cout << "Height Of B-Tree" << endl;

    Node* root = new Node(1);
    create_Tree(root);


    cout << "Height Of B Tree = " << height(root) << endl;


    return 0;
}

#include <iostream>
#include <vector>

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
    root->right->right = new Node(7);

    root->right->left->right = new Node(5);
    root->right->left->right->left = new Node(6);

    root->right->right->right = new Node(8);
    root->right->right->right->left = new Node(9);
}

int max_sum(Node* root,int& maxi)
{
    if(root == nullptr)
        return 0;

    int lsum = max_sum(root->left,maxi);
    int rsum = max_sum(root->right,maxi);

    maxi = max(maxi,root->val+lsum+rsum);

    return root->val+max(lsum,rsum);
}

int main()
{
    cout << "Maximum Path Sum of a B-Tree" << endl;

    Node* root = new Node(1);
    create_Tree(root);


    int maxi = -1;
    max_sum(root,maxi);

    cout << "Maximum Path sum = " << maxi << endl;

    return 0;
}

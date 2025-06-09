#include <iostream>
#include <vector>

using namespace std;

// Balanced B-Tree -->  Height difference between Left and Right Subtree is at max 1

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
    root->right->right = new Node(5);

    root->right->right->left = new Node(6);
}

int height_1(Node* root)
{
    if(root == nullptr)
        return 0;

    int lh = height_1(root->left);
    int rh = height_1(root->right);

    return max(lh,rh)+1;
}

bool IsBalanced_sol1(Node* root)
{
    if(root == nullptr)
        return true;

    int lh = height_1(root->left);
    int rh = height_1(root->right);

    if(abs(lh-rh)>1)
        return false;

    // Check for Left and Right are also balanced
    bool left_check = IsBalanced_sol1(root->left);
    bool right_check = IsBalanced_sol1(root->right);

    return left_check && right_check;
}

int height_2(Node* root)
{
    if(root == nullptr)
        return 0;

    int lh = height_2(root->left);
    int rh = height_2(root->right);

    if(lh==-1||rh==-1)
        return -1;
    if(abs(lh-rh)>1)
        return -1;

    return max(lh,rh)+1;
}

bool IsBalanced_sol2(Node* root)
{
    if(root == nullptr)
        true;

    int ht = height_2(root);
    if(ht==-1)
        return false;
    else
        return true;
}

int main()
{
    cout << "Balanced B-Tree" << endl;
    // Height difference between Left and Right Subtree is at max 1

    Node* root = new Node(1);
    create_Tree(root);

    bool res1 = IsBalanced_sol1(root);
    cout << "Using Sol1 Is B-Tree Balanced = " << res1 << endl;
    bool res2 = IsBalanced_sol1(root);
    cout << "Using Sol2 Is B-Tree Balanced = " << res2 << endl;
    return 0;
}

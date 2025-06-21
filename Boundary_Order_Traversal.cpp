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
    Node(int v)
    {
        val = v;
        left = right = nullptr;
    }
};

void createTree(Node* root)
{
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    root->right->right->left = new Node(7);
    root->right->right->right = new Node(8);
}

void print_v(vector<int> temp)
{
    for_each(temp.begin(),temp.end(),[](int n)
                                        {
                                            cout << n << ",";
                                        });
}

bool isLeaf(Node* root)
{
    if(root->left==nullptr && root->right == nullptr)
        return true;
    else
        return false;
}

void LeftBoundary(Node* root,vector<int>& res)
{
    if(!root)
        return;

    Node* cur = root->left;
    while(cur!=nullptr && !isLeaf(cur))
    {
        res.push_back(cur->val);
        if(cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void LeafNodes(Node* root,vector<int>& res)
{
    if(root==nullptr)
        return;

    LeafNodes(root->left,res);
    if(isLeaf(root))
        res.push_back(root->val);
    LeafNodes(root->right,res);
}

void RightBoundary(Node* root,vector<int>& res)
{
    if(root==nullptr)
        return;

    Node* cur = root->right;
    vector<int> temp;
    while(cur!=nullptr && !isLeaf(cur))
    {
        temp.push_back(cur->val);
        if(cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }

    for(int i=temp.size()-1;i>=0;i--)
        res.push_back(temp[i]);
}

int main()
{
    cout << "Boundary Order Traversal" << endl;
    vector<int> res;
    Node* root = new Node(1);
    createTree(root);

    if(root==nullptr)
    {
        cout << "Tree Empty" << endl;
    }
    else
    {
        res.push_back(root->val);

        if(isLeaf(root)) // Single node
        {
            cout << "Tree is Single Node" << endl;
        }
        else
        {
            LeftBoundary(root,res);
            LeafNodes(root,res);
            RightBoundary(root,res);
        }

        cout << " RES  -- >  " << endl;
        print_v(res);
    }

    return 0;
}

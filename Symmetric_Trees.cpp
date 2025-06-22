#include <iostream>
#include <vector>
#include <queue>
#include <map>
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

void createTree1(Node* root)
{
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);
}

void createTree2(Node* root)
{
    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(3);
    root->right->right = new Node(4);
}

void print_v(vector<int> temp)
{
    for_each(temp.begin(),temp.end(),[](int n)
                                        {
                                            cout << n << ",";
                                        });
}

bool IsSymmetricTree(Node* root1,Node* root2)
{
    if(root1==nullptr || root2==nullptr)
        return (root1==root2);

    if(root1->val != root2->val)
        return false;

    return IsSymmetricTree(root1->left,root2->right) && IsSymmetricTree(root1->right,root2->left);
}

int main()
{
    cout << "Symmetric  Trees" << endl;
    Node* root1 = new Node(1);
    Node* root2 = new Node(1);

    createTree1(root1);
    createTree2(root2);

    bool res1 = IsSymmetricTree(root1->left,root1->right);

    cout << "Is Tree-1 Symmetric = " << res1 << endl;

    bool res2 = IsSymmetricTree(root2->left,root2->right);

    cout << "Is Tree-2 Symmetric = " << res2 << endl;

    return 0;
}

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

// Doesn't work always
bool generateLevelOrder(Node* root)
{
    
    if(root==nullptr)
        return true;
        
    queue<Node*> q1;
    q1.push(root);
    
    queue<Node*> q2;
    q2.push(root);
    
    while(!q1.empty() && !q2.empty())
    {
        Node* node1 = q1.front();
        q1.pop();
        
        Node* node2 = q2.front();
        q2.pop();
        
        if(node1->data!=node2->data)
            return false;
            
        if(node1->left)
            q1.push(node1->left);
            
        if(node2->right)
            q2.push(node2->right);
            
            
        if(node1->right)
            q1.push(node1->right);
            
        if(node2->left)
            q2.push(node2->left);
        cout << "q = " << q1.size() << " q2 = " << q2.size() << endl;
        
    }
    cout << "q = " << q1.size() << " q2 = " << q2.size() << endl;
    if(q1.size()==0 && q2.size()==0)
        return true;
    else
        return false;
}

// Optimal Solution Works Always
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

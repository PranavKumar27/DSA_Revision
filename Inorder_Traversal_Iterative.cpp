#include <iostream>
#include <vector>
#include <stack>
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

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    root->right = new Node(3);
}

void print_v(vector<int> v)
{
    for_each(v.begin(),v.end(),[](int x)
                                {
                                    cout << x << ",";
                                });
}

vector<int> generateInorder(Node* root)
{
    Node* temp = root;
    stack<Node*> St;
    vector<int> res;

    while(true)
    {
        if(temp!=nullptr)
        {
            St.push(temp);
            temp = temp->left;
        }
        else
        {
            if(St.empty())
                break;

            temp = St.top();
            res.push_back(temp->val);
            St.pop();
            temp = temp->right;
        }
    }
    return res;
}

// Root left Right
vector<int> generatePreorder(Node* root)
{
    Node* temp = root;
    stack<Node*> St;
    vector<int> res;

    while(true)
    {
        if(temp)
        {
            res.push_back(temp->val);
            St.push(temp);
            temp = temp->left;
        }
        else
        {
            if(St.empty())
                break;

            temp = St.top();
            St.pop();
            temp = temp->right;
        }
    }
    return res;
}

int main()
{
    cout << "Using For Loop Print InOrder" << endl;
    Node* root = new Node(1);
    create_Tree(root);

    vector<int> InOrder = generateInorder(root);

    print_v(InOrder);

    cout << endl;

    vector<int> PreOrder = generatePreorder(root);

    print_v(PreOrder);

    return 0;
}

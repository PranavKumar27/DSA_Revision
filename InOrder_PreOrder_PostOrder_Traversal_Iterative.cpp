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
    root->right = new Node(7);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

}

void print_v(vector<int> v)
{
    for_each(v.begin(),v.end(),[](int x)
                                {
                                    cout << x << ",";
                                });
}

// TC --> O(N)
// SC --> O(N)
vector<int> generateINorder(Node* root)
{
    cout << __FUNCTION__ << endl;
    if(root == nullptr)
        return {};

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
// TC --> O(N)
// SC --> O(N)
vector<int> generatePREorder(Node* root)
{
    cout << __FUNCTION__ << endl;
    if(root == nullptr)
        return {};

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

// Root left Right
// TC --> O(N)
// SC --> O(N)
vector<int> generatePREorder_Sol2(Node* root)
{
    cout << __FUNCTION__ << endl;
    if(root == nullptr)
        return {};

    Node* temp = root;
    stack<Node*> St;
    vector<int> res;

    St.push(root);
    while(!St.empty())
    {
        temp = St.top();
        St.pop();
        res.push_back(temp->val);

        if(temp->right)
        {
            St.push(temp->right);
        }
        if(temp->left)
        {
            St.push(temp->left);
        }
    }
    return res;
}

// TC --> O(2N) since elements inserted first and then Popped back
// SC --> O(2N)
vector<int> generatePOSTorder(Node* root)
{
    cout << __FUNCTION__ << endl;
    if(root == nullptr)
        return {};

    stack<Node*> S1;
    stack<Node*> S2;
    vector<int> postOrder;

    S1.push(root);
    Node* temp;
    while(!S1.empty())
    {
        temp = S1.top();
        S2.push(temp);
        S1.pop();

        if(temp->left)
            S1.push(temp->left);
        if(temp->right)
            S1.push(temp->right);
    }

    while(!S2.empty())
    {
        postOrder.push_back(S2.top()->val);
        S2.pop();
    }
    return postOrder;
}

// Note: In the Solution we generate PostOrder Using single Stack
vector<int> generatePOSTorder_Sol2(Node* root)
{
    cout << __FUNCTION__ << endl;
    if(root == nullptr)
        return {};

    stack<Node*> St;
    vector<int> postOrder;
    Node* cur=root,*temp;

    while(cur!=nullptr || !St.empty())
    {
        if(cur!=nullptr)
        {
            St.push(cur);
            cur = cur->left;
        }
        else
        {
            temp = St.top()->right;
            if(temp==nullptr)
            {
                temp = St.top();
                St.pop();
                postOrder.push_back(temp->val);

                while(!St.empty() && St.top()->right == temp) // Check if temp is right of St.top() then it means St.top() is root of temp
                {
                    // Here we have already traversed the right of St.top() and pop the root now
                    temp = St.top();
                    St.pop();
                    postOrder.push_back(temp->val);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
    return postOrder;
}


int main()
{
    cout << "Using For Loop Print InOrder" << endl;
    Node* root = new Node(1);
    create_Tree(root);

    vector<int> InOrder = generateINorder(root);

    print_v(InOrder);

    cout << endl;

    vector<int> PreOrder = generatePREorder(root);

    print_v(PreOrder);

    cout << endl;

    vector<int> PreOrder_2 = generatePREorder_Sol2(root);

    print_v(PreOrder_2);

    cout << endl;

    vector<int> PostOrder = generatePOSTorder(root);

    print_v(PostOrder);

    cout << endl;

    vector<int> PostOrder_2 = generatePOSTorder_Sol2(root);

    print_v(PostOrder_2);


    return 0;
}

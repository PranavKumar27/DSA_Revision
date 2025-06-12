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

void create_Tree_2(Node* root)
{
    root->left = new Node(2);
    root->right = new Node(3);

    root->right->left = new Node(4);
    root->right->right = new Node(6);

    root->right->left->left = new Node(5);
    root->right->left->right = new Node(7);
}

bool check_via_PreOrder(Node* root1,Node* root2)
{
    //if(root1==nullptr && root2 == nullptr)
    //    return true;

    if(root1==nullptr || root2 == nullptr)
        return (root1==root2);

    if( (root1->val == root2->val) &&
        check_via_PreOrder(root1->left,root2->left) &&
        check_via_PreOrder(root1->right,root2->right) )
        return true;
    else
        return false;
}

bool check_via_LevelOrder(Node* root1,Node* root2)
{
    queue<Node*> Q1,Q2;
    if(root1==nullptr || root2 == nullptr)
        return (root1==root2);

    Q1.push(root1);
    Q2.push(root2);

    while(!Q1.empty() && !Q2.empty())
    {
        int sz1 = Q1.size();
        int sz2 = Q2.size();
        if(sz1!=sz2)
            return false;

        for(int i=0;i<sz1;i++)
        {
            Node* front1 = Q1.front();
            Q1.pop();

            Node* front2 = Q2.front();
            Q2.pop();


            if(front1->val != front2->val)
                return false;

            if(front1->left)
                Q1.push(front1->left);

            if(front1->right)
                Q1.push(front1->right);

            if(front2->left)
                Q2.push(front2->left);

            if(front2->right)
                Q2.push(front2->right);
        }
    }
    if(Q1.empty() && Q2.empty())
        return true;
    else
        return false;
}

int main()
{
    cout << "Identical Trees" << endl;
    Node* T1 = new Node(1);
    Node* T2 = new Node(1);
    Node* T3 = new Node(1);


    create_Tree(T1);
    create_Tree(T2);
    create_Tree_2(T3);

    bool res_1 = check_via_PreOrder(T1,T2);
    cout << "Is T1 and T2 identical ? ==> " << res_1 << endl;

    bool res_2 = check_via_LevelOrder(T2,T1);
    cout << "Is T1 and T3 identical ? ==> " << res_2 << endl;


    return 0;
}

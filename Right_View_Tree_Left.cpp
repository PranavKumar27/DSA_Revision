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

void createTree(Node* root)
{
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->right->left = new Node(8);
    root->right->left->right = new Node(9);
}

void print_v(vector<int> temp)
{
    for_each(temp.begin(),temp.end(),[](int n)
                                        {
                                            cout << n << ",";
                                        });
}


/*
# --> means Overlapping
        5#6 means 5 and 6 are on same x same vertical line

        Bottom View 4 8 6 9 7
            y
            |   -3    -2     -1      0     1     2      3
            |
            |                        1
            |                 2             3
            |          4            5#6          7
            |    N           N#8          N#9#N     N
            |
            |---------------------------------------------x

*/

// Using level Order Traversal
// TC-> O(N)
// SC -> O(N) 
void RightView_UsingLevelOrder(Node* root,vector<int>& res)
{
    queue<Node*> q;

    if(root==nullptr)
        return;

    q.push(root);

    while(!q.empty())
    {
        int sz = q.size();

        for(int i=0;i<sz;i++)
        {
            Node* node = q.front();
            q.pop();

            if(i==sz-1)  // Last Node of Level i.e. RightMost Node
                res.push_back(node->val);

            if(node->left)
                q.push(node->left);

            if(node->right)
                q.push(node->right);
        }
    }

}

void RightView_UsingReverseLevelOrder(Node* root,vector<int>& res)
{
    queue<Node*> q;

    if(root==nullptr)
        return;

    q.push(root);

    while(!q.empty())
    {
        int sz = q.size();

        for(int i=0;i<sz;i++)
        {
            Node* node = q.front();
            q.pop();

            if(i==0)  // First Node of Level i.e. RightMost Node since Right is inserted first
                res.push_back(node->val);

            if(node->right)
                q.push(node->right);

            if(node->left)
                q.push(node->left);

        }
    }

}

// Better Solution than LevelOrder Traversal since SC-> O(Height of tree)
vector<int> Right_Ans;
// RightView
// Using Reverse PreOrder Traversal Root Right left
// TC-> O(N)
// SC -> O(Height) but for Skew Trees O(N) 

void RightView(Node* node,int level)
{
    if(node==nullptr)
        return;

    if(level==Right_Ans.size()) // first time when it reaches a new level
        Right_Ans.push_back(node->val);

    // Move to right first and reach a new level
    RightView(node->right,level+1);
    RightView(node->left,level+1);
}

vector<int> Left_Ans;
// LeftView
// Using Reverse PreOrder Traversal Root Right left
void LeftView(Node* node,int level)
{
    if(node==nullptr)
        return;

    if(level==Left_Ans.size()) // first time when it reaches a new level
        Left_Ans.push_back(node->val);

    // Move to left first and reach a new level
    LeftView(node->left,level+1);
    LeftView(node->right,level+1);
}

int main()
{
    cout << "Right View of Tree" << endl;

    Node* root = new Node(1);
    createTree(root);

    vector<int> res1;
    RightView_UsingLevelOrder(root,res1);
    cout << "\n Using RightView_UsingLevelOrder Res -->" << endl;
    print_v(res1);

    vector<int> res2;
    RightView_UsingReverseLevelOrder(root,res2);
    cout << "\n Using RightView_UsingReverseLevelOrder Res -->" << endl;
    print_v(res2);

    RightView(root,0);
    cout << "\n Using Recursive RightView Res -->" << endl;
    print_v(Right_Ans);

    LeftView(root,0);
    cout << "\n Using Recursive LeftView Res -->" << endl;
    print_v(Left_Ans);

    return 0;
}

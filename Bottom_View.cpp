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

void BottomView(Node* root,vector<int>& res)
{
    queue<pair<Node*,int>> q; // <Node* , vertical>
    map<int,int> mp; // <vertical , Node->val>

    if(root == nullptr)
        return;

    q.push({root,0});

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node* node = it.first;
        int x = it.second;

        mp[x] = node->val;

        if(node->left)
            q.push({node->left,x-1});

        if(node->right)
            q.push({node->right,x+1});
        // Common Mistake here is that we write root instead of node
    }

    for(auto it:mp)
        res.push_back(it.second);

}

int main()
{
    cout << "Bottom View of Tree" << endl;

    Node* root = new Node(1);
    createTree(root);

    vector<int> res;
    BottomView(root,res);

    print_v(res);

    return 0;
}

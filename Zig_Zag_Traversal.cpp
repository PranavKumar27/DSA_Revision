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

void print_2D_v(vector<vector<int>> ZigZag)
{
    for(auto d:ZigZag)
    {
        print_v(d);
        cout << endl;
    }
}

// TC --> O(N) + O(N) for reverse of vector
// SC --> O(N)

void ZigZagTraversal(Node* root,vector<vector<int>>& ZigZag)
{
    if(root==nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty())
    {
        int sz = q.size();

        vector<int> temp;
        for(int i=0;i<sz;i++)
        {
            Node* front = q.front();
            q.pop();
            temp.push_back(front->val);

            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);

        }
        if(!flag)
            reverse(temp.begin(),temp.end());
        ZigZag.push_back(temp);

        // For each level change , change the flag as well
        flag = !flag; // flag = 0 means L->R change flag for each level
                      // flag = 1 means R->L change flag for each level
    }
}

// TC --> O(N)
// SC --> O(N)
// No need to use reverse function Here
void ZigZagTraversal_Sol2(Node* root,vector<vector<int>>& ZigZag)
{
    if(root==nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    bool flag = true;
    while(!q.empty())
    {
        int sz = q.size();

        vector<int> temp(sz);
        for(int i=0;i<sz;i++)
        {
            Node* front = q.front();
            q.pop();

            if(front->left)
                q.push(front->left);
            if(front->right)
                q.push(front->right);

            int index = (flag)?i:sz-1-i;
            temp[index] = front->val;

        }

        ZigZag.push_back(temp);

        // For each level change , change the flag as well
        flag = !flag; // flag = 0 means L->R change flag for each level
                      // flag = 1 means R->L change flag for each level
    }
}


int main()
{
    cout << "Zig Zag Traversal" << endl;
    Node* root = new Node(1);
    createTree(root);

    vector<vector<int>> ZigZag;
    ZigZagTraversal_Sol2(root,ZigZag);

    print_2D_v(ZigZag);

    return 0;
}

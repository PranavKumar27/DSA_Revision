#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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

    //root->right->right->left = new Node(7);
    //root->right->right->right = new Node(8);
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

/*
        Top View 4 2 1 3 7
            x
            |
            |
            |               1
            |        2                3
            |    4        5       N        7
            | N    N   6      N
            |
            |---------------------------------------------y

    */

void findTopView(Node* root,vector<int>& res)
{
    queue<pair<Node*,int>> q; // <Node,vertical>
    map<int,int> mp; // <Vertical,Val>

    if(root == nullptr)
        return;

    q.push({root,0});

    while(!q.empty())
    {
        Node* node = q.front().first;
        int x = q.front().second;
        q.pop();

        if(mp.find(x)==mp.end())
        {
            mp[x] = node->val;
        }

        if(node->left != nullptr)
            q.push({node->left,x-1});
        if(node->right!=nullptr)
            q.push({node->right,x+1});
    }

    for(auto d:mp)
    {
        res.push_back(d.second);
    }
}
int main()
{
    cout << "Top View Of Tree" << endl;

    Node* root = new Node(1);
    createTree(root);

    vector<int> res;
    findTopView(root,res);

    cout << "RES -->" << endl;
    print_v(res);

    return 0;
}

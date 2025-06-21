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

    root->left->left->left = new Node(9);
    root->left->right->right = new Node(8);

    root->right->right->right = new Node(10);
}

void print_v(vector<int> temp)
{
    for_each(temp.begin(),temp.end(),[](int n)
                                        {
                                            cout << n << ",";
                                        });
}

struct Node_Index
{
    Node* node;
    int x; // vertical
    /*
            x
            |
            |
            |            1
            |        2         3
            |    4       5
            |               6       7
            | 9              8         10
            |---------------------------------------------y

    */

    int y; // horizontal or level
};

void print_2D_v(vector<vector<int>> ZigZag)
{
    for(auto d:ZigZag)
    {
        print_v(d);
        cout << endl;
    }
}

void verticalOrderTraversal(Node* root,vector<vector<int>>& res)
{
    // consider root as vertical index = 0 and level = 0
    queue<Node_Index> q;
    if(root==nullptr)
        return;

    map<int,map<int,multiset<int>>> mpp;
    Node_Index node = {root,0,0};

    q.push(node);

    while(!q.empty())
    {
        Node_Index front = q.front();
        q.pop();

        int x = front.x;
        int y = front.y;
        Node* n = front.node;

        cout << "{ " << n->val << "," << x << "," << y << "}" << endl;

        mpp[x][y].insert(n->val);

        /*
        if(mpp.find(v_index)!=mpp.end())
        {
             cout << "v_index Found = " << v_index << endl;
             map<int,multiset<int>> mp = mpp[v_index];
             if(mp.find(level_index)!=mp.end())
             {
                 cout << "inserting val = " << n->val << endl;
                 mp[level_index].insert(n->val);
                 mpp[v_index] = mp;
             }
             else
             {
                 multiset<int> ms;
                 ms.insert(n->val);
                 mp[level_index] = ms;
                 mpp[v_index] = mp;
             }
        }
        else
        {
            multiset<int> ms;
            ms.insert(n->val);
            map<int,multiset<int>> mp;
            mp[level_index] = ms;
            mpp[v_index] = mp;
        }

        */
        if(n->left)
        {
            q.push(Node_Index{n->left,x-1,y+1});
            //cout << "Left = " << n->left->val << endl;
        }
        if(n->right)
        {
            q.push(Node_Index{n->right,x+1,y+1});
            //cout << "Right = " << n->right->val << endl;
        }

    }

    for(auto dd:mpp)
    {
        // At Vertical order
        // Merge all value of all levels at same vertical order
        vector<int> temp;
        for(auto d:dd.second)
        {
            temp.insert(temp.end(),d.second.begin(),d.second.end());
        }
        res.push_back(temp);
    }

}

int main()
{
    cout << "Vertical Order Traversal" << endl;
    Node* root = new Node(1);
    createTree(root);

    vector<vector<int>> res;
    verticalOrderTraversal(root,res);

    print_2D_v(res);

    return 0;
}

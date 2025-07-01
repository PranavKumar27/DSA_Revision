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


// Optimal Sol
// TC --> O(N)
// SC --> O(N)
bool path_Sol2(Node* root,int data,vector<int>& v)
{
    if(root==nullptr)
        return false;

    v.push_back(root->val);
    if(root->val == data)
        return true;

    if(path_Sol2(root->left,data,v) ||
       path_Sol2(root->right,data,v) ) // Either is true we return True
        return true;

    v.pop_back();
    return false;
}

// RAW SOLUTION
bool path_Sol1(Node* root,int data,vector<int>& v)
{
    if(root==nullptr)
        return false;

    v.push_back(root->val);
    if(root->val == data)
        return true;

    /*
    if(root->left==nullptr && root->right==nullptr)
    {
        int sz = v.size()-1;
        v.erase(v.begin()+sz);
        return false;
    }
    */

    bool ltree = path_Sol1(root->left,data,v);
    bool rtree = path_Sol1(root->right,data,v);


    if(!(ltree||rtree))
    {
        auto itr = find(v.begin(),v.end(),root->val);
        if(itr!=v.end())
        {
            v.erase(itr);
        }
    }

    return ltree||rtree;


}


int main()
{
    cout << "Path from Root to Node" << endl;

    Node* root = new Node(1);
    createTree(root);

    int dest_Node_data;
    do
    {
        cout << "Enter Dest : ";
        cin >> dest_Node_data;

        vector<int> res;
        if(path_Sol2(root,dest_Node_data,res))
        {
            print_v(res);
            cout << endl;
        }
        else
        {
            cout << "No path Exists" << endl;
        }
    }while(dest_Node_data!=-1);

    return 0;
}

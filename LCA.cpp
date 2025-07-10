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
    cout << __FUNCTION__ << endl;
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(8);
    root->right->right = new Node(9);

    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
}

void print_v(vector<int> temp)
{
    for_each(temp.begin(),temp.end(),[](int n)
                                        {
                                            cout << n << ",";
                                        });
    cout << endl;
}

bool findPath(Node* root,int dest,vector<int>& path)
{
    if(root == nullptr)
        return false;

    path.push_back(root->val);
    if(root->val == dest)
        return true;

    bool l = findPath(root->left,dest,path);
    bool r = findPath(root->right,dest,path);

    if(l||r) // path found
      return l||r;
    else
        path.pop_back();

    return l||r;
}

int find_Ancestor_Sol1(Node* root,int src,int dest)
{
    cout << __FUNCTION__ << endl;
    vector<int> path1;
    findPath(root,src,path1);
    cout << "Path1 =";
    print_v(path1);

    vector<int> path2;
    findPath(root,dest,path2);
    cout << "Path2 =";
    print_v(path2);


    // find last common in path-1 and path-2

    int sz1 = path1.size();
    int sz2 = path2.size();
    int index=0;
    int lca = -1;
    while(index<sz1 && index<sz2)
    {
        if(path1[index]==path2[index])
            lca = path1[index];
        else
            break;
        index++;
    }
    return lca;
}


Node* find_Ancestor_Sol2(Node* root,int src,int dest)
{
    if(root==nullptr)
        return root;

    if(root->val == src || root->val == dest)
        return root;

    Node* l = find_Ancestor_Sol2(root->left,src,dest);

    Node* r = find_Ancestor_Sol2(root->right,src,dest);

    if(l==nullptr)
        return r;
    else if(r==nullptr)
        return l;
    else
        return root;

    /*
    if(l==nullptr && r!=nullptr)
        return r;
    else if(l!=nullptr && r==nullptr)
        return l;
    else if(l!=nullptr && r!=nullptr)
        return root;
    else
        return nullptr;
    */

}

int main()
{
    cout << "Least Common Ancestor" << endl;
    Node* root = new Node(1);
    createTree(root);

    int src = 4;
    int dest = 7;

    int lca_1 = find_Ancestor_Sol1(root,src,dest);

    cout << "LCA using sol1 = " << lca_1 << endl;


    int lca_2 = find_Ancestor_Sol2(root,src,dest)->val;

    cout << "LCA using sol2 = " << lca_2 << endl;

    return 0;

}

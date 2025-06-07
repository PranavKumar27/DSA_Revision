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

    root->right->left = new Node(6);
    root->right->right = new Node(7);

}

void print_v(vector<int> v)
{
    for_each(v.begin(),v.end(),[](int x)
                                {
                                    cout << x << ",";
                                });
}


// TC --> O(3*N)
// SC --> O(3*N)
void generateAllTreeOrders(Node* root,
                            vector<int>& PreOrder,
                            vector<int>& InOrder,
                            vector<int>& PostOrder )

{
   if(root == nullptr)
    return;

   stack<pair<Node*,int>> st;
   int freq = 1;
   st.push({root,freq});
   while(!st.empty())
   {
       int cnt = st.top().second;
       Node* Node_Addr = st.top().first;

       if(cnt == 1)
       {
           PreOrder.push_back(Node_Addr->val);
           st.top().second++;
           if(Node_Addr->left!=nullptr)
           {
               st.push({Node_Addr->left,freq});
           }
       }
       else if(cnt==2)
       {
           InOrder.push_back(Node_Addr->val);
           st.top().second++;
           if(Node_Addr->right!=nullptr)
           {
               st.push({Node_Addr->right,freq});
           }
       }
       else
       {
           PostOrder.push_back(Node_Addr->val);
           st.pop();
       }
   }
}

int main()
{
    Node* root = new Node(1);
    create_Tree(root);

    vector<int> PreOrder,InOrder,PostOrder;

    generateAllTreeOrders(root,PreOrder,InOrder,PostOrder);

    cout << "InOrder :: " ;
    print_v(InOrder);

    cout << endl;

    cout << "PreOrder :: " ;
    print_v(PreOrder);

    cout << endl;

    cout << "PostOrder :: " ;
    print_v(PostOrder);

    cout << endl;
    return 0;
}

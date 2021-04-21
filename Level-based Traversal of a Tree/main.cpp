#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

// Represents arbitrary tree.  May or may not be a BST.
class TreeNode {
public:
   int data;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int d=0, TreeNode* l=nullptr, TreeNode *r = nullptr):data(d), left(l), right(r) {}
};

//Implement: put the integers fromt the tree into vector<int> v in level order
void level_order (vector<int> &v, TreeNode *root) {
   if (root == NULL) {}
   else{
      queue<TreeNode*> que;
      TreeNode* ptr;
      que.push(root);          /* Insert the root node in the queue */

      while(!que.empty()) {
         ptr = que.front();      /* get a Tree node from head of the queue */
         que.pop();
         if (ptr != NULL)
            v.push_back(ptr->data);        /* mark the node visited */
         if (ptr->left != NULL) /* move the left child node of the tree node in the queue */
            que.push(ptr->left);  
         if (ptr->right != NULL) /* move the right child node of the tree node in the queue */
            que.push(ptr->right);   
       } 
    }
}

int main()
{
   vector<int> v;
   
   TreeNode *r1 = new TreeNode(10, new TreeNode(5), new TreeNode(100));
   level_order(v,r1);
   
   for(auto d: v)
      cout << d << " ";
   cout << endl;
   
   r1->left->left = new TreeNode(0);
   r1->right->left = new TreeNode(99);
   
   v.clear();
   level_order(v,r1);
   for(auto d: v)
      cout << d << " ";
   cout << endl;

   
   return 0;  
}

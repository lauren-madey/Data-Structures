11.18 Level-based Traversal of a Tree

In this lab, you need to implement a traversal of a tree that prints each level in order starting from the root. For example, if the root of a BST was 10, and it's left child was 5 and its right child was 100, it would produce the order: 10 5 100. Notice that the root goes first since its the first level, followed by 5 and 100 on the second level.

Now suppose 5's left child was 0 and 100's left child was 99, then it would print: 10 5 100 0 99. It adds 0 and 99 last because they are on the third level and the nodes in each level are printed in order from left to right.

You're given the following class. It always represents a binary tree but it may or may not be a Binary Search Tree. The integers in the tree may not necessarily have an ordering, so your solution should not rely on the content of the tree to help it.

class TreeNode { public: TreeNode *left; TreeNode *right; int data; TreeNode(int d=0, TreeNode* l=nullptr, TreeNode *r = nullptr):data(d), left(l), right(r) {} };

Implement:

`void level_order(std::vector<int> &v, TreeNode *root);`

Insert the integers found in the nodes of the tree into the vector in level order.

Hint: the easiest way to solve this problem is by using one of the graph traversals we've learned.

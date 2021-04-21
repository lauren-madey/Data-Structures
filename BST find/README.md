## 8.13 Assignment: BST Find
Implement a function to find a node in a binary search tree. Using the following class and function definition:
```
class BTNode {
public:
   int item;
   BTNode *left;
   BTNode *right;
   BTNode(int i, BTNode *l=nullptr, BTNode *r=nullptr):item(i),left(l),right(r){}
};

BTNode *root = nullptr;

BTNode* find(int i) {
     // implement
}
```
If a node with a matching value is found, return a pointer to it. If no match is found, return nullptr.

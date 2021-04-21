## 8.12 Assignment: BST Insert

Implement a function to insert a node into a binary search tree. Using the following class and function definition:
```
class BTNode {
public:
   int item;
   BTNode *left;
   BTNode *right;
   BTNode(int i, BTNode *l=nullptr, BTNode *r=nullptr):item(i),left(l),right(r){}
};

BTNode *root = nullptr;

void insert(int i) {
     // implement
}
```
If the value to be inserted is already in the BST, then it should not be inserted a second time.

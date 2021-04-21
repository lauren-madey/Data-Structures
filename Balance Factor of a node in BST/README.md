## 8.17 Calculate the balance factor of a node in a BST.

Using the following definition for a BST node:

```
class BTNode {
public:
  int data;
  BTNode *left;
  BTNode *right;
  BTNode(int d,BTNode *l=nullptr,BTNode *r=nullptr)
    :data(d),left(l),right(r)
  {}
};
```
Implement a function to calculate the balance factor of a node in a BST. The function prototype must match the following function:

````
int balance_factor(BTNode *subtree)
{
   // IMPLEMENT
   return -2;
}
```

You may implement other functions to help you. In particular, you may want to implement a function to calculate a node's height.

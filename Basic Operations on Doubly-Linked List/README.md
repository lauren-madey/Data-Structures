##5.21 Assignment: Basic Operations on Doubly-Linked List
In this problem you will implement a few functions for a doubly-linked list for integers using the following node class:
```
class node { public: int data; node *prev; node *next; node(int d=0, node *p=nullptr, node *n=nullptr):data(d), prev(p), next(n) {} };
```
```
node *head = nullptr; node *tail =nullptr;
```
Your code may assume that the head and tail global variables are head and tail pointer of the list. They start out as nullptr, and your functions will modify them as needed for list operations. The functions you need to implement are as follows:

- `insert(int x,node* n=nullptr)`: add x after node n; add to beginning if n==nullptr
- `remove(node*)`: remove node pointed to by n
- `find(int x)`: return the first node with the value x, nullptr if not found
- `reverse()`: reverse the contents of the list

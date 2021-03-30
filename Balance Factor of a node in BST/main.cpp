/*
ZYBOOKS
8.17 Calculate the balance factor of a node in a BST.
Using the following definition for a BST node:

class BTNode {
public:
  int data;
  BTNode *left;
  BTNode *right;
  BTNode(int d,BTNode *l=nullptr,BTNode *r=nullptr)
    :data(d),left(l),right(r)
  {}
};
Implement a function to calculate the balance factor of a node in a BST. The function prototype must match the following function:

int balance_factor(BTNode *subtree)
{
   // IMPLEMENT
   return -2;
}
You may implement other functions to help you. In particular, you may want to implement a function to calculate a node's height.
*/
#include <iostream>
#include <fstream>
#include <random>

// DO NOT MODIFY BTNode
class BTNode {
public:
  int data;
  BTNode *left;
  BTNode *right;
  BTNode(int d,BTNode *l=nullptr,BTNode *r=nullptr)
    :data(d),left(l),right(r)
  {}
};

int computeHeight(BTNode *node) {
   int height;
  if (node->left == nullptr && node->right == nullptr)
    height = 0;
  else if (node->left && node->right == nullptr)
    height = computeHeight(node->left) + 1;
  else if (node->left == nullptr && node->right)
    height = computeHeight(node->right) + 1;
  else
    height = std::max(computeHeight(node->right), computeHeight(node->left)) + 1;
  return height;
}

// DO NOT CHANGE FUNCTION PROTOTYPE
int balance_factor(BTNode *subtree)
{
  int left = -1, right = -1;
  if(subtree==nullptr) return 0;
  if(subtree->left)
    left = computeHeight(subtree->left);
  if(subtree->right)
    right = computeHeight(subtree->right);
  return left - right;

  // IMPLEMENT
  return -2;
}

// DO NOT MODIFY ANY OF THE FUNCTIONS BELOW. THEY ARE USED FOR TESTING


void print_result(int bf)
{
  std::cout << "Tree has balance factor = " << bf << "." << std::endl;      
}

void print_feedback(int bf, std::ofstream &feedback)
{
  feedback << "Tree has balance factor = " << bf << "." << std::endl;      
}


int main()
{
   BTNode *root = new BTNode(100, 
    new BTNode(25, new BTNode(0, nullptr, new BTNode(16))), 
    new BTNode(125,nullptr,new BTNode(2132)));
  int ret = balance_factor(root);
  print_result(ret);
  return 0;
}

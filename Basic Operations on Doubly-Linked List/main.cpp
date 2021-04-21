#include <iostream>
using namespace std;

// DO NOT MODIFY class node
class node {
public:
    int data;
    node *prev;
    node *next;
    node(int d=0, node *p=nullptr, node *n=nullptr):data(d), prev(p), next(n) {}
};

node *head = nullptr;
node *tail =nullptr;

// MODIFY THE FOLLOWING FUNCTIONS

//1. insert(int x,node* n=nullptr):  add x after node n; add to beginning if n==nullptr

void insert(int x, node *n=nullptr)
{
   if(n == nullptr) {
    node *t = new node(x, nullptr, head);
    if(head != nullptr) {
      t->next = head;
      head->prev = t;
    } else {
      tail = t;
    }
    head = t;
  } else {
    node *t = new node(x, n, n->next);
    n->next = t;
    if(t->next != nullptr) {
      t->next->prev = t;
    } else {
      tail = t;
    }
  }
}

//2.  remove(node*): remove node pointed to by n

void remove(node *n) 
{
  if(n != nullptr) {
    node *prev = n->prev;
    node *next = n->next;

    if(prev != nullptr) {
      prev->next = next;
    } else {
      head = next;
    }
    if(next != nullptr) {
      next->prev = prev;
    } else {
      tail = prev;
    }
    delete n;
  } 
}

//3.  find(int x): return the first node with the value x, nullptr if not found

node* find(int x)
{
   node *n = head;
  while(n != nullptr) {
    if(n->data == x) { return n; }
    n = n->next;
  }
   return nullptr;  
}

//4. reverse(): reverse the contents of the list

void reverse()
{
 node *start = head;
  tail = head;
  head = NULL;
  
  while(start != nullptr) {
    node *curr = start;
    start = start->next;
    curr->next = head;
    head = curr;
  }
}

// DO NOT MODIFY FUNCTIONS BELOW THIS COMMENT

bool empty()
{
   return head==nullptr;  
}

void print(std::string msg)
{
   std::cout << msg << ": ";
   node *tmp = head;
   while (tmp)
     {
        std::cout << tmp->data << " " ;
        tmp = tmp->next;  
     }
   std::cout << std::endl;
}

int main()
{
   // add 0, 1, 2 to the list
   insert(2);  
   insert(1);  
   insert(0);  
   // print them out!
   print("list");
   return 0;
}

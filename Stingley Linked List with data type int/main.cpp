#include <iostream>

// Item Class
// format of data that goes into node
class Item{
public:
    int s;

    Item(int a_s =0){
        s=a_s;
    }
};

// Node Class
// format of a node
class Node{
public:
    Item item;
    Node *next;
    Node(Item i){
        item=i;
        next= nullptr;
    }
};

// List Class
// format of list
class List{
private:
    Node *head;
    Node *tail;
public:
    List() {
        //list is empty
        head = nullptr;
        tail = nullptr;
    }

    void append(Item a);
    bool remove(Item &a);
    bool empty();
};

// append to end
void List::append(Item a){
    Node *node = new Node(a);
    if (head== nullptr){
        //list is empty so set head and tail to node
        head=node;
        tail=node;
    }
    else{ //list is not empty
        //put new node at end of list
        tail->next=node; //current tail's next now points to new node
        tail=node; // tail pointer now points to new node
    }
}

bool List::remove(Item &copy)
{
    if (!empty()) // if list is not empty
    {
        copy = head->item; // return copy
        Node *tmp = head->next;
        delete head; // delete the node
        head = tmp;  // update the head
        if (tmp==nullptr) // removed last element
            tail = nullptr;
        return true;
    }
    return false; // nothing in list
}


bool List::empty()
{
    // if head is NULL, list is empty
    return head==nullptr;
}

// Singlely Linked List Transversal
/*
ListNode *tmp = head;
while(tmp!=nullptr) // not at end of list
{
  // get the item out and use it if needed
  // go to next node in the list
  tmp = tmp->next;
}
*/


int main() {
    List l;
    // add stuff to l
    // remove stuff from l
    // check if l is empty
    return 0;
}

#include <iostream>

class BTNode {
public:
    int item;
    BTNode *left;
    BTNode *right;
    BTNode(int i, BTNode *l=nullptr, BTNode *r=nullptr):item(i),left(l),right(r){}
};

BTNode *root = nullptr;

BTNode *find(int i) {
    //BTNode *n = new BTNode(i, nullptr, nullptr);
    if(root == nullptr){
        return nullptr;
    }
    else{
        BTNode *tmp = root;
        while (tmp != nullptr){
            if(i < tmp->item){ // new data goes to left
                if(tmp->item == i) return tmp;
                if (tmp->left == nullptr) return nullptr;
                else tmp = tmp->left;
            }
            else{ // new data goes right
                if(i == tmp->item) return tmp;
                if (tmp->right == nullptr) return nullptr;
                else tmp = tmp->right;
            }
        }
    }
    return nullptr;
}

int main()
{
    root = new BTNode(10, new BTNode(1), new BTNode(20));

    BTNode *t1 = find(10);
    if (t1)
        std::cout << "Found " << t1->item << std::endl;
    else
        std::cout << "Should have found 10." << std::endl;


    BTNode *t2 = find(1);
    if (t1)
        std::cout << "Found " << t2->item << std::endl;
    else
        std::cout << "Should have found 1." << std::endl;

    BTNode *t3 = find(20);
    if (t3)
        std::cout << "Found " << t3->item << std::endl;
    else
        std::cout << "Should have found 20." << std::endl;

    BTNode *t4 = find(100);
    if (t4)
        std::cout << "Should have found 20." << std::endl;
    else
        std::cout << "Did not find 100." << std::endl;


    return 0;
}

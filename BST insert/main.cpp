#include <iostream>

class BTNode {
public:
    int item;
    BTNode *left;
    BTNode *right;
    BTNode(int i, BTNode *l=nullptr, BTNode *r=nullptr):item(i),left(l),right(r){}
};

BTNode *root = nullptr;

void insert(int i) {
    BTNode *n = new BTNode(i, nullptr, nullptr);
    if(root == nullptr){
        root=n;
    }
    else{
        BTNode *tmp = root;
        while (tmp != nullptr){
            if(n->item < tmp->item){ // new data goes to left
                if(tmp->left == nullptr){
                    tmp->left=n; break;
                }
                else tmp=tmp->left;
            }
            else{ // new data goes right
                if(n->item == tmp->item) break;
                if(tmp->right == nullptr){
                    tmp->right=n; break;
                }
                else tmp=tmp->right;
            }
        }
    }
}

int main()
{
    insert (50);
    insert (150);
    insert (100);

    if (root)
    {
        std::cout << "root = " << root->item << std::endl;
        if (root->left)
            std::cout << "root->left = " << root->left->item << std::endl;
        if (root->right)
            std::cout << "root->right = " << root->right->item << std::endl;
    }

    return 0;
}

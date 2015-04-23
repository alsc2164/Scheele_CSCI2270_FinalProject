#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <vector>
struct node
{
    int value;
    node* parent;
    node* left;
    node* right;
};

class tree
{
private:
    node* root;
    std::vector<int> order;
    int sum;
    int height;
    int average;
    int mode;
    int length;
    int treeHEIGHT;
public:
    tree();
    ~tree();
    void addNode(int v);
    void deleteNode();
};

#endif // TREE_H_INCLUDED

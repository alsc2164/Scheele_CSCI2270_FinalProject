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
    node *searchTree(node *treeNode, int v);
<<<<<<< HEAD
    node *searchTreeValueCount(node *treeNode, int v);
=======
>>>>>>> bdaa3881b4abc6bc2742eb4914fae60bbb9eae86
    node *print(node *n);
public:
    tree();
    ~tree();
    void addNode(int v);
    void deleteNode(int v);
    void printOrder();
};

#endif // TREE_H_INCLUDED

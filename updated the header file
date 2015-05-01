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
    int treeHEIGHT;
    node *searchTree(node *treeNode, int v);
    //node *searchTreeValueCount(node *treeNode, int v);
    node *print(node *n);
    node *build(node *n);
    int treeHeight(node *p);
    //node* maximum(node* n);

public:
    tree();
    ~tree();
    void addNode(int v);
    void deleteNode(int v);
    void printOrder();
    int maximum();
    int minimum();
    int ave();
    int total();
    int frequency(int n);
    int print_numbers_forward_and_backward();
    int treeH();
    void output();
    int length();
};

#endif // TREE_H_INCLUDED

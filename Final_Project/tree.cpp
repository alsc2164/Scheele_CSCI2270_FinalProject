#include "tree.h"
#include <string>

tree::tree()
{
  root = NULL;
}
tree::~tree()
{

}
void tree::addNode(int s)
{
  if(root == NULL)
  {
    root = new node;
    root->value = s;
    root->parent = NULL;
    root->left = NULL;
    root->right = NULL;
    return;
  }
  else
  {
    node *x = root;
    node *p = root;
    int test = root->value;
    while(x != NULL)
    {
      if(x->value > s)
      {
        p = x;
        x = x->left;
      }
      else
      {
        p = x;
        x = x->right;
      }
    }
    if(p->value > s)
    {
      x = new node;
      p->left = x;
      x->parent = p;
      x->left = NULL;
      x->right = NULL;
      x->value = s;
    }
    else
    {
      x = new node;
      p->right = x;
      x->parent = p;
      x->left = NULL;
      x->right = NULL;
      x->value = s;
    }
  }
}

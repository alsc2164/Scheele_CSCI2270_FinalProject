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

node *tree::searchTree(node * treeNode, int v)
{
    //node *treeNode = root;
    if(treeNode == NULL)
    {
        return NULL;
    }
    else if(treeNode->value == v)
        return treeNode;
    else
    {
        if(v.compare(treeNode->value) < 0)
        {
            return searchTree(treeNode->left,value);
        }
        else
            return searchTree(treeNode->right, value);
    }
}





void tree::deleteNode(int s)
{
    node * foundNode = searchMovieTree(root,value);
    if(foundNode != NULL)
    {
        if(foundNode->left == NULL && foundNode->right == NULL)
        {
            if(foundNode->parent->left == foundNode)
            {
                foundNode->parent->left = NULL;
            }
            else
                foundNode->parent->right = NULL;
            delete foundNode;
        }
        else if(foundNode->right == NULL)
        {
            if(foundNode->parent->left == foundNode)
            {
                foundNode->parent->left = foundNode->left;
            }
            else
                foundNode->parent->right = foundNode->left;
            delete foundNode;
        }
        else if(foundNode->left == NULL)
        {
            if(foundNode->parent->left == foundNode)
            {
                foundNode->parent->left = foundNode->right;
            }
            else
                foundNode->parent->right = foundNode->right;
            delete foundNode;
        }
        else
        {
            node * replaceNode = foundNode->right;

            while(replaceNode->left != NULL)
            {
                replaceNode = replaceNode->left;
            }

            foundNode->value = replaceNode->value;
            if(replaceNode->right != NULL)
            {
                replaceNode->right->parent = replaceNode->parent;
            }
            if(replaceNode->parent->left == replaceNode)
            {
                replaceNode->parent->left = replaceNode->right;
            }
            else
                replaceNode->parent->right = replaceNode->right;
            delete replaceNode;
        }
    }
    else
        cout<<"Value not found."<<endl;
}
}

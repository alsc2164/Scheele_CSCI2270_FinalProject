#include "tree.h"
#include <string>
#include <iostream>
#include <fstream>


using namespace std;
int counter = 0;
tree::tree()
{
  root = NULL;
}
tree::~tree()
{

}

//adds a node to the tree and positions it in the correct place by adjusting the tree need be. (Adds a node given by user)
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

//searches the tree for a value chosen by the user
node *tree::searchTree(node * treeNode, int v)
{
    //node *treeNode = root;
    if(treeNode == NULL)
    {
        return NULL;
    }
    else if(treeNode->value == v)
    {
        return treeNode;
    }
    else
    {
        if(treeNode->value > v )
        {
            return searchTree(treeNode->left, v);
        }
        else
            return searchTree(treeNode->right, v);
    }
}
//deletes a node given by the user, and adjusts the tree need be
void tree::deleteNode(int v)
{
    node * foundNode = searchTree(root, v);
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
    }
node* tree::print(node* n)
{
    node *x = n;
    if(x->left!=NULL){
        print(x->left);
    }
    std::cout<< x->value << ", ";
    order.push_back(x->value);
    if(x->right!=NULL){
        print(x->right);
    }
}
node* tree::build(node* n)
{
    node *x = n;
    if(x->left!=NULL){
        build(x->left);
    }
    order.push_back(x->value);
    if(x->right!=NULL){
        build(x->right);
    }
}
void tree::printOrder()
{
    order.clear();
    print(root);
    std::cout << std::endl;
}

//prints the maximum value in the tree
int tree::maximum()
{
    node *x = root;
    while(x->right != NULL)
    {
        x = x->right;
    }
    return x->value;
}

//prints the minimum value in the tree
int tree::minimum()
{
    node *x = root;
    while(x->left != NULL)
    {
        x = x->left;
    }
    return x->value;
}

int tree::total()
{
    order.clear();
    build(root);
    sum = 0;
    for(int i = 0; i < order.size(); i++)
    {
        sum = sum + order[i];
    }
    return sum;
}
int tree::ave()
{
    total();
    return sum/order.size();
}
int tree::frequency(int n)
{
	
    order.clear();
    build(root);
    int counter = 0;
    for(int i = 0; i <order.size(); i++)
    {
        if(order[i] == n)
        {
            counter++;
        }
    }
    if(counter == 0)  // Contribution to project
    {
		cout << n << " does not exist on the list. Please enter another word." << endl;  //When the user enter word they wish to find the frequency of that does not exist on the text file
	}		// print out the statement to inform the user that the word they enter does not exist.
    return counter;
}

int tree::print_numbers_forward_and_backward()    //Contribution to project
{
        int array [10];		//Basically, this method when runs will propmt the user for 10 input integer values
        int temp;
        for (int i =0; i<10; i++)
        {
        cout << "Enter integer number: " << endl;
        cin >> array[i];
        }
        for (int i=0; i<10; i++)
        {
                for (int j=0; j<9; j++)		//Then, it goes into quick sort to put the entered values in order
                {
                        if(array[j]>array[j+1])
                        {
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
                        }
                }
        }
        cout << "The integers in ascending order are : ";
        for (int i=0;i<10;i++)   // print out whatever the numbers user entered in order
        { 
           cout <<"\n";
           cout <<array[i];
           cout << "\n";
        } 
        cout << "The integers in reverse order are: ";   //print out whatever the numbers the user entered in reverse order
        for(int i = 9; i>=0;  i--)
        {
			cout <<"\n";
           cout <<array[i];
           cout << "\n";
	   }
			
        return 0; 
 }


int tree::treeHeight(node *p)
{
    if(p == NULL)
    {
        return -1;
    }
    int left = treeHeight(p->left);
    int right = treeHeight(p->right);
    return 1 + std::max(left, right);
}
int tree::length()
{
    build(root);
    return order.size();
}
int tree::treeH()
{
    int temp = treeHeight(root);
    return temp;
}
void tree::output()
{
    order.clear();
    build(root);
    ofstream outfile;
    outfile.open("outfile.txt");
    outfile << "Output File:" << std::endl;
    outfile << "Numbers in order: ";
    for(int i = 0; i < order.size()-1; i++)
    {
        outfile << order[i] << ", ";
    }
    outfile << order[order.size()-1] << std::endl;
    outfile << "Number of data points: " << length() << endl;
    outfile << "Maximum: " << maximum() << " Minimum: " << minimum() << std::endl;
    outfile << "Total: " << total() << " Average: " << ave() << std:: endl;
    outfile.close();
}

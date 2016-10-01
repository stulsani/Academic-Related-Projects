/*
Author: Sumeet tulsani
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "rbtree.h"

using std::cout;
using std::setw;
using std::endl;

/*
/////////////////////////////////////////////////////////////////////////////
RBTree constructor
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::RBTree()
{
    nil = new Node();
    nil -> color = 'B';
    root = nil;
}

/*
/////////////////////////////////////////////////////////////////////////////
RBTree Destructor
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::~RBTree()
{
    Node* temp = new Node();
    temp = root;
    while(temp-> left != nil)
    {
        temp = temp-> left;
        delete temp;
    }
    while(temp-> right != nil)
    {
        temp = temp-> right;
        delete temp;
    }
    delete root;
}

/*
/////////////////////////////////////////////////////////////////////////////
RBTree Node parameterized constructor
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node::Node(const string& key, const string& value, Node* nil)
{
    this-> key = new string(key);
    this-> value = new string(value);
    this-> left = nil;
    this-> right = nil;
    this-> parent = nil;
}

/*
/////////////////////////////////////////////////////////////////////////////
RBTree Node constructor without parameters
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node::Node()
{

}

/*
/////////////////////////////////////////////////////////////////////////////
RBTree Node Destructor
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node::~Node()
{
    delete key;
    delete value;
}

void RBTree::rbPrintTree()
{
    reverseInOrderPrint(root,0);
}

void RBTree::reverseInOrderPrint(Node *x, int depth) {
   if ( x != nil ) {
      reverseInOrderPrint(x->right, depth+1);
      cout << setw(depth*4+4) << x->color << " ";
      cout << *(x->key) << " " << *(x->value) << endl;
      reverseInOrderPrint(x->left, depth+1);
   }
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: key to be inserted with it's value
DESC: New node element is made and passed to rbtreeinsert function
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBTree::rbInsert(const string& key, const string& value)
{
    Node* element = new Node(key,value,nil); //constructor initialization
    rbInsert(element);
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: key to be deleted with it's value
DESC: New node element is made and passed to rbtreedelete function. It calls
      preddessesor and successor function to check for duplicates, if
      duplicates are found it checks for value of duplicate elements, if
      it is same then it passes the node for deleteting
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBTree::rbDelete(const string& key, const string& value)
{
    Node* x = new Node();
    x = rbTreeSearch(root,key);
    Node* y = new Node();
    Node* z = new Node();
    vector<Node*> checkptr;  //Node* type vector for holding elements
    //check if element is found and it is equal to key
    if(x != nil && *x-> key == key)
    {
        y = rbTreeSuccessor(x);
        z = rbTreePredecessor(x);
        //check if value is same
        if(*x-> value == value)
        {
            checkptr.push_back(x);
        }
        //successor check if it is null or not
        while(y != nil && *y-> key == key)
        {
            if(*y-> value == value)
            {
                checkptr.push_back(y);
            }
            y = rbTreeSuccessor(y);
        }
        //predecessor check if it is null or not
        while(z != nil && *z-> key == key)
        {
            if(*z-> value == value)
            {
                checkptr.push_back(z);
            }
            z = rbTreePredecessor(z);
        }
    }
    //loop to pass elements from vector to delete function one by one
    for(unsigned int i = 0;i < checkptr.size();i++)
    {
        rbDelete(checkptr[i]);
    }
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to inserted is passed as argument
DESC: Pseudo code to insert node into rbtree
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBTree::rbInsert(Node* z)
{
    Node* x,*y;
    y = nil;
    x = root;
    while(x != nil)
    {
        y = x;
        if(*z -> key < *x -> key)
        {
            x = x -> left;
        }
        else
        {
            x = x -> right;
        }
    }
    z -> parent = y;
    if(y == nil)
    {
        root = z;
    }
    else
    {
        if(*z -> key < *y -> key)
        {
            y -> left = z;
        }
        else
        {
            y -> right = z;
        }
    }
    z -> left = nil;
    z -> right = nil;
    z -> color = 'R';
    rbInsertFixup(z);
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to inserted is passed as argument
DESC: Pseudo code to fix the properties of inserted node in rbtree . It
      checks for property 2 and 4 that are not voileted
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBTree::rbInsertFixup(Node* z)
{
     Node *y;
    while(z -> parent -> color == 'R')
    {
        if(z -> parent == z -> parent -> parent -> left)
        {
            y = z -> parent -> parent -> right;
            if(y -> color == 'R')
            {
                z -> parent -> color = 'B';
                y -> color = 'B';
                z -> parent -> parent -> color = 'R';
                z = z -> parent -> parent;
            }
            else
            {
                if(z == z -> parent -> right)
                {
                    z = z -> parent;
                    leftRotate(z);
                }
                z -> parent -> color = 'B';
                z -> parent -> parent -> color = 'R';
                rightRotate(z -> parent -> parent);
            }
        }
        else
        {
            if(z -> parent == z -> parent -> parent -> right)
        {
            y = z -> parent -> parent -> left;
            if(y -> color == 'R')
            {
                z -> parent -> color = 'B';
                y -> color = 'B';
                z -> parent -> parent -> color = 'R';
                z = z -> parent -> parent;
            }
            else
            {
                if(z == z -> parent -> left)
                {
                    z = z -> parent;
                    rightRotate(z);
                }
                z -> parent -> color = 'B';
                z -> parent -> parent -> color = 'R';
                leftRotate(z -> parent -> parent);
            }
        }
        }
    }
    root -> color = 'B';
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to inserted is passed as argument
DESC: Pseudo code to fix the tree height of rbtree. It is used to balance
      the tree
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBTree::leftRotate(Node* x)
{
   Node* y;
    y = x -> right;
    x -> right = y -> left;
    if(y -> left != nil)
    {
        y -> left -> parent = x;
    }
    y -> parent = x -> parent;
    if(x -> parent == nil)
    {
        root = y;
    }
    else if(x == x -> parent -> left)
    {
        x -> parent -> left = y;
    }
    else
    {
        x -> parent -> right = y;
    }
    y -> left = x;
    x -> parent = y;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to inserted is passed as argument
DESC: Pseudo code to fix the tree height of rbtree. It is used to balance
      the tree
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBTree::rightRotate(Node* x)
{
     Node* y;
    y = x -> left;
    x -> left = y -> right;
    if(y -> right != nil)
    {
        y -> right -> parent = x;
    }
    y -> parent = x -> parent;
    if(x -> parent == nil)
    {
        root = y;
    }
    else if(x == x -> parent -> right)
    {
        x -> parent -> right = y;
    }
    else
    {
        x -> parent -> left = y;
    }
    y -> right = x;
    x -> parent = y;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Key to be found is passed as input parameter
DESC: It calls treeserch function to find the node with given key.
      Duplicate keys are found using successor and predesessor functions
OUT:vector of const string* type is returned back
/////////////////////////////////////////////////////////////////////////////
*/

vector<const string*> RBTree::rbFind(const string& key)
{
    string value;
    vector<const string*> found; //vector to store string
    Node* holdkey = new Node();
    Node* succ = new Node();
    Node* pred = new Node();
    holdkey = rbTreeSearch(root,key);
    if(holdkey != nil) //if string returned is not Null
    {
        value = *holdkey-> value;
        found.push_back(new string(value));
        succ = rbTreeSuccessor(holdkey);
        pred = rbTreePredecessor(holdkey);
        //when key is same and successor is not Null
        while(succ != nil && *succ-> key == *holdkey-> key)
        {
            value = *succ-> value;
            found.push_back(new string(value));
            succ = rbTreeSuccessor(succ);
         }
            //when key is same and predecessor is not Null
            while(pred != nil && *pred-> key == *holdkey-> key)
            {
                value = *pred-> value;
                found.push_back(new string(value));
                pred = rbTreePredecessor(pred);
            }
    }
    return found;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to inserted is passed as argument along with key
DESC: rbTreeSearch function to find if passed key is present in the tree.
      root is passed into the function as tree search should start from
      the root of the tree
OUT: It returns the node if a node is found with given key
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node* RBTree::rbTreeSearch(Node* x, const string& key)
{
    //if tree is not empty
    while(x != nil && *x-> key != key)
    {
        if(key < *x-> key)
        {
            x = x-> left;
        }
        else
        {
            x = x-> right;
        }
    }
    return x;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to find is passed as argument
DESC: Pseudo code to find the successor if any for given key
OUT:It returns node if successor is found
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node* RBTree::rbTreeSuccessor(Node* x)
{
    Node* y;
    if(x->right != nil)
    {
        return rbTreeMinimum(x->right);
    }
    y = x->parent;
    while(y != nil && x == y->right)
    {
    x = y;
    y = y->parent;
    }
    return y;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to find is passed as argument
DESC: Pseudo code to find the predecessor if any for given key
OUT:It returns node if predecessor is found
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node* RBTree::rbTreePredecessor(Node* x)
{
    Node* y;
    if(x->left != nil)
    {
        return rbTreeMaximum(x->left);
    }
    y = x->parent;
    while(y != nil && x == y->left)
    {
        x = y;
        y = y->parent;
    }

    return y;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to find is passed as argument
DESC: Pseudo code to find the minimum key node in given tree
OUT:It returns node with minimum key in right subtree
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node* RBTree::rbTreeMaximum(RBTree::Node*x)
{
    while(x -> right != nil)
    {
        x = x -> right;
    }
    return x;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to find is passed as argument
DESC: Pseudo code to find the minimum key node in given tree
OUT:It returns node with minimum key in left subtree
/////////////////////////////////////////////////////////////////////////////
*/

RBTree::Node* RBTree::rbTreeMinimum(RBTree::Node*x)
{
    while(x -> left != nil)
    {
        x = x -> left;
    }
    return x;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to inserted is passed as argument
DESC: Pseudo code to delete node into rbtree
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/

void RBTree::rbDelete(Node* z)
{
	Node* y;
	Node* x;
	char yoriginalcolor;
	y = z;
	yoriginalcolor = y-> color;
	if(z-> left == nil)
	{
		x = z-> right;
		rbTransplant(z,z-> right);
	}
	else if(z-> right == nil)
	{
		x = z->left;
		rbTransplant(z,z->left);
	}
	else
	{
		y = rbTreeMaximum(z-> left);
		yoriginalcolor = y-> color;
		x = y-> left;
		if(y-> parent == z)
		{
			x-> parent = y;
		}
		else
		{
			rbTransplant(y,y->left);
			y->left=z->left;
			y->left->parent=y;
		}
		rbTransplant(z,y);
		y->right=z->right;
		y->right->parent=y;
		y->color=z->color;
	}
	if(yoriginalcolor=='B')
	{
		rbDeleteFixup(x);
	}
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to deleted with it's parent is passed as argument
DESC: Pseudo code to fix the tree after a node has been deleted
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/


void RBTree::rbTransplant(Node*u, Node*v)
{
    if(u -> parent == nil)
    {
        root = v;
    }
    else if(u == u -> parent -> left)
    {
        u -> parent -> left = v;
    }
    else
    {
        u -> parent -> right = v;
    }
    v -> parent = u -> parent;
}

/*
/////////////////////////////////////////////////////////////////////////////
IN: Node to deleted is passed as argument
DESC: Pseudo code to fix the properties of deleted node in rbtree . It
      checks for property 2 and 4 that are not violeted
OUT:NA
/////////////////////////////////////////////////////////////////////////////
*/


void RBTree::rbDeleteFixup(Node* x)
{
	Node* w;
	while(x!=root&&x->color=='B')
	{
		if(x==x->parent->left)
		{
			w=x->parent->right;
			if(w->color=='R')
			{
				w->color='B';
				x->parent->color='R';
				leftRotate(x->parent);
				w=x->parent->right;
			}
			if(w->left->color=='B'&&w->right->color=='B')
			{
				w->color='R';
				x=x->parent;
			}
			else
			{
				if(w->right->color=='B')
				{
					w->left->color='B';
					w->color='R';
					rightRotate(w);
					w=x->parent->right;
				}
				w->color=x->parent->color;
				x->parent->color='B';
				w->right->color='B';
				leftRotate(x->parent);
				x=root;
			}
	    }
		else
		{
			w=x->parent->left;
			if(w->color=='R')
			{
				w->color='B';
				x->parent->color='R';
				rightRotate(x->parent);
				w=x->parent->left;
			}
			if(w->right->color=='B'&&w->left->color=='B')
			{
				w->color='R';
				x=x->parent;
			}
			else
			{
				if(w->left->color=='B')
				{
					w->right->color='B';
					w->color='R';
					leftRotate(w);
					w=x->parent->left;
				}
				w->color=x->parent->color;
				x->parent->color='B';
				w->left->color='B';
				rightRotate(x->parent);
				x=root;
			}
		}
	}
	x->color='B';
}

#ifndef BST_H_
#define BST_H_

#include <stdexcept>
#include "btnode.h"

/*
	A class to represent a templated binary search tree.
*/
template <typename T>
class BST
{
	private:

		//pointer to the root node in the tree
		BTNode<T>* root;

	public:

		//default constructor to make an empty tree
		BST();

		/*
			You have to document these 4 functions
		*/
		void insert(const T& value);
		bool search(const T& value) const;
		void printInOrder() const;
		void remove(const T& value);

		//function to print out a visual representation
		//of the tree (not just print the tree's values
		//on a single line)
		void print() const;

	private:

		//recursive helper function for "print()"
		void print(BTNode<T>* node,int depth) const;
                void insertHelper(BTNode<T>* &ptr, BTNode<T>* newNode);
                void printHelper(BTNode<T>* ptr) const;
                void searcher(BTNode<T>* root, T value, BTNode<T>** parent, BTNode<T>** dir) const;
};

/*
	Default constructor to make an empty tree
*/
template <typename T>
BST<T>::BST()
{
	root = NULL;
}

template <typename T>
void BST<T>::insert(const T& value)
{
    BTNode<T>* newNode= new BTNode<T>(value);
    newNode->data= value;
    newNode->left= NULL;
    newNode->right= NULL;
    insertHelper(root, newNode);
}

template <typename T>
void BST<T>::insertHelper(BTNode<T>* &ptr, BTNode<T>* newNode)
{
    if(ptr == NULL) {
        ptr= newNode;
        return;
    }
    if(ptr->data == newNode->data)
        return;
    insertHelper((newNode->data > ptr->data?ptr->right:ptr->left), newNode);
}


template <typename T>
bool BST<T>::search(const T& value) const
{
    BTNode<T>* ptr= root;
    while(ptr != NULL) {
        if(ptr->data == value)
            return true;
        ptr= (value > ptr->data)?ptr->right:ptr->left;
    }
    return false;
}

template <typename T>
void BST<T>::searcher(BTNode<T>* root, T value, BTNode<T>** parent, BTNode<T>** dir) const {
    BTNode<T>* ptr;
    BTNode<T>* temp;
    if(root == NULL) {
        *dir= NULL;
        *parent= NULL;
        return;
    }

    if(root->data == value) {
        *dir= root;
        *parent= NULL;
        return;
    }

    if(value < root->data)
        ptr= root->left;
    else
        ptr= root->right;
    temp= root;

    while(ptr!=NULL) {
        if(value == ptr->data) {
            *dir= ptr;
            *parent= temp;
            return;
        }
        temp= ptr;
        if(value < ptr->data)
            ptr=ptr->left;
        else
            ptr= ptr->right;
    }
    *dir= NULL;
    *parent= temp;
}

template <typename T>
void BST<T>::printInOrder() const
{
    if(root == NULL) {
        std::cout<<"Empty"<<std::endl;
        return;
    }
    std::cout<<"[";
    printHelper(root);
    std::cout<<"]"<<std::endl;
}

template <typename T>
void BST<T>::printHelper(BTNode<T>* ptr) const{
    if(ptr == NULL)
        return;
    printHelper(ptr->left);
    std::cout<<" "<<ptr->data<<" ";
    printHelper(ptr->right);
}

template <typename T>
void BST<T>::remove(const T& value) {
    BTNode<T> *parent, *ptr;
    if(root == NULL) return;
    searcher(root, value, &parent, &ptr);
    if(ptr == NULL) return;

    if(ptr->left == NULL && ptr->right==NULL) {
        if(parent->left->data == ptr->data)
            parent->left= NULL;
        else
            parent->right= NULL;
        delete ptr;
        return;
    }

    if((ptr->left!=NULL && ptr->right==NULL) || (ptr->left==NULL && ptr->right!=NULL)) {
        if(ptr->left==NULL && ptr->right!=NULL) {
            if(parent->left == ptr) {
                parent->left= ptr->right;
                delete ptr;
            }
            else {
                parent->right= ptr->right;
                delete ptr;
            }
        }
        else {
            if(parent->left == ptr) {
                parent->left= ptr->left;
                delete ptr;
            }
            else {
                parent->right= ptr->left;
                delete ptr;
            }
        }
        return;
    }
    if((ptr->left!=NULL)&&(ptr->right!=NULL)) {
        BTNode<T>* checker= ptr->right;
        if((checker->left == NULL)&&(checker->right==NULL)) {
            ptr= checker;
            delete checker;
            ptr->right= NULL;
        }
        else {
            if((ptr->right->left != NULL)) {
                BTNode<T>* t1= ptr->right;
                BTNode<T>* t= ptr->right->left;
                while(t->left!=NULL) {
                    t1=t;
                    t= t->left;
                }
                ptr->data= t->data;
                delete t;
                t1->left= NULL;
            }
            else {
                BTNode<T>* temp= ptr->right;
                ptr->data= temp->data;
                ptr->right= temp->right;
                delete temp;
            }
        }
        return;
    }
}

/*
	Print out the values in the tree and their
	relationships visually.  Sample output (10 is the root):

	                    22
                18
        15
10
                9
        5
                3
                        1
*/
template <typename T>
void BST<T>::print() const
{
	print(root,0);
}

template <typename T>
void BST<T>::print(BTNode<T>* node,int depth) const
{
	if(node == NULL)
	{
		std::cout << std::endl;
		return;
	}

	print(node->right,depth+1);
	for(int i=0; i < depth; i++)
	{
		std::cout << "\t";
	}
	std::cout << node->data << std::endl;
	print(node->left,depth+1);
}

#endif

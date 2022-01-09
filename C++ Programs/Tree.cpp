#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node *left;
	Node *right;
	
	Node(){
		data = 0;
		left = NULL;
		right = NULL;
	}
	
	Node(int num){
		data = num;
		left = NULL;
		right = NULL;
	}
};

class Btree{
	Node *root;
	
	public:
		void print2D();
		void insert(int num);
		void insert(int num, Node *leaf);
		void destroy(Node *leaf);
		void print2DUtil(Node *leaf, int space);
	Btree(){
		root = NULL;
	}
	~Btree(){
		destroy(root);
	}
};

void Btree::print2DUtil(Node *leaf, int space)  
	{	  
    	if (leaf == NULL)  
        	return;  
  
    	space += 5;  
  
    	print2DUtil(leaf->right, space);  
  
    	cout<<endl;  
    	for (int i = 5; i < space; i++)  
        	cout<<" ";  
    	
		cout<<leaf->data<<"\n";  
      	print2DUtil(leaf->left, space);  
	}  
  
void Btree::print2D()  
	{  
    	print2DUtil(root, 0);  
	}  

void Btree::insert(int num)
{
  if(root != NULL)
  {
  	insert(num, root);
  }
  else
  {
    root = new Node(num);
  }
}

void Btree::insert(int num, Node *leaf){
			if(num < leaf->data){
				if(leaf->left != NULL){
					insert(num, leaf->left);
				}
				else {
					leaf->left = new Node(num);
				}
			}
			else if(num >= leaf->data){
				if(leaf->right != NULL){
					insert(num, leaf->right);
				}
				else {
					leaf->right = new Node(num);
				}
			}
	}
	
void Btree::destroy(Node *leaf){
		if(leaf != NULL){
			destroy(leaf->left);
			destroy(leaf->right);
			delete leaf;
		}
	}
	

int main(){
	
	Btree *btree = new Btree();
	
	btree->insert(43);
	btree->insert(10);
	btree->insert(79);
	btree->insert(90);
	btree->insert(12); 
	btree->insert(54); 
	btree->insert(11);
	btree->insert(9); 
	btree->insert(50); 

	btree->print2D();
	
	return 1;
}

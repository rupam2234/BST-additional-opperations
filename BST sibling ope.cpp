// C++ programme to insert nodes 
// measure the height of a given node
// find out the leftmost cousin of a given node
// findout the rightmost cousin of a given node

#include <iostream>
using namespace std;

// creating a class for nodes to initialize the members
class Node
{
public:
	int key;
	Node* parent;
	Node* lchild;
	Node* rchild;
	
	Node()
    {
        parent = lchild = rchild = NULL;
    }
};


// creating a base class tree
class Tree
{
    
    public:
	    Node *root;
};


// creating a derived class of Tree
class Bstope : Tree
{
    // for making the primary methods unaccessible out side the class
	private:
	
       int value;
	   
	   void insert(int value);
       int getheight(Node* current, int value, int count);
       int leftSibling(Node* current, int height, int value);
       int RightSibling(Node* current, int height, int value);
       int MaximumSum(Node* current);
       int MinimumSum(Node* current);
       Node* LLrotation(Node* current);
       Node* LRrotation(Node* parent);
       Node* RRrotation(Node* parent);
       Node* RLrotation(Node* current);
    
       Node node;
	   
	
public:
	
	Bstope()
        {
             root = NULL;
        }
    
    void insertValue(int value) // this fucntion can not be overloaded since I have passed the same perameter inside the primary function
	{
		return insert(value);
	}
		
	int getheight(int value)  // function overloading
    {
    	getheight(root, value, -1);
	}	
	
	int leftSibling(int value) //function overloading
	{
		leftSibling(root, getheight(value), value);
	}
	
	int RightSibling(int value) //function overloading
	{
		RightSibling(root, getheight(value), value);
	}
	
	int MaximumSum() //function overloading
	{
		MaximumSum(root);
	}
	
	int MinimumSum() //function overloading
	{
		MinimumSum(root);
	}
	
	Node* RRrotation() //function overloading
	{
		RRrotation(root);
	}
	
	Node* LLrotation() //function overloading
	{
		LLrotation(root);
	}
	
	Node* RLrotation() //function overloading
	{
		RLrotation(root);
	}
	
	Node* LRrotation() //function overloading
	{
		LRrotation(root);
	}
		
};


void Bstope :: insert(int value)
    {
        // a new node pointed by temp is created to hold the value to be inserted
        Node* temp = new Node();
        temp->key = value;

        // now we take a pointer current which will initially point to the root
        // and parent pointer will point to the parent of the current node

        Node* current = root;
        Node* parent = NULL;

        // when current is NULL, it means no BST is there and new node will form the root of the tree
        // if it is not NULL then the current has child so it will point to class 

        while (current != NULL)
        {
            parent = current;

            if (value < current->key)
            {
                current = current->lchild;
            }

            else
            {
                current = current->rchild;
            }
        }

        // now if we check the parent of current is NULL, if yes current is a root node 

        if (parent == NULL)
        {
        	//temp holds the value to be inserted, so now root will point to it.
            root = temp;  
        }
        else if(value < parent->key)
        {
            parent->lchild = temp;
        }
        else
        {
            parent->rchild = temp;
        }

        //now the parent of temp will be the parent 
    }
    

// for searching the height of an element
    
int Bstope::getheight(Node* current, int value, int count=-1)
    {           
		 
		if (current==NULL){
			return count;
	    }
	    
	    while(current!=NULL){
		    
		    count++;
			if(current->key == value){
				return count; 
			}
			
			else if(current->key > value){
				current=current->lchild;
			}
			
			else current=current->rchild;   
		}
		
		return count;	
	}

// for finding the leftmost cousin of a node	 
	
int Bstope::leftSibling(Node* current, int height, int value)
    {   
		
		if(current==NULL)
	   	 {
	   	 	return -1;
		 }
		 
		 while (height!= 0 && current!=NULL)
		 {
		 	if(current->lchild!= NULL)
		 	{
		 		current = current->lchild;
		 		height =height-1;
			}
			
			else if(current->rchild!=NULL)
			{
			    current=current->rchild;	
			    height=height-1;
			}
			
			else if(height!=0)
				return -1;
		 }
		 
		 if(current->key==value)
			{
				return -1;
			}
			
		 return current->key;    
		 
	}

// for finding the rightmost cousin of a node
	
int Bstope::RightSibling(Node* current, int height, int value)
    {   

		
		if(current==NULL)
	   	 {
	   	 	return -1;
		 }
		 
		while (height!= 0 && current!=NULL)
		{
		 	if(current->rchild!= NULL)
		 	{
		 		current = current->rchild;
		 		height =height-1;
			}
			
			else if(current->lchild!=NULL)
			{
			    current=current->lchild;	
			    height=height-1;
			}
			
			else if(height!=0)
			   return -1;
		}
		 
		if(current->key==value)
			{
				return -1;
			}
			
		return current->key;    
		 
	}
	
//to find the maximum sum of the brunch

int Bstope::MaximumSum(Node* current)
{
	if(current==NULL)
	{
		return 0; 
	}
	
	else if ((current->lchild=NULL) && (current->rchild=NULL))
	{
		return current->key;
	}
	
	return current->key + max(MaximumSum(current->lchild), MaximumSum(current->rchild));
}	


//to find the minimum sum of the brunch

int Bstope::MinimumSum(Node* current)
{
	if(current==NULL)
	{
		return 0; 
	}
	
	else if ((current->lchild=NULL) && (current->rchild=NULL))
	{
		return current->key;
	}
	
	return current->key + min(MaximumSum(current->lchild), MaximumSum(current->rchild));
}

/* 

void Bstope::SearchOrder(Node* current)
{
    while(current!=NULL)
	{
		if()
	}	
}

*/
//to apply RR rotation 

Node* Bstope::RRrotation(Node* current) //considersing current node as the parent node
 {
 	Node* temp;
 	
 	temp = current->rchild;
 	current->rchild = temp->lchild;
 	temp->lchild = current;
 	return temp;
 }
 
//to apply RR rotation

Node* Bstope::LLrotation(Node* current) //considering current node as the parent node
 {
 	Node* temp;
 	
 	temp = current->lchild;
 	current->lchild = temp->rchild;
 	temp->rchild = current;
 	return temp;
 }
 
//to apply RL rotation
 
Node* Bstope::RLrotation(Node* current)
{
	Node* temp;
	
	temp = current->rchild;
	current->rchild = LLrotation(temp);
	return RRrotation(current); 
}

//to apply LR rotation

Node* Bstope::LRrotation(Node* current)
{
	Node* temp;
	
	temp = current->lchild;
	current->lchild = RRrotation(temp);
	return LLrotation(current);
}


int main()
{
   // creating a object of Binary Search Tree
   
   Bstope b1;
   b1.insertValue(46); 
   b1.insertValue(39); 
   b1.insertValue(69); 
   b1.insertValue(25); 
   b1.insertValue(43);
   b1.insertValue(28);
   b1.insertValue(56);
   b1.insertValue(75);
   b1.insertValue(70);
   
   cout<<"\nThe height of the node (75) is: "<<b1.getheight(75)<<endl; 
   
   cout<<"\nLeftmost Cousin of (75) is: "<<b1.leftSibling(75);	
   
   cout<<"\n\nRightmost Cousin of (20) is: "<<b1.RightSibling(20);
   
   cout<<"\n\nMaximum Sum of the brunch: "<<b1.MaximumSum();
   
   cout<<"\n\nMinimum Sum of the brunch: "<<b1.MinimumSum();
   
   // closing these 4 output becasue it will rotate the tree, but until now I have not counted the balancing factors 
   /* 
   
   cout<<"\n\nRR rotation: "<<endl;
   cout<<"------> parent node will be: "<<b1.RRrotation()->key;
   
   cout<<"\n\nLL rotation: "<<endl;
   cout<<"------> parent node will be: "<<b1.LLrotation()->key; 

   cout<<"\n\nRL rotation: <<endl;
   cout<<"------> parent node will be: "<<b1.RLrotation()->key; 
   
   cout<<\n\nLR rotation: <<endl;
   cout<<"------> parent node will be: "<<b1.LRrotation()->key;
   
   */

} 


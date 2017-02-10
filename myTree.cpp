#include <iostream>

using namespace std;

class Node{
private:
int value;    //Node Value
Node* right;  //Points to the right child
Node* left;   //Points to left child	

int getValue(); //Private function to retrieve value. Only used while testing initial code functionality

public:
Node(int);                      //Constructor
void addNode(Node*, int);       //Function to add a node
string nodeSearch(Node*, int);  //Function to search for a node's presence
void traversePreorder(Node*);   //Function to print the Pre-Order Traversal Path
int getHeightInfo(Node*);       //Getting Height Information
};



Node::Node(int val):value(val){ //Construct a node with given value
	right = NULL;		//Set childen nodes to NULL
	left = NULL;
}

void Node::addNode(Node* root, int val){              //Takes in the root pointer to figure 
Node* traverser;                                      //Backup pointer to use
traverser = root;
if(traverser->value <= val){                          //If value greater than node being considered, go right!
	if(traverser->right == NULL){                 //If no further nodes are present, create a new one
		Node* newNode = new Node(val);
		traverser->right = newNode;           //Assign the previous node's right child pointer to newly constructed node
	}
	
	else{
		addNode(traverser->right, val);
	}
}
else{                                          //If value greater than node being considered, go left!
 if(traverser->left == NULL){
                Node* newNode = new Node(val); //If no further nodes are present, create a new one
                traverser->left = newNode;     //Reccursively call the function on the new node on the right
        }

        else{
                addNode(traverser->left, val); //Reccursively call the function on the new node on the left
        }
  } 
}

string Node::nodeSearch(Node* root, int key){  //Get the starting location and the key that is being searched
 string verdict;

 if(root == NULL){                              //If NULL is reached, the node was not found
 verdict = "not found";
 return verdict;
 }

 else if(root->value == key){                   //If there is a match, the node was ound
 verdict = "found";
 return verdict;
 }

 else if(root->value < key){
 verdict = nodeSearch(root->right, key);        //if key is greater than the considered node, look on the right
 return verdict;
 }

 else{
 verdict = nodeSearch(root->left, key);         //if key is lesser than the considered node, look on the left
 return verdict;
 	}
}

void Node::traversePreorder(Node* root){       //Accept the root
  if(root==NULL)
  return;
  cout << root->value << endl;			//Prints value while going down and up again
   traversePreorder(root->left);			//Print the left subtree and then print the right subtree
 traversePreorder(root->right);	            //As left nodes of subtree bottom out, the right nodes are printed on its way back to the root
}

int Node::getHeightInfo(Node* root){
 if(root == NULL)
 return -1;
 return (max(getHeightInfo(root->left),getHeightInfo(root->right))+1); //calculate the maximum path in each subtree and add 1 for the root
 }

int Node::getValue(){ //Getter function. Not used
 return value;
 }


int main(){

cout << "WELCOME TO THE TREE PROGRAM" << endl << endl;
cout << "ENTER ROOT VALUE" << endl;
int rootVal;
cin >> rootVal;
Node *root = new Node(rootVal); //Creating a new root node

cout << endl << "SELECT ONE OF THE FOLLOWING OPERATIONS WITH THEIR NUMBER" << endl << endl;
cout << "1. ADD A NODE TO THE TREE" << endl;
cout << "2. PRINT THE CURRENT PRE-ORDER TRAVERSAL" << endl;
cout << "3. SEARCH FOR THE PRESENCE OF A NODE" << endl;
cout << "4. GET THE HEIGHT OF THE TREE" << endl;
cout << "5. ANY OTHER KEY TO EXIT THE PROGRAM" << endl<< endl;

for(;;){ //Continuously interact with the user to operate on the tree.

cout << "1. Add Node   2. Print   3. Search   4. Height   5. Exit " << endl;
int option;
cout << endl << "Option: ";
cin >> option;

switch(option){

case 1: cout << "Enter New Node's Value: ";
	int value;
	cin >> value;
	root->addNode(root, value);
	cout << "Added New Node with Value " << value << endl << endl;	
	break;

case 2: cout << "Printing Preorder Traversal" << endl;
	root->traversePreorder(root);
	cout << endl;
	break;

case 3: cout << "Enter Key to Search: ";
	int key;
	cin >> key;
	cout << "The Node was " << root->nodeSearch(root, key) << endl << endl;
	break;

case 4: cout << "Height is: " << root->getHeightInfo(root) << endl;
	cout << endl;
	break;

default: exit(0);  
}
}
}









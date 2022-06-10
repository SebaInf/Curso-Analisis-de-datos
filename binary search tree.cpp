#include <bits/stdc++.h>
using namespace std;

struct Node{
	int key;
	Node* parent;
	Node* left;
	Node* right;

};

struct Node *newNode(int val)
{
   struct Node *temp =  new Node;
    temp->key = val;
    temp->left = temp->right = NULL;
    temp->parent = NULL;
    return temp;
}
 
struct Node* insert(struct Node* node, int key)
{

    if (node == NULL) return newNode(key);
 
    if (key < node->key)
    {
        Node *lchild = insert(node->left, key);
        node->left  = lchild;
 
        lchild->parent = node;
    }
    else if (key > node->key)
    {
        Node *rchild = insert(node->right, key);
        node->right  = rchild;
 
        rchild->parent = node;
    }
 
    return node;
}


 
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("Node : %d, ", root->key);
        
        if (root->left == NULL)
          printf(" left : NULL ");
        else
          printf(" left : %d   ", root->left->key);
        
        
        if (root->right == NULL)
          printf("right : NULL ");
        else
          printf("right : %d   ", root->right->key);
          
        
        if (root->parent == NULL)
          printf(" Parent : NULL \n");
        else
          printf(" Parent : %d    \n", root->parent->key);
        inorder(root->right);
    }
}
 
struct Node* minValueNode(struct Node* node)
{
    struct Node* current = node;
 
    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 

struct Node* deleteNode(struct Node* root, int key)
{
    if (root == NULL)
        return root;
 

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
    
    else {
    	
        if (root->left==NULL and root->right==NULL)
            return NULL;
       
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct Node* temp = minValueNode(root->right);
 
        root->key = temp->key;
        
 
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
 
 void repairParent(struct Node* root, int val,int control, int parent)
{

	
    if (root == NULL)
        return;
 
    if (root->key == val) {
 
        
        if(parent !=control ){
        
        	root->parent->key=parent;
        	//cout << "\n";
	        //cout << parent;
	        //cout << "\n";
	    }
        //else {
        //
        //	cout << "\n";
	    //	cout << "sin padre";
	    //	cout << "\n";
	    //}
        
    }
    else {
 
        repairParent(root->left, val, control,root->key);
        repairParent(root->right, val,control, root->key);
    }
}
 
void repairTree(struct Node *root, int KeyMenor, int KeyMayor)
{
	
	for(int k=0;k<=KeyMayor;k++){
	
	
		repairParent(root, k, 0,0); // 0,0 son valores de control que tienen que ser iguales y distintos a la key de cualquier nodo del arbol
	
	}

}

int main()
{
    
    struct Node* root = NULL;       
    root = insert(root, 44);
    root = insert(root, 17);
    root = insert(root, 32);
    root = insert(root, 28);
    root = insert(root, 29);
    root = insert(root, 88);
    root = insert(root, 65);
    root = insert(root, 97);
    root = insert(root, 54);
    root = insert(root, 82);
    root = insert(root, 76);
    root = insert(root, 80);
    root = insert(root, 78);
 
    cout << "Informacion del arbol dado \n";
    inorder(root);
 
    cout << "\nBorrando 32\n";
    root = deleteNode(root, 32);
    cout << "Informacion del nuevo arbol \n";
    inorder(root);
 
    cout << "\nBorrarndo 76\n";
    root = deleteNode(root, 76);
    cout << "Informacion del nuevo arbol \n";
    inorder(root);
 	
 
    cout << "\nBorrando 50\n";
    root = deleteNode(root, 50);
    cout << "Informacion del nuevo arbol \n";
    inorder(root);
    
    repairTree(root,17,97);
    
    cout << "\nInformacion del arbol reparado \n";
    
    inorder(root);
    
 
    return 0;
}
 
 

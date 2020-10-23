#include <iostream>
#include<conio.h>
#include<process.h>
using namespace std;

struct avl_node
{
	int key;
	struct avl_node *right;
	struct avl_node *left;
	int height;
}*root;

class avl
{
public:
        int height(avl_node*);
        int max(int ,int );
        avl_node *leftrotate(avl_node*);
        avl_node *rightrotate(avl_node*);
        int balancefactor(avl_node*);
        int insert(avl_node*,int );
        void inorder(avl_node*);
        void preorder(avl_node*);
        void postorder(avl_node*);
        void display(avl_node*, int);
        avl_node *minValueNode(avl_node* node)
        avl_node *deleteNode(avl_node*,int);

       avl_node *newavl_node(int data)
	{
		avl_node *temp=new avl_node();
		temp->value=data;
		temp->left=temp->right=NULL;
		temp->height=1;
		return temp;
	}
};

/*
 * For height of AVL tree
 */
              int avl::height(avl_node* y)
	{
	if(y==NULL)
		{
			return 0;
		}
          else
		{
			return y->height;
		}
	}

/*
 * To find maximum which will be used in calculating height
 */
	int avl::max(int a,int b)
	{
		if(a>b)
		{
			return a;
		}
		return b;
	}



/*
 * Left Rotation
 */
 avl_node *avl::leftrotate(avl_node *y)
{
	 avl_node *x=y->right;
         avl_node *t2=x->left;
	x->left=y;
	y->right=t2;
	y->height=max(height(y->right),height(y->left))+1;
    x->height=max(height(x->right),height(x->left))+1;
	return x;
}


/*
 * Right Rotation
 */
 avl_node *avl::rightrotate(avl_node *x)
{
	avl_node *y=x->left;
	avl_node *t2=y->right;
	y->right=x;
	x->left=t2;
	x->height=max(height(x->right),height(x->left))+1;
	y->height=max(height(y->right),height(y->left))+1;
	return y;
}

/*
 * For balance factor
 */

 int avl::balancefactor(avl_node *node)
  {
   if(node==NULL)
  {
   return 0;
  }
   else
   {
    return (height(node->left)-height(node->right));
   }
  }


/*
 * Insert Element into the tree
 */
    int avl::insert(avl_node *node,int key)

{  
    if (node == NULL)  
        return(newavl_node(key));  
  
    if (key < node->key)  
        node->left = insert(node->left, key);  

    else if (key > node->key)  
        node->right = insert(node->right, key);  
   
    else                      // Equal keys not allowed  
        return node;  
  
    //Update height of this ancestor node

    node->height = 1 + max(height(node->left),  
                           height(node->right));  
  
    // Get the balance factor of this  
        ancestor node to check whether  
        this node became unbalanced

    int balance = balancefactor(node);  
  
    // If this node becomes unbalanced, then there are 4 cases  
  
    if (balance > 1 && key < node->left->key)      // Left child,Left subtree Case   
        return rightrotate(node);  
  
     
    if (balance < -1 && key > node->right->key)    // Right child,Right subtree Case
        return leftrotate(node);  
  
     
    if (balance > 1 && key > node->left->key)      // Left child, Right subtree Case 
    {  
        node->left = leftRotate(node->left);  
        return rightrotate(node);  
    }  
  
   
    if (balance < -1 && key < node->right->key)     // Right child,Left subtree Case  
    {  
        node->right = rightrotate(node->right);  
        return leftrotate(node);  
    }  
  
    return node;          //return the (unchanged) node pointer 
}  

//Given a non-empty binary search tree,  
return the node with minimum key value  
found in that tree.The entire  
tree does not need to be searched

  avl_node *avl::minValueNode(Node* node)  
{  
    avl_node* current = node;  
  
    
    while (current->left != NULL)   //loop down to find the leftmost leaf
        current = current->left;  
  
    return current;  
}  


/*
 * Delete an element from the tree
 */
 avl_node *avl::deleteNode(avl_node* root, int key)  
{  
                  
    if (root == NULL)  // Perform BST deletion by copying
        return root;  
  
    // If the key to be deleted is smaller than the root's key, then it lies in left subtree  
      if ( key < root->key )  
        root->left = deleteNode(root->left, key);  
  
    // If the key to be deleted is greater than the root's key, then it lies in right subtree
  
    else if( key > root->key )  
        root->right = deleteNode(root->right, key);  
  
     // if key is same as root's key, then  
    // This is the node to be deleted 

    else
    {  
        if( (root->left == NULL) || (root->right == NULL) )   // node with only one child or no child  
        {  
            avl_node *temp = root->left ?  
                         root->left :  
                         root->right;  
  
            // No child case  
            if (temp == NULL)  
            {  
                temp = root;  
                root = NULL;  
            }
  
            else                // One child case  
            *root = *temp;     // Copy the contents of the non-empty child  
            free(temp);  
        }  
        else
        {   

            // node with two children: Get the inorder successor (smallest in the right subtree) 
            
            avl_node* temp = minValueNode(root->right);     
  
            // Copy the inorder successor's data to this node  
            root->key = temp->key;  
  
            // Delete the inorder successor  
            root->right = deleteNode(root->right,temp->key);  
        }  
    }  
    
    if (root == NULL)        // If the tree had only one node then return
    return root;  
  
    root->height = 1 + max(height(root->left),height(root->right));     // Update height of the current node
  
    //Get the balance factor of this node(to check whether this node became unbalanced)  
    int balance = balancefactor(root);  
  
    // If this node becomes unbalanced,then there are 4 cases  
   
    if (balance > 1 && balancefactor(root->left) >= 0)   // Left child, Left subtree Case  
        return rightrotate(root);  
    
    if (balance > 1 && balancefactor(root->left) < 0)    // Left child,Right subtree Case
    {  
        root->left = leftrotate(root->left);  
        return rightrotate(root);  
    }  
  
    
    if (balance < -1 && balancefactor(root->right) <= 0)   // Right child,Right subtree Case 
        return leftrotate(root);  
  
     
    if (balance < -1 && balancefactor(root->right) > 0)     // Right child,Left subtree Case 
    {  
        root->right = rightrotate(root->right);  
        return leftrotate(root);  
    }  
  
    return root;  
}  
  


/*
 * Preorder Traversal of AVL Tree
 */
    void avl::preorder(avl_node *root)
  {
if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }

   if(root!=NULL)
   {
   cout<<root->key<<" ";
   preorder(root->left);
   preorder(root->right);
   }
}

/*
 * Inorder Traversal of AVL Tree
 */
  void avl::inorder(avl_node *root)
{
   if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
   
  if(root!=NULL)
   {
    inorder(root->left);
    cout << root->key<< " ";
    inorder(root->right);
  }
}

/*
 * Postorder Traversal of AVL Tree
 */
void avl::postorder(avl_node *root)
{
 if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }

    if(root!=NULL)
   { postorder(root->left);
    postorder(root->right);
    cout <<root->key<< " ";
  }
}

/
*
 * Display AVL Tree
 */
void avlTree::display(avl_node *ptr, int level)
{
    int i;
    if (ptr!=NULL)
    {
        display(ptr->right, level + 1);
        cout<<"\n";
        if (ptr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"        ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}




int main()
{
    avl_node *root=NULL;
    avl_node *node=NULL;
    int choice, value,key;
    avl T;
    while (1)
    {
        cout<<"\n---------------------"<<endl;
        cout<<"AVL Tree Implementation"<<endl;
        cout<<"\n---------------------"<<endl;
        cout<<"1.Insert Element into the tree"<<endl;
        cout<<"2.Display AVL Tree"<<endl;
        cout<<"3.Inorder traversal"<<endl;
        cout<<"4.Preorder traversal"<<endl;
        cout<<"5.Postorder traversal"<<endl;
        cout<<"6.Delete an Element from the tree"<<endl;
        cout<<"7.Exit"<<endl;
        cout<<"Enter your Choice: ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter value to be inserted: ";
            cin>>value;
            root = T.insert(root, value);
            break;
        case 2:
            if (root == NULL)
            {
                cout<<"Tree is Empty"<<endl;
                continue;
            }
            cout<<"Balanced AVL Tree:"<<endl;
            T.display(root, 1);
            break;
        case 3:
            cout<<"Inorder Traversal of AVL tree: "<<endl;
            T.inorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Preorder Traversal of AVL tree: "<<endl;
            T.preorder(root);
            cout<<endl;
            break;
        case 5:
            cout<<"Postorder Traversal of AVL tree: "<<endl;
            T.postorder(root);
            cout<<endl;
            break;
        case 6:
            cout<<"Enter the key to be deleted: ";
            cin>>key;
            root = T.deleteNode(node, key);
            break;
        case 7:
            exit(1);
            break;
        default:
            cout<<"Wrong Choice"<<endl;
        }
    }
    return 0;
}

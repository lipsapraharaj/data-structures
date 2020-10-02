#include <iostream.h>
#include<conio.h>
#include<process.h>
#include<cstdlib>
using namespace std;
/*
 * node Declaration
 */
struct node
{
    int info;
    int count = 0;
    struct node *left;
    struct node *right;
}*root;
 
/*
 * Class Declaration
 */
class BST
{
    public:   
        void insert(node* , node*);
        void recursive_preorder(node*);
        void recursive_inorder(node*);
        void recursive_postorder(node*);
        void search(int);
        void DFS(node*);
        void mirrorimage(node*);
        void count_nodes(node*,node*);
       
        BST()
        {
            root = NULL;
        }
};
 
/*
 * Inserting Element into the Tree
 */
void BST::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        cout<<"Root node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
	}
	else
	{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
            cout<<"Node Added To Right"<<endl;
            return;
        }	
    }
}
 

 
/*
 * Pre Order Traversal(recursive)
 */
void BST::recursive_preorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}
/*
 * In Order Traversal(recursive)
 */
void BST::recursive_inorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
}
 
/*
 * Postorder Traversal(recursive)
 */
void BST::recursive_postorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}

/*
 *  Search a node
 */
void BST::search(int data)
{
    if(root==0)
    {
        cout<<"Tree is Empty";
    }
    else
    {
        node *traversenode = root;
        while (traversenode != 0 )
        {
            if(traversenode->data == data)
            {
                cout<<"Found in the Tree\n";
                return;
            }
            else if(data > traversenode->data)
            {
                traversenode = traversenode->right;
            }
            else if(data < traversenode->data)
            {
                traversenode = traversenode->left;
            }
        }
        cout<<"Element is not in the Tree\n";
    }
}

/*
 * Depth First Search Traversal
 */
void BST::DFS(node *root)
{
    struct node *temp=root, *prev;
    int visited;
 
    cout<<"On DFS traversal we get:\n";
    while (temp && !temp->visited)
    {
        if(temp->left && !temp->left->visited)
        {
            temp = temp->left;
        }
        else if(temp->right && !temp->right->visited)
        {
            temp = temp->right;
        }
        else
        {
            cout<<temp->a;
            temp->visited=1;
            temp=root;
        }
    }
}

/*
 * Creating Mirror Image of the Tree
 */
void BST::mirrorimage(node *root)
{
  if (root != NULL)
    {
        struct node *temp;
        mirrorimage(root->left);         /* First traversing the left subtree */
        mirrorimage(root->right);        /* Traversing the right subtree. */
        temp=root->left;  
       
         /* 
          * Swap the left and the right child 
          * of all the nodes to create
          * a mirror image of a tree 
          */

        root->left=root->right;  
        root->right=temp;
    }
}

/* 
 *  Count Number Of Leaf Nodes,Non-leaf Nodes and Total Number Of Nodes
 */
void BST::count_nodes(node *newnode, node *root)
        {
            if(newnode != NULL)
            {
                count_nodes(newnode->left);
                if((newnode->left == NULL) && (newnode->right == NULL))
                {
                    count++;
                }
                count_nodes(newnode->right);
            }
            cout<<"Total number of leaf nodes are : "<<count;
        }
 
    if(newnode != NULL)
    {
        count_nodes(newnode->left);
        if((newnode->left != NULL) || (newnode->right != NULL))
        {
            count++;
        }
        count_nodes(newnode->right);
    }
    cout<<"Total number of non-leaf nodes are : "<<count;
 
}

            if(root != NULL)
            {
                count_nodes(root->left);
                count++;
                count_nodes(root->right);
            }
             cout<<"Total number of nodes are : "<<count;
            
        }

 


 /*
 * Main Contains Menu
 */
int main()
{
    int choice, num,data;
    BST bst;
    node *temp;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on BST"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Recursive Inorder Traversal"<<endl;
        cout<<"3.Recursive Preorder Traversal"<<endl;
        cout<<"4.Recursive Postorder Traversal"<<endl;
        cout<<"5.Search a node"<<endl;
        cout<<"6.DFS(depth first search) Traversal"<<endl;
        cout<<"7.Creating Mirror Image of the Tree"<<endl;
        cout<<"8.Count the number of leaf nodes, non-leaf nodes and total number of nodes"<<endl;
        cout<<"9.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch(choice)
        {
        case 1:
            temp = new node;
            cout<<"Enter the number to be inserted : ";
	    cin>>temp->info;
            bst.insert(root, temp);
        case 2:
            cout<<"Inorder Traversal of BST(recursive):"<<endl;
            bst.recursive_inorder(root);
            cout<<endl;
            break;
	case 3:
            cout<<"Preorder Traversal of BST(recursive):"<<endl;
            bst.recursive_preorder(root);
            cout<<endl;
            break;
        case 4:
            cout<<"Postorder Traversal of BST(recursive):"<<endl;
            bst.recursive_postorder(root);
            cout<<endl;
            break;
         case 5:
            cout<<"Enter Data : "; 
            cin>>data;
            bst.search(data);
                break;
         case 6:
            bst.DFS(root);
            break;
         case 7:
            bst.mirrorimage(root);
            break;
         case 8:
            bst.count_nodes(newnode,root);
            break;
         case 9:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}



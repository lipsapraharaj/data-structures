#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<cstdlib>
#include<queue.h>
#include<stack.h>

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
        void iterative_preorder();
        void iterative_postorder();
        void iterative_inorder();
        void search(int);
        void BFS(node*);
        void mirrorimage(node*);
        void count_nodes(node*,node*);
        void heightoftree(node*)
       
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
 * Preorder Traversal(iterative)
 */

 void BST::iterative_preorder()
             {
                  node *current=root;
                  stack<node*> st1
                  while(current!=NULL)
                  {
                                      while((current!=NULL)&&(!visited))
                                      {
                                                     st1.push(current);
                                                     //if(current!=NULL)
                                                     cout<<current->data<<endl;
                                                     current=current->left;
                                      }
                                      current=st1.pop();
                                      if(current==NULL)
                                      break;
                                      visited=1;
                                      if(current->right!=NULL)
                                      {
                                                              visited=0;
                                                              current=current->right;
                                      }
                  }
             }

/*
 * Postorder Traversal(iterative)
 */
             
void BST::iterative_postorder()
             {
                node *tmp;
                  node *current=root;
                   stack<node*> st1
                  while(current!=NULL)
                  { 
                                      while((current!=NULL)&&(!current->visited))
                                      { st1.push(current);
                                       
                                           current=current->left;              
                                      }                    
                  current=st1.pop();
                  if(current==NULL)
                  break;
      tmp=current->right;                    
               
                                      if((current->right!=NULL) &&(!tmp->visited))
                                      { 
                                             st1.push(current);
                                             current=current->right;
                                              continue; 
                                      }
                                       
                                      
                                       if(!current->visited)
                                      {
                                                cout<<current->data<<endl;
                                                current->visited =1;
                                     }
                  }    
             }

             
/*
 * Inorder Traversal(iterative)
 */             
void BST::iterative_inorder()
             {
               int ctr=0;
                  node *current=root;
                   stack<node*> st1
                  while(current!=NULL)
                  {
                                      while((current!=NULL)&&(!visited))
                                      {
                                                     st1.push(current);
                                                     current=current->left;
                                      }
                                      current=st1.pop();
                                      if(current!=NULL)
                                      {
                                       cout<<current->data<<endl;
                                       ctr++;
                                      }
                                      else
                                      break;
                                      visited=1;
                                      if(current->right!=NULL)
                                      {
                                                              visited=0;
                                                              current=current->right;
                                      }
                  }
                  
                  cout<<"The number of nodes:\n"<<ctr<<endl;
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
 * Breadth First Search Traversal
 */
void BST::BFS(node *root)
{
 queue<node*> q;
   node *item;
   q.enqueue(root);            //insert the root at first
   while(!q.isEmpty())
  {
      item = q.front();            //get the element from the front end
      cout << item->value << " ";
      if(item->left != NULL)         //When left child is present, insert into queue
         q.enqueue(item->left);
      if(item->right != NULL)        //When right child is present, insert into queue
         q.enqueue(item->right);
      q.dequeue(); //remove the item from queue
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
 * Find The Height Of a Tree
 */
void BST::heightoftree(node *root)
{
    int maximum,rightsubtree,leftsubtree ;
    if (root!=NULL)
    {
         leftsubtree = heightoftree(root->left);      /* Finding the height of left subtree. */
        
         rightsubtree = heightoftree(root->right);   /* Finding the height of right subtree */
         if (leftsubtree > rightsubtree)
        {
            maximum = leftsubtree + 1;
            cout<<"Height : "<<maximum;
        }
        else
        {
            maximum = rightsubtree + 1;
            cout<<"Height : "<<maximum;
        }
    }
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
        cout<<"5.Iterative Inorder Traversal"<<endl;
        cout<<"6.Iterative Preorder Traversal"<<endl;
        cout<<"7.Iterative Postorder Traversal"<<endl;
        cout<<"8.Search a node"<<endl;
        cout<<"9.DFS(depth first search) Traversal"<<endl;
        cout<<"10.Creating Mirror Image of the Tree"<<endl;
        cout<<"11.Count the number of leaf nodes, non-leaf nodes and total number of nodes"<<endl;
        cout<<"12.Height of the Tree"<<endl;
        cout<<"13.Quit"<<endl;
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
            cout<<"Inorder Traversal of BST(iterative):"<<endl;
            bst.iterative_inorder();
            cout<<endl;
            break;
	case 6:
            cout<<"Preorder Traversal of BST(iterative):"<<endl;
            bst.iterative_preorder();
            cout<<endl;
            break;
        case 7:
            cout<<"Postorder Traversal of BST(iterative):"<<endl;
            bst.iterative_postorder();
            cout<<endl;
            break;
         case 8:
            cout<<"Enter Data to be searched : "; 
            cin>>data;
            bst.search(data);
                break;
         case 9:
            bst.BFS(root);
            break;
         case 10:
            bst.mirrorimage(root);
            break;
         case 11:
            bst.count_nodes(newnode,root);
            break;
         case 12:
            bst.heightoftree(root);
            break;
         case 13:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}



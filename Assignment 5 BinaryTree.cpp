/*
Aman Munjewar 
SIB18
*/
#include <iostream>
using namespace std;

class bst
{
	int data;
	bst *left, *right, *root;
	public:
		bst* create(int);
		int search(bst*, int);
		bst* insert(bst*, bst*);
		void inorder(bst*);
		bst*left_Node(bst*);
		bst* Delete(bst*, int);
};

bst* bst::create(int item)
{
	bst *newnode = new bst;
	newnode->data = item;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;	
}

int bst::search(bst *root, int key)
{
	bst *curr;
	curr = root;
	if(key == curr->data)
		return 1;
	else
	{
		while(curr!=NULL)
		{
			if(key < curr->data)
			{
				curr = curr->left;	
			}
			else if(key > curr->data)
			{
				curr = curr->right;
			}
			else
			{
				return 1;
			}	
		}
		if(curr == NULL)
		{
			return 0;
		}
	}
}

bst* bst::insert(bst*root, bst*parent)
{
	bst *newnode, *curr;
	int key, valid;
	cout<<"\nEnter the element to be inserted :\n";
	cin>>key;
	newnode = create(key);
	if(root == NULL)
		root = newnode;
	else
	{
		curr = root;
		valid = search(root, key);
		if(valid == 0)
		{
			while(curr!=NULL)
			{
				parent = curr;
				
				if(key < curr->data)
					curr = curr->left;	
				else
					curr = curr->right;
			}
			
				if(key < parent->data)
					parent->left = newnode;
				else
					parent->right = newnode;
		}
		else
		{
			cout<<"\n.....Duplicate Entry.....\n";
			return root;
		}
	}
	return root;
}

void bst::inorder(bst*root)
{
	if(root == NULL)
		return;
	inorder(root->left);
	cout<<root->data<<"\t";
	inorder(root->right);
}

bst * bst::left_Node(bst* node)
{
    bst* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 
bst* bst::Delete(bst* root, int k)
{
	bst* curr;
	bst* parent;
	bst* temp;
	
	if (root == NULL)
        cout<<"\nTree is empty\n";

    curr=root;
    
	while(k!=curr->data)
	{
		if(k<curr->data)
		{
			parent =curr;
			curr=curr->left;
		}
		else
		{
			parent=curr;
			curr=curr->right;
		}
	}
	
		if(curr->left==NULL && curr->right==NULL)
		{
			if(curr!=root)
			{
				if(parent->left==curr)
				{
					parent->left=NULL;
					delete curr;
				}
				else
				{
					parent->right=NULL;
					delete curr;
				}
			}
			else
			{
				root=NULL;
			}
			return root;	
		}
		
		
		else if(curr->left!=NULL && curr->right!=NULL)
		{
			if(curr!=root)
			{
				temp = curr;
				parent =curr;
				curr=curr->right;
				while(curr->left!=NULL)
				{
					parent =curr;
					curr=curr->left;
				}	
				temp->data=curr->data;
				parent->left=NULL;
				delete curr;
			}
			else
			{
				temp = curr;
				parent =curr;
				curr=curr->right;
				while(curr->left!=NULL)
				{
					parent =curr;
					curr=curr->left;
				}
				
				temp->data=curr->data;
				
				if(parent != temp)
					parent->left=NULL;
				else
					temp->right = curr -> right;
					
				delete curr;
				root = temp;
			}
			return root;
		}
		
		else if(curr->left!=NULL && curr->right == NULL)
		{
			if(curr!=root)
			{	
				if(parent->left==curr)
				{
					parent->left=curr->left;
				}
				else
				{
					parent->right=curr->left;	
				}
				delete curr;
			}
			else
			{
				parent = root;
				root = root->left;
				delete parent;
			}
			return root;
		}
		
		else if(curr->left==NULL && curr->right != NULL)
		{
			if(curr!=root)
			{	
				if(parent->left==curr)
				{
					parent->left=curr->right;
				}
				else
				{
					parent->right=curr->right;	
				}
				delete curr;
			}
			else
			{
				parent = root;
				
				root=root->right;
				delete parent;
			}
			return root;
		}
	
} 

int main()
{
	bst t;
	int ch,valid;
	bst *root = NULL;
	bst *parent;
	do
	{
		cout<<"\n.......MENU.......\n1.Insert Element\n2.Search Element\n3.Inorder Traversal\n4.Delete a node\n5.Exit\n";
	
		cin>>ch;
		switch(ch)
		{
			case 1:
				root = t.insert(root, parent);
				break;
			case 2: int a;
				cout<<"\nEnter the element to be searched : ";
				cin>>a;
				valid = t.search(root, a);
				if(valid == 0)
					cout<<"\nElement not found\n";
				else
					cout<<"\nElement found\n";
				break;
			case 3:
				if(root == NULL)
					cout<<"\n.....EMPTY.....\n";
				else
					t.inorder(root);
				break;
			case 4:int k;
				cout<<"\nEnter the element to be deleted : ";
				cin>>k;
				valid = t.search(root, k);
				if(valid == 0)
					cout<<"\nElement is not present";
				else
				{
					root = t.Delete(root, k);
					
					if(root == NULL)
					cout<<"\nNO MORE ELEMENTS\n";
					else
					t.inorder(root);
				}
				break;
			case 5:
				
				exit(0);
			default :
				cout<<"\n....INVALID CHOICE....\n";
		}
	}while(ch!=5);
}



/*OUTPUT

......MENU.......
1.Insert Element
2.Search Element
3.Inorder Traversal
4.Delete a node
5.Exit
1

Enter the element to be inserted :
5

.......MENU.......
1.Insert Element
2.Search Element
3.Inorder Traversal
4.Delete a node
5.Exit
1

Enter the element to be inserted :
6

.......MENU.......
1.Insert Element
2.Search Element
3.Inorder Traversal
4.Delete a node
5.Exit
1

Enter the element to be inserted :
4

.......MENU.......
1.Insert Element
2.Search Element
3.Inorder Traversal
4.Delete a node
5.Exit

1

Enter the element to be inserted :
9

.......MENU.......
1.Insert Element
2.Search Element
3.Inorder Traversal
4.Delete a node
5.Exit
3
4       5       6       9
.......MENU.......
1.Insert Element
2.Search Element
3.Inorder Traversal
4.Delete a node
5.Exit
4

Enter the element to be deleted : 6
4       5       9

.......MENU.......
1.Insert Element
2.Search Element
3.Inorder Traversal
4.Delete a node
5.Exit
5

*/
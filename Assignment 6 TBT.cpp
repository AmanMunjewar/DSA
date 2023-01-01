/*
Aman Munjewar 
SIB18
*/
#include <iostream>
using namespace std;

class tbt
{
	int data;
	tbt *left,*right;
	bool rthread,lthread;
	public:
		tbt* insert(tbt *,tbt *);
		tbt* create(int);
		tbt* leftmostnode(tbt *,tbt *);
		void inorder(tbt *,tbt *);
		tbt* preorder(tbt *,tbt *);
	
};

tbt* tbt :: create(int key)
{
	tbt* newnode=new tbt;
	newnode->data=key;
	newnode->left=newnode;
	newnode->right=newnode;
	newnode->lthread=true;
	newnode->rthread=true;
	return newnode;
}

tbt* tbt :: insert(tbt *root,tbt *head)
{
	int key;
	tbt *curr;
	cout<<"Enter the element to insert:";
	cin>>key;
	tbt *newnode=create(key);
	
	if(root==NULL)
	{
		head->left=newnode;
		root=newnode;
		root->left=root->right->right=head;
		head->lthread=false;
		return root;
		
	}
	else
	{
		curr=root;
		while(1)
		{
			if(curr->data==key)
			{
				cout<<" DUPLICATE ENTRY!";
				return root;;
				break;
			}
			if(key<curr->data)
			{
				if(curr->lthread)
				{
					newnode->left=curr->left;
					curr->left=newnode;
					newnode->right=curr;
					curr->lthread=false;
					break;
				}
				else
				{
					curr=curr->left;
				}
			}
			else
			{
				if(curr->rthread)
				{
						newnode->left=curr;
						newnode->right=curr->right;
						curr->right=newnode;
						curr->rthread=false;
						break;
				}
				else
				{
					curr=curr->right;
				}
			}
		}
	}
	return root; 	
}

tbt *tbt :: leftmostnode(tbt *temp,tbt *head)
{
	if(temp==NULL)
	{
		return NULL;
	}
	else
	{
		while(temp->left!=head)
		{
			if(temp->lthread)
			{
				break;
			}
			temp=temp->left;
			
		}
		return temp;
	}
}

void tbt :: inorder(tbt *root,tbt *head)
{
	tbt * curr;
	curr=leftmostnode(root,head);
	while(curr!=head)
	{
		cout<<"\t"<<curr->data;
		if(curr->rthread)
		{
			curr=curr->right;
		}
		else
		{
			curr=leftmostnode(curr->right,head);
		}
	}
}

tbt* tbt :: preorder(tbt *root,tbt *head)
{
	tbt *curr=root;
		while(1)
		{
			cout<<"\t"<<curr->data;
			if(curr->lthread==false)
			    curr= curr->left;
			else if(curr->rthread==false)
			    curr=curr->right;
			else
			{
				while(curr->right!=head && curr->rthread==true)
				{
					curr=curr->right;
				}
				if(curr->right!=head)
				    curr=curr->right;
				else
				    break;
			}
			
		}
}

int main()
{
	tbt *root= NULL;
	int ch;
	tbt t;
	tbt *head=t.create(999);
	do {
		cout<<"\nEnter the choice:\n1)Insert\n2)Inorder\n3)Preorder\n4)Exit\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				root=t.insert(root,head);
				break;
				
			case 2:
				t.inorder(root,head);
				break;
			case 3:
				t.preorder(root,head);
				break;
			case 4:
				
				break;
				
		}
	}while(ch!=4);
	
}

/*OUTPUT


Enter the choice:
1)Insert
2)Inorder
3)Preorder
4)Exit
1
Enter the element to insert:5

Enter the choice:
1)Insert
2)Inorder
3)Preorder
4)Exit
1
Enter the element to insert:3

Enter the choice:
1)Insert
2)Inorder
3)Preorder
4)Exit
1
Enter the element to insert:4

Enter the choice:
1)Insert
2)Inorder
3)Preorder
4)Exit
1
Enter the element to insert:6

Enter the choice:
1)Insert
2)Inorder
3)Preorder
4)Exit
2
        3       4       5       6
Enter the choice:
1)Insert
2)Inorder
3)Preorder
4)Exit
3
        5       3       4       6
Enter the choice:
1)Insert
2)Inorder
3)Preorder
4)Exit
4
*/

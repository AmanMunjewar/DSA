/*
Aman Munjewar 
SIB18
*/
#include<iostream>

using namespace std;


class Tree{
	
	
	char data;
	Tree *left;
	Tree *right;
	
      public:
		Tree(){
		left=NULL;
		right=NULL;
		
		}
		Tree*create(char);
		Tree* expression(char[]);
		void inorderrecursion(Tree*);
		void preorderrecursion(Tree*);
		void postorderrecursion(Tree*);
		void inorder(Tree*);
		void preorder(Tree*);
		void postorder(Tree*);
		
};

class stack{
public:
	
     Tree *t;
 
	stack*next,*top;

	stack(){
		top=NULL;
	}
	void push(Tree*);
	void pop();	
};



void stack::push(Tree* value){
	stack*newnode= new stack;
	newnode->t=value;
	newnode->next=NULL;
	if(top==NULL){
		top=newnode;
	}
	else{
		newnode->next=top;
		top=newnode;
	}
}


void stack::pop(){
	if(top==NULL){
		cout<<"stack is empty";
	}
	else{
		stack*ptr=top;
		top=top->next;
		delete ptr;
	}
}


Tree*Tree::create(char oper){
	Tree*newtree=new Tree();
	newtree->data=oper;
	return newtree;
}


Tree*Tree::expression(char postfix[]){
         
	Tree*ptr;
     stack s;
	char a;
	int i=0;
	while(postfix[i]!='\0'){
			ptr=create(postfix[i]);
		if(isalnum(postfix[i])){
		
		    	s.push(ptr);
			
		}
		else{
		
			
			ptr->right=s.top->t;
				s.pop();
		
			ptr->left=s.top->t;
				s.pop();
				s.push(ptr);
		}
		i++;
	}
ptr=s.top->t;

return ptr;
}


void Tree::inorder(Tree *root){                 
	
	Tree *curr=root;
	stack S;
	
	while(true){
	
	while(curr!=NULL){
		
		S.push(curr);
		curr=curr->left;
	}
	
	if(S.top!=NULL){
		curr=S.top->t;
		cout<<curr->data;
		S.pop();
		curr=curr->right;
	}
	
	else{
		break;
	}
	
    }
    
	
}

void Tree::preorder(Tree *root){
	
	Tree *curr=root;
	stack S;
	
	while(true){
		
		while(curr!=NULL){
			cout<<curr->data;
			
			if(curr->right != NULL){
				S.push(curr->right);
			}
			curr=curr->left;	
		}
		
		if(S.top!=NULL){
			curr=S.top->t;
			S.pop();
			
		}
		
		else{
			break;
		}
		
	}
	
}

void Tree::postorder(Tree *root){
	
	Tree *curr=root;
	
	stack S;
	while(true){
		
		while(curr!=NULL){
			
			if(curr->right != NULL){
				S.push(curr->right);
			}
			S.push(curr);
			curr=curr->left;
		}
		
		curr=S.top->t;
		S.pop();
		
		if((S.top!=NULL) &&  (S.top->t==curr->right)){
			
			S.pop();
			S.push(curr);
			curr=curr->right;	
		}
		
		else{
			cout<<curr->data;
			curr=NULL;
			
        }
	}
	
}

void Tree::inorderrecursion(Tree*root){
	if(root==NULL){
		return;
	}
	inorderrecursion(root->left);
	cout<<root->data;
	inorderrecursion(root->right);
}
void Tree:: preorderrecursion(Tree*root){
	if(root==NULL){
		return;
	}
	cout<<root->data;
	preorderrecursion(root->left);
	preorderrecursion(root->right);
	
}
void Tree::postorderrecursion(Tree*root){
	if(root==NULL){
		return;
	}
	postorderrecursion(root->left);
	postorderrecursion(root->right);
	cout<<root->data;
}

int main(){
	Tree T;
	Tree* a;
	
		char postfix[20];
		cout<<"Enter postfix expression:";
		cin>>postfix;
		a=T.expression(postfix);
		cout<<"\nInorder expression is :  ";
		T.inorder(a);
		cout<<"\nInorder Non-Recursive expression is:  ";
		T.inorderrecursion(a);
		cout<<endl;
			
    	
	 
		
	
	cout<<"\nPreorder expression is:  ";
	   T.preorder(a);
	   	cout<<"\nPreorder Non-Recursive expression is:   ";
    	T.preorderrecursion(a);
	cout<<endl;
		cout<<"\nPostorder Non-Recursive expression is:  ";
	T.postorderrecursion(a);
	cout<<"\nPostorder expression is:  ";
	T.postorder(a);
	
	cout<<endl;
		
}


/*OUTPUT

Enter postfix expression:CD*

Inorder expression is :  C*D
Inorder Non-Recursive expression is:  C*D

Preorder expression is:  *CD
Preorder Non-Recursive expression is:   *CD

Postorder Non-Recursive expression is:  CD*
Postorder expression is:  CD*

*/

/*
Aman Munjewar 
SIB18
*/
#include<iostream>

using namespace std;

class cir_queue{
int front ,rear,n;

public:
	cir_queue(){
		
		front=rear=-1;
	}
    int Insertion(int[],int, int);
	int Deletion(int[],int);
	int queuefull(int[],int);
    int queueempty(int[],int);
    void display(int[],int);
};

int cir_queue::Insertion(int queue[],int key, int n)
{
if(front==-1)
    {
        front++;
    }
    rear=(rear+1)%n;
    queue[rear]=key;
    
    return 0;
}


int cir_queue::Deletion(int queue[], int n)
{
	
int del;
    del=queue[front];
    

    if(front == rear){
    	front=-1;
    	rear=-1;
	}
	
	else{
		front=(front+1)%n;
	}
	
	return del;
}

int cir_queue::queuefull(int queue[], int n){
	
	if ((rear+1)%n==front){
		return 0;
	}
	
	else{
	
	return -1; 
	}
	
}

int cir_queue::queueempty(int queue[],int n){
	
	if (front=rear=-1) {
      return 0; 
   }
   else{
   	return -1;
   }
}

void cir_queue::display(int queue[],int n){
  int i;   
    for( i=front ;i!=rear;i=(i+1)%n){
        cout<<queue[i]<<"\t";
    }
    cout<<queue[i];
}

int main(){
	int n,element,a,b,del;
    cout<<"Enter the size of queue:";
                cin>>n;
		
    int queue[20];	
	cir_queue q;
	int ch;
	do{
	
	cout<<"\n\n1.Insertion\n2.Display\n3.Deletion\n4.Queuefull and Queueempty\n5.exit\n";
	cin>>ch;
	
	switch(ch){
		
		case 1:
	     	cout<<"Enter the elements in queue:"<<endl;
		     
			  for(int i=0;i<n;i++){
			  
		       cin>>element;
		       q.Insertion(queue,element,n);}
			 break;
			   
			   
	    case 2:q.display(queue,n);
	         break;	
	           
			   
	   case 3: 
			 		
	         del=q.Deletion(queue,n);
	          cout<<"\nDeleted element is:"<<endl;
			  cout<<del<<endl;
	
                     
			  break;
			  
	  
	         
	         
	    case 4:     
	  a=q.queuefull(queue,n);
	  b=q.queueempty(queue,n);
	         if(a==0){
               cout<<"\nQueue is full"<<endl;
           }
           
           else if(b==0){
               cout<<"\nQueue is empty"<<endl;
           }
           
           else{
           	   cout<<"\nQueue is neither empty nor full"<<endl;
		   }
           break;
			 
       case 5:exit(0);
              
	           break;			 
			 
			 
	 	  		   
	}}while(ch!=5);
	
	return 0;
}

/*       OUTPUT


Enter the size of queue:5

1.Insertion
2.Display
3.Deletion
4.Queuefull and Queueempty
5.exit
1
Enter the elements in queue:
5
4
6
8
1

1.Insertion
2.Display
3.Deletion
4.Queuefull and Queueempty
5.exit
2
5       4       6       8       1

1.Insertion
2.Display
3.Deletion
4.Queuefull and Queueempty
5.exit
3

Deleted element is:
5

1.Insertion
2.Display
3.Deletion
4.Queuefull and Queueempty
5.exit

3

Deleted element is:
4

1.Insertion
2.Display
3.Deletion
4.Queuefull and Queueempty
5.exit
4

Queue is empty

1.Insertion
2.Display
3.Deletion
4.Queuefull and Queueempty
5.exit

*/
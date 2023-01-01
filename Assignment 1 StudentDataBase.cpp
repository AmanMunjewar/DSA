/*
Aman Munjewar 
SIB18
*/
#include<iostream>
using namespace std;

struct Student
{
    string name;
    int rollno;
    float SGPA;
};

int a;


struct Student S[15];

void input(int p){
   cout<<"\nEnter the student data";
   cout<<"\nStudent name:";
   cin>>S[p].name;
   cout<<"Roll no.:";
   cin>>S[p].rollno;
   cout<<"SGPA:";
   cin>>S[p].SGPA;
}

void display(int q){
    
    cout<<" "<<S[q].name<<"\t "<<S[q].rollno<<"\t\t "<<S[q].SGPA<<endl;
}

float j;
void search(){
    cout<<"\n\nEnter SGPA of student you want to search:";
    cin>>j;
    int f=0;
    cout<<"\n Name  "<<"\t"<<"Roll no ";	

    for(int i=0;i<a;i++){
        
        if(S[i].SGPA==j){
            cout<<"\n"<<S[i].name<<"   \t"<<S[i].rollno<<" "<<endl;
            f=1;
        }
    }

    if(f==0){
        cout<<"Record not found"<<endl;

    }
}


void bubble(struct Student S[15],int a)
{
	int n,d;
	for(n=1; n<a; n++)
	
    {
        for(d=0; d<(a-1); d++)
        {
            if(S[d].rollno>S[d+1].rollno)
            {
               struct Student temp = S[d];
                S[d] = S[d+1];
                S[d+1] = temp;
            }
        }
    }

  
        
}




void binary(struct Student S[15],int a){

    int low=0;
    int high=a-1;
    
    int start_index;
    int end_index;
    string target;
    cout<<"\n\nEnter Name of student you want to search:";
    cin>>target;
                     cout<<"\n Name "<<"\t"<<"Roll no  "<<"\t"<<"SGPA "<<endl;
    while(low<=high){              
        
        int mid=(low+high)/2;

        if(S[mid].name==target){
            start_index=mid;
            high=mid-1;
        }

        else if(S[mid].name>target){
            high=mid-1;
        }

        else{
            low=mid+1;
        }

        
    }

    low=0;
    high=a-1;
        

    while(low<=high){
        
        int mid=(low+high)/2;

        if(S[mid].name==target){
            end_index=mid;
            low=mid+1;
        }

        else if(S[mid].name>target){
            high=mid-1;
        }

        else{
           low=mid+1; 
        }

        
    }
    if(start_index != -1 && end_index != -1){

        for(int j=start_index; j<=end_index; j++){
            cout<<"\n "<<S[j].name<<" \t   "<<S[j].rollno<<"   \t"<<S[j].SGPA<<endl;
        }
    }

    else{
        cout<<"Record not found";
    }

}


void Insertionsort(struct Student S[15],int a){

    for(int i=1; i<=a-1; i++){ 
	            
        struct Student temp=S[i];
         int j=i-1;
         while(j>=0 && temp.name<S[j].name){

            S[j+1]=S[j];
            j--;
         }

        S[j+1]=temp;
    }
}


int partition(struct Student S[15],int start ,int end){             
    float pivot = S[start].SGPA;
    
    int i=start+1;
    int j=end;
    
    do{
        while(S[i].SGPA<=pivot){
           i++;
        }

        while(S[j].SGPA>pivot){
           j--;
        }

        if(i<j){
            struct Student temp=S[i];
            S[i]=S[j];
            S[j]=temp;
        }

    } while (i<j);

    

    struct Student temp=S[start];
    S[start]=S[j];
    S[j]=temp;

    return j;
    
}

void quicksort(struct Student S[15],int start, int end){

    if(start<end){
        int partitionindex= partition(S,start,end);
        quicksort(S,start,partitionindex-1);
        quicksort(S,partitionindex+1,end);
    }
}



int main(){
    int ch;
    cout<<"\nEnter the total no. of records: ";
    cin>>a;
   
        do{
                cout<<"\n1.Enter Record\n2.Display Record\n3.Bubble sort\n4.Insertion sort\n5.Binary Search\n6.Quick sort\n7.Search record by sgpa\n8.Exit"<<endl;
               cout<<"\nEnter Your choice:";
			    cin>>ch;
        

                switch(ch){

                   case(1):
                 
                     for(int i=0;i<a;i++){
                        input(i);
                     }
                     break;

                   case(2):cout<<"           DATA                ";
                     cout<<"\n Name  "<<"\t"<<"Roll no "<<"\t"<<"SGPA "<<endl;
                     for(int i=0;i<a;i++){
                         display(i);
                     }
                     break;

                   case(3):
                     bubble(S,a);
                     cout<<"\n Name  "<<"\t"<<"Roll no "<<"\t"<<"SGPA "<<endl;
                     for(int i=0;i<a;i++){
                         display(i);
                         
                     }
                     break;

                   case(4):       
                     Insertionsort(S,a);
            
                    cout<<"\n Name  "<<"\t"<<"Roll no "<<"\t"<<"SGPA "<<endl;
                     for(int i=0;i<a;i++){
                         display(i);
                     }
                     break;

                   case(5):
                   	 Insertionsort(S,a);
                     binary(S,a);
                     
                     break;
                
                   case(6):
                     quicksort(S,0,a-1);
                    cout<<"\n Name  "<<"\t"<<"Roll no "<<"\t"<<"SGPA "<<endl;
                     for(int i=a-1;i>=0;i--){
                         display(i);
                     }
                     break;

                   case(7): 
                     search();
                     break;

                   
                     
                   case(8):
                   	 exit;
                   
                   
    
                }

        }while(ch!=8);      
        

    return 0;

}


/*

Enter the total no. of records: 3

1.Enter Record
2.Display Record
3.Bubble sort
4.Insertion sort
5.Binary Search
6.Quick sort
7.Search record by sgpa
8.Exit

Enter Your choice:1
Enter the student data
Student name:Raj
Roll no.:12
SGPA:88.45
Enter the student data
Student name:Manish
Roll no.:6
SGPA:90.00
Enter the student data
Student name:Yash
Roll no.:10
SGPA:87.66

1.Enter Record
2.Display Record
3.Bubble sort
4.Insertion sort
5.Binary Search
6.Quick sort
7.Search record by sgpa
8.Exit

Enter Your choice:2
           DATA                
 Name   Roll no         SGPA 
 Raj     12              88.45
 Manish  6               90
 Yash    10              87.66

1.Enter Record
2.Display Record
3.Bubble sort
4.Insertion sort
5.Binary Search
6.Quick sort
7.Search record by sgpa
8.Exit

Enter Your choice:3

 Name   Roll no         SGPA 
 Manish  6               90
 Yash    10              87.66
 Raj     12              88.45

1.Enter Record
2.Display Record
3.Bubble sort
4.Insertion sort
5.Binary Search
6.Quick sort
7.Search record by sgpa
8.Exit

Enter Your choice:4

 Name   Roll no         SGPA 
 Manish  6               90
 Raj     12              88.45
 Yash    10              87.66

1.Enter Record
2.Display Record
3.Bubble sort
4.Insertion sort
5.Binary Search
6.Quick sort
7.Search record by sgpa
8.Exit

Enter Your choice:5


Enter Name of student you want to search:Yash

 Name   Roll no         SGPA 

 Yash      10           87.66

1.Enter Record
2.Display Record
3.Bubble sort
4.Insertion sort
5.Binary Search
6.Quick sort
7.Search record by sgpa
8.Exit
*/
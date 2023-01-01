/*
Aman Munjewar 
SIB18
*/
#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
  class RECORD{
		public:
		int rollNo,roll1;
		char name[10];
		char div;
		char address[20];
		void accept()
  {
		 cout<<"\nEnter Roll Number: ";
		 cin>>rollNo;
		 cout<<"\nEnter the Name : ";
		 cin>>name;
		 cout<<"\nEnter the Division:";
		 cin>>div;
		 cout<<"\nEnter the Address:";
		 cin>>address;
  }
	void accept2(){
			        cout<<"\nEnter the Roll No. to modify : ";
			        cin>>rollNo;
			 }
	void accept3(){
			      cout<<"\nEnter the name to modify : ";
			    cin>>name;
			 }
			     int getRollNo()
			 {
			 return rollNo;
			 }
	 void show()
			 {
			 cout<<"\n"<<rollNo<<"\t\t"<<name<<"\t\t"<<div<<"\t\t"<<address;
			 }
};

int main(){
   int i,n,ch,ch1,rec,start,count,add,n1,add2,start2,n2,y,a,b,on,oname,add3,start3,n3,y1,add4,start4,n4;
   char name[20],name2[20];
     RECORD R;
    count=0;
   fstream g,f;
				    do
				{
				 cout<<"\n.................................MENU................................";
				 cout<<"\n1.Insert and overwrite\n2.Show\n3.Search & Edit(number)\n4.Search & Edit(name)\n5.Search & Edit(onlynumber)\n6.Search & edit(only name)\n7.Delete a Student Record\n8.Exit\nEnter the Choice\n";
				 cin>>ch;
				 switch(ch)
				 {
				  case 1:
				     f.open("StuRecord.txt",ios::out);
				      x:R.accept();
				      f.write((char*) &R,(sizeof(R)));
				      cout<<"\nDo you want to enter more records?\n1.Yes\n2.No";
				    cin>>ch1;
				       if(ch1==1)
				      goto x;
				     else {
				     f.close();
				     break;
				    }
				 case 2:
				      f.open("StuRecord.txt",ios::in);
				      f.read((char*) &R,(sizeof(R)));
				      cout<<"Rollno\t\tName\t\tDivision\t\tAddress";
				 while(f)
				    {    
						 R.show();
						 f.read((char*) &R,(sizeof(R)));
				 }
				   f.close();
				     break;
				 case 3:
						 cout<<"\nEnter the roll number you want to find";
						 cin>>rec;
						 f.open("StuRecord.txt",ios::in|ios::out);
						 f.read((char*)&R,(sizeof(R)));
				 while(f)
				 {
						 if(rec==R.rollNo)
						 {
						 cout<<"\nRecord found";
						 add=f.tellg();
						 f.seekg(0,ios::beg);
						 start=f.tellg();
						 n1=(add-start)/(sizeof(R));
						 f.seekp((n1-1)*sizeof(R),ios::beg);
						 R.accept();
						 f.write((char*) &R,(sizeof(R)));
						 f.close();
						 count++;
				    break;
				 }
				    f.read((char*)&R,(sizeof(R)));
				 }
				 if(count==0)
				    cout<<"\nRecord not found";
				     f.close();
				 break;
				 
				 case 4:
						 cout<<"\nEnter the name you want to find and edit";
						 cin>>name;
						 f.open("StuRecord.txt",ios::in|ios::out);
						 f.read((char*)&R,(sizeof(R)));
				 while(f)
				 {
				     y=(strcmp(name,R.name));
				     if(y==0)
				 {
						 cout<<"\nName found";
						 add2=f.tellg();
						 f.seekg(0,ios::beg);
						 start2=f.tellg();
						 n2=(add2-start2)/(sizeof(R));
						 f.seekp((n2-1)*sizeof(R),ios::beg);
						 R.accept();
						 f.write((char*) &R,(sizeof(R)));
						 f.close();
			     	 break;
				 }
				   f.read((char*)&R,(sizeof(R)));
				  }
				 break;
				 case 5:
					 cout<<"\n\tEnter the roll number you want to modify";
					 cin>>on;
					 f.open("StuRecord.txt",ios::in|ios::out);
					 f.read((char*) &R,(sizeof(R)));
				 while(f)
				 {
				 if(on==R.rollNo)
				 {
						 cout<<"\n\tNumber found";
						 add3=f.tellg();
						 f.seekg(0,ios::beg);
						 start3=f.tellg();
						 n3=(add3-start3)/(sizeof(R));
						 f.seekp((n3-1)*(sizeof(R)),ios::beg);
						 R.accept2();
						 f.write((char*)&R,(sizeof(R)));
						 f.close();
				 break;
				 }
				 f.read((char*)&R,(sizeof(R)));
				 }
				 break;
				 
				 case 6:
					 cout<<"\nEnter the name you want to find and edit";
					 cin>>name2;
					 f.open("StuRecord.txt",ios::in|ios::out);
					 f.read((char*)&R,(sizeof(R)));
				 while(f)
				 {
				   y1=(strcmp(name2,R.name));
				 if(y1==0)
				 {
					 cout<<"\nName found";
					 add4=f.tellg();
					 f.seekg(0,ios::beg);
					 start4=f.tellg();
					 n4=(add4-start4)/(sizeof(R));
					 f.seekp((n4-1)*sizeof(R),ios::beg);
					 R.accept3();
					 f.write((char*) &R,(sizeof(R)));
					 f.close();
				 break;
				 }
				   f.read((char*)&R,(sizeof(R)));
				 }
				 break;
				 
				 case 7:
						 int roll;
						 cout<<"Please Enter the Roll No. of Student Whose Info You Want to elete: ";
						 cin>>roll;
						 f.open("StuRecord.txt",ios::in);
						 g.open("temp.txt",ios::out);
						 f.read((char *)&R,sizeof(R));
						 while(!f.eof())
						 {
						 if (R.getRollNo() != roll)
						 g.write((char *)&R,sizeof(R));
						 f.read((char *)&R,sizeof(R));
						 }
						 cout << "The record with the roll no. " << roll << " has been deleted " << 
						endl;
						 f.close();
						 g.close();
						 remove("StuRecord.txt");
						 rename("temp.txt","StuRecord.txt");
						 break;
						 
						 case 8:exit(0);
						
				 break;
				 }
				 }while(ch!=8);
				}



/*
.................................MENU................................
1.Insert and overwrite
2.Show
3.Search & Edit(number)
4.Search & Edit(name)
5.Search & Edit(onlynumber)
6.Search & edit(only name)
7.Delete a Student Record
8.Exit
Enter the Choice
1

Enter Roll Number: 14

Enter the Name : manish

Enter the Division:b

Enter the Address:mlk

Do you want to enter more records?
1.Yes
2.No1

Enter Roll Number: 15

Enter the Name : aniket

Enter the Division:c

Enter the Address:pune

Do you want to enter more records?
1.Yes
2.No2

.................................MENU................................
1.Insert and overwrite
2.Show
3.Search & Edit(number)
4.Search & Edit(name)
5.Search & Edit(onlynumber)
6.Search & edit(only name)
7.Delete a Student Record
8.Exit
Enter the Choice
2
Rollno          Name            Division                Address
14              manish          b               mlk
15              aniket          c               pune
.................................MENU................................
1.Insert and overwrite
2.Show
3.Search & Edit(number)
4.Search & Edit(name)
5.Search & Edit(onlynumber)
6.Search & edit(only name)
7.Delete a Student Record
8.Exit
Enter the Choice
3

Enter the roll number you want to find14

Record found
Enter Roll Number: 16

Enter the Name : adesh

Enter the Division:c

Enter the Address:mlk

.................................MENU................................
1.Insert and overwrite
2.Show
3.Search & Edit(number)
4.Search & Edit(name)
5.Search & Edit(onlynumber)
6.Search & edit(only name)
7.Delete a Student Record
8.Exit
Enter the Choice
2
Rollno          Name            Division                Address
16              adesh           c               mlk
15              aniket          c               pune

.................................MENU................................
1.Insert and overwrite
2.Show
3.Search & Edit(number)
4.Search & Edit(name)
5.Search & Edit(onlynumber)
6.Search & edit(only name)
7.Delete a Student Record
8.Exit
Enter the Choice
7
Please Enter the Roll No. of Student Whose Info You Want to elete: 15
The record with the roll no. 15 has been deleted

.................................MENU................................
1.Insert and overwrite
2.Show
3.Search & Edit(number)
4.Search & Edit(name)
5.Search & Edit(onlynumber)
6.Search & edit(only name)
7.Delete a Student Record
8.Exit
Enter the Choice
8

*/
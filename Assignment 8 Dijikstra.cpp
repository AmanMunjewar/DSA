/*
Aman Munjewar 
SIB18
*/
#include <iostream>
using namespace std;

class graph
{
	int source,vertex,edge;
	int mat[20][20];
	int infinite = 999;
	public:
		void getGraph();
		void displayMatrix();
		void display(int [],int [],int);
		int minimum(int [],bool []);
		void dijkstra();
};

void graph::getGraph()
{
	int s,d,w;
	cout<<"Enter the total no. of vertices : ";
	cin>>vertex;
	cout<<"Enter the total no. of edges : ";
	cin>>edge;
	for(int i=0;i<vertex;i++)
	{
		for(int j=0;j<vertex;j++)
		{
		mat[i][j]=0;
		}
	}
	for(int i=0;i<edge;i++)
	{
		cout<<"\nEnter the source vertex :";
		cin>>s;
		cout<<"Enter the destination vertex :";
		cin>>d;
		cout<<"Enter the weight of edge :";
		cin>>w;
		mat[s][d]=w;
		mat[d][s]=w;
	}
}

void graph ::display(int dist[],int parent[],int src)
{
	int nodes[vertex]={0},n,e;
	cout<<"Vertex\tDistance\tPath\n";
	
	for(int i=0;i<vertex;i++)
	{
		cout<<i<<"\t"<<dist[i]<<"\t\t";
		e=i;
		n=0;
		while(e!=src)
		{
			nodes[n]=e;
			e=parent[e];
			n++;
		}
		nodes[n]=e;
		for(int j=n;j>0;j--)
		{
			cout<<nodes[j]<<"-";
		}
		cout<<nodes[0];
		cout<<"\n";
	}
}

void graph ::displayMatrix()
{
	cout<<"\nAdjacency Matrix is : \n";
	for(int k=0; k<vertex; k++)
	{
		cout<<"\t"<<k;
	}
	cout<<"\n";
	for(int k=0; k<vertex; k++)
	{
		cout<<"\t|";
	}
	cout<<"\n\n";
	for(int i=0;i<vertex;i++)
	{
		cout<<i<<" -- ";
		for(int j=0;j<vertex;j++)
			{
				cout<<"\t"<<mat[i][j];
			}
		cout<<"\n";
	}
}

int graph ::minimum(int a[],bool b[])
{
	int min,max=infinite;
	for(int i=0;i<vertex;i++)
	{
		if(b[i]==false && a[i]<max)
		{	
			max=a[i];
 			min=i;
		}
	}
	return min;
}

void graph ::dijkstra()
{
	int parent[vertex],dist[vertex],s;
	bool visit[vertex];
	for(int i=0;i<vertex;i++)
	{
		parent[i]=i;
		dist[i]=infinite;
		visit[i]=false;
	}
	cout<<"\nEnter the Start vertex :";
	cin>>s;
	source=s;
	dist[s]=0;
	for(int i=0;i<vertex;i++)
	{
		s=minimum(dist,visit);
		visit[s]=true;
		for(int j=0;j<vertex;j++)
		{
			if(mat[s][j]!=0 && visit[j]==false && dist[s]+mat[s][j]<dist[j])
			{
				dist[j]=dist[s]+mat[s][j];
				parent[j]=s;
			}
		}
	}
	display(dist,parent,source);
}

int main()
{
	graph obj;
	obj.getGraph();
	cout<<"\n\n";
	obj.displayMatrix();
	cout<<"\n\n";
	obj.dijkstra();
	return 0;
}

/*
Enter the total no. of vertices : 3
Enter the total no. of edges : 3

Enter the source vertex :0
Enter the destination vertex :1
Enter the weight of edge :5

Enter the source vertex :0
Enter the destination vertex :2
Enter the weight of edge :3

Enter the source vertex :0
Enter the destination vertex :3
Enter the weight of edge :4



Adjacency Matrix is : 
        0       1       2
        |       |       |

0 --    0       5       3
1 --    5       0       0
2 --    3       0       0



Enter the Start vertex :0
Vertex  Distance        Path
0       0               0
1       5               0-1
2       3               0-2
*/
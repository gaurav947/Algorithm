#include<bits/stdc++.h>
using namespace std;
int mindistance(int dist[],bool visit[],int V)
{
	int min = INT_MAX,min_index;
	for(int v=0;v<V;v++)
	{
		if(visit[v]==false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}
void printPath(int parent[],int j)
{
	if(parent[j] == -1)
	{
		return;
	}
	printPath(parent,parent[j]);
	
	cout<<"*"<<j;
}
void printsolution(int parent[],int dist[],int V,int src,int t)
{
	cout<<"vertex"<<"      "<<"distance"<<"   "<<"Path"<<endl;
	for(int i =0;i<V;i++)
	{
		if(i==t)
		{
		cout<<src<< "->"<<i<<"    "<<dist[i]<<"      "<<src;
		printPath(parent,i);
		cout<<endl;
	    }
	}
}
void dijkstra(int graph[][10],int src,int V,int t)
{
  	int dist[V];
  	bool visit[V];
  	int parent[V];
  	for(int i=0;i<V;i++)
  	{
  		dist[i]=INT_MAX;
  		visit[i] = false;
	}
	dist[src] = 0;
	parent[src]=-1;
	//find shortest path	
	//Pick shortest distance vertex 
	for(int count=0;count<V-1;count++)
	{
			
	//Pick shortest distance vertex 
		int u = mindistance(dist,visit,V);
		
		//set as visit
		visit[u] = true;
		
		//Pick the neighbour 
		for(int v=0;v<V;v++)
		{
			if(!visit[v] && graph[u][v]  && dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u]+graph[u][v];
			}
		}
		
	}
	printsolution(parent,dist,V,src,t);
} 
int main()
{
	int i,j,V;
	int graph[10][10];
	cout<<"Enter the No. of vertices in the graph = ";
	cin>>V;
	cout<<"\n";
	for(i=0;i<V;i++)
	{
		for(j=i;j<V;j++)
		{
			if(i!=j)
			{
				cout<<"Enter 1 ( if vertex *"<<i<<" is adjacent to *"<<j<<" ),otherwise 0 : =";
				cin>>graph[i][j];
				graph[j][i]=graph[i][j];	
			}
			else
			{
				graph[i][j] = 0;
			}
		}
	}
	int p,t;
	cout<<"From Where Dijkstra start = ";
	cin>>p;
	cout<<"Target = ";
	cin>>t;
	dijkstra(graph,p,V,t);                   
	return 0;
}
					                     
					   
					   
					    
				                         

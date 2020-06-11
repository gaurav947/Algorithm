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
void printsolution(int dist[],int V ,int src)
{
	cout<<"vertex"<<"   "<<"Distance from "<<src<<endl;
	for(int i =0 ;i<V;i++)
	{
		cout<<i <<"----------"<<dist[i]<<endl;
	}
}
void dijkstra(int graph[][10],int src,int V)
{
  	int dist[V];
  	bool visit[V];
  	
  	for(int i=0;i<V;i++)
  	{
  		dist[i]=INT_MAX;
  		visit[i] = false;
	}
	dist[src] = 0;
	
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
			if(!visit[v] && graph[u][v] && dist[u]!=INT_MAX && dist[u] + graph[u][v] < dist[v])
			{
				dist[v] = dist[u]+graph[u][v];
			}
		}
		
	}
	printsolution(dist,V,src);
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
	int p;
	cout<<"From Where Dijkstra start = ";
	cin>>p;
	dijkstra(graph,p,V);                   
	return 0;
}
					                     
					   
					   
					    
				                         

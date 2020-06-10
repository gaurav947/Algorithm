#include<bits/stdc++.h>
using namespace std;
#define v 5
int findminvertex(int key[],bool mstvisit[])
{
	int min = INT_MAX,min_index;
	for(int i=0;i<v;i++)
	{
		if(mstvisit[i]==false && key[i] < min)
		{
			min = key[i];
			min_index = i;
		}
	}
	return min_index;
}
void printMST(int parent[],int graph[v][v])
{
	cout<<"Edge \tWeight\n"; 
	for(int i=1;i<v;i++)
	{
		cout<<parent[i]<<"--"<<i<<"       "<<   graph[i][parent[i]]<<endl;
	}
}
void prim(int graph[v][v])
{
	int parent[v];
	int key[v];
	bool mstvisit[v];
	
	for(int i=0;i<v;i++)
	{
		key[i] = INT_MAX;
		mstvisit[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	for(int count=0;count<v-1;count++)
	{
		//find the vertex
		int u = findminvertex(key,mstvisit);
		mstvisit[u] = true;
		//find vertex neighbours
		for(int V=0;V<v;V++)
		{
			if(graph[u][V]!=0 && mstvisit[V]==false && graph[u][V] < key[V])
			{
				parent[V] = u;
				key[V] = graph[u][V];
			}
		}
	
	}
	printMST(parent,graph);
}
int main()
{
	int graph[v][v] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 
	prim(graph);					
						
}

#include<iostream> 
#include <list> 
#include <stack> 
using namespace std; 

class Graph 
{ 
	int V;	 
	list<int> *adj; 

	void topologicalSortUtil(int v, bool visited[], stack<int> &Stack); 
public: 
	Graph(int V); 
	void addEdge(int v, int w); 

	void topologicalSort(); 
	void print(int v);
}; 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
} 
void Graph::print(int v)
{
	list<int>::iterator it;
	for(int i=0;i<v;i++)
	{
		cout<<"Adjancency List of ( "<<i<<")";
		for(it = adj[i].begin();it!=adj[i].end();it++)
		{
			cout<<"->"<<*it;
		}
		cout<<"->X";
		cout<<"\n";
	}
}
void Graph::topologicalSortUtil( int v, bool visited[], stack<int> &Stack) 
{ 
   cout<<"end v = "<<v;
	visited[v] = true; 

	list<int>::iterator i; 
	
	for (i = adj[v].begin(); i != adj[v].end(); ++i)
	{
		if (!visited[*i]) 
		{  
			topologicalSortUtil(*i, visited, Stack); 
		}
	}

	Stack.push(v); 
} 

void Graph::topologicalSort() 
{ 
	stack<int> Stack; 
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
	{
		cout<<"SHuru = "<<i;
		visited[i] = false; 
	}
    cout<<"v = "<<V;
	for (int i = 0; i < V; i++) 
	{
		cout<<"PRO = "<<i;
	if (visited[i] == false) 
	{
		cout<<"Visited = "<<i;

		topologicalSortUtil(i, visited, Stack); 
	}
}
	

    cout<<"\nTOPO = ";
	while (Stack.empty() == false) 
	{ 
		cout << Stack.top() << " "; 
		Stack.pop(); 
	} 
} 
 
int main()  
{ 
	
	Graph g(6); 
	g.addEdge(5, 2); 
	g.addEdge(5, 0); 
	g.addEdge(4, 0); 
	g.addEdge(4, 1); 
	g.addEdge(2, 3); 
	g.addEdge(3, 1); 
	
	g.print(6);
	cout << "Following is a Topological Sort of the given graph \n"; 
	g.topologicalSort(); 

	return 0; 
} 


#include<iostream>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
class Edge{
	public:
	int source;
	int dest;
	int weight;
};
bool compare(Edge e1,Edge e2)
{
	return e1.weight < e2.weight;
}
int findParent(int v,int *parent)
{
	if(parent[v]==v)
	{
		return v;
	}
	else
	{
		findParent(parent[v],parent);
	}
}
void kruskals(Edge *input , int n,int E)
{
	sort(input,input+E,compare);
	
	Edge *output = new Edge[n-1];
	 int *parent = new int[n];
	 for(int i= 0 ;i<n;i++)
	 {
	 	parent[i] = i;
	 }
	 int count = 0;
	 int i=0;
	 while(count!=n-1)
	 {
	 	Edge currentEdge = input[i];
	 	
	 	int sourceParent = findParent(currentEdge.source,parent);
	 	int destParent  = findParent(currentEdge.dest,parent);
	 	
	 	if(sourceParent != destParent)
	 	{
	 		output[count] = currentEdge;
	 		count++;
	 		parent[sourceParent] = destParent;
        }
        i++;
	 	
	 }
	 cout<<"....YOUR Minimal Spanning Tree with Kruskals...\n";
	 	cout<<setw(4)<<"S"<<setw(2)<<"D"<<setw(2)<<"W"<<endl;
	 for(int i=0;i<n-1;i++)
	 {
	 	cout<<i<<"->";
	 	if(output[i].source < output[i].dest)
	 	{
	 		cout<<output[i].source<<" "<<output[i].dest<<" "
	 		    <<output[i].weight<<endl;
		}
		else{
			cout<<output[i].dest<<" "<<output[i].source<<" "
	 	    <<output[i].weight<<endl;
		}
	 }
}
int main()
{
	int n,E,i;
	cout<<"Enter the vertices = ";
	cin>>n;
	cout<<"Enter the Edges = ";
	cin>>E;
	Edge *input  =new Edge[E];
	cout<<"Enter the Source and destination then Edge weight "<<endl;
	cout<<setw(17)<<"S"<<setw(3)<<"D"<<setw(3)<<"W"<<endl;
	for(i=0;i<E;i++)
	{
		int s,d,w;
		cout<<"* Enter in  "<<i<<"-> ";
		cin>>s>>d>>w;
		input[i].source = s;
		input[i].dest = d;
		input[i].weight = w;
	}
	kruskals(input,n,E);
	
}

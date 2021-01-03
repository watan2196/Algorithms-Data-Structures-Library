#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int parent[N];
int sz[N];
int a,b,i;
int find(int x)
{
	if(parent[x] < 0)
	return x;
	else
	return parent[x]=find(parent[x]);
}
void merge(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a != b)
	{
		if(sz[a] < sz[b])
		swap(a,b);
	parent[b]=a;
	sz[a]+=sz[b];
	}
}
int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++)
	{
		parent[i]=-1;
		sz[i]=1;
	}
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		if(find(a) != find(b))
		merge(a,b);
	}
	
	for(int i=1;i<=n;i++)
	cout<<sz[i]<<" ";

	return 0;
}





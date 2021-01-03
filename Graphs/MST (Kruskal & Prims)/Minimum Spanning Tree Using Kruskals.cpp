#include <bits/stdc++.h>
using namespace std;
//Minimum spanning Tree
//https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/practice-problems/algorithm/minimum-spanning-tree-5/
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b,u,v,w;
struct edge
{
	int a;
	int b;
	int wt;
};
bool comp(edge e1,edge e2)
{
	if(e1.wt < e2.wt)
	return true;
	
	return false;
}
int parent[N];

int find(int x)
{
	if(parent[x] == -1)
	return x;
	else
	return parent[x]=find(parent[x]);
}
void merge(int a,int b)
{
	parent[a]=b;
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;

	   	cin>>n>>m;
	   	for(int i=1;i<=n;i++)
	   		parent[i]=-1;
	   		
	   	vector<edge> edg(m,{0,0,0});
	   	
	   	//problem input 
	   	for(int i=0;i<m;i++)
		{
			cin>>edg[i].a>>edg[i].b>>edg[i].wt;
		}
		vector<edge>ans;
		sort(edg.begin(),edg.end(),comp);
		
	
		int sum=0;
		for(int i=0;i<m;i++)
		{
			a=find(edg[i].a);
			b=find(edg[i].b);
			if(a != b)
			{
				sum+=edg[i].wt;
				merge(a,b);
			}
		}
		
		cout<<sum<<endl;
		
	return 0;
}


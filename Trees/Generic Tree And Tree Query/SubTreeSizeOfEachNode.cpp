#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
// find the subtree size of each node
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>g[N];
int vis[N];
int subtree[N];

int dfs(int node);

int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	   
	 int sz=dfs(1);
	 subtree[1]=sz;  
	   
	for(int i=1;i<=n;i++)
	cout<<subtree[i]<<" ";
	
	
	return 0;
}
int dfs(int node)
{
	vis[node]=1;
	int cnode_sz=1;
	for(int v:g[node])
	{
		if(!vis[v])
		{
			cnode_sz+=dfs(v);
		}
	}
	subtree[node]=cnode_sz;
	return cnode_sz;
}

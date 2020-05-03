#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
//SSSP Single Source Shortest Path in a tree using DFS
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b,node;

vector<int>g[N];
bool vis[N];
int dis[N];
void dfs(int node,int d);
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;

	   cin>>n>>m;
	   for(i=0;i<m;i++)
	   {
	   	cin>>a>>b;
	   	g[a].push_back(b);
	   	g[b].push_back(a);
	   }

	   cin>>node;
	   
	   dfs(node,0);
	   
	   for(int i=1;i<=n;i++)
	   cout<<dis[i]<<" ";
	   
	return 0;
}
void dfs(int node,int d)
{
	vis[node]=1;
	dis[node]=d;
	for(int v:g[node])
	{
		if(!vis[v])
		{
			dfs(v,dis[node]+1);
		}
	}
}
//Problems:
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
//https://www.spoj.com/problems/PT07Z/

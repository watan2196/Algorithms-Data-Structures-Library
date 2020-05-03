#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
//DFS
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b,node;
vector<int>g[N];
bool vis[N];
void dfs(int node);
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;

	   // no of nodes and edges
	   cin>>n>>m;
	   for(i=0;i<m;i++)
	   {
	   	cin>>a>>b;
	   	g[a].push_back(b); // graph input
	   	g[b].push_back(a);
	   }
	   
	   cin>>node; // start node for dfs
	   dfs(node);
	   
	return 0;
}
void dfs(int node)
{
	vis[node]=1;
	cout<<node<<" ";
	for(int v:g[node])
	{
		if(!vis[v])
		dfs(v);
	}
}
//Problems:
//https://www.spoj.com/problems/PT07Y/
//https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/bishu-and-his-girlfriend/
//https://www.spoj.com/problems/PT07Z/

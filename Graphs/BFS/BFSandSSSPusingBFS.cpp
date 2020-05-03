#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
//BFS to find single source shortest path in an undirected non/equal weighted graph
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b,node;
vector<int>g[N];
int vis[N];
int dis[N];
void bfs(int node);
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
	   
	   bfs(node);
	   
	   for(int i=1;i<=n;i++)
	   cout<<dis[i]<<" ";
	   



	return 0;
}
void bfs(int node)
{
	queue<int>q;
	q.push(node);
	vis[node];
	dis[node]=0;
	
	while(!q.empty())
	{
		int cnode=q.front();
		q.pop();
		for(int v:g[cnode])
		{
			if(!vis[v])
			{
				q.push(v);
				dis[v]=dis[cnode]+1;
				vis[v]=1;
			}
		}
	}
}

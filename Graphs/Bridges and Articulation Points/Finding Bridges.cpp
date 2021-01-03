#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
const int N=1e6+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>g[N];
int vis[N];
int tin[N];
int lowt[N];
int timer;
vector<pair<int,int>>bridges;
void dfs(int node,int par)
{
	vis[node]=1;
	tin[node]=lowt[node]=timer;
	timer++;
	for(int v:g[node])
	{
		if(v == par)continue;
		
		if(vis[v] == 1)
		{
			// back-edge from node->v
			lowt[node]=min(lowt[node],tin[v]);
		}
		else
		{
			dfs(v,node); // make dfs call to unvisited childs
			if(lowt[v] > tin[node])
			{
				bridges.push_back({node,v});
			}
			lowt[node]=min(lowt[node],lowt[v]);
		}
	}
}
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
	   
	   dfs(1,-1);
	   
	   for(auto it:bridges)
	   cout<<it.first<<" "<<it.second<<endl;

	return 0;
}


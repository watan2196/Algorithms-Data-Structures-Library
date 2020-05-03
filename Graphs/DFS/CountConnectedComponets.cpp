#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
//count of connected components
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;

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
	   cin>>n>>m;
	   
	   for(i=0;i<m;i++)
	   {
	   	cin>>a>>b;
	   	g[a].push_back(b);
	   	g[b].push_back(a);
	   }

	   cnt=0;
	   for(int i=1;i<=n;i++)
	   {
	   	if(!vis[i])
	   	{
		   dfs(i);
	   	   cnt++;
	    }
	   }
	   cout<<cnt<<endl;
	   
	return 0;
}
void dfs(int node)
{
	vis[node]=1;
	for(int v:g[node])
	{
		if(!vis[v])
		dfs(v);
	}
}

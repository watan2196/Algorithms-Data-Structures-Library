#include <bits/stdc++.h>
using namespace std;
//count no of cycles in graph
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;

vector<int>g[N];
int vis[N];
int dfs(int node,int par,int cycle);
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
		cnt=0;
		int ans=dfs(1,-1,0);
		
		cout<<cnt<<endl;
		
	return 0;
}
int dfs(int node,int par,int cycle)
{
	vis[node]=1;
	for(int v:g[node])
	{
		if(!vis[v])
		{
			return dfs(v,node,cnt);
		}
		else
		{
			if(v != par)
			{
				cnt++;
				return cnt;
			}
		}
	}
	return cnt;
}

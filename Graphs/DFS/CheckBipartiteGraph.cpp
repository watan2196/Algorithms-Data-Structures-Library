#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
// check bipartiteness of graph using dfs
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;

vector<int>g[N];
bool vis[N];
bool dfs(int node,int c);
bool col[N];
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
	    
		bool flag=true;
	   for(int i=1;i<=n;i++)
	   {
		   	if(!vis[i])
		   	{
		   		if(dfs(i,0) == false)
		   		flag=false;
		   		break;
		    }
		} 
		cout<<flag<<endl;
	return 0;
}
bool dfs(int node,int c)
{
	vis[node]=1;
	col[node]=c;
	for(int v:g[node])
	{
		if(!vis[v])
		{
			if(dfs(v,c^1) == false)
			return false;
		}
		else
		{
			if(col[v] == col[node])
			return false;
		}
	}
	return true;	
}

// problems:
//https://www.spoj.com/problems/BUGLIFE/

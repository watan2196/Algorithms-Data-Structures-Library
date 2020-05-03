#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
// given a graph wiht N nodes and Q queries, with u and v check if 
// one node exist in the subtree of other
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b,timer,q,x,y;
vector<int>g[N];
bool vis[N];
int tin[N],tout[N];
void dfs(int node);

int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
	   cin>>t;
	   while(t--)
	   {
	   	cin>>n>>m;
		   	for(i=0;i<m;i++)
		   	{
		   		cin>>a>>b;
		   		g[a].push_back(b);
		   		g[b].push_back(a);
		    }
		    	
	        timer=1;		    	
	        dfs(1);
				
		    cin>>q;
		   
		   while(q--)
		   {
		   	cin>>x>>y;
		    
			if((tin[x] < tin[y] && tout[x] < tout[y]) || (tin[x] > tin[y] && tout[x] > tout[y]))
			cout<<0<<endl;
			else
			cout<<1<<endl;	
	       } 
	   }



	return 0;
}
void dfs(int node)
{
	vis[node]=1;
	tin[node]=timer++;
	for(int v:g[node])
	{
		if(!vis[v])
		dfs(v);
	}
	tout[node]=timer++;
}

#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
// In / Out time of node in a graph
const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b,timer,s;
vector<int>g[N];
bool vis[N];
void dfs(int s);
int tin[N],tout[N];
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
	   
	   timer=1;
	   cin>>s;
	   dfs(s);
	   
	   //In time
	   for(int i=1;i<=n;i++)
	   cout<<tin[i]<<" ";
	   
	   // Out time
	   cout<<endl;
	   
	   for(int i=1;i<=n;i++)
	   cout<<tout[i]<<" ";
	   
	   
	return 0;
}
void dfs(int s)
{
	vis[s]=1;
	tin[s]=timer++; // increment timer for in time of the node
	for(int v:g[s])
	{
		if(!vis[v])
		dfs(v);
	}
	tout[s]=timer++; // after all the adjancey nodes are visited 
}                    //of the s node then its out time is computed


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;
const int INF=1e7;
int i,j,n,cnt,res,m,t,a,b,wt;
int dist[1000][1000];
vector<pair<int,int> >g[N];
void FloydWarshall();
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
		cin>>n>>m;
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(i == j)
				dist[i][j]=0;
				else
				dist[i][j]=INF;
				
				
		for(int i=0;i<m;i++)
		{
			cin>>a>>b>>wt;
			g[a].push_back({b,wt});
			dist[a][b]=wt;
		}
		
		FloydWarshall();
	   	
	   	for(int i=1;i<=n;i++)
	   		{
			   for(int j=1;j<=n;j++)
	   			{
				   if(dist[i][j] == INF)
	   				cout<<"INF"<<" ";
	   				else
	   				cout<<dist[i][j]<<" ";
	   			}
	   		cout<<endl;
			}

	return 0;
}
void FloydWarshall()
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k] + dist[k][j]);
}

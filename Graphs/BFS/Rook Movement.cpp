#include <bits/stdc++.h>
using namespace std;
//Rook Movement

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;
const int INF=1e9;
int i,j,n,cnt,res,m,t,b;
vector<vector<int> >a;
vector<vector<int> > bfs(int si,int sj)
{
	vector<vector<int> >dis(n,vector<int>(m,INF));
	vector<pair<int,int>>dir{{0,1},{0,-1},{-1,0},{1,0}};
	dis[si-1][sj-1]=0;
	
	queue<pair<int,int> >q;
	q.push({si,sj});
	
	
	while(!q.empty())
	{
			auto x=q.front();
			q.pop();
			for(auto d:dir)
			{
				int r=x.first + d.first;
				int c=x.second + d.second;
				while((r>=0 && r<n) && (c>=0 && c<m) && a[r][c] == 0)
				{
					if(dis[r][c] > dis[x.first][x.second] + 1)
					{
						dis[r][c]=dis[x.first][x.second] + 1;
						q.push({r,c});	
					}	
					r+=d.first;
					c+=d.second;
				}
			}
		}
	}
	
	return dis;
}

int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;

	   cin>>n>>m;
		a.resize(n);
	    for(int i=0;i<n;i++)
		a[i].resize(m);
		
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		cin>>a[i][j];
		
		int si,sj;
		cin>>si>>sj;
		
		vector<vector<int> >ans=bfs(si,sj);
		
		if(ans[di-1][dj-1] == INF)
		cout<<-1<<endl;
		else
		cout<<ans[di-1][dj-1];
		
	return 0;
}


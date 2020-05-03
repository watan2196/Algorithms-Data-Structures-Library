#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE
//2-D bfs or Multiple source bfs

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t;

vector<vector<int>>a;
int bfs(vector<vector<int>> &a);
bool inside(int r,int c,int n,int m);
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
		cin>>n>>m;
		a.resize(n);
		for(i=0;i<m;i++)
		a[i].resize(m);
		
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>a[i][j];
		
		int ans=bfs(a);
		
	   cout<<ans<<endl;

	return 0;
}
int bfs(vector<vector<int>> &a)
{
	int one=0;
	int n=a.size();
	int m=a[0].size();
	
	vector<pair<int,int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
	int vis[n][m];
	memset(vis,0,sizeof vis);
	queue<pair<int,int>>q;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j] == 2)
			{
				vis[i][j]=1;
				q.push({i,j}); //multiple sources for the bfs
			}
			if(a[i][j] == 1)
			one++;
		}
	}
	
	
	int level=0;
	while(!q.empty())
	{
		level+=1;
		int sz=q.size();
		for(int k=0;k<sz;k++)
		{
			pair<int,int>p=q.front();
			q.pop();
			for(auto d:dir)
			{
				int r=p.first + d.first;
				int c=p.second + d.second;
				if(inside(r,c,n,m) && a[r][c] == 1)
				{
					if(!vis[r][c])
					{
						vis[r][c]=1;
						one-=1;
						q.push({r,c});
					}
				}
			}
		}
		if(one  == 0)
		return level;
	}
	
	if(one>0)
	return -1;
	
}
bool inside(int r,int c,int n,int m)
{
	return ((r>=0 && r<n) && (c>=0 && c<m));
}
//Problems://https://www.interviewbit.com/problems/rotten-oranges/
//

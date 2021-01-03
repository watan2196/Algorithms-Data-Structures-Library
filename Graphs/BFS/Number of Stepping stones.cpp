#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;

int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;

	cin>>n>>m;
	vector<int>ans;
	queue<int>q;
	for(int i=1;i<=9;i++)
	q.push(i);
	
	if(n == 0)
	ans.push_back(0);
	
	while(!q.empty())
	{
		auto x=q.front();
		q.pop();
		
		if(x>= n && x<= m)
		ans.push_back(x);
		
		int v,u=x%10;
		x*=10;
		
			if(u != 0)
			{
				v=x+u-1;
				if(v <= m)
				q.push(v);
			}
			if(u != 9)
			{
				v=x + u+1;
				if(v <= m)
				q.push(v);
			}
		}	  
	
	for(auto it:ans)
	cout<<it<<" ";
	
	return 0;
}


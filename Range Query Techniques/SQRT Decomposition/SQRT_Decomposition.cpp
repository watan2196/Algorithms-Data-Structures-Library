#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;
const int INF=1e9;
int i,j,n,cnt,res,m,t,len,q,l,r;
int a[N];

int min_query(int l,int r,vector<int> &b)
{
	
	int len=n/b.size();
	
	int lb=l/len;
	int rb=r/len;
	
	
	
	int mn=INT_MAX;
	
	if(lb == rb)
	{
	for(int i=l;i<=r;i++)
	mn=min(mn,a[i]);
	}
	else
	{
		for(int i=l;i<(lb + 1)*len;i++)
		mn=min(mn,a[i]);
		
		for(int i=lb+1;i<=rb-1;i++)
		mn=min(mn,b[i]);
		
		for(int i=rb*len;i<=r;i++)
		mn=min(mn,a[i]);
	}
	
	return mn;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
		//input data
		cin>>n;
		
		
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		//preprocessing
		int len=(int)sqrt(n + .0); //size of each block and no of blocks
		
		
		vector<int>b((n/len),INF);
		
		for(int i=0;i<n;i++)
		b[i/len]=min(b[i/len],a[i]);
		

		cin>>q;
		//answer Range queries 
		while(q--)
		{
		cin>>l>>r;
		int ans=min_query(l,r,b);	
		cout<<ans<<endl;
		}
		
		
	return 0;
}


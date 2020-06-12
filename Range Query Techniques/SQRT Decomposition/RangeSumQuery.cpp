#include <bits/stdc++.h>
using namespace std;
//Range sum queries uisng 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,q,len,l,r;
int a[N];
int sum_query(int l,int r,vector<int> &b)
{
	int len=n/b.size();
	
	int lb=l/len;
	int rb=r/len;
	
	int sum=0;
	
	if(lb == rb)
	{
		for(int i=l;i<=r;i++)
		sum+=a[i];
	}
	else
	{
		for(int i=l;i<(lb+1)*len;i++)
		sum+=a[i];
		
		for(int i=lb+1;i<=rb-1;i++)
		sum+=b[i];
		
		for(int i=rb*len;i<=r;i++)
		sum+=a[i];
	}
	
	return sum;
}
int32_t main()
{
	#ifndef ONLINE_JUDGE
       freopen("qns.txt","r",stdin);
       freopen("ans.txt","w",stdout);
    #endif
       IOS;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	int len=(int)sqrt(n + .0);
	
	vector<int>b(n/len,0);
	//preprocessing in o(n)
	for(int i=0;i<n;i++)
	b[i/len]+=a[i];
	   
	   cin>>q;
	   while(q--)
	   {
	   	cin>>l>>r;
	   	
	   	int ans=sum_query(l,r,b);
	   	cout<<ans<<endl;
	   }

	return 0;
}


#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define ONLINE_JUDGE

const int N=1e5+5;
const int mod=1e9+7;

int i,j,n,cnt,res,m,t,a,b;
vector<int>g[N];
int In[N];
vector<int>ans;
void Kahn(int n)
{
    ans.clear();
    queue<int>q;
    
    for(int i=1;i<=n;i++)
    {
        if(In[i] == 0)
            q.push(i);
    }
    
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        ans.push_back(node);
        
        for(int v:g[node])
        {
            In[v]--;
            if(In[v] == 0)
               q.push(v); 
        }
    }
    if(ans.size() == n)
        {
        for(auto it:ans)
        cout<<it<<" ";
        }  
        else
        cout<<"IMPOSSIBLE";
}
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
            In[b]++;
        }
	    
        Kahn(n);
        
	return 0;
}


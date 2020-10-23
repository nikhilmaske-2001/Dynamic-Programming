#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mod 1000000007
#define INF 1000000000
#define vi vector<ll>
#define mll map<ll,ll>
#define test() ll t;cin>>t;while(t--)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define rep(a,n) ll a[n];for(i=0;i<n;i++)cin>>a[i];
#define even(s) (s%2==0)
#define odd(s) (s&1)
#define sz(a) (ll)a.size()
using namespace std;
ll i,j;
int dp[1001][1001];

int knapsack(int wt[],int val[],int w,int n)
{
    if(n==0 || w==0)
    {
        return 0;
    }
    if(dp[n][w]!=-1)
    {
        return dp[n][w];
    }
    if(wt[n-1]<=w)
    {
        return dp[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w)
    {
        return dp[n][w]=knapsack(wt,val,w,n-1);
    }
}

int main() {
    fastio;
    test()
    {
        int n,w;
        cin>>n>>w;
        int val[n],wt[n];
        for(i=0;i<n;i++)
        {
            cin>>val[i];
        }
        for(i=0;i<n;i++)
        {
            cin>>wt[i];
        }
        memset(dp,-1,sizeof(dp));
        int ans=knapsack(wt,val,w,n);
        cout<<ans<<endl;
    }
    return 0;
}
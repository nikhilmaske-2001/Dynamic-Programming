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
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(wt[i-1]<=w)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            {
                dp[i][j]=dp[i-1][j];
            }
            
        }
    }
    return dp[n][n];
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
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j]=0;
                }
            }
        }
        int ans=knapsack(wt,val,w,n);
        cout<<ans<<endl;
    }
    return 0;
}
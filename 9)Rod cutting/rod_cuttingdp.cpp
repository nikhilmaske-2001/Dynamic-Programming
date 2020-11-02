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

int main() {
    fastio;
    int n;
    cin>>n;
    int length[n],price[n];
    for(i=0;i<n;i++)
    {
        cin>>length[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>price[i];
    }
    int dp[n+1][n+1];
    //Rod cutting solution
    for(i=0;i<=n;i++)
    {
        dp[i][0]=0;
        dp[0][i]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(length[i-1]<=j)
            {
                dp[i][j]=max(price[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            }
            else if(length[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}
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

int countsubset(int a[],int n,int sum)
{
    for(i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
    for(j=1;j<=sum;j++)
    {
        dp[0][j]=0;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=sum;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-a[i-1]]+dp[i-1][j];
            }
            else if(a[i-1>j])
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int main() {
    fastio;
    int n,sum;
    cin>>n>>sum;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //s1-s2=sum
    //exactly like count the number of subset with guven differnce
    int ans=countsubset(a,n,sum);
    cout<<ans<<endl;
    return 0;
}
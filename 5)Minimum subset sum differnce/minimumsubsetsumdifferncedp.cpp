#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mod 1e9+7
#define INF 1000000000
#define vi vector<int>
#define test() ll t;cin>>t;while(t--)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int i,j;
bool dp[1001][1001];

int main() {
    fastio;
    int n;
    cin>>n;
    int a[n],range=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        range+=a[i];
    }
    //finding all possible subset having sum=0 to range by subset sum problem
    for(i=0;i<=n;i++)
    {
        dp[i][0]=true;
    }
    for(j=1;j<=range;j++)
    {
        dp[0][j]=false;
    }
    //same code as subset sum problem
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=range;j++)
        {
            if(a[i-1]<=j)
            {
                dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
            else if(a[i-1]>j)
            {
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    //In short we have to minimize (range-2*i)
    int diff;
    for(i=range/2;i>=0;i--)
    {
        if(dp[n][i]==true)
        {
            diff=range-2*i;
            break;
        }
    }
    cout<<diff<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mod 1e9+7
#define INF 1000000000
#define vi vector<ll>
#define test() ll t;cin>>t;while(t--)
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
int i,j;

int countofsubset(int a[],int n,int sum)
{
    if(sum==0)
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    if(a[n-1]<=sum)
    {
        return countofsubset(a,n-1,sum-a[n-1]) + countofsubset(a,n-1,sum); 
    }
    else if(a[n-1]>sum)
    {
        return countofsubset(a,n-1,sum);
    }
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
    int ans=countofsubset(a,n,sum);
    cout<<ans<<endl;
    return 0;
}
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

bool equalpartition(int a[],int n,int sum)
{
    if(sum==0)
    {
        return true;
    }
    if(n==0 && sum!=0)
    {
        return false;
    }
    if(a[n-1]<=sum)
    {
        return equalpartition(a,n-1,sum-a[n-1]) || equalpartition(a,n-1,sum);
    }
    else if(a[n-1]>sum)
    {
        return equalpartition(a,n-1,sum);
    }
}

int main() {
    fastio;
    int n;
    cin>>n;
    int a[n],sum=0;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(odd(sum))
    {
        cout<<"NO"<<endl;
    }
    else
    {
        bool flag=equalpartition(a,n,sum/2);
        if(flag)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}
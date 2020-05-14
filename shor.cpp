#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long int
using namespace __gnu_pbds;
using namespace std;
#define mod 1000000007
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define f(i,p,n) for(ll i=p;i<n;i++)
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

ll exp(ll a,ll b,ll m);
ll gcd(ll a, ll b)
{
	if(b==0) return a;

	return gcd(b,a%b);
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n,x;
    cin>>n;
    ll it = 1;

    ll iter_shor = 0;
    srand(time(0));
    while(it%2==1)
    {
    	iter_shor++;
    	x = rand()%n+1;

	    if(gcd(n,x)!=1)
	    {
	    	cout<<"ONe of the factors is "<<gcd(n,x)<<endl;
	    	break;
	    }
	    
	    ll mi = x;
	    it = 1;
	   
	    while(mi!=1 && it<n)
	    {
	    	mi*=x;

	    	mi = mi%n;
	    	it++;

	    }
	    if(it%2==1) continue;
	    cout<<"N = "<<n<<" x = "<<x<<endl;
	    cout<<"r = "<<it<<endl;
	    cout<<gcd(exp(x,it/2,n)-1,n)<<endl;
    }
    cout<<"no of iterations = "<<iter_shor<<endl;
    
    
return 0;
}

ll exp(ll a,ll b,ll m)
{
	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp;
}

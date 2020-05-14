#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll a[200001];
ll co[1000001]={0};
ll ans = 0;
struct node{
	ll l, r, ind;
};

ll root =555;
bool comp(node x, node y) {
	if(x.l/root != y.l/root) {
		return x.l/root < y.l/root;
	}
	return x.r < y.r;
}

void addr(ll pr, ll r)
{
	while(pr<r)
	{
		pr++;
		ans-=co[a[pr]]*co[a[pr]]*a[pr];
		co[a[pr]]++;
		ans+=co[a[pr]]*co[a[pr]]*a[pr];
	}
}
void addl(ll pl, ll l)
{
	while(pl>l)
	{
		pl--;
		ans-=co[a[pl]]*co[a[pl]]*a[pl];
		co[a[pl]]++;
		ans+=co[a[pl]]*co[a[pl]]*a[pl];
	}
}
void remover(ll pr, ll r)
{
	while(pr>r)
	{
		r++;
		ans-=co[a[r]]*co[a[r]]*a[r];
		co[a[r]]--;
		ans+=co[a[r]]*co[a[r]]*a[r];
	}
}
void removel(ll pl, ll l)
{
	while(pl<l)
	{
		l--;
		ans-=co[a[l]]*co[a[l]]*a[l];
		co[a[l]]--;
		ans+=co[a[l]]*co[a[l]]*a[l];
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

	   ll n,q;
	   cin>>n>>q;
	  
	   a[0] = 0;
	   f(1,n+1) cin>>a[i];
	   
	   node qu[q];
	   f(0,q)
	   {
	   	cin>>qu[i].l>>qu[i].r;
	   	qu[i].ind = i;
	   }
	   ll sb[q];
	   sort(qu,qu+q,comp);
	   ll l,r;
	   ll pl=0,pr=0;

	   f(0,q)
	   {
	   	l=qu[i].l;
	   	r=qu[i].r;
	   	addr(pr,r);
	   	addl(pl,l);
	   	removel(pl,l);
	   	remover(pr,r);
	   	sb[qu[i].ind]=ans;
	   	pr = r;
	   	pl = l;
	   }
    	f(0,q) cout<<sb[i]<<endl;
    
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
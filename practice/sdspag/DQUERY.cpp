#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll a[30001];
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
		co[a[pr]]++;
		if(co[a[pr]]==1) ans++;
	}
}
void addl(ll pl, ll l)
{
	while(pl>l)
	{
		pl--;
		co[a[pl]]++;
		if(co[a[pl]]==1) ans++;
	}
}
void remover(ll pr, ll r)
{
	while(pr>r)
	{
		r++;
		co[a[r]]--;
		if(co[a[r]]==0) ans--;
	}
}
void removel(ll pl, ll l)
{
	while(pl<l)
	{
		l--;
		co[a[l]]--;
		if(co[a[l]]==0) ans--;
	}
}
int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

	   ll n;
	   scanf("%d", &n);
	   a[0] = 0;
	   co[0]=mod;
	   f(1,n+1) scanf("%d", &a[i]);
	   ll q;
	   scanf("%d", &q);
	   node qu[q];
	   f(0,q)
	   {
	   	scanf("%d%d", &qu[i].l, &qu[i].r);
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
    	f(0,q) prllf("%d\n", sb[i]);
    
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
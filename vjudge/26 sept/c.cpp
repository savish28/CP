#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define lb lower_bound
#define debug(x) cout<<"["<<#x<<": "<<x<<"]"<<endl
#define f(i,p,n) for(ll i=p;i<n;i++)
ll exp(ll a,ll b,ll m);
ll a[8][8];
ll rs[8]={0};
ll cs[8]={0};
void update()
{
	for(ll c = 1 ; c<=7;c++)
	{
		ll ind = 7;
		for(ll i = 7; i > 1; i--)
		{
			while(a[ind][c]==0 && ind>0) ind--;
			if(a[i][c]==0 &&a[ind][c]>0) rs[i]++;
			if(a[i][c]>0 && a[ind][c]==0) rs[i]--;
			a[i][c] = a[ind][c];
			ind--;
			if(ind<0) ind = 0;
		}
	}
}

void autos()
{
	ll cnew[8];
	f(i,0,8) cnew[i] = cs[i];
	bool savish = 0;
	vector<ll> chagr[8];
	f(r,1,8)
	{
		ll sz = rs[r];
		f(c,1,8)
		{
			if(a[r][c]==sz && sz)
			{
				a[r][c] = 0;
				rs[r]--;
				cs[c]--;
				savish = 1;
			}
		}
	}

	f(c,1,8)
	{
		ll sz = cnew[c];
		f(r,1,8)
		{
			if(a[r][c]==sz && sz)
			{
				a[r][c] = 0;
				rs[r]--;
				cs[c]--;
				savish = 1;
			}
		}
	}
	update();
	if(savish) autos();
}

void colch(ll c, ll r)
{
	ll szc = cs[c];
	ll sz = rs[r];
	bool badlar = 0, badlac  = 0;
	

	f(i,1,8)
	{
		if(a[r][i]==sz && sz)
		{
			badlar = 1;
			a[r][i] = 0;
			rs[r]--;
			cs[i]--;
		}
	}

	f(i,1,8)
	{
		if(a[i][c]==szc && szc)
		{
			badlac = 1;
			a[i][c] = 0;
			cs[c]--;
			rs[i]--;
		}
	}
	update();

    	f(i,1,8)
    	{
    		f(j,1,8)
    		{
    			if(a[i][j]==0) cout<<'#';
    			else cout<<a[i][j];
    		}
    		cout<<endl;
    	}
    	cout<<endl;

	if(badlar || badlac) autos();
}


int main()
{
 ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif

    ll n;
    while(cin>>n)
    {

    	if(n==0) break;
    	memset(a,0,sizeof(a));
    	memset(rs,0,sizeof(a));
    	memset(cs,0,sizeof(a));
    	ll x,y;
    	bool endgame = 0;
    	f(i,0,n)
    	{
    		cin>>x>>y;
    		if(cs[y]==7)
    		{
    			endgame = 1;
    		}
    		else if(endgame==0)
    		{
    			a[7-cs[y]][y]  = x;
    			cs[y]++;

    			autos();
    		}
    	}

    	if(endgame)
    	{
    		cout<<"Game Over!"<<endl<<endl;
    		continue;
    	}

    	f(i,1,8)
    	{
    		f(j,1,8)
    		{
    			if(a[i][j]==0) cout<<'#';
    			else cout<<a[i][j];
    		}
    		cout<<endl;
    	}
    	cout<<endl;
    }
    
    
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
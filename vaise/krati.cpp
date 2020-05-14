#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ff first
#define ss second
#define MAX 10000
#define floop(i, a, b) 	for(int i = a; i <= b; i++)
#define vi vector<int>
#define vll vector<ll>
#define vs vector<string>
#define vvi vector<vector<int> >
#define vvll  vector<vector<ll> >
#define vvs  vector<vector<string> >
#define pb push_back
#define mi map<int, int>
#define mll map<ll, ll>
#define pll  pair<ll, ll>
#define plld pair<ll, double>
#define print1(x) 		cout << x <<" " <<"\n";
#define print2(x, y) 	cout << x << " " << y  << "\n";
#define print3(x, y, z) cout << x << " " << y << " " << z<<"\n";
#define modulo 10^9+7
#define yes cout<<"YES"<<"\n";
#define no cout<<"NO"<<"\n";
#define mem(v,d) memset(d,v,sizeof(d))


int main()
{
	ll t;
	cin>>t;
	for(ll it=1;it<=t;it++)
	{
		ll n,k;
		vector< vector<ll> > hash;
		cin>>n>>k;
		ll arr[n+1];

		floop(j,1,n)
		{
		    cin>>arr[j];
		}
		ll c=0;
		floop(j,1,n)
		{
            if(arr[j]!=j && j!=arr[arr[j]])
            {
                ll index1=j;
                ll index2=arr[j];
                ll index3=arr[arr[j]];

                vector<ll> ult;
                ult.push_back(index1);
                ult.push_back(index2);
                ult.push_back(index3);

                hash.pb(ult);

                ll v1=arr[index1];
                ll v2=arr[index2];
                ll v3=arr[index3];

                arr[index1]=v3;
                arr[index2]=v1;
                arr[index3]=v2;
                if(arr[index1]!=index1) j--;

            }
		}
		vector<pair<ll, ll> > vec;
		floop(j,1,n)
		{
		    if(arr[j]>j)
                {
                    vec.push_back(make_pair(j,arr[j]));
                }
            else if(arr[j]==j)
                continue;
		}

		if(vec.size() %2!=0)
		    cout<<-1<<"\n";
		else 
		{
		    for(int i=0;i<vec.size();i+=2)
		    {

		        ll a=vec[i].ff;
		        ll b=vec[i].ss;
		        ll c=vec[i+1].ff;
		        ll d=vec[i+1].ss;

		        vector <ll> res1;
		        res1.push_back(b);
		        res1.push_back(a);
		        res1.push_back(c);

		        vector <ll> res2;
		        res2.push_back(c);
		        res2.push_back(b);
		        res2.push_back(d);


		        hash.pb(res1);
		        hash.pb(res2);

		        arr[a]=a;
		        arr[b]=b;
		        arr[c]=c;
		        arr[d]=d;

		    }

			
		    if(hash.size()>k)
		        cout<<-1<<"\n";
		    else
		    {
		        cout<<hash.size()<<"\n";

		        for(ll k=0;k<hash.size();k++)
		        {
		            cout<<hash[k][0]<<" "<<hash[k][1]<<" "<<hash[k][2]<<"\n";
		        }
		    }
		}



	}

	return 0;
}
#include<bits/stdc++.h>
#define f(i,a,b) for(long long int i=a;i<b;i++)
#define ll long long int
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define vll vector<ll>  
#define vi vector<int>  
#define pll pair<ll,ll>
#define endl "\n"
#define ff first
#define ss second



using namespace std;
ll exp(ll a,ll b,ll m)
{	if(b==0)
	{
		return 1;
	}
	ll temp =exp(a,b/2,m);
	temp=(temp*temp)%m;
	if(b&1)
	{
		return (temp*(a%m))%m;
	}
	return temp; }



int main()
{
ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
 	#ifndef ONLINE_JUDGE
        freopen("/home/savish/Desktop/2019/io/input.txt", "r", stdin);
        freopen("/home/savish/Desktop/2019/io/output.txt", "w", stdout);
    #endif


ll t;
cin>>t;
while(t--){

	ll n,k;
	cin >> n>>k;
	ll A[n];
	f(i,0,n){
		cin >> A[i];
	}	

f(i,0,k){

A[i%n]=A[i%n]^A[n-(i%n)-1];

}


f(i,0,n){
	cout << A[i]<<" ";
}
cout << endl;







}
}

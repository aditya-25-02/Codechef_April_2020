// Aditya verma 
#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
#define FASTIO ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)
#define rep(i,a,n) for( ll i=a ; i<n ; i++)
#define per(i,a,n) for( ll i=n-1 ; i>=a ;i--)
#define pb push_back
#define TLE cerr<<"Time elapsed : "<<1000*(ld)clock()/(ld)CLOCKS_PER_SEC<<"ms\n"
#define vi vector<int>
#define ll long long int 
#define pii pair <int,int> 
#define db double
#define deb(x) cerr<<#x<<" : "<<x<<"\n";
#define all(x) x.begin(),x.end()
bool compare (ll a, ll b){ return b<a;} // comparator func
ll min(ll a,ll b){ return a<b ? a:b;}
ll max(ll a,ll b){ return b>a ? b:a;}
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
const ll mod=1000000007;
using namespace std;

ll  primefac (ll x) { 
        ll count = 0 ;
        for (ll i = 2; i<= sqrt(x) ; i++) { 
            if (x%i==0) {  
                while (x%i==0) {
                  count++; 
                  x/=i; 
                } 
            } 
        }  
        if (x>1) count++; 
    return count;
}     

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    
    int t; 
    cin>>t;
    while(t--) {
      ll x,k;
      cin>>x>>k;
      ll result = primefac(x);
      if(result >= k)    cout<<"1\n";
      else               cout<<"0\n";
    }
    return 0 ;
}
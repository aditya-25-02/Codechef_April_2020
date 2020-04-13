// Aditya verma 
#include<iostream>
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

int main() {
    FASTIO;
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    
    ll t; 
    cin>>t;
    while(t--) {
          int n , m , k;
          cin>>n>>m>>k;
          ll a[n][k];
          ll ans[n];
          rep(i,0,n) {
              
              ll count[m];
              
              rep(i,0,m)
              count[i]=0;
              
              rep(j,0,k) {
                cin>>a[i][j];
                count[a[i][j]-1]++;
              }
              
              ll max = 0;
              rep(l,0,m) {
                  if(count[l]>max) {
                    max=count[l];
                    ans[i]=l+1;
                  } 
              }
          }  
          
          ll score_in_all[k];
          rep(i,0,k)
          score_in_all[i]=0;
          
          rep(i,0,n) {
              
              rep(j,0,k) {
                if(a[i][j]==ans[i])
                score_in_all[j]++;
              }          
          }
          
          ll min_score = 1000000007;
          ll form_no ;
          rep(i,0,k) {
              if(score_in_all[i]<min_score) {
                 min_score = score_in_all[i] ;
                 form_no=i;
                } 
          }
          
          int changes = 0 ;
          
          rep(i,0,n) {
              
              if(ans[i]!=a[i][form_no]) {
                  ans[i]=a[i][form_no];
                  changes++;
              }
              if(changes>2) break;
          }
          
          rep(i,0,n)
          cout<<ans[i]<<" ";
          
          cout<<"\n";
          
    }
    return 0 ;
}
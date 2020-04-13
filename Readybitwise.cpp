// Aditya verma 
#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
#include<string>
#include<math.h>
#include<stack>
#define FASTIO ios_base::sync_with_stdio(false);std::cin.tie(NULL);std::cout.tie(NULL)
#define rep(i,a,n) for( ll i=a ; i<n ; i++)
#define per(i,a,n) for( ll i=n-1 ; i>=a ; i--)
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
const ll mod=998244353;

using namespace std;
string createpostfix(string s) 
{ 
    stack <char> st; 
    st.push('N');  
    string a; 
    rep(i,0,s.size()) { 
        
        if(s.at(i)=='#') 
        a+=s.at(i); 

        else if(s.at(i)=='(') 
        st.push('('); 

        else if(s.at(i)==')'|| i==s.size()-1) { 
            while(st.top() != 'N' && st.top() != '(') { 
                char c = st.top(); 
                st.pop(); 
                a+= c; 
            } 
            if(st.top() == '(') { 
                st.pop(); 
            } 
        }  
        else { 
            while(st.top() !='N' && st.top()!='(') { 
                char c = st.top(); 
                st.pop(); 
                a+= c; 
            }
            st.push(s.at(i));
        } 
    }    
    while(st.top() != 'N') { 
        char c = st.top(); 
        st.pop(); 
        a+= c; 
    } 
    return a; 
} 
ll pow(ll a , ll n , ll m) {
    ll res = 1;
    while(n) {
      if(n%2)
        res=(res*a)%m;
      n/=2;
      a=(a*a)%m;
    }
    return res;
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
          string exp;
          cin>>exp;
          string res = createpostfix(exp);
          //cerr<<res<<"\n";
          stack <ll> result;

          rep(i,0,res.size()) {
            //deb(res.at(i))
              if(res.at(i)=='#') {
                  rep(i,0,4) {
                      result.push(1);
                  }    
              }
              else {
                  ll x[4],y[4] ;
                  rep(i,0,4) {
                      y[i]=result.top();
                      result.pop();
                  }
                  rep(i,0,4) {
                      x[i]=result.top();
                      result.pop();
                  }
                  ll one ,a,A,zero;
                      if(res.at(i)=='&') {
                        one = (x[1]*y[1])%mod;
                        a   = (x[1]*y[2] + x[2]*y[1] + x[2]*y[2])%mod ;
                        A   = (x[1]*y[3] + x[3]*y[1] + x[3]*y[3])%mod ;
                        zero= (x[0]*(y[3]+y[2]+y[1]+y[0]) + (y[0]*(x[3]+x[2]+x[1]+x[0]))- (x[0]*y[0]) + (x[2]*y[3]) + (x[3]*y[2]) )%mod;
                      }
                      if(res.at(i)=='|') {
                         zero= (x[0]*y[0])%mod;
                         a   = (x[0]*y[2] + x[2]*y[0] + x[2]*y[2])%mod ;
                         A   = (x[0]*y[3] + x[3]*y[0] + x[3]*y[3])%mod ;
                         one = (x[1]*(y[3]+y[2]+y[0]+y[1]) + (y[1]*(x[3]+x[2]+x[0]+x[1]))- (x[1]*y[1]) + (x[2]*y[3]) + (x[3]*y[2]) )%mod;
                     
                      }
                      if(res.at(i)=='^') {  
                        one = (x[0]*y[1] + y[0]*x[1] + x[2]*y[3] + x[3]*y[2])%mod;
                        a   = (x[2]*y[0] + y[2]*x[0] + x[3]*y[1] + y[3]*x[1])%mod;
                        A   = (x[2]*y[1] + y[2]*x[1] + x[3]*y[0] + x[0]*y[3])%mod;
                        zero= (x[1]*y[1] + x[0]*y[0] + x[3]*y[3] + x[2]*y[2])%mod;
                      }
                    result.push(A);
                    result.push(a);
                    result.push(one);
                    result.push(zero);
              }
          }      
          ll f[4];
          ll sum = 0;
          rep(i,0,4) {
              f[i]=result.top();
              sum=(sum+f[i])%mod;
              result.pop();
          }
          ll m = pow(sum,mod-2,mod);
          //cerr<<f[0]<<" ";
          //cerr<<f[1]<<" ";
          //cerr<<f[2]<<" ";
          //cerr<<f[3]<<" "<<"\n";
          cout<<(f[0]*m)%mod<<" "<<(f[1]*m)%mod<<" "<<(f[2]*m)%mod<<" "<<(f[3]*m)%mod<<"\n";
    } 
    return 0 ;
}
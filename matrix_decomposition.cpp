// Aditya verma
#include<bits/stdc++.h>
#define  rep(i,a,n) for( ll i=a ; i<n ; i++)
#define  per(i,a,n) for( ll i=n-1 ; i>=a ;i--)
#define  pb push_back
#define  vi vector<int>
#define  ll long long int
#define  deb(x) cerr<<#x<<" : "<<x<<"\n";
#define  all(x) x.begin(),x.end()
bool     compare (ll a, ll b) { return b < a;} // comparator func
ll       gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
const    ll mod = 1000000007;
using namespace std;

void FASTIO() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
}
ll fastpow(ll base, ll power) {
  ll result = 1;
  while (power > 0) {

    if (power & 1) {
      result = (result * base) % mod;
    }
    base = (base * base) % mod;
    power >>= 1;
  }
  return result % mod;
}
int main() {
  FASTIO();
  ll t;
  cin >> t;
  while (t--) {
    ll n , a;
    cin >> n >> a;

    ll prod = 0;
    ll mul , oper;
    rep(i, 1, n + 1) {

      oper = ((2 * i) - 1); //deb(oper)
      mul = fastpow(a, oper); //deb(mul)
      prod = (prod + mul) % mod;// deb(prod)
      a = (a * mul) % mod;  //deb(a)

    }
    cout << prod << "\n";
  }
  return 0;
}
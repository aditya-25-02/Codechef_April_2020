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
int main() {
  FASTIO();
  int t;
  cin >> t;
  while (t--) {
    ll n, q;
    cin >> n >> q;
    ll init = 0, total = 0;
    rep(i, 0, q) {
      ll f, d;
      cin >> f >> d;
      total += ( abs(f - init) + abs(d - f) );
      init = d;
    }
    cout << total << "\n";
  }
  return 0;
}
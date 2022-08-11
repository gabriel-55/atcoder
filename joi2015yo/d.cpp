#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1LL << 62;
#define rep(i,n) for(ll i = 0; i < (ll)n; i++)
#define REP(i,a,b) for(ll i = a; i < (ll)b; i++)
void chmin(ll &a, ll b) {if(a > b) a = b;}

int main() {
   ll n, m;
   cin >> n >> m;

   vector<ll> d(n), c(m);
   rep(i,n) cin >> d[i];
   rep(i,m) cin >> c[i];

   vector<ll> dp(n+1, inf);
   dp[0] = 0;
   rep(i,m) {
      vector<ll> p(n+1, inf);
      swap(dp, p);

      rep(j,n+1) {
         chmin(dp[j], p[j]);
         if(j != 0) chmin(dp[j], p[j-1]+d[j-1]*c[i]);
      }
   }

   cout << dp[n] << '\n';
   return 0;
}
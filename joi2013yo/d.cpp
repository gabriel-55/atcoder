#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define REP(i,a,b) for(ll i = a; i < (ll)b; i++)
#define rep(i,n) REP(i,0,n)
void chmax(ll &a, ll b) {if(a < b) a = b;}

int main() {
   ll d, n;
   cin >> d >> n;

   vector<ll> t(d), a(n), b(n), c(n);
   rep(i,d) cin >> t[i];
   rep(i,n) cin >> a[i] >> b[i] >> c[i];

   vector<ll> dp(101, -1);
   rep(i,n) {
      if(a[i] <= t[0] && t[0] <= b[i]) dp[c[i]] = 0;
   }

   REP(i,1,d) {
      vector<ll> p(101, -1);
      swap(dp, p);

      rep(j,101) {
         if(p[j] == -1) continue;
         rep(k,n) {
            if(a[k] <= t[i] && t[i] <= b[k]) chmax(dp[c[k]], p[j]+abs(c[k]-j));
         }
      }
   }

   ll ans = 0;
   rep(i,101) chmax(ans, dp[i]);
   cout << ans << '\n';
}
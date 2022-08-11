#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll inf = 1LL << 60;
#define REP(i,a,b) for(ll i = a; i < (ll)b; i++)
#define rep(i,n) REP(i,0,n)
void chmin(ll &a, ll b) {if(a > b) a = b;}

int main() {
   ll n, l;
   cin >> n >> l;
   l = (l+1)*2-1;
   vector<ll> h(l+1, false);
   rep(i,n) {
      ll x;
      cin >> x;
      h[x*2] = true;
   }
   ll t1, t2, t3;
   cin >> t1 >> t2 >> t3;

   vector<ll> dp(l, inf);
   dp[0] = 0;
   rep(i,l-1) {
      if(dp[i] == inf) continue;
      if(i+2 <= l-1) chmin(dp[i+2], dp[i]+t1+t3*(h[i+1]+h[i+2]));
      if(i+4 <= l-1) chmin(dp[i+4], dp[i]+t1+t2+t3*(h[i+1]+h[i+4]));
      else chmin(dp[l-1], dp[i]+t1/2+t2/2*(l-i-2)+t3*h[i+1]);
      if(i+8 <= l-1) chmin(dp[i+8], dp[i]+t1+t2*3+t3*(h[i+1]+h[i+8]));
      else chmin(dp[l-1], dp[i]+t1/2+t2/2*(l-i-2)+t3*h[i+1]);
   }

   cout << dp[l-1] << '\n';
   return 0;
}
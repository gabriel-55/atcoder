#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, s;
   cin >> n >> s;
   vector<ll> a(n), b(n);
   rep(i,n) cin >> a[i] >> b[i];

   vector dp(n+1, vector<pair<int, int>>(s+1, {0, 0}));
   dp[0][0] = {1, 0};
   rep(i,n) rep(j,s+1) {
      if(dp[i][j].fi == 0) continue;
      if(j+a[i] <= s) dp[i+1][j+a[i]] = {1, 1};
      if(j+b[i] <= s) dp[i+1][j+b[i]] = {1, 0};
   }

   if(dp[n][s].fi == 0) {
      cout << "No" << '\n';
      return 0;
   }

   ll j = s;
   string ans;
   for(ll i = n; i > 0; i--) {
      if(dp[i][j].se) {
         ans += 'H';
         j -= a[i-1];
      } else {
         ans += 'T';
         j -= b[i-1];
      }
      debug(i, j);
   }

   debug(dp);
   reverse(ans.begin(), ans.end());
   cout << "Yes" << '\n';
   cout << ans << '\n';
}

/*---------------------------------------------------------------------------------------------------
　　 　　 ○＿＿＿＿＿_
　  　 　 ||　 　 　 |
　 　  　 ||　  ● 　 |
　 　  　 ||　 　 　 |
 　   　  ||￣￣￣￣￣
　　   　 ||  君が代は
   ∧__,,∧||　 千代に八千代に
　 ( ｀･ω･||    さざれ石の巌となりて
　  ヽ  つ０     こけのむすまで
　　 し―-J
---------------------------------------------------------------------------------------------------*/

#else
#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
using ldb = long double;
using P = pair<ll, ll>;
#define fi first
#define se second
#define REP(i,a,b) for (ll i = a, i##_range = (b); i < i##_range; i++)
#define rep(i,a) REP(i,0,a)
template <class T> bool chmin(T& a, const T& b) { return a > b ? a = b, true : false; }
template <class T> bool chmax(T& a, const T& b) { return a < b ? a = b, true : false; }
#ifdef _DEBUG
#include <debug.hpp>
#define debug(...) debug::dprint(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif
struct initialise { initialise() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }__INI__;
const ll inf = 1LL << 60;
const ll dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
#endif
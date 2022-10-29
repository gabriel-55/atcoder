#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll r, c, a;
   cin >> r >> c >> a;
   vector v(r, vector<ll>(c, 0));
   rep(i,a) {
      ll m, p, q;
      cin >> m >> p >> q;
      m--; p--;
      v[m][p] = q;
   }
   
   ll ans = 0;
   vector dp(r, vector<vector<ll>>(c, vector<ll>(3, 0)));
   for(ll i = r-1; i >= 0; i--) {
      for(ll j = c-1; j >= 0; j--) {
         rep(k,3) {
            if(i-1 >= 0) chmax(dp[i-1][j][0], dp[i][j][k]+v[i][j]);
            if(j-1 >= 0) {
               chmax(dp[i][j-1][k], dp[i][j][k]);
               if(k+1 <= 2) chmax(dp[i][j-1][k+1], dp[i][j][k]+v[i][j]);
            }
            chmax(ans, dp[i][j][k]+v[i][j]);
         }
      }
   }
   
   cout << ans << '\n';
   return 0;
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
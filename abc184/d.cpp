#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll a, b, c;
   cin >> a >> b >> c;

   vector dp(101, vector(101, vector<ldb>(101, 0)));
   for(ll i = 99; i >= 0; i--) {
      for(ll j = 99; j >= 0; j--) {
         for(ll k = 99; k >= 0; k--) {
            dp[i][j][k] += dp[i+1][j][k]*i/(i+j+k);
            dp[i][j][k] += dp[i][j+1][k]*j/(i+j+k);
            dp[i][j][k] += dp[i][j][k+1]*k/(i+j+k);
            dp[i][j][k] += 1;
         }
      }
   }

   cout << dp[a][b][c] << '\n';
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
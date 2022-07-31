#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll h, w;
   cin >> h >> w;
   vector v(h, vector<ll>(w));
   rep(i,h) rep(j,w) {
      char c;
      cin >> c;
      if(c == '+') v[i][j] = 1;
      else v[i][j] = -1;
   }

   vector dp(h, vector<ll>(w, -inf));
   dp[h-1][w-1] = 0;
   for(ll i = h-1; i >= 0; i--) for(ll j = w-1; j >= 0; j--) {
      if(i+1 < h) dp[i][j] = max(dp[i][j], -1*(dp[i+1][j]-v[i+1][j]));
      if(j+1 < w) dp[i][j] = max(dp[i][j], -1*(dp[i][j+1]-v[i][j+1]));
   }

   if(dp[0][0] == 0) cout << "Draw" << '\n';
   else if(dp[0][0] > 0) cout << "Takahashi" << '\n';
   else cout << "Aoki" << '\n';
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
#if !__INCLUDE_LEVEL__
#include __FILE__

using mint = modint998244353;

int main(void){
   ll n, m, k;
   cin >> n >> m >> k;
   vector g(n, vector<ll>());
   rep(i,m) {
      ll u, v;
      cin >> u >> v;
      u--; v--;
      g[u].emplace_back(v);
      g[v].emplace_back(u);
   }
   vector<mint> dp(n);
   dp[0] = 1;
   rep(x,k) {
      mint sum = 0;
      rep(i,n) sum += dp[i];
      vector<mint> p(n);
      swap(dp, p);
      rep(i,n) {
         dp[i] = sum-p[i];
         for(auto &nx : g[i]) dp[i] -= p[nx];
      }
   }
   cout << dp[0].val() << '\n';
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
#define m_99(i,a,b) for (ll i = a, i##_range = (b); i < i##_range; i++)
#define rep(i,a) m_99(i,0,a)
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
#if !__INCLUDE_LEVEL__
#include __FILE__

struct Edge{
   ll to;
   ll cost;
   ll time;
};

int main(void){
   ll n, m;
   cin >> n >> m;
   vector g(n, vector<Edge>());
   rep(i,m) {
      ll a, b, d, t;
      cin >> a >> b >> d >> t;
      a--; b--;
      Edge e;
      e.cost = d;
      e.time = t;
      e.to = b;
      g[a].emplace_back(e);
      e.to = a;
      g[b].emplace_back(e);
   }

   vector dp(1<<n, vector<P>(n, {inf, 0}));
   dp[0][0] = {0, 1};

   rep(bit,1<<n) rep(i,n) {
      if(bit != 0 && ~bit>>i&1) continue;
      for(auto &e : g[i]) {
         if(bit>>e.to&1) continue;
         if(dp[bit][i].fi + e.cost > e.time) continue;
         if(dp[bit|1<<e.to][e.to].fi < dp[bit][i].fi + e.cost) continue;
         if(chmin(dp[bit|1<<e.to][e.to].fi, dp[bit][i].fi + e.cost)) {
            dp[bit|1<<e.to][e.to].se = dp[bit][i].se;
         }
         else dp[bit|1<<e.to][e.to].se += dp[bit][i].se;
      }
   }

   dp[(1<<n)-1][0].fi == inf ? puts("IMPOSSIBLE") : printf("%lld %lld\n", dp[(1<<n)-1][0].fi, dp[(1<<n)-1][0].se);
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
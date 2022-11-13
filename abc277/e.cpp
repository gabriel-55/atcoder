#if !__INCLUDE_LEVEL__
#include __FILE__

struct Edge{
   ll to;
   ll pa;
};

int main(void){
   ll n, m, K;
   cin >> n >> m >> K;
   vector g(n, vector<Edge>());
   rep(i,m) {
      ll u, v, a;
      cin >> u >> v >> a;
      u--; v--;
      Edge e;
      e.to = v;
      e.pa = a;
      g[u].emplace_back(e);
      e.to = u;
      g[v].emplace_back(e);
   }

   vector<ll> s(n, 0);
   rep(i,K) {
      ll a;
      cin >> a;
      s[a-1] = 1;
   }

   vector dist(n, vector<ll>(2, inf));
   dist[0][0] = 0;
   deque<pair<ll, ll>> que;
   que.emplace_front(0, 0);

   while(!que.empty()){
      ll x = que.front().fi, y = que.front().se;
      que.pop_front();
      for(auto &k : g[x]){
         Edge e = k;
         if(y) e.pa ^= 1;
         if(s[x]) {
            if(dist[x][y^1] > dist[x][y]) {
               dist[x][y^1] = dist[x][y];
               que.emplace_front(x, y^1);
            }
         }
         if(!e.pa) continue;
         if(dist[e.to][y] <= dist[x][y]+1) continue;
         dist[e.to][y] = dist[x][y] + 1;
         que.emplace_back(e.to, y);
      }
   }

   if(dist[n-1][0] == inf && dist[n-1][1] == inf) cout << -1 << '\n';
   else cout << min(dist[n-1][0], dist[n-1][1]) << '\n';
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
#if !__INCLUDE_LEVEL__
#include __FILE__

struct Edge {
   ll to;
   ll cost;
};

int main(void){
   ll n, q;
   cin >> n >> q;
   vector g(n, vector<Edge>());

   while(q--) {
      ll ni, a, b;
      cin >> ni >> a >> b;
      a--; b--;
      if(ni == 1) {
         ll c;
         cin >> c;
         Edge e;
         e.to = b, e.cost = c;
         g[a].emplace_back(e);
         e.to = a;
         g[b].emplace_back(e);
         continue;
      }

      vector<ll> dist(n, inf);
      dist[a] = 0;
      priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
      pq.emplace(0, a);
      while(pq.size()) {
         ll c = pq.top().fi, v = pq.top().se;
         pq.pop();
         if(dist[v] < c) continue;
         for(auto &e : g[v]) {
            if(dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            pq.emplace(dist[e.to], e.to);
         }
      }
      if(dist[b] == inf) cout << -1 << '\n';
      else cout << dist[b] << '\n';
   }

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
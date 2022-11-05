#if !__INCLUDE_LEVEL__
#include __FILE__

struct Edge {
   ll to;
   ll cost;
};

int main(void){
   ll n, m, k, s;
   cin >> n >> m >> k >> s;
   ll p, q;
   cin >> p >> q;
   vector<ll> d(n, inf);
   queue<ll> que;
   rep(i,k) {
      ll c;
      cin >> c;
      que.push(--c);
      d[c] = 0;
   }

   vector g(n, vector<Edge>());
   rep(i,m) {
      ll a, b;
      cin >> a >> b;
      a--; b--;
      Edge e;
      e.to = b, e.cost = p;
      g[a].emplace_back(e);
      e.to = a;
      g[b].emplace_back(e);
   }

   while(que.size()) {
      ll v = que.front();
      que.pop();
      for(auto &e : g[v]) {
         if(d[e.to] <= d[v]+1) continue;
         if(d[v]+1 > s) continue;
         d[e.to] = d[v] + 1;
         que.push(e.to);
      }
   }

   rep(i,n) {
      for(auto &e : g[i]) {
         if(d[e.to] == inf) continue;
         e.cost = q;
      }
   }

   vector<ll> dist(n, inf);
   dist[0] = 0;
   priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
   pq.emplace(0, 0);
   while(pq.size()) {
      ll v = pq.top().se, x = pq.top().fi;
      pq.pop();
      if(dist[v] < x) continue;
      for(auto &e : g[v]) {
         if(d[e.to] == 0) continue;
         if(dist[e.to] <= dist[v] + e.cost) continue;
         dist[e.to] = dist[v] + e.cost;
         pq.emplace(dist[e.to], e.to);
      }
   }

   if(d[n-1] == inf) cout << dist[n-1]-p << '\n';
   else cout << dist[n-1]-q << '\n';
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
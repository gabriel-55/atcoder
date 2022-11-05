#if !__INCLUDE_LEVEL__
#include __FILE__

struct Edge {
   ll to;
   ll cost;
};

int main(void){
   ll n, k;
   cin >> n >> k;
   vector<ll> c(n), r(n);
   rep(i,n) cin >> c[i] >> r[i];
   vector g(n, vector<Edge>());
   vector g2(n, vector<ll>());
   rep(i,k) {
      ll a, b;
      cin >> a >> b;
      a--; b--;
      g2[a].emplace_back(b);
      g2[b].emplace_back(a);
   }

   rep(i,n) {
      vector<ll> dist(n, inf);
      dist[i] = 0;
      queue<ll> que;
      que.push(i);

      while(que.size()) {
         ll v = que.front();
         que.pop();
         if(dist[v]+1 > r[i]) continue;
         for(auto &nv : g2[v]) {
            if(dist[nv] <= dist[v]+1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
         }
      }

      rep(j,n) {
         if(dist[j] == inf || dist[j] == 0) continue;
         Edge e;
         e.to = j, e.cost = c[i];
         g[i].emplace_back(e);
      }
   }

   vector<ll> dist(n, inf);
   priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
   dist[0] = 0;
   pq.emplace(0, 0);
   while(pq.size()) {
      ll v = pq.top().se, x = pq.top().fi;
      pq.pop();
      if(dist[v] < x) continue;
      for(auto &e : g[v]) {
         if(dist[e.to] <= dist[v] + e.cost) continue;
         dist[e.to] = dist[v] + e.cost;
         pq.emplace(dist[e.to], e.to);
      }
   }

   cout << dist[n-1] << '\n';
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
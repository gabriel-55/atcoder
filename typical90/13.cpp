#if !__INCLUDE_LEVEL__
#include __FILE__

struct Edge {
   ll to;
   ll cost;
};

int main(void){
   ll n, m;
   cin >> n >> m;
   vector<ll> dist1(n, inf), dist2(n, inf);
   dist1[0] = 0, dist2[n-1] = 0;
   vector<vector<Edge>> g(n);
   rep(i,m) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      Edge e;
      e.to = b;
      e.cost = c;
      g[a].emplace_back(e);
      e.to = a;
      g[b].emplace_back(e);
   }
   priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;
   pq.emplace(0, 0);
   while(pq.size()) {
      ll v = pq.top().second, x = pq.top().first;
      pq.pop();
      if(dist1[v] < x) continue;
      for(auto &e : g[v]) {
         if(dist1[e.to] <= dist1[v] + e.cost) continue;
         dist1[e.to] = dist1[v] + e.cost;
         pq.emplace(dist1[e.to], e.to);
      }
   }
   pq.emplace(0, n-1);
   while(pq.size()) {
      ll v = pq.top().se, x = pq.top().fi;
      pq.pop();
      if(dist2[v] < x) continue;
      for(auto &e : g[v]) {
         if(dist2[e.to] <= dist2[v] + e.cost) continue;
         dist2[e.to] = dist2[v] + e.cost;
         pq.emplace(dist2[e.to], e.to);
      }
   }

   rep(i,n) cout << dist1[i] + dist2[i] << '\n';
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
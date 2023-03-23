#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   vector v(n, vector<P>());
   rep(i,m) {
      ll a, b, c;
      cin >> a >> b >> c;
      a--; b--;
      v[a].emplace_back(b, c);
   }
   rep(i,n){
      vector<ll> dist(n, inf);
      priority_queue<P, vector<P>, greater<>> pq;
      for(auto &[nv, cost] : v[i]) {
         if(dist[nv] <= cost) continue;
         dist[nv] = cost;
         pq.emplace(cost, nv);
      }
      while(!pq.empty()) {
         auto [now, x] = pq.top();
         pq.pop();
         if(dist[x] < now) continue;
         for(auto &[nx, cost] : v[x]) {
            if(dist[nx] <= dist[x]+cost) continue;
            dist[nx] = dist[x] + cost;
            pq.emplace(dist[nx], nx); 
         }
      }
      if(dist[i] == inf) cout << -1 << '\n';
      else cout << dist[i] << '\n';
   }
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
// #include <atcoder/all>
// using namespace atcoder;
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
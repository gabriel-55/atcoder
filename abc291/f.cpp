#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   vector v(n, vector<ll>());
   vector u(n, vector<ll>());
   rep(i,n){
      string s;
      cin >> s;
      rep(j,m) {
         if(s[j] == '1') v[i+j+1].emplace_back(i);
         if(s[j] == '1') u[i].emplace_back(i+j+1);
      }
   }
   queue<ll> que;
   que.push(n-1);
   vector<ll> dist(n, inf);
   dist[n-1] = 0;
   while(!que.empty()){
      ll x = que.front();
      que.pop();
      for(auto &nx : v[x]){
         if(dist[nx] <= dist[x]+1) continue;
         dist[nx] = dist[x]+1;
         que.push(nx);
      }
   }
   que.push(0);
   vector<ll> dist2(n, inf);
   dist2[0] = 0;
   while(!que.empty()){
      ll x = que.front();
      que.pop();
      for(auto &nx : u[x]){
         if(dist2[nx] <= dist2[x]+1) continue;
         dist2[nx] = dist2[x]+1;
         que.push(nx);
      }
   }
   m_99(k,1,n-1) {
      ll ans = inf;
      for(ll j = max(k-m, 0ll); j < k; j++) {
         for(auto &nx : u[j]) {
            if(nx <= k) continue;
            chmin(ans, dist2[j]+dist[nx]+1);
         }
      }
      if(ans == inf) ans = -1;
      cout << ans << '\n';
   }
   debug(dist, dist2);
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
#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m, k;
   cin >> n >> m >> k;
   vector<ll> a(m);
   rep(i,m) cin >> a[i], a[i]--;
   vector g(n, vector<P>());
   rep(i,n-1) {
      ll u, v;
      cin >> u >> v;
      u--; v--;
      g[u].emplace_back(v, i);
      g[v].emplace_back(u, i);
   }
   vector<ll> cnt(n-1, 0);
   rep(i,m-1){
      vector<ll> dist(n, inf);
      dist[a[i]] = 0;
      queue<ll> que;
      que.push(a[i]);
      while(!que.empty()){
         ll x = que.front();
         que.pop();
         for(auto &e : g[x]) {
            ll nx = e.fi;
            if(dist[nx] <= dist[x] + 1) continue;
            dist[nx] = dist[x]+1;
            que.push(nx);
         }
      }

      que.push(a[i+1]);
      while(!que.empty()){
         ll x = que.front();
         que.pop();
         for(auto &e : g[x]) {
            ll nx = e.fi;
            if(dist[nx] != dist[x]-1) continue;
            cnt[e.se]++;
            que.push(nx);
         }
      }
   }

   map<ll, ll> dp;
   dp[0] = 1;
   ll sum = 0;
   rep(i,n-1) {
      sum += cnt[i];
      map<ll, ll> p;
      swap(dp, p);
      for(auto &np : p) {
         dp[np.fi+cnt[i]] += np.se;
         dp[np.fi] += np.se;
         dp[np.fi+cnt[i]] %= 998244353;
         dp[np.fi] %= 998244353;
      }
   }
   if((sum+k)%2 || sum+k < 0) {
      cout << 0 << '\n';
      return 0;
   }
   cout << dp[(sum+k)/2] << '\n';
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
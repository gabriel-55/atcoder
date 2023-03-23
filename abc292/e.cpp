#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   vector v(n, vector<ll>(n, 0));
   vector g(n, vector<ll>());
   rep(i,m){
      ll a, b;
      cin >> a >> b;
      a--; b--;
      g[a].emplace_back(b);
      v[a][b] = 1;
   }
   ll ans = 0;
   queue<P> que;
   rep(i,n) que.emplace(i, i), v[i][i] = 1;
   vector seen(n, vector<ll>(n, 0));

   while(!que.empty()){
      auto [x, ori] = que.front();
      que.pop();
      for(auto &nx : g[x]) {
         if(seen[ori][nx]) continue;
         seen[ori][nx] = 1;
         que.emplace(nx, ori);
         if(!v[ori][nx]) ans++;
         v[ori][nx] = 1;
      }
   }

   cout << ans << '\n';
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
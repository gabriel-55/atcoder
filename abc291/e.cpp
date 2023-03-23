#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   vector v(n, vector<ll>());
   vector<ll> deg(n, 0);
   rep(i,m) {
      ll a, b;
      cin >> a >> b;
      a--; b--;
      v[a].emplace_back(b);
      deg[b]++;
   }
   vector<ll> c;
   rep(i,n) {
      if(!deg[i]) c.emplace_back(i);
   }
   if(c.size() != 1) {
      cout << "No\n";
      return 0;
   }
   vector<P> dist(n, {inf, -1});
   queue<ll> que;
   que.push(c[0]);
   vector<ll> now;
   while(!que.empty()) {
      ll x = que.front();
      que.pop();
      for(auto &nx : v[x]) {
         deg[nx]--;
         if(!deg[nx]) que.push(nx);
      }
      now.emplace_back(x);
   }
   // debug(deg, now, now.size(), n);
   if(now.size() != n) {
      cout << "No\n";
      return 0;
   }
   bool ok = true;
   rep(i,n-1) {
      bool ok2 = false;
      for(auto &nx : v[now[i]]) {
         if(nx != now[i+1]) continue;
         ok2 = true;
         break;
      }
      if(!ok2) ok = false;
   }
   if(ok) {
      vector<ll> ans(n, 0);
      cout << "Yes\n";
      rep(i,n) ans[now[i]] = i+1; 
      rep(i,n) cout << ans[i] << ' ';
      cout << '\n';
   } else cout << "No\n";
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
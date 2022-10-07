#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;
   vector v(n, vector<ll>());

   rep(i,m) {
      ll a, b;
      cin >> a >> b;
      a--; b--;
      v[a].emplace_back(b);
      v[b].emplace_back(a);
   }

   vector<int> dist(n, -1);

   ll q;
   cin >> q;
   while(q--) {
      ll x, k;
      cin >> x >> k;
      x--;

      ll ans = x+1;
      queue<ll> que;
      que.push(x);
      dist[x] = 0;

      while(que.size()) {
         ll a = que.front();
         que.pop();

         for(auto na : v[a]) {
            if(dist[na] != -1) continue;
            dist[na] = dist[a]+1;
            if(dist[na] <= k) ans += na+1;
            if(dist[na] < k) que.push(na);
         }
      }

      cout << ans << '\n';

      que.push(x);
      dist[x] = -1;
      while(que.size()) {
         ll a = que.front();
         que.pop();

         for(auto na : v[a]) {
            if(dist[na] == -1) continue;
            dist[na] = -1;
            que.push(na);
         }
      }
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
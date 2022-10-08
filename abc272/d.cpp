#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;

   vector c(n, vector<ll>(n, inf));
   vector<pair<ll, ll>> dist;
   
   for(ll k = -n-1; k <= n+1; k++) {
      for(ll l = -n-1; l <= n+1; l++) {
         ll d = k*k+l*l;
         if(d == m) dist.emplace_back(k, l);
      }
   }

   queue<pair<ll, ll>> que;
   c[0][0] = 0;
   que.push({0, 0});
   
   while(!que.empty()) {
      ll i = que.front().fi, j = que.front().se;
      que.pop();
      for(auto [k, l] : dist) {
         if(i+k >= n || j+l >= n || i+k < 0 || j+l < 0) continue;
         if(c[i][j]+1 >= c[i+k][j+l]) continue;
         c[i+k][j+l] = c[i][j]+1;
         que.push({i+k, j+l});
      }
   }

   rep(i,n) {
       rep(j,n) {
         if(c[i][j] == inf) c[i][j] = -1;
         cout << c[i][j] << ' ';
       }
       cout << '\n'; 
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
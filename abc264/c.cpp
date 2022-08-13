#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll h, w;
   cin >> h >> w;
   vector a(h, vector<ll>(w));
   rep(i,h) rep(j,w) cin >> a[i][j];
   ll x, y;
   cin >> x >> y;
   vector b(x, vector<ll>(y));
   rep(i,x) rep(j,y) cin >> b[i][j];

   for(ll bit = 0; bit < (1 << h); bit++) {
      vector<ll> v;
      for(ll i = 0; i < h; i++) {
         if((bit & (1 << i)) == 0) v.emplace_back(i);
      }

      if(v.size() != x) continue;
      ll cnt = 0;
      rep(j,w) {
         if(a[v[0]][j] != b[0][cnt]) continue;
         bool ok = true;
         rep(i,x) {
            if(a[v[i]][j] != b[i][cnt]) ok = false;
         }
         if(ok) {
            cnt++;
            if(cnt == y) {
               cout << "Yes" << '\n';
               return 0;
            } 
         }
      }
   }

   cout << "No" << '\n';
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
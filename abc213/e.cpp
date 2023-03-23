#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll h, w;
   cin >> h >> w;
   vector v(h, vector<ll>(w, 0));
   rep(i,h) rep(j,w) {
      char c;
      cin >> c;
      if(c == '#') v[i][j] = 1;
   }
   vector cnt(h, vector<ll>(w, inf));
   cnt[0][0] = 0;
   deque<P> dq;
   dq.emplace_back(0, 0);
   while(!dq.empty()) {
      auto [x, y] = dq.front();
      dq.pop_front();
      rep(k,4) {
         ll nx = x+dx[k], ny = y+dy[k];
         if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
         if(v[nx][ny]) continue;
         if(cnt[nx][ny] <= cnt[x][y]) continue;
         cnt[nx][ny] = cnt[x][y];
         dq.emplace_front(nx, ny);
      }

      m_99(i,-2,3) m_99(j,-2,3) {
         if((i && j) && (i%2 == 0 && j%2 == 0)) continue;
         ll nx = x+i, ny = y+j;
         if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
         if(cnt[nx][ny] <= cnt[x][y]+1) continue;
         cnt[nx][ny] = cnt[x][y]+1;
         dq.emplace_back(nx, ny);
      }
   }
   cout << cnt[h-1][w-1] << '\n';
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
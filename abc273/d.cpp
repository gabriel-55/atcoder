#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll h, w, sx, sy, n;
   cin >> h >> w >> sx >> sy >> n;
   vector<P> r(n);
   rep(i,n) cin >> r[i].fi >> r[i].se;
   sort(r.begin(), r.end());
   map<ll, ll> mpx, mpy;
   ll nowx = 1, nowy = 1;
   vector<vector<ll>> x(n), y(n);
   rep(i,n) {
      if(mpx[r[i].fi] == 0) {
         mpx[r[i].fi] = nowx;
         nowx++;
      }
      if(mpy[r[i].se] == 0) {
         mpy[r[i].se] = nowy;
         nowy++;
      }
      x[mpx[r[i].fi]-1].emplace_back(r[i].se);
      y[mpy[r[i].se]-1].emplace_back(r[i].fi);
   }

   ll q;
   cin >> q;
   while(q--) {
      char d;
      ll l;
      cin >> d >> l;
      if(d == 'L') {
         if(mpx[sx] == 0) {
            sy = max(1ll, sy-l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }

         auto it = lower_bound(x[mpx[sx]-1].begin(), x[mpx[sx]-1].end(), sy);
         if(it == x[mpx[sx]-1].begin()) {
            sy = max(1ll, sy-l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }
         it--;
         sy = max({1ll, sy-l, *it+1});
      }
      if(d == 'R') {
         if(mpx[sx] == 0) {
            sy = min(w, sy+l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }

         auto it = upper_bound(x[mpx[sx]-1].begin(), x[mpx[sx]-1].end(), sy);
         if(it == x[mpx[sx]-1].end()) {
            sy = min(w, sy+l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }
         sy = min({w, sy+l, *it-1});
      }
      if(d == 'U') {
         if(mpy[sy] == 0) {
            sx = max(1ll, sx-l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }

         auto it = lower_bound(y[mpy[sy]-1].begin(), y[mpy[sy]-1].end(), sx);
         if(it == y[mpy[sy]-1].begin()) {
            sx = max(1ll, sx-l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }
         it--;
         sx = max({1ll, sx-l, *it+1});
      }
      if(d == 'D') {
         if(mpy[sy] == 0) {
            sx = min(h, sx+l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }

         auto it = upper_bound(y[mpy[sy]-1].begin(), y[mpy[sy]-1].end(), sx);
         if(it == y[mpy[sy]-1].end()){
            sx = min(h, sx+l);
            cout << sx << ' ' << sy << '\n';
            continue;
         }
         sx = min({h, sx+l, *it-1});
      }
      cout << sx << ' ' << sy << '\n';
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
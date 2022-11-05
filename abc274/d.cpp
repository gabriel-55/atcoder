#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, x, y;
   cin >> n >> x >> y;

   vector<ll> a(n);
   rep(i,n) cin >> a[i];
   set<ll> dpx, dpy;
   dpx.insert(a[0]), dpy.insert(0);

   REP(i,1,n) {
      set<ll> ndp;
      if(i%2 != 0) {
         swap(ndp, dpy);
         for(auto &ny : ndp) {
            dpy.insert(ny+a[i]);
            dpy.insert(ny-a[i]);
         } 
      } else {
         swap(ndp, dpx);
         for(auto &nx : ndp) {
            dpx.insert(nx+a[i]);
            dpx.insert(nx-a[i]);
         }
      }
   }

   if(dpx.count(x) && dpy.count(y)) cout << "Yes" << '\n';
   else cout << "No" << '\n';
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
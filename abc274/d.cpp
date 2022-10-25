#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, x, y;
   cin >> n >> x >> y;
   vector<ll> a(n);
   rep(i,n) cin >> a[i];
   ll b = 2;

   map<ll, bool> nx, ny;
   nx[a[0]] = 1;
   ny[0] = 1;
   REP(i,1,n) {
      map<ll, bool> nnx, nny;
      swap(nx, nnx);
      swap(ny, nny);
      for(auto nnnx : nnx) {
         REP(j,b,b+2) nx[nnnx.fi + dx[j] * a[i]] = 1;
      }
      for(auto nnny : nny) {
         REP(j,b,b+2) ny[nnny.fi + dy[j] * a[i]] = 1;
      }
      if(!b) b = 2;
      else b = 0;
   }

   if(nx[x] && ny[y]) puts("Yes");
   else puts("No");
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
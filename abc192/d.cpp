#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   string x;
   ll m;
   cin >> x >> m;

   ll d = 0, k = x.size();
   if(k == 1) {
      if(stoll(x) > m) cout << 0 << '\n';
      else cout << 1 << '\n';
      return 0;
   }

   rep(i,k) chmax(d, (ll)x[i]-'0');

   auto func = [&](ll a) -> bool {
      ll res = 0, p = 1;
      for(ll i = k-1; i >= 0; i--) {
         if(x[i]-'0' > (ll)2e18/p) return false;
         if(a > (ll)2e18/p && i != 0) return false;
         res += (x[i]-'0')*p;
         p *= a;
         if(res > m) return false;
      }
      return true;
   };

   ll ans = 0;
   ll ok = d, ng = m+1;
   while(abs(ok-ng) > 1) {
      ll a = (ok+ng)/2;
      if(func(a)) ok = a;
      else ng = a;
   }

   cout << ok-d << '\n';
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
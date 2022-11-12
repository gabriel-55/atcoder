#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   vector<int> v(1e5+1, -1);
   v[0] = 0, v[1] = 0;
   REP(i,2,1e5+1) {
      if(v[i] != -1) continue;
      v[i] = 1;
      ll x = 2;
      while(1) {
         if(x*i > 1e5) break;
         v[x*i] = 0;
         x++;
      }
   }

   vector<int> a(1e5+1, 0);
   REP(i,2,1e5+1) {
      if(i%2 == 0) continue;
      if(v[i] && v[(i+2)/2]) a[i] = 1;
   }

   vector<int> s(1e5+2, 0);
   rep(i,1e5+1) s[i+1] = a[i] + s[i];

   ll q;
   cin >> q;
   while(q--) {
      ll l, r;
      cin >> l >> r;
      r++;
      cout << s[r] - s[l] << '\n';
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
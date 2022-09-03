#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   vector<bool> v(10);
   rep(i,10) {
      char c;
      cin >> c;
      if(c == '0') v[i] = 0;
      else v[i] = 1;
   }

   if(v[0]) {
      cout << "No" << '\n';
      return 0;
   }

   vector<bool> r(7, 0);
   if(!v[6]) r[0] = 1;
   if(!v[3]) r[1] = 1;
   if(!v[7] && !v[1]) r[2] = 1;
   if(!v[4] && !v[0]) r[3] = 1;
   if(!v[8] && !v[2]) r[4] = 1;
   if(!v[5]) r[5] = 1;
   if(!v[9]) r[6] = 1;

   rep(i,7) REP(j,i+1,7) REP(k,j+1,7) {
      if(!r[i] && r[j] && !r[k]) {
         cout << "Yes" << '\n';
         return 0;
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
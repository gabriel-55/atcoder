#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   string s;
   cin >> s;
   ll b1 = -1, b2 = -1;
   rep(i,8) {
      if(s[i] == 'K') {
         if(i == 0 || i == 7) {
            cout << "No\n";
            return 0;
         }
         bool yes1 = false, yes2 = false;
         rep(j,8) {
            if(s[j] == 'R') {
               if(j < i) yes1 = true;
               if(j > i) yes2 = true;
            }
         }
         if(!yes1 || !yes2) {
            cout << "No\n";
            return 0;
         }
      }
      if(s[i] == 'B') {
         if(b1 != -1) b2 = i;
         else b1 = i;
      }
   }
   if(b1%2 == b2%2) {
      cout << "No\n";
      return 0;
   }
   cout << "Yes\n";
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
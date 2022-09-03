#if !__INCLUDE_LEVEL__
#include __FILE__

int const mod = 1e9 + 7;

int main(void){
   string s;
   cin >> s;

   reverse(s.begin(), s.end());
   vector<int> dp(13, 0);
   dp[0] = 1;
   int cnt = 1;
   rep(i,s.size()) {
      vector<int> p(13, 0);
      swap(dp, p);
      if(i != 0) cnt *= 10;
      cnt %= 13;
      rep(j,13) {
         if(s[i] != '?') {
            dp[(j+cnt*(s[i]-'0'))%13] += p[j];
            dp[(j+cnt*(s[i]-'0'))%13] %= mod;
            continue;
         }

         rep(k,10) {
            dp[(j+cnt*k)%13] += p[j];
            dp[(j+cnt*k)%13] %= mod;
         }
      }
   }

   cout << dp[5] << '\n';
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
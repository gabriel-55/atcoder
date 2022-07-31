#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   vector<string> s(3);
   rep(i,3) cin >> s[i];

   vector<char> c;
   rep(i,3) rep(j,s[i].size()) c.emplace_back(s[i][j]);
   sort(c.begin(), c.end());
   c.erase(unique(c.begin(), c.end()), c.end());

   ll n = c.size();
   if(n > 10) {
      cout << "UNSOLVABLE" << '\n';
      return 0;
   }

   vector<ll> l(26, -1);
   rep(i,n) l[c[i]-'a'] = i;

   vector<ll> p(10);
   rep(i,10) p[i] = i;
   
   do {
      int ok = 1;
      rep(i,3) if(p[l[s[i][0]-'a']] == 0) ok = 0;
      if(!ok) continue;

      vector<ll> ans(3, 0);
      rep(i,3) rep(j,s[i].size()) {
         ans[i] *= 10;
         ans[i] += p[l[s[i][j]-'a']];
      }

      if(ans[0]+ans[1] == ans[2]) {
         rep(i,3) cout << ans[i] << '\n';
         return 0;
      }
   } while(next_permutation(p.begin(), p.end()));

   cout << "UNSOLVABLE" << '\n';
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
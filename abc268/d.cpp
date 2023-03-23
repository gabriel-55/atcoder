#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m;
   cin >> n >> m;

   vector<string> s(n);
   vector<ll> len(n);
   ll tot = 0;

   rep(i,n) cin >> s[i], len[i] = s[i].size(), tot += len[i];
   tot += n-1;

   map<string, bool> mp;
   rep(i,m) {
      string t;
      cin >> t;
      mp[t] = true;
   }

   if(tot > 16) {
      cout << -1  << '\n';
      return 0;
   }

   if(n == 1) {
      if(!mp[s[0]] && s[0].size() >= 3 && s[0].size() <= 16) cout << s[0] << '\n';
      else cout << -1 << '\n';
      return 0;
   }

   string ans;
   vector<ll> v(n);
   iota(v.begin(),v.end(), 0);
   auto dfs = [&](auto dfs, string t, ll now, ll rem, ll nxt) -> void {
      if(!ans.empty()) return;
      t += s[v[nxt]];
      now += len[v[nxt]];
      rem -= len[v[nxt]];
      if(nxt+1 == n){
         if(!mp[t] && now >= 3) ans = t;
         return;
      }
      rep(i,16){
         t += '_';
         if(now+rem+i > 16) break;
         dfs(dfs, t, now+1+i, rem-1, nxt+1);
      }
   };

   do{
      string t = s[v[0]];
      rep(i,16){
         t += '_';
         if(tot+i > 16) break;
         dfs(dfs, t, len[v[0]]+1+i, tot-len[v[0]]-1, 1);
      }
   } while(next_permutation(v.begin(),v.end()));
   
   if(ans.empty()) cout << -1 << '\n';
   else cout << ans << '\n';
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
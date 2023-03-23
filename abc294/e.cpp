#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll L, n1, n2;
   cin >> L >> n1 >> n2;
   map<ll, ll> mp;
   vector v1(n1+n2, vector<P>()), v2(n1+n2, vector<P>());
   ll now = 1, now2 = 1;
   rep(i,n1){
      ll v, l;
      cin >> v >> l;
      if(mp[v] == 0) {
         mp[v] = now;
         now++;
      }
      
      v1[mp[v]-1].emplace_back(now2, now2+l-1);
      now2 = now2+l;
   }
   now2 = 1;
   rep(i,n2){
      ll v, l;
      cin >> v >> l;
      if(mp[v] == 0) {
         mp[v] = now;
         now++;
      }
      
      v2[mp[v]-1].emplace_back(now2, now2+l-1);
      now2 = now2+l;
   }

   debug(v1, v2);

   ll ans = 0;
   rep(i,n1+n2) {
      if(v1[i].empty() || v2[i].empty()) continue;
      ll r = 0, sz = v2[i].size();
      rep(j,v1[i].size()) {
         while(r < sz) {
            if(v2[i][r].se < v1[i][j].fi) {
                debug(1);
                r++;
            }
            else if(v1[i][j].se < v2[i][r].fi) {
                debug(2);
                break;
            }
            else if(v1[i][j].fi <= v2[i][r].fi && v1[i][j].se >= v2[i][r].se) {
               debug(3);
               ans += v2[i][r].se - v2[i][r].fi + 1;
               r++;
            }
            else if(v1[i][j].fi >= v2[i][r].fi && v1[i][j].se <= v2[i][r].se){
               debug(4);
               ans += v1[i][j].se - v1[i][j].fi + 1;
               break;
            }
            else if(v2[i][r].se >= v1[i][j].fi && v2[i][r].fi < v1[i][j].fi) {
               debug(5);
               ans += v2[i][r].se - v1[i][j].fi + 1;
               debug(v1[i][j].fi, v1[i][j].se, v2[i][r].fi, v2[i][r].se);
               r++;
            }
            else if(v1[i][j].se >= v2[i][r].fi && v1[i][j].fi < v2[i][r].fi) {
               debug(6);
               ans += v1[i][j].se - v2[i][r].fi + 1;
               break;
            }
            debug(i, j, ans);
         }
      }
   }

   cout << ans << '\n';
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
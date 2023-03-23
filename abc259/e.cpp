#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, now = 0;
   cin >> n;
   vector<vector<ll>> p(n), e(n);
   vector<ll> m(n);
   map<ll, ll> cvt;
   vector<vector<ll>> v;
   rep(i,n){
      cin >> m[i];
      p[i].resize(m[i]), e[i].resize(m[i]);
      rep(j,m[i]) {
         cin >> p[i][j] >> e[i][j];
         if(!cvt[p[i][j]]) cvt[p[i][j]] = now+1, now++;
         p[i][j] = cvt[p[i][j]];
         p[i][j]--;
         v.push_back({0, 0, 0, 0});
         if(e[i][j] > v[p[i][j]][0]) {
            swap(v[p[i][j]][0], v[p[i][j]][2]);
            swap(v[p[i][j]][1], v[p[i][j]][3]);
            v[p[i][j]][0] = e[i][j];
            v[p[i][j]][1] = 1;
         }
         else if (e[i][j] == v[p[i][j]][0]) v[p[i][j]][1]++;
         else if(e[i][j] > v[p[i][j]][2]) {
            v[p[i][j]][2] = e[i][j];
            v[p[i][j]][3] = 1;
         }
         else if(e[i][j] == v[p[i][j]][2]) v[p[i][j]][3]++;
      }
   }
   set<vector<ll>> ans;
   rep(i,n) {
      vector<ll> cnt;
      rep(j,m[i]) {
         if(v[p[i][j]][0] == e[i][j] && v[p[i][j]][1] == 1) cnt.emplace_back(p[i][j]);
      }
      ans.insert(cnt);
   }
   cout << ans.size() << '\n';
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
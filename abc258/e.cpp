#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, q, x;
   cin >> n >> q >> x;
   vector<ll> w(n);
   rep(i,n) cin >> w[i];

   vector<ll> to(n), to2(n);
   ll r = 0, sum = accumulate(w.begin(), w.end(), 0ll),
   cnt = sum*(x/sum), cnt2 = n*(x/sum);
   rep(l,n) {
      while(cnt+w[r] < x){
         cnt += w[r];
         cnt2++;
         r++;
         r %= n;
      }
      cnt += w[r];
      cnt2++;
      r++;
      r %= n;
      to[l] = r;
      to2[l] = cnt2;
      cnt -= w[l];
      cnt2--;
   }

   vector<ll> a(n, -1);
   a[0] = 0;
   ll join = 0, cycle = 0;
   auto dfs = [&](auto dfs, ll y) -> void {
      ll ny = to[y];
      if(a[ny] != -1) {
         join = a[ny];
         cycle = a[y]+1-a[ny];
         return;
      }
      a[ny] = a[y]+1;
      dfs(dfs, ny);
   };
   dfs(dfs, 0ll);
   
   rep(i,n) {
      if(a[i] == -1) continue;
      to[a[i]] = i;
   }

   vector<ll> que(q);
   rep(i,q) cin >> que[i];

   rep(i,q){
      ll k = que[i];
      k--;
      if(k <= join) {
         cout << to2[to[k]] << '\n';
         continue;
      }
      k -= join;
      k %= cycle;
      k += join;
      cout << to2[to[k]] << '\n';
   }
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
#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, l, r;
   cin >> n >> l >> r;
   ll ans = inf, tot = 0;
   vector<ll> a(n);
   rep(i,n) {
      cin >> a[i];
      tot += a[i];
   }
   chmin(ans, tot);

   ll sum = tot;
   rep(i,n) {
      sum -= a[i];
      sum += l;
      chmin(ans, sum);
   }

   sum = tot;
   for(ll i = n-1; i >= 0; i--) {
      sum -= a[i];
      sum += r;
      chmin(ans, sum);
   }

   vector<ll> ch(n);
   rep(i,n) ch[i] = l-a[i];
   vector<ll> s(n+1);
   rep(i,n) s[i+1] = s[i] + ch[i];
   vector<ll> t(n);
   
   ll mn = 0, id = -1;
   REP(i,1,n+1) {
      if(s[i] < mn) id = i;
      t[i-1] = id;
      chmin(mn, s[i]);
   }

   ll k = tot;
   for(ll i = n-1; i > 0; i--) {
      k -= a[i];
      k += r;
      ll res = k;
      if(t[i-1] != -1) {
         res += s[t[i-1]];    
      }
      chmin(ans, res);    
   }
   
   cout << ans << '\n';
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
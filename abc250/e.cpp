#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n;
   cin >> n;
   vector<ll> a(n), b(n);
   rep(i,n) cin >> a[i];
   rep(i,n) cin >> b[i];
   vector<ll> dp(n, inf), ep(n, -1);
   while(1){
      set<ll> st;
      ll now = -1;
      rep(i,n){
         st.insert(a[i]);
         m_99(j,now+1,n) {
            if(st.count(b[j])) now = j;
            else break;
         }
         ep[i] = now;
      }
      break;
   }
   while(1){
      map<ll, ll> am, bm;
      ll cnt = 0, bnt = 0, now = -1;
      rep(i,n) {
         if(!am[a[i]]) {
            cnt++;
            if(bm[a[i]]) bnt++;
         }
         am[a[i]] = 1;
         if(cnt == bnt) {
            dp[i] = dp[i-1];
            continue;
         }
         m_99(j,now+1,n) {
            if(bm[b[j]]) {
               now++;
               continue;
            }
            if(!bm[b[j]] && am[b[j]]) bnt++;
            bm[b[j]] = 1;
            now = j;
            if(cnt == bnt) {
               dp[i] = now;
               break;
            }
         }
      }
      break;
   }
   ll q;
   cin >> q;
   debug(dp, ep);
   while(q--) {
      ll x, y;
      cin >> x >> y;
      x--; y--;
      if(dp[x] <= y && y <= ep[x]) puts("Yes");
      else puts("No");
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
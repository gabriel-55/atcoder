#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
   ll n, m, e;
   cin >> n >> m >> e;
   vector<ll> u(e), v(e);
   rep(i,e) {
      cin >> u[i] >> v[i];
      u[i]--;
      v[i]--;
   }
   ll q;
   cin >> q;
   vector<bool> ok(n,0), qu(e,1);
   vector<ll> x(q);
   rep(i,q) {
      cin >> x[i];
      x[i]--;
      qu[x[i]] = false;
   }
   reverse(x.begin(),x.end());

   dsu uf(n+m+1);
   ll cnt = 0;
   rep(i,e) {
      if(!qu[i]) continue;
      ll A = v[i], B = u[i];
      if(A+1 > n && B+1 > n) continue;
      if(A+1 <= n && B+1 <= n) {
         if(!ok[uf.leader(A)] && ok[uf.leader(B)]) {
            ok[A] = true;
            ok[B] = true;
            ok[uf.leader(A)] = true;
            cnt += uf.size(A);
         }
         if(ok[uf.leader(A)] && !ok[uf.leader(B)]) {
            ok[A] = true;
            ok[B] = true;
            ok[uf.leader(B)] = true;
            cnt += uf.size(B);
         }
         uf.merge(A, B);
         continue;
      }

      ll b = min(A, B);
      if(!ok[uf.leader(b)]) cnt += uf.size(b);
      ok[b] = true;
      ok[uf.leader(b)] = true;
   }

   vector<ll> ans;
   ans.emplace_back(cnt);
   
   rep(i,q) {
      ll A = v[x[i]], B = u[x[i]];
      if(A+1 > n && B+1 > n) {
         ans.emplace_back(cnt);
         continue;
      }
      if(A+1 <= n && B+1 <= n) {
         if(!ok[uf.leader(A)] && ok[uf.leader(B)]) {
            ok[A] = true;
            ok[B] = true;
            ok[uf.leader(A)] = true;
            cnt += uf.size(A);
         }
         if(ok[uf.leader(A)] && !ok[uf.leader(B)]) {
            ok[A] = true;
            ok[B] = true;
            ok[uf.leader(B)] = true;
            cnt += uf.size(B);
         }
         ans.emplace_back(cnt);
         uf.merge(A, B);
         continue;
      }

      ll b = min(A, B);
      if(!ok[uf.leader(b)]) cnt += uf.size(b);
      ok[b] = true;
      ok[uf.leader(b)] = true;
      ans.emplace_back(cnt);
   }

   reverse(ans.begin(), ans.end());
   REP(i,1,ans.size()) cout << ans[i] << '\n';
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
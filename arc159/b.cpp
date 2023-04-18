#if !__INCLUDE_LEVEL__
#include __FILE__

vector<ll> divisor(ll n) {
   vector<ll> div;
   for(ll i = 1; i*i <= n; i++){
      if(n%i == 0) {
         div.emplace_back(i);
         if(i*i != n) div.emplace_back(n/i);
      }
   }
   sort(div.begin(), div.end());
   return div;
}

int main(void){
    ll a, b;
    cin >> a >> b;
    ll g = gcd(a,b);
    a /= g;
    b /= g;
    if(b > a) swap(a, b);
    ll cnt = 0;
    while(a > 0 && b > 0) {
        vector<ll> div = divisor(a-b);
        ll k = inf;
        m_99(i,1,div.size()) {
            ll diff = b%div[i];
            if((a-diff)%div[i]) continue;
            chmin(k,diff);
        }
        if(k != inf){
            a -= k;
            b -= k;
            g = gcd(a, b);
            a /= g;
            b /= g;
            cnt += k;
        } else {
            cnt += b;
            break;
        }
    }
    cout << cnt << '\n';
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
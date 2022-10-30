#if !__INCLUDE_LEVEL__
#include __FILE__

int main(void){
    vector<string> s(9);
    rep(i,9) cin >> s[i];

    map<pair<ll, ll>, bool> mp;
    rep(i,9) rep(j,9) {
        if(s[i][j] == '#') mp[{i, j}] = true;
    }
    
    ll ans = 0;
    rep(i,9) rep(j,9) rep(k,9) rep(l,9) {
        if(i == k && j == l) continue;
        if(s[i][j] == '.' || s[k][l] == '.') continue;
        complex<ldb> a(i, j), b(k, l), c = b-a;
        c *= complex<ldb>(0, 1);
        c += a;
        complex<ldb> d = c;
        d += b;
        d -= a;

        if(mp[{c.real(), c.imag()}] && mp[{d.real(), d.imag()}]) ans++;
    }
    cout << ans/4 << '\n';
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

class ChineseRemainderTheorem {
    vector<pll> equations;
   public:
    void clear() { equations.clear(); }
    /* x = r (mod m)*/
    void addEquation(ll r, ll m) { equations.push_back({r, m}); }
    pll solve() {
        if (equations.size() == 0) return {-1, -1};  
        ll a1 = equations[0].first;
        ll m1 = equations[0].second;
        a1 %= m1;
        for (int i = 1; i < equations.size(); i++) {
            ll a2 = equations[i].first;
            ll m2 = equations[i].second;

            ll g = __gcd(m1, m2);
            if (a1 % g != a2 % g) return {-1, -1};  
            ll p, q;
            ext_gcd(m1 / g, m2 / g, &p, &q);

            ll mod = m1 / g * m2;
            ll x = ((__int128)a1 * (m2 / g) % mod * q % mod +
                       (__int128)a2 * (m1 / g) % mod * p % mod) %
                      mod;
            a1 = x;
            if (a1 < 0) a1 += mod;
            m1 = mod;
        }
        return {a1, m1};
    }
};

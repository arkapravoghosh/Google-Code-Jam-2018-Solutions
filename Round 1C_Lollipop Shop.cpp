#include   <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ull unsigned long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pld pair<ld, ld>
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define uset unordered_set
#define umap unordered_map
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define fastio ios::sync_with_stdio(false); cin.tie(0);
#define T int tt; cin>>tt; while(tt--)

const ll MOD = (ll)(1e9+7);
const int inf = (int)INFINITY;
const ll INF = (ll)INFINITY;

bool comp(const pii &a, const pii &b){
    return (a.second < b.second);
}

int main() {
    fastio;
    T {
        int n;
        cin>>n;
        umap<int, int> m1, m2;
        vector<pii > m;
        for(int i = 0; i < n; i++)
        {
            int d;
            cin>>d;
            if(d == 0) {
                cout<<-1<<endl;
            }
            else if(d == 1) {
                int t; cin>>t;
                if(!m2.count(t)) {
                    m2[t] = 1;
                    cout<<t<<endl;
                }
                else {
                    cout<<-1<<endl;
                }
                if(m1.count(t)) {
                    for(int j = 0; j < m.size(); j++)
                        if(m[j].first == t) {
                            m[j].second++;
                            break;
                        }
                }
                else {
                    m.pb(mp(t, 1));
                    m1[t] = 1;
                }
            }
            else {
                uset<int> v;
                for(int j = 0; j < d; j++)
                {
                    int z; cin>>z;
                    v.insert(z);
                }
                for(auto x : v)
                {
                    if(m1.count(x)) {
                        for(int j = 0; j < m.size(); j++)
                            if(m[j].first == x) {
                                m[j].second++;
                                break;
                            }
                    }
                    else {
                        m.pb(mp(x, 1));
                        m1[x] = 1;
                    }
                }
                sort(m.begin(), m.end(), comp);
                int flag = 1;
                for(int j = 0; j < m.size(); j++)
                {
                    if(v.count(m[j].first) && !m2.count(m[j].first)) {
                        cout<<m[j].first<<endl;
                        flag = 0;
                        m2[m[j].first] = 1;
                        break;
                    }
                }
                if(flag)
                    cout<<-1<<endl;
            }
        }
    }
	return 0;
} 

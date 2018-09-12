#include <bits/stdc++.h>
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
const int MAX = (int)1e5;
 
int main() {
    fastio;
    int t = 1;
    T {
        cout<<"Case #"<<t++<<": ";
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
            cin>>a[i];
        if(a[0] == 0 || a[n-1] == 0)
            cout<<"IMPOSSIBLE\n";
        else {
            char mat[n][n];
            int maxn = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                    mat[i][j] = mat[i][j] = '.';
            }
            vector<pii > b(n);
            int countl = 0, countr = n-1, ind = 0;
            b[0].ff = 0; b[0].ss = a[0]-1;
            ind = a[0]; countr = ind;
            for(int i = 1; i < n; i++)
            {
                if(a[i] == 0) {
                    if(i >= ind)
                        countl++;
                    b[i].ff = -1;
                } else {
                    if(countl > a[i]) {
                        b[i].ff = ind;
                        b[i].ss = ind + a[i]-1;
                        countl = countl + 1 - a[i];
                        ind = b[i].ss + 1;
                    }
                    else if(countl == a[i]) {
                        b[i].ff = ind;
                        b[i].ss = i-1;
                        ind = i;
                        countl = 1;
                    } else {
                        countr = a[i] - 1 - countl;
                        b[i].ff = i - countl;
                        b[i].ss = i + countr;
                        countl = 0;
                        ind = b[i].ss + 1;
                    }
                }
            }
            for(int i = 0; i < n; i++)
            {
                if(b[i].ff != -1) {
                    int start = b[i].ff, end = b[i].ss;
                    if(start < i) {
                        int k = 0;
                        for(int j = start; j < i; j++)
                        {
                            mat[k++][j] = '\\';
                        }
                        maxn = max(k, maxn);
                    }
                    if(end > i) {
                        int k = 0;
                        for(int j = end; j > i; j--)
                        {
                            mat[k++][j] = '/';
                        }
                        maxn = max(k, maxn);
                    }
                }
            }
            cout<<maxn+1<<"\n";
            for(int i = 0; i < maxn; i++)
            {
                for(int j = 0; j < n; j++)
                    cout<<mat[i][j];
                cout<<endl;
            }
            for(int i = 0; i < n; i++)
                cout<<".";
            cout<<endl;
        }
    }
    return 0;
}

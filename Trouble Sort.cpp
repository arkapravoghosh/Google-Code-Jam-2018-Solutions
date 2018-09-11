#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ppb pop_back
#define mt make_tuple
#define ll long long
#define ull unsigned long long
#define uset unordered_set
#define umap unordered_map
#define T int tt, t = 1; cin>>tt; while(tt--)

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
	T {
		cout<<"Case #"<<t++<<": ";
		int n;
		cin>>n;
		vector<ll> a(n);
		for(int i = 0; i < n; i++)
		    cin>>a[i];
	    bool sorted = false;
	    while(!sorted) {
	        sorted = true;
	        for(int i = 0; i < n-2; i++)
	        {
	            if(a[i] > a[i+2]) {
	                ll temp = a[i];
	                a[i] = a[i+2];
	                a[i+2] = temp;
	                sorted = false;
	            }
	        }
	    }
	    int ind = -1;
	    for(int i = 0; i < n-1; i++)
	        if(a[i] > a[i+1]) {
	            ind = i;
	            break;
	        }
	    if(ind == -1)
	        cout<<"OK";
	    else
	        cout<<ind;
		cout<<endl;
	}
	return 0;
}

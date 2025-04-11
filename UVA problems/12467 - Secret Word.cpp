#include <bits/stdc++.h>
#define pb push_back
#define int long long
#define ll long long
#define ull unsigned long long
#define ld long double
#define f first
#define s second
#define endl '\n'
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define read_file freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

using namespace std;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

// __builtin_popcount() 1s cnt
// __builtin_clz() 0s left
// __builtin_ctz(x) 0s right

vector<int> kmp(const string& a){
    int n=a.size();
    vector<int> k(n);
    for(int i=1; i<n; i++){
        int len=k[i-1];
        while(len&&a[i]!=a[len]) len=k[len-1];
        if(a[len]==a[i]) len++;
        k[i]=len;
    }
    return k;
}

void solve(){
    string a; cin>>a;
    string b=a; reverse(b.begin(), b.end());
    if(a==b){
        cout<<a<<endl; return;
    }

    string rip=a+"#"+b;
    vector<int> k=kmp(rip);
    int mxi=1, ind=0;
    for(int i=a.size()+1; i<rip.size(); i++){
        if(k[i]>mxi){mxi=k[i]; ind=i-k[i]+1;}
    }

    string ans=rip.substr(ind, mxi); reverse(ans.begin(), ans.end());
    cout<<ans<<endl;
}

int32_t main(){
    fast;

    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
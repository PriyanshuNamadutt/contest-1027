#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void dfs( int node , vector<int> &vis , vector<int> &parent , unordered_map<int,list<int>> &adj ) {

    for ( auto it : adj[node] ) {
        if ( !vis[it] ) {
            vis[it] = 1;
            parent[it] = node;
            dfs( it , vis , parent , adj );
        }
    }
} 

void solve( int node , ll &ans , bool check , vector<int> &parent , vector<ll> &a , ll val ) {
    if ( node == -1 ) return;

    if ( check ) {
        ans = max( ans , val + a[node] );
        solve( parent[node] , ans , false , parent , a , val + a[node] );
    }
    else {
        ans = max( ans , val - a[node] );
        solve( parent[node] , ans , true , parent , a , val - a[node] );
    }
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<ll> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }

        unordered_map<int,list<int>> adj;
        for ( int i = 1; i < n; i++ ) {
            int u, v;
            cin >> u >> v;
            --u , --v;

            adj[u].push_back( v );
            adj[v].push_back( u );
        }

        vector<int> vis( n , 0 );
        vector<int> parent( n );
        parent[0] = -1;
        vis[0] = 1;
        dfs( 0 , vis , parent , adj );

        for ( int i = 0; i < n; i++ ) {

            ll ans = a[i];
            solve( parent[i] , ans , false , parent , a , a[i] );
            cout << ans << " ";
        }
        cout << endl;
    }
    return 0;
}

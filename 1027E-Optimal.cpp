#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

void dfs( int node , vector<int> &vis , unordered_map<int,list<int>> &adj , vector<int> &parent ) {

    for ( auto it : adj[node] ) {
        if ( !vis[it] ) {
            vis[it] = 1;
            parent[it] = node;
            dfs( it , vis , adj , parent );
        }
    }
}

ll mini( int node , vector<ll> &a , vector<ll> &mx , vector<ll> &mn , vector<int> &parent );

ll maxi( int node , vector<ll> &a , vector<ll> &mx , vector<ll> &mn , vector<int> &parent ) {

    if ( mx[node] != -1 ) return mx[node];

    ll ans = mini( parent[node] , a , mx , mn , parent );
    return mx[node] = max( a[node] , a[node] - ans );
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

        vector<int> vis(n , 0);
        vis[0] = 1;
        vector<int> parent( n );

        dfs( 0 , vis , adj , parent );

        vector<ll> mx(n , -1);
        vector<ll> mn(n , -1);
        mx[0] = a[0] , mn[0] = a[0];

        for ( int i = 1; i < n; i++ ) {

            mx[i] = maxi( i , a , mx , mn , parent);
            mn[i] = mini( i , a , mx , mn , parent);
        }

        for ( int i = 0; i < n; i++ ) {
            cout << mx[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

ll mini( int node , vector<ll> &a , vector<ll> &mx , vector<ll> &mn , vector<int> &parent ) {

    if ( mn[node] != -1 ) return mn[node];

    ll ans = maxi( parent[node] , a , mx , mn , parent );
    return mn[node] = min( a[node] , a[node] - ans );
}

#include<iostream>
#include<vector>
#include<unordered_map>
typedef long long int ll;
using namespace std;

pair<ll,pair<int,int>> solve( int idx , vector<pair<int,int>> &a ) {

    int min_x = 1e9 , max_x = 0;
    int min_y = 1e9 , max_y = 0;
    for ( int i = 0; i < a.size(); i++ ) {

        if ( i == idx ) continue;

        if ( a[i].first > max_x ) max_x = a[i].first;
        if ( a[i].first < min_x ) min_x = a[i].first;
        if ( a[i].second > max_y) max_y = a[i].second;
        if ( a[i].second < min_y) min_y = a[i].second;
    }

    pair<int,int> p = { (max_x - min_x + 1) , ( max_y - min_y + 1) };
    return { (1LL)*(max_x - min_x + 1)*( max_y - min_y + 1) , p};
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<pair<int,int>> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i].first >> a[i].second;
        }
        if ( n == 1  ) {
            cout << 1 << endl;
            continue;
        }

        unordered_map<ll,pair<int,int>> mp;
        ll ans = 1e18;
        for( int i = 0; i < n; i++ ) {

            pair<ll,pair<int,int>> value = solve( i , a );
            ll num = value.first;
            int x = value.second.first;
            int y = value.second.second;

            if ( num < ans ) {
                ans = num;
                mp[ans] = {x,y};
            }
        }

        if ( ans >= n ) cout << ans << endl;
        else {
            int x = mp[ans].first;
            int y = mp[ans].second;

            cout << min( (x+1)*y , x*(y+1) ) << endl;
        }
    }
    return 0;
}

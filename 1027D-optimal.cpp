#include<iostream>
#include<vector>
typedef long long int ll;
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<pair<ll,ll>> a(n);
        pair<ll,ll> max_x = {0,0} , min_x = {1e9 + 7, 1e9 + 7};
        pair<ll,ll> max_y = {0,0} , min_y = {1e9 + 7, 1e9 + 7};

        for ( int i = 0; i < n; i++ ) {
            cin >> a[i].first >> a[i].second;

            if ( a[i].first >= max_x.first ) {
                max_x.second = max_x.first;
                max_x.first = a[i].first;
            }
            else if ( a[i].first > max_x.second ) max_x.second = a[i].first;

            if ( a[i].first <= min_x.first ) {
                min_x.second = min_x.first;
                min_x.first = a[i].first;
            }
            else if ( a[i].first < min_x.second ) min_x.second = a[i].first;

            if ( a[i].second >= max_y.first ) {
                max_y.second = max_y.first;
                max_y.first = a[i].second;
            }
            else if ( a[i].second > max_y.second ) max_y.second = a[i].second;

            if ( a[i].second <= min_y.first ) {
                min_y.second = min_y.first;
                min_y.first = a[i].second;
            }
            else if ( a[i].second < min_y.second ) min_y.second = a[i].second;
        }

        if ( n <= 2 ) {
            cout << n << endl;
            continue;
        }

        ll ans = 1e18;
        for ( int i = 0; i < n; i++ ) {

            ll x = a[i].first;
            ll y = a[i].second;

            ll a , b;

            if ( x == min_x.first ) {

                a = ( max_x.first - min_x.second + 1);
                if ( y == min_y.first ) b = ( max_y.first - min_y.second + 1);
                else if ( y == max_y.first ) b = ( max_y.second - min_y.first + 1);
                else b = ( max_y.first - min_y.first + 1);
            }
            else if ( x == max_x.first ) {

                a = ( max_x.second - min_x.first + 1);
                if ( y == min_y.first ) b = ( max_y.first - min_y.second + 1);
                else if ( y == max_y.first ) b = ( max_y.second - min_y.first + 1);
                else b = ( max_y.first - min_y.first + 1);
            }
            else {

                a = ( max_x.first - min_x.first + 1);
                if ( y == min_y.first ) b = ( max_y.first - min_y.second + 1);
                else if ( y == max_y.first ) b = ( max_y.second - min_y.first + 1);
                else b = ( max_y.first - min_y.first + 1);
            }

            ll num = a*b*(1LL);

            if ( num <= n-1 ) ans = min( (a+1)*b , (b+1)*a );
            else ans = min( ans , num );
        }
        cout << ans << endl;
    }
    return 0;
}

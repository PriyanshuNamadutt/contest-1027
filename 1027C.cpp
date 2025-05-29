#include<iostream>
#include<vector>
using namespace std;

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n; cin >> n;
        vector<int> a(n);
        for ( int i = 0; i < n; i++ ) {
            cin >> a[i];
        }

        int prev = -1 , cnt = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( a[i] - prev > 1 ) {
                prev = a[i];
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

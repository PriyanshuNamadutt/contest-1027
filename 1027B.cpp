#include<iostream>
using namespace std;

bool solve( int mn , int k , int n ) {
    
    int it = mn/2 + 1;
    int start = mn % 2 == 0 ? n : n-1;

    for ( int i = 0; i < it; i++ ) {
        if ( start == k ) return true;
        start -= 2;
    }
    return false;
}

int main () {
    int t; cin >> t;
    while ( t-- ) {
        int n, k;
        cin >> n >> k;
        string s; cin >> s;
        int cnt = 0;
        for ( int i = 0; i < n; i++ ) {
            if ( s[i] == '1' ) cnt++;
        }

        cout << ( solve( min(cnt , n-cnt) , k , n/2 ) ? "YES" : "NO" ) << endl;
    }
    return 0;
}

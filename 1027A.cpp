#include<bits/stdtr1c++.h>
using namespace std;

int main () {
    int t; cin >> t;
    while( t-- ) {
        string s; cin >> s;

        int num = 0;
        for ( int i = 0; i < 4; i++ ) {
            num += (s[i]-'0')*pow( 10 , 3-i );
        }

        int a = sqrt( num );
        if ( a*a != num ) cout << -1 << endl;
        else {
            cout << 0 << " " << a << endl;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define lli long long int
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;



// ------------- Solution class to use to finding the solutions
class Solution{

    public:
        //-------------- Start to code your function here
        


};


//--------------- Main function to running the program
int main() {
    int t;
    cin>>t;
    int ans=0;

    while(t--){
        int cnt = 0;
        
        int a,b,c;
        cin >> a >> b >> c;

        if(a == 1) cnt++;
        if(b == 1) cnt++;
        if(c == 1) cnt++;

    if(cnt >=2 ) ans ++;
    }
    cout << ans <<endl;


}
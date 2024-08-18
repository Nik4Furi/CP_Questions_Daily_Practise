#include <bits/stdc++.h>
#include <iostream>

using namespace std;

//----------- Define the long syntax to short
#define str string
#define ll long long
#define lli long long int
#define ld long double

//-------- Define the short functions
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
    while(t--){

        str s;
        cin >> s;
    
        int sz = sza(s);
        if(sz <= 10){
            cout << s <<endl;
            continue;
        }

        //o/w count len
        cout << s[0] << sz-2 << s[sz-1] <<endl;
        
        
    }
}
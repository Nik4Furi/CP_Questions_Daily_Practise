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
    
    int n;
    cin >> n;
    if(n == 2)  
        cout << "NO" <<endl;
    else if(n&1)
        cout << "NO" <<endl;
    else cout << "YES" <<endl;
    return 0;
}
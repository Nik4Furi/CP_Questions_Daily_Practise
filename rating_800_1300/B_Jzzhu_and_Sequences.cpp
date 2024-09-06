#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using namespace chrono;

//------------- Here I define the variables types
#define int int           // range is ~1e10 (-2147483648 to 2147483647)
#define ll long long      // range is 2e63-1
#define lli long long int // range is 2e63
#define dd double         // range 1.7e+308
#define ld long double    // range 1.7e+308

//---------------- Here I fix some variables/functions
#define MOD 1e9 + 7
#define pb push_back // arrays,stack or others function
#define ppb pop_back // arrays ...
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

//---------------- Here I define some inline/one-line functions
const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const ld EPS = 1e-9;

//-------------- Here I declare most used functions, i.e. in every line
template <typename T>
void readInput(T &value) { cin >> value; }
template <typename T>
void print(const T &value) { cout << value << endl; }

template <typename T>
void printVector(const std::vector<T> &vec)
{ // printng the vector
    for (const auto &element : vec)
    {
        std::cout << element << " ";
    }
    cout << endl;
}

template <typename K, typename V>
void printMap(const std::map<K, V> &m)
{ // print the map
    for (const auto &pair : m)
    {
        std::cout << pair.ff << ": " << pair.ss << std::endl;
    }
}

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

#ifdef nik4furi
#define debug(x)      \
    cerr << x << " "; \
    cerr << endl;
#else
#define debug(x) ;
#endif

class Solution
{
    const int mod = 1e9 + 7;

    int mmd(int ele)
    {
        return ele % mod;
    }
    int sub(int ele)
    {
        return mod + ele;
    }

    // Function of the recusion
    int solveRec(int x, int y, int n)
    {
        // base case
        if (n == 1)
            return x;
        else if (n == 2)
            return y;
        int a1 = solveRec(x, y, n - 1),
            a2 = solveRec(x, y, n - 2);

        a1 = a1 < 0 ? sub(a1) : mmd(a1);
        a2 = a2 < 0 ? sub(a2) : mmd(a2);
        int ans = (a1 - a2);

        ans = ans < 0 ? sub(ans) : mmd(ans);

        return ans;
    }

    //Recursion +Memo
    int solveMemo(int x,int y,int n,vector<int>&dp){
        // base case
        if (n == 1)
            return x;
        else if (n == 2)
            return y;

        //Edge case
        if(dp[n] != -1) return dp[n];

        int a1 = solveMemo(x, y, n - 1,dp),
            a2 = solveMemo(x, y, n - 2,dp);

        a1 = a1 < 0 ? sub(a1) : mmd(a1);
        a2 = a2 < 0 ? sub(a2) : mmd(a2);
        int ans = (a1 - a2);

        dp[n] = ans < 0 ? sub(ans) : mmd(ans);

        return dp[n];
    }

public:
    void sol()
    {
        int x, y, n;
        cin >> x >> y >> n;
        // give fn = fn-1 - fn-2

        x=x<0?sub(x):mmd(x);
        y = y<0?sub(y):mmd(y);

        //Edge case
        if(x == 0 && y == 0) {
            print(0);
            return;
        }

        if (n == 1)
        {
            print(x);
            return;
        }
        if (n == 2)
        {
            print(y);
            return;
        }
//Recursion
        // int ans = solveRec(x, y, n);

       /* //Now use meoization
        vector<int>dp(n+1,-1);
        int ans = solveMemo(x,y,n,dp); */

        //Math, every 6th phase is same
        // {x,y,y-x,-x,-y,x-y,x,y,y-x,...} 

        //we have already x,y
        int third=y-x ;
        third = third<0 ? sub(third) : mmd(third);

        int fourth = -(x) ;
        fourth = fourth< 0? sub(fourth) : mmd(fourth);

        int fifth = -(y);
        fifth = fifth<0?sub(fifth) : mmd(fifth);

        int six = x-y;
        six = six < 0 ? sub(six):mmd(six);

        int tempMod = n%6;
        switch (tempMod)
        {
        case 1:
            print(x);
            break;
        case 2:
            print(y);
            break;
        case 3:
            print(third);
            break;
        case 4:
            print(fourth);
            break;
        case 5:
            print(fifth);
            break;
        case 0:
            print(six);
            break;
        
       
        }
        
    }
};

int main()
{

#ifdef nik4furi
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // int t; readInput(t);
    int t = 1;
    for (int tc = 0; tc < t; tc++)
    {
        Solution *s = new Solution();
        s->sol();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef nik4furi
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}

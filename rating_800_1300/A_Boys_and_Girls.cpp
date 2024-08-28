#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
#include <iostream>

using namespace std;
using namespace chrono;

//------------- Variable type macros
#define ll long long   // range is 2e63-1
#define dd double      // range 1.7e+308
#define ld long double // range 1.7e+308

//---------------- Pre-defined constants and functions
#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define MOD 1e9 + 7
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll INF = 1e9;
const ld EPS = 1e-9;

//-------------- I/O optimizations and debugging
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

//--------------- Solution class
class Solution
{
    // Function to print sequences
    void printSeq(char ch1, char ch2, int n, int m)
    {
        int i = 0, j = 0;
        while (i < n && j < m)
        {
            cout << ch1 << ch2;
            i++, j++;
        }

        while (i < n)
        {
            cout << ch1;
            i++;
        }

        while (j < m)
        {
            cout << ch2;
            j++;
        }
    }

public:
    void sol()
    {
        // Redirect standard input and output to files
        TxtIO;

        int n, m;
        cin >> n >> m;

        if (n > m)
            printSeq('B', 'G', n, m);
        else
            printSeq('G', 'B', m, n);
    }
};

int main()
{
#ifdef nik4furi
    freopen("Error.txt", "w", stderr);
#endif

    // fastio();
    auto start1 = high_resolution_clock::now();

    // Assuming a single test case for simplicity
    Solution s;
    s.sol();

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef nik4furi
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
#endif

    return 0;
}

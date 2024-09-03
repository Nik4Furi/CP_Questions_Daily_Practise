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

    ll mod2 = 1073741824;

    ll mult(int a, int b, int c)
    {
        return (a % mod2 * b % mod2 * c % mod2) % mod2;
    }
    ll add(ll a, ll b)
    {
        return (a % mod2 + b % mod2) % mod2;
    }

    // Function to return the divisor of numbers
    int divisor(ll ele)
    {
        int cnt = 1;
        ll half = ele / 2;
        for (ll i = 1; i <= half; i++)
            if (ele % i == 0)
                cnt++;
        return cnt;
    }

public:
    void sol()
    {
        int a, b, c;
        cin >> a >> b >> c;

        vector<std::vector<std::vector<ll>>> dp(101, std::vector<std::vector<ll>>(101, std::vector<ll>(101, -1)));

        ll sum = 0;

        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                for (int k = 1; k <= c; k++)
                {
                    int arr[3] = {i, j, k};
                    bool found = false;

                    // Iterate over all permutations of (i, j, k)
                    do
                    {
                        if (dp[arr[0]][arr[1]][arr[2]] != -1)
                        {
                            found = true;
                            break;
                        }
                    } while (std::next_permutation(arr, arr + 3));

                    if (found)
                    {
                        sum = add(sum, dp[arr[0]][arr[1]][arr[2]]); 
                        continue;
                    }
                    ll multiply = mult(i, j, k);

                    dp[i][j][k] = dp[i][k][j] = dp[j][i][k] = dp[j][k][i] = dp[k][i][j] = dp[k][j][i] = divisor(multiply);
                    sum = add(sum, dp[i][j][k]);
                }
            }
        }

        print(sum);
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

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

void solve()
{
    /* int n;
     cout << "Print i/p " << endl;
     readInput(n);
     cout << n << endl;
     print(n);

     // double number = 3.14;
     std::vector<int> vec = {1, 2, 3};
     std::map<std::string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};

     // // Printing different types
     // print(number);
     cout << "print vector with " << endl;
     printVector(vec);
     printMap(m); */

    //----------------- START TO CODE FROM HERE
    int n;
    cin >> n;

    // first print n rows
    for (int row = 1; row <= n; row++)
    {

        // print first spaces
        for (int col1 = row; col1 <= n; col1++)
            cout << "  ";

        // then print val1 section
        int val = 0;
        for (int col2 = 1; col2 <= row; col2++)
        {
            if (col2 == row)
            {
                cout << val;
                break;
            }
            cout << val << " ";
            val++;
        }

        // then print the val2 section
        val -= 1;
        for (int col3 = 1; col3 < row; col3++)
        {
            cout<< " " << val ;
            val--;
        }

        // now print the spaces again
        //  for(int col4 =row;col4<=n;col4++)
        //      cout << " ";
        cout << endl;
    }

    // Now print the n+1th row,
    for (int col = 0; col <= n; col++)
        cout << col << " ";
    for (int col = n - 1; col > 0; col--)
        cout << col << " ";
    cout << 0;
    cout << endl;

    // now print the next 5 lines
    for (int row = n; row >= 1; row--)
    {

        // print first spaces
        for (int col1 = row; col1 <= n; col1++)
            cout << "  ";

        // then print val1 section
        int val = 0;
        for (int col2 = row; col2 >= 1; col2--){
            if(col2 == 1){
                cout << val;
                break;
            }
            cout  << val++ << " ";
        }

        // then print the val2 section
        val -= 1;
        for (int col3 = row - 1; col3 >= 1; col3--)
            cout << " " << val--;

        // now print the spaces again
        //  for(int col4 =row;col4<=n;col4++)
        //      cout << " ";
        cout << endl;
    }
}

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
        solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef nik4furi
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}

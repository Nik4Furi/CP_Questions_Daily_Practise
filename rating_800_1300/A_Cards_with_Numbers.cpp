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

#define TxtIO                         \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

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


class Solution{
     public:
       void sol(){
            TxtIO;
            int n;cin >> n;

            vector<pair<int,int>> ans;
            int sz = 2*n;
            vector<int>arr(5000,-1);

            bool isAns = true;

            for(int i=0;i<n;i++){
                int d;cin >>d;

                //find
                if(arr[d] == -1 ){
                    arr[d] = i+1;
                    
                }
                else {
                    // cout << arr[d] <<  " "<< i+1 <<endl;
                    //it if find
                    ans.push_back({arr[d],i+1});

                    //remove this record
                    arr[d] = -1;
                }
            }

            for(int i=0;i<n;i++){
                int d;cin >>d;

                //find
                if(arr[d] == -1 ){
                    arr[d] = i+1;
                    
                }
                else {
                    // cout << arr[d] <<  " "<< i+1 <<endl;
                    //it if find
                    ans.push_back({arr[d],i+1});

                    //remove this record
                    arr[d] = -1;
                }
            }

            // cout << sza(ans) <<endl;

            if(sza(ans) != n) cout << -1 <<endl;
            else {
                for(int i=0;i<n;i++)
                    cout << ans[i].first << " "<<ans[i].second << endl;
            }
       }
};

int main()
{

#ifdef nik4furi
    freopen("Error.txt", "w", stderr);
#endif
    // fastio();
    auto start1 = high_resolution_clock::now();
    // int t; readInput(t);
    int t=1;
    for(int tc=0;tc<t;tc++){
      Solution* s = new Solution();
      s-> sol();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef nik4furi
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}


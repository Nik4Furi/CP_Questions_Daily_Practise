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

//-------------------- Solution class to write all of code inint
class Solution
{
public:
    void solve() {
        int n;cin >>n;
        
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            int x,y;cin >> x >> y;
            v[i] = {x,y};
        }

        //now traverse the vector
        int res = 0;
        for(int i=0;i<n;i++){
            int x=v[i].first,y=v[i].second;
            bool isRight = false,isLeft=false,isUp =false,isDown = false;

            for(int j=i+1;j<n;j++){
                int tx = v[j].first,ty=v[j].second;

                //right
                if(x == tx && y < ty) isRight = true;
                //left
                else if(x == tx && y > ty) isLeft = true;

                //up
                else if(y == ty && x > tx) isUp = true;
                
                //down
                else if(y == ty && x < tx) isDown = true;

                if(isRight && isLeft && isUp && isDown) break;
            }
            cout << x << " "<< y << " "<< isRight << "  "<<isLeft << " "<< isUp << " "<<isDown <<endl;
            if(isRight && isLeft && isUp && isDown) res++;
        }

        cout << res <<endl;
    }
};

int main()
{

#ifdef nik4furi
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // int t;
    // readInput(t);
    int t=1;
    for (int tc = 0; tc < t; tc++)
    {
        Solution* sol = new Solution();
        sol->solve();
    }

    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
#ifdef nik4furi
    cerr << "Time: " << duration.count() / 1000 << endl;
#endif
}

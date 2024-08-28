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


class Solution{
    //----------functiont to finding all the permutations
    void findAllPermutations(vector<int>arr,vector<vector<int>> &permutes){

        do{
            // printVector(arr);
            permutes.push_back(arr);
        }while(next_permutation(arr.begin(),arr.end()));

    }
     public:
       void sol(){
            vector<vector<int>> grid(5,vector<int>(5));

            for(int i=0;i<5;i++){
                for(int j=0;j<5;j++) cin >> grid[i][j];
            }

            vector<int>arr(5);
            for(int i=0;i<5;i++) arr[i] = i+1;

            //Now finding all the permutations of arr, and finding the sum in O(1) time of all

            vector<vector<int>> permutes;

            findAllPermutations(arr,permutes);

            //Now traverse the permutes array and finding the maximum sum
            ll maxi = 0;

            for(int i=0;i<permutes.size();i++){
                vector<int> temp = permutes[i];
                int a=temp[0]-1,b=temp[1]-1,c=temp[2]-1,d=temp[3]-1,e=temp[4]-1;

                ll sum = (grid[a][b]+grid[b][a]+grid[c][d]+grid[d][c])+
                        (grid[b][c]+grid[c][b]+grid[d][e]+grid[e][d])+
                        (grid[c][d]+grid[d][c])+
                        (grid[d][e]+grid[e][d]);
                maxi  = max(maxi,sum);
            }

            print(maxi);
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


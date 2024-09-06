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
     public:
       void sol(){
            //App: finding the l,r on O(n), where only check curr > prev 
            //Verdict: for L, traverse 1 to n-1
            //Verdict: for r, traverse n-2  to 0;
            int n;cin >> n;
            vector<int> arr(n);

            for(int i=0;i<n;i++) cin >> arr[i];

            int l=-1,r=-1;

            //Now finding the lth
            for(int i=1;i<n;i++){
                int curr = arr[i],prev=arr[i-1];
                // cout << "cur and prev "<< curr << " "<<prev <<endl;

                if(prev > curr){
                    l = i-1;
                    break;
                }
            }

            //Now finding the rth
             for(int i=n-2;i>=0;i--){
                int curr=arr[i],prev=arr[i+1];

                if(prev < curr){
                    r = i+1;
                    break;
                }
            }

            //edge case
            if(l== -1 || r== -1){
                print("yes");
                cout << 1 << " "<<1 <<endl;
                return;
            }

            //o/w reverse and check
            reverse(arr.begin()+l,arr.begin()+r+1);

            // printVector(arr);


            //Now check array is sorted in incresing order
            for(int i=1;i<n;i++){
                if(arr[i] < arr[i-1]){
                    print("no");
                    return;
                }
            }

            print("yes");
            cout << l+1 << " "<<r+1 <<endl;
                

       }
};

int main()
{

#ifdef nik4furi
    freopen("Error.txt", "w", stderr);
#endif
    fastio();
    auto start1 = high_resolution_clock::now();
    // int t; readInput(t);4
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


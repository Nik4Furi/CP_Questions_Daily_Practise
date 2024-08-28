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
            int n;cin >> n;
            bool isAns = true;
            
            int cnt1=0,cnt2=0,cnt3=0,cnt4=0,cnt6=0;

            for(int i=0;i<n;i++) {
                int d;cin >> d;

                if(d == 5 || d == 7){
                    isAns = false;
                }
                cnt1 += d == 1;
                cnt2 += d == 2;
                cnt3 += d == 3;
                cnt4 += d == 4;
                cnt6 += d == 6;
            }

            if(!isAns || cnt1 != cnt2+cnt3
                ||
                cnt4 > cnt2){
                print(-1);
                return;
            }

            //now finding the valid groups
            int grp = n/3;

            //Now the ans exist
            for(int i=0;i<grp;i++){
                int secondPos = cnt2 >= cnt3 ? 2 : 3; 
                int thirdPos = secondPos == 3 ? 6 : (cnt4 != 0 ? 4 :6);
                cout << 1 << " "<< secondPos << " "<<thirdPos <<endl;

                cnt1--;
                if(secondPos == 2) cnt2 --;
                else cnt3--;

                if(thirdPos == 4) cnt4 --;
                else cnt6--;
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


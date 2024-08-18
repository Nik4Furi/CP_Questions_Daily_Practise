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
class Solution
{

public:
    //-------------- Start to code your function here
};

//--------------- Main function to running the program
int main()
{
    int n, k;
    cin >> n >> k;
    int cnt = 0;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        v.push_back(d);
    }

 
        for (int i = 0; i <= k; i++)
        { cout << v[i] << endl;
            if (v[i] >= v[k])
                cnt++;
            // else
            //     break;
        }

        cout << cnt << endl;
   
    return 0;
}
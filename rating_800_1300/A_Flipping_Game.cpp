#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    int initial_ones = 0;
    
    // Input and count initial number of ones
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) {
            initial_ones++;
        }
    }
    
    // Edge case: if all the elements are 1s, we must flip at least one element, so result will be n-1
    if (initial_ones == n) {
        cout << n - 1 << endl;
        return 0;
    }
    
    // Array to calculate gain when flipping subarray
    int max_gain = -1;
    int current_gain = 0;
    
    // We use Kadane's algorithm to find the maximum gain subarray
    for (int i = 0; i < n; ++i) {
        int value = (a[i] == 0) ? 1 : -1;
        current_gain += value;
        
        if (current_gain > max_gain) {
            max_gain = current_gain;
        }
        
        if (current_gain < 0) {
            current_gain = 0;
        }
    }
    
    // The maximum number of 1s is initial_ones + max_gain
    cout << initial_ones + max_gain << endl;
    
    return 0;
}

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Read input
    vector<char> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    // Map to store sum and its first index
    unordered_map<int, int> m;


    m[0] = -1; // Handle case starting from index 0

    int sum = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {

        // Update sum: P adds 1, A subtracts 1
        if (v[i] == 'P') {
            sum += 1;
        } else {
            sum -= 1;
        }

        // If sum exists, we found a balanced window
        if (m.find(sum) != m.end()) {
            int len = i - m[sum];
            if (len > ans) {
                ans = len;
            }
        } else {
            // Store index of this sum
            m[sum] = i;
        }
    }

    cout << ans << endl;

    return 0;
}



// USED TEST CASE
// Input:
// 8
//P    
//P
//A
//A
//P
//P
//A
//A

// OUTPUT

// 8  
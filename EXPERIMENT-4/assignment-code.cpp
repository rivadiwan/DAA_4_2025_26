#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int k, n;
    
    cout << "Enter K: ";
    cin >> k;
    cout << "Enter N: ";
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;

    cout << "Enter scores:" << endl;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (pq.size() < k) {
            pq.push(x);
        } else {
            if (x > pq.top()) {
                pq.pop();
                pq.push(x);
            }
        }

        if (pq.size() < k) {
            cout << "-1" << endl;
        } else {
            cout << pq.top() << endl;
        }
    }

    return 0;
}

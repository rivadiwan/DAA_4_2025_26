//#include <bits/stdc++.h>

//UID = 24BCS10039
//NAME = ABHINEET


//Experiment - 1

//Recurrence relation

// COST = 1 + N + NlogN + N/2 = NlogN
// T(N) = NlogN + 3T(N/2)


//Time complexity

//    O(N^(log Base 2 of 3) 
//    Case 1 Used


#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
using namespace std::chrono;

void complexRec(int n, int &operations, int depth, int &maxDepth) {

    maxDepth = max(maxDepth, depth);
    operations++;

    //o(1)
    if (n <= 2) {
        return;
    }
    operations++;

    // O(N)
    int p = n;
    operations++;

    //O(NlogN)
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operations++;
        }
        p >>= 1;
        operations++;
    }

    //O(N)
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operations++;
    }

    reverse(small.begin(), small.end()); //O(N/2)
    operations++;

    complexRec(n / 2, operations, depth + 1, maxDepth); //PART -1
    complexRec(n / 2, operations, depth + 1, maxDepth); //PART -2
    complexRec(n / 2, operations, depth + 1, maxDepth); //PART -3
}

int main()
{
    auto start = high_resolution_clock::now();
    int operations = 0, depth = 1, maxDepth = 1;
    int size;
    cout<<"Input Size : ";
    cin >>size;
    complexRec(size, operations, depth, maxDepth);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout <<"Time Duration : " << duration.count() <<"ms"<< endl;
    cout <<"Number Of Operations : " << operations << endl;
    cout <<"Maximum Recursion Depth : " << maxDepth << endl;

    cout<<"Recurrence Relation : NlogN + 3T(N/2)";
}


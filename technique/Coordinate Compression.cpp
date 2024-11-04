#include <bits/stdc++.h>
/*
Coordinate Compression (좌표압축)

*/

#define all(v) v.begin(), v.end()
void CoordinateCompression(vector<int> &A){
    vector<int> B = A;
    sort(all(B));
    B.erase(unique(all(B)), B.end());
    for(int i=0; i<A.size(); i++) {
        A[i] = lower_bound(all(B), A[i]) - B.begin();
    }
}
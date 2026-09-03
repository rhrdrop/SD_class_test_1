#include<bits/stdc++.h>
using namespace std;

int main() {
    int x, y, z;
    cin >> x >> y >> z;

    int minV = min({x, y, z});
    int maxV = max({x, y, z});

    cout << maxV - minV << endl;

}
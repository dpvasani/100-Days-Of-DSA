// C++ implementation to set the kth bit
// of the given number
#include <bits/stdc++.h>

using namespace std;

// function to set the kth bit
int setKthBit(int n, int k) {
  // kth bit of n is being set by this operation
  return ((1 << k) | n);
}

// Driver program to test above
int main() {
  int n = 10, k = 2;
  cout << "Kth bit set number = " << setKthBit(n, k);
  return 0;
}

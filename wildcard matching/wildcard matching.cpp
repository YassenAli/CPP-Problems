// Purpose: wildcard matching
// Author: Yassin Ali Mamdouh
// Date: 24 Dec 2023

#include <bits/stdc++.h>

using namespace std;

bool wildcardMatch(const string &filename, const string &pattern) {
    int i = 0, j = 0;    // i for filename and j for pattern
    int starIndex = -1;  // Index of the last '*' encountered in pattern
    int iIndex = -1;     // Index of the last '?' encountered in pattern

    while (i < filename.length()) {
        if (j < pattern.length() && (pattern[j] == '?' || filename[i] == pattern[j])) {
            // Single character match or '?' wildcard
            i++;
            j++;
        } else if (j < pattern.length() && pattern[j] == '*') {
            // '*' wildcard
            starIndex = j++;
            iIndex = i;
        } else if (starIndex != -1) {
            // Retry matching from the position after the last '*'
            j = starIndex + 1;
            i = ++iIndex;
        } else {
            // No match found
            return false;
        }
    }

    // Consume any remaining '*' characters in the pattern
    while (j < pattern.length() && pattern[j] == '*') {
        j++;
    }

    // Check if both filename and pattern have been fully consumed
    return i == filename.length() && j == pattern.length();
}

int main() {
    cout << wildcardMatch("US.txt", "*.*") << endl;  // true
    cout << wildcardMatch("test", "*.*") << endl;   // false
    cout << wildcardMatch("test.h", "test.?") << endl; // true
    cout << wildcardMatch("test.cpp", "test.?") << endl; // false
    cout << wildcardMatch("x", "??*") << endl;     // false
    cout << wildcardMatch("yy", "??*") << endl;     // true
    cout << wildcardMatch("zzz", "??*") << endl;    // true
    return 0;
}

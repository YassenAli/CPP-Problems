// Purpose: Add spaces to string.
// Author: Yassin Ali Mamdouh
// Date: 7 Dec 2023

#include <bits/stdc++.h>

using namespace std;

ifstream dic("dictionary.txt");

bool isInDictionary (string word) {
    string nextWord;
    dic.clear();
    dic.seekg(0, ios::beg);
    while (!dic.eof()) {
        dic >> nextWord;
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word == nextWord)
            return true;
    }
    return false;
}

/*bool isWord(string str) {
    return dictionary.find(str) != dictionary.end();
}*/

// Result store the current prefix with spaces between words
void wordBreakUtil(string str, int n, string result) {
    // Process all prefixes one by one
    for (int i = 1; i <= n; i++) {
        // Extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);

        // If dictionary contains this prefix, then we check
        // for remaining string. Otherwise, we ignore this prefix
        if (isInDictionary(prefix)) {
            // If no remaining string, then print the prefix only
            if (i == n) {
                // Add this element to previous prefix
                result += prefix;
                cout << result << endl; // print result
                return;
            }
            wordBreakUtil(str.substr(i, n - i), n - i, result + prefix + " ");
        }
    }
}

// Function to break the string into words
void wordBreak(string str) {
    wordBreakUtil(str, str.size(), "");
}

int main() {
    cout << "First Test:\n";
    wordBreak("MynameisYassin");

    //////////////////////////////////

    cout << endl << "Second Test:\n";
    wordBreak("letusplayfootballtonight");

    /////////////////////////////////

    cout << endl << "Third Test:\n";
    wordBreak("Iwearmyshoes");

    return 0;
}
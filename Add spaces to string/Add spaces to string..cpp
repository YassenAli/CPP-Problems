// Purpose: Add spaces to string.
// Author: Yassin Ali Mamdouh
// Date: 7 Dec 2023

#include <bits/stdc++.h>

using namespace std;

// Initialize a set with some words for demonstration.
// In a real application, you would populate this set with all English words.
unordered_set<string> dictionary = {"I", "will", "ill", "meet", "me", "you", "tomorrow", "tomrrow", "row", "we", "ar",
                                    "are", "my", "shoes", "wear",
                                    "arm",
                                    "army", "apple", "let", "us", "play", "football", "tonight", "foot", "ball",
                                    "banana", "orange",
                                    "table", "chair", "computer", "window", "door", "book", "pencil", "school", "cat",
                                    "dog", "house", "car", "city", "tree", "flower", "river", "mountain", "sun", "moon",
                                    "star", "sky", "water", "fire", "air", "earth", "ocean", "beach", "park", "friend",
                                    "family", "love", "hate", "happy", "sad", "laugh", "cry", "smile", "frown", "run",
                                    "walk", "jump", "sit", "stand", "sleep", "dream", "eat", "drink", "bread", "cheese",
                                    "milk", "coffee", "tea", "music", "dance", "song", "movie", "play", "game", "work",
                                    "play", "study", "learn", "teach", "write", "read", "draw", "paint", "red", "blue",
                                    "green", "yellow", "black", "white", "day", "night", "morning", "afternoon",
                                    "evening", "today", "tomorrow", "yesterday", "week", "month", "year", "summer",
                                    "winter", "spring", "fall", "hot", "cold", "rain", "snow", "wind", "road", "bridge",
                                    "street", "city"};

void fill_Dictionary() {
    ifstream dic("dictionary.txt");
    string nextWord;
    while (!dic.eof()) {
        dictionary.insert(nextWord);
    }
}

bool isWord(string str) {
    return dictionary.find(str) != dictionary.end();
}

// Result store the current prefix with spaces between words
void wordBreakUtil(string str, int n, string result) {
    // Process all prefixes one by one
    for (int i = 1; i <= n; i++) {
        // Extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);

        // If dictionary contains this prefix, then we check
        // for remaining string. Otherwise we ignore this prefix
        if (isWord(prefix)) {
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
    wordBreak("hallocityfriend");

    //////////////////////////////////

    cout << endl << "Second Test:\n";
    wordBreak("letusplayfootballtonight");

    /////////////////////////////////

    cout << endl << "Third Test:\n";
    wordBreak("Iwearmyshoes");

    return 0;
}
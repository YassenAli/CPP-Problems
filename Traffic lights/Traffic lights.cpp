// Purpose: Traffic lights
// Author: Yassin Ali Mamdouh
// Date: 7 Dec 2023

#include <bits/stdc++.h>

using namespace std;

void generate_traffic_lights(int n, vector<string> so_far) {
    if (n == 0) {
        for(auto color : so_far)
            cout << color << " ";
        cout << endl;
    } else {
        vector<string> colors = {"RED", "GREEN", "YELLOW"};
        for (auto color : colors) {
            vector<string> next = so_far;
            next.push_back(color);
            generate_traffic_lights(n-1, next);
        }
    }
}

int main() {
    int num_of_lights;
    cout << "Enter the number of traffic lights: ";
    cin >> num_of_lights;
    vector<string> sofar;
    generate_traffic_lights(num_of_lights, sofar);
    return 0;
}
// Purpose: converts dates from numerical month/day format to alphabetic month/day
// Author: Yassin Ali Mamdouh
// Date: 24 Dec 2023

#include <bits/stdc++.h>

using namespace std;

class MonthError : public runtime_error {
public:
    MonthError();
};

MonthError::MonthError() : runtime_error("Invalid month number") {}

class DayError : public runtime_error {
public:
    DayError();
};

DayError::DayError() : runtime_error("Invalid day number") {}

string convert_date(int month, int day) {
    string months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    // Check for valid month
    if (month < 1 || month > 12) {
        throw MonthError();
    }

    // Check for valid day based on month
    int max_days = 29; // Always allow 29 days for February
    if (month != 2) {
        max_days = 31;
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            max_days = 30;
        }
    }
    if (day < 1 || day > max_days) {
        throw DayError();
    }

    return months[month - 1] + " " + to_string(day);
}

int main() {
    try {
        int month, day;
        cout << "Enter month (1-12) and day: ";
        cin >> month >> day;

        string date = convert_date(month, day);
        cout << "Date in alphabetic format: " << date << endl;
    }
    catch (const MonthError &e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const DayError &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
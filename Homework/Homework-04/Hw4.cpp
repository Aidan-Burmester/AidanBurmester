// Homework 4: Calendar Display
// Aidan Burmester

#include <iostream>
#include <iomanip>

using namespace std;

// Avoid the leap year pls
bool isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

// Get the number of days in month while accounting for leap years
int getDays(int month, int year) {
    switch (month) {
        case 1: return 31;
        case 2: return isLeap(year) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

// I need to find first day of month
int getStartDay(int month, int year) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int k = year % 100;
    int j = year / 100;

    int h = (1 + (13 * (month + 1)) / 5 + k + k/4 + j/4 + 5*j) % 7;

    // Monday = 0
    return (h + 5) % 7;
}
// Main function to display calendar for a given year
int main() {
    int year;

    cout << "Enter a year: ";
    cin >> year;

    cout << "\nCalendar for " << year << "\n\n";

    for (int month = 1; month <= 12; month++) {

        string monthName;

        switch (month) {
            case 1: monthName = "January"; break;
            case 2: monthName = "February"; break;
            case 3: monthName = "March"; break;
            case 4: monthName = "April"; break;
            case 5: monthName = "May"; break;
            case 6: monthName = "June"; break;
            case 7: monthName = "July"; break;
            case 8: monthName = "August"; break;
            case 9: monthName = "September"; break;
            case 10: monthName = "October"; break;
            case 11: monthName = "November"; break;
            case 12: monthName = "December"; break;
        }

        cout << "-- " << monthName << " " << year << " --\n";
        cout << " Mon  Tue  Wed  Thu  Fri  Sat  Sun\n";

        int startDay = getStartDay(month, year);
        int days = getDays(month, year);

        // Print spacing for first week 
        for (int i = 0; i < startDay; i++) {
            cout << setw(5) << " ";
        }

        // Print days finaly
        for (int day = 1; day <= days; day++) {
            cout << setw(5) << day;

            if ((startDay + day) % 7 == 0)
                cout << endl;
        }

        cout << "\n\n";
    }

    return 0;
}

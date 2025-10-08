#include <iostream>
using namespace std;

// Function to calculate billing amount
double calculateBilling(double hourlyRate, int minutes, bool isLowIncome) {
    double billingAmount = 0.0;

    if (isLowIncome) {
        if (minutes > 30) {
            int extraMinutes = minutes - 30;
            billingAmount = hourlyRate * 0.40 * (extraMinutes / 60.0);
        }
    } else {
        if (minutes > 20) {
            int extraMinutes = minutes - 20;
            billingAmount = hourlyRate * 0.70 * (extraMinutes / 60.0);
        }
    }

    return billingAmount;
}

int main() {
    double hourlyRate;
    int consultingMinutes;
    char incomeStatus;
    bool isLowIncome;

    cout << "Enter hourly rate: ";
    cin >> hourlyRate;

    cout << "Enter total consulting time in minutes: ";
    cin >> consultingMinutes;

    cout << "Does the person have low income? (y/n): ";
    cin >> incomeStatus;

    isLowIncome = (incomeStatus == 'y' || incomeStatus == 'Y');

    double amount = calculateBilling(hourlyRate, consultingMinutes, isLowIncome);

    cout << "Billing amount: $" << amount << endl;

    return 0;
}

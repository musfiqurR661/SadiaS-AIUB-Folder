#include <iostream>

using namespace std;

int main() {
    const double photocopyCharge = 2.35; 
    double discountRate = 0.04;
    int totalPages;
    
    cout << "Enter the number of pages to photocopy: ";
    cin >> totalPages;
    
    double totalCost = 0.0;

    for (int i = 0; i < totalPages; i++) {
        totalCost += photocopyCharge;
    }

    if (totalCost > 100) {
        double discountAmount = totalCost * discountRate;
        totalCost -= discountAmount;
        
        cout << "Total cost after a 4% discount: " << totalCost << " TAKA" << endl;
    } else {
        cout << "Total cost: " << totalCost << " TAKA" << endl;
    }
    
    return 0;
}

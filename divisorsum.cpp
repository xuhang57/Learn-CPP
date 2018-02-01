#include <iostream>
#include <cstdint>
#include <cmath>
// Copyright Lucas Xu

using namespace std;

string divSum(uint64_t num){
    string result;
    string large_result;
    uint64_t num_sum = 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if( num % i == 0) {
            if (i == (num/i)) {
                // result = result + "+" + to_string(i);
                result += "+" + to_string(i);
                num_sum += i;
            } else {
                // result = result + "+" + to_string(i);
                result += "+" + to_string(i);
                num_sum += (i + num/i);
                large_result = "+" + to_string(num/i) + large_result;
            }
        }
    }
    uint64_t sums = num_sum + 1;
    result += (large_result + "=" + to_string(sums));
    result = "1" + result;
    return result;
}

int main() {
    uint64_t x;
    bool cont = true;
    while (cont) {
        cout << "Please enter a number: ";
        cin >> x;
        if (x == 0) {
            cont = false;
            cout << endl;
        }else{
            cout << x << ": " << divSum(x) << "\n";
        }
    }
    return 0;
}

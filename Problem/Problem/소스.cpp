#include <iostream>
#include <vector>
using namespace std;
const int Max = 10001;

int d(int n) {
    int sum = n;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    bool arr[Max] = { false };

    for (int i = 1; i < Max; i++) {
        int idx = d(i);
        if (idx <= 10000) {
            arr[idx] = true;
        }
    }
    for (int i = 1; i < Max; i++) {
        if (!arr[i]) {
            cout << i << "\n";
        }
    }

}
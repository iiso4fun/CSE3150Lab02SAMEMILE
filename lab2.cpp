#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

vector<int> createSequence(int length) {
    vector<int> data(length, 1);
    data.insert(data.end(), length, -1);
    return data;
}

void shuffleSequence(vector<int>& data) {
    random_device rd;
    mt19937 g(rd());
    shuffle(data.begin(), data.end(), g);
}

bool validateBalance(const vector<int>& data) {
    int sum = 0;
    bool hasNegative = false, hasPositive = false;
    
    for (int value : data) {
        sum += value;
        hasNegative |= (sum < 0);
        hasPositive |= (sum > 0);
    }
    return !(hasNegative && hasPositive);
}

double computeBalancedRatio(int size, int trials) {
    int success = 0;
    for (int i = 0; i < trials; ++i) {
        vector<int> data = createSequence(size);
        cout << "Trial " << i + 1 << "\nGenerated: ";
        for (int num : data) cout << num << " ";
        cout << "\n";
        
        shuffleSequence(data);
        cout << "Shuffled: ";
        for (int num : data) cout << num << " ";
        cout << "\n";
        
        if (validateBalance(data)) {
            ++success;
            cout << "Well-balanced!\n";
        } else {
            cout << "Not balanced.\n";
        }
    }
    return static_cast<double>(success) / trials;
}

TEST_CASE("Balanced sequence creation") {
    vector<int> data = createSequence(4);
    CHECK(data.size() == 8);
    CHECK(count(data.begin(), data.end(), 1) == 4);
    CHECK(count(data.begin(), data.end(), -1) == 4);
}

TEST_CASE("Shuffle algorithm consistency") {
    vector<int> data = {1, 1, -1, -1};
    shuffleSequence(data);
    CHECK(count(data.begin(), data.end(), 1) == 2);
    CHECK(count(data.begin(), data.end(), -1) == 2);
}

TEST_CASE("Balance validation") {
    CHECK(validateBalance({1, -1, 1, -1, 1, -1}));
    CHECK(!validateBalance({1, 1, -1, -1, -1, 1}));
    CHECK(validateBalance({1, 1, -1, -1}));
    CHECK(!validateBalance({-1, 1, 1, -1, -1}));
}

int main() {
    doctest::Context context;
    context.run();
    
    srand(time(0));
    int size, trials;
    cout << "Enter sequence size: ";
    cin >> size;
    cout << "Enter number of trials: ";
    cin >> trials;
    
    double ratio = computeBalancedRatio(size, trials);
    cout << "Balanced sequences ratio: " << ratio << endl;
    return 0;
}

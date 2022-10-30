#include <iostream>
#include <fstream>

#include <map>
#include <unordered_map>

#include <vector>
#include <algorithm>

#include <random>
#include <cmath>
#include <chrono>

// multimap
// unordered multimap

int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    // open file
    std::fstream file("results.csv", std::fstream::out);
    file << "n,ordered_time,unordered_time" << std::endl;


    for (int k = 1; k < 8; k++) {
        const size_t n = std::pow(10, k);
        // std::cout << "n: " << n << std::endl;

        // generate vector of length n with numbers 0 to n
        std::vector<int> v(n);
        std::iota(v.begin(), v.end(), 0);

        std::vector<nanoseconds> ordered_times;
        std::vector<nanoseconds> unordered_times;

        // for (int i = 0; i < 7; i++) {
        std::multimap<int, int> mm;

        // timing code adapted from https://stackoverflow.com/a/22387757
        auto t1 = high_resolution_clock::now();
        for (const int x : v) mm.insert({x, x});
        auto t2 = high_resolution_clock::now();

        const auto ordered_time = duration_cast<nanoseconds>(t2 - t1);

        std::unordered_multimap<int, int> um;

        t1 = high_resolution_clock::now();
        for (const int x : v) um.insert({x, x});
        t2 = high_resolution_clock::now();

        const auto unordered_time = duration_cast<nanoseconds>(t2 - t1);

        file << n << "," << ordered_time.count() << "," << unordered_time.count() << std::endl;
        std::cout << n << "," << ordered_time.count() << "," << unordered_time.count() << std::endl;

        // }
    }
    file.close();

}
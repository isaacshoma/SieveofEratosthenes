#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void SieveOfEratosthenes(int n) {

// This program takes in a vector
// We create a vector and assign it with true
// Only if the prime number is n + 1
    vector<bool> prime(n + 1, true);

    // 0 and 1 are not primes
    prime[0] = false;
    prime[1] = false;

    // Iterate through all in the elements
    // Initialize to the smallest prime of 2
    // This is loop will run as long as i * i is less than or equal to n
    // Any numbers greater than or equal to
    for (int i = 2; i * i <= n; i++) {

        // If i is not changed, that means it is a prime
        if (prime[i]) {

            // If the multiple of i is less than i*i, they are marked as composite number
            for (int p = i * i; p <= n; p += i)
                prime[p] = false;
        }
    }

    // Print out all prime numbers
    // When breaks off the previous loop when finished iterating through n
    for (int i = 2; i < n; i++) {
        if (prime[i])
            cout << i << " ";
    }
}

// Driver program to print out results
int main() {


// Use clock to time how long the compiler takes
    clock_t start, end;
    double time_taken;

    // Get the start time
    start = clock();

    int n = 10000;
    SieveOfEratosthenes(n);
    cout << n << endl;

    end = clock();

    // Calculate the CPU time used
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;

    cout << "Time taken by program: " << time_taken << " seconds" << endl;

    return 0;
}


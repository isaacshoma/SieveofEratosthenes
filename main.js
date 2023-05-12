function sieveOfEratosthenes(n) {

    // Initialize all elements to true
    const primes = Array(n + 1).fill(true);

    // 0 and 1 are not primes
    primes[0] = primes[1] = false;

    for (let p = 2; p * p <= n; p++) {
        if (primes[p]) {

            // Mark all multiples of p as not primes
            for (let i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    // Add prime numbers to result array
    // Stores all odd numbers
    const result = [];
    for (let i = 2; i <= n; i++) {
        if (primes[i]) {
            result.push(i);
        }
    }

    // Print results
    console.log(`Prime numbers between 1 and ${n} are: ${result.join(", ")}`);
}

// Call main function
sieveOfEratosthenes(10000);

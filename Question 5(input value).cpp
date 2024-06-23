#include <stdio.h>

// Function to find modulo inverse of a with respect to m using extended Euclid Algorithm
// a*x + m*y = gcd(a, m)
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1) {
        // q is quotient
        q = a / m;
        t = m;

        // m is remainder now, process same as euclid's algo
        m = a % m, a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    // Make x1 positive
    if (x1 < 0)
        x1 += m0;

    return x1;
}

// k is size of num[] and rem[]. Returns the smallest
// number x such that:
// x % num[0] = rem[0],
// x % num[1] = rem[1],
// ..................
// x % num[k-1] = rem[k-1]
// Assumption: Numbers in num[] are pairwise coprime
// (gcd for every pair is 1)
int findMinX(int num[], int rem[], int k) {
    // Compute product of all numbers
    int prod = 1;
    for (int i = 0; i < k; i++)
        prod *= num[i];

    // Initialize result
    int result = 0;

    // Apply above formula
    for (int i = 0; i < k; i++) {
        int pp = prod / num[i];
        result += rem[i] * modInverse(pp, num[i]) * pp;
    }

    return result % prod;
}

int main() {
    int k;
    printf("Enter the number of equations: ");
    scanf("%d", &k);

    int num[k], rem[k];
    for (int i = 0; i < k; i++) {
        printf("Enter modulus (n[%d]): ", i);
        scanf("%d", &num[i]);
        printf("Enter remainder (a[%d]): ", i);
        scanf("%d", &rem[i]);
    }

    printf("The solution x is %d\n", findMinX(num, rem, k));
    return 0;
}

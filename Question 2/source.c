#include <stdio.h>
#include <stdlib.h>





/*
 *  Recursion Based Algorithm
 *  ----------------------------
 *  Description :  - It is used to calculate nth value in the requried recurrence relation
 *  Advantage   :  - It is an Easy method to be implemented
 *  DisAdvantage:  - It may be slow for Large value of n due to huge number of recursive function calls
 */
int recurrenceRecursive(int n) {

    // Base cases
    if (n <= 2) {
        return n;
    }

    // returning value of nth term recursivly
    else
        return recurrenceRecursive(n - 3) + recurrenceRecursive(n - 2);
}





/*
 * Dynamic Programming Approach using Arrays
 * -----------------------------------------
 * Description : - Dynamic programming using arrays provides a way to store the solutions to subproblems and reuse
 *                 them to solve larger problems efficiently
 *               - The function uses an array to store the values of f(i) for i from 0 to n. It iterates from 3 to n,using
 *                 the recurrence relation to compute the value of f(i) and storing it in the array.Finally it returns f(n)
 *
 * Advantage   : - Avoiding recomputation of previously solved subproblems, it can reduce the time complexity of the algorithm.
 *               - This approach has a better time complexity than the recursive approach for computing Fibonacci numbers which
 *                  has an exponential time complexity.
 *
 * Disadvantage: - It requires a lot of memory to store the array of solutions. The space complexity of the algorithm is O(n).
 *               - If n is too large, the program may run out of memory or take too long to allocate and initialize the array.
 */
int recurrenceDP(int n) {

    // Dynamically allocating memory for an integer array
    int* dp = (int*)malloc((n + 1) * sizeof(int));

    // Base Cases
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;

    // Calculating the result of each nth value of reccurence
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 3] + dp[i - 2];
    }

    // Getting Final Result
    int result = dp[n];

    // This line deallocates the memory previously allocated for the ( dp array )
    free(dp);

    return result;
}





/*
 * Iterative implementation
 * -------------------------
 * Description   : - The function first checks for the base cases, and then iteratively computes the value of f(n) using the recurrence relation, storing the intermediate results in variables a, b, and c. Finally,
 *                   it returns the value of f(n).
 *
 * Advantages    : - This method is efficient for computing the Fibonacci numbers, with a time complexity of O(n).
 *                 - The iterative method has a lower space complexity than the dynamic programming approach using arrays
 *                   since it only needs to store three variables instead of an array of n elements.
 *
 * DisAdvantages : - Requires iterating through n values, which can be time-consuming for large values of n.
 *                 - This method may not be easy to generalize to other types of recurrence relations.
 *                 - This method is not suitable for problems that require storing the solutions to subproblems and reusing them,
 *                   as in the case of dynamic programming
 */
int iterativeMethod(int n) {

    // base cases
    if (n <= 2) {
        return n;
    }

    // Initialize variables to store the first 3 numbers and result
    int a = 0, b = 1, c = 2;
    int result;

    // iterating over variables to store the two values and result of each iteration till reaching nth term
    for (int i = 3; i <= n; i++) {
        result = a + b;
        a = b;
        b = c;
        c = result;
    }

    return result;
}





int main() {

    // Initialization inpur variables
    int mode, n;

    printf("To use the Recursive method enter 1, To use the DP method enter 2, To use the iterative method enter 3: ");
    scanf_s("%i", &mode);

    printf("Enter an integer: ");
    scanf_s("%i", &n);

    // Switch statement to call the corresponding function based on user input
    switch (mode) {

    case(1):
        printf("Result = %i", recurrenceRecursive(n));
        break;

    case(2):
        printf("Result = %i", recurrenceDP(n));
        break;

    case(3):
        printf("Result = %i", iterativeMethod(n));
        break;

    default:
        printf("Error");
    }

    // loop to prevent the program from closing immediately
    while (1) {}

    return 0;
}
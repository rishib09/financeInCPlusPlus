#include <iostream>
using namespace std;

/*
Implementing the Gaussian Elimination method, a fundamental algorithm in linear algebra used to solve systems of linear equations of the form:
Ax=b
This is widely used in Quantitative Finance to:
Solve for portfolio weights in mean-variance optimization
Compute sensitivities in risk models
Solve finite-difference PDE systems in option pricing (e.g., Crank-Nicolson schemes)
Linear regression in factor modeling and curve fitting
*/

// Define a custom alias for 'const unsigned short int'
typedef const unsigned short int ushort;

// Set the dimension of the matrix (4x4 system)
ushort dimen = 4;
ushort max_ = 3;

// Define matrix and vector types using fixed-size arrays
typedef double matrix[dimen][dimen];
typedef double vector[dimen];

// Solves Ax = b using Gaussian Elimination
void static GaussianEliminationMethod() {
    // Coefficient matrix A
    matrix A = {
        {10, -1,  2,  0},
        {-1, 11, -1,  3},
        { 2, -1, 10, -1},
        { 0,  3, -1,  8}
    };

    // Right-hand side vector b
    vector b = { 6, 25, -11, 15 };

    // Initialize solution vector x to zeros
    vector x = { 0.0, 0.0, 0.0, 0.0 };

    double pivot, sum;

    // ----------- Forward Elimination Phase -----------
    // Eliminate entries below the diagonal to transform A into an upper triangular matrix
    for (int k = 0; k <= max_ - 1; k++) {
        for (int l = k + 1; l <= max_; l++) {
            // Calculate the pivot factor for row reduction
            /*
            The pivot in Gaussian Elimination is a central concept — it’s what allows us to eliminate entries below the diagonal to transform the system into upper-triangular form.
            The pivot is the value in the current row and column (on the diagonal) that we're using to eliminate elements below it.
            */
            pivot = A[l][k] / A[k][k];

            // Update row l of matrix A
            for (int j = k; j <= max_; j++) {
                A[l][j] -= A[k][j] * pivot;
            }

            // Update the corresponding entry in vector b
            b[l] -= b[k] * pivot;
        }
    }

    // ----------- Backward Substitution Phase -----------
    // Start with the last row and work upwards to solve for x
    x[max_] = b[max_] / A[max_][max_];

    for (int k = max_ - 1; k >= 0; k--) {
        sum = b[k];
        for (int j = k + 1; j <= max_; j++) {
            sum -= x[j] * A[k][j];
        }
        x[k] = sum / A[k][k];
    }

    // ----------- Output Solution -----------
    // Print the solution vector x
    for (int i = 1; i <= dimen; i++) {
        cout << "x[" << i - 1 << "] = " << x[i - 1] << endl;
    }
}

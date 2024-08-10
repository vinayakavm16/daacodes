#include <stdio.h>
#include <limits.h>/*limits.h provides constants like INT_MAX.*/

int MatrixChainOrder(int p[], int n) {//This function computes the minimum number of scalar multiplications needed to multiply a chain of matrices.
    int m[n][n];//m is a 2D array that will store the minimum number of multiplications needed to compute the matrix chain product.
    int i, j, k, l, q;
//n is the number of matrices plus one.
    // Initialize the diagonal values to 0 because the cost of multiplying one matrix is zero
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // l is the chain length//l is the length of the matrix chain being considered.
    for (l = 2; l < n; l++) {//The outer loop iterates over increasing lengths of matrix chains starting from 2 to n-1.
        for (i = 1; i <n ; i++) {//The next loop iterates over the possible starting points of the chain (i).
            j = i + l - 1;//j is the ending point of the chain.
            m[i][j] = INT_MAX;//initializes the current cell to a large value, as we are looking for the minimum.
            for (k = i; k < j ; k++) {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                }
            }
        }
    }

    return m[1][n - 1];
}

int main() {
    int arr[] = {30, 35, 15, 5, 10, 20, 25};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Minimum number of multiplications is %d\n", MatrixChainOrder(arr, size));
    
    return 0;
}

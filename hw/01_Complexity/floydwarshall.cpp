#include <iostream>

// note: C++ does not support multidimensional arrays with dynamic bounds
// this code would require a constant V

const int V = 5;

void floydWarshall(int matrix[V][V]) {
    for (uint32_t k = 0; k < V; k++) {
        for (uint32_t i = 0; i < V; i++) {
            for (uint32_t j = 0; j < V; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
}
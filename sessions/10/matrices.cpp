constexpr int n = 5;

/*
    RAM TIMINGS: RAS CAS
    1.0 2.2 3 ...     1024
    4.5 5.5 6 ...     -1
    7 8 9



*/
void mult(double a[n][n], double b[n][n], double c[n][n]) {

    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            double dot = 0;
            for (int i = 0; i < n; i++)
                dot += a[k][i] * b[i][j];
            c[k][j] = dot;
        }
    }
}


void mult(double a[n][n], double b[n][n], double c[n][n]) {
    double temp[n][n];
    transpose(temp, b);

    for (int k = 0; k < n; k++) {
        for (int j = 0; j < n; j++) {
            double dot = 0;
            for (int i = 0; i < n; i++)
                dot += a[k][i] * temp[j][i];
            c[k][j] = dot;
        }
    }
}

//GPU: 3060  10,000  CPU
// GPU 4090  16,384  CPU

//NVIDIA: goal is to copy data into registers
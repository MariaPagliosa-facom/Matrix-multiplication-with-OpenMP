// mm_seq_naive.cpp  C = A x B, ordem i-j-k
#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;

int main(int argc, char **argv)
{
    int n = (argc >= 2 ? atoi(argv[1]) : 512);
    vector<double> A(n * n), B(n * n), C(n * n);

    // init
    mt19937 rng(42);
    uniform_real_distribution<double> dist(-1.0, 1.0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            A[i*n + j] = dist(rng);
            B[i*n + j] = dist(rng);
            // C não precisa ser zerada aqui: será atribuída com acc no fim
        }

    auto t0 = chrono::high_resolution_clock::now();

    // i-j-k
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            double acc = 0.0;

            for (int k = 0; k < n; ++k)
                acc += A[i * n + k] * B[k * n + j];
            C[i * n + j] = acc;
        }

    auto t1 = chrono::high_resolution_clock::now();
    double secs = chrono::duration<double>(t1 - t0).count();
    
    cout << "n=" << n << "  tempo(s)=" << secs << "\n";
}

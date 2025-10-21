// mm_seq_ikj.cpp  C = A x B, ordem i-k-j (melhor localidade)
#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

int main(int argc, char **argv)
{
    int n = (argc >= 2 ? atoi(argv[1]) : 512);
    vector<double> A(n * n), B(n * n), C(n * n, 0.0);

    // A = i+j ; B = identidade (pra validar fácil: C deve sair igual a A)
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            A[i * n + j] = i + j;
            B[i * n + j] = (i == j) ? 1.0 : 0.0;
        }

    auto t0 = chrono::high_resolution_clock::now();

    // Ordem i-k-j
    for (int i = 0; i < n; ++i)
    {
        const double *Ai = &A[i * n];
        double *Ci = &C[i * n];

        for (int k = 0; k < n; ++k)
        {
            double aik = Ai[k];
            const double *Bk = &B[k * n];
            
            for (int j = 0; j < n; ++j)
                Ci[j] += aik * Bk[j];
        }
    }

    auto t1 = chrono::high_resolution_clock::now();
    double secs = chrono::duration<double>(t1 - t0).count();

    cout << "n=" << n << "  C[0,0]=" << C[0]
         << "  tempo(s)=" << secs << "\n";
    return 0;
}
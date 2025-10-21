// mm_omp2d_tiled.cpp — blocagem 3D; paraleliza grade (iB,jB) com collapse(2)
#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <omp.h>

using namespace std;

int main(int argc, char **argv)
{
    int n = (argc >= 2 ? atoi(argv[1]) : 512);
    int BS = (argc >= 3 ? atoi(argv[2]) : 64);
    vector<double> A(n * n), B(n * n), C(n * n, 0.0);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            A[i * n + j] = i + j;
            B[i * n + j] = (i == j) ? 1.0 : 0.0;
        }

    auto t0 = chrono::high_resolution_clock::now();

    #pragma omp parallel for collapse(2) schedule(static)
    for (int iB = 0; iB < n; iB += BS)
    {
        for (int jB = 0; jB < n; jB += BS)
        {
            int iMax = min(iB + BS, n);
            int jMax = min(jB + BS, n);

            for (int kB = 0; kB < n; kB += BS)
            {
                int kMax = min(kB + BS, n);

                for (int i = iB; i < iMax; ++i)
                {
                    double *Ci = &C[i * n];
                    const double *Ai = &A[i * n];

                    for (int k = kB; k < kMax; ++k)
                    {
                        double aik = Ai[k];
                        const double *Bk = &B[k * n];

                        for (int j = jB; j < jMax; ++j)
                            Ci[j] += aik * Bk[j];
                    }
                }
            }
        }
    }

    auto t1 = chrono::high_resolution_clock::now();
    double secs = chrono::duration<double>(t1 - t0).count();
    
    cout << "n=" << n
         << "  BS=" << BS
         << "  threads=" << omp_get_max_threads()
         << "  C[0,0]=" << C[0]
         << "  tempo(s)=" << secs << "\n";
}

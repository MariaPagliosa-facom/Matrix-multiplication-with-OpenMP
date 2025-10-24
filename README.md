# Multiplicação de Matrizes com OpenMP
Implementações para comparar sequencial, OpenMP 1D com tiling e OpenMP 2D (naive collapse(2) e tiling) na multiplicação densa 𝐶 = 𝐴 × 𝐵 de matrizes 𝑛 × 𝑛 em C/C++.

'''sh
sudo apt install build-essential
'''

**Compilação**  

```sh
make
```

Todos os programas inicializam A[i,j] = i + j, B = I, e reportam tempo(s) apenas do kernel.
Versões com OpenMP respeitam OMP_NUM_THREADS.

#### 1. Sequenciais

```sh
./seq_naive 512
./seq_ikj   512

./seq_naive 1024
./seq_ikj   1024

./seq_naive 2048
./seq_ikj   2048
```
#### Naive + OpenMP 2D
```sh
export OMP_NUM_THREADS=8;  ./omp2d_naive 512
export OMP_NUM_THREADS=16; ./omp2d_naive 1024
```

**Tiling + OpenMP 1D**
```sh
export OMP_NUM_THREADS=8;  ./omp1d_tiled 512 128

export OMP_NUM_THREADS=16; ./omp1d_tiled 1024 64
export OMP_NUM_THREADS=16; ./omp1d_tiled 2048 64
export OMP_NUM_THREADS=16; ./omp1d_tiled 2048 128   # comparar BS
```

**Tiling + OpenMP 2D**
```sh
export OMP_NUM_THREADS=8;  ./omp2d_tiled 512 128

export OMP_NUM_THREADS=16; ./omp2d_tiled 1024 64
export OMP_NUM_THREADS=16; ./omp2d_tiled 2048 64
export OMP_NUM_THREADS=16; ./omp2d_tiled 2048 128   # comparar BS
```

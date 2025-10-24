# Multiplicação de Matrizes com OpenMP
Implementações para comparar sequencial, OpenMP 1D com tiling e OpenMP 2D (naive collapse(2) e tiling) na multiplicação densa 𝐶 = 𝐴 × 𝐵 de matrizes 𝑛 × 𝑛 em C/C++.

'''
sudo apt install build-essential
'''

**Compilação**  

```sh
cd src
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
**Compilar e executar algoritmo sequencial**
```sh
g++ seq_sorting.cpp -o seq_sort

# ordenar 100 mil
./seq_sort 100k.txt 100k_sorted_seq.txt

# ordenar 1 milhão
./seq_sort 1M.txt 1M_sorted_seq.txt

# ordenar 10 milhões
./seq_sort 10M.txt 10M_sorted_seq.txt
```
**Compilar e executar algoritmo paralelo**
```sh
mpic++ -O3 -march=native -funroll-loops -o main.cpp phases.cpp par_sort

# ordenar 100 mil p = 2
mpirun -np 2 ./par_sort 100k.txt 100k_sorted_par2p.txt

# ordenar 1 milhão p = 2
mpirun -np 2 ./par_sort 1M.txt 1M_sorted_par2p.txt

# ordenar 10 milhões p = 2
mpirun -np 2 ./par_sort 10M.txt 10M_sorted_par2p.txt

# ordenar 100 mil p = 4
mpirun -np 4 ./par_sort 100k.txt 100k_sorted_par4p.txt

# ordenar 1 milhão p = 4
mpirun -np 4 ./par_sort 1M.txt 1M_sorted_par4p.txt

# ordenar 10 milhões p = 4
mpirun -np 4 ./par_sort 10M.txt 10M_sorted_par4p.txt

# ordenar 100 mil p = 8
mpirun -np 8 ./par_sort 100k.txt 100k_sorted_par8p.txt

# ordenar 1 milhão p = 8
mpirun -np 8 ./par_sort 1M.txt 1M_sorted_par8p.txt

# ordenar 10 milhões p = 8
mpirun -np 8 ./par_sort 10M.txt 10M_sorted_par8p.txt
```
## Resultados (gráficos)
Os gráficos a seguir mostram os resultados das execuções das linhas acima em um computador equipado com processador Ryzen 9 com 16 núcleos.
![Tempo vs. tamanho](figures/barras_colorido_log_tempo_vs_dataset.png)

### Tempo vs nº de processos
| 100K | 1M | 10M |
|---|---|---|
| <img src="figures/barras_tempo_vs_processos_100K.png" width="300"> | <img src="figures/barras_tempo_vs_processos_1M.png" width="300"> | <img src="figures/barras_tempo_vs_processos_10M.png" width="300"> |
### Speedup vs nº de processos
| 100K | 1M | 10M |
|---|---|---|
| <img src="figures/barras_speedup_vs_processos_100K.png" width="300"> | <img src="figures/barras_speedup_vs_processos_1M.png" width="300"> | <img src="figures/barras_speedup_vs_processos_10M.png" width="300"> |

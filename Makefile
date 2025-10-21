# Makefile
CXX = g++
CXXFLAGS = -O2 -std=c++17
OMPFLAGS = -fopenmp

all: seq_naive seq_ikj omp2d_naive omp1d_tiled omp2d_tiled

seq_naive: mm_seq_naive.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

seq_ikj: mm_seq_ikj.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

omp2d_naive: mm_omp2d_naive.cpp
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) -o $@ $<

omp1d_tiled: mm_omp1d_tiled.cpp
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) -o $@ $<

omp2d_tiled: mm_omp2d_tiled.cpp
	$(CXX) $(CXXFLAGS) $(OMPFLAGS) -o $@ $<

clean:
	rm -f seq_naive seq_ikj omp2d_naive omp1d_tiled omp2d_tiled

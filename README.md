# Matrix Multiplication Examples

- MPI Code Reference: https://gist.github.com/AshanthaLahiru/bfa1a631f6af05af93e98538eeca3018
- OpenMP Code Reference: https://gist.github.com/metallurgix/0dfafc03215ce89fc595
- Explanation: https://www.baeldung.com/cs/matrix-multiplication-algorithms

**Run MPI**

```bash
mpic++ matrix_mpi.cpp -o matrix
mpirun -n 16 ./matrix
```

**Run OpenMP**

```bash
gcc -Wall -g -o mtx matrix_openmp.cpp -fopenmp
./mtx 16
```


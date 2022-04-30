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

## Comandos en Khipu

```
tmux new -s demo

# sesion 1
sbatch --tasks-per-node=32 --nodelist=n003 mpi.sh

## Prueba con dos nodos
sbatch -N 2 --tasks-per-node=32 --nodelist=n002,n003  mpi.sh 

# sesion 2

watch cat mpi_salida.txt

# session 3
ssh n003
htop

# session 4
ssh n004

```

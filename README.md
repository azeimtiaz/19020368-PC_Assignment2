# Parallel Execution of the Rank Sort

This repo contains the necessary files to execute the rank sort both sequentially and parallely. The sequential code given for the assignment ([rankSort_seq.c](https://github.com/azeimtiaz/19020368-PC_Assignment2/blob/main/rankSort_seq.c))  was used for preparing the parallel execution code ([rankSort_par.c](https://github.com/azeimtiaz/19020368-PC_Assignment2/blob/main/rankSort_par.c)) with OpenMP. To accurately evaluate the performance of both programs, a common input array of size 80,000 was generated using a separate program ([generate_array.c](https://github.com/azeimtiaz/19020368-PC_Assignment2/blob/main/generate_array.c)).

## Prerequisites  
- A Linux Environment 
- GCC (11.4.0 or above)

## Generate input array
Compile generation program. By default an array of size 80,000 will be created (Update value of N in all 3 files to change size).

~~~bash  
  gcc generate_array.c -o gen
~~~

Generate array and write to 'input.txt' file

~~~bash  
  ./gen > input.txt
~~~

## Perform Rank Sort Sequencially
Compile 'rankSort_seq.c' with compiler optimization of level 3.

~~~bash  
  gcc rankSort_seq.c -o seq -O3
~~~

Run program and write output to 'seqResults' file

~~~bash  
  ./seq > seqResults
~~~

## Perform Rank Sort Parallely
Compile 'rankSort_par.c' with compiler optimization of level 3. The number of threads is 8 by default. Update value of THREADS to change.

~~~bash  
  gcc rankSort_par.c -o par -O3 -fopenmp
~~~

Run program and write output to 'parResults' file

~~~bash  
  ./par > parResults
~~~

## Check Difference in Execution Time

~~~bash  
  diff seqResults parResults
~~~

#ifndef LAB2_HEADER_INCLUDED
#define LAB2_HEADER_INCLUDED

int** allocate(int const N, int const M);
void initial(int **arr,int const N, int const M);
void printArr(int** Arr,int const N, int const M);
void del(int** arr, int M);
void sorted_column(int **a, int n, int m);
bool find_min(int *a, int *b, int n);

#endif // LAB2_HEADER_INCLUDED

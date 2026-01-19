#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int cmpint(const void *a, const void *b)
{
    const int *ia = a;
    const int *ib = b;
    if (*ia > *ib) {
        return 1;
    }
    if (*ia < *ib) {
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{    
    // Controllo il numero di argomenti
    if (argc != 3) {
        return 1;
    }
    // Creo un vettore vuoto
    int *v = NULL;
    size_t n = 0;
    // Apro il file
    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        return 1;
    }
    // Leggo il contenuto 
    int val;
    while (fscanf(fin, "%i", &val) == 1) {
        // Ho un valore, allora lo aggiungo in coda al vettore
        ++n;
        v = realloc(v, n * sizeof(int));
        v[n - 1] = val;
    }
    // Chiudo il file
    fclose(fin);

    // Ordino il vettore
    qsort(v, n, sizeof(int), cmpint);

    // Creo il nuovo file
    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        return 1;
    }
    // Scrivo i valori su file
    for (size_t i = 0; i < n; ++i) {
        fprintf(fout, "%i\n", v[i]);
    }
    // Chiudo il file
    fclose(fout);
    // Libero la memoria
    free(v);
    return 0;
}
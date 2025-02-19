/* File program : alokasi2.c
Menggunakan fungsi free() untuk membebaskan kembali memory */

#include <stdio.h>
#include <stdlib.h>

main() {
    char *pblok;

    pblok = (char *) malloc(500 * sizeof(char));

    if (pblok == NULL)
        puts("Error on malloc");
    else {
        puts("OK, alokasi memory sudah dilakukan");
        puts("------");
        free(pblok);
        pblok = NULL;
        puts("Blok memory telah dibebaskan kembali");
        puts("dan pointernya sdh di-groundkan");
    }
}
#include <stdio.h>

typedef struct {
    int day, month, year;
} student;

void isYounger (student stud1, student stud2) {
    if (stud1.year < stud2.year) {
        printf ("Student 1 lebih muda");
    } else if (stud1.year > stud2.year) {
        printf ("Student 2 lebih muda");
    } else {
        if (stud1.month < stud2.month) {
            printf ("Student 1 lebih muda");
        } else if (stud1.month > stud2.month) {
            printf ("Student 2 lebih muda");
        } else {
            if (stud1.day < stud2.day) {
                printf ("Student 1 lebih muda");
            } else if (stud1.day > stud2.day) {
                printf ("Student 2 lebih muda");
            } else {
                printf ("Wah, tanggal kelahirannya kembar!");
            }
        }
    }
}

int main () {
    student stud1, stud2;

    //input data student 1
    printf ("Masukkan tanggal student 1: ");
    scanf ("%d", &stud1.day);

    printf ("Masukkan bulan student 1: ");
    scanf ("%d", &stud1.month);

    printf ("Masukkan tahun student 1: ");
    scanf ("%d", &stud1.year);
    //input data student 2
    printf ("Masukkan tanggal student 2: ");
    scanf ("%d", &stud2.day);

    printf ("Masukkan bulan student 2: ");
    scanf ("%d", &stud2.month);

    printf ("Masukkan bulan student 2: ");
    scanf ("%d", &stud2.year);

    isYounger (stud1, stud2);
    return 0;
}

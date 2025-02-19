//#include <stdio.h>
//#include <stdlib.h>

//typedef struct {
 //   int hari, bln, thn;
//} Date;

//int sameDay (Date day1, Date day2) {
  //  day1.hari == day2.hari;
    //day1.bln == day2.bln;
    //day1.thn == day2.thn;

    /*if (day1.thn <= 2024 || day2.thn <= 2024) {
        return 1;
    }
    if (day1.bln > 0 || day2.bln > 0 || day1.bln <=12 || day2.bln <= 12) {
        return 1;
    }
    if (day1.hari > 0 || day1.hari <= 31) {
        return 1;
    }*/
//}

/*int main () {
    Date day1, day2;
    Date bln1, bln2;
    Date year1, year2;

    printf ("Masukkan tanggal day ke 1: ");
    scanf ("%d", &day1);

    printf ("Masukkan tanggal day ke 2: ");
    scanf ("%d", &day2);

    //printf ("Masukkan tanggal day ke 1: ");
    //scanf ("%d", &day1);

    //printf ("Masukkan tanggal day ke 2: ");
    //scanf ("%d", &day2);

    if (sameDay(day1, day2)) {
        printf ("It is the same day\n.");
    } else {
        printf ("It is not the same day\n");
    }
    return 0;
}*/


#include <stdio.h>

typedef struct {
    int hari, bln, thn;
} Date;

int sameDay (Date day1, Date day2) {
    //day1.hari == day2.hari;
    //day1.bln == day2.bln;
    //day1.thn == day2.thn;
    if (day1.hari == day2.hari) {
        printf ("It is the same day\n");
    } else if (day1.bln == day2.bln) {
        printf ("It is the same day\n");
    } else if (day1.thn == day2.thn) {
        printf ("It is the same day\n");
    } else {
        printf ("It is not the same day\n");
    }

    if (day1.bln > 12 || day2.bln > 12) {
        printf ("ERROR! Bulan melebihi jangkauan!");
    }
    if (day1.hari > 31 || day2.hari > 31) {
        printf ("ERROR! Tanggal melebihi jangkauan!");
    } else if (day1.hari == 31 && day1.bln == 2 || day1.bln == 4 || day1.bln == 6 || day1.bln == 9 || day1.bln == 11) {
        printf ("ERROR! Tanggal yang diinput tidak ada pada tanggal tersebut");
    }/*else if (day1.hari == 31 && day1.bln == 2 || day1.bln == 4 || day1.bln == 6 || day1.bln == 9 || day1.bln == 11) {
        printf ("ERROR! Tanggal tidak ada pada bulan tersebut!");
    } */
}

int main () {
    Date day1, day2;
    Date bln1, bln2;
    Date year1, year2;

    //input data day1
    printf ("Masukkan tanggal day1 (2 angka): ");
    scanf ("%d", &day1);

    printf ("Masukkan bulan day1 (2 angka): ");
    scanf ("%d", &bln1);

    printf ("Masukkan tahun day1 (4 angka): ");
    scanf ("%d", &year1);

    //input data day2
    printf ("Masukkan tanggal day2 (2 angka): ");
    scanf ("%d", &day2);

    printf ("Masukkan bulan day2 (2 angka): ");
    scanf ("%d", &bln2);

    printf ("Masukkan tahun day2 (4 angka): ");
    scanf ("%d", &year2);

    sameDay (day1, day2);
    return 0;
}

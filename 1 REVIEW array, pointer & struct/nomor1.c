// Bismillahirrahmanirrahim
// 19 February 2024; review materi struct, array, dan pointer

#include <stdio.h>

struct student {
    int tugas, uts, uas, akhir;
    char nama[256], grade;
};

void input (struct student mhs[], int jmlmhs) {

    printf ("\nMasukkan DATA Mahasiswa\n");

    for (int i = 0; i < jmlmhs; i++) {
        printf("\n\nMahasiswa ke %d\n", i + 1);

        printf("\nNama: ");
        scanf("%s", mhs[i].nama);
        //gets (mhs[i].nama);
        //fgets (mhs[i].nama, sizeof mhs[i].nama, stdin);

        printf("\nNilai tugas: ");
        scanf("%d", &mhs[i].tugas);

        printf("\nNilai UTS: ");
        scanf("%d", &mhs[i].uts);

        printf("\nNilai UAS: ");
        scanf("%d", &mhs[i].uas);
    }
}

void tampil (struct student mhs[], int jmlmhs) {

    printf("\n\t\tDAFTAR NILAI\t\t\n");
    printf("\tMATAKULIAH KONSEP PEMROGRAMAN\t\n");
    printf("------------------------------------------------------\n");
    printf("Nama Mahasiswa\t Tugas\t UTS\t UAS\t Akhir\t Grade\n");
    printf("------------------------------------------------------\n");

    for (int i = 0; i < jmlmhs; i++) {
        mhs[i].akhir = (0.2 * mhs[i].tugas) + (0.4 * mhs[i].uts) + (0.4 * mhs[i].uas);

        if (mhs[i].akhir >= 80) {
            mhs[i].grade = 'A';
        } else if (mhs[i].akhir >= 70) {
            mhs[i].grade = 'B';
        } else if (mhs[i].akhir >= 60) {
            mhs[i].grade = 'C';
        } else if (mhs[i].akhir >= 50) {
            mhs[i].grade = 'D';
        } else {
            mhs[i].grade = 'E';
        }
        printf("%s\t\t %d\t %d\t %d\t %d\t %c\t\n", mhs[i].nama, mhs[i].tugas, mhs[i].uts, mhs[i].uas, mhs[i].akhir, mhs[i].grade);
    }

    printf("\n------------------------------------------------------\n");
    printf("Total Mahasiswa = %d\n", jmlmhs);
}

int main() {
    int jmlmhs;

    printf("\n\t\tMENGHITUNG NILAI AKHIR");
    printf("\n\t    MATA KULIAH KONSEP PEMROGRAMAN");

    printf("\nBerapa jumlah mahasiswa? ");
    scanf("%d", &jmlmhs);

    struct student datamhs[jmlmhs];

    input (datamhs, jmlmhs);
    tampil (datamhs, jmlmhs);

    return 0;
}

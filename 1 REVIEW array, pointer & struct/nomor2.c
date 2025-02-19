/*#include <stdio.h>

struct kantor {
    int id, tala, gajiperbln;
    char nama[256], gender;
};

void input (struct kantor pegawai[], int jmlpegawai) {
    for (int i = 0; i < jmlpegawai; i++) {
        printf ("\nData pegawai ke-%d", i + 1);

        printf ("\nNama\t: ");
        scanf ("%c", pegawai[i].nama);

        printf ("\nTgl Lahir (dd-mm-yyyy)\t: ");
        scanf ("%d", &pegawai[i].tala);

        printf ("\nJenis Kelamin (L/P)\t: ");
        scanf ("%c", &pegawai[i].gender);

        printf ("\nGaji per bulan\t: ");
        scanf ("%d", &pegawai[i].gajiperbln);
    }
}

void tampil (struct kantor pegawai[], int jmlpegawai) {
    printf ("\nData pegawai yang telah diinputkan");

    for (int i = 0; i < jmlpegawai; i++) {
        printf ("\nNo id\t: %d", pegawai[i].id);
        printf ("\nNama\t: %c", pegawai[i].nama);
        printf ("\nTgl lahir\t: %d", pegawai[i].tala);
        printf ("\nJenis Kelamin\t: %c", pegawai[i].gender);
        printf ("\nGaji/bulan\t: %d", pegawai[i].gajiperbln);
    }
}

int main () {
    int jmlpegawai;

    printf ("\t\tDATA PEGAWAI\t\t");

    printf ("\nBerapa jumlah pegawai? ");
    scanf ("%d", &jmlpegawai);

    struct kantor datapegawai[jmlpegawai];

    input (datapegawai, jmlpegawai);
    tampil (datapegawai, jmlpegawai);

    return 0;
} */


// penggunaan typedef
#include <stdio.h>

typedef struct {
    int id, tgllhr, blnlhr, thnlhr;
    char nama[256], gender;
    float gajiperbln;
} kantor;

void input(kantor *pegawai, int jmlpegawai) {

    for (int i = 0; i < jmlpegawai; i++) {
        printf("\nData pegawai ke-%d\n", i + 1);

        printf("\nNama: ");
        //fgets(pegawai[i].nama, sizeof(pegawai[i].nama), stdin);
        scanf("%s", pegawai[i].nama);

        printf("Tanggal Lahir (dd): ");
        scanf("%d", &pegawai[i].tgllhr);

        printf("Bulan Lahir (mm): ");
        scanf("%d", &pegawai[i].blnlhr);

        printf("Tahun Lahir (yyyy): ");
        scanf("%d", &pegawai[i].thnlhr);

        /*if (*pegawai[i].thnlhr < 2024) {
            return 1;
        } else {
            return 0;
        }*/

        printf("Jenis Kelamin (L/P) : ");
        scanf(" %c", &pegawai[i].gender);

        /*if (*pegawai[i].gender == 'L' || *pegawai[i]. gender == 'P') {
            return 1;
        } else {
            return 0;
        }*/
        printf("Gaji per bulan: ");
        scanf("%f", &pegawai[i].gajiperbln);
    }
}

void tampil(kantor *pegawai, int jmlpegawai) {
    printf("\nData pegawai yang telah diinputkan\n");

    for (int i = 0; i < jmlpegawai; i++) {
        printf("\nNo ID pegawai: %d\n", i + 1);
        printf("Nama: %s\n", pegawai[i].nama);
        printf("Tanggal lahir: %d-%d-%d\n", pegawai[i].tgllhr, pegawai[i].blnlhr, pegawai[i].thnlhr);
        printf("Jenis Kelamin: %c\n", pegawai[i].gender);
        printf("Gaji/bulan: Rp %.2f\n", pegawai[i].gajiperbln);
    }
}

int main() {
    int jmlpegawai;

    printf("\t\tDATA PEGAWAI\t\t");

    printf("\nBerapa jumlah pegawai? ");
    scanf("%d", &jmlpegawai);

    kantor datapegawai[jmlpegawai];

    input(datapegawai, jmlpegawai);
    tampil(datapegawai, jmlpegawai);

    return 0;
}

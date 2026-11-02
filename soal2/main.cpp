#include "Buku.h"

int main() {
    List L;
    infotype x, cari;
    address P;
    bool ada;

    CreateList(L);

    for (int i = 0; i < 4; i++) {
        cout << "Masukkan kode buku: ";
        cin >> x.kodeBuku;

        cout << "Masukkan judul buku: ";
        cin >> x.judul;

        cout << "Masukkan tahun terbit: ";
        cin >> x.thnTerbit;

        P = L.First;
        ada = false;

        while (P != NULL) {
            if (P->info.kodeBuku == x.kodeBuku) {
                ada = true;
                break;
            }
            P = P->next;
        }

        if (ada) {
            cout << "Kode buku sudah terdaftar!" << endl;
        } else {
            insertLast(L, alokasi(x));
        }

        cout << endl;
    }

    cout << "Masukkan kode buku yang dicari: ";
    cin >> cari.kodeBuku;

    P = findElm(L, cari);

    if (P != NULL) {
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Buku tidak ditemukan!" << endl;
    }

    return 0;
}

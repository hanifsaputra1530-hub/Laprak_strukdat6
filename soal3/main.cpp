#include "Buku.h"

int main() {
    List L;
    infotype x, cari;
    address P, Prec;
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

    cout << "Masukkan kode buku yang akan dihapus: ";
    cin >> cari.kodeBuku;

    P = findElm(L, cari);

    if (P != NULL) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            Prec = L.First;

            while (Prec->next != P) {
                Prec = Prec->next;
            }

            deleteAfter(Prec, P);
        }

        dealokasi(P);
        cout << "Data dengan kode buku " << cari.kodeBuku
             << " berhasil dihapus." << endl;
    } else {
        cout << "Kode buku tidak ditemukan!" << endl;
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}

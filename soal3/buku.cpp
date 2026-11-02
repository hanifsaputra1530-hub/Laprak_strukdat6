#include "Buku.h"

void CreateList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    }else {
        P->prev = L.Last;
        L.Last->next = P;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last;

    while(P != NULL) {
        cout << "Kode buku : " << P->info.kodeBuku << endl;
        cout << "Judul buku : " << P->info.judul << endl;
        cout << "Tahun terbit : " << P->info.thnTerbit << endl;
        P = P->prev;
    }
}


address findElm(List L, infotype x) {
    address P = L.First;

    while (P != NULL) {
        if (P->info.kodeBuku == x.kodeBuku) {
            return P;
        }
        P = P->next;
    }

    return NULL;
}

void deleteFirst(List &L, address &P) {
    P = L.First;
    L.First = P->next;

    if (L.First == NULL) {
        L.Last = NULL;
    } else {
        L.First->prev = NULL;
    }

    P->next = NULL;
}

void deleteLast(List &L, address &P) {
    P = L.Last;
    L.Last = P->prev;

    if (L.Last == NULL) {
        L.First = NULL;
    } else {
        L.Last->next = NULL;
    }

    P->prev = NULL;
}

void deleteAfter(address Prec, address &P) {
    P = Prec->next;
    Prec->next = P->next;

    if (P->next != NULL) {
        P->next->prev = Prec;
    }

    P->next = NULL;
    P->prev = NULL;
}

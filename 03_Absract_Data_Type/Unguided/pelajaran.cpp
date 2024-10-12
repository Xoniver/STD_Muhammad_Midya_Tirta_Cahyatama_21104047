#include "pelajaran.h"
#include <iostream>

using namespace std;

// implement createPelajaran
pelajaran createPelajaran(string namaMapel, string kodeMapel) {
    pelajaran pelajaran;
    pelajaran.namaMapel = namaMapel;
    pelajaran.kodeMapel = kodeMapel;

    return pelajaran;
}

// implement showPelajaran
void showPelajaran(pelajaran pelajaran) {
    cout << "Nama Mapel: " << pelajaran.namaMapel << endl;
    cout << "Kode Mapel: " << pelajaran.kodeMapel << endl;
}
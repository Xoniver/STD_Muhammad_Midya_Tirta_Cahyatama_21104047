#include "pelajaran.h"
#include <iostream>

using namespace std;

int main() {
    string namaMapel = "Struktur Data"; 
    string kodeMapel = "STD";

    // create pelajaran
    pelajaran pelajaran1 = createPelajaran(namaMapel, kodeMapel);

    // show pelajaran
    showPelajaran(pelajaran1);

    return 0;
}
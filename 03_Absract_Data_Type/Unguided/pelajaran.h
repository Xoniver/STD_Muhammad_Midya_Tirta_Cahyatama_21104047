#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

// mendifinisikan pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

// membuat pelajaran
pelajaran createPelajaran(string namaMapel, string kodeMapel);

// show data pelajaran
void showPelajaran(pelajaran pelajaran);

#endif
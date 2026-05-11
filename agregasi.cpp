#include <iostream>
#include <string>
using namespace std;

#include "anak.h"
#include "ibu.h"

int main() {
    ibu* varIbu = new ibu("dini");
    anak* varAnak1 = new anak("ono");
    anak* varAnak2 = new anak("ratu");

    varIbu->tambahAnak(varAnak1);
    varIbu->tambahAnak(varAnak2);

    varIbu->cetakAnak();

    delete varIbu;
    delete varAnak1;
    delete varAnak2;

    return 0;
}
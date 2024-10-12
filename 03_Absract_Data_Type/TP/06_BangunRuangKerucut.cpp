#include <iostream>
#include <cmath> 
using namespace std;

// Definisi ADT Kerucut
class Kerucut {
private:
    double radius; // Jari-jari alas 
    double tinggi; // Tinggi

public:
    Kerucut(double r, double t) {
        radius = r;
        tinggi = t;
    }

    double luasAlas() const {
        return M_PI * radius * radius;
    }

    double luasSelimut() const {
        double s = sqrt((radius * radius) + (tinggi * tinggi));
        return M_PI * radius * s;
    }

    double luasPermukaan() const {
        return luasAlas() + luasSelimut();
    }

    double volume() const {
        return (1.0 / 3.0) * luasAlas() * tinggi;
    }

    void show() const {
        cout << "Jari-jari alas: " << radius << endl;
        cout << "Tinggi: " << tinggi << endl;
        cout << "Luas alas: " << luasAlas() << " satuan luas" << endl;
        cout << "Luas selimut: " << luasSelimut() << " satuan luas" << endl;
        cout << "Luas permukaan: " << luasPermukaan() << " satuan luas" << endl;
        cout << "Volume: " << volume() << " satuan volume" << endl;
    }
};

int main() {
    // Membuat objek kerucut
    Kerucut kerucut1(5, 12);

    kerucut1.show();

    return 0;
}

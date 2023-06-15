#include <iostream>
using namespace std;

struct kompleks {
    int reel = 0;
    int img = 0;
};

void kompleksSayiYaz(kompleks k) {
    cout << k.reel;
    if (k.img >= 0) {
        cout << "+";
    }
    cout << k.img << "i" << endl;
}

kompleks kompleksTopla(kompleks s1, kompleks s2) {
    kompleks toplam;
    toplam.reel = s1.reel + s2.reel;
    toplam.img = s1.img + s2.img;
    return toplam;
}

int main() {
    kompleks k1;
    k1.reel = 2;
    k1.img = 3;
    kompleks k2;
    k2.reel = 5;
    k2.img = -8;
    kompleksSayiYaz(kompleksTopla(k1, k2));
    return 0;
}
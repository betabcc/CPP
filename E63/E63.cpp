#include <iostream>

struct Dugum {
    int veri;
    Dugum* sol;
    Dugum* sag;
};

Dugum* yeniDugumOlustur(int veri) {
    Dugum* yeniDugum = new Dugum();
    
    if (yeniDugum != nullptr) {
        yeniDugum->veri = veri;
        yeniDugum->sol = yeniDugum->sag = nullptr;
    }
    
    return yeniDugum;
}

Dugum* dugumEkle(Dugum* kok, int veri) {
    if (kok == nullptr) {
        kok = yeniDugumOlustur(veri);
    } else if (veri <= kok->veri) {
        kok->sol = dugumEkle(kok->sol, veri);
    } else {
        kok->sag = dugumEkle(kok->sag, veri);
    }
    
    return kok;
}

Dugum* enBuyuguBul(Dugum* kok) {
    while (kok->sag != nullptr) {
        kok = kok->sag;
    }
    
    return kok;
}

Dugum* sil(Dugum* kok, int veri) {
    if (kok == nullptr) return kok;
    
    else if (veri < kok->veri) kok->sol = sil(kok->sol, veri);
    
    else if (veri > kok->veri) kok->sag = sil(kok->sag, veri);
    
    else {
        if (kok->sol == nullptr && kok->sag == nullptr) {
            delete kok;
            kok = nullptr;
        }
        else if (kok->sol == nullptr) {
            Dugum *gecici = kok;
            kok = kok->sag;
            delete gecici;
        }
        else if (kok->sag == nullptr) {
            Dugum *gecici = kok;
            kok = kok->sol;
            delete gecici;
        }
        else {
            Dugum *gecici = enBuyuguBul(kok->sol);
            kok->veri = gecici->veri;
            kok->sol = sil(kok->sol, gecici->veri);
        }
    }
    
    return kok;
}

void inorder(Dugum* kok) {
    if (kok == nullptr) return;
    
    inorder(kok->sol);
    std::cout << kok->veri << " ";
    inorder(kok->sag);
}

int main() {
    Dugum* kok = nullptr;
    kok = dugumEkle(kok, 9);
    kok = dugumEkle(kok, 6);
    kok = dugumEkle(kok, 4);
    kok = dugumEkle(kok, 8);
    kok = dugumEkle(kok, 7);
    kok = dugumEkle(kok, 12);
    kok = dugumEkle(kok, 11);
    kok = dugumEkle(kok, 33);
    kok = dugumEkle(kok, 88);
    std::cout << "SILME ISLEMINDEN ONCE: ";
    inorder(kok);
    std::cout << "\n";
    kok = sil(kok, 9);
    std::cout << "SILME ISLEMINDEN SONRA: ";
    inorder(kok);
    std::cout << "\n";
    return 0;
}
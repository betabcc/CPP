#include <iostream>
#include <string>
using namespace std;

struct Il {
    int plakaNo;
    string isim;
    Il* next;
};

void ilEkle(Il** head, int plakaNo, string isim) {
    Il* yeniIl = new Il;
    yeniIl->plakaNo = plakaNo;
    yeniIl->isim = isim;
    yeniIl->next = NULL;

    if (*head == NULL) {
        *head = yeniIl;
        return;
    }

    Il* current = *head;
    Il* prev = NULL;

    while (current != NULL && current->plakaNo < yeniIl->plakaNo) {
        prev = current;
        current = current->next;
    }

    if (prev == NULL) {
        yeniIl->next = *head;
        *head = yeniIl;
    } else if (current == NULL) {
        prev->next = yeniIl;
    } else {
        prev->next = yeniIl;
        yeniIl->next = current;
    }
}

void listeYazdir(Il* head) {
    while (head != NULL) {
        cout << head->plakaNo << " " << head->isim << endl;
        head = head->next;
    }
}

int main() {
    Il* head = NULL;
    ilEkle(&head, 34, "Istanbul");
    ilEkle(&head, 6, "Ankara");
    ilEkle(&head, 1, "Adana");
    ilEkle(&head, 35, "Izmir");
	ilEkle(&head, 16, "Bursa");
	ilEkle(&head, 23, "Elazig");
	ilEkle(&head, 52, "Ordu");
	ilEkle(&head, 67, "Zonguldak");
	ilEkle(&head, 44, "Malatya");
	ilEkle(&head, 17, "Canakkale");
	ilEkle(&head, 46, "Kahramanmaras");
	ilEkle(&head, 7, "Antalya");
	ilEkle(&head, 77, "Yalova");
	ilEkle(&head, 66, "Yozgat");
	ilEkle(&head, 42, "Konya");
	ilEkle(&head, 26, "Eskisehir");
	ilEkle(&head, 38, "Kayseri");
	ilEkle(&head, 68, "Aksaray");
	ilEkle(&head, 11, "Bilecik");
	ilEkle(&head, 58, "Sivas");
	ilEkle(&head, 41, "Kocaeli");
	ilEkle(&head, 72, "Batman");
	ilEkle(&head, 20, "Denizli");
	ilEkle(&head, 75, "Ardahan");
	ilEkle(&head, 55, "Samsun");
	ilEkle(&head, 22, "Edirne");
	ilEkle(&head, 53, "Rize");
	ilEkle(&head, 33, "Mersin");
	ilEkle(&head, 63, "Sanliurfa");
	ilEkle(&head, 36, "Kars");
	ilEkle(&head, 32, "Isparta");
	ilEkle(&head, 71, "Kirikkale");
	ilEkle(&head, 39, "Kirklareli");
	ilEkle(&head, 12, "Bingol");
	ilEkle(&head, 10, "Balikesir");
	ilEkle(&head, 31, "Hatay");
	ilEkle(&head, 14, "Bolu");
	ilEkle(&head, 60, "Tokat");
	ilEkle(&head, 64, "Usak");
	ilEkle(&head, 18, "Cankiri");
	ilEkle(&head, 50, "Nevsehir");
	ilEkle(&head, 5, "Amasya");
	ilEkle(&head, 21, "Diyarbakir");
	ilEkle(&head, 59, "Tekirdag");
	ilEkle(&head, 45, "Manisa");
	ilEkle(&head, 24, "Erzincan");
	ilEkle(&head, 8, "Artvin");
	ilEkle(&head, 19, "Corum");
	ilEkle(&head, 70, "Karaman");
	ilEkle(&head, 48, "Mugla");
	ilEkle(&head, 51, "Nigde");
	ilEkle(&head, 25, "Erzurum");
	ilEkle(&head, 61, "Trabzon");
	ilEkle(&head, 9, "Aydin");
	ilEkle(&head, 57, "Sinop");
	ilEkle(&head, 65, "Van");
	ilEkle(&head, 28, "Giresun");
	ilEkle(&head, 4, "Agri");
	ilEkle(&head, 40, "Kirsehir");
	ilEkle(&head, 47, "Mardin");
	ilEkle(&head, 27, "Gaziantep");
	ilEkle(&head, 80, "Osmaniye");
	ilEkle(&head, 3, "Afyonkarahisar");
	ilEkle(&head, 73, "Sirnak");
	ilEkle(&head, 30, "Hakkari");
	ilEkle(&head, 62, "Tunceli");
	ilEkle(&head, 37, "Kastamonu");
	ilEkle(&head, 13, "Bitlis");
	ilEkle(&head, 43, "Kutahya");
	ilEkle(&head, 49, "Mus");
	ilEkle(&head, 78, "Karabuk");
	ilEkle(&head, 79, "Kilis");
	ilEkle(&head, 81, "Duzce");
	ilEkle(&head, 76, "Igdir");
	ilEkle(&head, 2, "Adiyaman");
	ilEkle(&head, 69, "Bayburt");
	ilEkle(&head, 15, "Burdur");
	ilEkle(&head, 29, "Gumushane");
	ilEkle(&head, 54, "Sakarya");
	ilEkle(&head, 56, "Siirt");
	ilEkle(&head, 74, "Bartin");
    listeYazdir(head);
    return 0;
}
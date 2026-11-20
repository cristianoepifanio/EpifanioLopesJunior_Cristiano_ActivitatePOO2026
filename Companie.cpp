
#include <iostream>
#include <cstring>
using namespace std;

class Companie {
private:
    char* numeCompanie;
    const int idCompanie;
    double cifraAfaceri;

public:
    // Constructor default
    Companie() : idCompanie(0) {
        numeCompanie = nullptr;
        cifraAfaceri = 0;
    }

    // Constructor cu un parametru
    Companie(int id) : idCompanie(id) {
        numeCompanie = nullptr;
        cifraAfaceri = 0;
    }

    // Constructor de copiere
    Companie(const Companie& c) : idCompanie(c.idCompanie) {
        numeCompanie = nullptr;
        cifraAfaceri = c.cifraAfaceri;
        setNumeCompanie(c.numeCompanie);
    }

    // Getter pentru ID
    int getIdCompanie() const {
        return idCompanie;
    }

    // Setter pentru nume
    void setNumeCompanie(const char* nume) {
        char* numeNou = nullptr;

        if (nume != nullptr) {
            numeNou = new char[strlen(nume) + 1];
            strcpy(numeNou, nume);
        }

        delete[] numeCompanie;
        numeCompanie = numeNou;
    }

    // Setter pentru cifra de afaceri
    void setCifraAfaceri(double cifra) {
        if (cifra >= 0) {
            cifraAfaceri = cifra;
        }
    }

    // Operator =
    Companie& operator=(const Companie& c) {
        if (this != &c) {
            setNumeCompanie(c.numeCompanie);
            cifraAfaceri = c.cifraAfaceri;
        }
        return *this;
    }

    // Metoda de afisare
    void afisare() const {
        cout << "\nID Companie: " << idCompanie << endl;
        cout << "Nume Companie: "
             << (numeCompanie != nullptr ? numeCompanie : "Nedefinit")
             << endl;
        cout << "Cifra de afaceri: " << cifraAfaceri << " RON" << endl;
        cout << "------------------------" << endl;
    }

    // Destructor
    ~Companie() {
        delete[] numeCompanie;
    }
};

int main(void) {

    // Test constructor default
    Companie c1;
    cout << "Compania 1 - Default" << endl;
    c1.afisare();

    // Test constructor cu un parametru
    Companie c2(101);
    c2.setNumeCompanie("Amazon Romania");
    c2.setCifraAfaceri(1500000);

    cout << "Compania 2" << endl;
    c2.afisare();

    // Test getter
    cout << "ID compania 2: "
         << c2.getIdCompanie() << endl;

    // Test alta companie
    Companie c3(102);
    c3.setNumeCompanie("Microsoft Romania");
    c3.setCifraAfaceri(2300000);

    cout << "\nCompania 3" << endl;
    c3.afisare();

    // Test operator =
    c3 = c2;

    cout << "Compania 3 dupa operatorul =" << endl;
    c3.afisare();

    // Test constructor de copiere
    Companie c4(c2);

    cout << "Compania 4 - Copie" << endl;
    c4.afisare();

    // Test modificare nume
    c4.setNumeCompanie("Google Romania");
    c4.setCifraAfaceri(3000000);

    cout << "Compania 4 dupa modificare" << endl;
    c4.afisare();

    return 0;
}

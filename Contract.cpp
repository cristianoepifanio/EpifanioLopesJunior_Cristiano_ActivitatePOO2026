#include <iostream>
#include <cstring>
using namespace std;

class Contract {
    char* numeClient;
    const int nrContract;
    double valoareContract;
public:
    // constructor default
    Contract() : nrContract(0) {
        numeClient = nullptr;
        valoareContract = 0;
    }

    // constructor cu parametru
    Contract(int nr) : nrContract(nr) {
        numeClient = nullptr;
        valoareContract = 0;
    }

    // constructor de copiere
    Contract(const Contract& c) : nrContract(c.nrContract) {
        numeClient = nullptr;
        valoareContract = c.valoareContract;
        setNumeClient(c.numeClient);
    }

    // getter pentru nrContract
    int getNrContract() const {
        return nrContract;
    }

    // setter pentru numeClient
    void setNumeClient(const char* nume) {
        char* numeNou = nullptr;
        if (nume != nullptr) {
            numeNou = new char[strlen(nume) + 1];
            strcpy(numeNou, nume);
        }
        delete[] numeClient;
        numeClient = numeNou;
    }

    // setter pentru valoareContract
    void setValoareContract(double valoare) {
        if (valoare >= 0) {
            valoareContract = valoare;
        }
    }

    //destructor
    ~Contract() {
        delete[] numeClient;
    }
    
    // operator =
    Contract& operator=(const Contract& c) {
        if (this != &c) {
            setNumeClient(c.numeClient);
            valoareContract = c.valoareContract;
        }
        return *this;
    }
    // metoda de afisare
    void afisare() const {
        cout << "\nNumar contract: " << nrContract << endl;
        cout << "Nume client: "
             << (numeClient != nullptr ? numeClient : "FARA CLIENT")
             << endl;
        cout << "Valoare contract: " << valoareContract << " RON" << endl;
        cout << "------------------------" << endl;
    }
};

int main(void) {
    // teste default
    Contract c1;
    cout << "Contract default este: \n";
    c1.afisare();
    // teste cu parametru
    Contract c2(101);
    c2.setNumeClient("Ionut Tepes");
    c2.setValoareContract(376478.98);
    cout << "Contract cu parametrul este: \n";
    c2.afisare();

    // teste de copiere
    Contract c3(c2);
    c3.setNumeClient("Diana Eminescu");
    c3.setValoareContract(9873625.67);
    cout << "Contract copiat este: \n";
    c3.afisare();

    // teste de operator =
    c1 = c2;
    cout << "Contract modificat cu operatorul = este: \n";
    c1.afisare();

    return 0;
}
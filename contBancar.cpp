/*Se consideră o aplicație informatică pentru gestiunea domeniului ContBancar, cu atributele:
- nume titular (char*)
- număr cont (nemodificabil)
- sold cont (double)
Se va încărca pe online.ase.ro doar un fișier .cpp cu numele Nr1_Nume_Prenume1_Prenume2_T1.cpp. În caz contrar, -2p.

Definiți o clasă în limbajul C++, care va fi utilizată în cadrul acestei aplicații.

Atributele clasei sunt definite corespunzător. (1p)

Implementați următoarele metode:
- constructorul cu un parametru și constructorul default (2p)
- metoda get pentru atributul constant (1p)
- metoda set pentru atributul alocat dinamic (2p)
- operatorul = (2p)
- o metodă de afișare a atributelor (1p)
Cerințe de predare:
1. În funcția main() se testează toate apelurile metodelor implementate în clasă. Exercițiile NETESTATE NU SE PUNCTEAZĂ.
2. Aplicația nu generează memory leaks (-1p în caz contrar).*/

#include <iostream>
#include <cstring>

using namespace std;

class ContBancar
{
private:
    char *numeTitular;
    const int numarCont;
    double soldCont;

public:
    // Constructor default
    ContBancar() : numarCont(0)
    {
        numeTitular = nullptr;
        soldCont = 0;
    }

    // Constructor cu un parametru
    ContBancar(int id) : numarCont(id)
    {
        numeTitular = nullptr;
        soldCont = 0;
    }

    // Constructor de copier
    ContBancar(const ContBancar &cont) : numarCont(cont.numarCont)
    {
        numeTitular = nullptr;
        soldCont = cont.soldCont;
        setNumeTitular(cont.numeTitular);
    }

    // getter pentru numarCont
    int getNumarCont() const
    {
        return numarCont;
    }

    // setter pentru numeTitular
    void setNumeTitular(const char *nume)
    {
        char *nouTitular = nullptr;
        if (nume != nullptr)
        {
            nouTitular = new char[strlen(nume) + 1];
            strcpy(nouTitular, nume);
        }
        delete[] numeTitular;
        numeTitular = nouTitular;
    }

    // setter pentru soldCont
    void setSoldCont(double sold)
    {
        if (sold >= 0)
        {
            soldCont = sold;
        }
    }
    // Destructor
    ~ContBancar()
    {
        delete[] numeTitular;
    }
    // operator =
    ContBancar &operator=(const ContBancar &c)
    {
        if (this != &c)
        {
            setNumeTitular(c.numeTitular);
            soldCont = c.soldCont;
        }

        return *this;
    }

    // metoda de afisare
    void afisare() const
    {
        cout << "\nNume titular: " << (numeTitular != nullptr ? numeTitular : "FARA TITULAR") << endl;
        cout << "Numar bancar: " << numarCont << endl;
        cout << "Sold bancar: " << soldCont << " RON" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << endl;
    }
};

int main(void)
{

    // test constructor default
    ContBancar cont1;
    cout << "Cont bancar defaut" << endl;
    cont1.afisare();

    // User 1
    ContBancar cont2(2);
    cont2.setNumeTitular("Ionut Tepes");
    cont2.setSoldCont(376478.98);
    cout << "Cont bancar cu parametru" << endl;
    cont2.afisare();

    // User 2
    ContBancar cont3(3);
    cont3.setNumeTitular("Diana Eminescu");
    cont3.setSoldCont(9873625.67);
    cout << "Cont bancar cu parametru" << endl;
    cont3.afisare();
    // Test getter pentru atributul constant
    cout << "Numar cont: " << cont2.getNumarCont() << endl;

    // teste operator=
    cont3 = cont2;
    cout << "\nUser2 dupa operator '=' " << endl;
    cont3.afisare();

    // test constructor si copier
    ContBancar cont4(cont2);
    cout << "\nUser4 - copie" << endl;
    cont4.afisare();

    // Test modificare nume si sold
    cont4.setNumeTitular("Anton Bradu");
    cont4.setSoldCont(7896);

    // User4 dupa modificare
    cout << "\nUser4 dupa modificare" << endl;
    cont4.afisare();

    return 0;
}

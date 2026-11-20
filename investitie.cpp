#include <iostream>
#include <cstring>

using namespace std;

class Investitie
{
private:
    char *denumireInvestitie;
    const int codInvestitie;
    double valoareInvestitie;

public:
    // constructor default
    Investitie() : codInvestitie(0)
    {
        denumireInvestitie = nullptr;
        valoareInvestitie = 0;
    }

    // constructor cu parametru
    Investitie(int cod) : codInvestitie(cod)
    {
        denumireInvestitie = nullptr;
        valoareInvestitie = 0;
    }

    // constructor de copiere
    Investitie(const Investitie &i) : codInvestitie(i.codInvestitie)
    {
        denumireInvestitie = nullptr;
        valoareInvestitie = i.valoareInvestitie;
        setDenumireInvestitie(i.denumireInvestitie);
    }

    // getter pentru cod investitie
    int getCodInvestitie() const
    {
        return codInvestitie;
    }

    // setter pentru denumire
    void setDenumireInvestitie(const char *nume)
    {
        char *numeNou = nullptr;
        if (nume != nullptr)
        {
            numeNou = new char[strlen(nume) + 1];
            strcpy(numeNou, nume);
        }
        delete[] denumireInvestitie;
        denumireInvestitie = numeNou;
    }

    // setter pentru valoare
    void setValoareInvestitie(double valoare)
    {
        if (valoare >= 0)
        {
            valoareInvestitie = valoare;
        }
    }

    // destructor
    ~Investitie()
    {
        delete[] denumireInvestitie;
    }

    // Operator =
    Investitie &operator=(const Investitie &i)
    {
        if (this != &i)
        {
            setDenumireInvestitie(i.denumireInvestitie);
            valoareInvestitie = i.valoareInvestitie;
        }
        return *this;
    }

    // metoda de afisare
    void afisare() const
    {
        cout << "\nInvestitie: " << (denumireInvestitie != nullptr ? denumireInvestitie : "") << endl;
        cout << "Cod investitie: " << codInvestitie << endl;
        cout << "Valoarea: " << valoareInvestitie << " RON.\n";
        cout << "\n--------------------------------------------------\n";
    }
};

int main(void)
{
    // teste default
    Investitie i1;
    cout << "Investitie default este: \n";
    i1.afisare();

    // teste cu parametru
    Investitie i2;
    i2.setDenumireInvestitie("Banca ING");
    i2.setValoareInvestitie(450);
    cout << "Investitie cu parametrul este: \n";
    i2.afisare();

    Investitie i3(1);
    i3.setDenumireInvestitie("Amazon");
    i3.setValoareInvestitie(10450);
    cout << "A doila Investitie cu parametrul este: \n";
    i3.afisare();

    // teste de copiere
    Investitie i4(i2);
    i4.setDenumireInvestitie("Banca BCR");
    i4.setValoareInvestitie(1000);
    cout << "Investitie copiata este: \n";
    i4.afisare();

    // teste de operator =
    i2 = i4;
    cout << "Investitie modificata cu operatorul = este: \n";
    i2.afisare();

    return 0;
}
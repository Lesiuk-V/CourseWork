#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
#include <cstring>
using namespace std;

#define _CRT_SECURE_NO_WARNINGS

class Human
{
protected:
    char  name[50];
    char surname[50];
    char patronymic[50];
    char nationality[20];
    char dateOfBirth[11];
public:
    string getName() { return name; }
    string getPatronymic() { return patronymic; }
    string getSurname() { return surname; }
    string getNationality() { return nationality; }
    string getDateOfBirth() { return dateOfBirth; }
    /*   void setName(string name) { this->name = name; }
       void setLastName(string lastName) { this->patronymic = lastName; }
       void setSurname(string surname) { this->surname = surname; }
       void setNationality(string nationality) { this->nationality = nationality; }
       void setDateOfBitth(string dateOfBirth) { this->dateOfBirth = dateOfBirth; }*/

    friend istream& operator >> (istream& s, Human& d);
    friend ostream& operator << (ostream& s, Human& d);

    Human()
    {
        strcpy_s(name, _countof(name), "unknow");
        strcpy_s(surname, _countof(surname), "unknow");
        strcpy_s(patronymic, _countof(patronymic), "unknow");
        strcpy_s(nationality, _countof(nationality), "unknow");
        strcpy_s(dateOfBirth, _countof(dateOfBirth), "unknow");
    }

    void create() {
        cout << "Name: "; cin.ignore(); cin.getline(name, 50);
        cout << "Surname: "; cin.getline(surname, 50);
        cout << "Patronymic: "; cin.getline(patronymic, 50);
        cout << "Nationality: "; cin.getline(nationality, 20);
        cout << "Date of bitrh: "; cin.getline(dateOfBirth, 11);
        //  std::cout << *this << " created\n";
    }

    virtual void print()
    {
        cout << "\nName: " << getName() << "\nSurname: " << getSurname() << "\nPatronymic: " << getPatronymic()
            << "\nNationaly" << getNationality() << "\nDate of birth:" << getDateOfBirth() << endl;
    }

    

    virtual int count()
    {
        int n;
        ifstream ifile;
        ifile.open("Test1.dat", ios::in | ios::binary);
        ifile.seekg(0, ios::end);
        int endposition = ifile.tellg();
        n = endposition / sizeof(Human);
        return n;
    }
};

istream& operator >> (istream& s, Human& d)
{
    cout << "Name: "; s >> d.name;
    cout << "Surname: "; s >> d.surname;
    cout << "Patronymic: "; s >> d.patronymic;
    cout << "Natyonality: "; s >> d.nationality;
    cout << "Date of birh: "; s >> d.dateOfBirth;
    return s;
}

ostream& operator << (ostream& s, Human& d)
{
    s << d.name << " " << d.surname << " " << d.patronymic << " " << d.nationality << " " << d.dateOfBirth;
    return s;
}


class Citizen : public Human
{
private:

    int numberDocument;
    char dateOfExpiry[11];
public:
    Human h;
    static string typeOfDocument;
    void setNumberDocument(int numberDocument) { this->numberDocument = numberDocument; }
   // void setDateOfExipiry(char* dateOfExpiry) { this->dateOfExpiry = dateOfExpiry; }
    int getNumberDocument() { return numberDocument; }
    string getDateOfExpiry() { return dateOfExpiry; }
    string getTypeOfDocument() { return typeOfDocument; }


    Citizen()
    {
        strcpy_s(name, _countof(name), "unknow");
        strcpy_s(surname, _countof(surname), "unknow");
        strcpy_s(patronymic, _countof(patronymic), "unknow");
        strcpy_s(nationality, _countof(nationality), "unknow");
        strcpy_s(dateOfBirth, _countof(dateOfBirth), "unknow");
        strcpy_s(dateOfExpiry, _countof(dateOfExpiry), "unknow");
    }
    virtual int count()
    {
        int n;
        ifstream ifile;
        ifile.open("Citizen.dat", ios::in | ios::binary);
        ifile.seekg(0, ios::end);
        int endposition = ifile.tellg();
        n = endposition / sizeof(Citizen);
        //if (i == 0)
        //{
        //   /* cin >> n;
        //    int position = (n - 1) * sizeof(Citizen);
        //    ifile.seekg(position);
        //    ifile.read(reinterpret_cast<char*>(&citizen), sizeof(citizen));
        //    citizen.showData();*/
        //}
        return n;
    }



    //Citizen(string name = "null", string surname = "null", string patronymic = "null",
    //    string nationality = "null", string dateOfbirth = "null", int numberDocument = 0,
    //    string dateOfExpiry = "null") //:Human(name,surname,patronymic,nationality,dateOfbirth)
    //{
    //    setNumberDocument(numberDocument);
    //    
    //    //setDateOfExipiry(dateOfExpiry);
    //}



    virtual void print() override
    {
        cout << "Name: " << getName() << "\nSurname: " << getSurname() << "\nPatronymic: " << getPatronymic()
            << "\nNationaly: " << getNationality() << "\nDate of birth: " << getDateOfBirth() << "\nType of document: " << getTypeOfDocument()
            << "\nDoucument Number: " << getNumberDocument() << "\nDate of expiry: " << getDateOfExpiry() << endl;
    }
};
string Citizen::typeOfDocument = "Паспорт";


class TemporaryCitizen : public Human
{
private:
    int numberDocument;
    static string typeOfDocument;
    string dateOfExpiry;
public:
    void setNumberDocument(int numberDocument) { this->numberDocument = numberDocument; }
    void setDateOfExipiry(string dateOfExpiry) { this->dateOfExpiry = dateOfExpiry; }
    int getNumberDocument() { return numberDocument; }
    string getDateOfExpiry() { return dateOfExpiry; }
    string getTypeOfDocument() { return typeOfDocument; }

    TemporaryCitizen(string name = "null", string surname = "null", string patronymic = "null",
        string nationality = "null", string dateOfbirth = "null", int numberDocument = 0,
        string dateOfExpiry = "null")// :Human(name, surname, patronymic, nationality, dateOfbirth)
    {
        setNumberDocument(numberDocument);
        setDateOfExipiry(dateOfExpiry);
    }


    virtual void print() override
    {
        cout << "Name: " << getName() << "\nSurname: " << getSurname() << "\nPatronymic: " << getPatronymic()
            << "\nNationaly: " << getNationality() << "\nDate of birth: " << getDateOfBirth() << "\nType of document: " << getTypeOfDocument()
            << "\nDoucument Number: " << getNumberDocument() << "\nDate of expiry: " << getDateOfExpiry() << endl;
    }


    virtual int count()
    {
        int n;
        ifstream ifile;
        ifile.open("TCitizen.dat", ios::in | ios::binary);
        ifile.seekg(0, ios::end);
        int endposition = ifile.tellg();
        n = endposition / sizeof(TemporaryCitizen);
        return n;
    }

};


string TemporaryCitizen::typeOfDocument = "Тимчасове громадянство";


void print_menu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. додати громадянина" << endl;
    cout << "2. додати тимчасового громадянина" << endl;
    cout << "3. переглянути громадян" << endl;
    cout << "4. переглянути тимчасових громадян" << endl;
    cout << "5. пошук громадян" << endl;
    cout << "6. пошук тимчасових громадян" << endl;
    cout << "7. видалення громадянина" << endl;
    cout << "8. видалення тимчасового громадянина" << endl;
    cout << "9. Exit" << endl;
    cout << ">";
}
int get_variant(int count) {
    int variant;
    cin >> variant;
    if (variant > count)
    {
        cerr << "Error\n";
        return 0;
    }
    return variant;
}

int main()
{
    system("chcp 1251>nul");
    int variant;
    int position;
    Citizen citizen;
    TemporaryCitizen tcitizen;
    fstream file, file1;
    file.open("Citizen.dat", ios::app | ios::out | ios::in | ios::binary);
    file1.open("TCitizen.dat", ios::app | ios::out | ios::in | ios::binary);
    do {
        print_menu();
        char ch;
        variant = get_variant(9);
        Citizen c;

        switch (variant) {
        case 1:
            
            do
            {
                citizen.create();

                file.write(reinterpret_cast<char*>(&citizen), sizeof(citizen));
                cout << "Сontinue(y/n)? ";
                cin >> ch;

            } while (ch == 'y');
            break;

        case 2:
            do
            {
                tcitizen.create();

                file1.write(reinterpret_cast<char*>(&tcitizen), sizeof(tcitizen));
                cout << "Сontinue(y/n)? ";
                cin >> ch;

            } while (ch == 'y');
            break;
            break;

        case 3:
        {
            file.seekg(0);
            for (int i = 0; i < citizen.count(); i++)
            {
                file.read(reinterpret_cast<char*>(&citizen), sizeof(citizen));
                cout << "\n Person: " << i+1;
                citizen.print();
            }
            cout << "\nin file: " << citizen.count() << " human\n";
            break;
        }

        case 4:
        {
            file1.seekg(0);
            for (int i = 0; i < tcitizen.count(); i++)
            {
                file1.read(reinterpret_cast<char*>(&tcitizen), sizeof(tcitizen));
                cout << "\n Person: " << i + 1;
                tcitizen.print();
            }
            cout << "\nin file: " << tcitizen.count() << " human\n";
            break;
        }
        case 5:
        {
            int n;
            cout << "\nEnter number person: ";
            cin >> n;
            if (n > citizen.count())
            {
                cout << "Громадянина з таким номером немає\nВведіть інше число\n";
                break;
            }
            int position = (n - 1) * sizeof(Citizen);
            file.seekg(position);
            file.read(reinterpret_cast<char*>(&citizen), sizeof(citizen));
            citizen.print();
            break;
        }

        case 6:
        {
            int n;
            cout << "\nEnter number person: ";
            cin >> n;
            if (n > tcitizen.count())
            {
                cout << "Громадянина з таким номером немає\nВведіть інше число\n";
                break;
            }
            int position = (n - 1) * sizeof(TemporaryCitizen);
            file1.seekg(position);
            file1.read(reinterpret_cast<char*>(&tcitizen), sizeof(tcitizen));
            tcitizen.print();
            break;
        }

        case 7:
        {

        }

        case 8:
        {
        }
        }
        if (variant != 9)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 9);
    return 0;
}
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string.h>
#include <fstream>
using namespace std;



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

    //Human(string name="null", string surname = "null", string patronymic = "null",  string nationality = "null", string dateOfbirth = "null")
    //{
    //    setName(name);
    //    setLastName(patronymic); 
    //    setSurname(surname);
    //    setNationality(nationality);
    //    setDateOfBitth(dateOfbirth);
    //}

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


    int count()
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
    string dateOfExpiry;
public:
    Human h;
    static string typeOfDocument;
    void setNumberDocument(int numberDocument) { this->numberDocument = numberDocument; }
    void setDateOfExipiry(string dateOfExpiry) { this->dateOfExpiry = dateOfExpiry; }
    int getNumberDocument() { return numberDocument; }
    string getDateOfExpiry() { return dateOfExpiry; }
    string getTypeOfDocument() { return typeOfDocument; }

    Citizen(string name = "null", string surname = "null", string patronymic = "null",
        string nationality = "null", string dateOfbirth = "null", int numberDocument = 0,
        string dateOfExpiry = "null") //:Human(name,surname,patronymic,nationality,dateOfbirth)
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

};


string TemporaryCitizen::typeOfDocument = "Тимчасове громадянство";


void print_menu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1. додати громадянина" << endl;
    cout << "2. додати тимчасового громадянина" << endl;
    cout << "3. переглянути громадян" << endl;
    cout << "4. переглянути тимчасових громадян" << endl;
    cout << "5. Exit" << endl;
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
    Citizen citizen;
    Human human;
    fstream file;
    file.open("Test1.dat", ios::app | ios::out | ios::in | ios::binary);
    // Citizen citizen("Name", "LastName", "Surname", "Nationality", "DateOfBirth", 1, "DateOfExpiry");
    // TemporaryCitizen tcitizen("Name", "LastName", "Surname", "Nationality", "DateOfBirth", 1, "DateOfExpiry");
    do {
        print_menu(); // выводим меню на экран
        char ch;
        variant = get_variant(5); // получаем номер выбранного пункта меню
        Citizen c;

        switch (variant) {
        case 1:
            do
            {
                human.create();

                file.write(reinterpret_cast<char*>(&human), sizeof(human));
                cout << "Сontinue(y/n)? ";
                cin >> ch;

            } while (ch == 'y');
            break;

        case 2:

            break;

        case 3:
        {
            file.seekg(0);
            //file.read(reinterpret_cast<char*>(&human), sizeof(human));

            for (int i = 0; i < human.count(); i++)
            {
                file.read(reinterpret_cast<char*>(&human), sizeof(human));
                cout << "\n Person: ";
                human.print();

            }
            /* while (!file.eof())
             {
                 cout << "\n Person: ";
                 human.print();
                 file.read(reinterpret_cast<char*>(&human), sizeof(human));
             }*/
            cout << "in file: " << human.count() << " human\n";
            cout << "enter x for exit\n";
            cin >> ch;
            break;
        }

        case 4:
        {
            citizen.print();
            break;
        }

        }

        if (variant != 5)
            system("pause"); // задерживаем выполнение, чтобы пользователь мог увидеть результат выполнения выбранного пункта
    } while (variant != 5);
    return 0;
}
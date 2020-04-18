#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <stdlib.h> 
#include <cstring>
#include <ctime>
#include <string>
#include <iostream>
using namespace std;



class Human
{
protected:
    char  name[40];
    char surname[40];
    char patronymic[40];
    char nationality[40];
    char dateOfBirth[11];
public:
    virtual void create()
    {
        cin.ignore(10, '\n');
        cout << "\nName: "; cin >> name;
        cout << "Surname: "; cin >> surname;
        cout << "Patronymic: "; cin >> patronymic;
        cout << "Nationality: "; cin >> nationality;
        cout << "Date of Birth: "; cin >> dateOfBirth;
    }


    virtual void showData()
    {

        cout << "Name: " << name << endl;
        cout << "Surname: " << surname << endl;
        cout << "Patronymic: " << patronymic << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;

    }
};

class Citizen : public Human
{
private:

    int numberDocument;
    static char typeOfDocument[20];
    char dateOfExpiry[11];
    static int cCount;
public:

    
    void read(int pn)
    {
        ifstream ifile;

        ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        ifile.seekg(pn * sizeof(Citizen));
        ifile.read((char*)this, sizeof(*this));
        ifile.close();
    }

    void write()
    {
        ofstream ofile;
        ofile.open("Citizen.dat", ios::app | ios::binary | ios::out | ios::in);
        ofile.write((char*)this, sizeof(*this));
        ofile.close();
    }

    void set_data_and_number(int n)
    {
        cout << "Data of expiry: "; cin >> dateOfExpiry;
        numberDocument = n + 1;
    }

    static int count()
    {
        {
            ifstream ifile;
            ifile.open("Citizen.dat ", ios::binary);
            ifile.seekg(0, ios::end);
            return (int)ifile.tellg() / sizeof(Human);
            ifile.close();
        }
    }

#pragma region Citizen Search

    void searchName()
    {
        Citizen citizen;
        ifstream ifile;
        char str[40];
        ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        cout << "Введіть ім'я для пошуку: ";
        cin >> str;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(Citizen));
            ifile.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
            if (0 == strcmp(str, citizen.name))
            {
                citizen.showData();
            }
        }
        ifile.close();
    }
    void searchSurname()
    {
        Citizen citizen;
        ifstream ifile;
        char str[40];
        ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        cout << "Введіть прізвище для пошуку: ";
        cin >> str;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(Citizen));
            ifile.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
            if (0 == strcmp(str, citizen.surname))
            {
                citizen.showData();
            }
        }
        ifile.close();
    }
    void searchNationality()
    {
        Citizen citizen;
        ifstream ifile;
        char str[40];
        ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        cout << "Введіть націоннальність для пошуку: ";
        cin >> str;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(Citizen));
            ifile.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
            if (0 == strcmp(str, citizen.nationality))
            {
                citizen.showData();
            }
        }
        ifile.close();
    }

    void searchDatrOfBirth()
    {
        Citizen citizen;
        ifstream ifile;
        char str[40];
        ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        cout << "Введіть дату народження для пошуку(день.місяць.рік): ";
        cin >> str;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(Citizen));
            ifile.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
            if (0 == strcmp(str, citizen.dateOfBirth))
            {
                citizen.showData();
            }
        }
        ifile.close();
    }

#pragma endregion

#pragma region Edit and delete

    void deleteData()
    {
        Citizen citizen;
        char str[40];
        cout << "Введіть id для видалення: ";
        cin >> str;
        ifstream file;
        file.open("Citizen.dat", ios::binary | ios::out | ios::in);
        ofstream temp;
        temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
        file.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
        while (!file.eof())
        {

            if (0 != strcmp(citizen.name, str))
            {
                temp.write(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
            }

            else
            {
                cout << "\nЗапис видалено\n";
            }
            file.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
        }
        temp.close();
        file.close();
        if (remove("Citizen.dat") != 0)
        {
            cout << "file do not remove";
        }
        if (rename("temp.dat", "Citizen.dat") != 0)
        {
            cout << "file do not rename";
        }
    }

    void editData()
    {
        Citizen citizen;
        char str[40];
        cout << "Введіть id для редагування: ";
        cin >> str;
        ifstream file;
        file.open("Citizen.dat", ios::binary | ios::out | ios::in);
        ofstream temp;
        temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
        file.seekg(0);
        file.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
        while (!file.eof())
        {

            if (0 != strcmp(citizen.name, str))
            {
                temp.write(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
            }

            else
            {
                citizen.create();
                temp.write(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
            }
            file.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
        }
        temp.close();
        file.close();
        if (remove("Citizen.dat") != 0)
        {
            cout << "file do not remove";
        }
        if (rename("temp.dat", "Citizen.dat") != 0)
        {
            cout << "file do not rename";
        }
    }

#pragma endregion


};
char Citizen::typeOfDocument[20] = "Паспорт";

//int Citizen::numberDocument = 0;
class TemporaryCitizen : public Human
{
private:
    int numberDocument;
    static char typeOfDocument[30];
    char dateOfExpiry[11];
public:

    void read(int pn)
    {
        ifstream ifile;

        ifile.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        ifile.seekg(pn * sizeof(Citizen));
        ifile.read((char*)this, sizeof(*this));
        ifile.close();
    }

    void write()
    {
        ofstream ofile;
        ofile.open("Tcitizen.dat", ios::app | ios::binary | ios::out | ios::in);
        ofile.write((char*)this, sizeof(*this));
        ofile.close();
    }

    void set_data_and_number(int n)
    {
        cout << "Data of expiry: "; cin >> dateOfExpiry;
        numberDocument = n + 1;
    }

    static int count()
    {
        {
            ifstream ifile;
            ifile.open("Tcitizen.dat ", ios::binary);
            ifile.seekg(0, ios::end);
            return (int)ifile.tellg() / sizeof(TemporaryCitizen);
            ifile.close();
        }
    }

#pragma region TCitizen Search
    void searchName()
    {
        TemporaryCitizen tcitizen;
        ifstream ifile;
        char str[40];
        ifile.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        cout << "Введіть ім'я для пошуку: ";
        cin >> str;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(TemporaryCitizen));
            ifile.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
            if (0 == strcmp(str, tcitizen.name))
            {
                tcitizen.showData();
            }
        }
        ifile.close();
    }
    void searchSurname()
    {
        TemporaryCitizen tcitizen;
        ifstream ifile;
        char str[40];
        ifile.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        cout << "Введіть прізвище для пошуку: ";
        cin >> str;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(TemporaryCitizen));
            ifile.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
            if (0 == strcmp(str, tcitizen.surname))
            {
                tcitizen.showData();
            }
        }
        ifile.close();
    }
    void searchNationality()
    {
        TemporaryCitizen tcitizen;
        ifstream ifile;
        char str[40];
        ifile.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
        ifile.seekg(0);
        cout << "Введіть націоннальність для пошуку: ";
        cin >> str;
        for (int i = 0; i < count(); i++)
        {
            ifile.seekg(i * sizeof(TemporaryCitizen));
            ifile.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
            if (0 == strcmp(str, tcitizen.nationality))
            {
                tcitizen.showData();
            }
        }
        ifile.close();
    }
#pragma endregion


#pragma region delete and edit Tcitizen

    void deleteData()
    {
        TemporaryCitizen tcitizen;
        char str[40];
        cout << "Введіть id для видалення: ";
        cin >> str;
        ifstream file;
        file.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
        ofstream temp;
        temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
        file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
        while (!file.eof())
        {

            if (0 != strcmp(tcitizen.name, str))
            {
                temp.write(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
            }

            else
            {
                cout << "\nЗапис видалено\n";
            }
            file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
        }
        temp.close();
        file.close();
        if (remove("Tcitizen.dat") != 0)
        {
            cout << "file do not remove";
        }
        if (rename("temp.dat", "Tcitizen.dat") != 0)
        {
            cout << "file do not rename";
        }
    }

    void editData()
    {
        TemporaryCitizen tcitizen;
        char str[40];
        cout << "Введіть id для редагування: ";
        cin >> str;
        ifstream file;
        file.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
        ofstream temp;
        temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
        file.seekg(0);
        file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
        while (!file.eof())
        {

            if (0 != strcmp(tcitizen.name, str))
            {
                temp.write(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
            }

            else
            {
                tcitizen.create();
                temp.write(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
            }
            file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
        }
        temp.close();
        file.close();
        if (remove("Tcitizen.dat") != 0)
        {
            cout << "file do not remove";
        }
        if (rename("temp.dat", "Tcitizen.dat") != 0)
        {
            cout << "file do not rename";
        }
    }

#pragma endregion


};


char TemporaryCitizen::typeOfDocument[30] = "Тимчасове громадянство";


void print_menu() {
    system("cls"); // очищаем экран
    cout << "What do you want to do?" << endl;
    cout << "1.  додати громадянина" << endl;
    cout << "2.  додати тимчасового громадянина" << endl;
    cout << "3.  переглянути громадян" << endl;
    cout << "4.  переглянути тимчасових громадян" << endl;
    cout << "5.  пошук громадян" << endl;
    cout << "6.  пошук тимчасових громадян" << endl;
    cout << "7.  видалення громадянина" << endl;
    cout << "8.  видалення тимчасових громадян" << endl;
    cout << "9.  редагування громадян " << endl;
    cout << "10. редагування тимчасових громадян" << endl;
    cout << "11. Exit" << endl;
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
    string str;
    Citizen citizen;
    int n;
    TemporaryCitizen tcitizen;
    do {
        print_menu();
        char ch;
        variant = get_variant(11);
        Citizen c;

        switch (variant) {
        case 1:

            do
            {
                cout << "Enter data of Person: ";
                citizen.create();
                citizen.write();
                cout << "Continiue(y/n)?";
                cin >> ch;
            } while (ch == 'y');

            break;

        case 2:
            do
            {
                cout << "Enter data of Person: ";
                tcitizen.create();
                tcitizen.write();
                cout << "Continiue(y/n)?";
                cin >> ch;
            } while (ch == 'y');

            break;

        case 3:
            n = Citizen::count();
            cout << "in file " << n << " citizen\n";
            for (int j = 1; j < n + 1; j++)
            {
                cout << "\n Citizen " << j << endl;
                citizen.read(j - 1);
                citizen.showData();
                cout << endl;
            }
            cout << endl;
            break;
        case 4:
            n = TemporaryCitizen::count();
            cout << "in file " << n << " temporary citizen";
            for (int j = 1; j < n + 1; j++)
            {
                cout << "\n Temporary citizen " << j << endl;
                tcitizen.read(j - 1);
                tcitizen.showData();
                cout << endl;
            }
            cout << endl;
            break;
        case 5:
            do
            {
                cout << "1. Пошук за іменем" << endl;
                cout << "2. Пошук за фамілією" << endl;
                cout << "3. Пошук за датою народження" << endl;
                cout << "4. Пошук за за національністю" << endl;
                cout << "5. пошук за id" << endl;
                cin >> variant;
                switch (variant)
                {
                case 1:
                    citizen.searchName();
                    break;

                case 2:
                    citizen.searchSurname();
                    break;

                case 3:
                    citizen.searchSurname();
                    break;

                case 4:
                    citizen.searchNationality();
                    break;

                case 5:

                    break;
                }
                break;
                    system("pause");
                    } while (variant != 5);
                break;
                case 6:
                    do
                    {
                        cout << "1. Пошук за іменем" << endl;
                        cout << "2. Пошук за фамілією" << endl;
                        cout << "3. Пошук за датою народження" << endl;
                        cout << "4. Пошук за за національністю" << endl;
                        cout << "5. пошук за id" << endl;
                        cin >> variant;
                        switch (variant)
                        {
                        case 1:
                            tcitizen.searchName();
                            break;

                        case 2:
                            tcitizen.searchSurname();
                            break;

                        case 3:
                            tcitizen.searchSurname();
                            break;

                        case 4:
                            tcitizen.searchNationality();
                            break;

                        case 5:

                            break;
                        }
                        break;
                        system("pause");
                    } while (variant != 5);
                    break;
                case 7:
                    citizen.deleteData();
                    break;
                case 8:
                    tcitizen.deleteData();
                    break;
                case 9:
                    citizen.editData();
                    break;
                case 10:
                    tcitizen.editData();
                    break;
                }
        if (variant != 11 || variant == 't')
            system("pause");
    } while (variant != 11);
    return 0;
}
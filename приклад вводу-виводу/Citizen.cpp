#include "Citizen.h"
#include <iostream>
#include <fstream>
using namespace std;

int Citizen::numberDocument = 1;

void Citizen::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Національність: "; cin >> nationality;
    cout << "Дата народження: "; cin >> dateOfBirth;
    set_data_and_number(count());
}

void Citizen::showData()
{
    cout << "\nТип документу: " << typeOfDocument << endl;
    cout << "Номер документу: " << numberDocument << endl;
    cout << "Ім'я: " << name << endl;
    cout << "Прізвище: " << surname << endl;
    cout << "По батькові: " << patronymic << endl;
    cout << "Національність: " << nationality << endl;
    cout << "Дата народження: " << dateOfBirth << endl;
    cout << "Дійсний до: " << dateOfExpiry << endl;
}

void Citizen::read(int pn)
{
    ifstream ifile;
    ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    ifile.seekg(pn * sizeof(Citizen));
    ifile.read((char*)this, sizeof(*this));
    ifile.close();
}

void Citizen::write()
{
        ofstream ofile;
        ofile.open("Citizen.dat", ios::app | ios::binary | ios::out | ios::in);
        ofile.write((char*)this, sizeof(*this));
        ofile.close();
}

void Citizen::set_data_and_number(int n)
{
    cout << "Дійсний до: "; cin >> dateOfExpiry;
    numberDocument = n + 1;
}

int Citizen::count()
{
    ifstream ifile;
    ifile.open("Citizen.dat ", ios::binary);
    ifile.seekg(0, ios::end);
    return (int)ifile.tellg() / sizeof(Human);
    ifile.close();
}

#pragma region SearchCitizen

void Citizen::searchName()
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

void Citizen::searchSurname()
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

void Citizen::searchPatronymic()
{
    Citizen citizen;
    ifstream ifile;
    char str[40];
    ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть по батькові для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Citizen));
        ifile.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
        if (0 == strcmp(str, citizen.patronymic))
        {
            citizen.showData();
        }
    }
    ifile.close();
}

void Citizen::searchNationality()
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

void Citizen::searchDateOfBirth()
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

void Citizen::searchDN()
{
    Citizen citizen;
    ifstream ifile;
    int str;
    ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть номер документа для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Citizen));
        ifile.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
        if (str == citizen.numberDocument)
        {
            citizen.showData();
        }
    }
    ifile.close();
}

#pragma endregion


#pragma region Delete adn edit data

void Citizen::deleteData()
{
    Citizen citizen;
    int str;
    cout << "Введіть номер документа для видалення: ";
    cin >> str;
    ifstream file;
    file.open("Citizen.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
    while (!file.eof())
    {

        if (citizen.numberDocument != str)
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

void Citizen::editData()
{
    Citizen citizen;
    int str;
    cout << "Введіть номер документа для редагування: ";
    cin >> str;
    ifstream file;
    file.open("Citizen.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));
    while (!file.eof())
    {

        if (citizen.numberDocument != str)
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

char Citizen::typeOfDocument[20] = "Паспорт";
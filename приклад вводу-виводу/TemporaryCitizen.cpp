#include "TemporaryCitizen.h"
#include <iostream>
#include <fstream>
using namespace std;

void TemporaryCitizen::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Національність: "; cin >> nationality;
    cout << "Дата народження: "; cin >> dateOfBirth;
    set_data_and_number(count());
}

void TemporaryCitizen::showData()
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

void TemporaryCitizen::read(int pn)
{
    ifstream ifile;

    ifile.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    ifile.seekg(pn * sizeof(TemporaryCitizen));
    ifile.read((char*)this, sizeof(*this));
    ifile.close();
}

void TemporaryCitizen::write()
{
    ofstream ofile;
    ofile.open("Tcitizen.dat", ios::app | ios::binary | ios::out | ios::in);
    ofile.write((char*)this, sizeof(*this));
    ofile.close();
}

void TemporaryCitizen::set_data_and_number(int n)
{
    cout << "Дійсний до: "; cin >> dateOfExpiry;
    if (n < 1000)
        numberDocument = 1;
    else
        numberDocument = n + 1;
}

int TemporaryCitizen::count()
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
void TemporaryCitizen::searchName()
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
void TemporaryCitizen::searchSurname()
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
void TemporaryCitizen::searchNationality()
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

void TemporaryCitizen::searchDateOfBirth()
{
    TemporaryCitizen tcitizen;
    ifstream ifile;
    char str[40];
    ifile.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть дату народження для пошуку(день.місяць.рік): ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(TemporaryCitizen));
        ifile.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
        if (0 == strcmp(str, tcitizen.dateOfBirth))
        {
            tcitizen.showData();
        }
    }
    ifile.close();
}

void TemporaryCitizen::searchDN()
{
    TemporaryCitizen tcitizen;
    ifstream ifile;
    int str;
    ifile.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть номер документа для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(TemporaryCitizen));
        ifile.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
        if (str == tcitizen.numberDocument)
        {
            tcitizen.showData();
        }
    }
    ifile.close();
}

#pragma endregion


#pragma region delete and edit Tcitizen

void TemporaryCitizen::deleteData()
{
    TemporaryCitizen tcitizen;
    int str;
    cout << "Введіть номер документа для видалення: ";
    cin >> str;
    ifstream file;
    file.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
    while (!file.eof())
    {

        if (tcitizen.numberDocument != str)
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

void TemporaryCitizen::editData()
{
    TemporaryCitizen tcitizen;
    int str;
    cout << "Введіть номер документа для редагування: ";
    cin >> str;
    ifstream file;
    file.open("Tcitizen.dat", ios::binary | ios::out | ios::in);
    ofstream temp;
    temp.open("temp.dat", ios::app | ios::binary | ios::out | ios::in);
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
    while (!file.eof())
    {

        if (tcitizen.numberDocument != str)
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

char TemporaryCitizen::typeOfDocument[30] = "Тимчасове громадянство";
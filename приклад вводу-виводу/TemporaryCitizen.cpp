#include "TemporaryCitizen.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int TemporaryCitizen::setNumberDocument()
{
    int id;
    string str;
    fstream idfile;
    idfile.open("TCitizenId.txt", fstream::out | fstream::in);
    ifstream temp;
    while (!idfile.eof())
    {
        getline(idfile, str);
        id = atoi(str.c_str());
    }
    ++id;
    idfile.close();
    idfile.open("TCitizenId.txt", fstream::out | fstream::in);
    idfile << id;
    idfile.close();
    return id;
}

void TemporaryCitizen::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Національність: "; cin >> nationality;
    cout << "Дата народження: "; cin >> dateOfBirth;
    cout << "Дійсний до: "; cin >> dateOfExpiry;
    numberDocument = setNumberDocument();                   
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

int TemporaryCitizen::count()
{
    ifstream ifile;
    ifile.open("Tcitizen.dat ", ios::binary);
    ifile.seekg(0, ios::end);
    return (int)ifile.tellg() / sizeof(TemporaryCitizen);
    ifile.close();
}

int TemporaryCitizen::search(int variant)
{
    if (variant == 0)
        return 0;
    TemporaryCitizen tcitizen;
    ifstream ifile;
    char str[40];
    ifile.open("TCitizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть дані для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(TemporaryCitizen));
        ifile.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));

        switch (variant)
        {
        case 1:
            if (0 == strcmp(str, tcitizen.name))
            {
                tcitizen.showData();
            }
            break;

        case 2:
            if (0 == strcmp(str, tcitizen.surname))
            {
                tcitizen.showData();
            }
            break;
        case 3:
            if (0 == strcmp(str, tcitizen.patronymic))
            {
                tcitizen.showData();
            }
            break;
        case 4:
            if (0 == strcmp(str, tcitizen.nationality))
            {
                tcitizen.showData();
            }
            break;
        case 5:
            if (0 == strcmp(str, tcitizen.dateOfBirth))
            {
                tcitizen.showData();
            }
            break;
        case 6:

            if (atoi(str) == tcitizen.numberDocument)
            {
                tcitizen.showData();
            }
            break;
        case 7:
            if (0 == strcmp(str, tcitizen.dateOfExpiry))
            {
                tcitizen.showData();
            }
            break;
        default:
            cout << "Помилка вводу. Введіть ще раз\n";
            break;
        }
    }
    ifile.close();
}

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
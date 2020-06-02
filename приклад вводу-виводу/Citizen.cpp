#include "Citizen.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Citizen::setNumberDocument()
{
    int id;
    string str;
    fstream file;
    file.open("id.txt", fstream::out | fstream::in);
    ifstream temp;
    while (!file.eof())
    {
        getline(file, str);
        id = atoi(str.c_str());
    }
    ++id;
    file.close();
    file.open("id.txt", fstream::out | fstream::in);
    file << id;
    file.close();
    return id;
}

void Citizen::create()
{
    cin.ignore(10, '\n');
    cout << "\nІм'я: "; cin >> name;
    cout << "Прізвище: "; cin >> surname;
    cout << "По батькові: "; cin >> patronymic;
    cout << "Національність: "; cin >> nationality;
    cout << "Дата народження: "; cin >> dateOfBirth;
    cout << "Дійсний до: "; cin >> dateOfExpiry;                
    numberDocument=setNumberDocument();
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
    cout << "Дійсний до: " << dateOfExpiry << endl << endl;;
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

int Citizen::count()
{
    ifstream ifile;
    ifile.open("Citizen.dat ", ios::binary);
    ifile.seekg(0, ios::end);
    return (int)ifile.tellg() / sizeof(Human);
    ifile.close();
}

#pragma region SearchCitizen

int Citizen::search(int variant)
{
    if (variant == 0)
        return 0;
    Citizen citizen;
    ifstream ifile;
    char str[40];
    ifile.open("Citizen.dat", ios::binary | ios::out | ios::in);
    ifile.seekg(0);
    cout << "Введіть дані для пошуку: ";
    cin >> str;
    for (int i = 0; i < count(); i++)
    {
        ifile.seekg(i * sizeof(Citizen));
        ifile.read(reinterpret_cast<char*>(&citizen), sizeof(Citizen));

        switch (variant)
        {
        case 1:
            if (0 == strcmp(str, citizen.name))
            {
                citizen.showData();
            }
            break;

        case 2:
            if (0 == strcmp(str, citizen.surname))
            {
                citizen.showData();
            }
            break;
        case 3:
            if (0 == strcmp(str, citizen.patronymic))
            {
                citizen.showData();
            }
            break;
        case 4:
            if (0 == strcmp(str, citizen.nationality))
            {
                citizen.showData();
            }
            break;
        case 5 :
            if (0 == strcmp(str, citizen.dateOfBirth))
            {
                citizen.showData();
            }
            break;
        case 6:
            
            if (atoi(str) == citizen.numberDocument)
            {
                citizen.showData();
            }
            break;
        case 7:
            if (0 == strcmp(str, citizen.dateOfExpiry))
            {
                citizen.showData();
            }
            break;
        default:
            cout << "Помилка вводу. Введіть ще раз\n";
            break;
        }
    }
    ifile.close();
}


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
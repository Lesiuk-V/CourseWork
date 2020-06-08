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

void TemporaryCitizen::create(int id)
{
    cin.ignore(10, '\n');
    cout << "\n��'�: "; cin >> name;
    cout << "�������: "; cin >> surname;
    cout << "�� �������: "; cin >> patronymic;
    cout << "�������������: "; cin >> nationality;
    cout << "���� ����������(����.�����.��): "; cin >> dateOfBirth;
    cout << "ĳ����� ��(����.�����.��): "; cin >> dateOfExpiry;
    if (id != 0)
        numberDocument = id;
    else
    numberDocument = setNumberDocument();                   
}

void TemporaryCitizen::showData()
{
    cout << "\n��� ���������: " << typeOfDocument << endl;
    cout << "����� ���������: " << numberDocument << endl;
    cout << "��'�: " << name << endl;
    cout << "�������: " << surname << endl;
    cout << "�� �������: " << patronymic << endl;
    cout << "�������������: " << nationality << endl;
    cout << "���� ����������(����.�����.��): " << dateOfBirth << endl;
    cout << "ĳ����� ��(����.�����.��): " << dateOfExpiry << endl << endl;
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
    cout << "������ ��� ��� ������: ";
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
            cout << "������� �����. ������ �� ���\n";
            break;
        }
    }
    ifile.close();
}

#pragma region delete and edit Tcitizen

void TemporaryCitizen::deleteData()
{
    bool del = false;
    TemporaryCitizen tcitizen;
    int str;
    cout << "\n������ ����� ��������� ��� ���������: ";
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
            del = true;
        }
        file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
    }
    temp.close();
    file.close();
    if (remove("Tcitizen.dat") != 0)
    {
        cout << "\n�������. ���� ��������� ��������\n";
    }
    if (rename("temp.dat", "Tcitizen.dat") != 0)
    {
        cout << "\n�������. ���� ��������� �������������\n";
    }
    if (del == true)
        cout << "\n����� ��������\n";
    else
        cout << "\n�� ������� �������� ����. ��������� �� ���.\n";
}

void TemporaryCitizen::editData()
{
    bool edit = false;
    TemporaryCitizen tcitizen;
    int str;
    cout << "������ ����� ��������� ��� �����������: ";
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
            tcitizen.create(numberDocument);
            temp.write(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
            edit = true;
        }
        file.read(reinterpret_cast<char*>(&tcitizen), sizeof(TemporaryCitizen));
    }
    temp.close();
    file.close();
    if (remove("Tcitizen.dat") != 0)
    {
        cout << "\n�������. ���� ��������� ��������\n";
    }
    if (rename("temp.dat", "Tcitizen.dat") != 0)
    {
        cout << "\n�������. ���� ��������� �������������\n";
    }
    if (edit == true)
        cout << "\n����� ������\n";
    else
        cout << "\n������� ��� ��� ������ ��������� �� ���.\n";
}

#pragma endregion

char TemporaryCitizen::typeOfDocument[30] = "��������� ������������";
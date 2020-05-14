#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Citizen.h"
#include "TemporaryCitizen.h"
using namespace std;
void print_menu() {
    system("cls");
    cout << "          Міграційна служба\n" << endl;
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
    cout << "11. Вихід" << endl;
    cout << ">";
}

void printSearchMenu()
{
    cout << "Пошук за полем: \n";
    cout << "1. Ім'я" << endl;
    cout << "2. Прізвище" << endl;
    cout << "3. По батькові" << endl;
    cout << "4. Національність" << endl;
    cout << "5. Дата народження" << endl;
    cout << "6. Номером документа" << endl;
    cout << "7. Дійсний до" << endl;
}
int get_variant(int count) {
    int variant;
    cin >> variant;
    if (variant > count)
    {
        cerr << "Помилка! Неправильний ввід\n";
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
                cout << "Введіть дані громадянина: ";
                citizen.create();
                citizen.write();
                cout << "Продовжити ввід?(т/н)?";
                cin >> ch;
            } while (ch == 'т');

            break;

        case 2:
            do
            {
                cout << "Введыть даны тимчасового громадянина: ";
                tcitizen.create();
                tcitizen.write();
                cout << "Породивжити(т/н)?";
                cin >> ch;
            } while (ch == 'т');

            break;

        case 3:
            n = Citizen::count();
            cout << "У файлі " << n << " громадян\n";
            for (int j = 1; j < n + 1; j++)
            {
                cout << "\n Громадянин " << j << endl;
                citizen.read(j - 1);
                citizen.showData();
                cout << endl;
            }
            cout << endl;
            break;
        case 4:
            n = TemporaryCitizen::count();
            cout << "У файлі " << n << " тимчасових громадян";
            for (int j = 1; j < n + 1; j++)
            {
                cout << "\n Тимчасовий громадянин" << j << endl;
                tcitizen.read(j - 1);
                tcitizen.showData();
                cout << endl;
            }
            cout << endl;
            break;
        case 5:
            do
            {
                printSearchMenu();
                variant = get_variant(7);
                citizen.search(variant);
                break;
                system("pause");
            } while (variant != 8);
            break;
        case 6:
            do
            {
                printSearchMenu();
                variant = get_variant(7);
                tcitizen.search(variant);
                break;
                system("pause");
            } while (variant != 8);
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
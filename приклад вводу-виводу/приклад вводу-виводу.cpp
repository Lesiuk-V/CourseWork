#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "Citizen.h"
#include "TemporaryCitizen.h"
using namespace std;
void print_citizen_menu()
{
    system("cls");
    cout << "          Громадяни\n" << endl;
    cout << "1.  Дадати данні громадянина" << endl;
    cout << "2.  Переглянути всі данні  " << endl;
    cout << "3.  Пошук громадян" << endl;
    cout << "4.  Редагування данних " << endl;
    cout << "5.  Видалення даних " << endl;
    cout << "6. Вихід" << endl;
    cout << "->";
}

void print_Tcitizen_menu()
{
    system("cls");
    cout << "          Тимчасові громадяни\n" << endl;
    cout << "1.  Дадати данні" << endl;
    cout << "2.  Переглянути данні" << endl;
    cout << "3.  Пошук" << endl;
    cout << "4.  Редагування даних" << endl;
    cout << "5.  Видалення даних" << endl;
    cout << "6. Вихід" << endl;
    cout << "->";
}

void print_menu() 
{
    system("cls");
    cout << "          Міграційна служба\n" << endl;
    cout << "1.  Грамадяни" << endl;
    cout << "2.  Тимчасові громадяни" << endl;
    cout << "3. Вихід" << endl;
    cout << "->";
}

void printSearchMenu()
{
    cout << "\n\nПошук за полем: \n";
    cout << "1. Ім'я" << endl;
    cout << "2. Прізвище" << endl;
    cout << "3. По батькові" << endl;
    cout << "4. Національність" << endl;
    cout << "5. Дата народження" << endl;
    cout << "6. Номером документа" << endl;
    cout << "7. Дійсний до" << endl;
    cout << "->";
}
int get_variant(int max) {
    int input = -1;
    bool valid = false;
    do
    {
        cin >> input;
        if (cin.good())
        {
            valid = true;
            if (input >0 && input <= max)
                return input;
            else
            {
                valid = false;
                cout << "Помилка вводу. Введіть ще раз" << endl;
            }
        }
        else
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Помилка вводу. Введіть ще раз" << endl;
        }
    } while (!valid);
    return input;
}
int main()
{
    system("chcp 1251>nul");
    int variant;
    int searchVar;
    Citizen citizen;
    int n;
    TemporaryCitizen tcitizen;
    do {
        print_menu();
        char ch;
        variant = get_variant(3);
        switch (variant) 
        {
            case 1:

                do
                {
                    print_citizen_menu();
                    variant = get_variant(6);
                    switch (variant)
                    {
                    case 1:

                        do
                        {

                            cout << "Введіть дані громадянина: ";
                            citizen.create(0);
                            citizen.write();
                            cout << "Продовжити ввід?(т/н)?";
                            cin >> ch;
                        } while (ch == 'т');
                        break;
                    case 2:
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
                    case 3:
                        do
                        {
                            printSearchMenu();
                            searchVar = get_variant(7);
                            citizen.search(searchVar);
                            break;
                            system("pause");
                        } while (searchVar != 7);
                        break;
                    case 4:
                        citizen.editData();
                        break;
                    case 5:

                        citizen.deleteData();
                        break;
                    }
                    if (variant != 6)
                        system("pause");
                } while (variant != 6);

                break;

            case 2:
                do
                {
                    print_Tcitizen_menu();
                    variant = get_variant(6);
                    switch (variant)
                    {
                    case 1:
                        do
                        {
                            cout << "Введіть дані тимчасового громадянина: ";
                            tcitizen.create(0);
                            tcitizen.write();
                            cout << "Породивжити(т/н)?";
                            cin >> ch;
                        } while (ch == 'т');
                        break;
                    case 2:
                        n = TemporaryCitizen::count();
                        cout << "У файлі " << n << " тимчасових громадян";
                        for (int j = 1; j < n + 1; j++)
                        {
                            cout << "\n Тимчасовий громадянин " << j << endl;
                            tcitizen.read(j - 1);
                            tcitizen.showData();
                            cout << endl;
                        }
                        cout << endl;
                        break;
                    case 3:
                        do
                        {
                            printSearchMenu();
                            searchVar = get_variant(7);
                            tcitizen.search(searchVar);
                            break;
                            system("pause");
                        } while (searchVar != 8);
                        break;
                    case 4:
                        tcitizen.editData();
                        break;
                    case 5:
                        tcitizen.deleteData();
                        break;
                    }
                    if (variant != 6)
                        system("pause");
                } while (variant != 6);
                break;
        }
        if (variant != 3)
            system("pause");
    } while (variant != 3);
    return 0;
}
#include <iostream>
#include <fstream>

using namespace std;
class Human {
protected:
    char  name[50];
    char surname[50];    
    char patronymic[50];
    char nationality[20];
    char dateOfBirth[11];
public:
    friend std::ostream& operator<<(std::ostream& o, Human& x) {
        cout << "Name: " << x.name << ", surname: " << x.surname << ", patronymic: " << x.patronymic
            << ", nationality: " << x.nationality << ", date of birth: " << x.dateOfBirth << endl;
        return o;
    }
    void create() {
        cout << "Name: "; cin.getline(name, 50);
        cout << "Surname: "; cin.getline(surname, 50);
        cout << "Patronymic: "; cin.getline(patronymic, 50);
        cout << "Nationality: "; cin.getline(nationality, 20);
        cout << "Date of bitrh: "; cin.getline(dateOfBirth, 10);
      //  std::cout << *this << " created\n";
    }
};

int main() {
    Human human, h;
    human.create();
    std::ofstream ofs("text.txt", ofstream::app, std::ios::binary );
    ofs.write(reinterpret_cast<char*>(&human), sizeof(human));
    ofs.close();
    std::ifstream ifs("text.txt", std::ios::binary);
    if (!ifs) { std::cerr << "File not found"; return 1; }
    while (ifs.read(reinterpret_cast<char*>(&h), sizeof(h)))
    {
        cout << h << endl;
    }
    ifs.close();
}
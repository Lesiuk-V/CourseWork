#pragma once
#include "Human.h"
class Citizen : public Human
{
private:
    static int numberDocument;
    static char typeOfDocument[20];
    char dateOfExpiry[11];
public:
    virtual void create() override;
    virtual void showData() override;
    void read(int pn);
    void write();
    void set_data_and_number(int n);
    static int count();
    void searchName();
    void searchSurname();
    void searchPatronymic();
    void searchNationality();
    void searchDateOfBirth();
    void searchDN();
    void deleteData();
    void editData();
};
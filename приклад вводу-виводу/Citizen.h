#pragma once
#include "Human.h"
class Citizen : public Human
{
private:
    int numberDocument=0;
    static char typeOfDocument[20];
    char dateOfExpiry[11];
public:
    virtual void create() override;
    virtual void showData() override;
    void read(int pn);
    void write();
    void set_data_and_number(int n);
    static int count();
    int search(int variant);
    void deleteData();
    void editData();
};
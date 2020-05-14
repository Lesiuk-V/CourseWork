#pragma once
#include "Human.h"
class TemporaryCitizen : public Human
{
private:
    int numberDocument = 1;
    static char typeOfDocument[30];
    char dateOfExpiry[11];
public:
    virtual void create() override;
    virtual void showData() override;
    void read(int pn);
    void write();
    void set_data_and_number(int n);
    static int count();
    int search(int);
    void deleteData();
    void editData();
};


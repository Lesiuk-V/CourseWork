#pragma once
#include "Human.h"
class TemporaryCitizen : public Human
{
private:
    int numberDocument;
    static char typeOfDocument[30];
    char dateOfExpiry[11];
public:
    virtual void create() override;
    virtual void showData() override;
    void read(int pn);
    void write();   
    static int count();
    int search(int);
    void deleteData();
    void editData();
    int setNumberDocument();
};


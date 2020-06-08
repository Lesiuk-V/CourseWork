#pragma once
#include "Human.h"
class Citizen : public Human
{
private:
    int numberDocument;
    static char typeOfDocument[20];
    char dateOfExpiry[11];
public:
    virtual void create(int) override;
    virtual void showData() override;
    void read(int pn);
    void write();
    static int count();
    int search(int variant);
    void deleteData();
    void editData();    
    int setNumberDocument();
};  
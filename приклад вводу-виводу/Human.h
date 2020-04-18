#pragma once
class Human
{
protected:
    char  name[40];
    char surname[40];
    char patronymic[40];
    char nationality[40];
    char dateOfBirth[11];
public:
    virtual void create();
    virtual void showData();
};
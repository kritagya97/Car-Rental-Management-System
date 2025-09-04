#ifndef AUTH_H_INCLUDED
#define AUTH_H_INCLUDED

#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include"layout.h"

using namespace std;
class Authentication{

public:
        bool admin_authentication(const string& adminUser, const string& adminPass);
        bool user_authentication(const string& inputUser, const string& inputPass);
        void signup();

        string getHiddenPassword();

        bool userLogin();
        bool adminLogin();

        Decorate d;


};


#endif // AUTH_H_INCLUDED

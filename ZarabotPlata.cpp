// ZarabotPlata.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>

using namespace std;

struct Sotrudnic {

    string name;
    string lastname;
    string surname;
    int tab_number;
    int year;
    int month;
    int work_hours;
    int tarif;

};

const string FILE_OF_DATA = "sotrudnik.txt";
const int RESERVE_SIZE = 100;
   void main()
    {        setlocale(LC_ALL, "rus");

        string login_admin = "admin";
        string password_admin = "admin";
        string login_user;
        string password_user;
        string login;
        string password;
        int mode;

       TryAgain:
       cout << "========Авторизируйтесь=========\n";
       
       cout << "Логин: ";
       cin >> login;
       cout << "Пароль: ";
       cin >> password;
       system("cls");

       if (login == login_admin && password == password_admin) {

           cout << "====================МЕНЮ=========================\n";
           cout << "1. Добавить сотрудника\n";
           cout << "2. Удалить сотрудника\n";
           cout << "3. Высчитать заработную плату сотрудников\n";
           cout << "4. Просмотр всех сотрудников\n";
           cout << "5. Просмотр сотрудника по табельному номеру\n";
           cout << "6. Просмотр сотрудника по Фамилии\n";
           cin >> mode;

           switch (mode)
           {
           case 1: 
           case 2:
           case 3:
           case 4:
           case 5:
           case 6:
           default:
               break;
           }
              
       }
       else if (login == login_user && password == password_user) {

           cout << "====================МЕНЮ=========================\n";
           cout << "1. Высчитать заработную плату сотрудников\n";
           cout << "2. Просмотр всех сотрудников\n";
           cout << "3. Просмотр сотрудника по табельному номеру\n";
           cout << "4. Просмотр сотрудника по Фамилии\n";
           cin >> mode;

           switch (mode)
           {
           case 1:
           case 2:
           case 3:
           case 4:
           default:
               break;
           }

       
       }
       else {
           system("cls");
           cout << "Неверный логин и пароль!\n";
           goto TryAgain;
       
       }



}


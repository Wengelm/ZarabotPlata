// ZarabotPlata.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include "SotrudnicStruct.cpp"
#include "UserStruct.cpp"


using namespace std;
const int RESERVE_SIZE = 100;
const string FILE_OF_DATA_USER = "user.txt";
const string FILE_OF_DATA_SODTRUDNIC = "sotrudnik.txt";

void readFileUser(User* array_of_user, int& number_of_user, int RESERVE_SIZE_USER);
void readFileSotrudnic(Sotrudnic* array_of_user, int& number_sotrudnic);
void auth(User* array_of_user, int& number_of_user, string input_login, string input_password, int& current_role, string& current_login);
void writeEndFileUser(User new_user);
void writeFileUser(User* array_of_user, int& number_of_user);
void writeEndFileSotrudnic(Sotrudnic new_sotrudnic);
void writeFileSotrudnic(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void showSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void getZarplata(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void getSotrudnicByTabel(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void getSotrudnicByFamily(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void getSotrudnicByMonth(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void showUserInArray(User* array_of_user, int& number_of_user);
void addSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void addUserInArray(User* array_of_user, int& number_user);

void editUserInArray(User* array_of_user, int& number_user);
void delUserInArray(User* array_of_user, int& number_user);
void delSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);
void editSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc);

void main()
{
    setlocale(LC_ALL, "rus");
    int mode;
    int mode_find_for_user;
    int mode_user;
    int mode_admin_case1;
    int mode_admin_case2;
    int mode_admin_case3;
    Sotrudnic array_of_sotrudnic[RESERVE_SIZE];
    User array_of_users[RESERVE_SIZE];
    int number_sotrudnic = 0;
    int number_of_user = 0;
    string input_login;
    string input_password;
    string current_login;
    int current_role=3;
   


    auth:
    cout << "========Авторизируйтесь=========\n";

    cout << "Логин: ";
    cin >> input_login;
    cout << "Пароль: ";
    cin >> input_password;


    readFileSotrudnic(array_of_sotrudnic, number_sotrudnic);
    readFileUser(array_of_users, number_of_user, RESERVE_SIZE);
    auth(array_of_users, number_of_user, input_login, input_password, current_role, current_login);

     menu:
        switch (current_role)
        {
        case 0:
            system("cls");
            cout << "====================ГЛАВНОЕ МЕНЮ=========================\n";
            cout << "1. Управление учетными записями.\n";
            cout << "2. Управление сотрудниками.\n";
            cout << "3. Поиск сотрудников и рассчет заработной платы.\n";
            cout << "4. Выход.\n";
            cin >> mode;
            switch (mode)
            {
            case 1:

                system("cls");
                cout << "====================МЕНЮ=========================\n";
                cout << "1. Добавить учетную запись.\n";
                cout << "2. Удалить учетную запись.\n";
                cout << "3. Редактировать учетную запись.\n";
                cout << "4. Просмотр учетных записей.\n";
                cout << "5. Вернуться в главное меню.\n";
                cin >> mode_admin_case1;

                switch (mode_admin_case1)
                {
                case 1:

                    addUserInArray(array_of_users, number_of_user);
                    goto menu;
                case 2:
                    delUserInArray(array_of_users, number_of_user);
                case 3:
                    editUserInArray(array_of_users, number_of_user);
                    goto menu;
                case 4:
                    system("cls");
                    cout << "|  ЛОГИН  |  ПАРОЛЬ |  РОЛЬ |  \n\n\n";
                    showUserInArray(array_of_users, number_of_user);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.    ";
                    system("pause");
                    goto menu;
                case 5:
                    system("cls");
                    goto menu;
                default:
                    break;
                }
            case 2:

                system("cls");
                cout << "====================МЕНЮ=========================\n";
                cout << "1. Добавить сотрудника.\n";
                cout << "2. Удалить сотрудника.\n";
                cout << "3. Редактировать редактировать сотрудника.\n";
                cout << "4. Просмотр просмотр сотрудников.\n";
                cout << "5. Вернуться в главное меню.\n";
                cin >> mode_admin_case2;

                switch (mode_admin_case2)
                {
                case 1:

                    addSotrudnikInArray(array_of_sotrudnic, number_sotrudnic);
                    system("pause");
                    goto menu;
                case 2:
                    delSotrudnikInArray(array_of_sotrudnic, number_sotrudnic);
                case 3:
                    editSotrudnikInArray(array_of_sotrudnic, number_sotrudnic);
                    goto menu;
                case 4:
                    system("cls");
                    cout << "|  ФАМИЛИЯ  |  ИМЯ  |  ОТВЕЧСТВО  |  ТАБ. НОМЕР  | ГОД | МЕСЯЦ | Отработанные часы | Тарифная ставка |\n\n\n";
                    showSotrudnikInArray(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.    ";
                    system("pause");
                    goto menu;
                case 5:
                    system("cls");
                    goto menu;
                default:
                    break;
                }
            


            case 3:

                system("cls");
                cout << "====================МЕНЮ=========================\n";
                cout << "1. Рассчитать зарплату всем сотрудникам.\n";
                cout << "2. Рассчитать зарплату по табельному номеру.\n";
                cout << "3. Рассчитать зарплату по фамилии\n";
                cout << "4. Рассчитать зарплату всем по номеру месяца\n";
                cout << "5. Вернуться в главное меню\n";

                cin >> mode_admin_case3;
                switch (mode_admin_case3)
                {
                case 1:
                    cout << "|  ФАМИЛИЯ  |  ИМЯ  |  ОТВЕЧСТВО  |  ТАБ. НОМЕР  | ГОД | МЕСЯЦ | Отработанные часы | Тарифная ставка | ЗП |\n\n\n";
                    getZarplata(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.    ";
                    system("pause");
                    goto menu;
                case 2:

                    getSotrudnicByTabel(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.   \n ";
                    system("pause");
                    goto menu;
                case 3:
                    getSotrudnicByFamily(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.   \n ";
                    system("pause");
                    goto menu;
                case 4:
                    getSotrudnicByMonth(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.   \n ";
                    system("pause");
                    goto menu;
                default:
                    break;
                }


            case 4:
                break;
            default:
                break;
            }

        case 1:
            system("cls");
            cout << "====================МЕНЮ=========================\n";
            cout << "1. Просмотр всех сотрудников\n";
            cout << "2. Рассчет заработной платы\n";
            cout << "3. Выход.\n";
            cin >> mode_user;

            switch (mode_user)
            {
            case 1:

                system("cls");
                cout << "|  ФАМИЛИЯ  |  ИМЯ  |  ОТВЕЧСТВО  |  ТАБ. НОМЕР  | ГОД | МЕСЯЦ | Отработанные часы | Тарифная ставка |\n\n\n";
               
                showSotrudnikInArray(array_of_sotrudnic, number_sotrudnic);
                cout << "Чтобы выйти в главное меню нажмите любую клавишу.    ";
                system("pause");
                goto menu;

            case 2:

                system("cls");
                cout << "====================МЕНЮ=========================\n";
                cout << "1. Рассчитать зарплату всем сотрудникам.\n";
                cout << "2. Рассчитать зарплату по табельному номеру.\n";
                cout << "3. Рассчитать зарплату по фамилии\n";
                cout << "4. Рассчитать зарплату всем по номеру месяца\n";
                cout << "5. Вернуться в главное меню\n";

                cin >> mode_find_for_user;
                switch (mode_find_for_user)
                {
                case 1: 
                    cout << "|  ФАМИЛИЯ  |  ИМЯ  |  ОТВЕЧСТВО  |  ТАБ. НОМЕР  | ГОД | МЕСЯЦ | Отработанные часы | Тарифная ставка | ЗП |\n\n\n";
                    getZarplata(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.    ";
                    system("pause");
                    goto menu;
                case 2:
                    
                    getSotrudnicByTabel(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.   \n ";
                    system("pause");
                    goto menu;
                case 3:
                    getSotrudnicByFamily(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.   \n ";
                    system("pause");
                    goto menu;
                case 4:
                    getSotrudnicByMonth(array_of_sotrudnic, number_sotrudnic);
                    cout << "Чтобы выйти в главное меню нажмите любую клавишу.   \n ";
                    system("pause");
                    goto menu;
                case 5:
                    goto menu;
                default:
                    break;
                }

            case 3:
                break;
            default:
                break;
            }

        default:
            break;
        }
    
    }

   

   




void auth(User* array_of_user, int& number_of_user, string input_login, string input_password, int& current_role, string& current_login) {
    

    for (int i = 0; i < number_of_user; i++) {

        if (array_of_user[i].login == input_login && array_of_user[i].password == input_password) {
            cout << "Авторизация успешна!";
            current_login = array_of_user[i].login;
            current_role = array_of_user[i].role;
            system("pause");
        }
        else cout << "Неверный логин или пароль. Пожалуйста повторите попытку.";

                   
              



    }
}
void readFileUser(User* array_of_user, int& number_of_user, int reserve_size_user) {
   

    ifstream fin(FILE_OF_DATA_USER, ios::in); // Открыли файл для чтения
    if (!fin.is_open()) cout << "Указанный файл c учетными записями не существует!" << endl;
    else
    {
        int i = 0;
        while (!fin.eof())
        {
            if (i < reserve_size_user)
            {
                fin >> array_of_user[i].login
                    >> array_of_user[i].password
                    >> array_of_user[i].role;

                i++;
            }
            else
            {
                cout << "Недостаточно памяти для чтения всех данных!" <<

                    endl;

                break;
            }
        }
        number_of_user = i;
    }
    fin.close(); //Закрыли файл


}
void writeEndFileUser(User new_user)
{
    ofstream fadd(FILE_OF_DATA_USER, ios::app); // Открыли файл для дозаписи
    fadd << endl;
    fadd << new_user.login << " "
        << new_user.password << " "
        << new_user.role;
    fadd.close();
}
void writeFileUser(User* array_of_user, int& number_of_user) {
    ofstream fout(FILE_OF_DATA_USER, ios::out);
    for (int i = 0; i < number_of_user; i++)
    {
        fout << array_of_user[i].login << " "
            << array_of_user[i].password << " "
            << array_of_user[i].role;
            
        if (i < number_of_user - 1)
        {
            fout << endl;
        }
    }
    fout.close();
}
void readFileSotrudnic(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {
    ifstream fin(FILE_OF_DATA_SODTRUDNIC, ios::in); // Открыли файл для чтения
    if (!fin.is_open()) cout << "Указанный файл не существует!" << endl;
    else
    {
        int i = 0;
        while (!fin.eof())
        {
            if (i < RESERVE_SIZE)
            {
                fin >> array_of_sotrudnic[i].name
                    >> array_of_sotrudnic[i].lastname
                    >> array_of_sotrudnic[i].surname
                    >> array_of_sotrudnic[i].tab_number
                    >> array_of_sotrudnic[i].year
                    >> array_of_sotrudnic[i].month
                    >> array_of_sotrudnic[i].work_hours
                    >> array_of_sotrudnic[i].tarif;
                i++;
            }
            else
            {
                cout << "Недостаточно памяти для чтения всех данных!" <<

                    endl;

                break;
            }
        }
        number_sotrudinc = i;
    }
    fin.close(); //Закрыли файл
}
void writeEndFileSotrudnic(Sotrudnic new_sotrudnic)
{
    ofstream fadd(FILE_OF_DATA_SODTRUDNIC, ios::app); // Открыли файл для дозаписи
    fadd << endl;
    fadd << new_sotrudnic.name << " "
        << new_sotrudnic.lastname << " "
        << new_sotrudnic.surname << " "
        << new_sotrudnic.tab_number << " "
        << new_sotrudnic.year << " "
        << new_sotrudnic.month << " "
        << new_sotrudnic.work_hours << " "
        << new_sotrudnic.tarif;
    fadd.close();
}
void writeFileSotrudnic(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {
    ofstream fout(FILE_OF_DATA_SODTRUDNIC, ios::out);
    for (int i = 0; i < number_sotrudinc; i++)
    {
        fout << array_of_sotrudnic[i].name << " "
            << array_of_sotrudnic[i].lastname << " "
            << array_of_sotrudnic[i].surname << " "
            << array_of_sotrudnic[i].tab_number << " "
            << array_of_sotrudnic[i].year << " "
            << array_of_sotrudnic[i].month << " "
            << array_of_sotrudnic[i].work_hours << " "
            << array_of_sotrudnic[i].tarif;
        if (i < number_sotrudinc - 1)
        {
            fout << endl;
        }
    }
    fout.close();
}
void showSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {

    for (int i = 0; i < number_sotrudinc; i++)
        cout << array_of_sotrudnic[i].lastname << "  |  "
        << array_of_sotrudnic[i].name << "  |  "
        << array_of_sotrudnic[i].surname << "  |  "
        << array_of_sotrudnic[i].tab_number << "  |  "
        << array_of_sotrudnic[i].year << "  |  "
        << array_of_sotrudnic[i].month << "  |  "
        << array_of_sotrudnic[i].work_hours << "  |  "
        << array_of_sotrudnic[i].tarif << "  |  " << endl;
}

void showUserInArray(User* array_of_user, int& number_of_user) {

    for (int i = 0; i < number_of_user; i++)
        cout << array_of_user[i].login << "  |  "
        << array_of_user[i].password << "  |  "
        << array_of_user[i].role << "  |  "
        << endl;
}

void getZarplata(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {

    int zarplata;
    long double viplata;

    for (int i = 0; i < number_sotrudinc; i++) {

        if (array_of_sotrudnic[i].work_hours > 144) {

            zarplata = (array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours);
            viplata = (zarplata * 2) / 100.0 * 12;

        }
        else {
            zarplata = (array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours);
            viplata = zarplata / 100.0 * 12;
        }


        cout << array_of_sotrudnic[i].name << "  |  "
            << array_of_sotrudnic[i].lastname << "  |  "
            << array_of_sotrudnic[i].surname << "  |  "
            << array_of_sotrudnic[i].tab_number << "  |  "
            << array_of_sotrudnic[i].year << "  |  "
            << array_of_sotrudnic[i].month << "  |  "
            << array_of_sotrudnic[i].work_hours << "  |  "
            << array_of_sotrudnic[i].tarif << "  |  "
            << viplata << " " << endl;
    }

}

void getSotrudnicByTabel(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {
    int zarplata;
    long double viplata;
    int tabel;
    cout << "Введите номер табеля ";
    cin >> tabel;
    cout << "|  ФАМИЛИЯ  |  ИМЯ  |  ОТВЕЧСТВО  |  ТАБ. НОМЕР  | ГОД | МЕСЯЦ | Отработанные часы | Тарифная ставка |\n\n\n";
    for (int i = 0; i < number_sotrudinc; i++) {

        if (tabel == array_of_sotrudnic[i].tab_number) {
            cout << array_of_sotrudnic[i].name << "  |  "
                << array_of_sotrudnic[i].lastname << "  |  "
                << array_of_sotrudnic[i].surname << "  |  "
                << array_of_sotrudnic[i].tab_number << "  |  "
                << array_of_sotrudnic[i].year << "  |  "
                << array_of_sotrudnic[i].month << "  |  "
                << array_of_sotrudnic[i].work_hours << "  |  "
                << array_of_sotrudnic[i].tarif << endl;

        }




        else  cout << "C Данным номером табеля нет сотрудников\n" << endl;

        if (array_of_sotrudnic[i].work_hours > 144) {
            zarplata = array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours;
            viplata = (zarplata * 2) / 100.0 * 12;
        }
        else {
            zarplata = array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours;
            viplata = zarplata / 100.0 * 12;
        }

        cout << "Заработная плата составит: " << viplata <<"\n";

    }
}
void getSotrudnicByFamily(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {
    int zarplata;
    long double viplata;
    string family;
    cout << "Введите фамилию сотрудника ";
    cin >> family;
    cout << "|  ФАМИЛИЯ  |  ИМЯ  |  ОТВЕЧСТВО  |  ТАБ. НОМЕР  | ГОД | МЕСЯЦ | Отработанные часы | Тарифная ставка |\n\n\n";
    for (int i = 0; i < number_sotrudinc; i++) {

        if (family == array_of_sotrudnic[i].lastname) {
            cout << array_of_sotrudnic[i].name << "  |  "
                << array_of_sotrudnic[i].lastname << "  |  "
                << array_of_sotrudnic[i].surname << "  |  "
                << array_of_sotrudnic[i].tab_number << "  |  "
                << array_of_sotrudnic[i].year << "  |  "
                << array_of_sotrudnic[i].month << "  |  "
                << array_of_sotrudnic[i].work_hours << "  |  "
                << array_of_sotrudnic[i].tarif << endl;

        }

        else  cout << "C данной фамилией сотрудника несуществует.\n" << endl;

        if (array_of_sotrudnic[i].work_hours > 144) {
            zarplata = array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours;
            viplata = (zarplata * 2) / 100.0 * 12;
        }
        else {
            zarplata = array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours;
            viplata = zarplata / 100.0 * 12;
        }

        cout << "Заработная плата составит: " << viplata << "\n";

    }
}

void getSotrudnicByMonth(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {
    int zarplata;
    long double viplata;
    int month;
    cout << "Введите фамилию сотрудника ";
    cin >> month;
    cout << "|  ФАМИЛИЯ  |  ИМЯ  |  ОТВЕЧСТВО  |  ТАБ. НОМЕР  | ГОД | МЕСЯЦ | Отработанные часы | Тарифная ставка |\n\n\n";
    for (int i = 0; i < number_sotrudinc; i++) {

        if (month == array_of_sotrudnic[i].month) {
            cout << array_of_sotrudnic[i].name << "  |  "
                << array_of_sotrudnic[i].lastname << "  |  "
                << array_of_sotrudnic[i].surname << "  |  "
                << array_of_sotrudnic[i].tab_number << "  |  "
                << array_of_sotrudnic[i].year << "  |  "
                << array_of_sotrudnic[i].month << "  |  "
                << array_of_sotrudnic[i].work_hours << "  |  "
                << array_of_sotrudnic[i].tarif << endl;

        }

        else  cout << "C данной фамилией сотрудника несуществует.\n" << endl;

        if (array_of_sotrudnic[i].work_hours > 144) {
            zarplata = array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours;
            viplata = (zarplata * 2) / 100.0 * 12;
        }
        else {
            zarplata = array_of_sotrudnic[i].tarif * array_of_sotrudnic[i].work_hours;
            viplata = zarplata / 100.0 * 12;
        }

        cout << "Заработная плата для " <<  array_of_sotrudnic[i].lastname << "составит: " << viplata << "\n";

    }
}

void addSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {
    if (number_sotrudinc + 1 <= RESERVE_SIZE) {

        number_sotrudinc++;
        cout << "Введите имя сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].name;
        cout << "Введите фамилию сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].lastname;
        cout << "Введите отчество сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].surname;
        cout << "Введите табельный номер сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].tab_number;
        cout << "Введите год сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].year;
        cout << "Введите номер месяца сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].month;
        cout << "Введите количество отработанных часов сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].work_hours;
        cout << "Введите тарифную ставку сотрудника:";
        cin >> array_of_sotrudnic[number_sotrudinc - 1].tarif;

        writeEndFileSotrudnic(array_of_sotrudnic[number_sotrudinc - 1]);
    }
    else cout << "Недостаточно памяти для добавления нового элемента!" << endl;


}

void addUserInArray(User* array_of_user, int& number_user) {
    if (number_user + 1 <= RESERVE_SIZE) {

        number_user++;
        cout << "Введите имя сотрудника:";
        cin >> array_of_user[number_user - 1].login;
        cout << "Введите фамилию сотрудника:";
        cin >> array_of_user[number_user - 1].password;
        cout << "Введите отчество сотрудника:";
        cin >> array_of_user[number_user - 1].role;
           
        writeEndFileUser(array_of_user[number_user - 1]);
    }
    else cout << "Недостаточно памяти для добавления нового элемента!" << endl;


}

void delSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {

    int number_of_deleted_item;
    cout << "Введите номер удаляемой записи: ";
    cin >> number_of_deleted_item;


    number_of_deleted_item--;
    if (number_of_deleted_item >= 0 &&
        number_of_deleted_item < number_sotrudinc)
    {
        for (int i = number_of_deleted_item; i < number_sotrudinc - 1; i++)
            array_of_sotrudnic[i] = array_of_sotrudnic[i + 1];
        number_sotrudinc--;
        writeFileSotrudnic(array_of_sotrudnic, number_sotrudinc);
    }
    else cout << "Введен некорректный номер удалемой записи!" << endl;
}

void delUserInArray(User* array_of_user, int& number_user) {

    int number_of_deleted_item;
    cout << "Введите номер удаляемой записи: ";
    cin >> number_of_deleted_item;


    number_of_deleted_item--;
    if (number_of_deleted_item >= 0 &&
        number_of_deleted_item < number_user)
    {
        for (int i = number_of_deleted_item; i < number_user - 1; i++)
            array_of_user[i] = array_of_user[i + 1];
        number_user--;
        writeFileUser(array_of_user, number_user);
    }
    else cout << "Введен некорректный номер удалемой записи!" << endl;
}

void editUserInArray(User* array_of_user, int& number_user) {

    int number_of_edit_item;
 
    cout << "Введите номер редактируемой записи: ";
    cin >> number_of_edit_item;
    number_of_edit_item--;
    for (int i = 0; i < number_user; i++) {

        if (number_of_edit_item == number_user) {
        
        } else cout << "Такого пользователя нет: ";
    }
    cout << "Введите новый логин: ";
    cin >> array_of_user[number_of_edit_item].login;
   
    cout << "Введите новый пароль: ";
    cin >> array_of_user[number_of_edit_item].password;
    
    cout << "Введите новую роль (0 = admin, 1 = user): ";
    cin >> array_of_user[number_of_edit_item].role;
    


        writeFileUser(array_of_user, number_user);
    
}

void editSotrudnikInArray(Sotrudnic* array_of_sotrudnic, int& number_sotrudinc) {

    int number_of_edit;
    cout << "Введите номер редактируемой записи: ";
    cin >> number_of_edit;


    number_of_edit--;
    cout << "Введите имя сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].name;
    cout << "Введите фамилию сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].lastname;
    cout << "Введите отчество сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].surname;
    cout << "Введите табельный номер сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].tab_number;
    cout << "Введите год сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].year;
    cout << "Введите номер месяца сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].month;
    cout << "Введите количество отработанных часов сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].work_hours;
    cout << "Введите тарифную ставку сотрудника:";
    cin >> array_of_sotrudnic[number_of_edit].tarif;
    
}

   
    
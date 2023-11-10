#include <iostream>
#include <string.h>
#include "Train.h"

using namespace std;

Train::Train()
{
    this->destination = "None";
    this->train_number = "None";
    this->departure_time = "None";

    cout << "Вызван конструктор по умолчанию класса Train" << endl;
}

Train::Train(string destination, string train_number, string departure_time)
{
    this->destination = destination;
    this->train_number = train_number;
    this->departure_time = departure_time;

    cout << "Вызван конструктор с параметром класса Train" << endl;
}

Train::Train(const Train &t)
{
    this->destination = t.destination;
    this->train_number = t.train_number;
    this->departure_time = t.departure_time;

    cout << "Вызван конструктор копирования класса Train" << endl;
}

Train::~Train()
{
    cout << "Вызван деструктор класса Train" << endl;
}

void Train::Extract()
{
    cout << this;
}

void Train::Get()
{
    string choice;

    try
    {
        cout << "Что хотите получить?" <<
                "1 - Пункт назначения" <<
                "2 - Номер поезда" <<
                "3 - Время отправления" <<
                "4 - Все поля" << endl;
        cout << "Выбор: ";
        cin >> choice;

        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    if (choice == "1") cout << "Пункт назначения: " << this->destination << endl;
    else if (choice == "2") cout << "Номер поезда: " << this->train_number << endl;
    else if (choice == "3") cout << "Время отправления: " << this->departure_time << endl;
    else if (choice == "4") cout << "Пункт назначения: " << this->destination << "Номер поезда: " << this->train_number << "Время отправления: " << this->departure_time << endl;
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }

    getline(cin, choice); // обнуляем поток ввода
}

string Train::GetTime()
{
    return this->departure_time;
}

string Train::GetDestination()
{
    return this->destination;
}

string Train::GetTrainNumber()
{
    return this->train_number;
}

void Train::Set()
{
    cin >> *this;
}

void Train::Change()
{
    string choice;

    try
    {
        cout << "Что хотите изменить?" <<
                "1 - Пункт назначения" <<
                "2 - Номер поезда" <<
                "3 - Время отправления" <<
                "4 - Все поля" << endl;
        cout << "Выбор: ";
        cin >> choice;

        for (int id = 0; id < choice.size(); id ++)
        {
            if (choice[id] >= 'A' && choice[id] <= 'Z') throw "Error";
        }
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод" << endl;
    }

    getline(cin, choice); // обнуляем поток ввода

    if (choice == "1")
    {
        cout << "Пункт назначения: ";
        cin >> this->destination;
    }
    else if (choice == "2")
    {
        cout << "Номер поезда: ";
        cin >> this->train_number;
    }
    else if (choice == "3")
    {
        cout << "Время отправления: ";
        cin >> this->departure_time;
    }
    else
    {
        cout << "Ошибка выбора" << endl;
        exit(0);
    }

    getline(cin, choice); // обнуляем поток ввода
}

ostream &operator<< (ostream &stream, Train t) // перегрузка оператора извлеченния
{
    stream << "Все поля класса:" << endl;
    stream << t.destination << endl;
    stream << t.train_number << endl;
    stream << t.departure_time << endl;

    return stream;
}

istream &operator>> (istream &stream, Train &t) // перегрузка оператора вставки
{
    cout << "Вставка значений:" << endl;
    cout << "Пункт назначения: ";
    stream >> t.destination;
    cout << "Номер поезда: ";
    stream >> t.train_number;
    cout << "Время отпрвления: ";
    stream >> t.departure_time;
    string buf;
    getline(stream, buf); // обнуляем поток ввода
    return stream;
}

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

void Train::Insert()
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

void Train::Set()
{
    cin >> *this;
}

void Train::Change()
{

}

ostream &operator<< (ostream &stream, Train t) // перегрузка оператора извлеченния
{

}

iostream &operator>> (istream &stream, Train &t) // перегрузка оператора вставки
{

}

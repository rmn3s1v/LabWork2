#include <iostream>
#include <string>
#include <algorithm>
#include "Storage.h"
#include "Train.h"

using namespace std;

Store::Store()
{
    this->array = new Train*[1];
    this->countElement = 0;
    cout << "Вызван конструктор по умолчанию класса Store" << endl;
}

Store::Store(int size)
{
    this->array = new Train*[size];
    this->countElement = 0;
    cout << "Вызван конструктор c параметром класса Store" << endl;
}
Store::Store(const Store &s)
{
    this->countElement = s.countElement;
    this->array = new Train*[this->countElement];

    for (int id = 0; id < this->countElement; id++) this->array[id] = s.array[id];

    cout << "Вызван конструктор копирования класса Store" << endl;
}

Store::~Store()
{
    delete [] array;
    cout << "Вызван деструктор класса Store" << endl;
}

// сортировка массива
void Store::SortedArray()
{
    for (int id1 = 0; id1 < countElement - 1; id1++)
    {
        for (int id2 = id1 + 1; id2 < countElement; id2++)
        {
            if (array[id1]->GetTime() > array[id2]->GetTime())
            {
                Train *buf = array[id1];
                array[id1] = array[id2];
                array[id2] = buf;
            }
        }
    }
}

// поиск
void Store::FindTrain()
{
    string findDestination;
    cout << "Чтобы узнать информацию о поездах, введите пунк назначения: ";
    cin >> findDestination;

    int flagFind = 0;

    cout << "~Информация о поездах~" << endl;

    for (int id = 0; id < countElement; id++)
    {

        if (findDestination == array[id]->GetDestination())
        {
            flagFind = 1;
            cout << array[id]->GetTrainNumber() << endl;
        }
    }

    if (!flagFind) cout << "Поездов по такому маршруту нет!" << endl;

    getline(cin, findDestination); // обнуляем поток ввода
}

// извлечение значения
void Store::ExtractField()
{
    for (int id = 0; id < countElement; id++) array[id]->Extract();
}

// получение полей
void Store::GetFiel()
{
    string choice;
    cout << "Введите номер элемента, поля которого вы хотите вывести: ";
    cin >> choice;

    try
    {
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";

        if (!all_of(choice.begin(), choice.end(), ::isdigit)) throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Неверный ввод!" << endl;
    }

    if (choice > to_string(countElement) or choice < "0")
    {
        cout << "Ошибка ввода" << endl;
        exit(0);
    }

    else
    {
        int idChoice = stoi(choice);
        array[idChoice]->Get();
    }
}

// метод установки значения
void Store::Set()
{
    Train *train;
    train->Set();
    array[countElement++] = train;
}

// метод изменения значения
void Store::Change()
{
    cout << "Выберете номер элемента, данные которого хотите изменить: ";
    string choice;

    try
    {
        cin >> choice;
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Ошибка ввода!" << endl;
        exit(0);
    }

    array[stoi(choice)]->Change();

    getline(cin, choice);
}

// метод удаления
void Store::Delete()
{
    cout << "Выберете номер элемента, данные которого хотите удалить: ";
    string choice;

    try
    {
        cin >> choice;
        for (int id = 0; id < choice.size(); id++) if (isalpha(choice[id])) throw "Error";
        if (choice > to_string(countElement) or choice < "0") throw "Error";
    }
    catch(const char*mssg)
    {
        cout << "Ошибка ввода!" << endl;
        exit(0);
    }

    for (int id = stoi(choice); id < countElement - 1; id++) array[id] = array[id+1];

    getline(cin, choice);
}

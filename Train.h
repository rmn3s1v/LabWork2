#include <iostream>
#include <string.h>
using namespace std;

class Train
{
private:
    string destination; // пункт назначение
    string train_number; // номер поезда
    string departure_time; // время отправления

public:
    Train(); // конструктор по умолчанию
    Train(string destination, string train_number, string departure_time); // конструктор с параметром
    Train(const Train &t); // конструктор копирования
    ~Train(); // деструктор

    void Insert(); // метод вставки (добавление значений)
    void Get(); // метод получения полей
    void Set(); // метод установки значения
    void Change(); // метод редактирования значений

    friend ostream &operator<< (ostream &stream, Train t); // перегрузка оператора извлеченния
    friend iostream &operator>> (istream &stream, Train &t); // перегрузка оператора вставки
};

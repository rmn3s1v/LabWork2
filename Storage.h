#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <string>
#include "Train.h"

using namespace std;

class Store
{
private:
    Train **array;
    int countElement;

public:
    Store();
    Store(int size);
    Store(const Store &s);
    ~Store();

    void SortedArray(); // сортировка после ввода
    void FindTrain(); // поиск по пункту назначения
    void ExtractField(); // извлечь значения объекта
    void GetFiel(); // получить поля
    void Set(); // вставить значение объекта
    void Change(); // изменить значение
    void Delete(); // удалить значние
};

#endif

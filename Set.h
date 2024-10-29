#include <iostream>
#include <stdint.h>
#include "BitField.h"
#include <vector>

class Set {
private:
    size_t _maxPower;       // максимальная мощность множества
    BitField _bitField; // битовое поле для хранения характеристического вектора
public:
    Set(size_t mp);
    Set(const Set& set);
    Set(const BitField& bf); //// конструктор преобразования типа
    operator BitField();  //static_cast   преобразование типа к битовому полю

    // доступ к битам
    size_t GetMaxPower(void) const;     // максимальная мощность множества
    void InsElem(const uint64_t Elem);       // включить элемент в множество
    void DelElem(const uint64_t Elem);       // удалить элемент из множества
    bool IsMember(const uint64_t Elem) const; // проверить наличие элемента в множестве
    
  // теоретико-множественные операции
    bool operator== (const Set &s) const; // сравнение. пофиг на размер
    bool operator!= (const Set &s) const; // сравнение
    Set& operator=(const Set &s);  // присваивание
    Set operator+ (const uint64_t Elem); // объединение с элементом
                                   // элемент должен быть из того же универса
    Set operator- (const uint64_t Elem); // разность с элементом
                                   // элемент должен быть из того же универса
    Set operator+ (const Set &s);  // объединение
    Set operator* (const Set &s);  // пересечение
    Set operator~ ();           // дополнение

    std::vector<uint64_t> GetPrimary();

    friend std::istream& operator>>(std::istream& istr, Set& set);
    friend std::istream& operator<<(std::istream& istr, const Set& set);

};
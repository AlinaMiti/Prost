#include "Set.h"
#include "BitField.h"
#include <vector>
#include <math.h>
#include <stdint.h>

Set::Set(size_t mp) : _bitField(mp){
    _maxPower = mp;
}

Set::Set(const Set& set) : _bitField(set._maxPower){
    _maxPower = set._maxPower;
    _bitField = set._bitField;
}
   
Set::Set(const BitField& bf) : _bitField(bf){
    _maxPower = bf.GetLength();
}

void Set::InsElem(uint64_t elem){
    if (elem >= _maxPower) 
        throw std::out_of_range("33Element out of range!");
    _bitField.SetBit(elem);
}

void Set::DelElem(uint64_t elem){
    if (elem >= _maxPower) 
        throw std::out_of_range("44Element out of range!");
    _bitField.ClrBit(elem);
}

bool Set::IsMember(uint64_t elem) const{
    if (elem >= _maxPower) 
        throw std::out_of_range("55Element out of range!");
    return _bitField.GetBit(elem);
}

size_t Set::GetMaxPower() const{
    return _maxPower;
}

Set::operator BitField(){
    return _bitField;
}

bool Set::operator==(const Set& s) const{
    return BitField(_bitField) == s._bitField;
}

bool Set::operator!=(const Set& s) const{
    if (BitField(_bitField) == s._bitField)
        return false;
    return true;
}

Set& Set::operator=(const Set& tmp){
    _maxPower = tmp._maxPower;
    _bitField = tmp._bitField;
    return *this;
}

Set Set::operator+(const Set& tmp){
    return _bitField | tmp._bitField;
}

Set Set::operator+(uint64_t elem){
    Set s(*this);
    s.InsElem(elem);
    return s;
}

Set Set::operator-(uint64_t elem){
    Set s(*this);
    s.DelElem(elem);
    return s;
}

Set Set::operator*(const Set& ymp){
    return _bitField & ymp._bitField;
}

Set Set::operator~(){
    return Set(~_bitField);
}

std::vector<uint64_t> Set::GetPrimary(){
    std::vector<uint64_t> prost;
    Set copy(*this);
    size_t size = copy.GetMaxPower();

    for(size_t i = 2; i < size; i++){
        if(copy.IsMember(i)){
            prost.push_back(i);
            for(size_t p = i*i; p < size; p += i){
                copy._bitField.ClrBit(p);
            }
        }
    }
    // for(size_t i = 2; i < size; i++){
    //     if(copy.IsMember(i))
    //         prost.push_back(i);
    // }  
    return prost;      
}
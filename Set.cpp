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
};

void Set::InsertElem(uint64_t elem){
    if (elem >= _maxPower) throw std::out_of_range("33Element out of range!");
    _bitField.SetBit(elem);
}

void Set::DeleteElem(uint64_t elem){
    if (elem >= _maxPower) throw std::out_of_range("44Element out of range!");
    _bitField.ClrBit(elem);
}

bool Set::IsMember(uint64_t elem){
    if (elem >= _maxPower) throw std::out_of_range("55Element out of range!");
    return _bitField.GetBit(elem);
}

size_t Set::GetMaxPower(){
    return _maxPower;
}

std::vector<uint64_t> Set::GetPrimary(){
    std::vector<uint64_t> prost;
    Set copy(*this);
    size_t size = copy.GetMaxPower();

    for(size_t i = 2; i <= size; ++i){
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
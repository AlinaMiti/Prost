#include <iostream>
#include "Set.h"
#include "BitField.h"
#include <vector>


int main() {
    /*uint16_t a = 1;
    //a = a << 10;
    std::cout << a << std::endl;
    uint8_t b = 0;
    b = static_cast<uint8_t>(a);
    std::cout << static_cast<uint32_t>(b) << std::endl;
    */

    size_t size = 100;
    Set m(size);

    try {
        for (size_t i = 0; i < size - 1; i++)
            m.InsertElem(i);

        std::vector<uint64_t> vec = m.GetPrimary();
        for (size_t i = 0; i < vec.size(); i++)
            std::cout << vec[i] << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }


    // size_t size = 10;
    // Set m(size);
    // for (size_t i = 0; i < size; i++)
    //     m.InsertElem(i);

    // std::vector<uint64_t> vec = m.GetPrimary();
    // for (size_t i = 0; i < vec.size(); i++)
    //     std::cout << vec[i] << std::endl;


    return 0;
}
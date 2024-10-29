#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}







// #include <iostream>
// #include <stdint.h>
// #include "BitField.h"
// #include "Set.h"


// int main() {
//     uint16_t a = 1;
//     //a = a << 10;
//     std::cout << a << std::endl;
//     uint8_t b = 0;
//     b = static_cast<uint8_t>(a);
//     std::cout << static_cast<uint32_t>(b) << std::endl;
//     return 0;
// }
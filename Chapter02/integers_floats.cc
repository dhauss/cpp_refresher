#include <cstdint>
#include <iostream>

int main()
{
    int i = 0;  // bit size depends on compiler/platform

    std::int8_t i1 = 0;
    std::uint8_t u1 = 0U;

    std::int16_t i2 = 0;
    std::uint16_t u2 = 0U;

    std::int32_t i3 = 0;
    std::uint32_t u3 = 0U;

    std::int64_t i4 = 0;
    std::uint64_t u4 = 0;

    float f1 = 12.0F;    // 32 bit
    double d1 = 12.0;   // 64 bit

    bool b1 = true;
    bool b2 = false;

    char c1 = 'a';

    return 0;
}

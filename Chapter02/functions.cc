#include <cstdint>
#include <iostream>

void printer(std::uint16_t); 

int main()
{
    printer(42);

    return 0;
}

void printer(std::uint16_t val){
    std::cout << val << '\n';
}
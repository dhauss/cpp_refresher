#include <cstdint>
#include <iterator>
#include <vector>

#include "IteratorLib.h"

namespace mystd{

    void advance(It &it, DifferenceType n)
    {
        if(n >= 0)
        {
            for(std::size_t i = 0; i < n; i++)
            {
                ++it;
            }
        } else{

            for(std::int32_t i = n; i <= 0; i++)
            {
                --it;
            }
        }
    }
    /*
    DifferenceType distance(It first, It last)
    {
    }
    
    It next(It it, DifferenceType n = 1)
    {
    }
    
    It prev(It it, DifferenceType n = 1)
    {
    }
*/
} // mystd
#include <cstdint>
#include <iterator>
#include <vector>
#include <iostream>

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
        } else
        {
            for(std::int32_t i = n; i <= 0; i++)
            {
                --it;
            }
        }
    }

    DifferenceType distance(It first, It last)
    {
        // return std::distance(first, last);
        auto first_address = &(*first);
        auto last_address = &(*last);

        return static_cast<DifferenceType>(last_address - first_address);

    }
    
    
    It next(It it, DifferenceType n)
    {
        mystd::advance(it, n);
        return it;
    }
    
    It prev(It it, DifferenceType n)
    {
        mystd::advance(it, -n);
        return it;
    }

} // mystd
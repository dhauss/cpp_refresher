#include <iostream>
#include <vector>
#include <array>
#include "IteratorLib.h"

int main()
{

    auto vector = std::vector<int>{1, 2, 3};
    auto vector_it = vector.begin();
    auto vector_end = vector.end();

    auto next_it = mystd::next(vector_it);
    std::cout << "*next_it: " << *next_it << '\n';

    auto prev_it = mystd::prev(next_it);
    std::cout << "*prev_it: " << *prev_it << '\n';

    mystd::advance(vector_it, 2);
    std::cout << "advance: " << *vector_it << '\n';

    mystd::advance(vector_end, -2);
    std::cout << "advance: " << *vector_end << '\n';

    auto dist = mystd::distance(vector_it, vector.begin());
    std::cout << "distance: " << dist << '\n';

    auto dist2 = mystd::distance(vector.begin(), --vector.end());
    std::cout << "distance: " << dist2 << '\n';

    auto large_vector = std::vector<std::int32_t>(10000000000, 0);

    auto dist4 = mystd::distance(large_vector.begin(), --large_vector.end());
    std::cout << "distance: " << dist4 << '\n';

    auto dist3 = mystd::distance(--large_vector.end(), large_vector.begin());
    std::cout << "distance: " << dist3 << '\n';

    return 0;
}

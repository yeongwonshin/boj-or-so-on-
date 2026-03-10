#include <initializer_list>

template<typename T>
T my_min(std::initializer_list<T> lst) {
    auto it = lst.begin();
    T min_val = *it;  // 첫 원소를 기준값으로 설정

    ++it;
    for (; it != lst.end(); ++it) {
        if (*it < min_val)
            min_val = *it;
    }

    return min_val;
}
#ifndef LEETCODE_NUM_TYPE_H
#define LEETCODE_NUM_TYPE_H

#include "data.h"

using namespace std;

template<class T>
struct NumType {
    T value;
    bool isNull;

    NumType(string s) {
        if (s == "null") {
            isNull = true;
        } else {
            isNull = false;
            value = Data<T>(s);
        }
    }

    operator T const *() const {
        return isNull ? nullptr : &value;
    }
};

#endif //LEETCODE_NUM_TYPE_H

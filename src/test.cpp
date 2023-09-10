#include "library.h"
#include <bits/stdc++.h>

class Solution {
public:
    int test1(int val) {
        return val;
    }
    vector<int> test2(int x, int y) {
        return vector<int>{x, y};
    }
    vector<int> test3(vector<int> val) {
        return val;
    }
    vector<int> test4(vector<int>& val) {
        return val;
    }
    vector<vector<int>> test5(vector<int> &val1,vector<int> &val2) {
        return {val1,val2};
    }
    vector<vector<int>> test6(vector<int>& val1, int i) {
        return {val1, {i}};
    }
    vector<vector<int>> test7(vector<int> &val1, vector<int>& val2, vector<int>& val3, int i) {
        return {val1,val2, val3, {i}};
    }
};

template<class T>
class MyIter{
private:
    T* ptr;
public:
    typedef T value_type;   // 内嵌类型声明
    MyIter (T* ptr = nullptr) : ptr(ptr) {}
    T& operator* () {return *ptr;}
    // ...
};

template<class I>
struct iterator_trait {
    typedef typename I::value_type value_type;
    // ...
};

template<class T>
struct iterator_trait<T*> {
    typedef T value_type;
    // ...
};

//template<class T>
//struct iterator_trait<const T*>: iterator_trait<T*> {};

template<class I>
typename iterator_trait<I>::value_type
func(I iter){
    typename I::value_type res;
    // ...
    return res;
}
void ff(int &&a) {cout << ++a;}

int main() {
    int x = 1, &y=x, &&z=1, &g=z;
    z = 2;
    auto & a = y;
//    ff(x);
//    ff(y);
//    ff(z);
//    ff(1);
//    lower_bound()
//    MyIter<int> iter(&x);
//    // ...
//    typename iterator_trait<const MyIter<int>>::value_type y = 2;
//    y = 3;
//    cout << y;
//    Test().print();
//
//    cout << func(iter);
//    cout << "test1" << endl;
//    test (&Solution::test1, {"1"});
//    cout << endl;
}
//int main() {
//
//    cout << "test2" << endl;
//    test (&Solution::test2, {"1 2"});
//    cout << endl;
//
//    cout << "test3" << endl;
//    test (&Solution::test3, {"[1]","[]","[1,2,3]"});
//    cout << endl;
//
//    cout << "test4" << endl;
//    test (&Solution::test4, {"[1]","[]","[1,2,3]"});
//    cout << endl;
//
//    cout << "test5" << endl;
//    test (&Solution::test5, {"[1,2,3] [4,5]","[1] []","[] [1]"});
//    cout << endl;
//
//    cout << "test6" << endl;
//    test (&Solution::test6, {"[1] 3"});
//    cout << endl;
//
//    cout << "test7" << endl;
//    test (&Solution::test7, {"[1] [2] [3] 4"});
//    cout << endl;
//    map<int, int> m;
//    m[1] = 2;
//    for (auto [k, v]: m) {
//        cout << k << v;
//    }
//}
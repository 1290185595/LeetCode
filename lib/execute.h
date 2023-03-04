#ifndef LEETCODE_EXECUTE_H
#define LEETCODE_EXECUTE_H

template<int ...I>
struct Sequence {
};
template<int S, int N, int ...I>
struct SeqHelper : SeqHelper<S, N - 1, N - 1, I...> {
};
template<int S, int...I>
struct SeqHelper<S, S, I...> {
    typedef Sequence<I...> sequence;
};

template<class R> class Execute;
template<class R, class T, class ...Args>
class Execute<R(T::*)(Args...)> {
private:
    R (T::*f)(Args...);

    template<int ...I>
    R operator()(istream &in, T t, Sequence<I...> &&) {
        auto data = Data < Args... > (in);
        return bind(f, t, get<I>(tuple<Args...>(data))...)();
    }

public:
    Execute(R(T::*f)(Args...)) {
        this->f = f;
    }

    R operator()(T t, Args...args) {
        return bind(f, t, args...)();
    }

    R operator()(istream &in, T t) {
        return (*this)(in, t, typename SeqHelper<0, sizeof...(Args)>::sequence());
    }

    R operator()(const string &s, T t) {
        stringstream in;
        in << s;
        return (*this)(in, t);
    }
};

template<class R, class T, class ...Args>
void test(R(T::*f)(Args...), vector<string> const & testcases) {
    T t;
    Execute<R(T::*)(Args...)> execute(f);
    for (string testcase: testcases) {
        cout << testcase << " => " << execute(testcase, t) << endl;
    }
}
template< class T, class ...Args>
void test(bool(T::*f)(Args...), vector<string> const & testcases) {
    T t;
    Execute<bool(T::*)(Args...)> execute(f);
    for (string testcase: testcases) {
        cout << testcase << " => " << (execute(testcase, t) ? "true":"false") << endl;
    }
}
#endif //LEETCODE_EXECUTE_H

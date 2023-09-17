#ifndef LEETCODE_DATA_H
#define LEETCODE_DATA_H


template<class ...Args>
class Data;

template<class T>
class Data<T> {
private:
    T data;
public:
    Data() = default;

    explicit Data(string &s) {
        data = T(s);
    }

    explicit Data(const char data[]) {
        string s(data);
        new(this)Data(s);
    }

    explicit Data(istream &in) {
        string s;
        in >> s;
        new(this)Data(s);
    }

    operator T &() {
        return data;
    }

    explicit operator tuple<T> &() {
        return make_tuple(data);
    }

    explicit operator tuple<T &> &() {
        return make_tuple(data);
    }
};

template<class T>
class Data<vector<T>> {
private:
    vector<T> data;
public:
    Data() = default;

    explicit Data(string s) {
        if (s == "[]") return;
        s.pop_back();
        s.push_back(',');
        int deep = 0;
        string temp;
        auto p = s.begin();
        while (++p != s.end()) {
            if (*p == ',' && deep == 0) {
                data.push_back(Data<T>(temp));
                temp.clear();
            } else {
                temp.push_back(*p);
                if (*p == '[') deep++;
                else if (*p == ']') deep--;
            }
        }
    }

    explicit Data(const char data[]) {
        string s(data);
        new(this)Data(s);
    }

    explicit Data(istream &in) {
        string s;
        in >> s;
        new(this)Data(s);
    }

    operator vector<T> &() {
        return data;
    }

    explicit operator tuple<vector<T>>() {
        return make_tuple(data);
    }

    explicit operator tuple<vector<T> &>() {
        return make_tuple(data);
    }
};

template<class T>
class Data<T &> : public Data<T> {
    using Data<T>::Data;
};


template<class T1, class T2, class ...Args>
class Data<T1, T2, Args...> {
private:
    Data<T1> t1;
    Data<T2, Args...> *t2 = new Data<T2, Args...>();
    tuple<T1, T2, Args...> data = tuple_cat(tuple<T1>(t1), tuple<T2, Args...>(*t2));
public:
    Data() = default;

    explicit Data(istream &in) {
        t1 = Data<T1>(in);
        t2 = new Data<T2, Args...>(in);
        data = tuple_cat(tuple<T1>(t1), tuple<T2, Args...>(*t2));
    }

    explicit Data(string const &s) {
        stringstream in;
        in << s;
        new(this)Data(in);
    }

    operator tuple<T1, T2, Args...> &() {
        return data;
    }
};

template<>
Data<int>::Data(string &s) {
    data = stoi(s);
}
template<>
Data<long long >::Data(string &s) {
    data = stoll(s);
}

template<>
Data<float>::Data(string &s) {
    data = stof(s);
}

#endif //LEETCODE_DATA_H

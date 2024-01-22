#ifndef KISSTEST_H
#define KISSTEST_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

namespace KISSTEST {

using namespace std;

template <typename T, typename U>
ostream& operator<<(ostream& os, const pair<T, U> p) {
    os << p.first << ": "s << p.second;

    return os;
}

template <typename Container>
void Print(ostream& os, const Container& container) {
    bool is_first_element = true;
    for (const auto& element : container) {
        if (is_first_element) {
            is_first_element = false;
        } else {
            os << ", "s;
        }
        os << element;
    }
}

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& v) {
    os << "["s;
    Print(os, v);
    os << "]"s;

    return os;
}

template <typename T>
ostream& operator<<(ostream& os, const set<T>& s) {
    os << "{"s;
    Print(os, s);
    os << "}"s;

    return os;
}

template <typename T, typename U>
ostream& operator<<(ostream& os, const map<T, U>& m) {
    os << "{"s;
    Print(os, m);
    os << "}"s;

    return os;
}

void AssertImpl(bool expr,
                const string& expr_str,
                const string& file,
                const string& func,
                const unsigned& line,
                const string& hint) {
    if (!expr) {
        cerr << boolalpha;
        cerr << file << "("s << line << "): "s << func << ": "s;
        cerr << "ASSERT("s << expr_str << ") failed."s;
        if (!hint.empty()) {
            cerr << " Hint: "s << hint;
        }
        cerr << endl;
        abort();
    }
}

#define ASSERT(expr) AssertImpl((expr), #expr, __FILE__, __FUNCTION__, __LINE__, "")

#define ASSERT_HINT(expr, hint) AssertImpl((expr), #expr, __FILE__, __FUNCTION__, __LINE__, (hint))

template<typename T, typename U>
void AssertEqualImpl(const T& t, const U& u,
                     const string& t_str, const string& u_str,
                     const string& file,
                     const string& func,
                     const unsigned& line,
                     const string& hint) {
    if (u != t) {
        cerr << boolalpha;
        cerr << file << "("s << line << "): "s << func << ": "s;
        cerr << "ASSERT_EQUAL("s << t_str << ", "s << u_str << ") failed: "s;
        cerr << t << " != "s << u << "."s;
        if (!hint.empty()) {
            cerr << "Hint: "s << hint;
        }
        cerr << endl;
        abort();
    }
}

#define ASSERT_EQUAL(a, b) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, "")

#define ASSERT_EQUAL_HINT(a, b, hint) AssertEqualImpl((a), (b), #a, #b, __FILE__, __FUNCTION__, __LINE__, (hint))

template <typename Func>
void RunTestImpl(Func func, const string & func_str) {
    func();
    cerr << func_str << " OK"s << endl;;
}

#define RUN_TEST(func) RunTestImpl((func), #func)

}

#endif // KISSTEST_H

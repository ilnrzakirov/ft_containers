//
// Created by Nadia Callie on 5/4/22.
//

#ifndef UNTITLED_PAIR_HPP
#define UNTITLED_PAIR_HPP
namespace ft
{
/************************************************************
                    ШАБЛОННАЯ СТРУКТУРА pair
************************************************************/
    template <class T1, class T2> struct pair {
        typedef T1 first_type;
        typedef T2 second_type;

        pair(): first(T1()), second(T2()) {}
        pair(const T1& V1, const T2& V2):first(V1), second(V2) {}
        template<class U1, class U2>
            pair(const pair<U1, U2>& X): first(X.first), second(X.second) { }

        T1 first;
        T2 second;
    };
/************************************************************
                    ШАБЛОННЫЕ ОПЕРАТОРЫ pair
************************************************************/

template <class T1, class T2>
    inline bool  operator == (const pair<T1, T2>& X, const pair<T1, T2>& Y) {
        return X.first == Y.first && X.second == Y.second ;
    }
template <class T1, class T2>
    inline bool operator != (const pair<T1, T2>& X, const pair<T1, T2>& Y) {
        return !(X == Y);
    }
template <class T1, class T2>
    inline bool operator < (const pair<T1, T2>& X, const pair<T1, T2>& Y) {
        return X.first < Y.first
        || (!(Y.first < Y.first) && X.second < Y.second);
    }

template <class T1, class T2>
    inline bool operator > (const pair<T1, T2>& X, const pair<T1, T2>& Y) {
        return Y < X;
    }

template <class T1, class T2>
    inline bool operator <= (const pair<T1, T2>& X, const pair<T1, T2>& Y) {
        return !(Y < X);
    }

template <class T1, class T2>
    inline bool operator >= (const pair<T1, T2>& X, const pair<T1, T2>& Y) {
        return !(X < Y);
    }

template <class T1, class T2>
    pair<T1, T2> make_pair(T1 X, T2 Y) {
        return pair<T1, T2>(X, Y);
    }

/************************************************************
                   доп ШАБЛОННЫЕ ОПЕРАТОРЫ
                    возможно нужно будет убрать, стр 63
************************************************************/
template<class T> inline
    bool operator != (const T& X, const T& Y) {
        return !(Y ==X);
    }
template<class T> inline
    bool operator > (const T& X, const T& Y) {
    return (Y < X);
    }
template<class T> inline
    bool operator <= (const T& X, const T& Y) {
        return (!(Y < X));
    }
template<class T> inline
    bool operator >= (const T& X, const T& Y) {
        return (!(X < Y));
    }

};
#endif //UNTITLED_PAIR_HPP

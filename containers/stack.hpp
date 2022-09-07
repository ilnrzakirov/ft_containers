#ifndef  STACK_
#define STACK_
#include <deque>

namespace ft {

template<class T, class C = std::deque<T> >
    class stack {
public:
   typedef C container_type;
   typedef typename C::value_type value_type;
   typedef typename C::size_type size_type;

        explicit stack(const C& Cont) : c(Cont) { }
        stack() : c() { }
        bool empty() const
            {return (c.empty()); }
        size_type size() const
            {return (c.size()); }
        value_type& top()
            {return (c.back()); }
        const value_type& top() const
            {return  (c.back()); }
        void push(const value_type& X)
            {c.push_back(X); }
        void pop()
            {c.pop_back(); }
        bool Eq(const stack<T, C>& X) const
            {return (c == X.c); }
        bool Lt(const stack<T, C>& X) const
            {return (c < X.c); }
protected:
    C c;
    };


template<class T, class C> inline
    bool operator==(const stack<T, C>& X, const stack<T, C>& Y)
        {return (X.Eq((Y))); }
template<class T, class C> inline
    bool operator!=(const stack<T, C>& X, const stack<T, C>& Y)
        {return (!(X == Y)); }
template<class T, class C> inline
    bool operator<(const stack<T, C>& X, const stack<T, C>& Y)
        {return (X.Lt(Y)); }
template<class T, class C> inline
    bool operator>(const stack<T, C>& X, const stack<T, C>& Y)
    {return (Y < X); }
template<class T, class C> inline
    bool operator<=(const stack<T, C>& X, const stack<T, C>& Y)
    {return (!(Y < X)); }
template<class T, class C> inline
    bool operator>=(const stack<T, C>& X, const stack<T, C>& Y)
    {return (!(X < Y)); }
}
#endif
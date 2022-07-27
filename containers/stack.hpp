#ifndef  STACK_
#define STACK_
#include <deque>

//T - тип элементов хранящихся в стеке
//С - тип контейнера, использующегося для контролирования последовательности элементов
namespace ft {
    /*
     * class T - тип элемента хранящегося в стеке
     * class C - тип контейнера, использующегося для контролирования последовательности элементов
     */
template<class T, class C = std::deque<T> >
    class stack {
public:
   typedef C container_type;
   typedef typename C::value_type value_type;
   typedef typename C::size_type size_type;

        explicit stack(const C& Cont) : c(Cont) { } //определяет исходную последовательность, копии Cont
        stack() : c() { } //определяет пустую исходную последовательность
        bool empty() const
            {return (c.empty()); }
        size_type size() const
            {return (c.size()); }
        value_type& top() //возвращает ссылку на последний элемент последовательности (изменяймый)
            {return (c.back()); }
        const value_type& top() const
            {return  (c.back()); }
        void push(const value_type& X) //вставляет элемент в конец последовательности
            {c.push_back(X); }
        void pop() //удаляет последний элемент последовательностий
            {c.pop_back(); }
        bool Eq(const stack<T, C>& X) const //минимизирует доступ через шаблонные функции
            {return (c == X.c); }
        bool Lt(const stack<T, C>& X) const //минимизирует доступ через шаблонные функции
            {return (c < X.c); }
protected:
    C c;
    };

    /* Шаблонные функции stack */
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
} /* namespace ft */
#endif /* STACK_ */
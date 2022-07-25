#ifndef UNTITLED_VECTOR_HPP
#define UNTITLED_VECTOR_HPP
#include <memory>
#include "../iterators/iterator.hpp"
#include <stdexcept>

namespace ft {
    template<class T, class A>
    class Vector_val {
    protected:
        Vector_val(A A1 = A()) : Alval(A1) {}
        typedef  typename A::template rebind<T>::other Alty;
        Alty Alval;
    };
    template <class T, class Ax = std::allocator<T> > class vector: public Vector_val <T, Ax> {
    protected:
        typedef vector<T, Ax>               Myt;
        typedef Vector_val<T, Ax>           MyBase;
        typedef	typename MyBase::Alty       A;
        typedef typename A::pointer         Tptr;
        typedef typename A::const_pointer   Ctptr;
    public:
        typedef A                           allocator_type;
        typedef typename A::size_type       size_type;
        typedef typename A::difference_type difference_type;
        typedef Tptr                        pointer;
        typedef Ctptr                       const_pointer;
        typedef typename A::reference       reference;
        typedef typename A::const_reference const_reference;
        typedef typename A::value_type      value_type;

        typedef random_acsees_iterator<value_type, difference_type, Tptr, reference, Tptr, reference>        iterator;
        typedef random_acsees_iterator<value_type, difference_type, Ctptr, const_reference, Tptr, reference> const_iterator;
        typedef ft::reverse_iterator<iterator>                                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                        const_reverse_iterator;

        vector () :MyBase(){Buy(0);}

        explicit vector (const A& Al) :MyBase(Al) {Buy(0);}

        explicit vector (size_type N) :MyBase() {
            if (Buy(N))
                Last = Ufill(First, N, T());
        }
        vector (size_type N, const T& V) : MyBase() {
            if (Buy(N))
                Last = Ufill(First, N, V);
        }
        vector (size_type N, const T& V, const A& Al) : MyBase(Al) {
            if (Buy(N))
                Last = Ufill(First, N, V);
        }
        vector(const Myt& X) : MyBase(X.Alval) {
            if (Buy(X.size()))
                Last = Ucopy(X.begin(), X.end(), First);
        }
        template<class It>
        vector(It F, It L) : MyBase() {
            Construct(F, L, Iter_cat(F));
        }
        template<class It>
        vector(It F, It L, const A& Al) : MyBase(Al) {
            Construct(F, L, Iter_cat(F));
        }
        ~vector() {
            Clear();
        }
        Myt& operator = (const Myt& X) {
            if (this == &X)
                ;
            else if (X.size() == 0)
                Clear();
            else if (X.size() <= size()) {
                pointer Q = Ucopy(X.begin(), X.end(), First);
                Destroy(Q, Last);
                Last = First + X.size();
            }
            else {
                Destroy(First, Last);
                MyBase::Alval.deallocate(First, End - First);
                if(Buy(X.size()))
                    Last = Ucopy(X.begin(), X.end(), First);
            }
            return (*this);
        }
}
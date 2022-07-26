#include "xtree.hpp"
#ifndef UNTITLED_TMAP_TRAITS_HPP
#define UNTITLED_TMAP_TRAITS_HPP
namespace ft {
    template<class K, class T, class Pr, class Ax, bool Mfl>
    class Tmap_traits {
    public:
        typedef K key_type;
        typedef pair<const K, T> value_type;
        typedef Pr key_compare;
        typedef typename Ax::template rebind<value_type>::other allocator_type;
        enum { Multi = Mfl };
        Tmap_traits() : comp() {}
        Tmap_traits(Pr Parg) : comp(Parg) {}
        class value_compare : ft::binary_function<value_type, value_type, bool> {
            friend class Tmap_traits<K, T, Pr, Ax, Mfl>;
        public:
            bool operator() (const value_type& X, const value_type& Y) const {
                return(comp(X.first, Y.first));
            }
            value_compare(key_compare Pred) : comp(Pred) {}
        protected:
            key_compare comp;
        };
        struct Kfn {
            const K& operator () (const value_type& X) const {
                return (X.first);
            }
        };
        Pr comp;
    };
}

#endif

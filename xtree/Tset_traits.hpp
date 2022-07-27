#include "xtree.hpp"
#ifndef UNTITLED_SET_TREE_HPP
#define UNTITLED_SET_TREE_HPP
namespace ft {
    template<class K, class Pr, class Ax, bool Mfl>
    class Tset_traits {
    public:
        typedef K key_type;
        typedef K value_type;
        typedef Pr key_compare;
        typedef typename Ax::template rebind<value_type>::other allocator_type;
        enum { Multi = Mfl };
        Tset_traits() : comp() {}
        Tset_traits(Pr Parg) : comp(Parg) {}
        typedef key_compare value_compare;
        struct Kfn { const K& operator () (const value_type &X) const { return X; } };
        Pr comp;
    };
};
#endif //UNTITLED_SET_TREE_HPP

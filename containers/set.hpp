#ifndef UNTITLED_SET_HPP
#define UNTITLED_SET_HPP
#include "../xtree/Tset_traits.hpp"

/******************************
SET - описывает обьект, который управляет последовательностью переменной длины из элементов типа Key(K)
Pr - функциональный объект упорядочивания
A - распределитель (распределяет и освобождает память для контейнера


******************************/
namespace ft {
    template<class K, class Pr = ft::less<K>, class A = std::allocator<K> >
    class set : public Tree<Tset_traits<K, Pr, A, false> > {
    public:
        typedef set<K, Pr, A> Myt;
        typedef Tree<Tset_traits<K, Pr, A, false> > Mybase;
        typedef K key_type;
        typedef Pr key_compare; //key_comp() - xtree
        typedef typename Mybase::value_compare value_compare;
        typedef typename Mybase::allocator_type allocator_type;
        typedef typename Mybase::size_type size_type;
        typedef typename Mybase::difference_type difference_type;
        typedef typename Mybase::pointer pointer;
        typedef typename Mybase::const_pointer const_pointer;
        typedef typename Mybase::reference reference;
        typedef typename Mybase::const_reference const_reference;
        typedef typename Mybase::iterator iterator;
        typedef typename Mybase::const_iterator const_iterator;
        typedef typename Mybase::reverse_iterator reverse_iterator;
        typedef typename Mybase::const_reverse_iterator const_reverse_iterator;
        typedef typename Mybase::value_type value_type;
        set() : Mybase(key_compare(), allocator_type()) {} //пустой набор
        explicit set(const key_compare &Pred) : Mybase(Pred, allocator_type()) {} //+ упорядочен с помощью Pred
        set(const key_compare &Pred, const allocator_type &Al) : Mybase(Pred, Al) {} // + обьект распределитель
        template<class It>
        set(It F, It L) : Mybase(key_compare(), allocator_type()) { //копируем
            for (; F != L; ++F)
                this->insert(*F);
        }
        template<class It>
        set(It F, It L, const key_compare &Pred) : Mybase(Pred, allocator_type()) { //+ упорядочен с помощью Pred
            for (; F != L; ++F)
                this->insert(*F);
        }
        template<class It>
        set(It F, It L, const key_compare &Pred, const allocator_type &Al) : Mybase(Pred, Al) { //+ обьект распределитель
            for (; F != L; ++F)
                this->insert(*F);
        }
    };
}

#endif //UNTITLED_SET_HPP

#ifndef UNTITLED_MAP_HPP
#define UNTITLED_MAP_HPP

#include "../xtree/Tmap_traits.hpp"

/******************************
MAP
K - Kay
T - Value
Pr - less(берет обьекты и сравнивает на оператор меньше), опасная хрень при поворотах
A -
******************************/

namespace ft {
template<class K, class T, class Pr = less<K>, class A = std::allocator<pair<const K, T> > >
    class map : public Tree<Tmap_traits<K, T, Pr, A, false> > {
    public:
        typedef map<K, T, Pr, A> Myt;
        typedef Tree<Tmap_traits<K, T, Pr, A, false> > Mybase;
        typedef K key_type;
        typedef T mapped_type;
        typedef T referent_type;
        typedef Pr key_compare;
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

        map() : Mybase(key_compare(), allocator_type()) {}
        explicit map(const key_compare &Pred) : Mybase(Pred, allocator_type()) {}
        map(const key_compare &Pred, const allocator_type &Al) : Mybase(Pred, Al) {}
        template<class It>
        map(It F, It L) : Mybase(key_compare(), allocator_type()) {
            for (; F != L; ++F)
                this->insert(*F);
        }
        template<class It>
        map(It F, It L, const key_compare &Pred) : Mybase(Pred, allocator_type()) {
            for (; F != L; ++F)
                this->insert(*F);
        }
        template<class It>
        map(It F, It L, const key_compare &Pred, const allocator_type &Al) : Mybase(Pred, Al) {
            for (; F != L; ++F)
                this->insert(*F);
        }

        //для неконстантных  - если ключа нет то создастся вершина и value проинициализируется значением по умолчанию
        //для константных at - как в векторе но мб и константным, если ключа нет excp
        //m[5] = 3; - вернет ссылку на Value и заменит в этой паре;
        mapped_type &operator[](const key_type &Kv) {
            iterator P = this->insert(value_type(Kv, mapped_type())).first;
            return ((*P).second);
        }
/******************************
At
******************************/
        mapped_type &at(const key_type &Kv) {
            iterator P = this->find(Kv);
            if (P == this->end())
                throw std::out_of_range("key not found");
            else
                return ((*P).second);
        }
        mapped_type &at(const key_type &Kv) const {
            return static_cast<const mapped_type>(at(Kv));
        }
};

}

#endif //UNTITLED_MAP_HPP

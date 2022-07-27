//
// Created by Nadia Callie on 5/4/22.
//
#ifndef UNTITLED_ITERATOR_HPP
#define UNTITLED_ITERATOR_HPP
#include "xutility.hpp"
namespace ft {
/************************************************************
            шаблонная функция Val_type
************************************************************/
template <class It> inline
    typename ft::iterator_traits<It>::value_type *Val_type(It) {
        return (0);
    }
/************************************************************
            шаблонная функция advance
************************************************************/
template <class InIt, class D> inline
    void advance (InIt& I, D N) {
    Advance(I, N, Iter_cat(I));
    }

template <class InIt, class D> inline
    void Advance (InIt &I, D N, input_iterator_tag) {
    for (; 0 < N; --N)
        ++I;
    }

template <class FwdIt, class D> inline
    void Advance (FwdIt &I, D N, forward_iterator_tag) {
    for (; 0 < N; --N)
        ++I;
    }

template <class BidIt, class D> inline
    void Advance (BidIt &I, D N, bidirectional_iterator_tag) {
    for (; 0 < N; --N)
        ++I;
    for (; N < 0; ++N)
        --I;
    }

template <class RanIt, class D> inline
    void Advance (RanIt &I, D N, random_access_iterator_tag) {
    I += N;
    }

/************************************************************
            шаблонная функция Dist_type
************************************************************/
template<class It> inline
    typename iterator_traits<It>::difference_type *Dist_type(It) {
    return (0);
    }
}

#endif //UNTITLED_ITERATOR_HPP

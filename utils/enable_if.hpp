#ifndef UNTITLED_ENABLE_IF_HPP
#define UNTITLED_ENABLE_IF_HPP
namespace ft {
template <bool, class T = void>
struct enable_if
{};

template <class T>
struct enable_if<true, T> {
    typedef T type;
};
}

#endif

//
// Created by Nadia Callie on 5/5/22.
//
#include <iostream>
#include <iomanip>
#include <numeric>
#include <array>

#define NAMESPASE ft


#include <iterator>
#include <vector>
#include <map>
#include <set>
#include <stack>


#include "containers/vector.hpp"
#include "containers/set.hpp"
#include "containers/map.hpp"
#include "containers/stack.hpp"







template<class T>
void print_container(const NAMESPASE::vector<T>& c) {
    for (T i : c) {
        std::cout << i << " ";
    }
    std::cout << '\n';
}

void test_erase() {
    std::cout << "\033[1;32m--------------------test_erase_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m--------------------(стирает элементы)------------------\033[0m\n";
    NAMESPASE::vector<int> c;
    c.push_back(0);
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(4);
    c.push_back(5);
    c.push_back(6);
    c.push_back(7);
    c.push_back(8);
    c.push_back(9);
    print_container(c);

    c.erase(c.begin());
    print_container(c);

    c.erase(c.begin()+2, c.begin()+5);
    print_container(c);

    // Erase all even numbers (C++11 and later)
    for (NAMESPASE::vector<int>::iterator it = c.begin(); it != c.end(); ) {
        if (*it % 2 == 0) {
            it = c.erase(it);
        } else {
            ++it;
        }
    }
    print_container(c);
};

void test_swap() {
    std::cout << "\033[1;32m--------------------test_swap_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m----------------(меняет содержимое местами)------------\033[0m\n";
    NAMESPASE::vector<int> a1;
    a1.push_back(1);
    a1.push_back(2);
    a1.push_back(3);

    NAMESPASE::vector<int> a2;
    a2.push_back(4);
    a2.push_back(5);

    NAMESPASE::vector<int>::iterator it1 = a1.begin();
    NAMESPASE::vector<int>::iterator it2 = a2.begin();

    std::cout << "До\n";
    print_container(a1);
    print_container(a2);
    std::cout << "После\n";
    a1.swap(a2);
    print_container(a1);
    print_container(a2);
}

void test_resize() {
    std::cout << "\033[1;32m--------------------test_resize_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m----------(изменяет количество хранимых элементов)-------\033[0m\n";
    NAMESPASE::vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    std::cout << "The vector<int> holds: ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(5);
    std::cout << "After resize up to 5: ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(2);
    std::cout << "After resize down to 2: ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    c.resize(6, 4);
    std::cout << "After resize up to 6 (initializer = 4): ";
    for(const auto& el: c) std::cout << el << ' ';
    std::cout << '\n';
    std::cout << "The vector<string> holds: ";
    NAMESPASE::vector<std::string> d;
    d.push_back("hello");
    d.push_back("world");
    d.push_back("!");
    d.resize(10);
    for(const auto& el: d) std::cout << el << ' ';
}

void test_pop_back() {
    std::cout << "\033[1;32m--------------------test_pop_back_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m------------(Удаляет последний элемент контейнера)---------\033[0m\n";

    NAMESPASE::vector<int> numbers;
    print_container(numbers);

    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(4);

    print_container(numbers);

    numbers.pop_back();

    print_container(numbers);

}
void test_push_back() {
    std::cout << "\033[1;32m--------------------test_push_back_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m--(Добавляет заданный элемент valueв в конец контейнера.)--\033[0m\n";
    NAMESPASE::vector<std::string> letters;

    letters.push_back("abc");
    std::string s = "def";
    letters.push_back(s);
    std::cout << "Выводит:\n";
    std::cout << "vector holds: ";
    print_container(letters);
}
void test_insert() {
    std::cout << "\033[1;32m--------------------test_insert_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m---(Вставляет элементы в указанное место в контейнере)---\033[0m\n";
    NAMESPASE::vector<int> c1(3, 100);
    print_container(c1);
    c1.insert(c1.begin(),200);
    print_container(c1);
    c1.insert(c1.begin(), 2, 300);
    print_container(c1);

    NAMESPASE::vector<int> c2(2, 400);
    c1.insert(c1.begin() + 2,c2.begin(), c2.end());
    print_container(c1);

    int arr[] = { 501,502,503 };
    c1.insert(c1.begin(), arr, arr + 3);
    print_container(c1);

    int arr1[] = { 601,602,603 };
    c1.insert(c1.end(), arr1, arr1 + 3);
    print_container(c1);
}
void test_clear() {
    std::cout << "\033[1;32m--------------------test_clear_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-(Удаляет все элементы из контейнера. После этого вызова size() возвращает ноль)-\033[0m\n";
    NAMESPASE::vector<int> container;
    container.push_back(1);
    container.push_back(2);
    container.push_back(3);
    std::cout << "Before clear:";
    print_container(container);
    std::cout << "Size=" << container.size() << ", Capacity=" << container.capacity() << '\n';
    container.clear();
    std::cout << "After clear:";
    print_container(container);
    std::cout << "Size=" << container.size() << ", Capacity=" << container.capacity() << '\n';
}

void test_empty() {
    std::cout << "\033[1;32m--------------------test_empty_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-(Проверяет, нет ли в контейнере элементов, т.е.начало ( ) == конец ( ))-\033[0m\n";
    std::cout << std::boolalpha;
    NAMESPASE::vector<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

    numbers.push_back(42);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}
void test_max_size() {
    std::cout << "\033[1;32m--------------------test_max_size-------------------\033[0m\n";
    std::cout << "\033[1;34m-(Возвращает максимальное количество элементов, которое может содержать контейнер)-\033[0m\n";
    NAMESPASE::vector<int> q;
    std::vector<int> s;
    std::cout << "Maximum size of a ft::vector is " << q.max_size() << '\n';
    std::cout << "Maximum size of a std::vector is " << s.max_size() << '\n';
}

void test_size() {
    std::cout << "\033[1;32m--------------------test_size_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----(Возвращает количество элементов в контейнере)----\033[0m\n";
    NAMESPASE::vector<int> q;
    q.push_back(1);
    q.push_back(3);
    q.push_back(5);
    q.push_back(7);
    std::cout << "nums contains " << q.size() << " elements.\n";
}

void test_reserve() {
    std::cout << "\033[1;32m--------------------test_reserve_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<int> q;
    std::cout << "Size=" << q.size() << ", Capacity=" << q.capacity() << '\n';
    q.push_back(5);
    std::cout << "Size=" << q.size() << ", Capacity=" << q.capacity() << '\n';
    q.reserve(10);
    std::cout << "Size=" << q.size() << ", Capacity=" << q.capacity() << '\n';
    q.reserve(11);
    std::cout << "Size=" << q.size() << ", Capacity=" << q.capacity() << '\n';
}

void test_capacity() {
    std::cout << "\033[1;32m--------------------test_capacity_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    int sz = 100;
    NAMESPASE::vector<int> v;

    unsigned long cap = v.capacity();
    std::cout << "Initial size: " << v.size() << ", capacity: " << cap << '\n';

    std::cout << "\nDemonstrate the capacity's growth policy."
                 "\nSize:  Capacity:  Ratio:\n" << std::left;
    while (sz-- > 0) {
        v.push_back(sz);
        if (cap != v.capacity()) {
            std::cout << std::setw( 7) << v.size()
                      << std::setw(11) << v.capacity()
                      << std::setw(10) << v.capacity() / static_cast<float>(cap) << '\n';
            cap = v.capacity();
        }
    }

    std::cout << "\nFinal size: " << v.size() << ", capacity: " << v.capacity() << '\n';
}

void test_begin() {
    std::cout << "\033[1;32m--------------------test_begin_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(16);
    NAMESPASE::vector<std::string> fruits;
    fruits.push_back("orange");
    fruits.push_back("apple");
    fruits.push_back("raspberry");

    NAMESPASE::vector<char> empty;

    // Print vector.
    for(NAMESPASE::vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << '\n';

    // Sums all integers in the vector nums (if any), printing only the result.
    std::cout << "Sum of nums: "
              << std::accumulate(nums.begin(), nums.end(), 0) << '\n';

    // Prints the first fruit in the vector fruits, checking if there is any.
    if (!fruits.empty())
        std::cout << "First fruit: " << *fruits.begin() << '\n';

    if (empty.begin() == empty.end())
        std::cout << "vector 'empty' is indeed empty.\n";
}

void test_end() {
    std::cout << "\033[1;32m--------------------test_end_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(8);
    nums.push_back(16);
    NAMESPASE::vector<int>::reverse_iterator rit = nums.rbegin();
    for(; rit != nums.rend(); rit++) {
        std::cout << *rit << " ";
    }
}

void test_at() {
    std::cout << "\033[1;32m--------------------test_at_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<int> data;
    data.push_back(1);
    data.push_back(2);
    data.push_back(3);
    data.push_back(4);
    data.push_back(5);
    data.push_back(6);

    // Set element 1
    data.at(1) = 88;

    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';

    std::cout << "data size = " << data.size() << '\n';

    try {
        // Set element 6
        data.at(6) = 666;
    } catch (...) {
        std::cout << "Error\n";
    }

    // Print final values
    std::cout << "data:";
    for (int elem : data)
        std::cout << " " << elem;
    std::cout << '\n';
}

void test_operator_pos() {
    std::cout << "\033[1;32m--------------------test_[]_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<int> numbers;

    numbers.push_back(2);
    numbers.push_back(4);
    numbers.push_back(6);
    numbers.push_back(8);

    std::cout << "Second element: " << numbers[1] << '\n';

    numbers[0] = 5;

    std::cout << "All numbers:";
    for (auto i : numbers) {
        std::cout << ' ' << i;
    }
    std::cout << '\n';
}

void test_front() {
    std::cout << "\033[1;32m--------------------test_front_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<char> letters;
    letters.push_back('o');
    letters.push_back('m');
    letters.push_back('g');
    letters.push_back('w');
    letters.push_back('t');
    letters.push_back('f');

    if (!letters.empty())
        std::cout << "The first character is '" << letters.front() << "'.\n";
}

void test_back() {
    std::cout << "\033[1;32m--------------------test_back_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<char> letters;
    letters.push_back('a');
    letters.push_back('b');
    letters.push_back('c');
    letters.push_back('d');
    letters.push_back('e');
    letters.push_back('f');
    if (!letters.empty())
        std::cout << "The last character is '" << letters.back() << "'.\n";
}

void test_constructor() {
    std::cout << "\033[1;32m--------------------test_constructor_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::vector<std::string> words1;
    words1.push_back("the");
    words1.push_back("frogurt");
    words1.push_back("is");
    words1.push_back("also");
    words1.push_back("cursed");


    std::cout << "words1: ";
    print_container(words1);

    // words2 == words1
    NAMESPASE::vector<std::string> words2(words1.begin(), words1.end());
    std::cout << "words2: ";
    print_container(words2);

    // words3 == words1
    NAMESPASE::vector<std::string> words3(words1);
    std::cout << "words3: ";
    print_container(words3);

    // words4 is {"Mo", "Mo", "Mo", "Mo", "Mo"}
    NAMESPASE::vector<std::string> words4(5, "Mo");
    std::cout << "words4: ";
    print_container(words4);
}
void test_operator_copy() {
    std::cout << "\033[1;32m--------------------test_operator_copy_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::vector<int> x , y, z , w;
    x.push_back(1);  w.push_back(4);
    x.push_back(2);  w.push_back(5);
    x.push_back(3);  w.push_back(6);
    w.push_back(7);

    std::cout << "Initially:\n";
    std::cout << "x: ";
    print_container(x);
    std::cout << "y: ";
    print_container(y);
    std::cout << "z: ";
    print_container(z);
    std::cout << "w: ";
    print_container(w);

    std::cout << "Copy assignment copies data from x to y:\n";
    y = x;
    std::cout << "x: ";
    print_container(x);
    std::cout << "y: ";
    print_container(y);

    std::cout << "Copy assignment copies data from x to z:\n";
    z = x;
    std::cout << "x: ";
    print_container(x);
    std::cout << "z: ";
    print_container(z);

    std::cout << "Assignment of initializer_list w to z:\n";
    z = w;
    std::cout << "w: ";
    print_container(w);
    std::cout << "z: ";
    print_container(z);
}

void test_assign() {
    std::cout << "\033[1;32m--------------------test_assign_vector-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::vector<char> characters;
    std::cout << "characters: ";
    characters.assign(5, 'a');
    print_container(characters);
    NAMESPASE::vector<char> extra;
    extra.assign(6, 'b');
    std::cout << "extra: ";
    print_container(extra);
    characters.assign(extra.begin(), extra.end());
    std::cout << "characters: ";
    print_container(characters);
}


void test_at_map() {
    std::cout << "\033[1;32m--------------------test_at_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----(доступ к указанному элементу с проверкой границ)----\033[0m\n";
    NAMESPASE::map<int, int> m;
    m.insert(NAMESPASE::make_pair(2,7));
    m.insert(NAMESPASE::make_pair(2,1));
    m.insert(NAMESPASE::make_pair(1,5));
    m.insert(NAMESPASE::make_pair(9,9));
    std::cout << m.at(2) << std::endl;
    std::cout << m.at(1) << std::endl;
    try {
        m.at(11);
    } catch (...) {
        std::cout << "Key not found" << std::endl;
    }

}

auto print_map = [](auto const comment, auto const& map) {
    std::cout << comment << "{";
    for (const auto &pair : map) {
        std::cout << "{" << pair.first << ": " << pair.second << "}";
    }
    std::cout << "}\n";
};

void test_operator_pos_map() {
    std::cout << "\033[1;32m--------------------test_operator[]_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----(получить доступ или вставить указанный элемент)----\033[0m\n";

    NAMESPASE::map<char, int> letter_counts;
    letter_counts.insert(NAMESPASE::make_pair('a', 27));
    letter_counts.insert(NAMESPASE::make_pair('b', 3));
    letter_counts.insert(NAMESPASE::make_pair('c', 1));

    print_map("letter_counts initially contains: ", letter_counts);

    letter_counts['b'] = 42;  // updates an existing value
    letter_counts['x'] = 9;  // inserts a new value

    print_map("after modifications it contains: ", letter_counts);

    // count the number of occurrences of each word
    // (the first call to operator[] initialized the counter with zero)
    NAMESPASE::map<std::string, int>  word_map;
    for (const auto &w : { "this", "sentence", "is", "not", "a", "sentence",
                           "this", "sentence", "is", "a", "hoax"}) {
        ++word_map[w];
    }
    word_map["that"]; // just inserts the pair {"that", 0}

    for (const auto &[word, count] : word_map) {
        std::cout << count << " occurrences of word '" << word << "'\n";
    }
}

void begin_end_map() {
    std::cout << "\033[1;32m--------------------test_begin_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int, float> num_map;
    num_map[4] = 4.13;
    num_map[9] = 9.24;
    num_map[1] = 1.09;
    // calls a_map.begin() and a_map.end()
    for (auto it = num_map.begin(); it != num_map.end(); ++it) {
        std::cout << it->first << ", " << it->second << '\n';
    }
}

void rbegin_rend_map() {
    std::cout << "\033[1;32m--------------------test_rbegin_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int, std::string> coins; // initializer entries in name alphabetical order
    coins.insert(NAMESPASE::make_pair(10, "dime"));
    coins.insert(NAMESPASE::make_pair(100, "dollar"));
    coins.insert(NAMESPASE::make_pair(50, "half dollar"));
    coins.insert(NAMESPASE::make_pair(5, "nickel"));
    coins.insert(NAMESPASE::make_pair(1, "penny"));
    coins.insert(NAMESPASE::make_pair(25, "quarter"));
    std::cout << "US coins in circulation, largest to smallest denomination:\n";
    for (auto it = coins.rbegin(); it != coins.rend(); ++it) {
        std::cout << std::setw(11) << it->second << " = ¢" << it->first << '\n';
    }
}

void empty_map() {
    std::cout << "\033[1;32m--------------------test_empty_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int,int> numbers;
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
    numbers.insert(NAMESPASE::make_pair(42, 13));
    numbers.insert(NAMESPASE::make_pair(13317, 123));
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

void size_map() {
    std::cout << "\033[1;32m--------------------test_size_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int,char> nums;
        nums.insert(NAMESPASE::make_pair(1, 'a'));
        nums.insert(NAMESPASE::make_pair(3, 'b'));
        nums.insert(NAMESPASE::make_pair(5, 'c'));
        nums.insert(NAMESPASE::make_pair(7, 'd'));
        std::cout << "nums contains " << nums.size() << " elements.\n";
}

void max_size_map() {
    std::cout << "\033[1;32m--------------------test_max_size_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<char, char> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << "Maximum size of a ft::map is " << q.max_size() << '\n';
}

void clear_map() {
    std::cout << "\033[1;32m--------------------test_clear_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int, char> container;
    container.insert(NAMESPASE::make_pair(1, 'x'));
    container.insert(NAMESPASE::make_pair(2, 'y'));
    container.insert(NAMESPASE::make_pair(3, 'z'));

    auto print = [](NAMESPASE::pair<const int, char>& n) {
        std::cout << " " << n.first << '(' << n.second << ')';
    };

    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';

    std::cout << "Clear\n";
    container.clear();

    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';
}

template<typename It>
void printInsertionStatus(It it, bool success)
{
    std::cout << "Insertion of " << it->first << (success ? " succeeded\n" : " failed\n");
}

void insert_map() {
    std::cout << "\033[1;32m--------------------test_insert_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<std::string, float> karasunoPlayerHeights;

    // Overload 3: insert from rvalue reference
    const auto [it_hinata, success] = karasunoPlayerHeights.insert(NAMESPASE::make_pair("Hinata", 162.8));
    printInsertionStatus(it_hinata, success);

    {
        // Overload 1: insert from lvalue reference
        const auto [it, success2] = karasunoPlayerHeights.insert(*it_hinata);
        printInsertionStatus(it, success2);
    }
    {
        // Overload 2: insert via forwarding to emplace
        const auto [it, success] = karasunoPlayerHeights.insert(NAMESPASE::make_pair("Kageyama", 180.6));
        printInsertionStatus(it, success);
    }

    {
        // Overload 6: insert from rvalue reference with positional hint
        const std::size_t n = karasunoPlayerHeights.size();
        const auto it = karasunoPlayerHeights.insert(it_hinata, {"Azumane", 184.7});
        printInsertionStatus(it,karasunoPlayerHeights.size() != n);
    }
    {
        // Overload 4: insert from lvalue reference with positional hint
        const std::size_t n = karasunoPlayerHeights.size();
        const auto it = karasunoPlayerHeights.insert(it_hinata, *it_hinata);
        printInsertionStatus(it, karasunoPlayerHeights.size() != n);
    }
    {
        // Overload 5: insert via forwarding to emplace with positional hint
        const std::size_t n = karasunoPlayerHeights.size();
        const auto it = karasunoPlayerHeights.insert(it_hinata, NAMESPASE::make_pair("Tsukishima", 188.3));
        printInsertionStatus(it, karasunoPlayerHeights.size() != n);
    }
}

void erase_map() {
    std::cout << "\033[1;32m--------------------test_erase_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int, std::string> c;
    c.insert(NAMESPASE::make_pair(1, "one"));
    c.insert(NAMESPASE::make_pair(2, "two"));
    c.insert(NAMESPASE::make_pair(3, "three"));
    c.insert(NAMESPASE::make_pair(4, "four"));
    c.insert(NAMESPASE::make_pair(5, "five"));
    c.insert(NAMESPASE::make_pair(6, "six"));


    // erase all odd numbers from c
    for(auto it = c.begin(); it != c.end(); ) {
        if(it->first % 2 != 0)
            it = c.erase(it);
        else
            ++it;
    }

    for(auto& p : c) {
        std::cout << p.second << ' ';
    }
    std::cout << "\n";
}

void swap_map() {
    std::cout << "\033[1;32m--------------------test_swap_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<std::string, std::string> m1, m2;

    m1.insert(NAMESPASE::make_pair("γ", "gamma"));
    m1.insert(NAMESPASE::make_pair("β", "beta"));
    m1.insert(NAMESPASE::make_pair("α", "alpha"));
    m1.insert(NAMESPASE::make_pair("γ", "gamma"));

    m2.insert(NAMESPASE::make_pair("ε", "epsilon"));
    m2.insert(NAMESPASE::make_pair("δ", "delta"));
    m2.insert(NAMESPASE::make_pair("ε", "epsilon"));

    print_map("m1", m1);
    print_map("m2", m2);

    m1.swap(m2);

    print_map("m1", m1);
    print_map("m2", m2);
}

void count_map() {
    std::cout << "\033[1;32m--------------------test_count_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<std::string, std::string> m1;

    m1.insert(NAMESPASE::make_pair("γ", "gamma"));
    m1.insert(NAMESPASE::make_pair("β", "beta"));
    m1.insert(NAMESPASE::make_pair("α", "alpha"));
    m1.insert(NAMESPASE::make_pair("γ", "gamma"));
    std::cout << m1.count("γ") << std::endl;
    std::cout << m1.count("α") << std::endl;
    std::cout << m1.count("z") << std::endl;
}

void find_map() {
    std::cout << "\033[1;32m--------------------test_find_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int,char> example;
    example.insert(NAMESPASE::make_pair(1,'a'));
    example.insert(NAMESPASE::make_pair(2,'b'));

    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
    } else {
        std::cout << "Not found\n";
    }

    search = example.find(5);
    if (search != example.end()) {
        std::cout << "Found " << search->first << " " << search->second << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

void equal_range_map() {
    std::cout << "\033[1;32m--------------------test_equal_range_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int, const char*> m;

    m.insert(NAMESPASE::make_pair(0, "zero"));
    m.insert(NAMESPASE::make_pair(1, "one"));
    m.insert(NAMESPASE::make_pair(2, "two"));
    {
        auto p = m.equal_range(1);
        for (auto& q = p.first; q != p.second; ++q) {
            std::cout << "m[" << q->first << "] = " << q->second << '\n';
        }

        if (p.second == m.find(2)) {
            std::cout << "end of equal_range (p.second) is one-past p.first\n";
        } else {
            std::cout << "unexpected; p.second expected to be one-past p.first\n";
        }
    }

    {
        auto pp = m.equal_range(-1);
        if (pp.first == m.begin()) {
            std::cout << "pp.first is iterator to first not-less than -1\n";
        } else {
            std::cout << "unexpected pp.first\n";
        }

        if (pp.second == m.begin()) {
            std::cout << "pp.second is iterator to first element greater-than -1\n";
        } else {
            std::cout << "unexpected pp.second\n";
        }
    }

    {
        auto ppp = m.equal_range(3);
        if (ppp.first == m.end()) {
            std::cout << "ppp.first is iterator to first not-less than 3\n";
        } else {
            std::cout << "unexpected ppp.first\n";
        }

        if (ppp.second == m.end()) {
            std::cout << "ppp.second is iterator to first element greater-than 3\n";
        } else {
            std::cout << "unexpected ppp.second\n";
        }
    }
}

void lower_upper_bound_map() {
    std::cout << "\033[1;32m--------------------lower_upper_bound_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<char,int> mymap;
    NAMESPASE::map<char,int>::iterator itlow,itup;

    mymap['a']=20;
    mymap['b']=40;
    mymap['c']=60;
    mymap['d']=80;
    mymap['e']=100;

    itlow=mymap.lower_bound ('b');  // itlow points to b
    itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    mymap.erase(itlow,itup);        // erases [itlow,itup)
    for (NAMESPASE::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';
}

struct ModCmp {
    bool operator()(const int lhs, const int rhs) const
    {
        return (lhs % 97) < (rhs % 97);
    }
};

void key_comp_map() {
    std::cout << "\033[1;32m--------------------key_comp_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int, char, ModCmp> cont;

    cont.insert(NAMESPASE::make_pair(1, 'a'));
    cont.insert(NAMESPASE::make_pair(2, 'b'));
    cont.insert(NAMESPASE::make_pair(3, 'c'));
    cont.insert(NAMESPASE::make_pair(4, 'd'));
    cont.insert(NAMESPASE::make_pair(5, 'e'));

    auto comp_func = cont.key_comp();

    for (auto it : cont) {
        bool before = comp_func(it.first, 100);
        bool after = comp_func(100, it.first);

        std::cout << '(' << it.first << ',' << it.second;
        if (!before && !after)
            std::cout << ") equivalent to key 100\n";
        else if (before)
            std::cout << ") goes before key 100\n";
        else if (after)
            std::cout << ") goes after key 100\n";
        else
            assert(0); // Cannot happen
    }
}

void value_comp_map() {
    std::cout << "\033[1;32m--------------------value_comp_map-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::map<int, char, ModCmp> cont;

    cont.insert(NAMESPASE::make_pair(1, 'a'));
    cont.insert(NAMESPASE::make_pair(2, 'b'));
    cont.insert(NAMESPASE::make_pair(3, 'c'));
    cont.insert(NAMESPASE::make_pair(4, 'd'));
    cont.insert(NAMESPASE::make_pair(5, 'e'));

    auto comp_func = cont.value_comp();

    const NAMESPASE::pair<int, char> val = { 100, 'a' };

    for (auto it : cont) {
        bool before = comp_func(it, val);
        bool after = comp_func(val, it);

        std::cout << '(' << it.first << ',' << it.second;
        if (!before && !after)
            std::cout << ") equivalent to key " << val.first << '\n';
        else if (before)
            std::cout << ") goes before key " << val.first << '\n';
        else if (after)
            std::cout << ") goes after key " << val.first << '\n';
        else
            assert(0); // Cannot happen
    }
}

void reportStackSize(const NAMESPASE::stack<int>& s)
{
    std::cout << s.size() << " elements on stack\n";
}

void reportStackTop(const NAMESPASE::stack<int>& s)
{
    // Leaves element on stack
    std::cout << "Top element: " << s.top() << '\n';
}

class BrainHackInterpreter {
    NAMESPASE::map<unsigned, unsigned> open_brackets, close_brackets;
    unsigned program_pos_{0};
    std::array<std::uint8_t, 32768> data_;
    int data_pos_{0};

    void collect_brackets_positions(const std::string_view program) {
        NAMESPASE::stack<unsigned> brackets_stack;

        for (auto pos{0U}; pos != program.length(); ++pos) {
            const char c{program[pos]};
            if ('[' == c) {
                brackets_stack.push(pos);
            } else if (']' == c) {
                if (brackets_stack.empty()) {
                    throw std::runtime_error("brackets [] do not match!");
                } else {
                    open_brackets[brackets_stack.top()] = pos;
                    close_brackets[pos] = brackets_stack.top();
                    brackets_stack.pop();
                }
            }
        }

        if (!brackets_stack.empty())
            throw std::runtime_error("brackets [] do not match!");
    }

    void check_data_pos(int pos) {
        if (pos < 0 or pos >= static_cast<int>(data_.size()))
            throw std::out_of_range{"data pointer out of bound"};
    }

public:
    BrainHackInterpreter(const std::string_view program) {
        collect_brackets_positions(program);
        data_.fill(0);

        for (; program_pos_ < program.length(); ++program_pos_) {
            switch (program[program_pos_]) {
                case '<': check_data_pos(--data_pos_); break;
                case '>': check_data_pos(++data_pos_); break;
                case '-': --data_[data_pos_]; break;
                case '+': ++data_[data_pos_]; break;
                case '.': std::cout << data_[data_pos_]; break;
                case ',': std::cin >> data_[data_pos_]; break;
                case '[':
                    if (data_[data_pos_] == 0)
                        program_pos_ = open_brackets[program_pos_];
                    break;
                case ']':
                    if (data_[data_pos_] != 0)
                        program_pos_ = close_brackets[program_pos_];
                    break;
            }
        }
    }
};

void pop_push_stack() {
    std::cout << "\033[1;32m--------------------pop_push_stack-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    BrainHackInterpreter
            {
                    "++++++++[>++>>++>++++>++++<<<<<-]>[<+++>>+++<-]>[<+"
                    "+>>>+<<-]<[>+>+<<-]>>>--------.<<+++++++++.<<----.>"
                    ">>>>.<<<------.>..++.<++.+.-.>.<.>----.<--.++.>>>+."
            };
}

void size_stack() {
    std::cout << "\033[1;32m--------------------size_stack-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";
    NAMESPASE::stack<int> container;

    std::cout << "Initially, container.size(): " << container.size() << '\n';

    for (int i = 0; i < 7; ++i)
        container.push(i);

    std::cout << "After adding elements, container.size(): " << container.size() << '\n';
}

void empty_stack() {
    std::cout << "\033[1;32m--------------------empty_stack-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    std::cout << std::boolalpha;

    NAMESPASE::stack<int> container;

    std::cout << "Initially, container.empty(): " << container.empty() << '\n';

    container.push(42);
    std::cout << "After adding elements, container.empty(): " << container.empty() << '\n';
}

void top_stack() {
    std::cout << "\033[1;32m--------------------top_stack-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::stack<int> s;
    s.push(2);
    s.push(6);
    s.push(51);

    reportStackSize(s);
    reportStackTop(s);

    reportStackSize(s);
    s.pop();

    reportStackSize(s);
    reportStackTop(s);
}

void begin_end_set() {
    std::cout << "\033[1;32m--------------------begin_end_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> set;
    set.insert(3);
    set.insert(1);
    set.insert(4);
    set.insert(1);
    set.insert(5);
    set.insert(9);
    set.insert(2);
    set.insert(6);
    set.insert(5);
    std::for_each(set.begin(), set.end(), [](int x) {
        std::cout << x << ' ';
    });
    std::cout << '\n';
}

void rbegin_rend_set() {
    std::cout << "\033[1;32m--------------------rbegin_rend_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<unsigned> rep;
    rep.insert(1);
    rep.insert(2);
    rep.insert(3);
    rep.insert(4);
    rep.insert(1);
    rep.insert(2);
    rep.insert(3);
    rep.insert(4);

    for (auto it = rep.rbegin(); it != rep.rend(); ++it) {
        for (auto n = *it; n > 0; --n)
            std::cout << "⏼" << ' ';
        std::cout << '\n';
    }
}

void empty_set() {
    std::cout << "\033[1;32m--------------------empty_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> numbers;
    std::cout << std::boolalpha;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';

    numbers.insert(42);
    numbers.insert(13317);
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}

void size_set() {
    std::cout << "\033[1;32m--------------------size_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> nums;
    nums.insert(1);
    nums.insert(3);
    nums.insert(5);
    nums.insert(7);
    std::cout << "nums contains " << nums.size() << " elements.\n";
}

void max_size_set() {
    std::cout << "\033[1;32m--------------------max_size_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<char> q;
    std::cout.imbue(std::locale("en_US.UTF-8"));
    std::cout << "Maximum size of a std::set is " << q.max_size() << '\n';
}

void clear_set() {
    std::cout << "\033[1;32m--------------------clear_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> container;
    container.insert(1);
    container.insert(2);
    container.insert(3);

    auto print = [](const int& n) { std::cout << " " << n; };

    std::cout << "Before clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';

    std::cout << "Clear\n";
    container.clear();

    std::cout << "After clear:";
    std::for_each(container.begin(), container.end(), print);
    std::cout << "\nSize=" << container.size() << '\n';
}

void insert_set() {
    std::cout << "\033[1;32m--------------------insert_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> set;

    auto result_1 = set.insert(3);
    assert(result_1.first != set.end()); // it's a valid iterator
    assert(*result_1.first == 3);
    if (result_1.second)
        std::cout << "insert done\n";

    auto result_2 = set.insert(3);
    assert(result_2.first == result_1.first); // same iterator
    assert(*result_2.first == 3);
    if (!result_2.second)
        std::cout << "no insertion\n";
}
void erase_set() {
    std::cout << "\033[1;32m--------------------erase_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> c;
    c.insert(1);
    c.insert(2);
    c.insert(3);
    c.insert(4);

    c.insert(1);
    c.insert(2);
    c.insert(3);
    c.insert(4);

    auto print = [&c] {
        std::cout << "c = { ";
        for(int n : c)
            std::cout << n << ' ';
        std::cout << "}\n";
    };
    print();

    std::cout << "Erase all odd numbers:\n";
    for(auto it = c.begin(); it != c.end(); ) {
        if(*it % 2 != 0)
            it = c.erase(it);
        else
            ++it;
    }
    print();

    std::cout << "Erase 1, erased count: " << c.erase(1) << '\n';
    std::cout << "Erase 2, erased count: " << c.erase(2) << '\n';
    std::cout << "Erase 2, erased count: " << c.erase(2) << '\n';
    print();
}

void swap_set() {
    std::cout << "\033[1;32m--------------------swap_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> a1, a2;

    a1.insert(3);
    a1.insert(1);
    a1.insert(3);
    a1.insert(2);

    a2.insert(5);
    a2.insert(4);
    a2.insert(5);


    auto it1 = a1.begin();
    auto it2 = a2.begin();

    const int& ref1 = *(a1.begin());
    const int& ref2 = *(a2.begin());

    std::cout << "a1 = ";
    for (NAMESPASE::set<int>::iterator it = a1.begin() ;it != a1.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "a2 = ";
    for (NAMESPASE::set<int>::iterator it = a2.begin() ;it != a2.end(); it++) {
        std::cout << *it << " ";
    }

    a1.swap(a2);
    std::cout << std::endl;
    std::cout << "a1 = ";
    for (NAMESPASE::set<int>::iterator it = a1.begin() ;it != a1.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << "a2 = ";
    for (NAMESPASE::set<int>::iterator it = a2.begin() ;it != a2.end(); it++) {
        std::cout << *it << " ";
    }
}

struct S {
    int x;
    S(int i) : x{i} { std::cout << "S{" << i << "} "; }
    bool operator<(S const& s) const { return x < s.x; }
};

struct R {
    int x;
    R(int i) : x{i} { std::cout << "R{" << i << "} "; }
    bool operator<(R const& r) const { return x < r.x; }
};
bool operator<(R const& r, int i) { return r.x < i; }
bool operator<(int i, R const& r) { return i < r.x; }

void count_set() {
    std::cout << "\n";
    std::cout << "\033[1;32m--------------------count_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> t;
    t.insert(3);
    t.insert(1);
    t.insert(4);
    t.insert(1);
    t.insert(5);
    std::cout << t.count(1) << ", " << t.count(2) << ".\n";

    NAMESPASE::set<S> s;
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1);
    s.insert(5);
    std::cout << ": " << s.count(1) << ", " << s.count(2) << ".\n";
    // Two temporary objects S{1} and S{2} were created.
    // Comparison function object is defaulted std::less<S>,
    // which is not transparent (has no is_transparent member type).

    NAMESPASE::set<R, std::less<>> r;
    r.insert(3);
    r.insert(1);
    r.insert(4);
    r.insert(1);
    r.insert(5);
    std::cout << ": " << r.count(1) << ", " << r.count(2) << ".\n";
}

void find_set() {
    std::cout << "\033[1;32m--------------------find_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> example;
    example.insert(1);
    example.insert(2);
    example.insert(3);
    example.insert(4);
    auto search = example.find(2);
    if (search != example.end()) {
        std::cout << "Found " << (*search) << '\n';
    } else {
        std::cout << "Not found\n";
    }
    search = example.find(6);
    if (search != example.end()) {
        std::cout << "Found " << (*search) << '\n';
    } else {
        std::cout << "Not found\n";
    }
}

template <typename I>
void print_equal_range(I first, I lb, I ub, I last) {
    for (I i{first}; i != lb; ++i)
        std::cout << *i << " ";
    std::cout << "[ ";
    for (I i{lb}; i != ub; ++i)
        std::cout << *i << " ";
    std::cout << "] ";
    for (I i{ub}; i != last; ++i)
        std::cout << *i << " ";
    std::cout << '\n';
}

void equal_range_set() {
    std::cout << "\033[1;32m--------------------equal_range_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> c;
    c.insert(4);
    c.insert(3);
    c.insert(2);
    c.insert(1);
    c.insert(3);
    c.insert(3);
    std::cout << "c = ";
    print_equal_range(begin(c), begin(c), end(c), end(c));
    for (int key{}; key != 6; ++key) {
        std::cout << "key = " << key << "; equal range = ";
        const auto [lb, ub] = c.equal_range(key);
        print_equal_range(begin(c), lb, ub, end(c));
    }
}

void upper_lower_bound_set() {
    std::cout << "\033[1;32m--------------------upper_lower_bound_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int> myset;
    NAMESPASE::set<int>::iterator itlow,itup;

    for (int i=1; i<10; i++) myset.insert(i*10); // 10 20 30 40 50 60 70 80 90

    itlow=myset.lower_bound (30);                //       ^
    itup=myset.upper_bound (60);                 //                   ^

    myset.erase(itlow,itup);                     // 10 20 70 80 90

    std::cout << "myset contains:";
    for (NAMESPASE::set<int>::iterator it=myset.begin(); it!=myset.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}
void key_comp_set() {
    std::cout << "\033[1;32m--------------------key_comp_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int, ModCmp> cont;
    cont.insert(1);
    cont.insert(2);
    cont.insert(3);
    cont.insert(4);
    cont.insert(5);

    auto comp_func = cont.key_comp();

    for (int key : cont) {
        bool before = comp_func(key, 100);
        bool after = comp_func(100, key);
        if (!before && !after)
            std::cout << key << " equivalent to key 100\n";
        else if (before)
            std::cout << key << " goes before key 100\n";
        else if (after)
            std::cout << key << " goes after key 100\n";
        else
            assert(0); // Cannot happen
    }
}

void value_comp_set() {
    std::cout << "\033[1;32m--------------------value_comp_set-------------------\033[0m\n";
    std::cout << "\033[1;34m-----()----\033[0m\n";

    NAMESPASE::set<int, ModCmp> cont;
    cont.insert(1);
    cont.insert(2);
    cont.insert(3);
    cont.insert(4);
    cont.insert(5);

    // Same behaviour as key_comp()
    auto comp_func = cont.value_comp();

    const int val = 100;

    for (int key : cont) {
        bool before = comp_func(key, val);
        bool after = comp_func(val, key);
        if (!before && !after)
            std::cout << key << " equivalent to key " << val << '\n';
        else if (before)
            std::cout << key << " goes before key " << val << '\n';
        else if (after)
            std::cout << key << " goes after key " << val << '\n';
        else
            assert(0); // Cannot happen
    }
}

void test_vector() {
//    https://en.cppreference.com/w/cpp/container/vector
    ////Modifiers
    test_clear();
    test_insert();
    test_erase();
    test_push_back();
    test_pop_back();
    test_resize();
    test_swap();

    ////Capacity
    test_empty();
    test_size();
    test_max_size();
    test_reserve();
    test_capacity();

    ////Iterators
    test_begin();
    test_end();

    /////Element access
    test_at();
    test_operator_pos();
    test_front();
    test_back();

    ////Member functions
    test_constructor();
    test_operator_copy();
    test_assign();
}

void test_map() {
    ////Element access
    test_at_map();
    test_operator_pos_map();
    ////Iterators
    begin_end_map();
    rbegin_rend_map();
    ////Capacity
    empty_map();
    size_map();
    max_size_map();
    ////Modifiers
    clear_map();
    insert_map();
    erase_map();
    swap_map();
    ////Lookup
    count_map();
    find_map();
    equal_range_map();
    lower_upper_bound_map();
    ////Observers
    key_comp_map();
    value_comp_map();
}

void test_stack() {
    //Element access
    top_stack();
    //Capacity
    empty_stack();
    size_stack();
    //Modifiers
    pop_push_stack();
}


void test_set() {
    //Iterators
    begin_end_set();
    rbegin_rend_set();
    //Capacity
    empty_set();
    size_set();
    max_size_set();
    //Modifiers
    clear_set();
    insert_set();
    erase_set();
    swap_set();
    //Lookup
    count_set();
    find_set();
    equal_range_set();
    upper_lower_bound_set();
    key_comp_set();
    value_comp_set();
}

int main() {
    std::cout << "\033[1;31m------------------------------TEST STACK------------------------------\033[0m\n";
    test_stack();
    std::cout<< "\n";
    std::cout << "\033[1;31m------------------------------TEST VECTOR------------------------------\033[0m\n";
    test_vector();
    std::cout << "\033[1;31m------------------------------TEST MAP------------------------------\033[0m\n";
    test_map();
    std::cout << "\033[1;31m--------------------TEST SET--------------------\033[0m\n";
    test_set();
}
























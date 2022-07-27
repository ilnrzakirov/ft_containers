#include <iostream>
#include <string>
#include <deque>
#if 0
#include <map>
#include <stack>
#include <vector>

namespace ft = std;
#else
#include "containers/map.hpp"
#include "containers/stack.hpp"
#include "containers/vector.hpp"
#endif

#include <stdlib.h>

#define MAX_RAM 4294967296
#define BUFFER_SIZE 4096
struct Buffer
{
    int idx;
    char buff[BUFFER_SIZE];
};


int main(void){

}
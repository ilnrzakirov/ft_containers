.PHONY : all fclean clean re

NAME     =	ft_containers
SRC      =	./main.cpp
OBJ      =	$(SRC:.cpp=.o)
HDR      =	./containers/map.hpp ./containers/set.hpp ./containers/stack.hpp ./containers/vector.hpp \
			./iterators/iterator.hpp ./iterators/pair.hpp ./iterators/xutility.hpp \
			./utils/enable_if.hpp ./utils/is_integral.hpp ./utils/less.hpp \
			./xtree/Tmap_traits.hpp  ./xtree/xtree.hpp


CC       =	c++

.PHONY:		all clean fclean re 
all:		$(NAME)

$(NAME):	$(OBJ) 
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp	$(HDR)
			$(CC) $(CXXFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
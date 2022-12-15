NAME = megaphone

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
CPPFLAGS =
# CPPFLAGS = -Iincludes

SRCS = megaphone.cpp
VPATH = srcs

OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:%.cpp=%.o))
DEPENDS = $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

$(OBJSDIR)/%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(DEPENDS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

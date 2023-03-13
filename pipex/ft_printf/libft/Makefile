NAME = libft.a

SRCS =  ft_toupper.c\
		ft_atoi.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_itoa.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_split.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_striteri.c\
		ft_strjoin.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strmapi.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_strrchr.c\
		ft_strtrim.c\
		ft_substr.c\
		ft_tolower.c\
		get_next_line.c\
		get_next_line_utils.c\
		
SRCS_BONUS = ft_lstiter_bonus.c\
			 ft_lstlast_bonus.c\
			 ft_lstdelone_bonus.c\
			 ft_lstadd_front_bonus.c\
			 ft_lstsize_bonus.c\
			 ft_lstclear_bonus.c\
			 ft_lstadd_back_bonus.c\
			 ft_lstnew_bonus.c\
			 ft_lstmap_bonus.c\
			 get_next_line_bonus.c\
			 get_next_line_utils_bonus.c

INCLUDES = -c -I ./libft.h

FLAGS = -Wall -Wextra -Werror 

OBJECTS = $(SRCS:.c=.o)

BONUS_OBJECTS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME):
		cc $(FLAGS) $(SRCS) $(INCLUDES)
		ar rcs $(NAME) $(OBJECTS)
#ar rcs $(NAME) $(OBJECTS)
#-s가 ranlib $(NAME) 같다

bonus: $(SRCS_BONUS:.c=.o)

$(SRCS_BONUS:.c=.o): $(SRCS_BONUS)
		cc $(FLAGS) $(SRCS_BONUS) $(INCLUDES)
		ar rus $(NAME) $(BONUS_OBJECTS)

clean:
	  rm -rf $(OBJECTS)
	  rm -rf $(BONUS_OBJECTS)

fclean: clean
	   rm -rf $(NAME)

re: fclean all


.Phoney: clean fclean re, all, bonus

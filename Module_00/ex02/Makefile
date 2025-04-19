NAME     := account
INCDIR   := include
SRCDIR   := src
OBJDIR   := obj
LOGDIR   := logs
LOGFILE  := $(LOGDIR)/account.log
SRC      := $(SRCDIR)/Account.cpp \
            $(SRCDIR)/tests.cpp
OBJ      := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRC))
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -I$(INCDIR)

GREEN    := \033[1;32m
CYAN     := \033[1;36m
RESET    := \033[0m
SMILEY   := 👍
BROOM    := 🧹
SOAP     := 🧼
PENCIL   := ✏️

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)✔ Build successful ! $(SMILEY)$(RESET)"

log: $(NAME)
	@mkdir -p $(LOGDIR)
	@./$(NAME) > $(LOGFILE)
	@echo "$(CYAN)$(PENCIL) Log written to $(LOGFILE)$(RESET)"

clean:
	@rm -rf $(OBJDIR)
	@echo "$(CYAN)$(BROOM) Object files cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME) $(LOGFILE)
	@echo "$(CYAN)$(SOAP) Full cleanup done.$(RESET)"

re: fclean all

.PHONY: all clean fclean re log

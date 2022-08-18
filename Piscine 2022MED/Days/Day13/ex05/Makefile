SOURCE	= ft_other.c main.c
HEADER	=  includes/ft.h
OUT	= do-op
GCC	 = gcc
GFLAGS = -Wall -Werror -Wextra
.PHONY: all clean

all: $(OUT)

$(OUT): $(SOURCE)
	@$(GCC) $(GFLAGS) $^  -o $@
clean:
	@rm -f $(OUT)
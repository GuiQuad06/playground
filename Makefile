include ./makefile.conf

NAME=main
LIB=$(realpath .)/Training-C/src
# Identify all the Training-C library source files
LIB_SRCS= $(wildcard $(LIB)/*.c)
# Redirect library objects file into OUT directory 
LIB_OBJS= $(patsubst $(LIB)/%.c,$(OUT)/%.o,$(LIB_SRCS))

STARTUP_DEFS=-D__STARTUP_CLEAR_BSS -D__START=main

# Linker flags
LDSCRIPTS=-L. -L$(BASE)/ldscripts -T nokeep.ld
LFLAGS=-lc -lgcc
ARM_LFLAGS=$(LCOV) $(STD_LIB) $(LDSCRIPTS) $(GC) $(MAP)

# ARM make recipe .elf
$(NAME)-$(CORE).elf: $(SRC)/$(NAME).c $(LIB_OBJS) $(STARTUP)
	$(ARM_CC) $^ $(ARM_CFLAGS) $(ARM_LFLAGS) -o $(OUT)/$@
	$(ARM_DIS) -dSs $(OUT)/$@ > $(OUT)/$(NAME)-$(CORE).dis

# Compile object for Training-C library
$(OUT)/%.o: $(LIB)/%.c
	$(CC) -c $^ $(CFLAGS) $(LFLAGS) -I $(LIB) -o $@

# Native x86_64 make recipe
$(NAME): $(SRC)/$(NAME).c $(LIB_OBJS)
	$(CC) $^ $(CFLAGS) $(LFLAGS) -I $(LIB) -o $(OUT)/$@
	$(DIS) -dSs $(OUT)/$@ > $(OUT)/$(NAME).dis

clean: 
	rm -f $(OUT)/*
	rm -f coverage.* *.gcov

# Target built with arm none eabi toolchain
.PHONY: arm
arm: $(NAME)-$(CORE).elf
	@echo '___________________________'
	@echo '_____ BUILT FOR ARM $(CORE) ____ '
	@echo '___________________________'

# Target built with native GCC
.PHONY: native
native: $(NAME)
	@echo '___________________________'
	@echo '_____ BUILT FOR x86_64 ____ '
	@echo '___________________________'

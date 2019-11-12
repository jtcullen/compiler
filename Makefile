TARGET_EXEC ?= compiler

BUILD_DIR ?= ./build
GENERATED_SRC_DIR ?= ./generated-src
SRC_DIRS ?= ./src

RE2C := re2c
RE2C_SRC := $(shell find $(SRC_DIRS) -name *.re)
RE2C_CPP := $(GENERATED_SRC_DIR)/Lexer.cpp
RE2C_FLAGS := -W -o $(RE2C_CPP)

SRCS := $(RE2C_CPP) $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d) $(GENERATED_SRC_DIR)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CC := g++
CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall -g

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(RE2C_CPP): $(RE2C_SRC)
	$(MKDIR_P) $(dir $@)
	$(RE2C) $(RE2C_FLAGS) $(RE2C_SRC)

.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR)
	$(RM) -r $(GENERATED_SRC_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p

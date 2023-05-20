APP_NAME = graph
LIB_NAME = libgraph
TEST_NAME = graph_test

CFLAGS = -Wall -Werror -I src
TESTFLAGS = -I thirdparty
DEPSFLAGS = -MMD

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.c)
APP_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.c)
LIB_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.c)
TEST_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d)

all: $(APP_PATH)	

$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	gcc $(CFLAGS) -o $@ $^

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.c
	gcc $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<


test: $(LIB_PATH) $(TEST_PATH)
	$(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -o $@ $^

$(OBJ_DIR)/test/main.o: test/main.c
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

$(OBJ_DIR)/test/tests.o: test/tests.c
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<


clean:
	rm $(APP_PATH) $(OBJ_DIR)/*/*/*.[aod]


run: all
	$(APP_PATH)

-include $(DEPS)

.PHONY: all clean test
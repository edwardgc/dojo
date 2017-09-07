GTEST_DIR = /usr/src/gtest
BOOST_LIB_DIR = /usr/lib/i386-linux-gnu
STANDARD_INC_DIR = /usr/include
SRC_DIR = ./src
TEST_DIR = ./test
INC_DIR = ./inc
LIB_DIR = ./lib
OBJ_DIR = ./obj

SRC_OBJs = $(patsubst src/%.cc, obj/%.o, $(wildcard src/*.cc))
TEST_OBJs = $(patsubst test/%.cc, obj/%.o, $(wildcard test/*.cc))

CXXFLAGS += -isystem -g -std=c++14 -Wall -Wextra -pthread

TESTS = runAll

all : $(TESTS) productCode testCode

productCode : $(SRC_OBJs)
	/usr/bin/ar cr $(LIB_DIR)/libbase.a $?

testCode : $(TEST_OBJs)
	/usr/bin/ar cr $(LIB_DIR)/libbaseUt.a $?

clean :
	rm -f $(TESTS) $(OBJ_DIR)/*.o $(LIB_DIR)/*.a

$(TESTS) : $(SRC_OBJs) $(TEST_OBJs)
	$(CXX) $(CXXFLAGS) -L$(BOOST_LIB_DIR) -L$(GTEST_DIR) $^ -lboost_system -lboost_filesystem -lgtest -lgtest_main -o $@

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -I$(STANDARD_INC_DIR) -I$(INC_DIR) -c $^ -o $@

$(OBJ_DIR)/%.o : $(TEST_DIR)/%.cc
	$(CXX) $(CXXFLAGS) -I$(STANDARD_INC_DIR) -I$(INC_DIR) -c $^ -o $@

$(OBJ_DIR) :
	mkdir -p obj

$(LIB_DIR) :
	mkdir -p lib



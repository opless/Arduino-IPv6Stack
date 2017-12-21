RED=\e[31m
YELLOW=\e[33m
GREEN=\e[32m
END=\e[0m\n

CFLAGS=-I src 
CXXFLAGS=-I classes -I src -I simulator
CSRC=$(sort $(wildcard src/*.c))
COBJ=$(patsubst src/%.c,build/%.o,$(CSRC))

XSRC=$(sort $(wildcard classes/*.cpp))
XSRC+=$(sort $(wildcard simulator/*.cpp))
COBJ+= $(patsubst classes/%.cpp,build/%.o,$(XSRC))

#VPATH=src

all: testrun



.PHONY: clean
clean:
	@echo "==================="
	@echo "=====  CLEAN  ====="
	@echo "==================="
	-rm -rf build testrun


build:
	@echo "===================="
	@echo "= CREATE BUILD DIR ="
	@echo "===================="
	-mkdir build


build/%.o:simulator/%.cpp  build
	@printf "$(GREEN) COMPILING $(YELLOW) $< $(END)"
	@$(CXX) -c $(CXXFLAGS) $< -o $@

build/%.o:classes/%.cpp  build
	@printf "$(GREEN) COMPILING $(YELLOW) $< $(END)"
	@$(CXX) -c $(CXXFLAGS) $< -o $@


build/%.o:src/%.c  build
	@printf "$(GREEN) COMPILING $(YELLOW) $< $(END)"
	@$(CC) -c $(CFLAGS) $< -o $@

#testrun: main.c $(BOBJSA) $(BOBJSB) $(BOBJSC)
#$(CC) $(CFLAGS) -o $@ main.c $(BUILT_OBJS) 

#testrun: $(COBJ) $(XOBJ)
#testrun: $(XOBJ)
testrun: main.c $(COBJ)
	@printf "$(RED) REMEMBER TO COMPILE TESTRUN $(END)"

#run: all
#	./testrun



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
#	echo $(COBJ)


build:
	@echo "===================="
	@echo "= CREATE BUILD DIR ="
	@echo "===================="
	-mkdir build
#	echo $(BUILT_OBJS)

#%.o:src/%.cpp  
#	##$(CXX) -c $(CFLAGS) $< -o $@

build/%.o:classes/%.cpp  build
	$(CXX) -c $(CXXFLAGS) $< -o $@


build/%.o:src/%.c  build
	$(CC) -c $(CFLAGS) $< -o $@

#testrun: main.c $(BOBJSA) $(BOBJSB) $(BOBJSC)
#$(CC) $(CFLAGS) -o $@ main.c $(BUILT_OBJS) 

#testrun: $(COBJ) $(XOBJ)
#testrun: $(XOBJ)
testrun: main.c $(COBJ)
	@echo testrun wants $(COBJ)

#run: all
#	./testrun



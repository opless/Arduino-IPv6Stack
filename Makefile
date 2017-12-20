CFLAGS=-I src
CSRC=$(sort $(wildcard src/*.c))
COBJ=$(patsubst src/%.c,build/%.o,$(CSRC))

XSRC=$(sort $(wildcard src/*.cpp))
COBJ+= $(patsubst src/%.cpp,build/%.o,$(XSRC))

all: build testrun

.PHONY: clean
clean:
	-rm -rf build testrun
	echo $(COBJ)

deps: $(CSRC) $(XSRC)
	$(CXX) -MD -E $(CSRC) $(XSRC) > /dev/null
	cat *.d > build/alldeps.d
	rm *.d



build:
	-mkdir build
#	echo $(OBJS)
#	echo $(BUILT_OBJS)

#%.o:src/%.cpp  
#	##$(CXX) -c $(CFLAGS) $< -o $@

#build/%.o:src/%.c  
#	$(CXX) -c $(CFLAGS) $< -o $@

#testrun: main.c $(BOBJSA) $(BOBJSB) $(BOBJSC)
#$(CC) $(CFLAGS) -o $@ main.c $(BUILT_OBJS) 

#testrun: $(COBJ) $(XOBJ)
#testrun: $(XOBJ)
testrun: $(COBJ)


run: all
	./testrun

-include build/alldeps.d


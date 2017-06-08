include ../../config.mk

OBJECTS = wonderland.o
PROCPP = wonderland.cpp

all: $(PROCPP) $(OBJECTS) $(BUILD)
#all: $(OBJECTS)

$(PROCPP):%.cpp:%.pc
	proc code=CPP PARSE=NONE CPP_SUFFIX=cpp wonderland.pc
	

$(OBJECTS): %.o: %.cpp
	$(CC) -c -I $(ORACLE_LIB) $< -o $@
	-cp *.o $(BUILD)

clean:
	-rm -f *.cpp *.o t* *.lis

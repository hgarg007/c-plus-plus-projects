include ../../config.mk

OBJECTS = main.o
PROCPP = main.cpp

all: $(PROCPP) $(OBJECTS) $(BUILD)
#all: $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	$(CC) -c -I $(ORACLE_LIB) $< -o $@
	-cp *.o $(BUILD)

clean:
	-rm -f *.o 


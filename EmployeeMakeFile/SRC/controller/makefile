include ../../config.mk

OBJECTS = controller.o
PROCPP = controller.cpp

all: $(PROCPP) $(OBJECTS) $(BUILD)
#all: $(OBJECTS)

$(OBJECTS): %.o: %.cpp
	 $(CC) -c -I $(ORACLE_LIB) $< -o $@
	 -cp *.o $(BUILD)

clean:
	 -rm -f *.o

include ../config.mk
SRC_HOME = $(PROGRAM_HOME)/SRC

SOURCES = wonderland employee controller main ui

WONDERLAND_OBJECT = $(BUILD)/wonderland.o
MAIN_OBJECT = $(BUILD)/main.o
CONTROLLER_OBJECT = $(BUILD)/controller.o
EMPLOYEE_OBJECT = $(BUILD)/employee.o
UI_OBJECT = $(BUILD)/ui.o

OBJECTS = $(WONDERLAND_OBJECT) $(EMPLOYEE_OBJECT) $(UI_OBJECT) $(CONTROLLER_OBJECT) $(MAIN_OBJECT) 

all: clean COMPILE LINK

COMPILE:
	 for d in $(SOURCES); \
		do \
		$(MAKE) --directory=$$d ; \
		done

LINK:
	$(CC) -o $(BIN) $(OBJECTS) -lclntsh -L /usr/lib/oracle/11.2/client64/lib

clean:
	for d in $(SOURCES); \
	do \
	$(MAKE) --directory=$$d clean; \
	done
	-rm -f $(BUILD)/*

SHELL 	= /bin/sh
CC 		= clang

INCLUDES     = 
FLAGS        = -std=c11
# TODO: fix these later
# CFLAGS       = -pedantic-errors -Wall -Wextra -Werror -Wthread-safety
CFLAGS       = 
# DEBUGFLAGS   = -O0 -Wno-unused -Wno-unused-parameter -g -D _DEBUG
DEBUGFLAGS   = -O0 -g -D _DEBUG
RELEASEFLAGS = -O3 -D NDEBUG
LINKFLAGS 	 = -lcunit
SHAREDFLAGS	 = -fPIC -shared -D_DEFAULT_SOURCE

TARGET			= src/test_runner
SHARED_TARGET	= algo.so
SOURCES			= $(wildcard src/*.c src/*/*.c src/*/include/*.c)
OBJECTS			= $(SOURCES:.c=.o)
DEPS			= $(OBJECTS:.o=.d)

all: $(TARGET)
all:

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) $(INCLUDES) $(CFLAGS) $(DEBUGFLAGS) $(OBJECTS) $(LINKFLAGS) $(WRAPFLAGS) -o $(TARGET)
	ASAN_OPTIONS=detect_leaks=1 ./$(TARGET)

build-only: $(SOURCES)
	$(CC) $(FLAGS) $(INCLUDES) $(CFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(SOURCES) $(LINKFLAGS)

release: $(SOURCES)
	$(CC) $(FLAGS) $(INCLUDES) $(CFLAGS) $(RELEASEFLAGS) -o $(TARGET) $(SOURCES) $(LINKFLAGS)
	./$(TARGET)

debug: $(SOURCES)
	$(CC) $(FLAGS) $(INCLUDES) $(CFLAGS) $(DEBUGFLAGS) -o $(TARGET) $(SOURCES) $(LINKFLAGS)
	./$(TARGET)

-include $(DEPS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) $(CFLAGS) $(DEBUGFLAGS) -c -o $@ $< -flto

%.d: %.c
	@$(CC) $(FLAGS) $(INCLUDES) $(CFLAGS) $(DEBUGFLAGS) $< -MM -MT $(@:.d=.o) >$@ -flto

shared: $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(FLAGS) $(RELEASEFLAGS) $(SHAREDFLAGS) -o $(SHARED_TARGET) $(SOURCES) $(LINKFLAGS) $(WRAPFLAGS)

ctags:
	ctags -R .

comp-db:
	bear -- make -B build-only

clean:
	-rm -f $(OBJECTS)
	-rm -f $(DEPS)
	-rm -f $(TARGET)
	-rm -f $(SHARED_TARGET)
	-rm -f gmon.out
	-rm -rf code_coverage
	-rm -f src/*.gcda
	-rm -f src/*/*.gcda
	-rm -f src/*.gcov
	-rm -f src/*/*.gcov
	-rm -f src/*.gcno
	-rm -f src/*/*.gcno
	-rm -f src/*.info
	-rm -f src/run_result.txt

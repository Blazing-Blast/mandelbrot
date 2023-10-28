TARGET = mandelbrot
OBJS = \
	src/mandelbrot.o \
	src/graphics/graphics.o \
	config.o
	
CXX = @ g++
LDARGS = -l minifb -l X11 -l GL -flto
CXXARGS = -c --std=c++20 -O3 -flto
SAY = @echo

all: $(TARGET)

run: $(TARGET)
	./$<

oneshot: run clean

clean:
	$(SAY) "RM 	$(OBJS)"
	@ rm -f $(OBJS)
	$(SAY) "RM	$(TARGET)"
	@ rm -f $(TARGET)

$(TARGET): $(OBJS)
	$(SAY) "LD	$@"
	@ $(CXX) -o $@ $^ $(LDARGS)

%.o: %.c++
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.cxx
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.ixx
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.cp
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.cpp
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.CPP
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.cppm
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.cc
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

%.o: %.C
	$(SAY) "CXX	$<"
	$(CXX) -o $@ $< $(CXXARGS)

.PHONY: all clean
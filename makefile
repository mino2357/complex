CXX = g++
TARGET = a
CXXFLAGS = -std=c++14 -Wall -Wextra -O2 -I/opt/local/include -L/usr/lib/ 
LDLIBS = -lglsc3d -lm -lfreetype -lGL -lGLU -lglut -lpng
SRCS = main.cpp
OBJS :=$(SRCS:.cpp=.o)

$(TARGET): $(OBJS)
	$(CXX) $(LDLIBS) -o $@ $(OBJS)

#run: all
#	./$(TARGET)

all: clean $(TARGET)

clean:
	rm $(TARGET) $(OBJS)

main.cpp : mino2357complex.hpp

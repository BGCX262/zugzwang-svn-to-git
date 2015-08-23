
libcurses=$$(pkg-config --libs --cflags ncurses)

all: showpos

%.o: %.cpp 
	$(CXX) -c -g $< -o $@

showpos: showpos.o display.o core.o
	$(CXX) $(libcurses) -g $^ -o $@

clean:
	rm -f showpos *.o

VPATH = src
DESDIR = out

output: main.o parser.o simulator.o process.o
	g++ $(DESDIR)/main.o $(DESDIR)/parser.o $(DESDIR)/simulator.o $(DESDIR)/process.o -o $(DESDIR)/output

main.o: main.cpp
	g++ -c $(VPATH)/main.cpp -o $(DESDIR)/$@

process.o: process.cpp process.h
	g++ -c $(VPATH)/process.cpp -o $(DESDIR)/$@

parser.o: parser.cpp parser.h
	g++ -c $(VPATH)/parser.cpp -o $(DESDIR)/$@

simulator.o: simulator.cpp simulator.h
	g++ -c $(VPATH)/simulator.cpp -o $(DESDIR)/$@

clean:
	rm $(DESDIR)/*.o

purge:
	rm $(DESDIR)/*.o $(DESDIR)/output
VPATH = src
DESDIR = out

output: main.o parser.o
	g++ $(DESDIR)/main.o $(DESDIR)/parser.o -o $(DESDIR)/output

main.o: main.cpp
	g++ -c $(VPATH)/main.cpp -o $(DESDIR)/$@

parser.o: parser.cpp parser.h
	g++ -c $(VPATH)/parser.cpp  -o $(DESDIR)/$@

clean:
	rm $(DESDIR)/*.o

purge:
	rm $(DESDIR)/*.o $(DESDIR)/output
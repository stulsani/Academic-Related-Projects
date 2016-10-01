output: book.o periodic.o video.o film.o media.o main.o searchengine.o
	g++ -g book.o periodic.o video.o film.o media.o main.o searchengine.o -o output

main.o: main.cpp searchengine.h media.h book.h video.h periodic.h film.h
	g++ -g -c -std=c++11 main.cpp

searchengine.o: searchengine.cpp searchengine.h
	g++ -g -c -std=c++11  searchengine.cpp

media.o: media.cpp media.h
	g++ -g -c -std=c++11 media.cpp

book.o: book.cpp book.h
	g++ -g -c -std=c++11 book.cpp

periodic.o: periodic.cpp periodic.h
	g++ -g -c -std=c++11 periodic.cpp

video.o: video.cpp video.h
	g++ -g -c -std=c++11 video.cpp

film.o: film.cpp film.h
	g++ -g -c -std=c++11 film.cpp

clean:
	rm -f *.o output

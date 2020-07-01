GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = prog

all: $(PROGRAMA) zip

zip: main.cpp diary.cpp app.cpp date.cpp diahora.cpp time.cpp app.h date.h diahora.h diary.h message.h time.h
	zip $(PROGRAMA).zip *

$(PROGRAMA): diary.o app.o date.o diahora.o time.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) *.o

main.o:	main.cpp
	$(GCC) $(GCC_FLAGS) -c main.cpp

diary.o: diary.cpp diary.h
	$(GCC) $(GCC_FLAGS) -c diary.cpp

app.o: app.cpp app.h
	$(GCC) $(GCC_FLAGS) -c app.cpp

date.o: date.cpp date.h
	$(GCC) $(GCC_FLAGS) -c date.cpp

diahora.o: diahora.cpp diahora.h
	$(GCC) $(GCC_FLAGS) -c diahora.cpp

time.o: time.cpp time.h
	$(GCC) $(GCC_FLAGS) -c time.cpp

run: $(PROGRAMA)
	./prog

.PHONY: all zip


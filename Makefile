GCC = g++
GCC_FLAGS = -I include -std=c++11
PROGRAMA = diary

all: $(PROGRAMA) zip

zip: main.cpp diary.cpp app.cpp date.cpp diahora.cpp time.cpp app.h date.h diahora.h diary.h message.h time.h
	zip $(PROGRAMA).zip *

$(PROGRAMA): diary.o app.o date.o diahora.o time.o main.o
	$(GCC) $(GCC_FLAGS) -o $(PROGRAMA) *.o

main.o:	main.cpp
	$(GCC) $(GCC_FLAGS) -c main.cpp

diary.o: diary.cpp
	$(GCC) $(GCC_FLAGS) -c diary.cpp

app.o: app.cpp
	$(GCC) $(GCC_FLAGS) -c app.cpp

date.o: date.cpp
	$(GCC) $(GCC_FLAGS) -c date.cpp

diahora.o: diahora.cpp
	$(GCC) $(GCC_FLAGS) -c diahora.cpp

time.o: time.cpp
	$(GCC) $(GCC_FLAGS) -c time.cpp

.PHONY: all zip


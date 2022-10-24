BIN=chessdotcpp.exe
CXX=g++
#CXX=clang++-15
CFLAGS=-std=c++20 -O3 -Wall -Wextra -Wpedantic -mavx2
LFLAGS=-pthread

SRCS = ChessDotCpp.cpp attacks.cpp search.cpp board.cpp fen.cpp perft.cpp movegen.cpp magics.cpp move.cpp moveorder.cpp nncpuprobe/misc.cpp nncpuprobe/nncpu.cpp uci.cpp tablebases.cpp evaluationClassical2.cpp movepick.cpp searchhash.cpp #external/fathom/src/tbprobe.cpp
$(info $(SRCS))

OBJS = ChessDotCpp.o   attacks.o   search.o   board.o   fen.o   perft.o   movegen.o   magics.o   move.o   moveorder.o   nncpuprobe/misc.o   nncpuprobe/nncpu.o   uci.o   tablebases.o   evaluationClassical2.o   movepick.o   searchhash.o   #external/fathom/src/tbprobe.o
$(info $(OBJS))

all: build

build: $(OBJS)
	$(CXX) $(LFLAGS) -o $(BIN) $^

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^

clean: cleanobjs cleanbin

cleanobjs:
	rm -f $(OBJS)
	rm -f *.o.tmp

cleanbin:
	rm -f $(BIN)
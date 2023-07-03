NAME := chessdotcpp
ifeq ($(OS), Windows_NT)
	SUFFIX := .exe
else
	SUFFIX :=
endif
BIN := $(NAME)$(SUFFIX)

ifndef CXX
	CXX=g++
endif
CFLAGS=-std=c++20 -O3 -Wall -Wextra -Wpedantic -mavx2 $(EXTRACFLAGS)
LFLAGS=-pthread $(EXTRALFLAGS)

SRCS = ChessDotCpp.cpp attacks.cpp search.cpp board.cpp fen.cpp perft.cpp movegen.cpp magics.cpp move.cpp moveorder.cpp uci.cpp tablebases.cpp evaluationClassical2.cpp movepick.cpp searchhash.cpp #external/fathom/src/tbprobe.cpp
OBJS = ChessDotCpp.o attacks.o search.o board.o fen.o perft.o movegen.o magics.o move.o moveorder.o uci.o tablebases.o evaluationClassical2.o movepick.o searchhash.o   #external/fathom/src/tbprobe.o

ifeq ($(OS),Windows_NT)
	#RM = del /F
	RM = rm -f
else
	RM = rm -f
endif

$(info $(CXX))
$(info $(CFLAGS))
$(info $(LFLAGS))
$(info $(SRCS))
$(info $(OBJS))

all: build

build: $(OBJS)
	$(CXX) -o $(BIN) $^ $(LFLAGS)
	$(MAKE) clean-objs

pgo:
ifeq ($(CXX),g++)
	$(MAKE) EXTRACFLAGS='-fprofile-generate' EXTRALFLAGS='-lgcov' build
	./$(BIN) bench
	$(MAKE) clean-objs clean-bin
	$(MAKE) EXTRACFLAGS='-fprofile-use -fno-peel-loops -fno-tracer' EXTRALFLAGS='-lgcov' build
	$(MAKE) clean-objs clean-profile
# TODO
# else ifeq ($(CXX),clang++)
# 	$(MAKE) EXTRACFLAGS='-fprofile-instr-generate' EXTRALFLAGS='-fprofile-instr-generate' build
# 	./$(BIN) bench
# 	llvm-profdata merge -output=all.profdata *.profraw
# 	$(MAKE) clean-objs clean-bin
# 	$(MAKE) EXTRACFLAGS='-fprofile-instr-use=all.profdata' EXTRALFLAGS='-fprofile-use' build
# 	$(MAKE) clean-objs clean-profile
else
	$(error Unknown compiler for PGO build)
endif

%.o: %.cpp
	$(CXX) $(CFLAGS) -c -o $@ $^

clean: clean-objs clean-bin clean-profile

clean-objs:
	$(RM) *.o
	$(RM) *.o.tmp

clean-bin:
	$(RM) $(BIN)

clean-profile:
	$(RM) *.gcda
	$(RM) *.profraw
	$(RM) all.profdata
NAME := chessdotcpp

ifndef ARCH
	ARCH := avx2
endif

ifeq ($(OS), Windows_NT)
	SUFFIX := .exe
else
	SUFFIX :=
endif

BIN := $(NAME)-$(ARCH)$(SUFFIX)

ifdef CLASSICAL
	NNUE_FLAG := -DNNUE=0
else
	NNUE_FLAG := -DNNUE=1
endif

ifdef INCBIN
	INCBIN_FLAG := -DENABLE_INCBIN=1
else
	INCBIN_FLAG :=
endif

ifdef NO_TABLEBASES
	TABLEBASES_FLAG := -DENABLE_TABLEBASES=0
	TABLEBASES_SRCS :=
	TABLEBASES_OBJS :=
else
	TABLEBASES_FLAG := -DENABLE_TABLEBASES=1
	TABLEBASES_SRCS := external/fathom/src/tbprobe.cpp
	TABLEBASES_OBJS := external/fathom/src/tbprobe.o
endif

ifndef CXX
	CXX=g++
endif

CFLAGS=-std=c++20 -O3 -Wall -Wextra -Wpedantic -m$(ARCH) $(NNUE_FLAG) $(INCBIN_FLAG) $(TABLEBASES_FLAG) $(EXTRACFLAGS)
LFLAGS=-pthread $(EXTRALFLAGS)

SRCS = ChessDotCpp.cpp attacks.cpp search.cpp board.cpp fen.cpp perft.cpp movegen.cpp magics.cpp move.cpp moveorder.cpp uci.cpp tablebases.cpp evaluationClassical2.cpp movepick.cpp searchhash.cpp evaluationNnueBase.cpp $(TABLEBASES_SRCS)
OBJS = ChessDotCpp.o attacks.o search.o board.o fen.o perft.o movegen.o magics.o move.o moveorder.o uci.o tablebases.o evaluationClassical2.o movepick.o searchhash.o evaluationNnueBase.o  $(TABLEBASES_OBJS)

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

all: pull-net build

pull-net:
	git submodule update --init --depth 1

build: $(OBJS)
	$(CXX) -o $(BIN) $^ $(LFLAGS)
	$(MAKE) clean-objs

pgo: pull-net
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
	$(RM) external/fathom/src/tbprobe.o

clean-bin:
	$(RM) $(BIN)

clean-profile:
	$(RM) *.gcda
	$(RM) external/fathom/src/tbprobe.gcda
	$(RM) *.profraw
	$(RM) external/fathom/src/tbprobe.profraw
	$(RM) all.profdata
	
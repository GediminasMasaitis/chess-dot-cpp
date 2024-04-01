NAME := chessdotcpp
EVALFILE := networks/default.nnue

ifndef ARCH
	ARCH := avx2
endif

ifeq ($(OS), Windows_NT)
	SUFFIX := .exe
else
	SUFFIX :=
endif

EXE := $(NAME)-$(ARCH)$(SUFFIX)

ifdef CLASSICAL
	NNUE_FLAG := -DNNUE=0
else
	NNUE_FLAG := -DNNUE=1
endif

ifdef INCBIN
	INCBIN_FLAG := -DENABLE_INCBIN=1
else
	INCBIN_FLAG := -DENABLE_INCBIN=1 #always incbin
endif
EVALFILE_FLAG := -DEVALFILE=\"$(EVALFILE)\"

ifdef NO_TABLEBASES
	TABLEBASES_FLAG := -DENABLE_TABLEBASES=0
	TABLEBASES_SRCS :=
else
	TABLEBASES_FLAG := -DENABLE_TABLEBASES=1
	TABLEBASES_SRCS := external/fathom/src/tbprobe.cpp
endif

ifndef CXX
	CXX=g++
endif

CFLAGS=-std=c++20 -O3 -Wall -Wextra -Wpedantic -m$(ARCH) $(NNUE_FLAG) $(INCBIN_FLAG) $(TABLEBASES_FLAG) $(EXTRACFLAGS) $(EVALFILE_FLAG)
LFLAGS=-pthread --static $(EXTRALFLAGS)

SRCS = ChessDotCpp.cpp attacks.cpp search.cpp board.cpp fen.cpp perft.cpp movegen.cpp magics.cpp move.cpp moveorder.cpp uci.cpp tablebases.cpp evaluationClassical2.cpp movepick.cpp searchhash.cpp evaluationNnueBase.cpp $(TABLEBASES_SRCS)

ifeq ($(OS),Windows_NT)
	RM = del /F
else
	RM = rm -f
endif

$(info $(CXX))
$(info $(CFLAGS))
$(info $(LFLAGS))
$(info $(SRCS))
$(info $(OBJS))

all: build

build: $(SRCS)
	$(CXX) -o $(EXE) $^ $(CFLAGS) $(LFLAGS)

pgo:
ifeq ($(CXX),g++)
	$(MAKE) EXTRACFLAGS='-fprofile-generate' EXTRALFLAGS='-lgcov' build
	./$(BIN) bench
	$(MAKE) EXTRACFLAGS='-fprofile-use -fno-peel-loops -fno-tracer' EXTRALFLAGS='-lgcov' build
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

clean: clean-bin clean-profile

clean-bin:
	$(RM) $(BIN)

clean-profile:
	$(RM) *.gcda
	$(RM) external/fathom/src/tbprobe.gcda
	$(RM) *.profraw
	$(RM) external/fathom/src/tbprobe.profraw
	$(RM) all.profdata

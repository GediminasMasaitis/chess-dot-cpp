# Chess.cpp

Chess.cpp is a C++ chess engine made from scratch. It uses a lot of common chess engine tecniques used many other engines, with a little bit of original ideas sprinkled in.

* Version 1: Using an evaluation smilar to [CPW engine](https://github.com/nescitus/cpw-engine) but adapted for bitboards, incrementally building up search features. Final ELO ~2680
* Version 2: Using a handcrafted evaluation optimised by [Texel tuning](https://github.com/AndyGrant/Ethereal/blob/master/Tuning.pdf). Enabled multithreaded search with lazy SMP. Final ELO ~2930 1CPU, ~3000 4CPU, ~3040 12CPU
* Version 3: Using a NNUE evaluation trained on self-generated data.

For more details on each version see [changelog.md](changelog.md)

## Special thanks
* [**Chess Programing Wiki**](https://www.chessprogramming.org) for teaching the basics and later on some more complex topics.
* [**Engine Programming Discord**](https://discord.gg/invite/YctB2p4) for answering many (often dumb) questions I had along the way.
* [**Luecx**](https://github.com/Luecx) for giving me endless tips regarding data generation and NNUE training, and for writing a NNUE trainer [CudAD](https://github.com/Luecx/CudAD) which I used to train my NNUE networks.
### 1.0
Initial release

### 1.1
Quiessence

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 205 time 102 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 205 nps 1990 time 103 pv d2d4 d7d5
info depth 3 multipv 1 score cp 32 nodes 2116 nps 20346 time 104 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 18194 nps 168462 time 108 pv e2e4 e7e5 b1c3 b8c6
info depth 5 multipv 1 score cp 30 nodes 108955 nps 801139 time 136 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 11 nodes 1376889 nps 2573624 time 535 pv e2e3 g8f6 d2d4 e7e6 f1b5 b8c6
info depth 7 multipv 1 score cp 33 nodes 9559949 nps 3168693 time 3017 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 9 nodes 167689990 nps 3179740 time 52737 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e5 d1e2 b8c6
```

### 1.2
Do not reinitialize state on new search

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 205 nps 205000 time 1 pv d2d4 d7d5
info depth 3 multipv 1 score cp 32 nodes 2116 nps 2116000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 18194 nps 3638800 time 5 pv e2e4 e7e5 b1c3 b8c6
info depth 5 multipv 1 score cp 30 nodes 108955 nps 3204558 time 34 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 11 nodes 1376889 nps 3158002 time 436 pv e2e3 g8f6 d2d4 e7e6 f1b5 b8c6
info depth 7 multipv 1 score cp 33 nodes 9559949 nps 3271714 time 2922 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 9 nodes 167689990 nps 3178535 time 52757 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e5 d1e2 b8c6
```

```
Score of ChessDotCppDev vs tscp: 6 - 174 - 20  [0.080] 200
...      ChessDotCppDev playing White: 3 - 89 - 9  [0.074] 101
...      ChessDotCppDev playing Black: 3 - 85 - 11  [0.086] 99
...      White vs Black: 88 - 92 - 20  [0.490] 200
Elo difference: -424.3 +/- 75.5, LOS: 0.0 %, DrawRatio: 10.0 %
```

### 1.3
In check extension

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 205 nps 205000 time 1 pv d2d4 d7d5
info depth 3 multipv 1 score cp 32 nodes 2134 nps 2134000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 18548 nps 3091333 time 6 pv g1f3 d7d6 d2d4 g8f6
info depth 5 multipv 1 score cp 30 nodes 114098 nps 3169388 time 36 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 10 nodes 1463147 nps 3222790 time 454 pv g1f3 g8f6 d2d3 d7d6 e2e4 e7e5
info depth 7 multipv 1 score cp 33 nodes 11309006 nps 3283683 time 3444 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 185474295 nps 3181540 time 58297 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
```

```
Score of ChessDotCppDev vs tscp: 18 - 147 - 35  [0.177] 200
...      ChessDotCppDev playing White: 10 - 68 - 22  [0.210] 100
...      ChessDotCppDev playing Black: 8 - 79 - 13  [0.145] 100
...      White vs Black: 89 - 76 - 35  [0.532] 200
Elo difference: -266.4 +/- 53.6, LOS: 0.0 %, DrawRatio: 17.5 %
```
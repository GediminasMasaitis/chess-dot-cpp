### 1.0.1
Initial release

```
info depth 1 multipv 1 score cp 44 nodes 1 nps 1000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 22 nps 22000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 44 nodes 190 nps 190000 time 1 pv d2d4 d7d5 e2e4
info depth 4 multipv 1 score cp -5 nodes 1617 nps 539000 time 3 pv g1f3 d7d5 d2d4 e7e5
info depth 5 multipv 1 score cp 90 nodes 11299 nps 364483 time 31 pv e2e4 e7e6 d1g4 d7d5 g4g7
info depth 6 multipv 1 score cp -57 nodes 105318 nps 554305 time 190 pv b1c3 e7e6 e2e4 f8b4 c3b5 b4d2
info depth 7 multipv 1 score cp 108 nodes 658111 nps 336285 time 1957 pv e2e3 e7e6 d1h5
info depth 8 multipv 1 score cp -62 nodes 7486458 nps 569485 time 13146 pv e2e3 e7e6 d1g4 g8h6 g4c4 h6f5 e3e4
```

```
Score of ChessDotCppDev vs tscp: 4 - 189 - 7  [0.037] 200
...      ChessDotCppDev playing White: 2 - 94 - 3  [0.035] 99
...      ChessDotCppDev playing Black: 2 - 95 - 4  [0.040] 101
...      White vs Black: 97 - 96 - 7  [0.502] 200
Elo difference: -563.7 +/- 127.4, LOS: 0.0 %, DrawRatio: 3.5 %
```

### 1.1.1
Quiessence

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 205 nps 205000 time 1 pv d2d4 d7d5
info depth 3 multipv 1 score cp 32 nodes 2116 nps 2116000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 18194 nps 3638800 time 5 pv e2e4 e7e5 b1c3 b8c6
info depth 5 multipv 1 score cp 30 nodes 108955 nps 3301666 time 33 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 11 nodes 1376889 nps 3158002 time 436 pv e2e3 g8f6 d2d4 e7e6 f1b5 b8c6
info depth 7 multipv 1 score cp 33 nodes 9559949 nps 3287465 time 2908 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 9 nodes 167689990 nps 3162887 time 53018 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e5 d1e2 b8c6
```

```
Score of ChessDotCppDev vs tscp: 3 - 171 - 26  [0.080] 200
...      ChessDotCppDev playing White: 3 - 84 - 13  [0.095] 100
...      ChessDotCppDev playing Black: 0 - 87 - 13  [0.065] 100
...      White vs Black: 90 - 84 - 26  [0.515] 200
Elo difference: -424.3 +/- 68.9, LOS: 0.0 %, DrawRatio: 13.0 %
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

### 1.3.1
In check extension

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 205 nps 205000 time 1 pv d2d4 d7d5
info depth 3 multipv 1 score cp 32 nodes 2134 nps 2134000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 18548 nps 3709600 time 5 pv g1f3 d7d6 d2d4 g8f6
info depth 5 multipv 1 score cp 30 nodes 114098 nps 3355823 time 34 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 10 nodes 1463147 nps 3222790 time 454 pv g1f3 g8f6 d2d3 d7d6 e2e4 e7e5
info depth 7 multipv 1 score cp 33 nodes 11309006 nps 3299009 time 3428 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 185474295 nps 3182851 time 58273 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
```

```
Score of ChessDotCppDev vs tscp: 14 - 149 - 37  [0.163] 200
...      ChessDotCppDev playing White: 7 - 71 - 22  [0.180] 100
...      ChessDotCppDev playing Black: 7 - 78 - 15  [0.145] 100
...      White vs Black: 85 - 78 - 37  [0.517] 200
Elo difference: -284.9 +/- 54.0, LOS: 0.0 %, DrawRatio: 18.5 %
```

### 1.4.1
Probe transposition table

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 205 nps 205000 time 1 pv d2d4 d7d5
info depth 3 multipv 1 score cp 32 nodes 2134 nps 2134000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 18432 nps 3072000 time 6 pv g1f3 d7d6 d2d4 g8f6
info depth 5 multipv 1 score cp 30 nodes 106160 nps 3216969 time 33 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 10 nodes 1296469 nps 3193273 time 406 pv g1f3 g8f6 d2d3 d7d6 e2e4 e7e5
info depth 7 multipv 1 score cp 33 nodes 8769407 nps 3255162 time 2694 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 138033426 nps 3152023 time 43792 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
```

```
Score of ChessDotCppDev vs tscp: 15 - 150 - 35  [0.163] 200
...      ChessDotCppDev playing White: 8 - 71 - 21  [0.185] 100
...      ChessDotCppDev playing Black: 7 - 79 - 14  [0.140] 100
...      White vs Black: 87 - 78 - 35  [0.522] 200
Elo difference: -284.9 +/- 54.7, LOS: 0.0 %, DrawRatio: 17.5 %
```


### 1.5.1
Move ordering: PV move first

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 119 nps 119000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 1208 nps 1208000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 8500 nps 2833333 time 3 pv g1f3 d7d6 d2d4 g8f6
info depth 5 multipv 1 score cp 30 nodes 45887 nps 2867937 time 16 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 10 nodes 454353 nps 2822068 time 161 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 33 nodes 2041332 nps 2843080 time 718 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 51072371 nps 2858474 time 17867 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
```

```
Score of ChessDotCppDev vs tscp: 38 - 123 - 39  [0.287] 200
...      ChessDotCppDev playing White: 24 - 54 - 22  [0.350] 100
...      ChessDotCppDev playing Black: 14 - 69 - 17  [0.225] 100
...      White vs Black: 93 - 68 - 39  [0.563] 200
Elo difference: -157.7 +/- 46.8, LOS: 0.0 %, DrawRatio: 19.5 %
```

### 1.6.1
Move ordering: captures before quiets

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 119 nps 119000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 1214 nps 1214000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 7682 nps 2560666 time 3 pv g1f3 d7d6 d2d4 g8f6
info depth 5 multipv 1 score cp 30 nodes 39881 nps 2848642 time 14 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 10 nodes 314716 nps 3026115 time 104 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 33 nodes 1303232 nps 3110338 time 419 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 25742040 nps 3082140 time 8352 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 196302503 nps 3112701 time 63065 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4
```

```
Score of ChessDotCppDev vs tscp: 83 - 56 - 61  [0.568] 200
...      ChessDotCppDev playing White: 47 - 27 - 26  [0.600] 100
...      ChessDotCppDev playing Black: 36 - 29 - 35  [0.535] 100
...      White vs Black: 76 - 63 - 61  [0.532] 200
Elo difference: 47.2 +/- 40.5, LOS: 98.9 %, DrawRatio: 30.5 %
```

```
Score of ChessDotCppDev vs vice: 30 - 125 - 45  [0.263] 200
...      ChessDotCppDev playing White: 19 - 56 - 25  [0.315] 100
...      ChessDotCppDev playing Black: 11 - 69 - 20  [0.210] 100
...      White vs Black: 88 - 67 - 45  [0.552] 200
Elo difference: -179.5 +/- 46.5, LOS: 0.0 %, DrawRatio: 22.5 %
```

### 1.7.1
Move ordering: killer heuristic

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 882 nps 882000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 4505 nps 2252500 time 2 pv g1f3 d7d6 d2d4 g8f6
info depth 5 multipv 1 score cp 30 nodes 27079 nps 2707900 time 10 pv b1c3 b8c6 e2e3 e7e5 d2d4
info depth 6 multipv 1 score cp 10 nodes 184230 nps 2971451 time 62 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 33 nodes 723515 nps 3118599 time 232 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 7378153 nps 3047564 time 2421 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 42623286 nps 3118016 time 13670 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5
```

```
Score of ChessDotCppDev vs vice: 35 - 112 - 53  [0.307] 200
...      ChessDotCppDev playing White: 16 - 57 - 27  [0.295] 100
...      ChessDotCppDev playing Black: 19 - 55 - 26  [0.320] 100
...      White vs Black: 71 - 76 - 53  [0.487] 200
Elo difference: -141.0 +/- 43.6, LOS: 0.0 %, DrawRatio: 26.5 %
```

### 1.8.1
Move ordering: history heuristic

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 729 nps 729000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 4252 nps 4252000 time 1 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 26494 nps 2649400 time 10 pv b1c3 b8c6 d2d4 e7e5 e2e3
info depth 6 multipv 1 score cp 10 nodes 144762 nps 2838470 time 51 pv e2e3 d7d5 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 7 multipv 1 score cp 33 nodes 832266 nps 2961800 time 281 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 5529958 nps 2913571 time 1898 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3
info depth 9 multipv 1 score cp 34 nodes 36202964 nps 2924310 time 12380 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
```

```
Score of ChessDotCppDev vs vice: 41 - 102 - 57  [0.347] 200
...      ChessDotCppDev playing White: 22 - 48 - 30  [0.370] 100
...      ChessDotCppDev playing Black: 19 - 54 - 27  [0.325] 100
...      White vs Black: 76 - 67 - 57  [0.522] 200
Elo difference: -109.5 +/- 42.1, LOS: 0.0 %, DrawRatio: 28.5 %
```

### 1.9.1
Move ordering: MvvLva

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 727 nps 727000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3989 nps 3989000 time 1 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 24697 nps 2744111 time 9 pv b1c3 b8c6 d2d4 e7e5 e2e3
info depth 6 multipv 1 score cp 10 nodes 112925 nps 2754268 time 41 pv e2e3 d7d5 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 7 multipv 1 score cp 33 nodes 719234 nps 2900137 time 248 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 3664354 nps 2767638 time 1324 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3
info depth 9 multipv 1 score cp 34 nodes 25938981 nps 2836721 time 9144 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 20 nodes 136787825 nps 2745310 time 49826 pv g1f3 g8f6 b1c3 b8c6
```

```
Score of ChessDotCppDev vs vice: 59 - 68 - 73  [0.477] 200
...      ChessDotCppDev playing White: 32 - 33 - 35  [0.495] 100
...      ChessDotCppDev playing Black: 27 - 35 - 38  [0.460] 100
...      White vs Black: 67 - 60 - 73  [0.517] 200
Elo difference: -15.6 +/- 38.5, LOS: 21.2 %, DrawRatio: 36.5 %
```

### 1.10.1
Null move pruning

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 727 nps 727000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3821 nps 3821000 time 1 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 23072 nps 2884000 time 8 pv b1c3 b8c6 d2d4 e7e5 e2e3
info depth 6 multipv 1 score cp 10 nodes 74847 nps 2772111 time 27 pv e2e3 d7d5 d2d4 e7e6 g1f3 g8f6
info depth 7 multipv 1 score cp 33 nodes 391043 nps 2940172 time 133 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 1215845 nps 2887992 time 421 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 4161896 nps 2884196 time 1443 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 20 nodes 14244923 nps 2874858 time 4955 pv g1f3 g8f6 b1c3 b8c6 e2e4 d7d5 e4e5 f6g4 d2d4 c8f5
info depth 11 multipv 1 score cp 33 nodes 56580832 nps 2866158 time 19741 pv e2e4 e7e5 g1f3 g8f6 f1c4 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 204553661 nps 2863854 time 71426 pv e2e4 e7e5 g1f3 g8f6
```

```
Score of ChessDotCppDev vs vice: 77 - 53 - 70  [0.560] 200
...      ChessDotCppDev playing White: 49 - 16 - 35  [0.665] 100
...      ChessDotCppDev playing Black: 28 - 37 - 35  [0.455] 100
...      White vs Black: 86 - 44 - 70  [0.605] 200
Elo difference: 41.9 +/- 39.1, LOS: 98.2 %, DrawRatio: 35.0 %
```

```
Score of ChessDotCppDev vs mediocre: 14 - 159 - 27  [0.138] 200
...      ChessDotCppDev playing White: 7 - 75 - 18  [0.160] 100
...      ChessDotCppDev playing Black: 7 - 84 - 9  [0.115] 100
...      White vs Black: 91 - 82 - 27  [0.522] 200
Elo difference: -319.0 +/- 60.6, LOS: 0.0 %, DrawRatio: 13.5 %
```

### 1.10.1
Evaluation hash table

```
info depth 1 multipv 1 score cp 44 nodes 21 nps 21000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 727 nps 727000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3821 nps 1910500 time 2 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 23072 nps 2563555 time 9 pv b1c3 b8c6 d2d4 e7e5 e2e3
info depth 6 multipv 1 score cp 10 nodes 74847 nps 2772111 time 27 pv e2e3 d7d5 d2d4 e7e6 g1f3 g8f6
info depth 7 multipv 1 score cp 33 nodes 391043 nps 3179211 time 123 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 1215845 nps 3158038 time 385 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 4161896 nps 3174596 time 1311 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 20 nodes 14244923 nps 3103469 time 4590 pv g1f3 g8f6 b1c3 b8c6 e2e4 d7d5 e4e5 f6g4 d2d4 c8f5
info depth 11 multipv 1 score cp 33 nodes 56580832 nps 3076550 time 18391 pv e2e4 e7e5 g1f3 g8f6 f1c4 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 204553661 nps 2997079 time 68251 pv e2e4 e7e5 g1f3 g8f6
```

```
Score of ChessDotCppDev vs mediocre: 18 - 148 - 34  [0.175] 200
...      ChessDotCppDev playing White: 8 - 73 - 19  [0.175] 100
...      ChessDotCppDev playing Black: 10 - 75 - 15  [0.175] 100
...      White vs Black: 83 - 83 - 34  [0.500] 200
Elo difference: -269.4 +/- 54.1, LOS: 0.0 %, DrawRatio: 17.0 %
```

### 1.11.1
Principal variation search

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 777 nps 777000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 4043 nps 2021500 time 2 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 21621 nps 2402333 time 9 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 69490 nps 2779600 time 25 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 33 nodes 198116 nps 2830228 time 70 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 869513 nps 2957527 time 294 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 2990681 nps 2937800 time 1018 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 20 nodes 7885249 nps 2909685 time 2710 pv g1f3 g8f6 b1c3 b8c6 e2e4 d7d5 e4e5 f6g4 d2d4 c8f5
info depth 11 multipv 1 score cp 33 nodes 27407805 nps 2812499 time 9745 pv e2e4 e7e5 g1f3 g8f6 f1c4 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 56611482 nps 2765042 time 20474 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 25 nodes 136071196 nps 2753474 time 49418 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 f3e5 d8h4 d1f3 f7f5 d3b5 c7c6
```

```
Score of ChessDotCppDev vs vice: 196 - 116 - 188  [0.580] 500
...      ChessDotCppDev playing White: 117 - 38 - 95  [0.658] 250
...      ChessDotCppDev playing Black: 79 - 78 - 93  [0.502] 250
...      White vs Black: 195 - 117 - 188  [0.578] 500
Elo difference: 56.1 +/- 24.2, LOS: 100.0 %, DrawRatio: 37.6 %

Score of ChessDotCppDev vs mediocre: 18 - 145 - 37  [0.182] 200
...      ChessDotCppDev playing White: 9 - 73 - 18  [0.180] 100
...      ChessDotCppDev playing Black: 9 - 72 - 19  [0.185] 100
...      White vs Black: 81 - 82 - 37  [0.497] 200
Elo difference: -260.5 +/- 52.6, LOS: 0.0 %, DrawRatio: 18.5 %
```

### 1.12.1
Static evaluation pruning

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 777 nps 777000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 4043 nps 2021500 time 2 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 21533 nps 2691625 time 8 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 68004 nps 2833500 time 24 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 33 nodes 189451 nps 2786044 time 68 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 814381 nps 2827711 time 288 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 2521002 nps 2782562 time 906 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 20 nodes 6439376 nps 2734342 time 2355 pv g1f3 g8f6 b1c3 b8c6 e2e4 d7d5 e4e5 f6g4 d2d4 c8f5
info depth 11 multipv 1 score cp 33 nodes 20377296 nps 2639204 time 7721 pv e2e4 e7e5 g1f3 g8f6 f1c4 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 42042196 nps 2585779 time 16259 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 25 nodes 90732806 nps 2559747 time 35446 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 f3e5 d8h4 d1f3 f7f5 d3b5 c7c6
```

```
Score of ChessDotCppDev vs vice: 207 - 113 - 180  [0.594] 500
...      ChessDotCppDev playing White: 115 - 49 - 86  [0.632] 250
...      ChessDotCppDev playing Black: 92 - 64 - 94  [0.556] 250
...      White vs Black: 179 - 141 - 180  [0.538] 500
Elo difference: 66.1 +/- 24.6, LOS: 100.0 %, DrawRatio: 36.0 %

Score of ChessDotCppDev vs mediocre: 57 - 336 - 107  [0.221] 500
...      ChessDotCppDev playing White: 33 - 158 - 59  [0.250] 250
...      ChessDotCppDev playing Black: 24 - 178 - 48  [0.192] 250
...      White vs Black: 211 - 182 - 107  [0.529] 500
Elo difference: -218.9 +/- 30.6, LOS: 0.0 %, DrawRatio: 21.4 %
```

### 1.13.1
Futility pruning

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 777 nps 777000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3992 nps 3992000 time 1 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 20668 nps 2952571 time 7 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 62664 nps 2724521 time 23 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 33 nodes 168569 nps 2675698 time 63 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 688799 nps 2669763 time 258 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 2048858 nps 2570712 time 797 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 20 nodes 5160858 nps 2532315 time 2038 pv g1f3 g8f6 b1c3 b8c6 e2e4 d7d5 e4e5 f6g4 d2d4 c8f5
info depth 11 multipv 1 score cp 33 nodes 15900849 nps 2390745 time 6651 pv e2e4 e7e5 g1f3 g8f6 f1c4 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 31717453 nps 2311767 time 13720 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 25 nodes 65654068 nps 2246580 time 29224 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 f3e5 d8h4 d1f3 f7f5 d3b5 c7c6
```

```
Score of ChessDotCppDev vs vice: 219 - 98 - 183  [0.621] 500
...      ChessDotCppDev playing White: 115 - 42 - 93  [0.646] 250
...      ChessDotCppDev playing Black: 104 - 56 - 90  [0.596] 250
...      White vs Black: 171 - 146 - 183  [0.525] 500
Elo difference: 85.8 +/- 24.6, LOS: 100.0 %, DrawRatio: 36.6 %

Score of ChessDotCppDev vs mediocre: 70 - 328 - 102  [0.242] 500
...      ChessDotCppDev playing White: 43 - 151 - 56  [0.284] 250
...      ChessDotCppDev playing Black: 27 - 177 - 46  [0.200] 250
...      White vs Black: 220 - 178 - 102  [0.542] 500
Elo difference: -198.3 +/- 30.3, LOS: 0.0 %, DrawRatio: 20.4 %
```

### 1.14.1
Repetition and 50 move rule detection

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 777 nps 777000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3992 nps 1996000 time 2 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 20668 nps 2583500 time 8 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 62664 nps 2724521 time 23 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 33 nodes 168569 nps 2633890 time 64 pv g1f3 d7d5 e2e3 c8g4 f1e2 d8d6 e1g1
info depth 8 multipv 1 score cp 13 nodes 688799 nps 2639076 time 261 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 34 nodes 2048857 nps 2564276 time 799 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 20 nodes 5160853 nps 2531070 time 2039 pv g1f3 g8f6 b1c3 b8c6 e2e4 d7d5 e4e5 f6g4 d2d4 c8f5
info depth 11 multipv 1 score cp 33 nodes 15900786 nps 2390376 time 6652 pv e2e4 e7e5 g1f3 g8f6 f1c4 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 31644652 nps 2310671 time 13695 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 25 nodes 65746487 nps 2244673 time 29290 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 f3e5 d8h4 d1f3 f7f5 d3b5 c7c6
info depth 14 multipv 1 score cp 16 nodes 194054990 nps 2234009 time 86864 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 f8c5
```

```
Score of ChessDotCppDev vs vice: 322 - 99 - 79  [0.723] 500
...      ChessDotCppDev playing White: 177 - 38 - 35  [0.778] 250
...      ChessDotCppDev playing Black: 145 - 61 - 44  [0.668] 250
...      White vs Black: 238 - 183 - 79  [0.555] 500
Elo difference: 166.7 +/- 30.6, LOS: 100.0 %, DrawRatio: 15.8 %

Score of ChessDotCppDev vs mediocre: 56 - 184 - 52  [0.281] 292
...      ChessDotCppDev playing White: 32 - 87 - 27  [0.312] 146
...      ChessDotCppDev playing Black: 24 - 97 - 25  [0.250] 146
...      White vs Black: 129 - 111 - 52  [0.531] 292
Elo difference: -163.4 +/- 39.4, LOS: 0.0 %, DrawRatio: 17.8 %
```

### 1.15.1
Late move reductions

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 450 nps 450000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1929 nps 1929000 time 1 pv b1c3 e7e5 e2e4 b8c6
info depth 5 multipv 1 score cp 30 nodes 4202 nps 4202000 time 1 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 11 nodes 16381 nps 2730166 time 6 pv d2d4 d7d5 e2e3 g8f6 f1b5 b8c6 g1f3
info depth 7 multipv 1 score cp 20 nodes 33393 nps 2568692 time 13 pv b1c3 d7d5 e2e4 e7e6 e4d5 e6d5 d2d4
info depth 8 multipv 1 score cp 13 nodes 86994 nps 2485542 time 35 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 26 nodes 177355 nps 2497957 time 71 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e6 f1e2 g8f6 d2d4 b8c6
info depth 10 multipv 1 score cp 21 nodes 436349 nps 2551748 time 171 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 d2d4 f8b4 c1g5 d7d6
info depth 11 multipv 1 score cp 18 nodes 965231 nps 2462323 time 392 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 b8c6 f1b5 d8e7 d1e2 c8f5
info depth 12 multipv 1 score cp 24 nodes 1794276 nps 2382836 time 753 pv e2e4 b8c6 g1f3 e7e5 b1c3 f8b4 f1c4 g8f6 e1g1 e8g8 d2d3 d7d6
info depth 13 multipv 1 score cp 28 nodes 2838110 nps 2324414 time 1221 pv e2e4 b8c6 g1f3 e7e5 f1c4 g8f6 d2d3 f8c5 e1g1 e8g8 b1c3 d7d6 c1g5
info depth 14 multipv 1 score cp 10 nodes 8214922 nps 2246355 time 3657 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 d2d3 e8g8 e1g1 b4c3 b2c3 d7d6
info depth 15 multipv 1 score cp 18 nodes 15038956 nps 2221083 time 6771 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3e3
info depth 16 multipv 1 score cp 17 nodes 31055989 nps 2181357 time 14237 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 h2h3 c8e6 e1g1 g8f6 b1c3 d8d6 d2d3 e8c8
info depth 17 multipv 1 score cp 18 nodes 54005553 nps 2166461 time 24928 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 h2h3 c8e6 e1g1 d8d6 b1c3 e8c8 d2d3 c8b8 c1e3
info depth 18 multipv 1 score cp 15 nodes 147236235 nps 2198802 time 66962 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 h2h3 c8e6 e1g1 d8d6 b1c3 e8c8 d2d3 c8b8 c1g5 f8e7
```

```
Score of ChessDotCppDev vs vice: 369 - 56 - 75  [0.813] 500
...      ChessDotCppDev playing White: 191 - 25 - 34  [0.832] 250
...      ChessDotCppDev playing Black: 178 - 31 - 41  [0.794] 250
...      White vs Black: 222 - 203 - 75  [0.519] 500
Elo difference: 255.3 +/- 34.1, LOS: 100.0 %, DrawRatio: 15.0 %

Score of ChessDotCppDev vs mediocre: 54 - 118 - 42  [0.350] 214
...      ChessDotCppDev playing White: 33 - 57 - 17  [0.388] 107
...      ChessDotCppDev playing Black: 21 - 61 - 25  [0.313] 107
...      White vs Black: 94 - 78 - 42  [0.537] 214
Elo difference: -107.2 +/- 43.4, LOS: 0.0 %, DrawRatio: 19.6 %

Score of ChessDotCppDev vs simplex: 167 - 246 - 87  [0.421] 500
...      ChessDotCppDev playing White: 99 - 115 - 36  [0.468] 250
...      ChessDotCppDev playing Black: 68 - 131 - 51  [0.374] 250
...      White vs Black: 230 - 183 - 87  [0.547] 500
Elo difference: -55.4 +/- 28.0, LOS: 0.0 %, DrawRatio: 17.4 %
```
### 1.16
Move ordering: Countermove heuristic

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 450 nps 450000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1695 nps 1695000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 3955 nps 1977500 time 2 pv d2d4 g8f6 g1f3 d7d6 e2e3
info depth 6 multipv 1 score cp 11 nodes 8778 nps 2194500 time 4 pv d2d4 g8f6 e2e3 d7d5 f1b5 c7c6 b5d3
info depth 7 multipv 1 score cp 20 nodes 22223 nps 2222300 time 10 pv d2d4 g8f6 g1f3 d7d5 c1f4 c8f5 e2e3
info depth 8 multipv 1 score cp 12 nodes 51478 nps 2238173 time 23 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 15 nodes 125060 nps 2315925 time 54 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 f1d3 f8b4 c2c3 b4d6
info depth 10 multipv 1 score cp 16 nodes 614245 nps 2602733 time 236 pv d2d4 d7d5 g1f3 e7e6 e2e3 g8f6 f1d3 f8e7 e1g1 e8g8
info depth 11 multipv 1 score cp 22 nodes 1098822 nps 2531847 time 434 pv g1f3 e7e6 e2e3 g8f6 d2d4 f8e7 f1d3 e8g8 e1g1 d7d5 b1c3
info depth 12 multipv 1 score cp 21 nodes 1820965 nps 2464093 time 739 pv g1f3 e7e6 e2e3 g8f6 f1b5 f8e7 e1g1 e8g8 d2d4 d7d5 b1c3 c8d7
info depth 13 multipv 1 score cp 24 nodes 5902243 nps 2397336 time 2462 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 b1c3 g8f6 c1g5 c8e6 f3e5
info depth 14 multipv 1 score cp 25 nodes 9513748 nps 2347334 time 4053 pv e2e4 e7e6 b1c3 d7d5 d2d4 b8c6 f1b5 f8b4 d1g4 e8f8 b5c6 b7c6 c1g5 g8f6
info depth 15 multipv 1 score cp 18 nodes 26522710 nps 2288413 time 11590 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3e3
info depth 16 multipv 1 score cp 32 nodes 41509148 nps 2280973 time 18198 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 e1g1 f6e4 b1c3 e4f6 f1e1 d7d6 d2d4 c8g4 d4e5 c6e5
info depth 17 multipv 1 score cp 28 nodes 67968388 nps 2236390 time 30392 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 b1c3 b8c6 f1e2 f8e7 e1g1 e8g8 c1f4
info depth 18 multipv 1 score cp 34 nodes 119509625 nps 2202739 time 54255 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 d4e5 b8c6 e1g1 c8g4 d3b5 d8d7 c1e3 f8c5 e3c5 e4c5
```

```
Score of ChessDotCppDev vs vice: 382 - 60 - 58  [0.822] 500
...      ChessDotCppDev playing White: 191 - 29 - 30  [0.824] 250
...      ChessDotCppDev playing Black: 191 - 31 - 28  [0.820] 250
...      White vs Black: 222 - 220 - 58  [0.502] 500
Elo difference: 265.8 +/- 35.9, LOS: 100.0 %, DrawRatio: 11.6 %

Score of ChessDotCppDev vs mediocre: 133 - 265 - 102  [0.368] 500
...      ChessDotCppDev playing White: 66 - 137 - 47  [0.358] 250
...      ChessDotCppDev playing Black: 67 - 128 - 55  [0.378] 250
...      White vs Black: 194 - 204 - 102  [0.490] 500
Elo difference: -93.9 +/- 27.9, LOS: 0.0 %, DrawRatio: 20.4 %

Score of ChessDotCppDev vs simplex: 199 - 231 - 70  [0.468] 500
...      ChessDotCppDev playing White: 118 - 99 - 33  [0.538] 250
...      ChessDotCppDev playing Black: 81 - 132 - 37  [0.398] 250
...      White vs Black: 250 - 180 - 70  [0.570] 500
Elo difference: -22.3 +/- 28.3, LOS: 6.1 %, DrawRatio: 14.0 %
```

### 1.17
Move ordering: SEE, adjust LMR to take advantage

```
iinfo depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 444000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1671 nps 1671000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 4026 nps 2013000 time 2 pv d2d4 g8f6 g1f3 d7d6 e2e3
info depth 6 multipv 1 score cp 13 nodes 11050 nps 1841666 time 6 pv g1f3 d7d5 d2d4 e7e6 c1f4 f8b4 b1c3
info depth 7 multipv 1 score cp 20 nodes 36030 nps 2119411 time 17 pv b1c3 d7d5 e2e4 e7e6 e4d5 e6d5 d2d4
info depth 8 multipv 1 score cp 15 nodes 128121 nps 2329472 time 55 pv g1f3 d7d5 e2e3 c8g4 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 25 nodes 197782 nps 2382915 time 83 pv g1f3 d7d5 e2e3 c8g4 h2h3 g4f3 d1f3 e7e5 b1c3
info depth 10 multipv 1 score cp 24 nodes 335360 nps 2345174 time 143 pv g1f3 d7d5 e2e3 c8f5 f1e2 d8d6 e1g1 b8c6 d2d4 e8c8
info depth 11 multipv 1 score cp 21 nodes 1099099 nps 2270865 time 484 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 a2a3 b4c3 d2c3 e8g8 c1g5
info depth 12 multipv 1 score cp 24 nodes 1589099 nps 2244490 time 708 pv e2e4 e7e5 g1f3 g8f6 f1c4 b8c6 b1c3 f8b4 e1g1 e8g8 d2d3 d7d6
info depth 13 multipv 1 score cp 16 nodes 2700508 nps 2167341 time 1246 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 e8g8 d2d3 b8c6 c1f4
info depth 14 multipv 1 score cp 14 nodes 5771281 nps 2095599 time 2754 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 c8f5 c3e4 f5e4 d2d3 e4f5
info depth 15 multipv 1 score cp 18 nodes 12255348 nps 2060761 time 5947 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3e3
info depth 16 multipv 1 score cp 15 nodes 24316435 nps 2022997 time 12020 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8g4
info depth 17 multipv 1 score cp 27 nodes 44338246 nps 2002359 time 22143 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 b8c6 c1e3 f8e7 f1b5 e8g8 e1g1
info depth 18 multipv 1 score cp 23 nodes 92027969 nps 1982635 time 46417 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8g4 c1f4 b8c6
info depth 19 multipv 1 score cp 25 nodes 212034507 nps 1983818 time 106882 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 d4e5 b8c6 e1g1 c8g4 d3b5 d8d7 b1d2 f8c5 h2h3 g4f5 d2e4
```

```
Score of ChessDotCppDev vs vice: 374 - 63 - 63  [0.811] 500
...      ChessDotCppDev playing White: 195 - 25 - 30  [0.840] 250
...      ChessDotCppDev playing Black: 179 - 38 - 33  [0.782] 250
...      White vs Black: 233 - 204 - 63  [0.529] 500
Elo difference: 253.0 +/- 34.9, LOS: 100.0 %, DrawRatio: 12.6 %

Score of ChessDotCppDev vs mediocre: 122 - 275 - 103  [0.347] 500
...      ChessDotCppDev playing White: 66 - 134 - 50  [0.364] 250
...      ChessDotCppDev playing Black: 56 - 141 - 53  [0.330] 250
...      White vs Black: 207 - 190 - 103  [0.517] 500
Elo difference: -109.8 +/- 28.2, LOS: 0.0 %, DrawRatio: 20.6 %

Score of ChessDotCppDev vs simplex: 199 - 226 - 75  [0.473] 500
...      ChessDotCppDev playing White: 109 - 105 - 36  [0.508] 250
...      ChessDotCppDev playing Black: 90 - 121 - 39  [0.438] 250
...      White vs Black: 230 - 195 - 75  [0.535] 500
Elo difference: -18.8 +/- 28.1, LOS: 9.5 %, DrawRatio: 15.0 %
```
### 1.18
Move ordering: Captures history

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 444000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1671 nps 1671000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 4026 nps 2013000 time 2 pv d2d4 g8f6 g1f3 d7d6 e2e3
info depth 6 multipv 1 score cp 13 nodes 11050 nps 2210000 time 5 pv g1f3 d7d5 d2d4 e7e6 c1f4 f8b4 b1c3
info depth 7 multipv 1 score cp 20 nodes 36029 nps 2251812 time 16 pv b1c3 d7d5 e2e4 e7e6 e4d5 e6d5 d2d4
info depth 8 multipv 1 score cp 15 nodes 128034 nps 2462192 time 52 pv g1f3 d7d5 e2e3 c8g4 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 25 nodes 197715 nps 2411158 time 82 pv g1f3 d7d5 e2e3 c8g4 h2h3 g4f3 d1f3 e7e5 b1c3
info depth 10 multipv 1 score cp 24 nodes 335329 nps 2378219 time 141 pv g1f3 d7d5 e2e3 c8f5 f1e2 d8d6 e1g1 b8c6 d2d4 e8c8
info depth 11 multipv 1 score cp 21 nodes 1098676 nps 2288908 time 480 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 a2a3 b4c3 d2c3 e8g8 c1g5
info depth 12 multipv 1 score cp 24 nodes 1588386 nps 2262658 time 702 pv e2e4 e7e5 g1f3 g8f6 f1c4 b8c6 b1c3 f8b4 e1g1 e8g8 d2d3 d7d6
info depth 13 multipv 1 score cp 16 nodes 2698642 nps 2178080 time 1239 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 e8g8 d2d3 b8c6 c1f4
info depth 14 multipv 1 score cp 14 nodes 5740991 nps 2081577 time 2758 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 c8f5 c3e4 f5e4 d2d3 e4f5
info depth 15 multipv 1 score cp 18 nodes 11862170 nps 2049087 time 5789 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3e3
info depth 16 multipv 1 score cp 18 nodes 22636275 nps 2007473 time 11276 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 c8g4 c1f4 b8c6
info depth 17 multipv 1 score cp 26 nodes 42834597 nps 1990917 time 21515 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4c5 b1c3 c8g4 c1g5 g4f3 g2f3
info depth 18 multipv 1 score cp 23 nodes 89618092 nps 1973619 time 45408 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6
info depth 19 multipv 1 score cp 24 nodes 202262301 nps 1972944 time 102518 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6 d1e2
```

```
Score of ChessDotCppDev vs vice: 367 - 79 - 54  [0.788] 500
...      ChessDotCppDev playing White: 190 - 40 - 20  [0.800] 250
...      ChessDotCppDev playing Black: 177 - 39 - 34  [0.776] 250
...      White vs Black: 229 - 217 - 54  [0.512] 500
Elo difference: 228.1 +/- 34.3, LOS: 100.0 %, DrawRatio: 10.8 %

Score of ChessDotCppDev vs mediocre: 127 - 264 - 109  [0.363] 500
...      ChessDotCppDev playing White: 67 - 128 - 55  [0.378] 250
...      ChessDotCppDev playing Black: 60 - 136 - 54  [0.348] 250
...      White vs Black: 203 - 188 - 109  [0.515] 500
Elo difference: -97.7 +/- 27.7, LOS: 0.0 %, DrawRatio: 21.8 %

Score of ChessDotCppDev vs simplex: 197 - 222 - 81  [0.475] 500
...      ChessDotCppDev playing White: 121 - 91 - 38  [0.560] 250
...      ChessDotCppDev playing Black: 76 - 131 - 43  [0.390] 250
...      White vs Black: 252 - 167 - 81  [0.585] 500
Elo difference: -17.4 +/- 27.9, LOS: 11.1 %, DrawRatio: 16.2 %
Finished match
```

### 1.19
Pawn hash table

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 444000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1671 nps 1671000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 4026 nps 2013000 time 2 pv d2d4 g8f6 g1f3 d7d6 e2e3
info depth 6 multipv 1 score cp 13 nodes 11050 nps 1841666 time 6 pv g1f3 d7d5 d2d4 e7e6 c1f4 f8b4 b1c3
info depth 7 multipv 1 score cp 20 nodes 36029 nps 2119352 time 17 pv b1c3 d7d5 e2e4 e7e6 e4d5 e6d5 d2d4
info depth 8 multipv 1 score cp 15 nodes 128034 nps 2462192 time 52 pv g1f3 d7d5 e2e3 c8g4 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 25 nodes 197715 nps 2411158 time 82 pv g1f3 d7d5 e2e3 c8g4 h2h3 g4f3 d1f3 e7e5 b1c3
info depth 10 multipv 1 score cp 24 nodes 335329 nps 2378219 time 141 pv g1f3 d7d5 e2e3 c8f5 f1e2 d8d6 e1g1 b8c6 d2d4 e8c8
info depth 11 multipv 1 score cp 21 nodes 1098676 nps 2332645 time 471 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 a2a3 b4c3 d2c3 e8g8 c1g5
info depth 12 multipv 1 score cp 24 nodes 1588386 nps 2312061 time 687 pv e2e4 e7e5 g1f3 g8f6 f1c4 b8c6 b1c3 f8b4 e1g1 e8g8 d2d3 d7d6
info depth 13 multipv 1 score cp 16 nodes 2698642 nps 2232127 time 1209 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 e8g8 d2d3 b8c6 c1f4
info depth 14 multipv 1 score cp 14 nodes 5740991 nps 2163961 time 2653 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 c8f5 c3e4 f5e4 d2d3 e4f5
info depth 15 multipv 1 score cp 18 nodes 11862170 nps 2138483 time 5547 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3e3
info depth 16 multipv 1 score cp 18 nodes 22636275 nps 2107856 time 10739 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 c8g4 c1f4 b8c6
info depth 17 multipv 1 score cp 26 nodes 42834597 nps 2094703 time 20449 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4c5 b1c3 c8g4 c1g5 g4f3 g2f3
info depth 18 multipv 1 score cp 23 nodes 89618092 nps 2077137 time 43145 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6
info depth 19 multipv 1 score cp 24 nodes 202262301 nps 2072380 time 97599 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6 d1e2
```

```
Score of ChessDotCppDev vs vice: 368 - 65 - 67  [0.803] 500
...      ChessDotCppDev playing White: 190 - 28 - 32  [0.824] 250
...      ChessDotCppDev playing Black: 178 - 37 - 35  [0.782] 250
...      White vs Black: 227 - 206 - 67  [0.521] 500
Elo difference: 244.1 +/- 34.2, LOS: 100.0 %, DrawRatio: 13.4 %

Score of ChessDotCppDev vs mediocre: 129 - 257 - 114  [0.372] 500
...      ChessDotCppDev playing White: 69 - 124 - 57  [0.390] 250
...      ChessDotCppDev playing Black: 60 - 133 - 57  [0.354] 250
...      White vs Black: 202 - 184 - 114  [0.518] 500
Elo difference: -91.0 +/- 27.4, LOS: 0.0 %, DrawRatio: 22.8 %

Score of ChessDotCppDev vs simplex: 183 - 231 - 86  [0.452] 500
...      ChessDotCppDev playing White: 100 - 101 - 49  [0.498] 250
...      ChessDotCppDev playing Black: 83 - 130 - 37  [0.406] 250
...      White vs Black: 230 - 184 - 86  [0.546] 500
Elo difference: -33.5 +/- 27.8, LOS: 0.9 %, DrawRatio: 17.2 %
```

### 1.20
PGO (Profile guided optimization)

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 444000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1671 nps 835500 time 2 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 4026 nps 1342000 time 3 pv d2d4 g8f6 g1f3 d7d6 e2e3
info depth 6 multipv 1 score cp 13 nodes 11050 nps 1841666 time 6 pv g1f3 d7d5 d2d4 e7e6 c1f4 f8b4 b1c3
info depth 7 multipv 1 score cp 20 nodes 36029 nps 2401933 time 15 pv b1c3 d7d5 e2e4 e7e6 e4d5 e6d5 d2d4
info depth 8 multipv 1 score cp 15 nodes 128034 nps 2724127 time 47 pv g1f3 d7d5 e2e3 c8g4 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 25 nodes 197715 nps 2746041 time 72 pv g1f3 d7d5 e2e3 c8g4 h2h3 g4f3 d1f3 e7e5 b1c3
info depth 10 multipv 1 score cp 24 nodes 335329 nps 2726252 time 123 pv g1f3 d7d5 e2e3 c8f5 f1e2 d8d6 e1g1 b8c6 d2d4 e8c8
info depth 11 multipv 1 score cp 21 nodes 1098676 nps 2660232 time 413 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 a2a3 b4c3 d2c3 e8g8 c1g5
info depth 12 multipv 1 score cp 24 nodes 1588386 nps 2634139 time 603 pv e2e4 e7e5 g1f3 g8f6 f1c4 b8c6 b1c3 f8b4 e1g1 e8g8 d2d3 d7d6
info depth 13 multipv 1 score cp 16 nodes 2698642 nps 2550701 time 1058 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 e8g8 d2d3 b8c6 c1f4
info depth 14 multipv 1 score cp 14 nodes 5740991 nps 2471369 time 2323 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 c8f5 c3e4 f5e4 d2d3 e4f5
info depth 15 multipv 1 score cp 18 nodes 11862170 nps 2428781 time 4884 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3e3
info depth 16 multipv 1 score cp 18 nodes 22636275 nps 2394106 time 9455 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 c8g4 c1f4 b8c6
info depth 17 multipv 1 score cp 26 nodes 42834597 nps 2377982 time 18013 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4c5 b1c3 c8g4 c1g5 g4f3 g2f3
info depth 18 multipv 1 score cp 23 nodes 89618092 nps 2365779 time 37881 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6
info depth 19 multipv 1 score cp 24 nodes 202262301 nps 2354954 time 85888 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6 d1e2
info depth 20 multipv 1 score cp 24 nodes 441835029 nps 2343952 time 188500 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6 d1e2 e7h4
```

```
Score of ChessDotCppDev vs vice: 378 - 53 - 69  [0.825] 500
...      ChessDotCppDev playing White: 191 - 24 - 35  [0.834] 250
...      ChessDotCppDev playing Black: 187 - 29 - 34  [0.816] 250
...      White vs Black: 220 - 211 - 69  [0.509] 500
Elo difference: 269.4 +/- 35.2, LOS: 100.0 %, DrawRatio: 13.8 %

Score of ChessDotCppDev vs mediocre: 143 - 260 - 97  [0.383] 500
...      ChessDotCppDev playing White: 77 - 126 - 47  [0.402] 250
...      ChessDotCppDev playing Black: 66 - 134 - 50  [0.364] 250
...      White vs Black: 211 - 192 - 97  [0.519] 500
Elo difference: -82.8 +/- 28.0, LOS: 0.0 %, DrawRatio: 19.4 %

Score of ChessDotCppDev vs simplex: 202 - 207 - 91  [0.495] 500
...      ChessDotCppDev playing White: 120 - 84 - 46  [0.572] 250
...      ChessDotCppDev playing Black: 82 - 123 - 45  [0.418] 250
...      White vs Black: 243 - 166 - 91  [0.577] 500
Elo difference: -3.5 +/- 27.6, LOS: 40.2 %, DrawRatio: 18.2 %
```

### 1.21
Quiescence: Delta pruning

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 13000 time 2 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 58000 time 2 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 148000 time 3 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1655 nps 413750 time 4 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 3999 nps 799800 time 5 pv d2d4 g8f6 g1f3 d7d6 e2e3
info depth 6 multipv 1 score cp 13 nodes 10892 nps 1361500 time 8 pv g1f3 d7d5 d2d4 e7e6 c1f4 f8b4 b1c3
info depth 7 multipv 1 score cp 20 nodes 35226 nps 2201625 time 16 pv b1c3 d7d5 e2e4 e7e6 e4d5 e6d5 d2d4
info depth 8 multipv 1 score cp 15 nodes 123510 nps 2627872 time 47 pv g1f3 d7d5 e2e3 c8g4 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 25 nodes 191265 nps 2656458 time 72 pv g1f3 d7d5 e2e3 c8g4 h2h3 g4f3 d1f3 e7e5 b1c3
info depth 10 multipv 1 score cp 24 nodes 323274 nps 2649786 time 122 pv g1f3 d7d5 e2e3 c8f5 f1e2 d8d6 e1g1 b8c6 d2d4 e8c8
info depth 11 multipv 1 score cp 21 nodes 1044326 nps 2597825 time 402 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 a2a3 b4c3 d2c3 e8g8 c1g5
info depth 12 multipv 1 score cp 24 nodes 1505164 nps 2564163 time 587 pv e2e4 e7e5 g1f3 g8f6 f1c4 b8c6 b1c3 f8b4 e1g1 e8g8 d2d3 d7d6
info depth 13 multipv 1 score cp 16 nodes 2549663 nps 2473000 time 1031 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 e8g8 d2d3 b8c6 c1f4
info depth 14 multipv 1 score cp 14 nodes 5375216 nps 2384745 time 2254 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 c8f5 c3e4 f5e4 d2d3 e4f5
info depth 15 multipv 1 score cp 18 nodes 11003891 nps 2332815 time 4717 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3e3
info depth 16 multipv 1 score cp 18 nodes 20902024 nps 2290130 time 9127 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 c8g4 c1f4 b8c6
info depth 17 multipv 1 score cp 26 nodes 39408043 nps 2262229 time 17420 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4c5 b1c3 c8g4 c1g5 g4f3 g2f3
info depth 18 multipv 1 score cp 23 nodes 82166757 nps 2247388 time 36561 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6
info depth 19 multipv 1 score cp 24 nodes 184418075 nps 2222654 time 82972 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6 d1e2
info depth 20 multipv 1 score cp 24 nodes 397447644 nps 2196462 time 180949 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6 c1f4 b8c6 d1e2 e7h4
```

```
Score of ChessDotCppDev vs vice: 361 - 59 - 80  [0.802] 500
...      ChessDotCppDev playing White: 193 - 23 - 34  [0.840] 250
...      ChessDotCppDev playing Black: 168 - 36 - 46  [0.764] 250
...      White vs Black: 229 - 191 - 80  [0.538] 500
Elo difference: 243.0 +/- 33.2, LOS: 100.0 %, DrawRatio: 16.0 %

Score of ChessDotCppDev vs mediocre: 155 - 233 - 112  [0.422] 500
...      ChessDotCppDev playing White: 92 - 99 - 59  [0.486] 250
...      ChessDotCppDev playing Black: 63 - 134 - 53  [0.358] 250
...      White vs Black: 226 - 162 - 112  [0.564] 500
Elo difference: -54.6 +/- 27.1, LOS: 0.0 %, DrawRatio: 22.4 %

Score of ChessDotCppDev vs simplex: 217 - 198 - 85  [0.519] 500
...      ChessDotCppDev playing White: 128 - 85 - 37  [0.586] 250
...      ChessDotCppDev playing Black: 89 - 113 - 48  [0.452] 250
...      White vs Black: 241 - 174 - 85  [0.567] 500
Elo difference: 13.2 +/- 27.8, LOS: 82.5 %, DrawRatio: 17.0 %
```

### 1.22
Quiescence: SEE pruning

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 438 nps 438000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 1519 nps 759500 time 2 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 3644 nps 1214666 time 3 pv d2d4 g8f6 g1f3 d7d6 e2e3
info depth 6 multipv 1 score cp 13 nodes 9752 nps 1950400 time 5 pv g1f3 d7d5 d2d4 e7e6 c1f4 f8b4 b1c3
info depth 7 multipv 1 score cp 20 nodes 29789 nps 2291461 time 13 pv b1c3 d7d5 e2e4 e7e6 e4d5 e6d5 d2d4
info depth 8 multipv 1 score cp 15 nodes 106473 nps 2596902 time 41 pv g1f3 d7d5 e2e3 c8g4 d2d4 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 25 nodes 166696 nps 2645968 time 63 pv g1f3 d7d5 e2e3 c8g4 h2h3 g4f3 d1f3 e7e5 b1c3
info depth 10 multipv 1 score cp 24 nodes 348430 nps 2619774 time 133 pv g1f3 d7d5 e2e3 c8f5 f1e2 d8d6 e1g1 b8c6 d2d4 e8c8
info depth 11 multipv 1 score cp 16 nodes 1095407 nps 2626875 time 417 pv g1f3 d7d5 e2e3 e7e6 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 b1c3
info depth 12 multipv 1 score cp 16 nodes 2008784 nps 2514122 time 799 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 22 nodes 2837213 nps 2469288 time 1149 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 e8g8 d2d3 b4c3 b2c3
info depth 14 multipv 1 score cp 15 nodes 5473610 nps 2332172 time 2347 pv e2e4 e7e5 f1c4 g8f6 b1c3 b8c6 g1f3 f6e4 e1g1 e4f6 d2d4 d7d5 d4e5 d5c4
info depth 15 multipv 1 score cp 8 nodes 12182447 nps 2241480 time 5435 pv e2e4 e7e5 f1c4 g8f6 b1c3 b8c6 g1f3 f8b4 e1g1 e8g8 d1e2 d7d6 d2d3 b4c3 b2c3
info depth 16 multipv 1 score cp 10 nodes 22742692 nps 2211893 time 10282 pv e2e4 e7e5 f1c4 g8f6 b1c3 b8c6 g1f3 f8c5 e1g1 d7d6 d2d3 e8g8 c1d2 c8d7 d1e2 d8e7
info depth 17 multipv 1 score cp 24 nodes 42618114 nps 2183640 time 19517 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 e1g1 e8g8 a2a3 b4c3 d2c3 a7a6 b5c6 d7c6 c1e3
info depth 18 multipv 1 score cp 22 nodes 74177461 nps 2169756 time 34187 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 a2a3 b4c3 d2c3 f6e4 e1g1 d7d6 d1d5 c8f5 f1e1 a7a6
info depth 19 multipv 1 score cp 30 nodes 139454640 nps 2157371 time 64641 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 a2a3 b4c3 d2c3 f6e4 e1g1 e8g8 f1e1 d7d5 b5c6 b7c6 f3e5
info depth 20 multipv 1 score cp 18 nodes 296956667 nps 2152858 time 137936 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 a2a3 b4c3 d2c3 f6e4 b5c6 b7c6 f3e5 d8f6 f2f4 d7d5 d1h5 c8a6
```

```
Score of ChessDotCppDev vs vice: 364 - 57 - 79  [0.807] 500
...      ChessDotCppDev playing White: 191 - 26 - 33  [0.830] 250
...      ChessDotCppDev playing Black: 173 - 31 - 46  [0.784] 250
...      White vs Black: 222 - 199 - 79  [0.523] 500
Elo difference: 248.5 +/- 33.5, LOS: 100.0 %, DrawRatio: 15.8 %

Score of ChessDotCppDev vs mediocre: 154 - 234 - 112  [0.420] 500
...      ChessDotCppDev playing White: 87 - 104 - 59  [0.466] 250
...      ChessDotCppDev playing Black: 67 - 130 - 53  [0.374] 250
...      White vs Black: 217 - 171 - 112  [0.546] 500
Elo difference: -56.1 +/- 27.1, LOS: 0.0 %, DrawRatio: 22.4 %

Score of ChessDotCppDev vs simplex: 221 - 209 - 70  [0.512] 500
...      ChessDotCppDev playing White: 136 - 87 - 27  [0.598] 250
...      ChessDotCppDev playing Black: 85 - 122 - 43  [0.426] 250
...      White vs Black: 258 - 172 - 70  [0.586] 500
Elo difference: 8.3 +/- 28.3, LOS: 71.9 %, DrawRatio: 14.0 %
```

### 1.23

Better LMR based on depth, move counts, PV, and score improving

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 679 nps 679000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 2983 nps 2983000 time 1 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 9711 nps 3237000 time 3 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23090 nps 2886250 time 8 pv d2d4 d7d5 g1f3 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 21 nodes 36837 nps 2631214 time 14 pv d2d4 d7d5 c1f4 g8f6 e2e3 c8f5 f1b5 b8c6
info depth 8 multipv 1 score cp 16 nodes 68565 nps 2539444 time 27 pv d2d4 d7d5 c1f4 c8f5 e2e3 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 34 nodes 288750 nps 2510869 time 115 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 34 nodes 453684 nps 2465673 time 184 pv g1f3 b8c6 d2d4 e7e6 e2e3 f8e7 f1d3 g8f6 e1g1 e8g8
info depth 11 multipv 1 score cp 16 nodes 850684 nps 2396292 time 355 pv d2d4 d7d5 c1f4 c8f5 e2e3 e7e6 f1b5 c7c6 b5d3 f8d6 f4d6 d8d6
info depth 12 multipv 1 score cp 16 nodes 3211142 nps 2398164 time 1339 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 22 nodes 4058969 nps 2389034 time 1699 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 e8g8 d2d3 b4c3 b2c3
info depth 14 multipv 1 score cp 23 nodes 5493592 nps 2315040 time 2373 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 d2d4 d7d6 e5f3 f6e4 f1e2 b8c6 e1g1 c8g4
info depth 15 multipv 1 score cp 26 nodes 7187767 nps 2269582 time 3167 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 d2d4 d7d6 e5f3 e7e4 c1e3 e4e7 b1c3 b8c6 d4d5 c6b4
info depth 16 multipv 1 score cp 27 nodes 11830028 nps 2205037 time 5365 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 d4e5 f8c5 e1g1 e8g8 d1e2 c8f5 b1d2 e4d2
info depth 17 multipv 1 score cp 27 nodes 19755994 nps 2161250 time 9141 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 d4e5 f8c5 e1g1 e8g8 d1e2 c8f5 b1d2 e4d2 c1d2
info depth 18 multipv 1 score cp 16 nodes 37559608 nps 2119018 time 17725 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 e1g1 e8g8 d2d3 d7d6 c1g5 h7h6 g5f6 d8f6 c3d5 f6d8
info depth 19 multipv 1 score cp 27 nodes 66954316 nps 2086779 time 32085 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 b8c6 c1f4 c8f5 e1c1 e8c8 c1b1
info depth 20 multipv 1 score cp 26 nodes 110229089 nps 2074158 time 53144 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 b8c6 g5f6 g7f6 b1c3 h8g8 e1c1 e7e2
info depth 21 multipv 1 score cp 17 nodes 233656846 nps 2092405 time 111669 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 e1g1 e8g8 b5c6 d7c6 f3e5 f8e8 d2d4 c6c5 c1e3 b4c3 b2c3 c5d4 d1d4
```

```
Score of ChessDotCppDev vs vice: 396 - 43 - 61  [0.853] 500
...      ChessDotCppDev playing White: 206 - 16 - 28  [0.880] 250
...      ChessDotCppDev playing Black: 190 - 27 - 33  [0.826] 250
...      White vs Black: 233 - 206 - 61  [0.527] 500
Elo difference: 305.5 +/- 37.7, LOS: 100.0 %, DrawRatio: 12.2 %

Score of ChessDotCppDev vs mediocre: 157 - 220 - 123  [0.437] 500
...      ChessDotCppDev playing White: 87 - 97 - 66  [0.480] 250
...      ChessDotCppDev playing Black: 70 - 123 - 57  [0.394] 250
...      White vs Black: 210 - 167 - 123  [0.543] 500
Elo difference: -44.0 +/- 26.6, LOS: 0.1 %, DrawRatio: 24.6 %

Score of ChessDotCppDev vs simplex: 207 - 205 - 88  [0.502] 500
...      ChessDotCppDev playing White: 128 - 81 - 41  [0.594] 250
...      ChessDotCppDev playing Black: 79 - 124 - 47  [0.410] 250
...      White vs Black: 252 - 160 - 88  [0.592] 500
Elo difference: 1.4 +/- 27.7, LOS: 53.9 %, DrawRatio: 17.6 %
```

### 1.24

Slight performance upgrades, remove dependencies on compiler specifics

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 679 nps 679000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 2983 nps 2983000 time 1 pv d2d4 g8f6 g1f3 d7d6
info depth 5 multipv 1 score cp 30 nodes 9711 nps 2427750 time 4 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23090 nps 2565555 time 9 pv d2d4 d7d5 g1f3 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 21 nodes 36837 nps 2631214 time 14 pv d2d4 d7d5 c1f4 g8f6 e2e3 c8f5 f1b5 b8c6
info depth 8 multipv 1 score cp 16 nodes 68565 nps 2539444 time 27 pv d2d4 d7d5 c1f4 c8f5 e2e3 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 34 nodes 288750 nps 2510869 time 115 pv g1f3 d7d5 e2e3 c8f5 f1e2 b8c6 d2d4 c6b4 e2b5 c7c6
info depth 10 multipv 1 score cp 34 nodes 453684 nps 2465673 time 184 pv g1f3 b8c6 d2d4 e7e6 e2e3 f8e7 f1d3 g8f6 e1g1 e8g8
info depth 11 multipv 1 score cp 16 nodes 850684 nps 2403062 time 354 pv d2d4 d7d5 c1f4 c8f5 e2e3 e7e6 f1b5 c7c6 b5d3 f8d6 f4d6 d8d6
info depth 12 multipv 1 score cp 16 nodes 3211142 nps 2366353 time 1357 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 22 nodes 4058969 nps 2366745 time 1715 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 e8g8 d2d3 b4c3 b2c3
info depth 14 multipv 1 score cp 23 nodes 5493592 nps 2314065 time 2374 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 d2d4 d7d6 e5f3 f6e4 f1e2 b8c6 e1g1 c8g4
info depth 15 multipv 1 score cp 26 nodes 7187767 nps 2271016 time 3165 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 d2d4 d7d6 e5f3 e7e4 c1e3 e4e7 b1c3 b8c6 d4d5 c6b4
info depth 16 multipv 1 score cp 27 nodes 11830028 nps 2208743 time 5356 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 d4e5 f8c5 e1g1 e8g8 d1e2 c8f5 b1d2 e4d2
info depth 17 multipv 1 score cp 27 nodes 19755994 nps 2166464 time 9119 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 d4e5 f8c5 e1g1 e8g8 d1e2 c8f5 b1d2 e4d2 c1d2
info depth 18 multipv 1 score cp 16 nodes 37559608 nps 2125253 time 17673 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 e1g1 e8g8 d2d3 d7d6 c1g5 h7h6 g5f6 d8f6 c3d5 f6d8
info depth 19 multipv 1 score cp 27 nodes 66954316 nps 2102374 time 31847 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 b8c6 c1f4 c8f5 e1c1 e8c8 c1b1
info depth 20 multipv 1 score cp 26 nodes 110229089 nps 2085381 time 52858 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 b8c6 g5f6 g7f6 b1c3 h8g8 e1c1 e7e2
```

```
Score of ChessDotCppDev vs vice: 392 - 45 - 63  [0.847] 500
...      ChessDotCppDev playing White: 204 - 20 - 26  [0.868] 250
...      ChessDotCppDev playing Black: 188 - 25 - 37  [0.826] 250
...      White vs Black: 229 - 208 - 63  [0.521] 500
Elo difference: 297.3 +/- 37.1, LOS: 100.0 %, DrawRatio: 12.6 %
```
### 1.25

History gravity, adjust LMR to take advantage

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 705 nps 705000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3180 nps 3180000 time 1 pv d2d4 g8f6 e2e3 d7d5
info depth 5 multipv 1 score cp 30 nodes 10038 nps 2509500 time 4 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23680 nps 2631111 time 9 pv d2d4 d7d5 g1f3 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 21 nodes 41623 nps 2448411 time 17 pv d2d4 d7d5 c1f4 g8f6 b1c3 e7e6 e2e3
info depth 8 multipv 1 score cp 16 nodes 81433 nps 2262027 time 36 pv d2d4 d7d5 c1f4 c8f5 e2e3 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 31 nodes 375697 nps 2392974 time 157 pv g1f3 e7e6 e2e3 g8f6 b1c3 f8e7 f1b5 e8g8 e1g1
info depth 10 multipv 1 score cp 21 nodes 776389 nps 2374278 time 327 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 f8b4 c1g5 d7d6
info depth 11 multipv 1 score cp 33 nodes 1143514 nps 2319501 time 493 pv e2e4 e7e5 f1c4 g8f6 g1f3 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 1864896 nps 2282614 time 817 pv e2e4 e7e5 f1c4 g8f6 b1c3 f8b4 g1f3 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 28 nodes 2849356 nps 2233037 time 1276 pv e2e4 e7e5 f1c4 g8f6 d2d3 b8c6 g1f3 f8c5 e1g1 e8g8 b1c3 d7d6 c1g5
info depth 14 multipv 1 score cp 10 nodes 5486549 nps 2158359 time 2542 pv e2e4 e7e5 f1c4 g8f6 d2d3 b8c6 g1f3 f8c5 e1g1 e8g8 b1c3 d7d6 c1g5 c8g4
info depth 15 multipv 1 score cp 26 nodes 12127424 nps 2138498 time 5671 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 d2d4 d7d6 e5f3 e7e4 c1e3 e4e7 b1c3 b8c6 d4d5 c6b4
info depth 16 multipv 1 score cp 20 nodes 24733236 nps 2151464 time 11496 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d8e7 f1e2
info depth 17 multipv 1 score cp 28 nodes 37962802 nps 2124981 time 17865 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 b1c3 f8e7 f1e2 e8g8 e1g1 c8f5 c1f4
info depth 18 multipv 1 score cp 16 nodes 74982608 nps 2120608 time 35359 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 e1g1 e8g8 d2d3 d7d6 c1g5 h7h6 g5f6 d8f6 c3d5 f6d8
info depth 19 multipv 1 score cp 27 nodes 132186166 nps 2099059 time 62974 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 b8c6 c1f4 c8f5 e1c1 e8c8 c1b1
info depth 20 multipv 1 score cp 21 nodes 257910280 nps 2081566 time 123902 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3c3 e8c8 d2d3 d8d4 c1e3 f8b4
```

```
Score of ChessDotCppDev vs vice: 420 - 26 - 54  [0.894] 500
...      ChessDotCppDev playing White: 210 - 13 - 27  [0.894] 250
...      ChessDotCppDev playing Black: 210 - 13 - 27  [0.894] 250
...      White vs Black: 223 - 223 - 54  [0.500] 500
Elo difference: 370.4 +/- 42.4, LOS: 100.0 %, DrawRatio: 10.8 %

Score of ChessDotCppDev vs mediocre: 214 - 151 - 135  [0.563] 500
...      ChessDotCppDev playing White: 119 - 67 - 64  [0.604] 250
...      ChessDotCppDev playing Black: 95 - 84 - 71  [0.522] 250
...      White vs Black: 203 - 162 - 135  [0.541] 500
Elo difference: 44.0 +/- 26.2, LOS: 100.0 %, DrawRatio: 27.0 %

Score of ChessDotCppDev vs simplex: 290 - 143 - 67  [0.647] 500
...      ChessDotCppDev playing White: 163 - 56 - 31  [0.714] 250
...      ChessDotCppDev playing Black: 127 - 87 - 36  [0.580] 250
...      White vs Black: 250 - 183 - 67  [0.567] 500
Elo difference: 105.3 +/- 29.5, LOS: 100.0 %, DrawRatio: 13.4 %

Score of ChessDotCppDev vs cosette5: 196 - 203 - 101  [0.493] 500
...      ChessDotCppDev playing White: 108 - 102 - 40  [0.512] 250
...      ChessDotCppDev playing Black: 88 - 101 - 61  [0.474] 250
...      White vs Black: 209 - 190 - 101  [0.519] 500
Elo difference: -4.9 +/- 27.2, LOS: 36.3 %, DrawRatio: 20.2 %
```

### 1.26

History aging

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 705 nps 705000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3180 nps 1590000 time 2 pv d2d4 g8f6 e2e3 d7d5
info depth 5 multipv 1 score cp 30 nodes 10038 nps 2007600 time 5 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23680 nps 2152727 time 11 pv d2d4 d7d5 g1f3 g8f6 c1f4 c8f5
info depth 7 multipv 1 score cp 21 nodes 41623 nps 2190684 time 19 pv d2d4 d7d5 c1f4 g8f6 b1c3 e7e6 e2e3
info depth 8 multipv 1 score cp 16 nodes 81433 nps 2200891 time 37 pv d2d4 d7d5 c1f4 c8f5 e2e3 e7e6 f1b5 c7c6 b5d3
info depth 9 multipv 1 score cp 31 nodes 375697 nps 2333521 time 161 pv g1f3 e7e6 e2e3 g8f6 b1c3 f8e7 f1b5 e8g8 e1g1
info depth 10 multipv 1 score cp 21 nodes 776389 nps 2331498 time 333 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 f8b4 c1g5 d7d6
info depth 11 multipv 1 score cp 33 nodes 1143514 nps 2296212 time 498 pv e2e4 e7e5 f1c4 g8f6 g1f3 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 16 nodes 1864896 nps 2274263 time 820 pv e2e4 e7e5 f1c4 g8f6 b1c3 f8b4 g1f3 d7d6 e1g1 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 28 nodes 2849356 nps 2229543 time 1278 pv e2e4 e7e5 f1c4 g8f6 d2d3 b8c6 g1f3 f8c5 e1g1 e8g8 b1c3 d7d6 c1g5
info depth 14 multipv 1 score cp 10 nodes 5486549 nps 2155814 time 2545 pv e2e4 e7e5 f1c4 g8f6 d2d3 b8c6 g1f3 f8c5 e1g1 e8g8 b1c3 d7d6 c1g5 c8g4
info depth 15 multipv 1 score cp 26 nodes 12127424 nps 2136614 time 5676 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 d2d4 d7d6 e5f3 e7e4 c1e3 e4e7 b1c3 b8c6 d4d5 c6b4
info depth 16 multipv 1 score cp 20 nodes 24733236 nps 2141962 time 11547 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d8e7 f1e2
info depth 17 multipv 1 score cp 28 nodes 37962802 nps 2117396 time 17929 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 b1c3 f8e7 f1e2 e8g8 e1g1 c8f5 c1f4
info depth 18 multipv 1 score cp 16 nodes 74982608 nps 2107970 time 35571 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 e1g1 e8g8 d2d3 d7d6 c1g5 h7h6 g5f6 d8f6 c3d5 f6d8
info depth 19 multipv 1 score cp 27 nodes 132186166 nps 2086074 time 63366 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 b8c6 c1f4 c8f5 e1c1 e8c8 c1b1
info depth 20 multipv 1 score cp 21 nodes 257910280 nps 2059328 time 125240 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3c3 e8c8 d2d3 d8d4 c1e3 f8b4
```

```
Score of ChessDotCppDev vs vice: 426 - 21 - 53  [0.905] 500
...      ChessDotCppDev playing White: 219 - 7 - 24  [0.924] 250
...      ChessDotCppDev playing Black: 207 - 14 - 29  [0.886] 250
...      White vs Black: 233 - 214 - 53  [0.519] 500
Elo difference: 391.6 +/- 43.8, LOS: 100.0 %, DrawRatio: 10.6 %

Score of ChessDotCppDev vs mediocre: 238 - 142 - 120  [0.596] 500
...      ChessDotCppDev playing White: 123 - 65 - 62  [0.616] 250
...      ChessDotCppDev playing Black: 115 - 77 - 58  [0.576] 250
...      White vs Black: 200 - 180 - 120  [0.520] 500
Elo difference: 67.5 +/- 26.9, LOS: 100.0 %, DrawRatio: 24.0 %

Score of ChessDotCppDev vs simplex: 266 - 153 - 81  [0.613] 500
...      ChessDotCppDev playing White: 149 - 67 - 34  [0.664] 250
...      ChessDotCppDev playing Black: 117 - 86 - 47  [0.562] 250
...      White vs Black: 235 - 184 - 81  [0.551] 500
Elo difference: 79.9 +/- 28.5, LOS: 100.0 %, DrawRatio: 16.2 %

Score of ChessDotCppDev vs cosette5: 200 - 205 - 95  [0.495] 500
...      ChessDotCppDev playing White: 107 - 93 - 50  [0.528] 250
...      ChessDotCppDev playing Black: 93 - 112 - 45  [0.462] 250
...      White vs Black: 219 - 186 - 95  [0.533] 500
Elo difference: -3.5 +/- 27.4, LOS: 40.2 %, DrawRatio: 19.0 %

Score of ChessDotCppDev vs wyldchess: 88 - 307 - 105  [0.281] 500
...      ChessDotCppDev playing White: 56 - 141 - 53  [0.330] 250
...      ChessDotCppDev playing Black: 32 - 166 - 52  [0.232] 250
...      White vs Black: 222 - 173 - 105  [0.549] 500
Elo difference: -163.2 +/- 29.2, LOS: 0.0 %, DrawRatio: 21.0 %
```

Fixed "cheating" issue with remembered state:
```
Score of ChessDotCppDev vs mediocre: 230 - 145 - 125  [0.585] 500
...      ChessDotCppDev playing White: 126 - 71 - 53  [0.610] 250
...      ChessDotCppDev playing Black: 104 - 74 - 72  [0.560] 250
...      White vs Black: 200 - 175 - 125  [0.525] 500
Elo difference: 59.6 +/- 26.6, LOS: 100.0 %, DrawRatio: 25.0 %
```

### 1.27
Make pawn control act the same for all pieces in eval

```
Score of ChessDotCppDev vs ChessDotCpp126: 158 - 133 - 209  [0.525] 500
...      ChessDotCppDev playing White: 82 - 59 - 109  [0.546] 250
...      ChessDotCppDev playing Black: 76 - 74 - 100  [0.504] 250
...      White vs Black: 156 - 135 - 209  [0.521] 500
Elo difference: 17.4 +/- 23.2, LOS: 92.9 %, DrawRatio: 41.8 %

Score of ChessDotCppDev vs mediocre: 230 - 137 - 133  [0.593] 500
...      ChessDotCppDev playing White: 134 - 51 - 65  [0.666] 250
...      ChessDotCppDev playing Black: 96 - 86 - 68  [0.520] 250
...      White vs Black: 220 - 147 - 133  [0.573] 500
Elo difference: 65.4 +/- 26.4, LOS: 100.0 %, DrawRatio: 26.6 %
```

### 1.28
Time control: reduce allocated time if PV move doesn't change on iterative deepening

```
Score of ChessDotCppDev vs ChessDotCpp126: 194 - 92 - 214  [0.602] 500
...      ChessDotCppDev playing White: 116 - 42 - 92  [0.648] 250
...      ChessDotCppDev playing Black: 78 - 50 - 122  [0.556] 250
...      White vs Black: 166 - 120 - 214  [0.546] 500
Elo difference: 71.9 +/- 23.1, LOS: 100.0 %, DrawRatio: 42.8 %

Score of ChessDotCppDev vs mediocre: 249 - 107 - 144  [0.642] 500
...      ChessDotCppDev playing White: 121 - 52 - 77  [0.638] 250
...      ChessDotCppDev playing Black: 128 - 55 - 67  [0.646] 250
...      White vs Black: 176 - 180 - 144  [0.496] 500
Elo difference: 101.5 +/- 26.3, LOS: 100.0 %, DrawRatio: 28.8 %
```

On AVX2 build:
```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 705 nps 705000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3183 nps 3183000 time 1 pv d2d4 g8f6 e2e3 d7d5
info depth 5 multipv 1 score cp 30 nodes 10300 nps 2575000 time 4 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23258 nps 2584222 time 9 pv d2d4 g8f6 e2e3 e7e6 g1f3 d7d5
info depth 7 multipv 1 score cp 21 nodes 43063 nps 2392388 time 18 pv d2d4 g8f6 e2e3 d7d5 g1f3 c8f5 f1b5 b8c6
info depth 8 multipv 1 score cp 16 nodes 135115 nps 2329568 time 58 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 22 nodes 268821 nps 2358078 time 114 pv e2e4 e7e6 d2d3 d7d5 g1f3 d5e4 d3e4 f8b4 c2c3 d8d1 e1d1
info depth 10 multipv 1 score cp 24 nodes 415128 nps 2345355 time 177 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 b8c6 d1e2 c8e6 c1g5
info depth 11 multipv 1 score cp 25 nodes 724065 nps 2291344 time 316 pv e2e4 e7e6 g1f3 d7d5 e4e5 c8d7 d2d4 f8b4 c2c3 b4a5 d1b3 a5b6
info depth 12 multipv 1 score cp 29 nodes 1558506 nps 2333092 time 668 pv e2e4 e7e6 g1f3 d7d5 e4e5 f8b4 a2a3 b4e7 d2d4 e8f8 b1c3 c8d7
info depth 13 multipv 1 score cp 22 nodes 3718051 nps 2233063 time 1665 pv e2e4 e7e5 f1c4 g8f6 b1c3 f8b4 g1f3 e8g8 e1g1 d7d6 d2d3 b4c3 b2c3
info depth 14 multipv 1 score cp 11 nodes 6739971 nps 2177696 time 3095 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 e2e7 f8e7 b1c3
info depth 15 multipv 1 score cp 28 nodes 10007168 nps 2151616 time 4651 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 e7e2 f1e2 b8c6
info depth 16 multipv 1 score cp 21 nodes 16749355 nps 2131774 time 7857 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d8e7 f1e2 b8c6 e1g1 c8f5 d4d5 c6e5
info depth 17 multipv 1 score cp 21 nodes 31966613 nps 2126005 time 15036 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 d2d3 c8g4 h2h3 g4f3 d1f3 d8f6 b1d2 e8c8 e1g1
info depth 18 multipv 1 score cp 28 nodes 90771368 nps 2221575 time 40859 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 f3g5 d7d5 e4d5 f6d5 g5f7 e8f7 d1f3 f7e6 b1c3 c6b4 e1g1 d8f6 f3e4
info depth 19 multipv 1 score cp 28 nodes 149312027 nps 2196508 time 67977 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 c8e6 f3d4 b8c6 d4c6 b7c6 b1c3
info depth 20 multipv 1 score cp 23 nodes 288935381 nps 2175275 time 132827 pv e2e4 e7e5 g1f3 b8c6 f1c4 f8c5 e1g1 g8f6 d2d3 e8g8 b1c3 d7d6 c3a4 c6a5 c4b5 c7c6 a4c5 c6b5 c5b3 a5b3
```

```
Score of ChessDotCpp vs vice: 459 - 15 - 26  [0.944] 500
...      ChessDotCpp playing White: 234 - 5 - 11  [0.958] 250
...      ChessDotCpp playing Black: 225 - 10 - 15  [0.930] 250
...      White vs Black: 244 - 230 - 26  [0.514] 500
Elo difference: 490.7 +/- 59.3, LOS: 100.0 %, DrawRatio: 5.2 %

Score of ChessDotCpp vs mediocre: 268 - 114 - 118  [0.654] 500
...      ChessDotCpp playing White: 143 - 61 - 46  [0.664] 250
...      ChessDotCpp playing Black: 125 - 53 - 72  [0.644] 250
...      White vs Black: 196 - 186 - 118  [0.510] 500
Elo difference: 110.6 +/- 27.6, LOS: 100.0 %, DrawRatio: 23.6 %

Score of ChessDotCpp vs simplex: 325 - 94 - 81  [0.731] 500
...      ChessDotCpp playing White: 185 - 31 - 34  [0.808] 250
...      ChessDotCpp playing Black: 140 - 63 - 47  [0.654] 250
...      White vs Black: 248 - 171 - 81  [0.577] 500
Elo difference: 173.7 +/- 30.7, LOS: 100.0 %, DrawRatio: 16.2 %

Score of ChessDotCpp vs cosette5: 222 - 165 - 113  [0.557] 500
...      ChessDotCpp playing White: 116 - 74 - 60  [0.584] 250
...      ChessDotCpp playing Black: 106 - 91 - 53  [0.530] 250
...      White vs Black: 207 - 180 - 113  [0.527] 500
Elo difference: 39.8 +/- 26.9, LOS: 99.8 %, DrawRatio: 22.6 %

Score of ChessDotCpp vs wyldchess: 95 - 275 - 130  [0.320] 500
...      ChessDotCpp playing White: 58 - 120 - 72  [0.376] 250
...      ChessDotCpp playing Black: 37 - 155 - 58  [0.264] 250
...      White vs Black: 213 - 157 - 130  [0.556] 500
Elo difference: -130.9 +/- 27.4, LOS: 0.0 %, DrawRatio: 26.0 %
```
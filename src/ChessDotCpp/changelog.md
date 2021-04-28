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


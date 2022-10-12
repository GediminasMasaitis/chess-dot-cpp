Engines tested against:

| Name | Version | ELO |
| --- | --- | --- |
| TSCP | 1.81 | 1723 |
| Vice | 1.0 | 2044 |
| mediocre | 0.5 | 2319 |
| simplex | 0.9.8 | 2407 |
| cosette | 5.0 | 2493 |
| wyldchess | 1.51 | 2629 |
| Supernova | 2.4 | 2698 |
| GreKo | 2021.06 | 2767 |
| glaurung | 2.2 | 2802 |
| Zurichess | Neuchatel | 2904 |
| Texel | 1.07 | 3113 |
| Weiss | 2.0 | 3305 |
| Seer | 2.5 | 3489 |


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

### 1.29

Mate distance pruning

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 705 nps 705000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3183 nps 3183000 time 1 pv d2d4 g8f6 e2e3 d7d5
info depth 5 multipv 1 score cp 30 nodes 10300 nps 2060000 time 5 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23258 nps 2325800 time 10 pv d2d4 g8f6 e2e3 e7e6 g1f3 d7d5
info depth 7 multipv 1 score cp 21 nodes 43042 nps 2265368 time 19 pv d2d4 g8f6 e2e3 d7d5 g1f3 c8f5 f1b5 b8c6
info depth 8 multipv 1 score cp 16 nodes 135064 nps 2369543 time 57 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 22 nodes 268638 nps 2398553 time 112 pv e2e4 e7e6 d2d3 d7d5 g1f3 d5e4 d3e4 f8b4 c2c3 d8d1 e1d1
info depth 10 multipv 1 score cp 24 nodes 414821 nps 2343621 time 177 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 b8c6 d1e2 c8e6 c1g5
info depth 11 multipv 1 score cp 25 nodes 714553 nps 2319977 time 308 pv e2e4 e7e6 g1f3 d7d5 e4e5 c8d7 d2d4 f8b4 c2c3 b4a5 d1b3 a5b6
info depth 12 multipv 1 score cp 29 nodes 1461617 nps 2312685 time 632 pv e2e4 e7e6 g1f3 d7d5 e4e5 f8b4 a2a3 b4e7 d2d4 e8f8 b1c3 c8d7
info depth 13 multipv 1 score cp 26 nodes 3445878 nps 2289619 time 1505 pv e2e4 e7e6 g1f3 d7d5 e4e5 d5d4 f1b5 c7c6 b5c4 f8c5 e1g1 g8e7 d2d3 e8g8
info depth 14 multipv 1 score cp 26 nodes 6395676 nps 2229235 time 2869 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 f1b5 c7c6 b5e2 c8g4 e1g1 b8d7 d2d4
info depth 15 multipv 1 score cp 19 nodes 11054518 nps 2188146 time 5052 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 h2h3 c8e6 b1c3 d8f6 d2d4 e5d4 d1d4
info depth 16 multipv 1 score cp 24 nodes 19020449 nps 2159206 time 8809 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 h2h3 c8e6 e1g1 g8f6 b1c3 d8d6 d2d4 e8c8
info depth 17 multipv 1 score cp 22 nodes 31389862 nps 2122514 time 14789 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 h2h3 c8e6 e1g1 g8f6 b1c3 f8b4 d2d3 b4c3 b2c3
info depth 18 multipv 1 score cp 27 nodes 63356059 nps 2098994 time 30184 pv e2e4 e7e5 f1c4 g8f6 d2d3 c7c6 d1e2 a7a5 d3d4 d7d6 g1f3 b7b5 c4d3 e5d4 f3d4 f8e7 e1g1 e8g8
info depth 19 multipv 1 score cp 23 nodes 144896995 nps 2167559 time 66848 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 e1g1 f8c5 d2d3 d7d6 b1c3 e8g8 c3a4 c5b6 a4b6 a7b6 c1g5 c8e6 c4e6
info depth 20 multipv 1 score cp 18 nodes 339904125 nps 2234153 time 152140 pv e2e4 e7e5 f1c4 g8f6 d2d3 b8c6 b1c3 c6a5 c1g5 f8b4 g1e2 b4e7 e1g1 e8g8 c4b5 c7c6 b5a4 d7d5 e4d5 f6d5
```

```
Score of ChessDotCpp vs mediocre: 548 - 235 - 217  [0.656] 1000
...      ChessDotCpp playing White: 291 - 97 - 112  [0.694] 500
...      ChessDotCpp playing Black: 257 - 138 - 105  [0.619] 500
...      White vs Black: 429 - 354 - 217  [0.537] 1000
Elo difference: 112.5 +/- 19.8, LOS: 100.0 %, DrawRatio: 21.7 %

Score of ChessDotCpp vs simplex: 322 - 102 - 76  [0.720] 500
...      ChessDotCpp playing White: 176 - 36 - 38  [0.780] 250
...      ChessDotCpp playing Black: 146 - 66 - 38  [0.660] 250
...      White vs Black: 242 - 182 - 76  [0.560] 500
Elo difference: 164.1 +/- 30.6, LOS: 100.0 %, DrawRatio: 15.2 %

Score of ChessDotCpp vs cosette5: 217 - 179 - 104  [0.538] 500
...      ChessDotCpp playing White: 114 - 87 - 49  [0.554] 250
...      ChessDotCpp playing Black: 103 - 92 - 55  [0.522] 250
...      White vs Black: 206 - 190 - 104  [0.516] 500
Elo difference: 26.5 +/- 27.2, LOS: 97.2 %, DrawRatio: 20.8 %

Score of ChessDotCpp vs wyldchess: 114 - 257 - 129  [0.357] 500
...      ChessDotCpp playing White: 71 - 115 - 64  [0.412] 250
...      ChessDotCpp playing Black: 43 - 142 - 65  [0.302] 250
...      White vs Black: 213 - 158 - 129  [0.555] 500
Elo difference: -102.2 +/- 27.0, LOS: 0.0 %, DrawRatio: 25.8 %
```

### 1.30

Reduce TT entry size

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 705 nps 705000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3183 nps 3183000 time 1 pv d2d4 g8f6 e2e3 d7d5
info depth 5 multipv 1 score cp 30 nodes 10300 nps 2060000 time 5 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23237 nps 2323700 time 10 pv d2d4 g8f6 e2e3 e7e6 g1f3 d7d5
info depth 7 multipv 1 score cp 21 nodes 43100 nps 2394444 time 18 pv d2d4 g8f6 e2e3 d7d5 g1f3 c8f5 f1b5 b8c6
info depth 8 multipv 1 score cp 16 nodes 135796 nps 2341310 time 58 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 22 nodes 260673 nps 2369754 time 110 pv e2e4 e7e6 d2d3 d7d5 g1f3 d5e4 d3e4 f8b4 b1c3 g8f6
info depth 10 multipv 1 score cp 24 nodes 404733 nps 2366859 time 171 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 b8c6 d1e2 c8e6 c1g5
info depth 11 multipv 1 score cp 16 nodes 1136698 nps 2368120 time 480 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 b4c3 d2c3
info depth 12 multipv 1 score cp 15 nodes 2088515 nps 2344012 time 891 pv b1c3 d7d5 g1f3 e7e6 e2e4 d5d4 c3b5 b8c6 d2d3 g8f6 c1f4 f8b4 c2c3
info depth 13 multipv 1 score cp 22 nodes 3488965 nps 2259692 time 1544 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 d7d6 e1g1 e8g8 d2d3 b4c3 b2c3
info depth 14 multipv 1 score cp 25 nodes 5690316 nps 2206404 time 2579 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 c8f5 b1c3
info depth 15 multipv 1 score cp 28 nodes 8869296 nps 2187249 time 4055 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 e7e2 f1e2 b8c6
info depth 16 multipv 1 score cp 16 nodes 15721927 nps 2150742 time 7310 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 c8e6
info depth 17 multipv 1 score cp 22 nodes 37113024 nps 2163141 time 17157 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 h2h3 c8e6 e1g1 g8f6 b1c3 f8b4 d2d3 b4c3 b2c3
info depth 18 multipv 1 score cp 20 nodes 56491369 nps 2143152 time 26359 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 d2d3 c8g4 c1e3 d8e7 a2a3 e8c8 e1g1 e7f6 b1c3 c8b8
info depth 19 multipv 1 score cp 24 nodes 96053236 nps 2135275 time 44984 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 e1g1 f6e4 b1c3 e4c3 d2c3 f7f6 f3h4 g7g6 c1e3 d7d6 f1e1 c8d7 h4f3
info depth 20 multipv 1 score cp 18 nodes 184761906 nps 2111275 time 87512 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 e1g1 f8c5 b1c3 b7b5 a4b3 e8g8 d2d3 d7d6 c1g5 h7h6 b3d5 h6g5
```

```
Score of ChessDotCpp vs simplex: 653 - 190 - 157  [0.732] 1000
...      ChessDotCpp playing White: 378 - 65 - 57  [0.813] 500
...      ChessDotCpp playing Black: 275 - 125 - 100  [0.650] 500
...      White vs Black: 503 - 340 - 157  [0.582] 1000
Elo difference: 174.1 +/- 21.7, LOS: 100.0 %, DrawRatio: 15.7 %

Score of ChessDotCpp vs cosette5: 471 - 329 - 200  [0.571] 1000
...      ChessDotCpp playing White: 249 - 148 - 103  [0.601] 500
...      ChessDotCpp playing Black: 222 - 181 - 97  [0.541] 500
...      White vs Black: 430 - 370 - 200  [0.530] 1000
Elo difference: 49.7 +/- 19.4, LOS: 100.0 %, DrawRatio: 20.0 %
```

### 1.31.1

Fixed issue with transposition table and repetitions

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 104 nps 104000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 705 nps 705000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 8 nodes 3176 nps 3176000 time 1 pv d2d4 g8f6 e2e3 d7d5
info depth 5 multipv 1 score cp 30 nodes 10253 nps 2050600 time 5 pv b1c3 e7e5 d2d4 b8c6 e2e3
info depth 6 multipv 1 score cp 10 nodes 23127 nps 2102454 time 11 pv d2d4 g8f6 e2e3 e7e6 g1f3 d7d5
info depth 7 multipv 1 score cp 21 nodes 42486 nps 2124300 time 20 pv d2d4 g8f6 e2e3 d7d5 g1f3 c8f5 f1b5 b8c6
info depth 8 multipv 1 score cp 16 nodes 134917 nps 2176080 time 62 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 b1c3 d5d6
info depth 9 multipv 1 score cp 19 nodes 229221 nps 2183057 time 105 pv e2e4 b8c6 b1c3 g8f6 d2d4 d7d5 e4d5 f6d5 c3e4
info depth 10 multipv 1 score cp 19 nodes 522411 nps 2251771 time 232 pv g1f3 g8f6 b1c3 b8c6 e2e4 e7e5 d2d4 f8b4 c1g5 d7d6
info depth 11 multipv 1 score cp 30 nodes 1192746 nps 2258988 time 528 pv e2e4 e7e5 g1f3 g8f6 f1c4 f6e4 d2d3 e4f6 f3e5 d7d5 c4b5 c7c6
info depth 12 multipv 1 score cp 14 nodes 1705513 nps 2212079 time 771 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 b4c3 d2c3 d7d6 e1g1 f6e4
info depth 13 multipv 1 score cp 22 nodes 2394943 nps 2165409 time 1106 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1c4 e8g8 e1g1 d7d6 d2d3 b4c3 b2c3
info depth 14 multipv 1 score cp 25 nodes 3879466 nps 2102691 time 1845 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 c8f5 b1c3
info depth 15 multipv 1 score cp 25 nodes 6579618 nps 2025120 time 3249 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 d2d4 d7d6 e5f3 e7e4 c1e3 e4g6 b1c3 f8e7 f1b5 c7c6 f3h4
info depth 16 multipv 1 score cp 21 nodes 12305582 nps 2001884 time 6147 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d8e7 f1e2 b8c6 e1g1 c8f5 d4d5 c6e5
info depth 17 multipv 1 score cp 20 nodes 27286229 nps 1989227 time 13717 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 e1g1 f8c5 d2d4 c5d4 f3d4 c6d4 c1e3 d4e6 d1f3 e8g8 b1c3
info depth 18 multipv 1 score cp 16 nodes 48485533 nps 1996768 time 24282 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 e1g1 d7d6 c1g5 e8g8 b1c3 h7h6 g5f6 d8f6 c3d5 f6d8
info depth 19 multipv 1 score cp 23 nodes 79105877 nps 1984095 time 39870 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3c3 e8c8 d2d3 d8d4 c1e3
info depth 20 multipv 1 score cp 27 nodes 162600124 nps 1986101 time 81869 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 d4e5 d7d5 f1b5 c7c6 b5d3 f8b4 c2c3 b4e7 e1g1 e4c5 c1e3 e8g8 d1e2 c5d3 e2d3 c8g4
```

Endgames:
```
Score of ChessDotCpp vs cosette5: 347 - 462 - 146  [0.440] 955
...      ChessDotCpp playing White: 176 - 229 - 73  [0.445] 478
...      ChessDotCpp playing Black: 171 - 233 - 73  [0.435] 477
...      White vs Black: 409 - 400 - 146  [0.505] 955
Elo difference: -42.0 +/- 20.4, LOS: 0.0 %, DrawRatio: 15.3 %
```

Silver:
```
Score of ChessDotCpp vs cosette5: 389 - 414 - 197  [0.487] 1000
...      ChessDotCpp playing White: 210 - 182 - 108  [0.528] 500
...      ChessDotCpp playing Black: 179 - 232 - 89  [0.447] 500
...      White vs Black: 442 - 361 - 197  [0.540] 1000
Elo difference: -8.7 +/- 19.3, LOS: 18.9 %, DrawRatio: 19.7 %
```

### 1.32

* Tuned some search values
* Added continuations
* Improved late move reductions
* Improved TT store policy
* Faster movegen
* Aspiration windows
* Added Lazy SMP

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 444000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 2046 nps 1023000 time 2 pv e2e3 d7d5 d2d4 e7e6
info depth 5 multipv 1 score cp 26 nodes 5695 nps 1423750 time 4 pv e2e4 e7e5 d2d4 d7d5 f1b5 c7c6
info depth 6 multipv 1 score cp 5 nodes 21792 nps 1816000 time 12 pv d2d4 d7d5 e2e3 e7e6 f1d3 g8f6
info depth 7 multipv 1 score cp 15 nodes 31582 nps 1857764 time 17 pv d2d4 d7d5 e2e3 e7e6 g1f3 f8d6 f1d3
info depth 8 multipv 1 score cp 12 nodes 89444 nps 1944434 time 46 pv e2e4 e7e6 b1c3 d7d5 e4d5 e6d5 d1e2 f8e7 d2d4
info depth 9 multipv 1 score cp 16 nodes 149828 nps 1971421 time 76 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1d3 f8b4 c1d2 b8c6
info depth 10 multipv 1 score cp 19 nodes 231754 nps 1964016 time 118 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1b5 c7c6 b5d3 f8b4 c1d2 b4d6
info depth 11 multipv 1 score cp 22 nodes 536639 nps 2009883 time 267 pv e2e4 e7e6 d2d4 d7d5 e4e5 g8e7 g1f3 e7f5 c1g5 f8b4 c2c3 f7f6
info depth 12 multipv 1 score cp 17 nodes 924419 nps 2005247 time 461 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8b4 c2c3 d8e7 c1e3 b4d6
info depth 13 multipv 1 score cp 17 nodes 1421352 nps 2042172 time 696 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f3e5
info depth 14 multipv 1 score cp 21 nodes 2573675 nps 1990467 time 1293 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1c3 d8d6
info depth 15 multipv 1 score cp 21 nodes 7251162 nps 1948713 time 3721 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 f8b4 c2c3 b4d6 b1d2 e4f6
info depth 16 multipv 1 score cp 12 nodes 12491808 nps 1952760 time 6397 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 b8c6 g5f6 g7f6
info depth 17 multipv 1 score cp 13 nodes 22930543 nps 1932132 time 11868 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 e5f3 e7e4 d1e2 e4e2 f1e2 d7d5 d2d3 f8b4 b1c3 c8g4 c1f4 b4c3 b2c3 g4f3 e2f3
info depth 18 multipv 1 score cp 11 nodes 41739921 nps 1949916 time 21406 pv e2e4 e7e5 g1f3 g8f6 f3e5 d8e7 e5f3 e7e4 f1e2 d7d5 e1g1 f8d6 e2b5 e8f8 f1e1 e4g4 h2h3 g4g6 f3e5 g6g5
info depth 19 multipv 1 score cp 17 nodes 83111037 nps 1908448 time 43549 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 d2d3 c8g4 c1e3 f8b4 c2c3 b4e7 b1d2 d8d3 f3e5 d3e3 f2e3 g4d1 a1d1
```

4CPU
```
info depth 1 multipv 1 score cp 32 nodes 1232 nps 617000 time 2 pv e2e4 d7d5 e4d5 d8d5
info depth 2 multipv 1 score cp 32 nodes 2468 nps 1235500 time 2 pv e2e4 d7d5 e4d5 d8d5
info depth 3 multipv 1 score cp 10 nodes 3414 nps 1138000 time 3 pv e2e3 d7d5 d2d4 e7e6 f1b5 c8d7
info depth 4 multipv 1 score cp 10 nodes 4138 nps 1379333 time 3 pv e2e3 d7d5 d2d4 e7e6 f1b5 c8d7
info depth 5 multipv 1 score cp 26 nodes 15495 nps 3874000 time 4 pv e2e4 e7e5 d2d4 d7d5 d4e5 d5e4
info depth 6 multipv 1 score cp 5 nodes 35709 nps 5101571 time 7 pv d2d4 d7d5 e2e3 e7e6 f1d3 g8f6 g1f3
info depth 7 multipv 1 score cp 15 nodes 49089 nps 5454444 time 9 pv d2d4 d7d5 c1f4 e7e6 e2e3 f8d6 f1b5 e8f8 d1g4
info depth 8 multipv 1 score cp 11 nodes 70441 nps 5870083 time 12 pv d2d4 d7d5 c1f4 e7e6 e2e3 g8f6 f1b5 c8d7 b1c3 d7b5
info depth 9 multipv 1 score cp 16 nodes 153053 nps 6377250 time 24 pv e2e3 d7d6 d2d4 e7e5 f1d3 g8f6 g1f3 e5e4 d3b5 b8c6
info depth 10 multipv 1 score cp 19 nodes 320584 nps 6820978 time 47 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1b5 c7c6 b5d3 f8b4 c1d2 b4d6
info depth 11 multipv 1 score cp 22 nodes 1022159 nps 7353669 time 139 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8b4 c2c3 d8e7 c1e3 b4d6
info depth 12 multipv 1 score cp 17 nodes 1249671 nps 7182017 time 174 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 f3e5
info depth 13 multipv 1 score cp 17 nodes 2365281 nps 6757948 time 350 pv e2e4 e7e6 d2d4 d7d5 e4d5 d8d5 b1c3 f8b4 d1d2 b4c3 d2c3 b8c6 g1f3 g8f6
info depth 14 multipv 1 score cp 14 nodes 4708462 nps 6774766 time 695 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 e1g1 e8g8 d2d3 b4c3 b2c3 d7d6 b5c6
info depth 15 multipv 1 score cp 21 nodes 6564877 nps 6740121 time 974 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1b5 c7c6 b5d3 f8e7 b1d2 c8f5 d2e4
info depth 16 multipv 1 score cp 14 nodes 12751917 nps 6822856 time 1869 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 f8d6 b1d2 c8f5 d2e4 d5e4 c1g5
info depth 17 multipv 1 score cp 18 nodes 21315044 nps 6860329 time 3107 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 f8d6 b1d2 e4f6 e1g1 e8g8 f3e5 c8d7
info depth 18 multipv 1 score cp 21 nodes 40707930 nps 6792579 time 5993 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 d2d3 c8g4 c1e3 f8b4 c2c3 b4e7 b1d2 d8d3 f3e5 d3e3 f2e3 g4d1
info depth 19 multipv 1 score cp 15 nodes 78545186 nps 6781074 time 11583 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 d2d3 c8g4 b1d2 d8f6 h2h3 g4e6 d2b3 e6b3 a2b3 e8c8 e1g1 f8c5
info depth 20 multipv 1 score cp 16 nodes 148089824 nps 6776946 time 21852 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 e1g1 e8g8 b1c3 d7d6 c3a4 c5b6 a4b6 a7b6 c1d2 c8e6 c4e6 f7e6
info depth 21 multipv 1 score cp 14 nodes 339693632 nps 6628297 time 51249 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 e1g1 e8g8 b1c3 d7d6 c3a4 c5b6 a4b6 a7b6 c1d2 c8e6 c4e6 f7e6 d1e2
```

```
Score of ChessDotCpp vs cosette5: 280 - 134 - 86  [0.646] 500
...      ChessDotCpp playing White: 141 - 71 - 39  [0.639] 251
...      ChessDotCpp playing Black: 139 - 63 - 47  [0.653] 249
...      White vs Black: 204 - 210 - 86  [0.494] 500
Elo difference: 104.5 +/- 28.7, LOS: 100.0 %, DrawRatio: 17.2 %

Score of ChessDotCpp vs wyldchess: 160 - 230 - 110  [0.430] 500
...      ChessDotCpp playing White: 81 - 116 - 53  [0.430] 250
...      ChessDotCpp playing Black: 79 - 114 - 57  [0.430] 250
...      White vs Black: 195 - 195 - 110  [0.500] 500
Elo difference: -49.0 +/- 27.1, LOS: 0.0 %, DrawRatio: 22.0 %

Score of ChessDotCpp-4CPU vs wyldchess: 98 - 62 - 40  [0.590] 200
...      ChessDotCpp-4CPU playing White: 51 - 27 - 22  [0.620] 100
...      ChessDotCpp-4CPU playing Black: 47 - 35 - 18  [0.560] 100
...      White vs Black: 86 - 74 - 40  [0.530] 200
Elo difference: 63.2 +/- 43.8, LOS: 99.8 %, DrawRatio: 20.0 %

```

### 1.33

Added internal iterative deepening

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 444000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 2046 nps 1023000 time 2 pv e2e3 d7d5 d2d4 e7e6
info depth 5 multipv 1 score cp 26 nodes 5695 nps 1423750 time 4 pv e2e4 e7e5 d2d4 d7d5 f1b5 c7c6
info depth 6 multipv 1 score cp 5 nodes 21840 nps 1820000 time 12 pv d2d4 d7d5 e2e3 e7e6 f1d3 g8f6
info depth 7 multipv 1 score cp 15 nodes 30596 nps 1912250 time 16 pv d2d4 d7d5 e2e3 e7e6 g1f3 f8d6 f1d3
info depth 8 multipv 1 score cp 11 nodes 54009 nps 1862379 time 29 pv d2d4 d7d5 c1f4 e7e6 e2e3 g8f6 f1b5 c8d7 b1c3
info depth 9 multipv 1 score cp 16 nodes 97478 nps 1949560 time 50 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1d3 f8b4 c1d2 b8c6
info depth 10 multipv 1 score cp 19 nodes 164379 nps 1933870 time 85 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1b5 c7c6 b5d3 f8b4 c1d2 b4d6
info depth 11 multipv 1 score cp 22 nodes 439648 nps 2073811 time 212 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 a2a3 b4c3 d2c3 d7d6 c1g5
info depth 12 multipv 1 score cp 16 nodes 635379 nps 2049609 time 310 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 22 nodes 933633 nps 2079360 time 449 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 d2d3 d7d6 b5c6 b7c6 e1g1 e8g8
info depth 14 multipv 1 score cp 14 nodes 1652876 nps 2030560 time 814 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 b5c6 d7c6 f3e5 b4c3 d2c3 d8d1 e1d1
info depth 15 multipv 1 score cp 21 nodes 2630866 nps 2042597 time 1288 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 f8b4 c2c3 b4d6 b1d2 e4f6
info depth 16 multipv 1 score cp 12 nodes 4448284 nps 2046128 time 2174 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 b8c6 g5f6 g7f6
info depth 17 multipv 1 score cp 14 nodes 7132232 nps 2021034 time 3529 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3c3 e8c8 d2d3
info depth 18 multipv 1 score cp 15 nodes 9920139 nps 1999624 time 4961 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 f8c5 d2d3 d8f6 f3g4 g8e7
info depth 19 multipv 1 score cp 16 nodes 22600794 nps 2015588 time 11213 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 d1e2 b8c6 b1c3 c6b4 c1e3 g8f6 e1g1 e8g8 a2a3 b4d3
info depth 20 multipv 1 score cp 16 nodes 29276901 nps 1968459 time 14873 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 d1e2 b8c6 b1c3 c6b4 c1e3 g8f6 e1g1 e8g8 a2a3 b4d3 e2d3
info depth 21 multipv 1 score cp 16 nodes 40597576 nps 1974302 time 20563 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 b1c3 h7h6 h2h3 b8c6 d1d2 c6b4 a2a3 b4d3
info depth 22 multipv 1 score cp 16 nodes 61835930 nps 1957328 time 31592 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 b1c3 c8e6 c3b5 b8c6 e3g5 a7a6 b5d6 e7d6 g5f6
info depth 23 multipv 1 score cp 17 nodes 116355028 nps 1974160 time 58939 pv e2e4 e7e6 g1f3 d7d5 e4e5 c8d7 f1e2 c7c5 e1g1 b8c6 c2c3 d8b6 d2d4 e8c8 d4c5 f8c5 b2b4 c5e7 b4b5 c6a5 c1e3 e7c5 e3c5
```


```
Score of ChessDotCpp vs wyldchess: 183 - 191 - 126  [0.492] 500
...      ChessDotCpp playing White: 89 - 98 - 63  [0.482] 250
...      ChessDotCpp playing Black: 94 - 93 - 63  [0.502] 250
...      White vs Black: 182 - 192 - 126  [0.490] 500
Elo difference: -5.6 +/- 26.4, LOS: 34.0 %, DrawRatio: 25.2 %

Score of ChessDotCpp vs glaurung: 40 - 390 - 70  [0.150] 500
...      ChessDotCpp playing White: 20 - 191 - 39  [0.158] 250
...      ChessDotCpp playing Black: 20 - 199 - 31  [0.142] 250
...      White vs Black: 219 - 211 - 70  [0.508] 500
Elo difference: -301.3 +/- 36.6, LOS: 0.0 %, DrawRatio: 14.0 %
```

### 1.34

Trust TT move validity on single threaded search

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 10 nodes 116 nps 116000 time 1 pv e2e4 e7e5
info depth 3 multipv 1 score cp 32 nodes 444 nps 444000 time 1 pv e2e4 d7d5 d2d3
info depth 4 multipv 1 score cp 10 nodes 2046 nps 2046000 time 1 pv e2e3 d7d5 d2d4 e7e6
info depth 5 multipv 1 score cp 26 nodes 5695 nps 1898333 time 3 pv e2e4 e7e5 d2d4 d7d5 f1b5 c7c6
info depth 6 multipv 1 score cp 5 nodes 21840 nps 1985454 time 11 pv d2d4 d7d5 e2e3 e7e6 f1d3 g8f6
info depth 7 multipv 1 score cp 15 nodes 30596 nps 2039733 time 15 pv d2d4 d7d5 e2e3 e7e6 g1f3 f8d6 f1d3
info depth 8 multipv 1 score cp 11 nodes 54009 nps 2000333 time 27 pv d2d4 d7d5 c1f4 e7e6 e2e3 g8f6 f1b5 c8d7 b1c3
info depth 9 multipv 1 score cp 16 nodes 97478 nps 1949560 time 50 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1d3 f8b4 c1d2 b8c6
info depth 10 multipv 1 score cp 19 nodes 164379 nps 1980469 time 83 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1b5 c7c6 b5d3 f8b4 c1d2 b4d6
info depth 11 multipv 1 score cp 22 nodes 439648 nps 2035407 time 216 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 a2a3 b4c3 d2c3 d7d6 c1g5
info depth 12 multipv 1 score cp 16 nodes 635379 nps 2023500 time 314 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 d7d6 e5f3 b4c3 d2c3 f6e4
info depth 13 multipv 1 score cp 22 nodes 933633 nps 2016485 time 463 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 d2d3 d7d6 b5c6 b7c6 e1g1 e8g8
info depth 14 multipv 1 score cp 14 nodes 1652876 nps 2018163 time 819 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 b5c6 d7c6 f3e5 b4c3 d2c3 d8d1 e1d1
info depth 15 multipv 1 score cp 21 nodes 2630866 nps 2034699 time 1293 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 f8b4 c2c3 b4d6 b1d2 e4f6
info depth 16 multipv 1 score cp 12 nodes 4448284 nps 2028401 time 2193 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 c1g5 b8c6 g5f6 g7f6
info depth 17 multipv 1 score cp 14 nodes 7132232 nps 2008513 time 3551 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 d8f6 f3c3 e8c8 d2d3
info depth 18 multipv 1 score cp 15 nodes 9920139 nps 1965551 time 5047 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 h2h3 g4f3 d1f3 f8c5 d2d3 d8f6 f3g4 g8e7
info depth 19 multipv 1 score cp 16 nodes 22600794 nps 1980788 time 11410 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 d1e2 b8c6 b1c3 c6b4 c1e3 g8f6 e1g1 e8g8 a2a3 b4d3
info depth 20 multipv 1 score cp 16 nodes 29276901 nps 1960550 time 14933 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 d1e2 b8c6 b1c3 c6b4 c1e3 g8f6 e1g1 e8g8 a2a3 b4d3 e2d3
info depth 21 multipv 1 score cp 16 nodes 40597576 nps 1959910 time 20714 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 b1c3 h7h6 h2h3 b8c6 d1d2 c6b4 a2a3 b4d3
info depth 22 multipv 1 score cp 16 nodes 61835930 nps 1948631 time 31733 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 b1c3 c8e6 c3b5 b8c6 e3g5 a7a6 b5d6 e7d6 g5f6
info depth 23 multipv 1 score cp 17 nodes 116355028 nps 1939832 time 59982 pv e2e4 e7e6 g1f3 d7d5 e4e5 c8d7 f1e2 c7c5 e1g1 b8c6 c2c3 d8b6 d2d4 e8c8 d4c5 f8c5 b2b4 c5e7 b4b5 c6a5 c1e3 e7c5 e3c5
```

### 1.35

Late move pruning

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 34 nodes 77 nps 77000 time 1 pv e2e4 b8c6
info depth 3 multipv 1 score cp 19 nodes 290 nps 290000 time 1 pv b1c3 d7d5 e2e4
info depth 4 multipv 1 score cp 19 nodes 657 nps 657000 time 1 pv b1c3 d7d5 e2e4 d5e4
info depth 5 multipv 1 score cp 11 nodes 1815 nps 907500 time 2 pv b1c3 d7d6 e2e4 e7e5 f1c4
info depth 6 multipv 1 score cp 14 nodes 7182 nps 1436400 time 5 pv e2e4 e7e5 d2d4 d7d5 b1c3 b8c6
info depth 7 multipv 1 score cp 16 nodes 11453 nps 1431625 time 8 pv e2e4 e7e5 f1c4 b8c6 d2d3 d7d6 e1f1
info depth 8 multipv 1 score cp 13 nodes 25980 nps 1528235 time 17 pv e2e4 e7e6 d2d3 d7d5 g1f3 b8c6 c1f4 f8d6
info depth 9 multipv 1 score cp 14 nodes 42467 nps 1516678 time 28 pv e2e4 e7e6 d2d4 d7d5 e4e5 b8c6 c1f4 c8d7 b1c3
info depth 10 multipv 1 score cp 14 nodes 73986 nps 1574170 time 47 pv e2e4 e7e6 d2d4 d7d5 e4e5 f8e7 c1f4 c8d7 b1c3 e8f8
info depth 11 multipv 1 score cp 17 nodes 126166 nps 1638519 time 77 pv e2e4 e7e6 d2d4 d7d5 e4e5 f8e7 f1b5 c8d7 b5d7 b8d7 g1f3 e7b4 c2c3 b4e7
info depth 12 multipv 1 score cp 19 nodes 261196 nps 1653139 time 158 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1b5 c7c6 b5d3 f8b4 c1d2 b4d6
info depth 13 multipv 1 score cp 17 nodes 494040 nps 1674711 time 295 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8b4 c1d2 b4d2 b1d2 e8g8 e1g1
info depth 14 multipv 1 score cp 27 nodes 929900 nps 1669479 time 557 pv e2e4 e7e6 g1f3 d7d5 e4e5 f8b4 c2c3 b4a5 d2d4 g8e7 f1d3 c8d7 e1g1 e8g8
info depth 15 multipv 1 score cp 27 nodes 1523151 nps 1688637 time 902 pv e2e4 e7e6 g1f3 d7d5 e4e5 f8b4 c2c3 b4a5 d2d4 g8e7 f1d3 e8g8 e1g1 c8d7 c1f4
info depth 16 multipv 1 score cp 19 nodes 2277848 nps 1686045 time 1351 pv e2e4 e7e6 g1f3 d7d5 e4e5 c8d7 d2d3 f8c5 d3d4 c5b6 f1d3 b8c6 c2c3 g8e7 e1g1 e8g8
info depth 17 multipv 1 score cp 22 nodes 3381173 nps 1659064 time 2038 pv e2e4 e7e6 g1f3 d7d5 e4e5 c8d7 f1e2 f8b4 c2c3 b4a5 d2d4 g8e7 e1g1 e8g8 c1g5 a5b6 e2d3
info depth 18 multipv 1 score cp 21 nodes 4936873 nps 1627182 time 3034 pv e2e4 e7e6 g1f3 d7d5 e4e5 d5d4 c2c3 b8c6 f1b5 c8d7 e1g1 c6e5 b5d7 e5d7 f3d4 f8d6 d4f3 g8f6 d2d4
info depth 19 multipv 1 score cp 15 nodes 8855841 nps 1609567 time 5502 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 d1e2 g8e7 e1g1 e7c6 f1d1 f8e7 d2d4 c5d4 f3d4 e8g8 c1f4 c6d4
info depth 20 multipv 1 score cp 12 nodes 14497459 nps 1581138 time 9169 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1d3 b8c6 e1g1 d8b6 c2c3 c8d7 d3e2 g8e7 d2d3 e7g6 d3d4 c5d4 c3d4 e8c8
info depth 21 multipv 1 score cp 16 nodes 21795709 nps 1588492 time 13721 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 d2d4 c5d4 d1d4 g8e7 f1b5 c8d7 d4a4 b8c6 e1g1 a7a6 b5c6 e7c6 a4b3 d8c7 c1e3 c6e5
info depth 22 multipv 1 score cp 14 nodes 41038537 nps 1581934 time 25942 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 d2d4 c8d7 b1c3 c5d4 d1d4 b8c6 d4f4 c6b4 f1d3 b4d3 c2d3 g8e7 e1g1 e7g6 f4g4 h7h5 g4g5
info depth 23 multipv 1 score cp 20 nodes 72883085 nps 1573163 time 46329 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8e7 g1f3 g8f6 e1g1 e8g8 b1c3 b8c6 h2h3 e7d6 c1g5 c8e6 c3b5 a7a6 g5f6 g7f6 b5d6
info depth 24 multipv 1 score cp 13 nodes 103311166 nps 1562030 time 66139 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 e1g1 e8g8 b1c3 c8e6 c3b5 a7a6 b5d6 d8d6 f1e1 b8c6 c1g5 e6g4 c2c3 f8e8
info depth 25 multipv 1 score cp 11 nodes 148545118 nps 1560102 time 95215 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1b5 c7c6 b5d3 f8d6 g1f3 d8e7 c1e3 g8f6 e1g1 c8e6 b1c3 b8d7 d1d2 h7h6 f1e1 e8c8 e3f4 c8b8 h2h3 d7b6 a2a3
```

```
Score of ChessDotCpp vs wyldchess: 389 - 363 - 248  [0.513] 1000
...      ChessDotCpp playing White: 189 - 185 - 126  [0.504] 500
...      ChessDotCpp playing Black: 200 - 178 - 122  [0.522] 500
...      White vs Black: 367 - 385 - 248  [0.491] 1000
Elo difference: 9.0 +/- 18.7, LOS: 82.8 %, DrawRatio: 24.8 %
```

### 1.36

* Late move pruning improvements
* Performance for futility pruning by detecting if a move checks directly

```
info depth 1 multipv 1 score cp 44 nodes 26 nps 26000 time 1 pv e2e4
info depth 2 multipv 1 score cp 36 nodes 81 nps 81000 time 1 pv d2d4 b8c6
info depth 3 multipv 1 score cp 29 nodes 258 nps 258000 time 1 pv e2e4 d7d5 f1b5 b8c6
info depth 4 multipv 1 score cp 18 nodes 1065 nps 1065000 time 1 pv e2e3 e7e5 d2d4 f8b4 c1d2
info depth 5 multipv 1 score cp 27 nodes 2052 nps 1026000 time 2 pv d2d4 d7d5 e2e3 c8d7 c1d2
info depth 6 multipv 1 score cp 21 nodes 2878 nps 959333 time 3 pv d2d4 d7d5 e2e3 c8d7 c1d2 g8f6
info depth 7 multipv 1 score cp 16 nodes 5690 nps 1138000 time 5 pv d2d4 d7d5 e2e3 g8f6 f1d3 c8g4 d3b5 b8c6
info depth 8 multipv 1 score cp 31 nodes 15815 nps 1317916 time 12 pv d2d4 d7d6 e2e4 g8f6 b1c3 c8g4 f1b5 c7c6 b5e2
info depth 9 multipv 1 score cp 22 nodes 36918 nps 1476720 time 25 pv d2d4 d7d5 e2e3 e7e6 g1f3 c8d7 f1d3 f8b4 c2c3 b4d6
info depth 10 multipv 1 score cp 16 nodes 94284 nps 1545639 time 61 pv d2d4 g8f6 g1f3 e7e6 e2e3 f8e7 f1d3 e8g8 e1g1 d7d5
info depth 11 multipv 1 score cp 19 nodes 180478 nps 1625927 time 111 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e6 g1e2 e6d6 d2d4 e7e5 c3e4 d6b4 c2c3
info depth 12 multipv 1 score cp 23 nodes 322702 nps 1638081 time 197 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d8e7 e1g1
info depth 13 multipv 1 score cp 13 nodes 526630 nps 1671841 time 315 pv e2e4 e7e5 g1f3 g8f6 d2d4 f6e4 f1d3 d7d5 f3e5 f8b4 c2c3 b4e7 d1a4 c8d7 e5d7
info depth 14 multipv 1 score cp 19 nodes 881443 nps 1688588 time 522 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1b5 c8d7 b5d7 b8d7 e1g1 f8e7 c1f4 e8g8
info depth 15 multipv 1 score cp 25 nodes 1404896 nps 1678489 time 837 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 d2d4 c5d4 f3d4 d8a5 b1c3 f8b4 c1d2 a5b6 d4f3 b8c6
info depth 16 multipv 1 score cp 15 nodes 2017360 nps 1668618 time 1209 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 d2d4 c5d4 f3d4 f8c5 d1g4 e8f8 f1d3 d8c7 d4f3 b8c6
info depth 17 multipv 1 score cp 26 nodes 3170091 nps 1649370 time 1922 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 b5d7 b8d7 e1g1 d8b6 d1e2 f8e7 d2d3 e8c8 c2c3 b6c7 c1f4
info depth 18 multipv 1 score cp 16 nodes 4478958 nps 1639442 time 2732 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 b5d7 b8d7 e1g1 d8b6 d2d3 g8e7 c2c4 e8c8 d1e2 d5c4 d3c4 c8b8
info depth 19 multipv 1 score cp 19 nodes 6861607 nps 1624048 time 4225 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d8e7 e2e7 e8e7 e1g1 b8c6 f1e1 c8e6 d3f5 d6b4 c1d2
info depth 20 multipv 1 score cp 15 nodes 10906316 nps 1606232 time 6790 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 b1c3 b8c6 c3b5 c8e6 c2c3 a7a6 b5d6
info depth 21 multipv 1 score cp 15 nodes 16999768 nps 1595473 time 10655 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 d1e2 c8e6 f3g5 d8e7 g5e6 e7e6 e2e6 f7e6 e1g1 b8c6 c1e3 c6b4 d3b5 e8f7
info depth 22 multipv 1 score cp 15 nodes 25027698 nps 1576448 time 15876 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 d1e2 c8e6 f3g5 d8e7 g5e6 e7e6 e2e6 f7e6 b1c3 b8c6 d3b5 e8g8 c1e3 e6e5
info depth 23 multipv 1 score cp 14 nodes 42554645 nps 1577032 time 26984 pv e2e4 e7e6 d2d4 d7d5
info depth 24 multipv 1 score cp 14 nodes 65841523 nps 1580904 time 41648 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 e1g1 e8g8 b1c3 b8c6 c1g5 c8e6 c3b5 a7a6 b5d6 d8d6 g5f6 g7f6 c2c3
info depth 25 multipv 1 score cp 15 nodes 112485635 nps 1585980 time 70925 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 c2c4 g8f6 c4c5 d6e7 f1d3 e8g8 e1g1 b7b6 c5b6 a7b6 b1c3 b8c6 f1e1 c8g4 c1e3 e7d6
```

```
Score of ChessDotCpp vs wyldchess: 452 - 336 - 218  [0.558] 1006
...      ChessDotCpp playing White: 234 - 163 - 106  [0.571] 503
...      ChessDotCpp playing Black: 218 - 173 - 112  [0.545] 503
...      White vs Black: 407 - 381 - 218  [0.513] 1006
Elo difference: 40.2 +/- 19.1, LOS: 100.0 %, DrawRatio: 21.7 %
```

### 1.37

Razoring

```
info depth 1 multipv 1 score cp 10 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 26 nodes 61 nps 61000 time 1 pv d2d3 b8c6
info depth 3 multipv 1 score cp 21 nodes 178 nps 178000 time 1 pv e2e4 d7d6
info depth 4 multipv 1 score cp 32 nodes 455 nps 455000 time 1 pv e2e4 d7d5 d2d3
info depth 5 multipv 1 score cp 19 nodes 1933 nps 966500 time 2 pv d2d4 d7d5 b1c3 b8c6 c1f4
info depth 6 multipv 1 score cp 10 nodes 3834 nps 1278000 time 3 pv d2d4 d7d5 e2e3 e7e6 c1d2 b8c6
info depth 7 multipv 1 score cp 15 nodes 8419 nps 1403166 time 6 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e5 d1e2 b8c6
info depth 8 multipv 1 score cp 15 nodes 12685 nps 1409444 time 9 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e5 d1e2 b8c6 e2e5
info depth 9 multipv 1 score cp 7 nodes 43309 nps 1546750 time 28 pv e2e3 d7d5 g1f3 e7e6 d2d4 f8d6 b1c3 e8f8 f1b5
info depth 10 multipv 1 score cp 11 nodes 74691 nps 1589170 time 47 pv e2e3 d7d5 d2d4 e7e6 f1b5 c8d7 b5d7 d8d7 g1f3 d7b5 b1c3 f8b4
info depth 11 multipv 1 score cp 21 nodes 177805 nps 1677405 time 106 pv e2e4 e7e6 d2d4 d7d5 e4e5 f8b4 c2c3 b4e7 f1d3 e8f8 e1f1 c8d7
info depth 12 multipv 1 score cp 23 nodes 269997 nps 1698094 time 159 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d8e7 e1g1
info depth 13 multipv 1 score cp 19 nodes 410443 nps 1731827 time 237 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1b5 c7c6 b5d3 d8e7 e1f1 g8f6 f1g1
info depth 14 multipv 1 score cp 12 nodes 691975 nps 1756281 time 394 pv e2e4 e7e6 d2d4 d7d5 e4e5 c8d7 g1f3 c7c5 f1e2 c5d4 f3d4 b8c6 d4c6
info depth 15 multipv 1 score cp 23 nodes 1182181 nps 1753977 time 674 pv e2e4 e7e6 g1f3 d7d5 e4e5 c8d7 f1e2 c7c5 e1g1 b8c6 c2c3 d8b6 d2d4 e8c8 d4c5
info depth 16 multipv 1 score cp 12 nodes 2038481 nps 1746770 time 1167 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1e2 b8c6 e1g1 d8c7 e2b5 c8d7 b5c6 d7c6 d2d4 e8c8
info depth 17 multipv 1 score cp 13 nodes 3023222 nps 1717739 time 1760 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 b5d7 b8d7 e1g1 g8e7 d1e2 d8c7 b1c3 e7f5 a2a3 d5d4 c3b5
info depth 18 multipv 1 score cp 16 nodes 4679434 nps 1709070 time 2738 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 d1e2 d8b6 b5d7 b8d7 e1g1 g8e7 d2d3 e8c8 b1c3 e7f5 f1e1 f8e7
info depth 19 multipv 1 score cp 17 nodes 6819322 nps 1715984 time 3974 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 d1e2 d8b6 b5d7 b8d7 e1g1 g8e7 d2d3 e7c6 c2c4 e8c8 c4d5 e6d5 b1c3
info depth 20 multipv 1 score cp 14 nodes 12236421 nps 1711387 time 7150 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 b1c3 g8f6 f1d3 e8g8 e1g1 f8e8 c1g5 c7c6 f1e1 e8e1 d1e1 h7h6 g5e3
info depth 21 multipv 1 score cp 16 nodes 16898956 nps 1702494 time 9926 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 b1c3 g8f6 f1d3 e8g8 e1g1 b8c6 c1g5 c8e6 c3b5 a7a6 g5f6 g7f6 b5d6
info depth 22 multipv 1 score cp 16 nodes 24506088 nps 1700040 time 14415 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 b1c3 g8f6 f1d3 e8g8 e1g1 b8c6 c1g5 c8e6 c3b5 a7a6 g5f6 g7f6 b5d6
info depth 23 multipv 1 score cp 15 nodes 40264378 nps 1685548 time 23888 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 b8c6 e1g1 f8e7 b1c3 e8g8 a2a3 a7a6 c1e3 e7d6 h2h3 c8e6 d1d2 f8e8 e3f4
info depth 24 multipv 1 score cp 19 nodes 59672256 nps 1684467 time 35425 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 c8e6 d3f5 d8e7 f5e6 e7e6 e2e6 f7e6 e1g1 b8c6 f1e1 e8d7 c1e3 c6b4 c2c3 b4c6
info depth 25 multipv 1 score cp 10 nodes 113654232 nps 1679337 time 67678 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1b5 c7c6 b5d3 f8d6 g1f3 g8e7 e1g1 b8d7 c1g5 e8g8 c2c3 d7b6 d1c2 h7h6 g5e3 c8e6 b1d2 d8c7 d2b3 f8e8
```

```
Score of ChessDotCpp vs wyldchess: 447 - 318 - 235  [0.565] 1000
...      ChessDotCpp playing White: 213 - 175 - 112  [0.538] 500
...      ChessDotCpp playing Black: 234 - 143 - 123  [0.591] 500
...      White vs Black: 356 - 409 - 235  [0.473] 1000
Elo difference: 45.1 +/- 18.9, LOS: 100.0 %, DrawRatio: 23.5 %
```

### 1.38

Tune static eval pruning

```
info depth 1 multipv 1 score cp 10 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 26 nodes 61 nps 61000 time 1 pv d2d3 b8c6
info depth 3 multipv 1 score cp 21 nodes 178 nps 178000 time 1 pv e2e4 d7d6
info depth 4 multipv 1 score cp 32 nodes 456 nps 456000 time 1 pv e2e4 d7d5 d2d3
info depth 5 multipv 1 score cp 19 nodes 1947 nps 973500 time 2 pv d2d4 d7d5 b1c3 b8c6 c1f4
info depth 6 multipv 1 score cp 10 nodes 3859 nps 1286333 time 3 pv d2d4 d7d5 e2e3 e7e6 c1d2 b8c6
info depth 7 multipv 1 score cp 15 nodes 8689 nps 1241285 time 7 pv e2e4 d7d5 e4d5 d8d5 b1c3 d5e5 d1e2 b8c6
info depth 8 multipv 1 score cp 12 nodes 18102 nps 1392461 time 13 pv e2e4 e7e6 b1c3 d7d5 e4d5 e6d5 d1e2 f8e7 d2d4
info depth 9 multipv 1 score cp 12 nodes 30451 nps 1450047 time 21 pv e2e4 e7e6 g1f3 d7d5 d2d3 f8c5 c1f4 e8f8 b1c3
info depth 10 multipv 1 score cp 19 nodes 57896 nps 1378476 time 42 pv e2e4 e7e6 g1f3 d7d5 d2d3 f8b4 c1d2 b4d2 d1d2 d5d4 d2f4 b8c6
info depth 11 multipv 1 score cp 16 nodes 129117 nps 1501360 time 86 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1b5 c7c6 b5d3 f8e7 g1f3 e8f8
info depth 12 multipv 1 score cp 21 nodes 213360 nps 1534964 time 139 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1b5 c7c6 b5d3 f8d6 g1f3 d8e7 d1e2 e7e2
info depth 13 multipv 1 score cp 21 nodes 426772 nps 1557562 time 274 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1b5 c7c6 b5d3 g8f6 d1e2 d8e7 e1g1
info depth 14 multipv 1 score cp 28 nodes 743655 nps 1627253 time 457 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 b5d7 b8d7 e1g1 d8c7 d1e2 e8c8 d2d3 f8e7
info depth 15 multipv 1 score cp 23 nodes 1431386 nps 1635869 time 875 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 b8c6 c1g5
info depth 16 multipv 1 score cp 14 nodes 2650937 nps 1675687 time 1582 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 f1d3 c8d7 e1g1 f8d6 c1d2 e8g8 a2a3 b8c6 b1c3 d8e7
info depth 17 multipv 1 score cp 18 nodes 5310327 nps 1623953 time 3270 pv e2e4 e7e6 g1f3 d7d5 e4e5 d5d4 f1b5 c7c6 b5d3 f8c5 e1g1 g8e7 d3e4 e8g8 d2d3 d8b6 c2c3 e7f5
info depth 18 multipv 1 score cp 17 nodes 7462877 nps 1547672 time 4822 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 d1e2 d7b5 e2b5 d8d7 b5e2 g8e7 e1g1 e7f5 d2d3 f8e7 b1c3 e8g8
info depth 19 multipv 1 score cp 22 nodes 9605911 nps 1550090 time 6197 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 d1e2 d7b5 e2b5 d8d7 b5e2 g8e7 e1g1 b8c6 d2d3 e8c8 b1c3 d5d4 c3b5
info depth 20 multipv 1 score cp 19 nodes 15445835 nps 1574659 time 9809 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 f1b5 c8d7 d1e2 d7b5 e2b5 d8d7 b5e2 g8e7 e1g1 b8c6 d2d3 e7f5 c1g5 f8e7 g5e7
info depth 21 multipv 1 score cp 16 nodes 23402005 nps 1594685 time 14675 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 d2d4 c8d7 f1d3 b8c6 d4c5 f8c5 e1g1 g8e7 b1c3 e8g8 c3a4 c5b4 c2c3 b4a5 c1f4
info depth 22 multipv 1 score cp 13 nodes 35626492 nps 1605520 time 22190 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 d2d4 c8d7 f1d3 b8c6 d4c5 f8c5 e1g1 g8e7 b1d2 e8g8 d2b3 c5b6 c2c3 d8c7 c1g5 e7g6
info depth 23 multipv 1 score cp 12 nodes 52146469 nps 1603322 time 32524 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 b1c3 g8f6 f1d3 e8g8 e1g1 f8e8 c1g5 c7c6 d1d2 c8e6 f1e1 b8d7 g5f4 d8c7 f4d6
info depth 24 multipv 1 score cp 11 nodes 84160205 nps 1581185 time 53226 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 b1c3 g8f6 f1d3 e8g8 e1g1 c7c6 f1e1 c8e6 f3g5 e6g4 d1d2 d8c7 h2h3 d6h2 g1h1 g4d7 g5f3
info depth 25 multipv 1 score cp 10 nodes 147264215 nps 1599619 time 92062 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 b1c3 g8f6 f1d3 e8g8 e1g1 c7c6 f1e1 c8e6 f3g5 e6g4 d1d2 f8e8 h2h3 g4d7 a2a3 e8e1 d2e1 b8a6
```

```
Score of ChessDotCpp vs wyldchess: 460 - 313 - 227  [0.574] 1000
...      ChessDotCpp playing White: 227 - 145 - 129  [0.582] 501
...      ChessDotCpp playing Black: 233 - 168 - 98  [0.565] 499
...      White vs Black: 395 - 378 - 227  [0.508] 1000
Elo difference: 51.4 +/- 19.1, LOS: 100.0 %, DrawRatio: 22.7 %

Score of ChessDotCpp vs glaurung: 81 - 320 - 99  [0.261] 500
...      ChessDotCpp playing White: 34 - 163 - 54  [0.243] 251
...      ChessDotCpp playing Black: 47 - 157 - 45  [0.279] 249
...      White vs Black: 191 - 210 - 99  [0.481] 500
Elo difference: -180.8 +/- 30.0, LOS: 0.0 %, DrawRatio: 19.8 %
```

## Version 2

Started rewriting the whole evaluation function using texel tuned values.
This version performs around on-par with the previous one in self-play, despite only having material and PST evaluation.

```
Score of ChessDotCpp2.0 vs ChessDotCpp1.38: 413 - 404 - 183  [0.504] 1000
...      ChessDotCpp2.0 playing White: 204 - 205 - 92  [0.499] 501
...      ChessDotCpp2.0 playing Black: 209 - 199 - 91  [0.510] 499
...      White vs Black: 403 - 414 - 183  [0.494] 1000
Elo difference: 3.1 +/- 19.5, LOS: 62.4 %, DrawRatio: 18.3 %
```

### 2.0

The current version of evaluation consists of only material and piece square tables, nothing else.

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 1 nodes 61 nps 61000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 1 nodes 144 nps 144000 time 1 pv d2d4 g8f6
info depth 4 multipv 1 score cp 14 nodes 350 nps 175000 time 2 pv d2d4 b8c6 d4d5
info depth 5 multipv 1 score cp 36 nodes 1588 nps 529333 time 3 pv g1f3 g8f6 d2d4 d7d5 b1c3
info depth 6 multipv 1 score cp 0 nodes 4153 nps 1038250 time 4 pv g1f3 g8f6 d2d4 d7d5 b1c3 b8c6
info depth 7 multipv 1 score cp 29 nodes 6849 nps 1369800 time 5 pv b1c3 g8f6 d2d4 d7d5 c1e3 b8c6 g1f3
info depth 8 multipv 1 score cp 11 nodes 16671 nps 1667100 time 10 pv e2e4 d7d5 e4d5 g8f6 g1f3 f6d5 b1c3 b8c6
info depth 9 multipv 1 score cp 34 nodes 54083 nps 2163320 time 25 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 d8e7 c1e3 g8f6
info depth 10 multipv 1 score cp 13 nodes 99199 nps 2306953 time 43 pv e2e4 e7e5 g1f3 b8c6 b1c3 f8d6 d2d4 e5d4 c1g5 g8f6
info depth 11 multipv 1 score cp 26 nodes 142631 nps 2338213 time 61 pv g1f3 d7d5 d2d4 e7e6 b1c3 g8f6 c1g5 f8b4 g5f6 b4c3 b2c3
info depth 12 multipv 1 score cp 16 nodes 255952 nps 2437638 time 105 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8d6 e1g1 e8g8 d2d4 e5d4
info depth 13 multipv 1 score cp 16 nodes 328428 nps 2432800 time 135 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8d6 e1g1 e8g8 d2d4 e5d4 f3d4
info depth 14 multipv 1 score cp 16 nodes 467659 nps 2461363 time 190 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8d6 e1g1 e8g8 d2d4 e5d4 f3d4 c6d4
info depth 15 multipv 1 score cp 16 nodes 727963 nps 2476064 time 294 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8d6 e1g1 e8g8 d2d4 e5d4 f3d4 c6d4
info depth 16 multipv 1 score cp 16 nodes 1226351 nps 2507875 time 489 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 e1g1 e8g8 f1e1 f8e8 d2d3 c6d4 c1e3 c7c6
info depth 17 multipv 1 score cp 22 nodes 1754422 nps 2527985 time 694 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 e1g1 e8g8 d2d3 f8e8 c1e3 c5e3 f2e3 c6b4 a1c1
info depth 18 multipv 1 score cp 14 nodes 4551140 nps 2584406 time 1761 pv g1f3 d7d5 d2d4 e7e6 e2e3 g8f6 c2c4 f8e7 b1c3 b8c6 f1e2 e8g8 e1g1 f8e8 f1e1 c8d7 c4d5 e6d5
info depth 19 multipv 1 score cp 13 nodes 8292789 nps 2602884 time 3186 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5 e2e3 e7e6 f1b5 c7c6 b5d3 f5d3 c2d3 f8d6 f4d6 d8d6 e1g1 b8d7 b1c3 e8g8
info depth 20 multipv 1 score cp 13 nodes 14803153 nps 2642476 time 5602 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f6e4 c3e4 d7d5 c4d3 d5e4 d3e4 f8d6 e1g1 e8g8 d2d4 c6d4 f3d4
info depth 21 multipv 1 score cp 13 nodes 20177243 nps 2652457 time 7607 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f6e4 c3e4 d7d5 c4d3 d5e4 d3e4 f8d6 e1g1 e8g8 d2d4 c6d4 f3d4 e5d4 d1d4
info depth 22 multipv 1 score cp 16 nodes 26551350 nps 2660989 time 9978 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4 f8b4 d4c6 b7c6 e4e5 f6d5 c1d2 d8e7 d1e2 c8b7 e1c1 e8g8 c3d5
info depth 23 multipv 1 score cp 21 nodes 41971584 nps 2666216 time 15742 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 b1c3 h7h6 c3d5 e8g8 e1g1 d7d6 c2c3 c5b6 f1e1 c8e6 c1e3 b6e3 d5e3 e6c4
info depth 24 multipv 1 score cp 21 nodes 56240154 nps 2670472 time 21060 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 b1c3 h7h6 c3d5 e8g8 c2c3 d7d6 d3d4 c5b6 d5f6 d8f6 d4d5 c6a5 c4d3 c8g4 e1g1 a8e8 c1d2
info depth 25 multipv 1 score cp 21 nodes 80886246 nps 2664500 time 30357 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 b1c3 h7h6 c3d5 e8g8 c2c3 d7d6 e1g1 c5b6 c1e3 c8e6 f1e1 b6e3 d5e3 e6c4 e3c4 a8c8 a1c1
```

```
Score of ChessDotCpp2.0 vs vice: 97 - 1 - 2  [0.980] 100
...      ChessDotCpp2.0 playing White: 48 - 1 - 1  [0.970] 50
...      ChessDotCpp2.0 playing Black: 49 - 0 - 1  [0.990] 50
...      White vs Black: 48 - 50 - 2  [0.490] 100
Elo difference: 676.1 +/- nan, LOS: 100.0 %, DrawRatio: 2.0 %

Score of ChessDotCpp2.0 vs mediocre: 73 - 19 - 8  [0.770] 100
...      ChessDotCpp2.0 playing White: 36 - 11 - 4  [0.745] 51
...      ChessDotCpp2.0 playing Black: 37 - 8 - 4  [0.796] 49
...      White vs Black: 44 - 48 - 8  [0.480] 100
Elo difference: 209.9 +/- 78.5, LOS: 100.0 %, DrawRatio: 8.0 %

Score of ChessDotCpp2.0 vs simplex: 164 - 24 - 12  [0.850] 200
...      ChessDotCpp2.0 playing White: 85 - 10 - 6  [0.871] 101
...      ChessDotCpp2.0 playing Black: 79 - 14 - 6  [0.828] 99
...      White vs Black: 99 - 89 - 12  [0.525] 200
Elo difference: 301.3 +/- 65.1, LOS: 100.0 %, DrawRatio: 6.0 %

Score of ChessDotCpp2.0 vs cosette5: 131 - 40 - 29  [0.728] 200
...      ChessDotCpp2.0 playing White: 66 - 19 - 15  [0.735] 100
...      ChessDotCpp2.0 playing Black: 65 - 21 - 14  [0.720] 100
...      White vs Black: 87 - 84 - 29  [0.507] 200
Elo difference: 170.6 +/- 49.3, LOS: 100.0 %, DrawRatio: 14.5 %

Score of ChessDotCpp2.0 vs wyldchess: 267 - 149 - 92  [0.616] 508
...      ChessDotCpp2.0 playing White: 140 - 76 - 39  [0.625] 255
...      ChessDotCpp2.0 playing Black: 127 - 73 - 53  [0.607] 253
...      White vs Black: 213 - 203 - 92  [0.510] 508
Elo difference: 82.2 +/- 28.0, LOS: 100.0 %, DrawRatio: 18.1 %

Score of ChessDotCpp2.0 vs supernova: 214 - 194 - 92  [0.520] 500
...      ChessDotCpp2.0 playing White: 112 - 97 - 41  [0.530] 250
...      ChessDotCpp2.0 playing Black: 102 - 97 - 51  [0.510] 250
...      White vs Black: 209 - 199 - 92  [0.510] 500
Elo difference: 13.9 +/- 27.5, LOS: 83.9 %, DrawRatio: 18.4 %

Score of ChessDotCpp2.0 vs glaurung: 103 - 319 - 78  [0.284] 500
...      ChessDotCpp2.0 playing White: 51 - 161 - 38  [0.280] 250
...      ChessDotCpp2.0 playing Black: 52 - 158 - 40  [0.288] 250
...      White vs Black: 209 - 213 - 78  [0.496] 500
Elo difference: -160.6 +/- 30.4, LOS: 0.0 %, DrawRatio: 15.6 %
```

### 2.1

Bishop pair eval

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 2 nodes 69 nps 69000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 2 nodes 154 nps 154000 time 1 pv d2d4 g8f6
info depth 4 multipv 1 score cp 29 nodes 327 nps 327000 time 1 pv d2d4 g8f6 c1e3 f6g4
info depth 5 multipv 1 score cp 28 nodes 1432 nps 1432000 time 1 pv g1f3 g8f6 d2d4 d7d5 c1e3
info depth 6 multipv 1 score cp 10 nodes 3297 nps 1648500 time 2 pv g1f3 g8f6 d2d4 d7d5 c1e3 b8d7
info depth 7 multipv 1 score cp 24 nodes 6918 nps 1729500 time 4 pv b1c3 d7d5 d2d4 g8f6 c1e3 f6g4 e3f4
info depth 8 multipv 1 score cp 19 nodes 11326 nps 1887666 time 6 pv b1c3 d7d5 d2d4 c8f5 c1e3 g8f6 g1f3 b8d7
info depth 9 multipv 1 score cp 23 nodes 15365 nps 1920625 time 8 pv b1c3 d7d5 d2d4 g8f6 g1f3 c8e6 e2e3 b8c6 f1d3
info depth 10 multipv 1 score cp 6 nodes 65467 nps 2338107 time 28 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 c4d5 e6d5 b1c3 b8c6
info depth 11 multipv 1 score cp 21 nodes 101418 nps 2358558 time 43 pv d2d4 g8f6 b1c3 d7d5 g1f3 e7e6 e2e3 f8b4 f1d3 b4c3 b2c3 e8g8
info depth 12 multipv 1 score cp 15 nodes 179370 nps 2423918 time 74 pv d2d4 g8f6 b1c3 d7d5 c1f4 e7e6 c3b5 f8d6 b5d6 c7d6 g1f3 e8g8 a1c1
info depth 13 multipv 1 score cp 20 nodes 336833 nps 2495059 time 135 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 f8d6 f1d3
info depth 14 multipv 1 score cp 15 nodes 482063 nps 2550597 time 189 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 f1c4 f8d6 e1g1 e8g8 d2d4 e5d4 f3d4 d6e5
info depth 15 multipv 1 score cp 17 nodes 733715 nps 2574438 time 285 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 d2d4 e5d4 f3d4 f8b4 d4c6 d7c6 d1d8 e8d8 f1d3 c8e6
info depth 16 multipv 1 score cp 18 nodes 1216088 nps 2620879 time 464 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 f1c4 f8c5 e1g1 e8g8 f1e1 f8e8 c3d5 c6d4 c2c3
info depth 17 multipv 1 score cp 17 nodes 3139292 nps 2596602 time 1209 pv g1f3 g8f6 c2c4 e7e6 d2d4 d7d5 b1c3 f8b4 c4d5 e6d5 e2e3 b8c6 f1d3 b4c3 b2c3 f6e4 c1b2 e8g8
info depth 18 multipv 1 score cp 19 nodes 6770634 nps 2528242 time 2678 pv d2d4 g8f6 c2c4 e7e6 b1c3 f8b4 g1f3 d7d5 e2e3 e8g8 f1d3 d5c4 d3c4 f6e4 d1c2 e4d6 a2a3 b4a3
info depth 19 multipv 1 score cp 17 nodes 8914882 nps 2531917 time 3521 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 f8e7 e2e3 e8g8 f1d3 c7c5 e1g1 b8c6 a2a3 a7a5 f1e1 c5d4 e3d4
info depth 20 multipv 1 score cp 21 nodes 17439455 nps 2588992 time 6736 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 f1c4 f8c5 d2d3 e8g8 e1g1 d7d6 c3d5 c6d4 c2c3 d4f3 d1f3 c7c6 d5f6 d8f6 f3f6
info depth 21 multipv 1 score cp 13 nodes 29393729 nps 2610223 time 11261 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 f1c4 f6e4 c3e4 d7d5 c4d3 d5e4 d3e4 f8d6 e1g1 e8g8 d2d4 c6d4 f3d4 e5d4 d1d4
info depth 22 multipv 1 score cp 19 nodes 34830655 nps 2615699 time 13316 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 f1c4 f6e4 c3e4 d7d5 c4d3 d5e4 d3e4 f8d6 e1g1 e8g8 c2c3 c8g4 h2h3 g4h5 d2d4 f8e8
info depth 23 multipv 1 score cp 19 nodes 43465826 nps 2617634 time 16605 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 d2d4 e5d4 f3d4 f8c5 d4c6 b7c6 e4e5 d8e7 d1e2 f6d5 c3d5 c6d5 c1f4 e8g8 e1c1 c8b7 c1b1
info depth 24 multipv 1 score cp 18 nodes 81261516 nps 2613750 time 31090 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 b8c6 e2e3 f8d6 f1d3 d5c4 d3c4 a7a6 a2a4 e8g8 e1g1 e6e5 d4d5 c6b4 e3e4 c8g4 c1e3 a8c8
info depth 25 multipv 1 score cp 20 nodes 111164341 nps 2618589 time 42452 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 b8c6 e2e3 f8d6 f1d3 e8g8 c4c5 d6e7 e1g1 b7b6 d3b5 c8d7 d1a4 d8e8 f3e5 c6e5 d4e5 d7b5
```

```
Score of ChessDotCpp2.1 vs ChessDotCpp2.0: 268 - 216 - 516  [0.526] 1000
...      ChessDotCpp2.1 playing White: 127 - 111 - 262  [0.516] 500
...      ChessDotCpp2.1 playing Black: 141 - 105 - 254  [0.536] 500
...      White vs Black: 232 - 252 - 516  [0.490] 1000
Elo difference: 18.1 +/- 15.0, LOS: 99.1 %, DrawRatio: 51.6 %

Score of ChessDotCpp2.1 vs supernova: 210 - 200 - 90  [0.510] 500
...      ChessDotCpp2.1 playing White: 104 - 103 - 44  [0.502] 251
...      ChessDotCpp2.1 playing Black: 106 - 97 - 46  [0.518] 249
...      White vs Black: 201 - 209 - 90  [0.492] 500
Elo difference: 6.9 +/- 27.6, LOS: 68.9 %, DrawRatio: 18.0 %
```

### 2.2

Doubled pawn eval

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 1 nodes 61 nps 61000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 1 nodes 144 nps 144000 time 1 pv d2d4 g8f6
info depth 4 multipv 1 score cp 16 nodes 349 nps 349000 time 1 pv d2d4 b8c6 d4d5
info depth 5 multipv 1 score cp 35 nodes 1415 nps 1415000 time 1 pv g1f3 g8f6 d2d4 d7d5 b1c3
info depth 6 multipv 1 score cp 0 nodes 4193 nps 1397666 time 3 pv g1f3 g8f6 d2d4 d7d5 b1c3 b8c6
info depth 7 multipv 1 score cp 27 nodes 9788 nps 1957600 time 5 pv b1c3 g8f6 d2d4 d7d5 c1f4 b8c6 g1f3
info depth 8 multipv 1 score cp 10 nodes 24458 nps 2038166 time 12 pv e2e4 g8f6 e4e5 f6e4 g1f3 d7d5 b1c3 b8c6
info depth 9 multipv 1 score cp 35 nodes 49955 nps 2081458 time 24 pv e2e4 e7e5 g1f3 g8f6 f1d3 f8d6 b1c3 e8g8 e1g1
info depth 10 multipv 1 score cp 1 nodes 142584 nps 2299741 time 62 pv e2e4 e7e5 g1f3 g8f6 d2d4 e5d4 e4e5 f6e4 c2c3 d4c3
info depth 11 multipv 1 score cp 21 nodes 194665 nps 2317440 time 84 pv g1f3 b8c6 d2d4 d7d5 b1c3 g8f6 c1f4 c8f5 a1c1 a8c8 e2e3
info depth 12 multipv 1 score cp 15 nodes 246347 nps 2324028 time 106 pv g1f3 b8c6 d2d4 d7d5 b1c3 g8f6 e2e3 f6e4 f1d3 e4c3 b2c3 c8g4
info depth 13 multipv 1 score cp 15 nodes 332792 nps 2377085 time 140 pv g1f3 b8c6 d2d4 d7d5 b1c3 g8f6 e2e3 e7e6 f1d3 f8d6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 15 nodes 622021 nps 2458581 time 253 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 f1d3 d6d5 d3e4 d5e4 d1e2 b8c6
info depth 15 multipv 1 score cp 16 nodes 968204 nps 2495371 time 388 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 b1c3 f8d6 e1g1 e8g8 d2d4 e5d4 f3d4 c6d4
info depth 16 multipv 1 score cp 22 nodes 1459428 nps 2516255 time 580 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 b1c3 f8d6 e1g1 e8g8 f1e1 f8e8 c3b5 d6b4 c2c3 b4c5
info depth 17 multipv 1 score cp 13 nodes 2676121 nps 2512789 time 1065 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 b1c3 f8d6 e1g1 e8g8 f1e1 f8e8 c3d5 c6a5 c4d3 a5c6 c2c3
info depth 18 multipv 1 score cp 13 nodes 4147965 nps 2520027 time 1646 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4 f8b4 d4c6 b7c6 e4e5 b4c3 b2c3 f6e4 c3c4 e8g8 c1f4
info depth 19 multipv 1 score cp 30 nodes 6194009 nps 2528166 time 2450 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4 c6d4 d1d4 d7d6 c1f4 f8e7 f1d3 c7c5 d4e3 e8g8 e1g1
info depth 20 multipv 1 score cp 25 nodes 8947870 nps 2562391 time 3492 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4 c6d4 d1d4 d7d6 f1c4 f8e7 c1f4 c7c5 d4d1 e8g8 e1g1 f8e8
info depth 21 multipv 1 score cp 22 nodes 15145820 nps 2564914 time 5905 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 f1e2 b8c6 e1g1 f8e7 c1f4 e8g8 b1c3 c8f5 a1c1 d6d5 d3d4
info depth 22 multipv 1 score cp 21 nodes 24023559 nps 2554882 time 9403 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 b8c6 d4d5 c6e5 d1e2 c8f5 b1d2 e4d2 c1d2 f5g4 e1c1 f8e7 e2b5 c7c6 b5b7
info depth 23 multipv 1 score cp 28 nodes 38772348 nps 2569917 time 15087 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8d6 f3e5 d6e5 d2d4 e5d4 d1d4 b8c6 d4d1 e8g8 f1d3 c6b4 e1g1 d7d5 c3d5 f6d5 e4d5 d8d5 c1e3
info depth 24 multipv 1 score cp 23 nodes 90202226 nps 2571182 time 35082 pv e2e4 e7e6 b1c3 d7d5 d2d4 g8f6 c1g5 d5e4 c3e4 b8d7 f1d3 f8e7 e4f6 d7f6 g1f3 e8g8 e1g1 c7c5 d4c5 e7c5 c2c3 h7h6 g5f4 c8d7 f4e5
info depth 25 multipv 1 score cp 28 nodes 135603369 nps 2567175 time 52822 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f1d3 b4c3 d2c3 d7d5 d1e2 d5e4 d3e4 f6e4 e2e4 b8c6 e1g1 f7f6 c1e3 e8g8 b2b4 c8e6 a1d1 d8e7 b4b5
```

```
Score of ChessDotCpp2.2 vs ChessDotCpp2.1: 289 - 229 - 482  [0.530] 1000
...      ChessDotCpp2.2 playing White: 142 - 117 - 241  [0.525] 500
...      ChessDotCpp2.2 playing Black: 147 - 112 - 241  [0.535] 500
...      White vs Black: 254 - 264 - 482  [0.495] 1000
Elo difference: 20.9 +/- 15.5, LOS: 99.6 %, DrawRatio: 48.2 %

Score of ChessDotCpp2.2 vs supernova: 214 - 198 - 88  [0.516] 500
...      ChessDotCpp2.2 playing White: 108 - 98 - 44  [0.520] 250
...      ChessDotCpp2.2 playing Black: 106 - 100 - 44  [0.512] 250
...      White vs Black: 208 - 204 - 88  [0.504] 500
Elo difference: 11.1 +/- 27.7, LOS: 78.5 %, DrawRatio: 17.6 %
```

### 2.3

Passed pawn eval

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 2 nodes 61 nps 61000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 2 nodes 144 nps 144000 time 1 pv d2d4 g8f6
info depth 4 multipv 1 score cp 15 nodes 359 nps 359000 time 1 pv d2d4 b8c6 d4d5
info depth 5 multipv 1 score cp 34 nodes 1511 nps 1511000 time 1 pv g1f3 g8f6 d2d4 d7d5 b1c3
info depth 6 multipv 1 score cp 0 nodes 4281 nps 2140500 time 2 pv g1f3 g8f6 d2d4 d7d5 b1c3 b8c6
info depth 7 multipv 1 score cp 27 nodes 9354 nps 1870800 time 5 pv b1c3 g8f6 d2d4 d7d5 c1f4 b8c6 g1f3
info depth 8 multipv 1 score cp 10 nodes 13121 nps 2186833 time 6 pv b1c3 g8f6 e2e4 e7e5 g1f3 b8c6 d2d4 f8d6
info depth 9 multipv 1 score cp 21 nodes 28767 nps 2212846 time 13 pv b1c3 d7d5 d2d4 g8f6 c1e3 b8c6 a1c1 c8f5 g1f3
info depth 10 multipv 1 score cp 8 nodes 95211 nps 2380275 time 40 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8d6 d2d4 e5d4
info depth 11 multipv 1 score cp 18 nodes 115767 nps 2362591 time 49 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6 b1c3
info depth 12 multipv 1 score cp 15 nodes 169173 nps 2416757 time 70 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 d7d5 b1c3 g8f6 e4d5 f6d5
info depth 13 multipv 1 score cp 22 nodes 259779 nps 2427841 time 107 pv e2e4 e7e5 g1f3 b8c6 c2c3 g8f6 d2d4 e5d4 e4e5 f6e4 f1d3 d7d5 c3d4
info depth 14 multipv 1 score cp 11 nodes 542438 nps 2443414 time 222 pv g1f3 d7d5 d2d4 g8f6 b1c3 e7e6 c1f4 c7c6 e2e3 f8d6 f4d6 d8d6 f1d3 e8g8
info depth 15 multipv 1 score cp 20 nodes 995835 nps 2434804 time 409 pv g1f3 d7d5 d2d4 g8f6 c1f4 e7e6 e2e3 c7c5 f1b5 c8d7 b1c3 f8e7 e1g1 e8g8 f3e5 b8c6
info depth 16 multipv 1 score cp 14 nodes 1620628 nps 2466709 time 657 pv g1f3 d7d5 d2d4 g8f6 c1f4 e7e6 e2e3 f8d6 f4d6 d8d6 f1d3 d6b6 b1c3 b6b2 c3b5 c7c6
info depth 17 multipv 1 score cp 15 nodes 2414627 nps 2476540 time 975 pv g1f3 d7d5 d2d4 g8f6 b1c3 e7e6 e2e3 b8c6 f1e2 f8e7 e1g1 e8g8 c1d2 f6e4 c3e4 d5e4 f3e5
info depth 18 multipv 1 score cp 17 nodes 5526828 nps 2462935 time 2244 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6 b1c3 d7d6 c1f4 c8d7 f1e2 f8e7 e1g1 e8g8
info depth 19 multipv 1 score cp 23 nodes 7942121 nps 2450515 time 3241 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 b8c6 c1e3 c8e6 e1c1 e8c8 d3d4
info depth 20 multipv 1 score cp 21 nodes 10907728 nps 2450073 time 4452 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d1e2 d8e7 d2d3 e4f6 b1c3 c8f5 c3b5 b8a6 b5d4 f5g6 e2e7 f8e7 c1e3
info depth 21 multipv 1 score cp 17 nodes 20140344 nps 2445997 time 8234 pv e2e4 c7c5 b1c3 b8c6 g1f3 e7e5 f1c4 f8e7 e1g1 g8f6 f1e1 d7d6 d2d3 e8g8 c1e3 f6g4 c3d5 g4e3 e1e3 c6d4 f3d4
info depth 22 multipv 1 score cp 20 nodes 26103659 nps 2435042 time 10720 pv e2e4 c7c5 b1c3 b8c6 g1f3 g8f6 f1b5 c6d4 e4e5 d4b5 c3b5 f6e4 e1g1 d7d5 e5d6 e4d6 b5d6 d8d6 c2c3 c8e6 d2d4 e8c8 c1e3
info depth 23 multipv 1 score cp 15 nodes 41070983 nps 2468949 time 16635 pv e2e4 c7c5 b1c3 b8c6 g1f3 g8f6 f1b5 d7d6 d2d4 c5d4 f3d4 c8d7 c1g5 e7e5 d4f3 f8e7 g5f6 e7f6 d1d6 a8c8 c3d5 d8a5 d5c3 a7a6
info depth 24 multipv 1 score cp 15 nodes 56691852 nps 2482456 time 22837 pv e2e4 c7c5 b1c3 b8c6 g1f3 g8f6 f1b5 d7d6 d2d4 c5d4 f3d4 c8d7 d4c6 b7c6 b5d3 e7e5 e1g1 d6d5 e4d5 f6d5 c3d5
info depth 25 multipv 1 score cp 11 nodes 149346381 nps 2493886 time 59885 pv e2e4 c7c5 b1c3 b8c6 g1f3 g8f6 f1b5 d7d6 d2d4 c5d4 f3d4 c8d7 d4c6 b7c6 b5e2 e7e5 e1g1 f8e7 f1e1 e8g8 c1e3 a8c8 a1c1
```

```
Score of ChessDotCpp2.3 vs ChessDotCpp2.2: 161 - 115 - 224  [0.546] 500
...      ChessDotCpp2.3 playing White: 87 - 60 - 104  [0.554] 251
...      ChessDotCpp2.3 playing Black: 74 - 55 - 120  [0.538] 249
...      White vs Black: 142 - 134 - 224  [0.508] 500
Elo difference: 32.1 +/- 22.6, LOS: 99.7 %, DrawRatio: 44.8 %

Score of ChessDotCpp2.3 vs supernova: 235 - 179 - 86  [0.556] 500
...      ChessDotCpp2.3 playing White: 114 - 86 - 51  [0.556] 251
...      ChessDotCpp2.3 playing Black: 121 - 93 - 35  [0.556] 249
...      White vs Black: 207 - 207 - 86  [0.500] 500
Elo difference: 39.1 +/- 27.9, LOS: 99.7 %, DrawRatio: 17.2 %
```

### 2.4

Rooks on open and semi-open file eval

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 1 nodes 69 nps 69000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 1 nodes 155 nps 155000 time 1 pv d2d4 g8f6
info depth 4 multipv 1 score cp 29 nodes 328 nps 328000 time 1 pv d2d4 g8f6 c1e3 f6g4
info depth 5 multipv 1 score cp 27 nodes 1413 nps 1413000 time 1 pv g1f3 g8f6 d2d4 d7d5 c1e3
info depth 6 multipv 1 score cp 10 nodes 2823 nps 1411500 time 2 pv g1f3 g8f6 d2d4 d7d5 c1e3 b8d7
info depth 7 multipv 1 score cp 27 nodes 7544 nps 1886000 time 4 pv g1f3 b8c6 d2d4 d7d5 c1e3 g8f6 b1c3
info depth 8 multipv 1 score cp 9 nodes 21206 nps 1927818 time 11 pv e2e4 g8f6 b1c3 b8c6 g1f3 e7e5 d2d4 f8d6
info depth 9 multipv 1 score cp 27 nodes 37906 nps 2105888 time 18 pv e2e4 d7d5 e4d5 g8f6 g1f3 f6d5 d2d4 c8f5 b1d2
info depth 10 multipv 1 score cp 12 nodes 63962 nps 2205586 time 29 pv e2e4 d7d5 e4d5 g8f6 g1f3 f6d5 d2d4 c8e6 f1b5 c7c6 b5e2
info depth 11 multipv 1 score cp 20 nodes 102283 nps 2223543 time 46 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6 b1c3
info depth 12 multipv 1 score cp 20 nodes 234300 nps 2390816 time 98 pv d2d4 g8f6 b1c3 d7d5 c1f4 c7c6 g1f3 f6e4 f3e5 c8f5 c3e4
info depth 13 multipv 1 score cp 14 nodes 364987 nps 2401230 time 152 pv d2d4 g8f6 b1c3 d7d5 c1f4 e7e6 c3b5 b8a6 e2e3 c7c6 b5c3 f8d6 f4d6
info depth 14 multipv 1 score cp 12 nodes 671659 nps 2469334 time 272 pv d2d4 g8f6 b1c3 d7d5 g1f3 e7e6 e2e3 b8c6 f1d3 c6b4 a2a3 b4d3 c2d3 f8d6 e1g1
info depth 15 multipv 1 score cp 20 nodes 1457204 nps 2495212 time 584 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4 c6d4 d1d4 f8d6 f1d3 e8g8 e1g1
info depth 16 multipv 1 score cp 14 nodes 2278814 nps 2543319 time 896 pv g1f3 d7d5 d2d4 g8f6 c1f4 e7e6 e2e3 b8c6 b1c3 f8b4 f1d3 f6e4 d3e4 d5e4 f4g5 b4c3
info depth 17 multipv 1 score cp 15 nodes 3132774 nps 2540773 time 1233 pv g1f3 d7d5 d2d4 g8f6 c1f4 c8f5 b1c3 b8c6 e2e3 e7e6 f1b5 f8d6 f4d6 c7d6 e1g1 e8g8 a1c1
info depth 18 multipv 1 score cp 17 nodes 6578083 nps 2565554 time 2564 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4 c6d4 d1d4 d7d6 c1f4 c8d7 f1b5 c7c5 d4a4 f8e7
info depth 19 multipv 1 score cp 22 nodes 8317994 nps 2562536 time 3246 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 d7d6 f1d3 c8d7 e1g1 c7c5 d4e3 g8f6 e3e2 d7g4 d3b5 g4d7
info depth 20 multipv 1 score cp 25 nodes 10811923 nps 2557824 time 4227 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 d7d6 f1d3 c8d7 e1g1 g8f6 c1f4 c7c5 d4e3 f8e7 e4e5 d6e5
info depth 21 multipv 1 score cp 21 nodes 18517839 nps 2558065 time 7239 pv e2e4 c7c5 b1c3 b8c6 g1f3 g8f6 f1b5 d7d6 d2d4 c5d4 f3d4 c8d7 d4c6 b7c6 b5d3 e7e5 e1g1 f8e7 c1e3 e8g8 a1c1
info depth 22 multipv 1 score cp 18 nodes 25670927 nps 2561457 time 10022 pv e2e4 c7c5 b1c3 b8c6 g1f3 g8f6 f1b5 d7d6 d2d4 c5d4 f3d4 c8d7 e1g1 c6d4 d1d4 d7b5 c3b5 a7a6 b5c3 e7e5 d4a4 b7b5 a4b3
info depth 23 multipv 1 score cp 19 nodes 36218377 nps 2568861 time 14099 pv e2e4 c7c5 b1c3 b8c6 g1f3 e7e5 f1c4 f8e7 c3d5 g8f6 d2d3 e8g8 e1g1 d7d6 c2c3 c8e6 d5f6 e7f6 c4e6 f7e6 c1e3 a8c8 a1c1 f8e8
info depth 24 multipv 1 score cp 19 nodes 54780584 nps 2562115 time 21381 pv e2e4 c7c5 b1c3 b8c6 g1f3 g8f6 f1b5 d7d6 d2d4 c5d4 f3d4 c8d7 e1g1 c6d4 d1d4 d7b5 c3b5 d8d7 d4a4 e8c8 c1e3 d7e6 b5c3 c8b8
info depth 25 multipv 1 score cp 15 nodes 110023708 nps 2563519 time 42919 pv e2e4 c7c5 g1f3 d7d6 b1c3 g8f6 f1c4 b8c6 e1g1 e7e6 d2d4 c5d4 f3d4 c6d4 d1d4 f8e7 c4b5 c8d7 b5d7 d8d7 c1e3 e8g8 a1e1 e6e5 d4d3 a8e8 e3a7 g8h8
```

```
Score of ChessDotCpp2.4 vs ChessDotCpp2.3: 127 - 91 - 282  [0.536] 500
...      ChessDotCpp2.4 playing White: 68 - 50 - 133  [0.536] 251
...      ChessDotCpp2.4 playing Black: 59 - 41 - 149  [0.536] 249
...      White vs Black: 109 - 109 - 282  [0.500] 500
Elo difference: 25.1 +/- 20.1, LOS: 99.3 %, DrawRatio: 56.4 %

// Redo this one
Score of ChessDotCpp2.4 vs supernova: 242 - 154 - 104  [0.588] 500
...      ChessDotCpp2.4 playing White: 121 - 84 - 46  [0.574] 251
...      ChessDotCpp2.4 playing Black: 121 - 70 - 58  [0.602] 249
...      White vs Black: 191 - 205 - 104  [0.486] 500
Elo difference: 61.8 +/- 27.4, LOS: 100.0 %, DrawRatio: 20.8 %
```

### 2.5

Protected pawn and weak pawn eval

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 0 nodes 61 nps 61000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 0 nodes 156 nps 156000 time 1 pv g1f3 g8f6
info depth 4 multipv 1 score cp 3 nodes 430 nps 430000 time 1 pv b1c3 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 36 nodes 2553 nps 1276500 time 2 pv d2d4 g8f6 b1c3 b8c6 g1f3
info depth 6 multipv 1 score cp 5 nodes 6315 nps 2105000 time 3 pv d2d4 b8c6 d4d5 c6b4 g1f3 g8f6
info depth 7 multipv 1 score cp 38 nodes 13169 nps 2194833 time 6 pv e2e4 b8c6 g1f3 g8f6 e4e5 f6e4 d2d4
info depth 8 multipv 1 score cp 9 nodes 29136 nps 2081142 time 14 pv e2e4 g8f6 e4e5 f6e4 b1c3 d7d5 d2d4 b8c6
info depth 9 multipv 1 score cp 37 nodes 53190 nps 2216250 time 24 pv e2e4 e7e6 g1f3 d7d5 b1c3 d5d4 c3b5 g8f6 f1d3
info depth 10 multipv 1 score cp 10 nodes 109956 nps 2244000 time 49 pv e2e4 e7e5 g1f3 b8c6 c2c3 g8f6 d2d4 f6e4 f1d3 d7d5
info depth 11 multipv 1 score cp 28 nodes 186683 nps 2333537 time 80 pv d2d4 d7d5 g1f3 e7e6 e2e3 c7c5 f1e2 c5d4 e3d4 f8b4 c2c3 b4d6
info depth 12 multipv 1 score cp 13 nodes 291459 nps 2389008 time 122 pv d2d4 g8f6 b1c3 d7d5 g1f3 e7e6 e2e3 c7c6 f1d3 f8d6 e1g1 e8g8
info depth 13 multipv 1 score cp 22 nodes 462066 nps 2419193 time 191 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8d6 e1g1 e8g8 d2d3 c6d4 f3d4
info depth 14 multipv 1 score cp 17 nodes 867467 nps 2396317 time 362 pv d2d4 g8f6 g1f3 e7e6 c2c4 f8b4 c1d2 b8c6 b1c3 d7d5 e2e3 e8g8 f1d3 d5c4 d3c4
info depth 15 multipv 1 score cp 19 nodes 1975707 nps 2491433 time 793 pv e2e3 g8f6 g1f3 e7e6 f1e2 d7d5 e1g1 c7c5 c2c4 d5d4 e3d4 c5d4 d2d3 b8c6 c1f4
info depth 16 multipv 1 score cp 16 nodes 3244936 nps 2499950 time 1298 pv e2e3 g8f6 d2d4 e7e6 c2c4 f8b4 c1d2 b8c6 d2b4 c6b4 a2a3 b4c6 g1f3 e8g8 f1d3 d7d5 e1g1
info depth 17 multipv 1 score cp 20 nodes 5234787 nps 2522788 time 2075 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8e7 e1g1 e8g8 d2d3 d7d6 c1e3 c6a5 c4b3 c8g4 h2h3
info depth 18 multipv 1 score cp 20 nodes 6361672 nps 2522471 time 2522 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8e7 e1g1 e8g8 d2d3 d7d6 c1e3 c6a5 c4b3 c8g4 h2h3 a5b3
info depth 19 multipv 1 score cp 19 nodes 10651723 nps 2498058 time 4264 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8e7 e1g1 e8g8 h2h3 d7d6 a2a3 a7a6 d2d4 e5d4 f3d4 c6d4
info depth 20 multipv 1 score cp 24 nodes 13109587 nps 2503262 time 5237 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8e7 e1g1 d7d6 h2h3 e8g8 a2a3 a7a6 d2d3 c6a5 c4a2 a5c6 c3d5 c8e6
info depth 21 multipv 1 score cp 21 nodes 18767260 nps 2506646 time 7487 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8e7 e1g1 d7d6 d2d3 c6a5 c4b3 a5b3 a2b3 e8g8 c1e3 a7a6 d3d4 c8g4 d4e5
info depth 22 multipv 1 score cp 19 nodes 32909383 nps 2522371 time 13047 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8e7 b1c3 e7c6 d4d1 f8b4 f1d3 e8g8 e1g1 b4c3 b2c3 d7d5 c1e3 c8e6 f1e1
info depth 23 multipv 1 score cp 20 nodes 50303622 nps 2530108 time 19882 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8e7 b1c3 d7d6 c1e3 c6a5 c4b3 f6g4 e3d2 a5b3 a2b3 e8g8 h2h3 g4f6 d2e3 h7h6 e1g1 c7c5 a1c1 c8e6 f1e1
info depth 24 multipv 1 score cp 22 nodes 98792573 nps 2525566 time 39117 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 f8d6 e2e3 e8g8 c4d5 e6d5 f1d3 c7c6 e1g1 f8e8 h2h3 f6e4 d1c2 c8f5 f3d2 d8e7 d2e4
info depth 25 multipv 1 score cp 29 nodes 150893560 nps 2524401 time 59774 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 b8c6 c4d5 e6d5 c1f4 f8d6 f4d6 d8d6 e2e3 e8g8 f1b5 c8g4 e1g1 g4f3 d1f3 c6b4 a2a3 b4c2 a1c1
```

```
Score of ChessDotCpp2.5 vs ChessDotCpp2.4: 322 - 221 - 457  [0.550] 1000
...      ChessDotCpp2.5 playing White: 156 - 111 - 233  [0.545] 500
...      ChessDotCpp2.5 playing Black: 166 - 110 - 224  [0.556] 500
...      White vs Black: 266 - 277 - 457  [0.494] 1000
Elo difference: 35.2 +/- 15.9, LOS: 100.0 %, DrawRatio: 45.7 %

// Redo this one
Score of ChessDotCpp2.5 vs supernova: 175 - 120 - 65  [0.576] 360
...      ChessDotCpp2.5 playing White: 94 - 53 - 33  [0.614] 180
...      ChessDotCpp2.5 playing Black: 81 - 67 - 32  [0.539] 180
...      White vs Black: 161 - 134 - 65  [0.537] 360
Elo difference: 53.5 +/- 32.8, LOS: 99.9 %, DrawRatio: 18.1 %
```

### 2.6

Mobility eval

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 10 nodes 46 nps 46000 time 1 pv b1a3
info depth 3 multipv 1 score cp 1 nodes 217 nps 217000 time 1 pv e2e3 d7d5
info depth 4 multipv 1 score cp -8 nodes 500 nps 500000 time 1 pv e2e3 d7d5 b1a3
info depth 5 multipv 1 score cp 34 nodes 2071 nps 1035500 time 2 pv d2d4 g8f6 g1f3 d7d5 c2c3
info depth 6 multipv 1 score cp 12 nodes 5627 nps 1406750 time 4 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5
info depth 7 multipv 1 score cp 32 nodes 11905 nps 1700714 time 7 pv d2d4 g8f6 g1f3 d7d5 c2c3 b8c6 e2e3
info depth 8 multipv 1 score cp 21 nodes 19283 nps 1753000 time 11 pv e2e4 d7d5 e4d5 g8f6 d2d4 c7c6 d5c6 b8c6
info depth 9 multipv 1 score cp 40 nodes 38789 nps 1847095 time 21 pv e2e4 c7c5 c2c3 b8c6 g1f3 e7e6 e4e5 d7d5 d2d4
info depth 10 multipv 1 score cp 36 nodes 68489 nps 1956828 time 35 pv e2e4 c7c5 g1f3 b8c6 f1c4 e7e6 b1c3 c6d4 f3d4
info depth 11 multipv 1 score cp 36 nodes 101816 nps 1996392 time 51 pv e2e4 c7c5 g1f3 b8c6 c2c3 d7d5 e4d5 d8d5 f1e2 g8f6 d2d4
info depth 12 multipv 1 score cp 20 nodes 201317 nps 2033505 time 99 pv e2e4 c7c5 c2c3 d7d5 e4d5 d8d5 g1f3 g8f6 d2d4 c5d4 f3d4 b8c6
info depth 13 multipv 1 score cp 33 nodes 308865 nps 2086925 time 148 pv e2e4 c7c5 c2c3 d7d5 e4d5 d8d5 d2d4 c5d4 c3d4 b8c6 g1f3 d5e4 f1e2 g8f6
info depth 14 multipv 1 score cp 24 nodes 523321 nps 2136004 time 245 pv e2e4 c7c5 c2c3 e7e5 d2d4 c5d4 c3d4 e5d4 d1d4 g8f6 b1c3 b8c6 d4d1 f8e7
info depth 15 multipv 1 score cp 31 nodes 990665 nps 2206380 time 449 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 f1b5 d7d5 e4d5 f6d5 e1g1 e7e6 c3d5 e6d5 d2d4
info depth 16 multipv 1 score cp 33 nodes 1490457 nps 2231223 time 668 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 c1e3 f8e7 e4e5 f6d5
info depth 17 multipv 1 score cp 31 nodes 2275237 nps 2243823 time 1014 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 f1b5 e7e5 e1g1 d7d6 a2a3 a7a6 b5c4 h7h6 c4e2 c8e6 d2d3
info depth 18 multipv 1 score cp 24 nodes 4463625 nps 2226246 time 2005 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5 b1d2 f8e7 d2f3 h7h6 c2c4 d5b4
info depth 19 multipv 1 score cp 25 nodes 8542124 nps 2247927 time 3800 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 b1c3 b8c6 f1d3 c8g4 d4c5 f8c5 h2h3 g4f3
info depth 20 multipv 1 score cp 20 nodes 11391004 nps 2241441 time 5082 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 b1c3 b8c6 f1d3 c8g4 d3e2 g4f5 e1g1 f8d6 d4c5 d6c5
info depth 21 multipv 1 score cp 21 nodes 16491779 nps 2256674 time 7308 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 b1c3 f8d6 f1d3 b8c6 e1g1 e8g8 d4c5 d6c5 h2h3 d5d4 e3d4
info depth 22 multipv 1 score cp 23 nodes 24499087 nps 2256316 time 10858 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 b1c3 f8e7 e2e3 e8g8 c4d5 e6d5 f1d3 c7c5 e1g1 b8c6 a2a3 c8g4 d4c5 g4f3 d1f3 e7c5
info depth 23 multipv 1 score cp 23 nodes 38491015 nps 2251463 time 17096 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 b1c3 f8e7 e2e3 e8g8 c4d5 e6d5 f1d3 c7c5 e1g1 b8c6 d4c5 c8g4 h2h3 g4f3 d1f3 a7a6 f1e1
info depth 24 multipv 1 score cp 31 nodes 103772300 nps 2200337 time 47162 pv d2d4 g8f6 c2c4 d7d5 b1c3 e7e6 g1f3 b8c6 e2e3 f8d6 f1d3 e8g8 c4d5 e6d5 e1g1 c8e6 a2a3 c6e7 c3b5 c7c6 b5d6 d8d6 c1d2 h7h6
info depth 25 multipv 1 score cp 29 nodes 184895374 nps 2210345 time 83650 pv d2d4 d7d5 c2c4 e7e6 g1f3 a7a6 c4d5 e6d5 b1c3 g8f6 c1f4 f8d6 f4d6 d8d6 e2e3 e8g8 f1d3 c8d7 e1g1 b8c6 a2a3 c6e7 h2h3 h7h6 f1e1
```

```
Score of ChessDotCpp2.6 vs ChessDotCpp2.5: 192 - 105 - 203  [0.587] 500
...      ChessDotCpp2.6 playing White: 88 - 57 - 105  [0.562] 250
...      ChessDotCpp2.6 playing Black: 104 - 48 - 98  [0.612] 250
...      White vs Black: 136 - 161 - 203  [0.475] 500
Elo difference: 61.1 +/- 23.6, LOS: 100.0 %, DrawRatio: 40.6 %

Score of ChessDotCpp2.6 vs supernova: 286 - 115 - 99  [0.671] 500
...      ChessDotCpp2.6 playing White: 150 - 52 - 48  [0.696] 250
...      ChessDotCpp2.6 playing Black: 136 - 63 - 51  [0.646] 250
...      White vs Black: 213 - 188 - 99  [0.525] 500
Elo difference: 123.8 +/- 28.6, LOS: 100.0 %, DrawRatio: 19.8 %

Score of ChessDotCpp2.6 vs glaurung: 126 - 251 - 123  [0.375] 500
...      ChessDotCpp2.6 playing White: 56 - 136 - 58  [0.340] 250
...      ChessDotCpp2.6 playing Black: 70 - 115 - 65  [0.410] 250
...      White vs Black: 171 - 206 - 123  [0.465] 500
Elo difference: -88.7 +/- 27.0, LOS: 0.0 %, DrawRatio: 24.6 %
```

### 2.7

King attack eval

```
info depth 1 multipv 1 score cp 0 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 9 nodes 46 nps 46000 time 1 pv b1a3
info depth 3 multipv 1 score cp 3 nodes 200 nps 200000 time 1 pv e2e3 g8f6
info depth 4 multipv 1 score cp 12 nodes 337 nps 337000 time 1 pv e2e3 g8f6 b1a3
info depth 5 multipv 1 score cp 34 nodes 2207 nps 1103500 time 2 pv e2e3 g8f6 g1f3 d7d5 d2d4
info depth 6 multipv 1 score cp 13 nodes 5769 nps 1442250 time 4 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5
info depth 7 multipv 1 score cp 26 nodes 8498 nps 1699600 time 5 pv e2e4 d7d5 e4d5 g8f6 d2d4 c7c6 d5c6
info depth 8 multipv 1 score cp 20 nodes 12664 nps 1809142 time 7 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 b1c3 c7c6
info depth 9 multipv 1 score cp 40 nodes 38125 nps 1906250 time 20 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 g8f6 d4d5
info depth 10 multipv 1 score cp 27 nodes 58841 nps 1898096 time 31 pv e2e4 c7c5 b1c3 b8c6 g1f3 e7e6 f1b5 d7d5 b5c6 b7c6 e1g1
info depth 11 multipv 1 score cp 39 nodes 120239 nps 1939338 time 62 pv e2e4 c7c5 g1f3 e7e6 d2d4 d7d5 e4d5 e6d5 c1e3 c5d4 e3d4
info depth 12 multipv 1 score cp 23 nodes 204378 nps 1965173 time 104 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 d2d3 e7e6 e1g1 a7a6 b5c6
info depth 13 multipv 1 score cp 32 nodes 291635 nps 2011275 time 145 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 d7d5 e4d5 e6d5 d2d3 g8f6 e1g1
info depth 14 multipv 1 score cp 32 nodes 454099 nps 2045490 time 222 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4 h7h6 c1e3 c6d4 d1d4 g8f6
info depth 15 multipv 1 score cp 25 nodes 895212 nps 2096515 time 427 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 d2d3 e7e6 e1g1 f8e7 c2c3 d7d6 e4e5 f6g4 f1e1
info depth 16 multipv 1 score cp 27 nodes 1436173 nps 2105825 time 682 pv e2e4 c7c5 g1f3 b8c6 f1b5 e7e6 e1g1 a7a6 b5c6 d7c6 b1c3 g8f6 e4e5 f6d5 d2d4 c5d4
info depth 17 multipv 1 score cp 33 nodes 3209332 nps 2079930 time 1543 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 b8c6 g1f3 h7h6 f1d3 g8e7 d3e2 e7g6 e1g1 f8e7 a2a3
info depth 18 multipv 1 score cp 25 nodes 6256071 nps 2097944 time 2982 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 e2e3 c7c5 c4d5 e6d5 f1b5 b8c6 e1g1 c8g4 f1e1 f8d6 h2h3 g4f3
info depth 19 multipv 1 score cp 17 nodes 8338303 nps 2086662 time 3996 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 e2e3 c7c5 c4d5 e6d5 f1b5 b8c6 e1g1 c5d4 e3d4 f8e7 b5c6 b7c6 f3e5 e8g8 e5c6
info depth 20 multipv 1 score cp 28 nodes 14326752 nps 2086015 time 6868 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 f8e7 c4d5 e6d5 c1f4 e8g8 e2e3 b8c6 f1d3 c6b4 h2h3 b4d3 d1d3 c7c6 e1g1
info depth 21 multipv 1 score cp 23 nodes 27261351 nps 2095737 time 13008 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 f1d3 b8c6 e1g1 c8g4 f1e1 g4f3 d1f3 c5d4 e3d4 f8e7 c1e3 e8g8
info depth 22 multipv 1 score cp 22 nodes 35063567 nps 2098483 time 16709 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 f1d3 b8c6 e1g1 c8g4 f1e1 f8e7 d4c5 e8g8 d1b3 e7c5 b3b7 g4f3
info depth 23 multipv 1 score cp 27 nodes 54159900 nps 2094431 time 25859 pv d2d4 g8f6 c2c4 d7d5 b1c3 c7c6 e2e3 g7g6 g1f3 f8g7 f1e2 e8g8 e1g1 c8f5 c1d2 b8d7 c4d5 c6d5 d1b3 d8b6 b3b6 d7b6 a1c1
info depth 24 multipv 1 score cp 26 nodes 82327308 nps 2096175 time 39275 pv d2d4 g8f6 c2c4 d7d5 b1c3 d5c4 g1f3 c7c6 e2e4 b7b5 e4e5 f6d5 a2a4 d5c3 b2c3 a7a5 a4b5 c6b5 a1b1 c8d7 f1e2 e7e6 e1g1 h7h6
info depth 25 multipv 1 score cp 29 nodes 156959119 nps 2096562 time 74865 pv d2d4 g8f6 c2c4 d7d5 b1c3 e7e6 g1f3 b8c6 e2e3 f8d6 c4d5 e6d5 f1d3 e8g8 e1g1 f8e8 a2a3 c6e7 f1e1 e7g6 e3e4 d5e4 c3e4 c8e6 h2h3
```

```
Score of ChessDotCpp2.7 vs ChessDotCpp2.6: 267 - 210 - 523  [0.528] 1000
...      ChessDotCpp2.7 playing White: 139 - 100 - 261  [0.539] 500
...      ChessDotCpp2.7 playing Black: 128 - 110 - 262  [0.518] 500
...      White vs Black: 249 - 228 - 523  [0.510] 1000
Elo difference: 19.8 +/- 14.9, LOS: 99.5 %, DrawRatio: 52.3 %

Score of ChessDotCpp2.7 vs supernova: 291 - 115 - 94  [0.676] 500
...      ChessDotCpp2.7 playing White: 151 - 47 - 53  [0.707] 251
...      ChessDotCpp2.7 playing Black: 140 - 68 - 41  [0.645] 249
...      White vs Black: 219 - 187 - 94  [0.532] 500
Elo difference: 127.8 +/- 28.9, LOS: 100.0 %, DrawRatio: 18.8 %

Score of ChessDotCpp2.7 vs greko: 199 - 178 - 123  [0.521] 500
...      ChessDotCpp2.7 playing White: 95 - 96 - 59  [0.498] 250
...      ChessDotCpp2.7 playing Black: 104 - 82 - 64  [0.544] 250
...      White vs Black: 177 - 200 - 123  [0.477] 500
Elo difference: 14.6 +/- 26.5, LOS: 86.0 %, DrawRatio: 24.6 %

Score of ChessDotCpp2.7 vs glaurung: 153 - 241 - 106  [0.412] 500
...      ChessDotCpp2.7 playing White: 77 - 124 - 50  [0.406] 251
...      ChessDotCpp2.7 playing Black: 76 - 117 - 56  [0.418] 249
...      White vs Black: 194 - 200 - 106  [0.494] 500
Elo difference: -61.8 +/- 27.4, LOS: 0.0 %, DrawRatio: 21.2 %
```

### 2.8

Tempo eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 29 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 173 nps 173000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 26 nodes 311 nps 311000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 29 nodes 1173 nps 1173000 time 1 pv d2d4 e7e6 g1f3 d7d5 e2e3
info depth 6 multipv 1 score cp 29 nodes 2050 nps 1025000 time 2 pv d2d4 b8c6 e2e3 d7d5 g1f3 e7e6
info depth 7 multipv 1 score cp 47 nodes 8298 nps 1659600 time 5 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4
info depth 8 multipv 1 score cp 39 nodes 11965 nps 1709285 time 7 pv e2e4 e7e5 b1c3 b8c6 g1f3 f8c5 c3d5 c5b6
info depth 9 multipv 1 score cp 30 nodes 19484 nps 1771272 time 11 pv e2e4 e7e5 d2d4 e5d4 c2c3 b8c6 c3d4 d7d5 e4d5
info depth 10 multipv 1 score cp 28 nodes 36958 nps 1847900 time 20 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6
info depth 11 multipv 1 score cp 19 nodes 116606 nps 2045719 time 57 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c6 f1d3 g8f6 c2c3 f8d6 e1g1
info depth 12 multipv 1 score cp 25 nodes 243111 nps 2009181 time 121 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8e7 f1e2 e8g8
info depth 13 multipv 1 score cp 29 nodes 339459 nps 2057327 time 165 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8
info depth 14 multipv 1 score cp 25 nodes 554547 nps 2069205 time 268 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 f8c5 c1e3 c6d4 e3d4 c5d4 d1d4 g8f6
info depth 15 multipv 1 score cp 19 nodes 1435303 nps 2065184 time 695 pv d2d4 d7d5 g1f3 g8f6 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 f1e2 c5d4 e3d4 f8d6 b1c3
info depth 16 multipv 1 score cp 24 nodes 2100073 nps 2087547 time 1006 pv d2d4 d7d5 g1f3 g8f6 c2c4 e7e6 b1c3 f8e7 c4d5 e6d5 e2e3 c7c5 d4c5 b8c6 f1d3 e7c5
info depth 17 multipv 1 score cp 23 nodes 3191236 nps 2103649 time 1517 pv d2d4 d7d5 g1f3 g8f6 c2c4 e7e6 e2e3 c7c6 f1d3 d5c4 d3c4 f8d6 e1g1 e8g8 b1c3 f8e8 c4d3
info depth 18 multipv 1 score cp 24 nodes 5989257 nps 2158290 time 2775 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 e2e3 h7h6 b1c3 c7c5 c4d5 e6d5 f1e2 c5d4 f3d4 b8c6 e1g1 f8d6
info depth 19 multipv 1 score cp 25 nodes 8499717 nps 2169955 time 3917 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c6 e2e3 h7h6 f1d3 d5c4 d3c4 f8d6 c4d3 e8g8 e1g1 f8e8 f1e1
info depth 20 multipv 1 score cp 22 nodes 15647775 nps 2137674 time 7320 pv d2d4 d7d5 c2c4 c7c6 g1f3 g8f6 c4d5 c6d5 b1c3 b8c6 c1f4 c8f5 e2e3 e7e6 a1c1 f8d6 f4d6 d8d6 f1d3 f5d3
info depth 21 multipv 1 score cp 22 nodes 22663163 nps 2164374 time 10471 pv d2d4 d7d5 c2c4 c7c6 g1f3 g8f6 c4d5 c6d5 b1c3 b8c6 c1f4 c8f5 e2e3 e7e6 a1c1 f8d6 f4d6 d8d6 f1d3 f5d3
info depth 22 multipv 1 score cp 35 nodes 42626835 nps 2183192 time 19525 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 b8c6 e2e3 a7a6 a2a3 g7g6 f1d3 f8g7 e1g1 e8g8 f1e1 h7h6 h2h3 d5c4 d3c4
info depth 23 multipv 1 score cp 33 nodes 64750819 nps 2175693 time 29761 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 b8c6 e2e3 a7a6 h2h3 h7h6 c4d5 e6d5 f1d3 f8d6 a2a3 e8g8 e1g1 f8e8 d1b3 c8e6 b3b7
info depth 24 multipv 1 score cp 32 nodes 91744377 nps 2179719 time 42090 pv d2d4 d7d5 c2c4 e7e6 b1c3 c7c5 c4d5 e6d5 g1f3 c5d4 f3d4 g8f6 c1f4 f8e7 e2e3 e8g8 f1d3 b8c6 d4c6 b7c6 e1g1 c8e6 h2h3 a8c8
info depth 25 multipv 1 score cp 31 nodes 169460585 nps 2173017 time 77984 pv d2d4 d7d5 c2c4 e7e6 b1c3 c7c5 c4d5 e6d5 g1f3 c5d4 d1d4 g8f6 c1g5 b8c6 g5f6 c6d4 f6d8 d4c2 e1d2 c2a1 d8h4 c8d7 e2e3 f8e7 c3d5 e7h4
```

```
Score of ChessDotCpp2.8 vs ChessDotCpp2.7: 247 - 227 - 526  [0.510] 1000
...      ChessDotCpp2.8 playing White: 142 - 103 - 255  [0.539] 500
...      ChessDotCpp2.8 playing Black: 105 - 124 - 271  [0.481] 500
...      White vs Black: 266 - 208 - 526  [0.529] 1000
Elo difference: 6.9 +/- 14.8, LOS: 82.1 %, DrawRatio: 52.6 %
```

### 2.9

Passed doubled pawn eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 29 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 173 nps 173000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 27 nodes 310 nps 310000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 32 nodes 1169 nps 1169000 time 1 pv d2d4 e7e6 g1f3 d7d5 e2e3
info depth 6 multipv 1 score cp 31 nodes 2012 nps 1006000 time 2 pv d2d4 b8c6 g1f3 d7d5 e2e3 e7e6
info depth 7 multipv 1 score cp 36 nodes 8120 nps 1624000 time 5 pv e2e4 e7e6 g1f3 d7d5 e4e5 d5d4 c2c3
info depth 8 multipv 1 score cp 30 nodes 15410 nps 1712222 time 9 pv e2e4 e7e5 g1f3 b8c6 b1c3 a7a6 d2d4 e5d4
info depth 9 multipv 1 score cp 31 nodes 22336 nps 1718153 time 13 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4
info depth 10 multipv 1 score cp 28 nodes 34929 nps 1838368 time 19 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6
info depth 11 multipv 1 score cp 16 nodes 66858 nps 1910228 time 35 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 b1c3 g8f6 c1f4 b8c6 g1f3
info depth 12 multipv 1 score cp 27 nodes 108380 nps 1970545 time 55 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 b8c6 c1f4 g8f6 c2c3 c8e6
info depth 13 multipv 1 score cp 30 nodes 281293 nps 2053233 time 137 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 c6d4 d1d4 c7c6 c1e3
info depth 14 multipv 1 score cp 30 nodes 461703 nps 2089153 time 221 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8 e8d8 f1d3
info depth 15 multipv 1 score cp 23 nodes 684806 nps 2107095 time 325 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8 e8d8 f1d3 c8e6
info depth 16 multipv 1 score cp 21 nodes 1352856 nps 2120463 time 638 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 b7c6 f1d3 b4c3 b2c3 d7d5 e4d5
info depth 17 multipv 1 score cp 25 nodes 3484888 nps 2131429 time 1635 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c6 c2c4 f8d6 c4c5 d6c7 f1d3 g8f6 e1g1 e8g8 b1c3 f8e8 f1e1
info depth 18 multipv 1 score cp 27 nodes 5224674 nps 2158956 time 2420 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 c5d4 e3d4 b8c6 c4d5 e6d5 f1d3 c8g4 b1c3 g8f6 c1e3 h7h6
info depth 19 multipv 1 score cp 26 nodes 7676813 nps 2161264 time 3552 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 g8f6 c4d5 e6d5 f1d3 c5d4 e3d4 f8d6 e1g1 e8g8 f1e1 f8e8 b1c3
info depth 20 multipv 1 score cp 27 nodes 11857297 nps 2148061 time 5520 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 g8f6 c4d5 e6d5 b1c3 c5d4 e3d4 f8d6 c1g5 c8e6 g5f6 d8f6 c3b5 d6b4 b5c3
info depth 21 multipv 1 score cp 23 nodes 19372636 nps 2145839 time 9028 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 g8f6 c4d5 e6d5 b1c3 c5d4 e3d4 b8c6 f1d3 f8d6 e1g1 e8g8 c3b5 f8e8 b5d6
info depth 22 multipv 1 score cp 26 nodes 27154520 nps 2135628 time 12715 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 g8f6 c4d5 e6d5 b1c3 c5d4 e3d4 b8c6 f1d3 f8d6 e1g1 e8g8 c3b5 c6b4 b5d6
info depth 23 multipv 1 score cp 28 nodes 42160557 nps 2136334 time 19735 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 g8f6 c4d5 e6d5 b1c3 c5d4 e3d4 b8c6 f1d3 f8d6 e1g1 e8g8 c3b5 c6b4 b5d6 d8d6 c1e3
info depth 24 multipv 1 score cp 28 nodes 144631270 nps 2157387 time 67040 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 a7a6 e2e3 c7c5 c4d5 e6d5 f1d3 b8c6 a2a3 c8g4 d4c5 f8c5 e1g1 e8g8 c1d2 c5d6 h2h3 g4f3
info depth 25 multipv 1 score cp 26 nodes 179485271 nps 2152230 time 83395 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 a7a6 e2e3 c7c5 c4d5 e6d5 f1d3 b8c6 e1g1 c5c4 d3c2 f8d6 a2a3 e8g8 h2h3 c6e7 f3e5 c8f5
```

```
Score of ChessDotCpp2.9 vs ChessDotCpp2.8: 235 - 213 - 552  [0.511] 1000
...      ChessDotCpp2.9 playing White: 122 - 99 - 278  [0.523] 499
...      ChessDotCpp2.9 playing Black: 113 - 114 - 274  [0.499] 501
...      White vs Black: 236 - 212 - 552  [0.512] 1000
Elo difference: 7.6 +/- 14.4, LOS: 85.1 %, DrawRatio: 55.2 %
```

### 2.10

Bishop on same color square pawn eval

```
info depth 1 multipv 1 score cp 17 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 27 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 17 nodes 173 nps 173000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 24 nodes 313 nps 313000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 26 nodes 1181 nps 1181000 time 1 pv d2d4 e7e6 g1f3 d7d5 b1c3
info depth 6 multipv 1 score cp 24 nodes 1853 nps 926500 time 2 pv d2d4 e7e6 g1f3 b8c6 e2e3 d7d5
info depth 7 multipv 1 score cp 33 nodes 7582 nps 1516400 time 5 pv e2e4 e7e6 d2d4 d7d5 e4e5 b8c6 g1f3
info depth 8 multipv 1 score cp 42 nodes 10893 nps 1556142 time 7 pv e2e4 e7e6 d2d4 d7d5 e4e5 c8d7 g1f3 b8c6
info depth 9 multipv 1 score cp 30 nodes 20886 nps 1740500 time 12 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4
info depth 10 multipv 1 score cp 27 nodes 32430 nps 1907647 time 17 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6
info depth 11 multipv 1 score cp 26 nodes 74187 nps 2005054 time 37 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 g8f6 f1e2 b8c6 e1g1
info depth 12 multipv 1 score cp 18 nodes 117264 nps 2057263 time 57 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 g8f6 f1e2 e7e6 c2c3 f8d6
info depth 13 multipv 1 score cp 31 nodes 220186 nps 2117173 time 104 pv e2e4 d7d5 e4d5 c7c6 d5c6 b8c6 f1d3 e7e5 g1f3 g8f6 b1c3 f8c5 e1g1
info depth 14 multipv 1 score cp 28 nodes 474456 nps 2137189 time 222 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 e5d4 f3d4 f8b4 d4f5 e8g8 f1d3 d7d5
info depth 15 multipv 1 score cp 15 nodes 775826 nps 2167111 time 358 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 d2d4 e5d4 f3d4 f8b4 d4c6 b4c3 b2c3 b7c6 f1d3 e8g8
info depth 16 multipv 1 score cp 17 nodes 1220391 nps 2167657 time 563 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1c4 f8c5 e1g1 d7d6 d2d3 e8g8 a2a3 a7a6 f1e1 f8e8
info depth 17 multipv 1 score cp 24 nodes 3074317 nps 2055024 time 1496 pv g1f3 d7d5 e2e3 e7e6 d2d4 g8f6 c2c4 c7c6 f1d3 d5c4 d3c4 f8d6 e1g1 e8g8 c4d3 f8e8 b1c3
info depth 18 multipv 1 score cp 24 nodes 4370138 nps 2078049 time 2103 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 b8c6 c4d5 e6d5 f1d3 c8g4 d4c5 g8f6 e1g1 g4f3 d1f3 f8c5
info depth 19 multipv 1 score cp 25 nodes 6804093 nps 2090351 time 3255 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 b8c6 c4d5 e6d5 f1d3 c8g4 d4c5 g8f6 e1g1 f8c5 b1c3 e8g8 c1d2
info depth 20 multipv 1 score cp 26 nodes 10647129 nps 2085627 time 5105 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 b8c6 c4d5 e6d5 f1d3 c8g4 d4c5 g8f6 e1g1 f8c5 b1c3 e8g8 c1d2 f8e8
info depth 21 multipv 1 score cp 22 nodes 19571697 nps 2102900 time 9307 pv g1f3 d7d5 e2e3 e7e6 d2d4 c7c5 c2c4 b8c6 c4d5 e6d5 f1d3 g8f6 e1g1 c5c4 d3c2 f8d6 b1c3 c6b4 c2a4 c8d7 c3b5 d7b5
info depth 22 multipv 1 score cp 25 nodes 37008798 nps 2115271 time 17496 pv g1f3 d7d5 e2e3 c8f5 c2c4 c7c6 d1b3 d8c7 c4d5 c6d5 f1b5 f5d7 b1c3 e7e6 d2d4 g8f6 e1g1 b8c6 b5d3 a7a6 c1d2 c6b4 c3b5
info depth 23 multipv 1 score cp 25 nodes 58032982 nps 2114596 time 27444 pv g1f3 g8f6 d2d4 d7d5 c2c4 c7c6 c1f4 d5c4 e2e3 b7b5 f1e2 e7e6 e1g1 f8e7 b2b3 c4b3 a2b3 e8g8 b1d2 c8b7 f1e1 b8d7 e2d3
info depth 24 multipv 1 score cp 29 nodes 142319929 nps 2110851 time 67423 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 b1c3 c7c5 e2e3 c5d4 e3d4 b8c6 c4d5 e6d5 f1d3 f8d6 e1g1 e8g8 c3b5 d6b8 f1e1 a7a6 b5c3 f8e8
info depth 25 multipv 1 score cp 28 nodes 180329684 nps 2094372 time 86102 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 b1c3 a7a6 e2e3 c7c5 c4d5 e6d5 f1d3 b8c6 e1g1 f8d6 d4c5 d6c5 c1d2 e8g8 c3e2 f6e4 a1c1 c5e7 e2g3
```

```
Score of ChessDotCpp2.10 vs ChessDotCpp2.9: 245 - 217 - 538  [0.514] 1000
...      ChessDotCpp2.10 playing White: 131 - 103 - 266  [0.528] 500
...      ChessDotCpp2.10 playing Black: 114 - 114 - 272  [0.500] 500
...      White vs Black: 245 - 217 - 538  [0.514] 1000
Elo difference: 9.7 +/- 14.6, LOS: 90.4 %, DrawRatio: 53.8 %

Score of ChessDotCpp2.10 vs greko: 220 - 157 - 123  [0.563] 500
...      ChessDotCpp2.10 playing White: 115 - 79 - 56  [0.572] 250
...      ChessDotCpp2.10 playing Black: 105 - 78 - 67  [0.554] 250
...      White vs Black: 193 - 184 - 123  [0.509] 500
Elo difference: 44.0 +/- 26.6, LOS: 99.9 %, DrawRatio: 24.6 %
```

### 2.11

Blocked passed pawn eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 26 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 183 nps 183000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 23 nodes 323 nps 323000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 13 nodes 1337 nps 668500 time 2 pv d2d4 d7d5 b1c3 e7e6 e2e3
info depth 6 multipv 1 score cp 13 nodes 4479 nps 1493000 time 3 pv g1f3 d7d5 d2d4 e7e6 b1c3 g8f6
info depth 7 multipv 1 score cp 34 nodes 9453 nps 1575500 time 6 pv e2e4 e7e6 d2d4 d7d5 e4e5 b8c6 g1f3
info depth 8 multipv 1 score cp 18 nodes 13727 nps 1525222 time 9 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 g8f6
info depth 9 multipv 1 score cp 29 nodes 21074 nps 1621076 time 13 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4
info depth 10 multipv 1 score cp 26 nodes 29414 nps 1730235 time 17 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6
info depth 11 multipv 1 score cp 24 nodes 61955 nps 1877424 time 33 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 g8f6 f1e2 b8c6 e1g1
info depth 12 multipv 1 score cp 29 nodes 123058 nps 1984806 time 62 pv e2e4 c7c5 b1c3 b8c6 d2d3 g8f6 g1f3 d7d5 e4d5 f6d5 c3d5
info depth 13 multipv 1 score cp 31 nodes 197149 nps 2053635 time 96 pv e2e4 c7c5 b1c3 b8c6 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 d4c6 d7c6 d1d8
info depth 14 multipv 1 score cp 23 nodes 470160 nps 2108340 time 223 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8 e8d8 f1d3
info depth 15 multipv 1 score cp 21 nodes 974261 nps 2141232 time 455 pv d2d4 g8f6 e2e3 e7e6 g1f3 d7d5 c2c4 c7c5 c4d5 e6d5 f1e2 c5d4 e3d4 b8c6 e1g1
info depth 16 multipv 1 score cp 15 nodes 1625986 nps 2142274 time 759 pv d2d4 g8f6 e2e3 e7e6 g1f3 d7d5 c2c4 c7c5 c4d5 e6d5 f1d3 c5d4 e3d4 b8c6 b1c3 f8d6
info depth 17 multipv 1 score cp 18 nodes 2615936 nps 2147730 time 1218 pv d2d4 g8f6 e2e3 e7e6 g1f3 d7d5 c2c4 b8c6 f1d3 d5c4 d3c4 f8d6 b1c3 e8g8 e1g1 c6b4 f1e1
info depth 18 multipv 1 score cp 22 nodes 4455648 nps 2125786 time 2096 pv d2d4 g8f6 e2e3 d7d5 g1f3 e7e6 c2c4 c7c5 c4d5 e6d5 f1d3 h7h6 e1g1 b8c6 b1c3 c5d4 f3d4 f8d6
info depth 19 multipv 1 score cp 23 nodes 10452429 nps 2147612 time 4867 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 c8f5 e2e3 e7e6 b1d2 f8e7 f1b5 b8d7 a1c1 a7a6 b5d7 d8d7 e1g1
info depth 20 multipv 1 score cp 23 nodes 12830118 nps 2144787 time 5982 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 c8f5 e2e3 b8c6 b1c3 e7e6 a1c1 f8d6 f4d6 d8d6 f1d3 f5d3
info depth 21 multipv 1 score cp 23 nodes 17332937 nps 2148089 time 8069 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 c8f5 e2e3 b8c6 b1c3 e7e6 a1c1 f8d6 f4d6 d8d6 f1d3 f5d3
info depth 22 multipv 1 score cp 16 nodes 27988258 nps 2127252 time 13157 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 c8f5 e2e3 b8c6 f1d3 f5d3 d1d3 e7e6 b1d2 f8d6 f4d6 d8d6 e1g1 e8g8
info depth 23 multipv 1 score cp 16 nodes 57331295 nps 2109862 time 27173 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 b8c6 e2e3 c8f5 f1d3 f5d3 d1d3 e7e6 b1d2 f8d6 f4d6 d8d6 a1c1 e8g8 e1g1
info depth 24 multipv 1 score cp 25 nodes 114910626 nps 2121883 time 54155 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 b8c6 e2e3 c8f5 f1d3 f5d3 d1d3 e7e6 b1d2 f8d6 f4d6 d8d6 a1c1 e8c8 e1g1 d6c7
info depth 25 multipv 1 score cp 26 nodes 184375666 nps 2122676 time 86860 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 b8c6 e2e3 c8f5 d1b3 d8b6 b3b6 a7b6 b1c3 e7e6 f1e2 h7h6 e1g1 f8e7 f3h4 f5h7 h4f3
```

```
info depth 1 multipv 1 score cp 14 nodes 29231 nps 2924200 time 10 pv e2e4 e7e5 d2d4 e5d4 g1f3 g8f6 d1d4 d7d5
info depth 2 multipv 1 score cp 14 nodes 33519 nps 3352800 time 10 pv e2e4 e7e5 b1c3 b8c6 g1f3 f8c5 f1b5 g8f6
info depth 3 multipv 1 score cp 14 nodes 36794 nps 3680200 time 10 pv e2e4 e7e5 b1c3 b8c6 g1f3 f8c5 f1b5 g8f6
info depth 4 multipv 1 score cp 11 nodes 39516 nps 3592909 time 11 pv d2d4 g8f6 b1c3 d7d5 e2e3 e7e6 g1f3 b8c6
info depth 5 multipv 1 score cp 11 nodes 42065 nps 3824818 time 11 pv d2d4 g8f6 b1c3 d7d5 e2e3 e7e6 g1f3 b8c6
info depth 6 multipv 1 score cp 11 nodes 44515 nps 4047181 time 11 pv d2d4 g8f6 b1c3 d7d5 c1f4 e7e6 e2e3 b8c6 g1f3
info depth 7 multipv 1 score cp 11 nodes 48326 nps 4393727 time 11 pv d2d4 g8f6 b1c3 d7d5 c1f4 e7e6 e2e3 b8c6 g1f3
info depth 8 multipv 1 score cp 11 nodes 50722 nps 4611272 time 11 pv b1c3 d7d5 d2d4 g8f6 c1f4 e7e6 e2e3 b8c6 g1f3
info depth 9 multipv 1 score cp 27 nodes 84826 nps 6059500 time 14 pv e2e4 e7e5 d2d4 e5d4 d1d4 b8c6 d4d1 f8c5 b1c3 g8f6
info depth 10 multipv 1 score cp 26 nodes 122860 nps 7227352 time 17 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6
info depth 11 multipv 1 score cp 18 nodes 522155 nps 10878583 time 48 pv d2d4 d7d5 e2e3 e7e6 g1f3 f8e7 c2c4 g8f6 c4d5 e6d5
info depth 12 multipv 1 score cp 32 nodes 894862 nps 11621662 time 77 pv e2e4 c7c5 g1f3 e7e6 d2d4 d7d5 b1c3 c5d4 f1b5 c8d7 f3d4 e6e5 b5d7 b8d7 d4f5 d5d4
info depth 13 multipv 1 score cp 32 nodes 938480 nps 11586246 time 81 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8
info depth 14 multipv 1 score cp 23 nodes 1239895 nps 11922211 time 104 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8 e8d8 f1d3 c8e6
info depth 15 multipv 1 score cp 22 nodes 2709107 nps 12370378 time 219 pv d2d4 d7d5 e2e3 e7e6 c2c4 c7c5 g1f3 b8c6 c4d5 e6d5 f1d3 c5d4 e3d4 g8f6 b1c3 f8d6
info depth 16 multipv 1 score cp 19 nodes 4510357 nps 12528794 time 360 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 e5d4 f3d4 f8b4 d4c6 d7c6 d1d8 e8d8 c1d2 h8e8 f1d3 c8e6
info depth 17 multipv 1 score cp 17 nodes 8191623 nps 12583144 time 651 pv g1f3 d7d5 d2d4 c8f5 c2c4 e7e6 c4d5 e6d5 e2e3 c7c6 f1d3 f5d3 d1d3 g8f6 e1g1 f8d6 c1d2
info depth 18 multipv 1 score cp 25 nodes 17791478 nps 12708204 time 1400 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 e2e3 b8c6 a2a3 a7a6 b1c3 f8d6 c4c5 d6e7 f1d3 e8g8 e1g1 h7h6 h2h3
info depth 19 multipv 1 score cp 25 nodes 23221848 nps 12696475 time 1829 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c6 e2e3 h7h6 f1d3 f8d6 c4c5 d6c7 e1g1 e8g8 c1d2 f8e8 a1c1 c8d7
info depth 20 multipv 1 score cp 21 nodes 42761298 nps 12681288 time 3372 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 h7h6 e2e3 a7a6 h2h3 b8c6 a2a3 f8e7 c1d2 f6e4 f1d3 e4d2 f3d2 e8g8 c4d5
info depth 21 multipv 1 score cp 25 nodes 63189504 nps 12688656 time 4980 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 c7c5 c4d5 c5d4 d1a4 c8d7 a4d4 e6d5 c3d5 d8a5 d5c3 b8c6 d4d2 e8c8 e2e4 d7e6 f1d3 f8e7
info depth 22 multipv 1 score cp 26 nodes 131958295 nps 12568654 time 10499 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c5 e2e3 b8c6 c4d5 e6d5 f1d3 f8d6 e1g1 c5c4 d3c2 c6b4 c2a4 c8d7 a2a3 b4d3 c3b5 d7b5
info depth 23 multipv 1 score cp 27 nodes 247917498 nps 12321943 time 20120 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 a7a6 e2e3 h7h6 c4d5 e6d5 f1d3 f8d6 h2h3 e8g8 e1g1 b8c6 a2a3 f8e8 f1e1 c6e7 c1d2 e7g6
info depth 24 multipv 1 score cp 25 nodes 406054625 nps 12336461 time 32915 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 c8f5 e2e3 b8c6 d1b3 d8b6 f1b5 e7e6 e1g1 f8e7 f3h4 f5g6 b1d2 b6a5 d2f3 e8g8 h4g6
info depth 25 multipv 1 score cp 24 nodes 751526781 nps 12406550 time 60575 pv d2d4 g8f6 c2c4 c7c6 b1c3 d7d5 c4d5 c6d5 g1f3 c8f5 c1f4 e7e6 d1b3 d8b6 e2e3 b8c6 b3b6 a7b6 f1e2 f8b4 e1g1 e8g8 a2a3 b4c3 b2c3 h7h6
info depth 26 multipv 1 score cp 24 nodes 929392924 nps 12424374 time 74804 pv d2d4 g8f6 c2c4 c7c6 b1c3 d7d5 c4d5 c6d5 g1f3 c8f5 d1b3 e7e6 b3b7 b8d7 c1f4 f6h5 f4e5 f7f6 e5c7 d8c8 b7c8 a8c8 c7g3 h5g3 h2g3 c8b8 e2e4 d5e4
```

```
Score of ChessDotCpp2.11 vs ChessDotCpp2.10: 367 - 338 - 795  [0.510] 1500
...      ChessDotCpp2.11 playing White: 195 - 165 - 390  [0.520] 750
...      ChessDotCpp2.11 playing Black: 172 - 173 - 405  [0.499] 750
...      White vs Black: 368 - 337 - 795  [0.510] 1500
Elo difference: 6.7 +/- 12.0, LOS: 86.3 %, DrawRatio: 53.0 %

Score of ChessDotCpp2.11 vs wyldchess: 136 - 28 - 36  [0.770] 200
...      ChessDotCpp2.11 playing White: 71 - 9 - 19  [0.813] 99
...      ChessDotCpp2.11 playing Black: 65 - 19 - 17  [0.728] 101
...      White vs Black: 90 - 74 - 36  [0.540] 200
Elo difference: 209.9 +/- 50.0, LOS: 100.0 %, DrawRatio: 18.0 %

Score of ChessDotCpp2.11 vs greko: 260 - 144 - 96  [0.616] 500
...      ChessDotCpp2.11 playing White: 131 - 68 - 51  [0.626] 250
...      ChessDotCpp2.11 playing Black: 129 - 76 - 45  [0.606] 250
...      White vs Black: 207 - 197 - 96  [0.510] 500
Elo difference: 82.1 +/- 28.0, LOS: 100.0 %, DrawRatio: 19.2 %

Score of ChessDotCpp2.11 vs glaurung: 502 - 642 - 356  [0.453] 1500
...      ChessDotCpp2.11 playing White: 230 - 326 - 194  [0.436] 750
...      ChessDotCpp2.11 playing Black: 272 - 316 - 162  [0.471] 750
...      White vs Black: 546 - 598 - 356  [0.483] 1500
Elo difference: -32.5 +/- 15.4, LOS: 0.0 %, DrawRatio: 23.7 %
```

### 2.12

Improve performance for multithreaded search

12CPU:
```
info depth 1 multipv 1 score cp 18 nodes 1 nps 3717300 time 10 pv e2e4 e7e6 b1c3 b8c6 d2d4 a7a6 e4e5 d7d5 g1f3
info depth 2 multipv 1 score cp 18 nodes 2 nps 4202300 time 10 pv e2e4 e7e6 d2d4 d7d5 b1c3 a7a6 e4d5 e6d5 g1f3
info depth 3 multipv 1 score cp 18 nodes 3 nps 4465200 time 10 pv e2e4 e7e6 d2d4 d7d5 b1c3 a7a6 e4d5 e6d5 g1f3
info depth 4 multipv 1 score cp 18 nodes 4 nps 4831700 time 10 pv e2e4 e7e6 d2d4 d7d5 b1c3 a7a6 e4d5 e6d5 g1f3
info depth 5 multipv 1 score cp 18 nodes 5 nps 5174400 time 10 pv e2e4 e7e6 d2d4 d7d5 b1c3 a7a6 e4d5 e6d5 g1f3
info depth 6 multipv 1 score cp 33 nodes 6 nps 5092909 time 11 pv e2e4 e7e6 d2d4 d7d5 b1c3 a7a6 e4d5 e6d5 g1f3 g8f6
info depth 7 multipv 1 score cp 33 nodes 7 nps 5430727 time 11 pv e2e4 e7e6 d2d4 d7d5 b1c3 a7a6 e4e5 b8c6 g1f3 g8e7
info depth 8 multipv 1 score cp 33 nodes 8 nps 5750818 time 11 pv e2e4 d7d5 e4d5 g8f6 b1c3 c7c6 d2d4 c6d5 g1f3
info depth 9 multipv 1 score cp 30 nodes 1145 nps 6776750 time 12 pv e2e4 d7d5 e4d5 g8f6 g1f3 f6d5 d2d4 e7e6 b1c3 d5c3
info depth 10 multipv 1 score cp 25 nodes 2889 nps 8027000 time 13 pv e2e4 d7d5 e4d5 g8f6 g1f3 f6d5 d2d4 c7c6 c1g5 d5f6 b1c3
info depth 11 multipv 1 score cp 32 nodes 17500 nps 13001095 time 21 pv e2e4 c7c5 g1f3 b8c6 d2d3 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5
info depth 12 multipv 1 score cp 28 nodes 29443 nps 14323344 time 29 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8
info depth 13 multipv 1 score cp 22 nodes 50803 nps 15959097 time 41 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 d7c6 d1d8 e8d8 f1d3
info depth 14 multipv 1 score cp 23 nodes 84664 nps 17233163 time 61 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4 f8b4 d4c6 d7c6 d1d8 e8d8 f1d3 c8e6
info depth 15 multipv 1 score cp 22 nodes 215564 nps 18386285 time 147 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 c7c5 c4d5 f6d5 c1g5 d5c3 b2c3 f8e7 g5e7
info depth 16 multipv 1 score cp 16 nodes 299937 nps 18493863 time 198 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 b8c6 e2e3 f8e7 c4d5 e6d5 f1e2 c6b4 e1g1 c7c6 c1d2
info depth 17 multipv 1 score cp 17 nodes 500182 nps 18710378 time 312 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 b8c6 e2e3 a7a6 h2h3 f8e7 f1e2 e8g8 e1g1 f6e4 c4d5 e6d5
info depth 18 multipv 1 score cp 24 nodes 1059258 nps 18708371 time 663 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 b8c6 a2a3 f8e7 e2e3 f6e4 c4d5 e6d5 f1d3 c8f5 e1g1 e4c3
info depth 19 multipv 1 score cp 23 nodes 1500635 nps 18709995 time 935 pv d2d4 g8f6 c2c4 e7e6 b1c3 d7d5 g1f3 b8c6 a2a3 f8e7 e2e3 f6e4 c4d5 e6d5 f1d3 e4c3 b2c3 e8g8 e1g1 c8e6
info depth 20 multipv 1 score cp 23 nodes 3144047 nps 18469983 time 2008 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 b1c3 c6d5 g1f3 b8c6 c1f4 c8f5 e2e3 e7e6 a1c1 f8d6 f4d6 d8d6 f1d3 f5d3
info depth 21 multipv 1 score cp 23 nodes 5333417 nps 18260627 time 3465 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 g1f3 c6d5 c1f4 c8f5 e2e3 b8c6 f1d3 f5d3 d1d3 e7e6 b1d2 f8d6 f4d6 d8d6 e1g1 e8g8
info depth 22 multipv 1 score cp 23 nodes 14830071 nps 18119586 time 9692 pv d2d4 d7d5 g1f3 c8f5 c2c4 c7c6 b1c3 e7e6 c1f4 f8d6 f4d6 d8d6 c4c5 d6c7 e2e3 g8f6 f1d3 e8g8 d3f5 e6f5 e1g1 b8d7 f1e1
info depth 23 multipv 1 score cp 22 nodes 29151098 nps 18000105 time 19190 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8e7 e2e3 e8g8 f1d3 b8c6 e1g1 c6d4 e3d4 c8g4 d3e2 g4d7
info depth 24 multipv 1 score cp 23 nodes 35498120 nps 17948289 time 23405 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8e7 e2e3 e8g8 f1d3 b8c6 d4c6 b7c6 a1c1 c8e6 e1g1 a8c8 h2h3
info depth 25 multipv 1 score cp 24 nodes 58734514 nps 17625637 time 39632 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 c1f4 c8f5 e2e3 b8c6 f1d3 f5d3 d1d3 e7e6 g1f3 g8f6 e1g1 f8d6 f4d6 d8d6 b1d2 e8c8 a1c1 h7h6
info depth 26 multipv 1 score cp 24 nodes 94766167 nps 17638584 time 64252 pv d2d4 d7d5 c2c4 c7c6 g1f3 g8f6 c4d5 c6d5 b1c3 b8c6 c1g5 e7e6 a1c1 c8d7 e2e3 f8e7 f1e2 e8g8 e1g1 a7a6 a2a3 h7h6 g5f4 f6h5 f4g3 h5g3
```

```
Score of ChessDotCpp2.12-12CPU vs ChessDotCpp2.11: 80 - 45 - 175  [0.558] 300
...      ChessDotCpp2.12-12CPU playing White: 36 - 20 - 94  [0.553] 150
...      ChessDotCpp2.12-12CPU playing Black: 44 - 25 - 81  [0.563] 150
...      White vs Black: 61 - 64 - 175  [0.495] 300
Elo difference: 40.7 +/- 25.3, LOS: 99.9 %, DrawRatio: 58.3 %

Score of ChessDotCpp2.12-12CPU vs glaurung: 128 - 34 - 38  [0.735] 200
...      ChessDotCpp2.12-12CPU playing White: 63 - 17 - 20  [0.730] 100
...      ChessDotCpp2.12-12CPU playing Black: 65 - 17 - 18  [0.740] 100
...      White vs Black: 80 - 82 - 38  [0.495] 200
Elo difference: 177.2 +/- 47.9, LOS: 100.0 %, DrawRatio: 19.0 %
```

### 2.12.1

Fix bug with bishop on same color square pawn eval

```
Score of ChessDotCpp2.12.1 vs ChessDotCpp2.12: 2383 - 2386 - 5231  [0.500] 10000
...      ChessDotCpp2.12.1 playing White: 1218 - 1181 - 2601  [0.504] 5000
...      ChessDotCpp2.12.1 playing Black: 1165 - 1205 - 2630  [0.496] 5000
...      White vs Black: 2423 - 2346 - 5231  [0.504] 10000
Elo difference: -0.1 +/- 4.7, LOS: 48.3 %, DrawRatio: 52.3 %
```

### 2.13

Pinned piece eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 25 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 173 nps 173000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 23 nodes 313 nps 313000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 27 nodes 1180 nps 1180000 time 1 pv d2d4 e7e6 g1f3 d7d5 b1c3
info depth 6 multipv 1 score cp 24 nodes 1864 nps 932000 time 2 pv d2d4 e7e6 g1f3 b8c6 e2e3 d7d5
info depth 7 multipv 1 score cp 34 nodes 6443 nps 1288600 time 5 pv e2e4 b8c6 d2d4 e7e6 g1f3 d7d5 e4e5
info depth 8 multipv 1 score cp 38 nodes 11378 nps 1625428 time 7 pv e2e4 g8f6 e4e5 f6e4 d2d4 e7e6 b1c3 e4c3
info depth 9 multipv 1 score cp 28 nodes 29565 nps 1739117 time 17 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4
info depth 10 multipv 1 score cp 29 nodes 40381 nps 1835500 time 22 pv e2e4 e7e5 g1f3 b8c6 b1c3 a7a6 d2d4 e5d4 f3d4 g8f6
info depth 11 multipv 1 score cp 21 nodes 70834 nps 1914432 time 37 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 g8f6 f1b5 b8c6 e1g1 c8d7
info depth 12 multipv 1 score cp 30 nodes 104828 nps 2015923 time 52 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 e7e6 c2c3 g8f6 f1e2 f8e7
info depth 13 multipv 1 score cp 29 nodes 166938 nps 2060962 time 81 pv e2e4 d7d5 e4d5 c7c6 d5c6 b8c6 f1d3 e7e5 g1f3 f8c5 e1g1 g8f6 b1c3
info depth 14 multipv 1 score cp 27 nodes 376612 nps 2127751 time 177 pv e2e4 e7e6 d2d4 d7d5 b1c3 f8e7 g1f3 g8f6 e4e5 f6e4 f1d3 e4c3 b2c3 e8g8
info depth 15 multipv 1 score cp 23 nodes 1032344 nps 2168789 time 476 pv g1f3 d7d5 e2e3 e7e6 d2d4 f8d6 c2c4 c7c6 c1d2 g8f6 c4c5 d6c7 f1d3 e8g8 e1g1
info depth 16 multipv 1 score cp 16 nodes 1568034 nps 2177825 time 720 pv g1f3 d7d5 e2e3 e7e6 d2d4 g8f6 c2c4 c7c5 c4d5 e6d5 f1d3 b8c6 b1c3 c5d4 e3d4 f8d6
info depth 17 multipv 1 score cp 20 nodes 3300952 nps 2191867 time 1506 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 e2e3 b8c6 a2a3 a7a6 c4d5 e6d5 f1d3 f8d6 e1g1 e8g8 b1c3
info depth 18 multipv 1 score cp 24 nodes 4975547 nps 2189941 time 2272 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 e2e3 h7h6 b1c3 c7c5 c4d5 e6d5 d4c5 f8c5 f1d3 c5d6 d3e2 b8c6
info depth 19 multipv 1 score cp 24 nodes 7117902 nps 2186759 time 3255 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 e2e3 c7c5 c4d5 e6d5 f1d3 c5d4 e3d4 f8d6 e1g1 e8g8 f1e1 f8e8 b1c3
info depth 20 multipv 1 score cp 24 nodes 10331463 nps 2179633 time 4740 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 e2e3 c7c5 c4d5 e6d5 f1d3 c5d4 e3d4 f8d6 e1g1 b8c6 f1e1 c8e6 b1c3 e8g8 a2a3
info depth 21 multipv 1 score cp 26 nodes 26049701 nps 2167737 time 12017 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 b1c3 a7a6 e2e3 h7h6 c4d5 e6d5 f1d3 f8d6 e1g1 e8g8 c3e2 c7c6 e2g3
info depth 22 multipv 1 score cp 22 nodes 50059090 nps 2152060 time 23261 pv d2d4 d7d5 g1f3 c8f5 c1f4 e7e6 e2e3 g8f6 f1d3 f5d3 d1d3 c7c5 e1g1 c5d4 e3d4 b8c6 b1c3 a8c8 c3e2 f8d6 c2c3 e8g8
info depth 23 multipv 1 score cp 27 nodes 80705254 nps 2141859 time 37680 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 a7a6 e2e3 h7h6 c4d5 e6d5 f1d3 f8d6 e1g1 e8g8 c1d2 b8c6 a2a3 f8e8 h2h3 c8e6 a1c1
info depth 24 multipv 1 score cp 30 nodes 107056711 nps 2139465 time 50039 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 a7a6 e2e3 h7h6 c4d5 e6d5 f1d3 b8c6 e1g1 f8d6 a2a3 e8g8 h2h3 f8e8 c1d2 c6e7 a1c1 e7g6
```

```
Score of ChessDotCpp2.13 vs ChessDotCpp2.12.1: 269 - 226 - 505  [0.521] 1000
...      ChessDotCpp2.13 playing White: 149 - 109 - 243  [0.540] 501
...      ChessDotCpp2.13 playing Black: 120 - 117 - 262  [0.503] 499
...      White vs Black: 266 - 229 - 505  [0.518] 1000
Elo difference: 14.9 +/- 15.1, LOS: 97.3 %, DrawRatio: 50.5 %

Score of ChessDotCpp2.13 vs glaurung: 174 - 225 - 101  [0.449] 500
...      ChessDotCpp2.13 playing White: 93 - 115 - 42  [0.456] 250
...      ChessDotCpp2.13 playing Black: 81 - 110 - 59  [0.442] 250
...      White vs Black: 203 - 196 - 101  [0.507] 500
Elo difference: -35.6 +/- 27.3, LOS: 0.5 %, DrawRatio: 20.2 %
```

### 2.14

Piece protected by pawn eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 26 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 173 nps 173000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 23 nodes 312 nps 312000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 26 nodes 1181 nps 1181000 time 1 pv d2d4 e7e6 g1f3 d7d5 e2e3
info depth 6 multipv 1 score cp 11 nodes 3714 nps 1238000 time 3 pv d2d4 g8f6 g1f3 d7d5 c2c3 c7c6
info depth 7 multipv 1 score cp 36 nodes 11102 nps 1586000 time 7 pv e2e4 d7d5 e4d5 c7c6 d2d4 g8f6 d5c6
info depth 8 multipv 1 score cp 23 nodes 14846 nps 1649555 time 9 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 f1b5 b8c6 g1f3
info depth 9 multipv 1 score cp 32 nodes 23991 nps 1845461 time 13 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4
info depth 10 multipv 1 score cp 25 nodes 33425 nps 1856944 time 18 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 a7a6
info depth 11 multipv 1 score cp 27 nodes 55886 nps 1927103 time 29 pv e2e4 e7e5 g1f3 d7d5 d2d4 e5d4 e4d5 g8f6 f3d4 f6d5 c2c3
info depth 12 multipv 1 score cp 14 nodes 111189 nps 2021618 time 55 pv e2e4 e7e5 d2d4 e5d4 g1f3 b8c6 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3
info depth 13 multipv 1 score cp 20 nodes 275559 nps 2103503 time 131 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 c7c5 c4d5 e6d5 f1b5 b8c6 e1g1 c5d4
info depth 14 multipv 1 score cp 20 nodes 463413 nps 2135543 time 217 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 c7c5 c4d5 e6d5 f1b5 b8c6 e1g1 c5d4 e3d4
info depth 15 multipv 1 score cp 22 nodes 742292 nps 2164116 time 343 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 c7c5 c4d5 e6d5 f1d3 c5d4 e3d4 f8b4 b1c3 b8c6
info depth 16 multipv 1 score cp 20 nodes 1470077 nps 2171457 time 677 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 c7c5 c4d5 e6d5 b1c3 b8c6 f1b5 f8d6 d4c5 d6c5
info depth 17 multipv 1 score cp 22 nodes 2784445 nps 2158484 time 1290 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 c7c6 f1d3 d5c4 d3c4 f8d6 e1g1 e8g8 c4d3 f8e8 b1c3
info depth 18 multipv 1 score cp 21 nodes 5424708 nps 2146698 time 2527 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 b8c6 e2e3 c8f5 f1b5 e7e6 b1d2 f8d6 f4d6
info depth 19 multipv 1 score cp 28 nodes 11063203 nps 2140712 time 5168 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 f1e2 f8b4 c1d2 b4c3 d2c3 d8e7
info depth 20 multipv 1 score cp 23 nodes 16936680 nps 2129328 time 7954 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 b1c3 c6d5 g1f3 b8c6 c1f4 c8f5 a1c1 e7e6 e2e3 f8d6 f4d6 d8d6 f1d3 f5d3
info depth 21 multipv 1 score cp 23 nodes 21360810 nps 2130754 time 10025 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 b1c3 c6d5 g1f3 b8c6 c1f4 c8f5 a1c1 e7e6 e2e3 f8d6 f4d6 d8d6 f1d3 f5d3
info depth 22 multipv 1 score cp 22 nodes 31966098 nps 2127668 time 15024 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 d5c6 b8c6 g1f3 e7e5 d4e5 d8d1 e1d1 f6g4 d1e1 f8c5 e2e3 c8e6 h2h3 g4e5 f3e5 c6e5 b1c3
info depth 23 multipv 1 score cp 20 nodes 63100939 nps 2125111 time 29693 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 b8c6 e2e3 c8f5 b1c3 e7e6 f1e2 f8e7 a1c1 e8g8 e1g1 e7d6 f4g3 a7a6 f1e1
info depth 24 multipv 1 score cp 29 nodes 84119459 nps 2125516 time 39576 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 c4d5 c6d5 c1f4 b8c6 e2e3 c8f5 f1d3 f5d3 d1d3 e7e6 b1d2 f8d6 f4d6 d8d6 e1g1 h7h6 a1c1 e8g8
info depth 25 multipv 1 score cp 26 nodes 179723061 nps 2116954 time 84897 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 e2e3 c7c5 c4d5 e6d5 f1d3 f8d6 d4c5 d6c5 h2h3 b8c6 b1c3 e8g8 e1g1 c8e6 a2a3 d5d4 e3d4 c6d4 f1e1
```

```
Score of ChessDotCpp2.14 vs ChessDotCpp2.13: 509 - 452 - 1039  [0.514] 2000
...      ChessDotCpp2.14 playing White: 264 - 217 - 518  [0.524] 999
...      ChessDotCpp2.14 playing Black: 245 - 235 - 521  [0.505] 1001
...      White vs Black: 499 - 462 - 1039  [0.509] 2000
Elo difference: 9.9 +/- 10.5, LOS: 96.7 %, DrawRatio: 51.9 %

Score of ChessDotCpp2.14 vs glaurung: 215 - 187 - 98  [0.528] 500
...      ChessDotCpp2.14 playing White: 112 - 95 - 44  [0.534] 251
...      ChessDotCpp2.14 playing Black: 103 - 92 - 54  [0.522] 249
...      White vs Black: 204 - 198 - 98  [0.506] 500
Elo difference: 19.5 +/- 27.4, LOS: 91.9 %, DrawRatio: 19.6 %
```

### 2.15

Outpost eval

```
info depth 1 multipv 1 score cp 17 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 28 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 17 nodes 182 nps 182000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 24 nodes 321 nps 321000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 27 nodes 1191 nps 1191000 time 1 pv d2d4 e7e6 g1f3 d7d5 b1c3
info depth 6 multipv 1 score cp 25 nodes 1833 nps 916500 time 2 pv d2d4 e7e6 g1f3 b8c6 e2e3 d7d5
info depth 7 multipv 1 score cp 33 nodes 6590 nps 1318000 time 5 pv e2e4 b8c6 g1f3 e7e6 d2d4 d7d5 e4e5
info depth 8 multipv 1 score cp 42 nodes 11108 nps 1586857 time 7 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 e5d4
info depth 9 multipv 1 score cp 30 nodes 23572 nps 1683714 time 14 pv e2e4 c7c5 d2d4 c5d4 c2c3 e7e5 c3d4 e5d4 d1d4
info depth 10 multipv 1 score cp 24 nodes 40819 nps 1855409 time 22 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 d2d4 c5d4 f3d4 d7d5
info depth 11 multipv 1 score cp 28 nodes 75884 nps 1897100 time 40 pv e2e4 c7c5 g1f3 b8c6 d2d3 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5
info depth 12 multipv 1 score cp 31 nodes 146975 nps 2013356 time 73 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 b8c6 c2c3 g8f6 f1e2 e7e6
info depth 13 multipv 1 score cp 26 nodes 386810 nps 2079623 time 186 pv e2e4 c7c5 c2c3 b8c6 d2d4 d7d5 e4d5 d8d5 g1f3 g8f6 f1e2 c5d4 c3d4
info depth 14 multipv 1 score cp 25 nodes 581881 nps 2108264 time 276 pv e2e4 c7c5 c2c3 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 b8c6 f1b5 a7a6 d1e2 c8e6 b5c6
info depth 15 multipv 1 score cp 26 nodes 1059954 nps 2132704 time 497 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 h2h3 e7e6 e4e5 f6g8 d2d3 d7d6 e5d6 f8d6 c1g5
info depth 16 multipv 1 score cp 19 nodes 2068041 nps 2105948 time 982 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 e5d4 f3d4 f8b4 d4c6 b4c3 b2c3 d7c6 f1d3 e8g8 e1g1
info depth 17 multipv 1 score cp 22 nodes 4950332 nps 2084350 time 2375 pv d2d4 d7d5 g1f3 c8f5 c2c4 e7e6 c4d5 e6d5 e2e3 g8f6 f1d3 f5d3 d1d3 c7c5 b1c3 c5c4 d3b1
info depth 18 multipv 1 score cp 24 nodes 7616798 nps 2085651 time 3652 pv d2d4 d7d5 c2c4 d5c4 g1f3 g8f6 e2e3 c7c5 f1c4 e7e6 b1c3 c5d4 e3d4 f8d6 e1g1 e8g8 f1e1 b8c6
info depth 19 multipv 1 score cp 23 nodes 10314031 nps 2091671 time 4931 pv d2d4 d7d5 c2c4 e7e6 e2e3 c7c5 g1f3 c5d4 e3d4 g8f6 c4d5 f6d5 b1c3 b8c6 f1e2 f8b4 c1d2 e8g8 e1g1
info depth 20 multipv 1 score cp 24 nodes 15776701 nps 2093233 time 7537 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 g1f3 g8f6 c1f4 b8c6 e2e3 c8f5 f1b5 e7e6 e1g1 f8d6 f4d6 d8d6 b5c6 b7c6 b1c3
info depth 21 multipv 1 score cp 26 nodes 22338483 nps 2062267 time 10832 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 c1f4 b8c6 b1c3 c8f5 e2e3 e7e6 g1f3 g8f6 f1d3 f5d3 d1d3 a7a6 a1c1 c6b4 d3e2
info depth 22 multipv 1 score cp 31 nodes 39913694 nps 2052856 time 19443 pv d2d4 d7d5 c2c4 c7c6 b1c3 d5c4 e2e4 b7b5 e4e5 c8f5 f1e2 b8a6 a2a3 a6c7 e2f3 c7d5 c3e4 g7g6 g1e2 f5e4 f3e4 f8g7
info depth 23 multipv 1 score cp 22 nodes 65519397 nps 2060747 time 31794 pv d2d4 d7d5 c2c4 c7c6 b1c3 d5c4 e2e4 b7b5 e4e5 b8a6 a2a3 a6c7 a3a4 a7a6 a4b5 c6b5 f1e2 c8b7 e2f3 c7d5 g1e2 e7e6 e1g1
info depth 24 multipv 1 score cp 23 nodes 89959878 nps 2066048 time 43542 pv d2d4 d7d5 c2c4 c7c6 b1c3 d5c4 e2e4 b7b5 e4e5 b8a6 a2a3 a6c7 a3a4 e7e6 a4b5 c6b5 f1e2 g8e7 e2f3 e7d5 g1e2 b5b4 c3e4
info depth 25 multipv 1 score cp 24 nodes 211036167 nps 2075452 time 101682 pv d2d4 g8f6 c2c4 e7e6 e2e3 d7d5 b1c3 c7c5 c4d5 e6d5 f1d3 b8c6 g1f3 f8d6 d4c5 d6c5 e1g1 e8g8 a2a3 a7a6 f1e1 c5d6 h2h3 f8e8
```

```
Score of ChessDotCpp2.15 vs ChessDotCpp2.14: 282 - 208 - 510  [0.537] 1000
...      ChessDotCpp2.15 playing White: 141 - 93 - 266  [0.548] 500
...      ChessDotCpp2.15 playing Black: 141 - 115 - 244  [0.526] 500
...      White vs Black: 256 - 234 - 510  [0.511] 1000
Elo difference: 25.8 +/- 15.1, LOS: 100.0 %, DrawRatio: 51.0 %

Score of ChessDotCpp2.15 vs glaurung: 192 - 208 - 100  [0.484] 500
...      ChessDotCpp2.15 playing White: 93 - 108 - 50  [0.470] 251
...      ChessDotCpp2.15 playing Black: 99 - 100 - 50  [0.498] 249
...      White vs Black: 193 - 207 - 100  [0.486] 500
Elo difference: -11.1 +/- 27.3, LOS: 21.2 %, DrawRatio: 20.0 %
```

### 2.16

Piece attack eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 26 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 171 nps 171000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 27 nodes 315 nps 315000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 12 nodes 1339 nps 669500 time 2 pv d2d4 d7d5 e2e3 e7e6 b1c3
info depth 6 multipv 1 score cp 15 nodes 5271 nps 1317750 time 4 pv e2e4 e7e5 g1f3 d7d5 d2d4 g8f6
info depth 7 multipv 1 score cp 34 nodes 7800 nps 1560000 time 5 pv e2e4 e7e5 g1f3 d7d5 f3e5 d5e4 d2d4
info depth 8 multipv 1 score cp 24 nodes 13924 nps 1740500 time 8 pv e2e4 e7e5 b1c3 f8c5 d1g4 c5f8 g4f3 b8c6
info depth 9 multipv 1 score cp 29 nodes 27961 nps 1747562 time 16 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 f1e2 b8c6 e1g1
info depth 10 multipv 1 score cp 32 nodes 41170 nps 1871363 time 22 pv d2d4 g8f6 g1f3 d7d5 e2e3 c8f5 f1e2 e7e6 e1g1 b8c6
info depth 11 multipv 1 score cp 30 nodes 72382 nps 1904789 time 38 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 g8f6 f1b5 b8c6 e1g1 e7e6
info depth 12 multipv 1 score cp 15 nodes 170293 nps 1980151 time 86 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 e1g1 e8g8 f1e1 f8e8
info depth 13 multipv 1 score cp 18 nodes 254367 nps 1987242 time 128 pv e2e4 e7e5 g1f3 b8c6 b1c3 f8c5 a2a3 g8f6 f1c4 e8g8 e1g1 d7d6 d2d3
info depth 14 multipv 1 score cp 20 nodes 393555 nps 2007933 time 196 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 d2d3 e8g8 e1g1 d7d6 a2a3 f8e8
info depth 15 multipv 1 score cp 22 nodes 678199 nps 2024474 time 335 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1c4 f8c5 d2d3 e8g8 a2a3 a7a6 b2b4 c5a7 e1g1
info depth 16 multipv 1 score cp 18 nodes 2045443 nps 2029209 time 1008 pv d2d4 d7d5 e2e3 e7e6 c2c4 g8f6 g1f3 c7c5 c4d5 e6d5 h2h3 c5d4 e3d4 f6e4 b1c3 b8c6
info depth 17 multipv 1 score cp 21 nodes 3009331 nps 2029218 time 1483 pv d2d4 d7d5 e2e3 e7e6 c2c4 g8f6 g1f3 b8c6 b1c3 a7a6 h2h3 f8e7 f1e2 d5c4 e2c4 e8g8 e1g1
info depth 18 multipv 1 score cp 21 nodes 4398027 nps 2026740 time 2170 pv d2d4 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 g1f3 b8c6 f1d3 c8g4 d4c5 g8f6 e1g1 g4f3 d1f3 f8c5
info depth 19 multipv 1 score cp 23 nodes 8751881 nps 2014705 time 4344 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c6 e2e3 f8d6 h2h3 e8g8 c4c5 d6c7 f1d3 f8e8 e1g1 h7h6 f1e1
info depth 20 multipv 1 score cp 23 nodes 13517603 nps 2010052 time 6725 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 g1f3 b8c6 b1c3 g8f6 c1f4 e7e6 e2e3 f8d6 f4d6 d8d6 f1d3 e8g8 e1g1 c8d7
info depth 21 multipv 1 score cp 30 nodes 18431794 nps 1997160 time 9229 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 g1f3 b8c6 b1c3 g8f6 c1f4 e7e6 e2e3 f8d6 f4d6 d8d6 a1c1 c8d7 f1e2 e8g8 c3b5
info depth 22 multipv 1 score cp 30 nodes 28812503 nps 1982966 time 14530 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 f8e7 e2e3 e8g8 c4d5 e6d5 f1d3 c7c5 e1g1 b8c6 a2a3 c8g4 d4c5 e7c5 f1e1 c5d6
info depth 23 multipv 1 score cp 27 nodes 43678640 nps 1977035 time 22093 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c5 e2e3 b8c6 c4d5 e6d5 f1d3 f8d6 e1g1 e8g8 c3b5 c6b4 b5d6 d8d6 d4c5 d6c5 d3e2
info depth 24 multipv 1 score cp 26 nodes 66980184 nps 1973720 time 33936 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c5 e2e3 b8c6 c4d5 f6d5 d4c5 d5c3 d1d8 e8d8 b2c3 f8c5 c1b2 d8c7 e1c1 h8d8 d1d8 c7d8 f1d3
info depth 25 multipv 1 score cp 24 nodes 151797868 nps 1967516 time 77152 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c5 e2e3 b8c6 c4d5 f6d5 d4c5 f8c5 c3d5 e6d5 f1d3 e8g8 e1g1 c6b4 d3e2 c8f5 c1d2
```

```
Score of ChessDotCpp2.16 vs ChessDotCpp2.15: 266 - 211 - 523  [0.527] 1000
...      ChessDotCpp2.16 playing White: 136 - 113 - 251  [0.523] 500
...      ChessDotCpp2.16 playing Black: 130 - 98 - 272  [0.532] 500
...      White vs Black: 234 - 243 - 523  [0.495] 1000
Elo difference: 19.1 +/- 14.9, LOS: 99.4 %, DrawRatio: 52.3 %

Score of ChessDotCpp2.16 vs glaurung: 217 - 194 - 89  [0.523] 500
...      ChessDotCpp2.16 playing White: 110 - 88 - 52  [0.544] 250
...      ChessDotCpp2.16 playing Black: 107 - 106 - 37  [0.502] 250
...      White vs Black: 216 - 195 - 89  [0.521] 500
Elo difference: 16.0 +/- 27.7, LOS: 87.2 %, DrawRatio: 17.8 %
```

### 2.17

Separate attack eval depending if the piece is attacked back or not

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 22 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 171 nps 171000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 29 nodes 305 nps 305000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 13 nodes 1343 nps 1343000 time 1 pv d2d4 d7d5 e2e3 e7e6 b1c3
info depth 6 multipv 1 score cp 17 nodes 5619 nps 1873000 time 3 pv e2e4 e7e5 g1f3 d7d5 d2d4 g8f6
info depth 7 multipv 1 score cp 40 nodes 10204 nps 1700666 time 6 pv e2e4 d7d5 e4d5 c7c6 d2d4 g8f6 d5c6
info depth 8 multipv 1 score cp 32 nodes 13657 nps 1707125 time 8 pv e2e4 g8f6 e4e5 f6e4 d2d4 d7d5 g1f3 c7c6
info depth 9 multipv 1 score cp 37 nodes 21744 nps 1812000 time 12 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 e7e6 d4c6
info depth 10 multipv 1 score cp 30 nodes 36813 nps 1840650 time 20 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 e7e6
info depth 11 multipv 1 score cp 26 nodes 63043 nps 1854205 time 34 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 e7e5 d4f3 g8f6 b1c3
info depth 12 multipv 1 score cp 19 nodes 151903 nps 1972766 time 77 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 g1f3 g8f6 c2c3 e7e6 f1e2 f8d6
info depth 13 multipv 1 score cp 26 nodes 296314 nps 2002121 time 148 pv e2e4 c7c5 c2c3 b8c6 d2d4 d7d5 e4d5 d8d5 g1f3 g8f6 f1e2 c5d4 c3d4
info depth 14 multipv 1 score cp 16 nodes 607446 nps 2024820 time 300 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 b1c3 f8d6 d2d3 e8g8 e1g1 a7a6 b5c4 f6g4
info depth 15 multipv 1 score cp 18 nodes 1210092 nps 2020186 time 599 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 b1c3 c5d4 e3d4 b8c6 f1b5
info depth 16 multipv 1 score cp 16 nodes 2394906 nps 2004105 time 1195 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 c2c4 c7c5 c4d5 e6d5 b1c3 b8c6 h2h3 c5d4 e3d4 f8b4
info depth 17 multipv 1 score cp 15 nodes 4237422 nps 1981956 time 2138 pv d2d4 d7d5 c1f4 c8f5 e2e3 e7e6 g1f3 g8f6 b1c3 f8b4 f1d3 f5d3 d1d3 e8g8 e1g1 b8c6 a2a3
info depth 18 multipv 1 score cp 12 nodes 7535078 nps 1972017 time 3821 pv d2d4 d7d5 e2e3 e7e6 g1f3 g8f6 c2c4 c7c5 b1c3 b8c6 h2h3 h7h6 a2a3 c5d4 e3d4 f8e7 c4d5 f6d5
info depth 19 multipv 1 score cp 23 nodes 11275774 nps 1969223 time 5726 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c6 e2e3 f8d6 c4c5 d6c7 f1d3 e8g8 e1g1 f8e8 f1e1 h7h6 h2h3
info depth 20 multipv 1 score cp 30 nodes 14812874 nps 1973997 time 7504 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 c7c5 c4d5 f6d5 e2e4 c5d4 f1b5 c8d7 b5d7 b8d7 e4d5 d4c3 d5e6 f7e6 b2c3 d7f6
info depth 21 multipv 1 score cp 26 nodes 20043252 nps 1973732 time 10155 pv d2d4 d7d5 c2c4 e7e6 b1c3 g8f6 g1f3 a7a6 e2e3 c7c5 c4d5 e6d5 f1d3 b8c6 e1g1 c5c4 d3c2 f8d6 e3e4 d5e4 c3e4
info depth 22 multipv 1 score cp 27 nodes 30331620 nps 1968818 time 15406 pv d2d4 d7d5 c2c4 g8f6 c4d5 c7c6 g1f3 c6d5 c1f4 b8c6 e2e3 c8f5 b1d2 e7e6 a1c1 f8d6 f4g3 e8g8 f1b5 a8c8 e1g1 f8e8
info depth 23 multipv 1 score cp 27 nodes 45555182 nps 1964855 time 23185 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 g1f3 b8c6 c1f4 c8g4 e2e3 g8f6 b1d2 e7e6 f1e2 f8d6 f4g3 e8g8 e1g1 c6b4 f1e1 d6g3
info depth 24 multipv 1 score cp 27 nodes 68142658 nps 1960319 time 34761 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 g1f3 b8c6 c1f4 c8g4 e2e3 g8f6 b1d2 e7e6 f1e2 f8d6 f4g3 e8g8 e1g1 c6b4 f1e1 d6g3 h2g3 g4f3
info depth 25 multipv 1 score cp 26 nodes 91128975 nps 1952875 time 46664 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 g1f3 b8c6 c1f4 c8g4 e2e3 g8f6 b1d2 e7e6 f1e2 f8d6 f4g3 e8g8 a1c1 d6g3 h2g3 d8a5 a2a3 g4f3
```

```
Score of ChessDotCpp2.17 vs ChessDotCpp2.16: 253 - 217 - 530  [0.518] 1000
...      ChessDotCpp2.17 playing White: 140 - 95 - 264  [0.545] 499
...      ChessDotCpp2.17 playing Black: 113 - 122 - 266  [0.491] 501
...      White vs Black: 262 - 208 - 530  [0.527] 1000
Elo difference: 12.5 +/- 14.7, LOS: 95.2 %, DrawRatio: 53.0 %

Score of ChessDotCpp2.17 vs glaurung: 205 - 187 - 108  [0.518] 500
...      ChessDotCpp2.17 playing White: 106 - 94 - 50  [0.524] 250
...      ChessDotCpp2.17 playing Black: 99 - 93 - 58  [0.512] 250
...      White vs Black: 199 - 193 - 108  [0.506] 500
Elo difference: 12.5 +/- 27.0, LOS: 81.8 %, DrawRatio: 21.6 %
```

### 2.17.1

Fix bug that caused asymmetric eval for bishops and rooks

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 20 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 170 nps 170000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 28 nodes 305 nps 305000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 26 nodes 1181 nps 1181000 time 1 pv d2d4 e7e6 g1f3 d7d5 e2e3
info depth 6 multipv 1 score cp 20 nodes 2604 nps 1302000 time 2 pv d2d4 g8f6 g1f3 d7d5 c2c3 c8f5
info depth 7 multipv 1 score cp 39 nodes 6815 nps 1363000 time 5 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3
info depth 8 multipv 1 score cp 26 nodes 9996 nps 1428000 time 7 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 f1b5 b8c6 g1f3
info depth 9 multipv 1 score cp 29 nodes 21076 nps 1621230 time 13 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4
info depth 10 multipv 1 score cp 31 nodes 35011 nps 1750550 time 20 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6
info depth 11 multipv 1 score cp 18 nodes 67547 nps 1777552 time 38 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 c2c3 d4c3 b1c3 f8c5 f1e2
info depth 12 multipv 1 score cp 19 nodes 129099 nps 1871000 time 69 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 c2c3 g8f6 e4e5 f6e4 c3d4 f8b4 c1d2
info depth 13 multipv 1 score cp 27 nodes 265889 nps 1912870 time 139 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 b1c3 a7a6 b5c6 d7c6 e1g1 g8f6 d2d3
info depth 14 multipv 1 score cp 19 nodes 619514 nps 1948157 time 318 pv d2d4 g8f6 g1f3 d7d5 e2e3 c8f5 f1e2 c7c6 c2c4 e7e6 b1c3 f8e7 e1g1 e8g8
info depth 15 multipv 1 score cp 17 nodes 1078587 nps 1961067 time 550 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 b1c3 f8b4 c4d5 e6d5 e2e3 e8g8 f1d3 f6e4 e1g1
info depth 16 multipv 1 score cp 21 nodes 2155527 nps 1950703 time 1105 pv d2d4 g8f6 g1f3 d7d5 c2c4 d5c4 b1c3 c7c5 e2e4 c5d4 d1d4 d8d4 f3d4 e7e5 d4f3 b8c6
info depth 17 multipv 1 score cp 23 nodes 4402410 nps 1942811 time 2266 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 b1c3 c7c6 e2e3 f8d6 c4c5 d6c7 f1d3 e8g8 e1g1 h7h6 c1d2
info depth 18 multipv 1 score cp 24 nodes 6161367 nps 1936318 time 3182 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 b1c3 f8e7 c4d5 e6d5 c1f4 b8c6 e2e3 c8f5 f1e2 e8g8 e1g1 a7a6
info depth 19 multipv 1 score cp 23 nodes 9105519 nps 1939407 time 4695 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 b1c3 b8c6 c4d5 e6d5 c1g5 f8b4 e2e3 c8f5 f1d3 f5d3 g5f6 b4c3 b2c3 d8f6
info depth 20 multipv 1 score cp 23 nodes 14638712 nps 1928429 time 7591 pv d2d4 d7d5 g1f3 g8f6 c2c4 d5c4 b1c3 c7c6 e2e4 b7b5 e4e5 f6d5 f1e2 h7h6 e1g1 c8f5 c1d2 e7e6 a1c1 f8e7
info depth 21 multipv 1 score cp 21 nodes 27569148 nps 1923742 time 14331 pv d2d4 d7d5 g1f3 g8f6 c2c4 c7c6 e2e3 c8f5 d1b3 d8c7 c4d5 c6d5 b1c3 e7e6 c1d2 b8c6 c3b5 c7d8 a1c1 a8c8 f1d3
info depth 22 multipv 1 score cp 23 nodes 41083664 nps 1915947 time 21443 pv d2d4 d7d5 g1f3 g8f6 c2c4 c7c6 c4d5 c6d5 c1f4 b8c6 e2e3 c8f5 f1d3 f5d3 d1d3 a8c8 b1d2 e7e6 a1c1 e6e5 f4g3 e5d4
info depth 23 multipv 1 score cp 24 nodes 68430807 nps 1901806 time 35982 pv d2d4 d7d5 c2c4 c7c6 b1c3 g8f6 c4d5 c6d5 c1g5 b8c6 e2e3 e7e6 a1c1 c8d7 g1f3 f8e7 a2a3 a8c8 f1d3 h7h6 g5f6 e7f6 e1g1
info depth 24 multipv 1 score cp 25 nodes 93771833 nps 1900908 time 49330 pv d2d4 d7d5 c2c4 c7c6 b1c3 g8f6 c4d5 c6d5 c1g5 b8c6 a1c1 e7e6 g1f3 f8e7 e2e3 e8g8 f1d3 c6b4 e1g1 c8d7 d3b1 h7h6 g5f6
info depth 25 multipv 1 score cp 20 nodes 151830813 nps 1897932 time 79998 pv d2d4 d7d5 c2c4 c7c6 b1c3 g8f6 c4d5 c6d5 c1g5 b8c6 a1c1 e7e6 g1f3 f8e7 e2e3 c8d7 a2a3 a8c8 f1d3 h7h6 g5f6 e7f6 c3b5 e8g8 e1g1
```

```
Score of ChessDotCpp2.17.1 vs ChessDotCpp2.17: 138 - 127 - 235  [0.511] 500
...      ChessDotCpp2.17.1 playing White: 72 - 58 - 120  [0.528] 250
...      ChessDotCpp2.17.1 playing Black: 66 - 69 - 115  [0.494] 250
...      White vs Black: 141 - 124 - 235  [0.517] 500
Elo difference: 7.6 +/- 22.2, LOS: 75.0 %, DrawRatio: 47.0 %

Score of ChessDotCpp2.18 vs glaurung: 204 - 199 - 97  [0.505] 500
...      ChessDotCpp2.18 playing White: 98 - 98 - 55  [0.500] 251
...      ChessDotCpp2.18 playing Black: 106 - 101 - 42  [0.510] 249
...      White vs Black: 199 - 204 - 97  [0.495] 500
Elo difference: 3.5 +/- 27.4, LOS: 59.8 %, DrawRatio: 19.4 %
```

### 2.18

Piece behind pawn eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 25 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 172 nps 172000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 26 nodes 309 nps 309000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 21 nodes 1215 nps 1215000 time 1 pv d2d4 g8f6 b1c3 d7d5 g1f3
info depth 6 multipv 1 score cp 15 nodes 3266 nps 1088666 time 3 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6
info depth 7 multipv 1 score cp 17 nodes 5473 nps 1368250 time 4 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 f1b5 b8c6
info depth 8 multipv 1 score cp 21 nodes 11584 nps 1448000 time 8 pv e2e4 e7e5 b1c3 b8c6 g1f3 f8c5 f1c4 g8f6
info depth 9 multipv 1 score cp 31 nodes 27375 nps 1610294 time 17 pv g1f3 d7d5 e2e3 h7h6 d2d4 g8f6 f1e2 c7c6 e1g1
info depth 10 multipv 1 score cp 26 nodes 52330 nps 1744333 time 30 pv e2e4 e7e5 g1f3 d7d5 f3e5 d5e4 d2d4 g8f6 c2c3 c7c6
info depth 11 multipv 1 score cp 26 nodes 78881 nps 1792750 time 44 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 d7d5 d4c6 b7c6 b1c3
info depth 12 multipv 1 score cp 38 nodes 154508 nps 1861542 time 83 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4 g8f6 d4c6
info depth 13 multipv 1 score cp 23 nodes 301139 nps 1930378 time 156 pv e2e4 e7e5 g1f3 b8c6 f1b5 c6d4 f3d4 e5d4 e1g1 c7c6 b5c4 d7d5 e4d5
info depth 14 multipv 1 score cp 23 nodes 453956 nps 1939982 time 234 pv e2e4 e7e5 g1f3 b8c6 f1b5 c6d4 f3d4 e5d4 e1g1 c7c6 b5c4 d7d5 e4d5 c6d5
info depth 15 multipv 1 score cp 17 nodes 1138136 nps 1965692 time 579 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 f1d3 c5d4 e3d4 f8b4 b1c3 b8c6
info depth 16 multipv 1 score cp 21 nodes 1949712 nps 1975392 time 987 pv d2d4 g8f6 g1f3 d7d5 c1f4 e7e6 e2e3 c7c5 b1c3 a7a6 f1e2 c5d4 e3d4 f8d6 f4d6
info depth 17 multipv 1 score cp 18 nodes 3403493 nps 1963931 time 1733 pv d2d4 g8f6 g1f3 d7d5 c2c4 c7c6 c4d5 c6d5 c1f4 b8c6 b1c3 c8f5 e2e3 a8c8 f1b5 e7e6 e1g1
info depth 18 multipv 1 score cp 21 nodes 5390504 nps 1963038 time 2746 pv d2d4 g8f6 g1f3 d7d5 c2c4 c7c6 e2e3 c8f5 d1b3 d8b6 c4d5 c6d5 b1c3 e7e6 b3b6 a7b6 f1b5 b8c6 e1g1
info depth 19 multipv 1 score cp 34 nodes 9246159 nps 1954790 time 4730 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 d8e8 f1d3 f8d6 c1d2 h7h6 e1g1 c8d7
info depth 20 multipv 1 score cp 30 nodes 11728581 nps 1957373 time 5992 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 c1g5 f8d6 e1c1 d8e7 f1e2 h7h6 g5e3
info depth 21 multipv 1 score cp 31 nodes 15308910 nps 1956910 time 7823 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 e4e5 f6d7 c1f4 f8b4 e1c1 d8e7 f1e2 b4c3
info depth 22 multipv 1 score cp 22 nodes 41068962 nps 1943908 time 21127 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 g1f3 c6d5 c1f4 b8c6 b1c3 c8f5 e2e3 a8c8 f1e2 e7e6 e1g1 f8e7 a1c1 e8g8 c3b5 h7h6
info depth 23 multipv 1 score cp 26 nodes 66593647 nps 1938905 time 34346 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 c1f4 c6d5 e2e3 b8c6 g1f3 c8f5 f1d3 f5d3 d1d3 e7e6 e1g1 f8e7 b1d2 e8g8 a2a3 a8c8 a1c1
info depth 24 multipv 1 score cp 19 nodes 100520032 nps 1932334 time 52020 pv d2d4 g8f6 c2c4 d7d5 c4d5 c7c6 c1f4 c6d5 e2e3 c8f5 g1f3 b8d7 b1c3 e7e6 f1d3 f5g6 a1c1 a8c8 e1g1 f8e7 f4g3 e8g8 h2h3 a7a6
info depth 25 multipv 1 score cp 29 nodes 171443957 nps 1929675 time 88846 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 d2d3 d7d6 b1c3 c8d7 h2h3 f8e7 c1e3 e8g8 b5a4 h7h6 e1g1 a8b8 a4b3 d7e6 b3e6 f7e6 d3d4 e5d4 f3d4
```

```
Score of ChessDotCpp2.18 vs ChessDotCpp2.17: 237 - 230 - 533  [0.503] 1000
...      ChessDotCpp2.18 playing White: 120 - 121 - 260  [0.499] 501
...      ChessDotCpp2.18 playing Black: 117 - 109 - 273  [0.508] 499
...      White vs Black: 229 - 238 - 533  [0.495] 1000
Elo difference: 2.4 +/- 14.7, LOS: 62.7 %, DrawRatio: 53.3 %
```

### 2.19

* Checks eval
* King attacks eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 24 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 15 nodes 170 nps 170000 time 1 pv b1c3 b8c6
info depth 4 multipv 1 score cp 28 nodes 316 nps 316000 time 1 pv b1c3 e7e6 e2e3
info depth 5 multipv 1 score cp 13 nodes 1293 nps 1293000 time 1 pv d2d4 d7d5 e2e3 e7e6 b1c3
info depth 6 multipv 1 score cp 17 nodes 4131 nps 1377000 time 3 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4
info depth 7 multipv 1 score cp 17 nodes 6362 nps 1590500 time 4 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4
info depth 8 multipv 1 score cp 35 nodes 12244 nps 1530500 time 8 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 g1f3 b8c6
info depth 9 multipv 1 score cp 32 nodes 20471 nps 1705916 time 12 pv e2e4 e7e5 g1f3 d7d5 f3e5 d5e4 d2d4 b8c6 e5c6
info depth 10 multipv 1 score cp 22 nodes 41163 nps 1789695 time 23 pv e2e4 e7e5 g1f3 d7d5 f3e5 d5e4 d2d4 b8d7 b1c3 d7e5
info depth 11 multipv 1 score cp 25 nodes 86945 nps 1890108 time 46 pv e2e4 d7d5 e4d5 c7c6 d2d4 c6d5 f1e2 g8f6 g1f3 b8c6 c2c3
info depth 12 multipv 1 score cp 23 nodes 160669 nps 1935771 time 83 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 c2c3 d7d5 e4d5 d8d5 c3d4 g8f6
info depth 13 multipv 1 score cp 18 nodes 334763 nps 1969194 time 170 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 f1e2 f8e7 c2c4 e8g8 c4d5 e6d5 e1g1
info depth 14 multipv 1 score cp 26 nodes 648286 nps 1982525 time 327 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 c7c5 c4d5 e6d5 f1b5 b8c6 e1g1 c5d4 e3d4
info depth 15 multipv 1 score cp 18 nodes 1611787 nps 1987406 time 811 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 f8d6 d2d3 a7a6 b5c6 d7c6 b1c3 e8g8 c1e3
info depth 16 multipv 1 score cp 17 nodes 2383523 nps 1982964 time 1202 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 a7a6 b5c6 e7c6 d2d4 e5d4 c1g5 f8e7 g5e7
info depth 17 multipv 1 score cp 26 nodes 3302798 nps 1983662 time 1665 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 d8e8 f1c4 b7b5 e4e5 b5c4
info depth 18 multipv 1 score cp 22 nodes 4895196 nps 1985075 time 2466 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 d8e8 f1e2 c8e6 e1g1 f8c5 c1d2
info depth 19 multipv 1 score cp 33 nodes 6827319 nps 1970366 time 3465 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8e7 b1c3 e7c6 d4d3 f8d6 c1e3 e8g8 e1c1 a7a6 f1e2
info depth 20 multipv 1 score cp 34 nodes 10610320 nps 1956179 time 5424 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e5 f1c4 f8e7 d2d3 g8f6 d1e2 d7d6 e1g1 e8g8 a2a3 a7a6 c1d2 c8e6 c4e6
info depth 21 multipv 1 score cp 30 nodes 16061185 nps 1964430 time 8176 pv e2e4 c7c5 g1f3 b8c6 f1b5 e7e5 e1g1 f8d6 d2d3 g8e7 b1c3 a7a6 b5c4 b7b5 c4b3 e8g8 c3d5 h7h6 c2c3 e7g6 c1e3
info depth 22 multipv 1 score cp 30 nodes 21781435 nps 1962468 time 11099 pv e2e4 c7c5 g1f3 b8c6 f1b5 e7e5 e1g1 f8d6 d2d3 g8e7 b1c3 a7a6 b5c4 b7b5 c4b3 e8g8 c3d5 h7h6 c2c3 e7g6 c1e3 c8b7
info depth 23 multipv 1 score cp 25 nodes 42444300 nps 1956770 time 21691 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 c1g5 d8e8 a1d1 f8b4 g5f6 g7f6 f1e2 a8d8 e1g1 d8d1
info depth 24 multipv 1 score cp 35 nodes 63177141 nps 1952804 time 32352 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5c4 e7g6 b1c3 f8c5 c3d5 e8g8 c2c3 c6a5 c4d3 a5c6 b2b4 c5e7 d1a4 a8b8 d5e7 d8e7 c1b2
info depth 25 multipv 1 score cp 33 nodes 92607113 nps 1950691 time 47474 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5c4 e7g6 c2c3 h7h6 d2d4 f8e7 c1e3 e8g8 b1d2 d7d6 h2h3 c8d7 d4e5 d6e5 c4d5 f8e8 d1e2
```

```
Score of ChessDotCpp2.19 vs ChessDotCpp2.18: 260 - 211 - 529  [0.524] 1000
...      ChessDotCpp2.19 playing White: 129 - 104 - 267  [0.525] 500
...      ChessDotCpp2.19 playing Black: 131 - 107 - 262  [0.524] 500
...      White vs Black: 236 - 235 - 529  [0.500] 1000
Elo difference: 17.0 +/- 14.8, LOS: 98.8 %, DrawRatio: 52.9 %

Score of ChessDotCpp2.19 vs glaurung: 213 - 166 - 121  [0.547] 500
...      ChessDotCpp2.19 playing White: 110 - 79 - 61  [0.562] 250
...      ChessDotCpp2.19 playing Black: 103 - 87 - 60  [0.532] 250
...      White vs Black: 197 - 182 - 121  [0.515] 500
Elo difference: 32.8 +/- 26.6, LOS: 99.2 %, DrawRatio: 24.2 %
```

### 2.20

Improved king safety eval

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 21 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 16 nodes 191 nps 191000 time 1 pv d2d4 e7e6
info depth 4 multipv 1 score cp 34 nodes 323 nps 323000 time 1 pv d2d4 e7e6 e2e3
info depth 5 multipv 1 score cp 15 nodes 1172 nps 1172000 time 1 pv g1f3 g8f6 d2d4 d7d5 e2e3
info depth 6 multipv 1 score cp 21 nodes 3393 nps 1131000 time 3 pv e2e4 e7e6 e4e5 b8c6 d2d4 f8b4 c1d2
info depth 7 multipv 1 score cp 17 nodes 8544 nps 1424000 time 6 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4
info depth 8 multipv 1 score cp 15 nodes 15068 nps 1506800 time 10 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5
info depth 9 multipv 1 score cp 11 nodes 22631 nps 1616500 time 14 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6
info depth 10 multipv 1 score cp 15 nodes 58906 nps 1785030 time 33 pv d2d4 d7d5 g1f3 g8f6 e2e3 e7e6 f1e2 f8e7 e1g1 e8g8
info depth 11 multipv 1 score cp 29 nodes 108639 nps 1810650 time 60 pv e2e4 e7e6 g1f3 d7d5 e4e5 c7c5 c2c3 d5d4 f1d3 b8c6 e1g1
info depth 12 multipv 1 score cp 21 nodes 177261 nps 1846468 time 96 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3
info depth 13 multipv 1 score cp 23 nodes 238816 nps 1865750 time 128 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8e7
info depth 14 multipv 1 score cp 37 nodes 420633 nps 1886246 time 223 pv e2e4 e7e5 g1f3 d7d6 b1c3 g8f6 f1c4 b8c6 d2d4 e5d4 f3d4 c6e5 c4e2 c7c6
info depth 15 multipv 1 score cp 21 nodes 742173 nps 1888480 time 393 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 f8c5 b1c3 c6d4 f3e5 d4b5 c3b5 d7d6 d2d4
info depth 16 multipv 1 score cp 21 nodes 1503585 nps 1908102 time 788 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8b4 f1d3 c8e6 e1g1
info depth 17 multipv 1 score cp 19 nodes 2428458 nps 1910667 time 1271 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8b4 c1d2 h8e8 e1c1 c8d7
info depth 18 multipv 1 score cp 29 nodes 3430262 nps 1886832 time 1818 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 d8e8 f1d3 f8c5 c1g5 c8e6 e1g1
info depth 19 multipv 1 score cp 33 nodes 4940413 nps 1872787 time 2638 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8e7 f1e2 e7c6 d4d1 f8d6 b1c3 e8g8 e1g1 f8e8 c1e3
info depth 20 multipv 1 score cp 26 nodes 7674736 nps 1867332 time 4110 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 c1g5 d8e8 g5f6 g7f6 f1e2 f8d6 e1c1
info depth 21 multipv 1 score cp 28 nodes 11747076 nps 1867282 time 6291 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 c1g5 f8d6 e1c1 h7h6 g5f6 g7f6 f1e2 d8e7 a2a3
info depth 22 multipv 1 score cp 29 nodes 20280431 nps 1868131 time 10856 pv e2e4 e7e5 g1f3 b8c6 f1b5 c6d4 f3d4 e5d4 e1g1 g8e7 c2c3 e7c6 d2d3 f8d6 g2g3 d8f6 b5c4 c6e5 c3d4 e5f3 g1h1 e8g8 b1c3
info depth 23 multipv 1 score cp 24 nodes 52316861 nps 1872672 time 27937 pv e2e4 c7c5 b1c3 b8c6 g1f3 e7e5 a2a3 g8f6 f1b5 d7d6 b2b4 c5b4 a3b4 f8e7 e1g1 e8g8 b5c6 b7c6 d2d4 e5d4 f3d4 c8d7 d1e2
info depth 24 multipv 1 score cp 29 nodes 81634492 nps 1874414 time 43552 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 a2a3 f8e7 d4c6 b7c6 e4e5 f6d5 c3d5 c6d5 c1e3 e8g8
info depth 25 multipv 1 score cp 22 nodes 184887750 nps 1875243 time 98594 pv e2e4 c7c5 b1c3 b8c6 g1e2 e7e6 d2d4 c5d4 e2d4 g8f6 a2a3 f8e7 c1f4 d7d5 e4d5 e6d5 f1b5 c8d7 e1g1 a7a6 d4c6 b7c6 b5e2 e8g8 f1e1
```

```
Score of ChessDotCpp2.20 vs ChessDotCpp2.19: 282 - 224 - 494  [0.529] 1000
...      ChessDotCpp2.20 playing White: 151 - 118 - 232  [0.533] 501
...      ChessDotCpp2.20 playing Black: 131 - 106 - 262  [0.525] 499
...      White vs Black: 257 - 249 - 494  [0.504] 1000
Elo difference: 20.2 +/- 15.3, LOS: 99.5 %, DrawRatio: 49.4 %

Score of ChessDotCpp2.20 vs glaurung: 221 - 147 - 132  [0.574] 500
...      ChessDotCpp2.20 playing White: 106 - 78 - 66  [0.556] 250
...      ChessDotCpp2.20 playing Black: 115 - 69 - 66  [0.592] 250
...      White vs Black: 175 - 193 - 132  [0.482] 500
Elo difference: 51.8 +/- 26.3, LOS: 100.0 %, DrawRatio: 26.4 %

Score of ChessDotCpp2.20 vs ChessDotCppOldEval: 3440 - 607 - 953  [0.783] 5000
...      ChessDotCpp2.20 playing White: 1738 - 295 - 467  [0.789] 2500
...      ChessDotCpp2.20 playing Black: 1702 - 312 - 486  [0.778] 2500
...      White vs Black: 2050 - 1997 - 953  [0.505] 5000
Elo difference: 223.2 +/- 9.9, LOS: 100.0 %, DrawRatio: 19.1 %
```

### 2.20.1

Fix eval bug with pawn attack initialization

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 25 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 16 nodes 193 nps 193000 time 1 pv d2d4 e7e6
info depth 4 multipv 1 score cp 35 nodes 314 nps 314000 time 1 pv d2d4 e7e6 e2e3
info depth 5 multipv 1 score cp 15 nodes 1251 nps 1251000 time 1 pv g1f3 g8f6 e2e3 d7d5 d2d4
info depth 6 multipv 1 score cp 15 nodes 2620 nps 1310000 time 2 pv g1f3 g8f6 e2e3 d7d5 d2d4 e7e6
info depth 7 multipv 1 score cp 22 nodes 5469 nps 1367250 time 4 pv g1f3 g8f6 e2e3 d7d5 d2d4 e7e6 f1b5 c8d7
info depth 8 multipv 1 score cp 20 nodes 13125 nps 1458333 time 9 pv e2e4 e7e5 g1f3 b8c6 b1c3 f8c5 f1b5 g8f6
info depth 9 multipv 1 score cp 32 nodes 20517 nps 1578230 time 13 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4
info depth 10 multipv 1 score cp 38 nodes 32596 nps 1629800 time 20 pv e2e4 e7e5 b1c3 b8c6 g1f3 f8c5 f1b5 g8f6 e1g1 e8g8
info depth 11 multipv 1 score cp 15 nodes 76759 nps 1744522 time 44 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 f1b5 f8b4 e1g1 e8g8 b5c6
info depth 12 multipv 1 score cp 15 nodes 117115 nps 1774469 time 66 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 f1b5 f8b4 e1g1 e8g8 b5c6
info depth 13 multipv 1 score cp 25 nodes 185151 nps 1797582 time 103 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4f5 e8g8 c1g5
info depth 14 multipv 1 score cp 34 nodes 374887 nps 1828717 time 205 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8b4 c2c3 b4d6 e1g1 e8g8 f1e1 f8e8 c1d2
info depth 15 multipv 1 score cp 20 nodes 695415 nps 1849507 time 376 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8d6 e1g1
info depth 16 multipv 1 score cp 22 nodes 1796222 nps 1867174 time 962 pv g1f3 d7d5 d2d4 e7e6 c2c4 c7c5 c4d5 e6d5 c1g5 f7f6 g5f4 c5d4 f3d4 b8c6 e2e3 c6d4
info depth 17 multipv 1 score cp 20 nodes 2727265 nps 1875698 time 1454 pv g1f3 d7d5 d2d4 e7e6 c2c4 g8f6 e2e3 c7c5 f1d3 d5c4 d3c4 f8e7 b1c3 e8g8 e1g1 b8c6 f1e1
info depth 18 multipv 1 score cp 25 nodes 5415991 nps 1863727 time 2906 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 b1c3 a7a6 b5c6 d7c6 d2d3 c8e6 c1e3 h7h6 h2h3 e8g8
info depth 19 multipv 1 score cp 30 nodes 7734377 nps 1863705 time 4150 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 b5c6 d7c6 d2d4 d8e7 d4e5 d6e5 f3e5 e7e5 f2f3 e5c5 g1h1 e8g8
info depth 20 multipv 1 score cp 28 nodes 10705596 nps 1855710 time 5769 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8d6 f1e2 d8e7 e1g1 d6b4 c1g5 h7h6 g5f6
info depth 21 multipv 1 score cp 25 nodes 14931213 nps 1844042 time 8097 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8b4 c1d2 d8e7 e1c1 h8d8 f1e2 c8e6 e4e5 f6g4
info depth 22 multipv 1 score cp 24 nodes 21764213 nps 1838193 time 11840 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8d6 c1e3 d8e7 a1d1 c8e6 f1e2 d6e5 f2f3 h8d8 e1g1
info depth 23 multipv 1 score cp 25 nodes 28853288 nps 1839194 time 15688 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8d6 c1e3 h8e8 f1d3 f6g4 e3d4 d6e5 d4e5 g4e5 e1c1 c8e6
info depth 24 multipv 1 score cp 28 nodes 42614090 nps 1833416 time 23243 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8b4 f2f3 c8e6 c1f4 d8e7 e1c1 h8d8 f1d3 a8c8 f4d2 b4c5 d2g5
info depth 25 multipv 1 score cp 26 nodes 65308178 nps 1822570 time 35833 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6e4 f1d3 e4c5 b1c3 d7d5 e5d6 f8d6 e1g1 c5d3 d1d3 e8g8 f1e1 f8e8 c1d2
```

```
Score of ChessDotCpp2.21 vs ChessDotCpp2.20: 2328 - 2213 - 5459  [0.506] 10000
...      ChessDotCpp2.21 playing White: 1133 - 1074 - 2793  [0.506] 5000
...      ChessDotCpp2.21 playing Black: 1195 - 1139 - 2666  [0.506] 5000
...      White vs Black: 2272 - 2269 - 5459  [0.500] 10000
Elo difference: 4.0 +/- 4.6, LOS: 95.6 %, DrawRatio: 54.6 %
```

### 2.21

Do not razor while in check

```
info depth 1 multipv 1 score cp 15 nodes 2 nps 2000 time 1 pv
info depth 2 multipv 1 score cp 25 nodes 60 nps 60000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 16 nodes 193 nps 193000 time 1 pv d2d4 e7e6
info depth 4 multipv 1 score cp 35 nodes 314 nps 314000 time 1 pv d2d4 e7e6 e2e3
info depth 5 multipv 1 score cp 15 nodes 1248 nps 624000 time 2 pv g1f3 g8f6 e2e3 d7d5 d2d4
info depth 6 multipv 1 score cp 15 nodes 2610 nps 870000 time 3 pv g1f3 g8f6 e2e3 d7d5 d2d4 e7e6
info depth 7 multipv 1 score cp 22 nodes 5451 nps 1090200 time 5 pv g1f3 g8f6 e2e3 d7d5 d2d4 e7e6 f1b5 c8d7
info depth 8 multipv 1 score cp 20 nodes 13058 nps 1305800 time 10 pv e2e4 e7e5 g1f3 b8c6 b1c3 f8c5 f1b5 g8f6
info depth 9 multipv 1 score cp 32 nodes 20398 nps 1457000 time 14 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4
info depth 10 multipv 1 score cp 38 nodes 32406 nps 1473000 time 22 pv e2e4 e7e5 b1c3 b8c6 g1f3 f8c5 f1b5 g8f6 e1g1 e8g8
info depth 11 multipv 1 score cp 15 nodes 76523 nps 1561693 time 49 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 f1b5 f8b4 e1g1 e8g8 b5c6
info depth 12 multipv 1 score cp 15 nodes 116762 nps 1644535 time 71 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 f1b5 f8b4 e1g1 e8g8 b5c6
info depth 13 multipv 1 score cp 25 nodes 187847 nps 1723366 time 109 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4f5 e8g8 c1g5
info depth 14 multipv 1 score cp 29 nodes 353146 nps 1801765 time 196 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 a7a6 b5c6 d7c6 d2d4 c8g4 d4e5 g4f3
info depth 15 multipv 1 score cp 26 nodes 1121689 nps 1885191 time 595 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 c2c4 b8c6 f1e2 f8e7 c4d5 e6d5 b1c3 e8g8 e1g1
info depth 16 multipv 1 score cp 28 nodes 1909357 nps 1884853 time 1013 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8e7 d4d1 e7c6 c1e3 f8d6 b1c3 e8g8
info depth 17 multipv 1 score cp 15 nodes 3358892 nps 1874381 time 1792 pv g1f3 g8f6 e2e3 d7d5 d2d4 e7e6 c2c4 c7c5 b1c3 b8c6 f1e2 d5c4 e1g1 f8e7 e2c4 e8g8 d4c5
info depth 18 multipv 1 score cp 26 nodes 5710310 nps 1857615 time 3074 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 h2h3 e8g8 c1e3 c8e6 b1d2 h7h6
info depth 19 multipv 1 score cp 21 nodes 7355603 nps 1856537 time 3962 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 h2h3 e8g8 c1e3 c8e6 d1e2 h7h6 b1c3
info depth 20 multipv 1 score cp 33 nodes 9982911 nps 1856940 time 5376 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 h2h3 e8g8 c1e3 c8e6 d1e2 h7h6 b1c3 d8e7
info depth 21 multipv 1 score cp 23 nodes 14401178 nps 1845358 time 7804 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 h2h3 e8g8 c1e3 c8e6 d1e2 h7h6 c2c4 d8e7 b1c3
info depth 22 multipv 1 score cp 26 nodes 20999635 nps 1832268 time 11461 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 e8g8 b5c6 d7c6 b1c3 d8e7 h2h3 h7h6 c1e3 d6b4 d1e2 c8d7 f3d2 b4c3
info depth 23 multipv 1 score cp 28 nodes 43142187 nps 1803753 time 23918 pv e2e4 e7e5 g1f3 d7d6 d2d4 e5d4 f3d4 g8f6 b1c3 f8e7 f1e2 e8g8 e1g1 f8e8 c1f4 b8c6 f2f3 c8d7 d4c6 d7c6 e2c4 f6d7 f4e3
info depth 24 multipv 1 score cp 25 nodes 100401213 nps 1809976 time 55471 pv e2e4 c7c5 g1f3 b8c6 f1b5 d7d6 e1g1 c8d7 b1c3 e7e5 h2h3 g8f6 a2a4 f8e7 b5c6 b7c6 b2b3 h7h6 d2d3 e8g8 c1b2 d8c7 f3d2 a8b8
info depth 25 multipv 1 score cp 20 nodes 160781648 nps 1813954 time 88636 pv e2e4 c7c5 g1f3 b8c6 f1b5 d7d6 e1g1 c8d7 b1c3 e7e5 h2h3 g8f6 a2a4 f8e7 b5c6 b7c6 b2b3 h7h6 d2d3 e8g8 d1e2 d8c7 c1b2 a8b8 f3d2
```

```
Score of ChessDotCpp2.21 vs ChessDotCpp2.20.1: 360 - 334 - 806  [0.509] 1500
...      ChessDotCpp2.21 playing White: 174 - 167 - 409  [0.505] 750
...      ChessDotCpp2.21 playing Black: 186 - 167 - 397  [0.513] 750
...      White vs Black: 341 - 353 - 806  [0.496] 1500
Elo difference: 6.0 +/- 11.9, LOS: 83.8 %, DrawRatio: 53.7 %
```

### 2.22

Do not razor in PV nodes

```
info depth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 multipv 1 score cp 25 nodes 75 nps 75000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 28 nodes 226 nps 226000 time 1 pv g1f3 d7d5 e2e3
info depth 4 multipv 1 score cp 23 nodes 512 nps 512000 time 1 pv d2d4 e7e6 g1f3 f8b4 c1d2
info depth 5 multipv 1 score cp 25 nodes 1503 nps 1503000 time 1 pv b1c3 d7d5 d2d4 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 2860 nps 1430000 time 2 pv g1f3 d7d5 d2d4 g8f6 c2c3 b8c6
info depth 7 multipv 1 score cp 35 nodes 8672 nps 1734400 time 5 pv e2e4 d7d5 e4d5 d8d5 d2d4 d5e4 c1e3 g8f6
info depth 8 multipv 1 score cp 35 nodes 12650 nps 1581250 time 8 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3 c7c6
info depth 9 multipv 1 score cp 32 nodes 21875 nps 1682692 time 13 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4
info depth 10 multipv 1 score cp 24 nodes 36780 nps 1671818 time 22 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 g8f6
info depth 11 multipv 1 score cp 35 nodes 54502 nps 1703187 time 32 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 d7d5 d4c6 b7c6 b1c3
info depth 12 multipv 1 score cp 25 nodes 87520 nps 1750400 time 50 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 d2d4 e5d4 f3d4 f8e7 d4f3 e8g8
info depth 13 multipv 1 score cp 15 nodes 187693 nps 1822262 time 103 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 e1g1 e8g8 b5c6 d7c6 f3e5
info depth 14 multipv 1 score cp 18 nodes 309892 nps 1833680 time 169 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 f8e7 c2c3 e8g8
info depth 15 multipv 1 score cp 42 nodes 734336 nps 1859078 time 395 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 f8e7 e1g1 e8g8 f1e1
info depth 16 multipv 1 score cp 17 nodes 1953187 nps 1858408 time 1051 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8b4 f1d3 c8e6 e1g1
info depth 17 multipv 1 score cp 21 nodes 2565891 nps 1863392 time 1377 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 e7g6 d2d4 e5d4 f3d4 f8b4 e1g1 e8g8 a2a3 b4c3 b2c3
info depth 18 multipv 1 score cp 25 nodes 3577434 nps 1861308 time 1922 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8b4 d4f5 e8g8 e1g1 d7d6
info depth 19 multipv 1 score cp 21 nodes 6076428 nps 1844135 time 3295 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 d2d4 c6d4 f3d4 e5d4 d1d4 g8f6 b1c3 e8g8 c1e3 f8e8 e1c1 d8e7 b5d3
info depth 20 multipv 1 score cp 33 nodes 8925032 nps 1839454 time 4852 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 c1e3 e8g8 h2h3 c8e6 b1c3 h7h6 d1e2 d8e7
info depth 21 multipv 1 score cp 25 nodes 12929678 nps 1833216 time 7053 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 d3d4 f6d7 c1e3 e8g8 b1d2 e5d4 e3d4 c6c5 e4e5
info depth 22 multipv 1 score cp 22 nodes 19317028 nps 1829783 time 10557 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 d3d4 f6d7 c1e3 e8g8 b1d2 e5d4 e3d4 c6c5 e4e5 d6e7
info depth 23 multipv 1 score cp 22 nodes 29944433 nps 1819334 time 16459 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 d3d4 f6d7 c1e3 e8g8 b1c3 e5d4 e3d4 c6c5 d4e3 h7h6 d1e2
info depth 24 multipv 1 score cp 22 nodes 55817427 nps 1812077 time 30803 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 b1c3 c8e6 h2h3 e8g8 c1e3 h7h6 d1e2 d8e7 a2a3 a8d8 f3d2 f6d7
info depth 25 multipv 1 score cp 23 nodes 102560258 nps 1807133 time 56753 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 d2d3 g8e7 c1e3 e7g6 h2h3 g4f3 d1f3 f8e7 b1c3 e8g8 c3e2 d8d7 e2g3 e7f6 g3f5
```

```
Score of ChessDotCpp2.22 vs ChessDotCpp2.21: 354 - 343 - 803  [0.504] 1500
...      ChessDotCpp2.22 playing White: 176 - 175 - 399  [0.501] 750
...      ChessDotCpp2.22 playing Black: 178 - 168 - 404  [0.507] 750
...      White vs Black: 344 - 353 - 803  [0.497] 1500
Elo difference: 2.5 +/- 12.0, LOS: 66.2 %, DrawRatio: 53.5 %
```

### 2.23

Razoring at pre-frontier nodes (depth=2)

```
info depth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 multipv 1 score cp 25 nodes 75 nps 75000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 28 nodes 226 nps 226000 time 1 pv g1f3 d7d5 e2e3
info depth 4 multipv 1 score cp 23 nodes 512 nps 512000 time 1 pv d2d4 e7e6 g1f3 f8b4 c1d2
info depth 5 multipv 1 score cp 25 nodes 1503 nps 751500 time 2 pv b1c3 d7d5 d2d4 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 2860 nps 953333 time 3 pv g1f3 d7d5 d2d4 g8f6 c2c3 b8c6
info depth 7 multipv 1 score cp 35 nodes 8666 nps 1444333 time 6 pv e2e4 d7d5 e4d5 d8d5 d2d4 d5e4 c1e3 g8f6
info depth 8 multipv 1 score cp 35 nodes 12400 nps 1377777 time 9 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3 c7c6
info depth 9 multipv 1 score cp 32 nodes 21579 nps 1541357 time 14 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4
info depth 10 multipv 1 score cp 24 nodes 47915 nps 1711250 time 28 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 g8f6
info depth 11 multipv 1 score cp 32 nodes 64291 nps 1737594 time 37 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 12 multipv 1 score cp 28 nodes 127322 nps 1793267 time 71 pv e2e4 c7c5 d2d3 b8c6 g1f3 e7e6 f1e2 d7d5 e1g1 d5d4 c2c3 e6e5
info depth 13 multipv 1 score cp 21 nodes 286814 nps 1862428 time 154 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 d2d3 f6g4 e1g1 e8g8 b5c4
info depth 14 multipv 1 score cp 21 nodes 718504 nps 1921133 time 374 pv g1f3 d7d5 e2e3 c8f5 f1e2 c7c6 e1g1 g8f6 c2c4 e7e6 d2d4 f8e7 c4d5 c6d5
info depth 15 multipv 1 score cp 21 nodes 1475513 nps 1936368 time 762 pv g1f3 d7d5 e2e3 g8f6 c2c4 e7e6 d2d4 c7c5 c4d5 e6d5 f1b5 c8d7 b1c3 c5d4 e3d4 b8c6
info depth 16 multipv 1 score cp 17 nodes 2659526 nps 1918849 time 1386 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 d8e8 f1e2 f8b4 c1d2
info depth 17 multipv 1 score cp 26 nodes 3538555 nps 1918956 time 1844 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 d2d3 f8d6 e1g1 g8f6 c1e3 e8g8 b1d2 c8e6 h2h3
info depth 18 multipv 1 score cp 33 nodes 4630622 nps 1911111 time 2423 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8b4 c1d2 c8e6 f1e2 d8e8 e1c1
info depth 19 multipv 1 score cp 26 nodes 6174797 nps 1905801 time 3240 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8d6 c1e3 a7a6 e3g5 c8e6 g5f6 g7f6 e1c1
info depth 20 multipv 1 score cp 33 nodes 8452162 nps 1892133 time 4467 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8d6 c1e3 d8e7 f2f3 h8d8 f1e2 c8e6 e1c1
info depth 21 multipv 1 score cp 20 nodes 24769681 nps 1875496 time 13207 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 f8d6 c1e3 d8e7 e3d4 c6c5 d4e3 c8e6 e1c1 c7c6
info depth 22 multipv 1 score cp 34 nodes 37072188 nps 1874225 time 19780 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 b8c6 g1f3 g8e7 f1d3 c5d4 c3d4 c8d7 b1c3 a8c8 e1g1 c6b4 d3e2 d8a5 c1e3 e7f5
info depth 23 multipv 1 score cp 25 nodes 56403811 nps 1866748 time 30215 pv e2e4 e7e6 c2c3 d7d5 e4e5 c7c5 d2d4 g8e7 g1f3 b8c6 f1d3 c8d7 e1g1 a8c8 a2a3 e7g6 c1e3 f8e7 b1d2 c5c4 d3c2 e8g8 h2h3
info depth 24 multipv 1 score cp 29 nodes 104062616 nps 1858526 time 55992 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 b1c3 f8e7 c4d5 e6d5 c1f4 e8g8 e2e3 c7c5 d4c5 b8c6 f1b5 e7c5 a1c1 c8g4 e1g1 g4f3 d1f3 a7a6
info depth 25 multipv 1 score cp 22 nodes 156249496 nps 1859803 time 84014 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 b1c3 c7c5 c4d5 c5d4 f3d4 f6d5 c1d2 f8c5 e2e3 e8g8 a1c1 c5d4 e3d4 b8c6 d1a4 d5e7 c3b5 e7f5 f1d3
```

```
Score of ChessDotCpp2.23 vs ChessDotCpp2.22: 348 - 324 - 828  [0.508] 1500
...      ChessDotCpp2.23 playing White: 171 - 167 - 412  [0.503] 750
...      ChessDotCpp2.23 playing Black: 177 - 157 - 416  [0.513] 750
...      White vs Black: 328 - 344 - 828  [0.495] 1500
Elo difference: 5.6 +/- 11.8, LOS: 82.3 %, DrawRatio: 55.2 %

Score of ChessDotCpp2.23 vs glaurung: 215 - 165 - 120  [0.550] 500
...      ChessDotCpp2.23 playing White: 103 - 80 - 67  [0.546] 250
...      ChessDotCpp2.23 playing Black: 112 - 85 - 53  [0.554] 250
...      White vs Black: 188 - 192 - 120  [0.496] 500
Elo difference: 34.9 +/- 26.7, LOS: 99.5 %, DrawRatio: 24.0 %
```

### 2.24

Razoring at depth=3

```
info depth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 multipv 1 score cp 25 nodes 75 nps 75000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 28 nodes 226 nps 226000 time 1 pv g1f3 d7d5 e2e3
info depth 4 multipv 1 score cp 23 nodes 512 nps 512000 time 1 pv d2d4 e7e6 g1f3 f8b4 c1d2
info depth 5 multipv 1 score cp 25 nodes 1503 nps 751500 time 2 pv b1c3 d7d5 d2d4 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 2860 nps 953333 time 3 pv g1f3 d7d5 d2d4 g8f6 c2c3 b8c6
info depth 7 multipv 1 score cp 35 nodes 8666 nps 1444333 time 6 pv e2e4 d7d5 e4d5 d8d5 d2d4 d5e4 c1e3 g8f6
info depth 8 multipv 1 score cp 35 nodes 12400 nps 1377777 time 9 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3 c7c6
info depth 9 multipv 1 score cp 32 nodes 21579 nps 1541357 time 14 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4
info depth 10 multipv 1 score cp 24 nodes 47911 nps 1711107 time 28 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 g8f6
info depth 11 multipv 1 score cp 32 nodes 64272 nps 1737081 time 37 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 12 multipv 1 score cp 28 nodes 127280 nps 1792676 time 71 pv e2e4 c7c5 d2d3 b8c6 g1f3 e7e6 f1e2 d7d5 e1g1 d5d4 c2c3 e6e5
info depth 13 multipv 1 score cp 21 nodes 286619 nps 1861162 time 154 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 d2d3 f6g4 e1g1 e8g8 b5c4
info depth 14 multipv 1 score cp 23 nodes 602873 nps 1901807 time 317 pv g1f3 d7d5 e2e3 g8f6 f1e2 c8f5 d2d4 b8c6 c2c4 d5c4 e2c4 e7e5 b1c3 f8b4
info depth 15 multipv 1 score cp 21 nodes 1363777 nps 1907380 time 715 pv g1f3 d7d5 e2e3 c7c5 d2d4 e7e6 c2c4 c5d4 e3d4 b8c6 c4d5 e6d5 b1c3 g8f6 f1d3
info depth 16 multipv 1 score cp 25 nodes 2839196 nps 1882755 time 1508 pv d2d4 g8f6 e2e3 d7d5 c2c4 c7c6 g1f3 c8f5 f1d3 f5d3 d1d3 d5c4 d3c4 b8d7 e1g1 e7e6
info depth 17 multipv 1 score cp 24 nodes 4628543 nps 1877705 time 2465 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 d8e8 f1e2 c8g4 h2h3 g4e2
info depth 18 multipv 1 score cp 24 nodes 5480437 nps 1881372 time 2913 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 c1g5 d8e8 b1d2 f8d6 f1e2 c8e6 e1g1
info depth 19 multipv 1 score cp 26 nodes 7348287 nps 1872652 time 3924 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 e7g6 d2d4 c6d4 f3d4 c7c6 b5e2 e5d4 d1d4 f8e7 e4e5 e8g8 e1g1
info depth 20 multipv 1 score cp 22 nodes 10344002 nps 1865801 time 5544 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 c1g5 f8e7 b1c3 d8e8 f1e2 h7h6 g5d2 c8e6 e1c1
info depth 21 multipv 1 score cp 19 nodes 14963194 nps 1863411 time 8030 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8c5 d4c6 d7c6 d1d8 e8d8 e1g1 c8e6 c1e3 c5e3
info depth 22 multipv 1 score cp 21 nodes 30247311 nps 1850441 time 16346 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 b8c6 g1f3 g8e7 f1d3 e7g6 e1g1 f8e7 f1e1 c5d4 c3d4 e8g8 a2a3 c8d7 b1c3 a8c8
info depth 23 multipv 1 score cp 22 nodes 42040845 nps 1849412 time 22732 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 h7h6 h2h3 f8e8 e1e8 d8e8 c1e3 c7c6 c2c3 c8e6 b1d2 b8d7
info depth 24 multipv 1 score cp 21 nodes 59371372 nps 1851767 time 32062 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 c7c6 c2c4 d5c4 d3c4 c8f5 b1c3 f8e8 e1e8 d8e8 d4d5 c6d5 c3d5
info depth 25 multipv 1 score cp 19 nodes 191968040 nps 1855426 time 103463 pv e2e4 e7e6 g1f3 d7d5 e4e5 g8e7 c2c3 c7c5 d2d4 b8c6 f1d3 c8d7 a2a3 a8c8 e1g1 c5d4 c3d4 d8b6 d3c2 e7f5 c2f5 e6f5 h2h3 c6e7 b1c3
```

```
Score of ChessDotCpp2.24 vs ChessDotCpp2.23: 354 - 303 - 843  [0.517] 1500
...      ChessDotCpp2.24 playing White: 179 - 143 - 428  [0.524] 750
...      ChessDotCpp2.24 playing Black: 175 - 160 - 415  [0.510] 750
...      White vs Black: 339 - 318 - 843  [0.507] 1500
Elo difference: 11.8 +/- 11.6, LOS: 97.7 %, DrawRatio: 56.2 %
```

### 2.25

Extend late move pruning up to depth 7

```
info depth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 multipv 1 score cp 25 nodes 75 nps 75000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 28 nodes 226 nps 226000 time 1 pv g1f3 d7d5 e2e3
info depth 4 multipv 1 score cp 23 nodes 512 nps 512000 time 1 pv d2d4 e7e6 g1f3 f8b4 c1d2
info depth 5 multipv 1 score cp 25 nodes 1503 nps 751500 time 2 pv b1c3 d7d5 d2d4 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 2860 nps 953333 time 3 pv g1f3 d7d5 d2d4 g8f6 c2c3 b8c6
info depth 7 multipv 1 score cp 35 nodes 8666 nps 1444333 time 6 pv e2e4 d7d5 e4d5 d8d5 d2d4 d5e4 c1e3 g8f6
info depth 8 multipv 1 score cp 35 nodes 12352 nps 1372444 time 9 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3 c7c6
info depth 9 multipv 1 score cp 32 nodes 21535 nps 1538214 time 14 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4
info depth 10 multipv 1 score cp 24 nodes 45142 nps 1671925 time 27 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 g8f6
info depth 11 multipv 1 score cp 36 nodes 69740 nps 1700975 time 41 pv e2e4 e7e5 d2d4 e5d4 d1d4 d7d6 b1c3 b8c6 d4d1 g8f6 g1f3
info depth 12 multipv 1 score cp 24 nodes 111336 nps 1739625 time 64 pv e2e4 e7e5 d2d4 e5d4 g1f3 d7d5 e4d5 d8d5 c2c3 b8c6 c3d4 g8f6
info depth 13 multipv 1 score cp 28 nodes 179544 nps 1760235 time 102 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3 d5e4 c1e3 b8c6
info depth 14 multipv 1 score cp 24 nodes 369565 nps 1820517 time 203 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 e4e5 f6e4 f1e2
info depth 15 multipv 1 score cp 21 nodes 1163854 nps 1877183 time 620 pv d2d4 g8f6 g1f3 d7d5 c2c4 e7e6 e2e3 c7c5 c4d5 e6d5 f1b5 c8d7 b1c3 c5d4 e3d4 b8c6
info depth 16 multipv 1 score cp 19 nodes 2515512 nps 1864723 time 1349 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 e4e5 f6e4 f1d3 e4c5 c1g5 d8e8
info depth 17 multipv 1 score cp 36 nodes 3198750 nps 1864073 time 1716 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d4 d6d5 f1d3 c7c5 d4c5 f8c5 e1g1 e8g8 f1e1
info depth 18 multipv 1 score cp 17 nodes 6114246 nps 1847762 time 3309 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 f8e7 c1f4 b8c6 e2e3 e8g8 a1c1 a7a6 c4d5 e6d5 f1d3 c6b4
info depth 19 multipv 1 score cp 29 nodes 8731182 nps 1845525 time 4731 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 b8c6 e2e3 f8e7 f1e2 e8g8 e1g1 a7a6 h2h3 h7h6 a2a3 f8e8 c1d2
info depth 20 multipv 1 score cp 17 nodes 13014368 nps 1833784 time 7097 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 b8c6 e2e3 c8g4 f1e2 g4e2 d1e2 f8b4
info depth 21 multipv 1 score cp 24 nodes 17838367 nps 1833525 time 9729 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8e7 e2e3 b8c6 f1e2 e8g8 e1g1 c8d7 h2h3
info depth 22 multipv 1 score cp 28 nodes 28862885 nps 1831168 time 15762 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8e7 e2e3 b8c6 f1e2 e8g8 e1g1 f8e8 h2h3 c6d4
info depth 23 multipv 1 score cp 25 nodes 47363516 nps 1832456 time 25847 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8e7 e2e3 b8c6 f1e2 e8g8 e1g1 c6d4 d1d4 c8e6 h2h3
info depth 24 multipv 1 score cp 24 nodes 70072026 nps 1835643 time 38173 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8c5 e2e3 e8g8 a1c1 c5d4 e3d4 b8c6 f1e2 c8f5 e1g1 f8e8
info depth 25 multipv 1 score cp 27 nodes 137348719 nps 1830974 time 75014 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8e7 b1c3 e7f6 c1e3 e8g8 c3d5 f6d4 e3d4 f8e8 f1e1 d7d6 c2c3
```

```
Score of ChessDotCpp2.25 vs ChessDotCpp2.24: 377 - 321 - 802  [0.519] 1500
...      ChessDotCpp2.25 playing White: 181 - 154 - 415  [0.518] 750
...      ChessDotCpp2.25 playing Black: 196 - 167 - 387  [0.519] 750
...      White vs Black: 348 - 350 - 802  [0.499] 1500
Elo difference: 13.0 +/- 12.0, LOS: 98.3 %, DrawRatio: 53.5 %

Score of ChessDotCpp2.25 vs wyldchess: 375 - 36 - 89  [0.839] 500
...      ChessDotCpp2.25 playing White: 188 - 13 - 49  [0.850] 250
...      ChessDotCpp2.25 playing Black: 187 - 23 - 40  [0.828] 250
...      White vs Black: 211 - 200 - 89  [0.511] 500
Elo difference: 286.8 +/- 34.1, LOS: 100.0 %, DrawRatio: 17.8 %

Score of ChessDotCpp2.25 vs supernova: 1067 - 176 - 257  [0.797] 1500
...      ChessDotCpp2.25 playing White: 527 - 98 - 126  [0.786] 751
...      ChessDotCpp2.25 playing Black: 540 - 78 - 131  [0.808] 749
...      White vs Black: 605 - 638 - 257  [0.489] 1500
Elo difference: 237.6 +/- 18.8, LOS: 100.0 %, DrawRatio: 17.1 %

Score of ChessDotCpp2.25 vs greko: 556 - 204 - 240  [0.676] 1000
...      ChessDotCpp2.25 playing White: 282 - 100 - 118  [0.682] 500
...      ChessDotCpp2.25 playing Black: 274 - 104 - 122  [0.670] 500
...      White vs Black: 386 - 374 - 240  [0.506] 1000
Elo difference: 127.8 +/- 19.6, LOS: 100.0 %, DrawRatio: 24.0 %

Score of ChessDotCpp2.25 vs glaurung: 439 - 335 - 226  [0.552] 1000
...      ChessDotCpp2.25 playing White: 220 - 168 - 112  [0.552] 500
...      ChessDotCpp2.25 playing Black: 219 - 167 - 114  [0.552] 500
...      White vs Black: 387 - 387 - 226  [0.500] 1000
Elo difference: 36.3 +/- 19.0, LOS: 100.0 %, DrawRatio: 22.6 %
```

### 2.26

Probe and store transposition table entries in quiessence search

```
info depth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 multipv 1 score cp 25 nodes 75 nps 75000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 28 nodes 219 nps 219000 time 1 pv g1f3 d7d5 e2e3
info depth 4 multipv 1 score cp 23 nodes 504 nps 504000 time 1 pv d2d4 e7e6 g1f3 f8b4 c1d2
info depth 5 multipv 1 score cp 25 nodes 1464 nps 1464000 time 1 pv b1c3 d7d5 d2d4 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 2782 nps 1391000 time 2 pv g1f3 d7d5 d2d4 g8f6 c2c3 b8c6
info depth 7 multipv 1 score cp 35 nodes 8167 nps 1361166 time 6 pv e2e4 d7d5 e4d5 d8d5 d2d4 d5e4 c1e3 g8f6
info depth 8 multipv 1 score cp 35 nodes 11491 nps 1436375 time 8 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3 c7c6
info depth 9 multipv 1 score cp 32 nodes 24960 nps 1560000 time 16 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 10 multipv 1 score cp 24 nodes 43773 nps 1621222 time 27 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 g8f6
info depth 11 multipv 1 score cp 32 nodes 62007 nps 1631763 time 38 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 12 multipv 1 score cp 27 nodes 99278 nps 1654633 time 60 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 c1g5
info depth 13 multipv 1 score cp 15 nodes 169142 nps 1691420 time 100 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 c1g5 f8b4 c2c3 b4d6 f1e2 e8g8
info depth 14 multipv 1 score cp 23 nodes 303191 nps 1742477 time 174 pv e2e4 e7e5 g1f3 g8f6 d2d4 d7d5 d4e5 f6e4 b1d2 f8e7 c2c3 e4c5 d2b3 e8g8 b3c5 e7c5
info depth 15 multipv 1 score cp 36 nodes 504455 nps 1770017 time 285 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 f1d3 b8d7 e5f3 f8d6 e1g1 e8g8 f1e1
info depth 16 multipv 1 score cp 16 nodes 1133249 nps 1776252 time 638 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 f1d3 b8d7 e5f3 f8d6 c2c4 d8e7 e1g1 d5c4 d3c4
info depth 17 multipv 1 score cp 23 nodes 1940282 nps 1776815 time 1092 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8c5 d4f5 e8g8 b1c3
info depth 18 multipv 1 score cp 24 nodes 2791494 nps 1771252 time 1576 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5c6 e7c6 b1c3 f8d6 d2d3 e8g8 c1g5 f7f6 g5e3 f8e8
info depth 19 multipv 1 score cp 22 nodes 4498627 nps 1763475 time 2551 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 f1d3 d8e8 e1g1 a8d8 c1e3 f8b4
info depth 20 multipv 1 score cp 25 nodes 12216630 nps 1758800 time 6946 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 d1a4 c8d7 a4d4 e6d5 c3d5 f6d5 d4d5 b8c6 c1g5 f7f6 d5e4 f8e7
info depth 21 multipv 1 score cp 22 nodes 17315365 nps 1755410 time 9864 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 f6d5 c1d2 d5c3 d2c3 f8c5 e2e3 e8g8 b2b4 c5e7 a1c1
info depth 22 multipv 1 score cp 31 nodes 29046643 nps 1741405 time 16680 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 f8e7 c4d5 e6d5 c1f4 e8g8 e2e3 c7c5 d4c5 b8c6 a1c1 c8f5 f1d3 f5d3 d1d3 e7c5
info depth 23 multipv 1 score cp 22 nodes 46988609 nps 1738515 time 27028 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8c5 e2e3 b8c6 a1c1 c5d4 e3d4 e8g8 f1e2 f8e8 e1g1
info depth 24 multipv 1 score cp 19 nodes 87144780 nps 1741293 time 50046 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 f6d5 c1d2 f8e7 e2e3 e8g8 f1c4 d5b6 c4b3 c8d7 a1c1 b8c6 e1g1 a8c8
info depth 25 multipv 1 score cp 23 nodes 153718826 nps 1742527 time 88216 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 f6d5 c1d2 f8e7 e2e4 d5c3 d2c3 e8g8 a1c1 c8d7 f1d3 b8c6 d4c6 d7c6 e1g1
```

```
Score of ChessDotCpp2.26 vs ChessDotCpp2.25: 503 - 425 - 1072  [0.519] 2000
...      ChessDotCpp2.26 playing White: 245 - 214 - 541  [0.515] 1000
...      ChessDotCpp2.26 playing Black: 258 - 211 - 531  [0.523] 1000
...      White vs Black: 456 - 472 - 1072  [0.496] 2000
Elo difference: 13.6 +/- 10.4, LOS: 99.5 %, DrawRatio: 53.6 %

Score of ChessDotCpp2.25 vs glaurung: 444 - 314 - 242  [0.565] 1000
...      ChessDotCpp2.25 playing White: 231 - 158 - 112  [0.573] 501
...      ChessDotCpp2.25 playing Black: 213 - 156 - 130  [0.557] 499
...      White vs Black: 387 - 371 - 242  [0.508] 1000
Elo difference: 45.4 +/- 18.8, LOS: 100.0 %, DrawRatio: 24.2 %
```

### 2.27

Fix bug which caused the search to discard last iterative deepening iteration

```
info depth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 multipv 1 score cp 25 nodes 75 nps 75000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 28 nodes 219 nps 219000 time 1 pv g1f3 d7d5 e2e3
info depth 4 multipv 1 score cp 23 nodes 504 nps 504000 time 1 pv d2d4 e7e6 g1f3 f8b4 c1d2
info depth 5 multipv 1 score cp 25 nodes 1464 nps 1464000 time 1 pv b1c3 d7d5 d2d4 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 2782 nps 1391000 time 2 pv g1f3 d7d5 d2d4 g8f6 c2c3 b8c6
info depth 7 multipv 1 score cp 35 nodes 8167 nps 2722333 time 3 pv e2e4 d7d5 e4d5 d8d5 d2d4 d5e4 c1e3 g8f6
info depth 8 multipv 1 score cp 35 nodes 11491 nps 1641571 time 7 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3 c7c6
info depth 9 multipv 1 score cp 32 nodes 24960 nps 2773333 time 9 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 10 multipv 1 score cp 24 nodes 43773 nps 2303842 time 19 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 g8f6
info depth 11 multipv 1 score cp 32 nodes 62007 nps 1937718 time 32 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 12 multipv 1 score cp 27 nodes 99278 nps 2256318 time 44 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 c1g5
info depth 13 multipv 1 score cp 15 nodes 169142 nps 2451333 time 69 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 c1g5 f8b4 c2c3 b4d6 f1e2 e8g8
info depth 14 multipv 1 score cp 23 nodes 303191 nps 2659570 time 114 pv e2e4 e7e5 g1f3 g8f6 d2d4 d7d5 d4e5 f6e4 b1d2 f8e7 c2c3 e4c5 d2b3 e8g8 b3c5 e7c5
info depth 15 multipv 1 score cp 36 nodes 504455 nps 2534949 time 199 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 f1d3 b8d7 e5f3 f8d6 e1g1 e8g8 f1e1
info depth 16 multipv 1 score cp 16 nodes 1133249 nps 3465593 time 327 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 f1d3 b8d7 e5f3 f8d6 c2c4 d8e7 e1g1 d5c4 d3c4
info depth 17 multipv 1 score cp 23 nodes 1940282 nps 2661566 time 729 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8c5 d4f5 e8g8 b1c3
info depth 18 multipv 1 score cp 24 nodes 2791494 nps 2220758 time 1257 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5c6 e7c6 b1c3 f8d6 d2d3 e8g8 c1g5 f7f6 g5e3 f8e8
info depth 19 multipv 1 score cp 22 nodes 4498627 nps 2496463 time 1802 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 b1c3 c8e6 f1d3 d8e8 e1g1 a8d8 c1e3 f8b4
info depth 20 multipv 1 score cp 25 nodes 12216630 nps 4190953 time 2915 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 d1a4 c8d7 a4d4 e6d5 c3d5 f6d5 d4d5 b8c6 c1g5 f7f6 d5e4 f8e7
info depth 21 multipv 1 score cp 22 nodes 17315365 nps 2182975 time 7932 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 f6d5 c1d2 d5c3 d2c3 f8c5 e2e3 e8g8 b2b4 c5e7 a1c1
info depth 22 multipv 1 score cp 31 nodes 29046643 nps 2583531 time 11243 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 f8e7 c4d5 e6d5 c1f4 e8g8 e2e3 c7c5 d4c5 b8c6 a1c1 c8f5 f1d3 f5d3 d1d3 e7c5
info depth 23 multipv 1 score cp 22 nodes 46988609 nps 2487485 time 18890 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 e6d5 c1f4 f8c5 e2e3 b8c6 a1c1 c5d4 e3d4 e8g8 f1e2 f8e8 e1g1
info depth 24 multipv 1 score cp 19 nodes 87144780 nps 2850104 time 30576 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 f6d5 c1d2 f8e7 e2e3 e8g8 f1c4 d5b6 c4b3 c8d7 a1c1 b8c6 e1g1 a8c8
info depth 25 multipv 1 score cp 23 nodes 153718826 nps 2653939 time 57921 pv d2d4 d7d5 c2c4 e7e6 g1f3 g8f6 b1c3 c7c5 c4d5 c5d4 f3d4 f6d5 c1d2 f8e7 e2e4 d5c3 d2c3 e8g8 a1c1 c8d7 f1d3 b8c6 d4c6 d7c6 e1g1
```

```
Score of ChessDotCpp2.27 vs ChessDotCpp2.26: 304 - 154 - 542  [0.575] 1000
...      ChessDotCpp2.27 playing White: 156 - 77 - 268  [0.579] 501
...      ChessDotCpp2.27 playing Black: 148 - 77 - 274  [0.571] 499
...      White vs Black: 233 - 225 - 542  [0.504] 1000
Elo difference: 52.5 +/- 14.5, LOS: 100.0 %, DrawRatio: 54.2 %

Score of ChessDotCpp2.27 vs wyldchess: 411 - 23 - 66  [0.888] 500
...      ChessDotCpp2.27 playing White: 207 - 9 - 34  [0.896] 250
...      ChessDotCpp2.27 playing Black: 204 - 14 - 32  [0.880] 250
...      White vs Black: 221 - 213 - 66  [0.508] 500
Elo difference: 359.7 +/- 39.9, LOS: 100.0 %, DrawRatio: 13.2 %

Score of ChessDotCpp2.27 vs supernova: 393 - 32 - 75  [0.861] 500
...      ChessDotCpp2.27 playing White: 199 - 18 - 33  [0.862] 250
...      ChessDotCpp2.27 playing Black: 194 - 14 - 42  [0.860] 250
...      White vs Black: 213 - 212 - 75  [0.501] 500
Elo difference: 316.8 +/- 36.8, LOS: 100.0 %, DrawRatio: 15.0 %

Score of ChessDotCpp2.27 vs greko: 308 - 72 - 120  [0.736] 500
...      ChessDotCpp2.27 playing White: 148 - 34 - 67  [0.729] 249
...      ChessDotCpp2.27 playing Black: 160 - 38 - 53  [0.743] 251
...      White vs Black: 186 - 194 - 120  [0.492] 500
Elo difference: 178.1 +/- 28.8, LOS: 100.0 %, DrawRatio: 24.0 %

Score of ChessDotCpp2.27 vs glaurung: 295 - 114 - 91  [0.681] 500
...      ChessDotCpp2.27 playing White: 160 - 47 - 44  [0.725] 251
...      ChessDotCpp2.27 playing Black: 135 - 67 - 47  [0.637] 249
...      White vs Black: 227 - 182 - 91  [0.545] 500
Elo difference: 131.7 +/- 29.1, LOS: 100.0 %, DrawRatio: 18.2 %

Score of ChessDotCpp2.27 vs zurichess: 174 - 142 - 184  [0.532] 500
...      ChessDotCpp2.27 playing White: 85 - 70 - 96  [0.530] 251
...      ChessDotCpp2.27 playing Black: 89 - 72 - 88  [0.534] 249
...      White vs Black: 157 - 159 - 184  [0.498] 500
Elo difference: 22.3 +/- 24.2, LOS: 96.4 %, DrawRatio: 36.8 %

Score of ChessDotCpp2.27-4CPU vs zurichess: 83 - 35 - 82  [0.620] 200
...      ChessDotCpp2.27-4CPU playing White: 43 - 14 - 43  [0.645] 100
...      ChessDotCpp2.27-4CPU playing Black: 40 - 21 - 39  [0.595] 100
...      White vs Black: 64 - 54 - 82  [0.525] 200
Elo difference: 85.0 +/- 37.4, LOS: 100.0 %, DrawRatio: 41.0 %

Score of ChessDotCpp2.27-8CPU vs zurichess: 97 - 31 - 72  [0.665] 200
...      ChessDotCpp2.27-8CPU playing White: 51 - 16 - 33  [0.675] 100
...      ChessDotCpp2.27-8CPU playing Black: 46 - 15 - 39  [0.655] 100
...      White vs Black: 66 - 62 - 72  [0.510] 200
Elo difference: 119.1 +/- 39.5, LOS: 100.0 %, DrawRatio: 36.0 %
```

### 2.28

Scaling for endgame eval

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -518  | -386  | -419  | -1181 |       | -415  | -390  | -520  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -37  |  -85  |  -75  |  -47  |  -52  | -135  | -127  |  -53  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  37   |  85   |  75   |  47   |  52   |  135  |  127  |  53   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  518  |  386  |  419  | 1181  |       |  415  |  390  |  520  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 15
Midgame: 0
Endgame: 0
Phase: 24
```

```
info depth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 multipv 1 score cp 25 nodes 75 nps 75000 time 1 pv e2e3 b8c6
info depth 3 multipv 1 score cp 28 nodes 219 nps 219000 time 1 pv g1f3 d7d5 e2e3
info depth 4 multipv 1 score cp 23 nodes 504 nps 504000 time 1 pv d2d4 e7e6 g1f3 f8b4 c1d2
info depth 5 multipv 1 score cp 25 nodes 1464 nps 1464000 time 1 pv b1c3 d7d5 d2d4 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 2782 nps 1391000 time 2 pv g1f3 d7d5 d2d4 g8f6 c2c3 b8c6
info depth 7 multipv 1 score cp 35 nodes 8167 nps 2722333 time 3 pv e2e4 d7d5 e4d5 d8d5 d2d4 d5e4 c1e3 g8f6
info depth 8 multipv 1 score cp 35 nodes 11492 nps 1915333 time 6 pv e2e4 d7d5 e4d5 g8f6 d2d4 f6d5 c2c3 c7c6
info depth 9 multipv 1 score cp 32 nodes 24962 nps 3120250 time 8 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 10 multipv 1 score cp 24 nodes 43775 nps 2575000 time 17 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 g8f6
info depth 11 multipv 1 score cp 32 nodes 62009 nps 2214607 time 28 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f3e5 d8d5 d2d4 e4d3 e5d3
info depth 12 multipv 1 score cp 28 nodes 101947 nps 2614025 time 39 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 d7c6 d1d8 e8d8 c1g5
info depth 13 multipv 1 score cp 18 nodes 181796 nps 2885650 time 63 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1c4 f8b4 e1g1 e8g8 d2d3 d7d6 c1e3 b4c3 b2c3
info depth 14 multipv 1 score cp 21 nodes 302663 nps 2776724 time 109 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1c4 f8b4 e1g1 e8g8 d2d3 d7d6 c1d2 b4c3 d2c3
info depth 15 multipv 1 score cp 29 nodes 481047 nps 2717779 time 177 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 d2d3 e4f6 f1e2 b8c6 e1g1 d6d5 f1e1
info depth 16 multipv 1 score cp 26 nodes 865814 nps 3114438 time 278 pv e2e4 e7e5 g1f3 g8f6 f3e5 d7d6 e5f3 f6e4 b1c3 e4c3 d2c3 f8e7 f1d3 e8g8 e1g1 f8e8
info depth 17 multipv 1 score cp 35 nodes 1587576 nps 3194317 time 497 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c8d7 g1f3 h7h6 f1d3 b8c6 e1g1 a8c8 c1d2 c5d4 c3d4
info depth 18 multipv 1 score cp 29 nodes 2978280 nps 3254950 time 915 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c8d7 g1f3 h7h6 f1d3 b8c6 a2a3 c5d4 c3d4 g8e7 e1g1 a8c8
info depth 19 multipv 1 score cp 26 nodes 5106985 nps 2995299 time 1705 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c8d7 g1f3 h7h6 f1d3 b8c6 a2a3 c5d4 c3d4 c6e7 e1g1 a8c8 b1c3
info depth 20 multipv 1 score cp 33 nodes 8196995 nps 2780527 time 2948 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 b1c3 e8g8 h2h3 h7h6 c1e3 c8e6 d1e2 d8e7
info depth 21 multipv 1 score cp 25 nodes 12081004 nps 2558450 time 4722 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 b1d2 c8e6 f3g5 d8e7 g5e6 e7e6 h2h3 e8g8 d2c4
info depth 22 multipv 1 score cp 27 nodes 16718965 nps 2394924 time 6981 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 g8f6 d2d3 a7a6 b5c6 d7c6 b1d2 c8e6 b2b3 e8g8 c1b2 f6d7 h2h3 f7f6 d1e2 d8e7
info depth 23 multipv 1 score cp 33 nodes 28470064 nps 2945077 time 9667 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 a7a6 b5c6 d7c6 d2d4 e5d4 d1d4 f7f6 b1c3 c8e6 c1e3 g8e7 d4d1 e7g6 d1e2 e8g8 a1d1
info depth 24 multipv 1 score cp 32 nodes 48630939 nps 2954671 time 16459 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 a7a6 b5c6 d7c6 d2d4 c8g4 d4e5 g4f3 d1f3 d6e5 f1d1 d8f6 f3g4 e5b2 c1b2 f6b2 b1d2 a8d8
info depth 25 multipv 1 score cp 33 nodes 71761126 nps 2555231 time 28084 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 a7a6 b5c6 d7c6 d2d4 c8g4 d4e5 g4f3 d1f3 d6e5 f1d1 d8f6 f3g4 a8d8 d1d8 f6d8 b1c3 g8e7 c1e3 e7g6
```

```
Score of ChessDotCpp2.28 vs ChessDotCpp2.27: 261 - 197 - 542  [0.532] 1000
...      ChessDotCpp2.28 playing White: 131 - 89 - 280  [0.542] 500
...      ChessDotCpp2.28 playing Black: 130 - 108 - 262  [0.522] 500
...      White vs Black: 239 - 219 - 542  [0.510] 1000
Elo difference: 22.3 +/- 14.6, LOS: 99.9 %, DrawRatio: 54.2 %

Score of ChessDotCpp2.28 vs wyldchess: 8330 - 623 - 1047  [0.885] 10000
...      ChessDotCpp2.28 playing White: 4166 - 318 - 516  [0.885] 5000
...      ChessDotCpp2.28 playing Black: 4164 - 305 - 531  [0.886] 5000
...      White vs Black: 4471 - 4482 - 1047  [0.499] 10000
Elo difference: 355.1 +/- 9.2, LOS: 100.0 %, DrawRatio: 10.5 %

Score of ChessDotCpp2.28 vs glaurung: 286 - 107 - 107  [0.679] 500
...      ChessDotCpp2.28 playing White: 142 - 46 - 63  [0.691] 251
...      ChessDotCpp2.28 playing Black: 144 - 61 - 44  [0.667] 249
...      White vs Black: 203 - 190 - 107  [0.513] 500
Elo difference: 130.1 +/- 28.4, LOS: 100.0 %, DrawRatio: 21.4 %

Score of ChessDotCpp2.28 vs zurichess: 198 - 134 - 168  [0.564] 500
...      ChessDotCpp2.28 playing White: 93 - 66 - 91  [0.554] 250
...      ChessDotCpp2.28 playing Black: 105 - 68 - 77  [0.574] 250
...      White vs Black: 161 - 171 - 168  [0.490] 500
Elo difference: 44.7 +/- 24.9, LOS: 100.0 %, DrawRatio: 33.6 %

Score of ChessDotCpp2.28 vs zurichess: 687 - 308 - 505  [0.626] 1500
...      ChessDotCpp2.28 playing White: 348 - 154 - 248  [0.629] 750
...      ChessDotCpp2.28 playing Black: 339 - 154 - 257  [0.623] 750
...      White vs Black: 502 - 493 - 505  [0.503] 1500
Elo difference: 89.7 +/- 14.5, LOS: 100.0 %, DrawRatio: 33.7 %

Score of ChessDotCpp2.28 vs weiss2.0: 21 - 859 - 120  [0.081] 1000
...      ChessDotCpp2.28 playing White: 13 - 423 - 63  [0.089] 499
...      ChessDotCpp2.28 playing Black: 8 - 436 - 57  [0.073] 501
...      White vs Black: 449 - 431 - 120  [0.509] 1000
Elo difference: -421.9 +/- 30.7, LOS: 0.0 %, DrawRatio: 12.0 %
```

## Version 3

Implemented data generation and NNUE evaluation trained on self-play of ChessDotCpp 2.28.
This version performs around on-par with the previous one in self-play, despite not having efficient updates with a persistent accumulator, no SIMD code and only a very basic NNUE network.

### 3.0

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -521  | -362  | -408  | -1116 |       | -412  | -356  | -522  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -33  |  -94  |  -80  |  -73  |  -92  | -132  | -120  |  -36  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  38   |  102  |  96   |  73   |  79   |  134  |  109  |  60   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  499  |  347  |  390  | 1098  |       |  415  |  352  |  496  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 20
Phase: 24
```

```
info depth 1 multipv 1 score cp 74 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 35 nodes 72 nps 72000 time 1 pv e2e4 b8c6
info depth 3 multipv 1 score cp 54 nodes 171 nps 171000 time 1 pv g1f3 c7c6 e2e4
info depth 4 multipv 1 score cp 19 nodes 653 nps 653000 time 1 pv e2e4 c7c6 g1f3 d7d5
info depth 5 multipv 1 score cp 25 nodes 1720 nps 1720000 time 1 pv d2d3 c7c5 e2e4 b8c6 f1e2
info depth 6 multipv 1 score cp 17 nodes 3935 nps 1967500 time 2 pv e2e4 d7d5 e4d5 d8d5 g1f3 b8c6
info depth 7 multipv 1 score cp 30 nodes 11738 nps 2934500 time 4 pv e2e4 b8c6 d2d3 d7d5 e4d5 c6b4 g1f3 d8d5
info depth 8 multipv 1 score cp 17 nodes 29003 nps 2416916 time 12 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f1b5 b8d7 b5d7 d8d7
info depth 9 multipv 1 score cp 34 nodes 43352 nps 1605629 time 27 pv e2e4 e7e6 b1c3 d7d5 d2d4 d5e4 c3e4 g8f6 e4f6 d8f6
info depth 10 multipv 1 score cp 22 nodes 75466 nps 1886650 time 40 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 c6d4 f3d4 c5d4
info depth 11 multipv 1 score cp 41 nodes 112131 nps 1625086 time 69 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 b1c3
info depth 12 multipv 1 score cp 31 nodes 201613 nps 1996168 time 101 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1b5 d8e7
info depth 13 multipv 1 score cp 33 nodes 411190 nps 2310056 time 178 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 d4c5 f8c5 d2b3 c5e7 e4d5 d8d5 d1d5 e6d5
info depth 14 multipv 1 score cp 25 nodes 739688 nps 2060412 time 359 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 c5d4 e4d5 a7a6 d2b3 d8d5 d1d4 b8c6
info depth 15 multipv 1 score cp 35 nodes 1012206 nps 1564460 time 647 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 g8f6 e4e5 f6e4 f1e2 b8c6 c2c3 c5d4 c3d4
info depth 16 multipv 1 score cp 30 nodes 1509656 nps 1711628 time 882 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 g8f6 e4d5 e6d5 f1b5 b8d7 e1g1 f8e7 f1e1 e8g8 c2c3
info depth 17 multipv 1 score cp 30 nodes 2170362 nps 1659298 time 1308 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 c5d4 e4d5 d8d5 f1c4 d5c5 c2c3 d4c3 b2c3 g8f6 e1g1
info depth 18 multipv 1 score cp 27 nodes 3880794 nps 2065350 time 1879 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 b8c6 f1b5 d8e7 b5e2 c6d4 f3d4 c5d4 d2b3 e7b4 d1d2 b4d2 c1d2
info depth 19 multipv 1 score cp 28 nodes 6018806 nps 1794515 time 3354 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 f8e7 g1f3 c7c5 f1e2 e8g8 e1g1 c5d4 c3d4 b8c6 d2b3
info depth 20 multipv 1 score cp 28 nodes 8881220 nps 1701383 time 5220 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 c7c6 e1g1 f8e7 c2c3 e8g8 f1e1 b8d7 c1g5 f8e8 b1d2 c6c5
info depth 21 multipv 1 score cp 20 nodes 17033546 nps 2217043 time 7683 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 f8e8 c1g5 b8d7 b1d2 c7c5 a2a3 d8b6 d2b3
info depth 22 multipv 1 score cp 22 nodes 24047016 nps 1627547 time 14775 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 f8e8 f1e1 e7d6 e1e8 d8e8 b1d2 b8d7 d1b3 c7c6 a2a3
info depth 23 multipv 1 score cp 28 nodes 36608681 nps 1756991 time 20836 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 a2a3 f8e7 f1e2 c5d4 c3d4 e8g8 e1g1 f7f6 e5f6 d7f6 f1e1
info depth 24 multipv 1 score cp 20 nodes 60889965 nps 1920697 time 31702 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 f1d3 f8e7 e1g1 d8b6 d1a4 c5d4 c3d4 e8g8 d2b3 a7a5 c1d2 e7b4 d2b4 c6b4
info depth 25 multipv 1 score cp 22 nodes 92034549 nps 1741297 time 52854 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 f1d3 f8e7 e1g1 d8b6 d1a4 c5d4 c3d4 e8g8 d2b3 f7f6 c1e3 e7b4 d3e2 f6e5 d4e5
```

```
Score of ChessDotCpp3.0 vs ChessDotCpp2.28: 674 - 671 - 655  [0.501] 2000
...      ChessDotCpp3.0 playing White: 308 - 343 - 349  [0.482] 1000
...      ChessDotCpp3.0 playing Black: 366 - 328 - 306  [0.519] 1000
...      White vs Black: 636 - 709 - 655  [0.482] 2000
Elo difference: 0.5 +/- 12.5, LOS: 53.3 %, DrawRatio: 32.8 %

Score of ChessDotCpp3.0 vs vice: 498 - 0 - 2  [0.998] 500
...      ChessDotCpp3.0 playing White: 250 - 0 - 1  [0.998] 251
...      ChessDotCpp3.0 playing Black: 248 - 0 - 1  [0.998] 249
...      White vs Black: 250 - 248 - 2  [0.502] 500
Elo difference: 1079.2 +/- nan, LOS: 100.0 %, DrawRatio: 0.4 %

Score of ChessDotCpp3.0 vs simplex: 481 - 7 - 12  [0.974] 500
...      ChessDotCpp3.0 playing White: 239 - 6 - 5  [0.966] 250
...      ChessDotCpp3.0 playing Black: 242 - 1 - 7  [0.982] 250
...      White vs Black: 240 - 248 - 12  [0.492] 500
Elo difference: 629.4 +/- 90.3, LOS: 100.0 %, DrawRatio: 2.4 %

Score of ChessDotCpp3.0 vs cosette5: 465 - 9 - 26  [0.956] 500
...      ChessDotCpp3.0 playing White: 224 - 5 - 21  [0.938] 250
...      ChessDotCpp3.0 playing Black: 241 - 4 - 5  [0.974] 250
...      White vs Black: 228 - 246 - 26  [0.482] 500
Elo difference: 534.8 +/- 64.1, LOS: 100.0 %, DrawRatio: 5.2 %

Score of ChessDotCpp3.0 vs wyldchess: 410 - 40 - 50  [0.870] 500
...      ChessDotCpp3.0 playing White: 202 - 18 - 30  [0.868] 250
...      ChessDotCpp3.0 playing Black: 208 - 22 - 20  [0.872] 250
...      White vs Black: 224 - 226 - 50  [0.498] 500
Elo difference: 330.2 +/- 40.4, LOS: 100.0 %, DrawRatio: 10.0 %

Score of ChessDotCpp3.0 vs supernova: 384 - 44 - 72  [0.840] 500
...      ChessDotCpp3.0 playing White: 192 - 23 - 34  [0.839] 249
...      ChessDotCpp3.0 playing Black: 192 - 21 - 38  [0.841] 251
...      White vs Black: 213 - 215 - 72  [0.498] 500
Elo difference: 288.1 +/- 35.8, LOS: 100.0 %, DrawRatio: 14.4 %

Score of ChessDotCpp3.0 vs greko: 310 - 95 - 95  [0.715] 500
...      ChessDotCpp3.0 playing White: 162 - 49 - 40  [0.725] 251
...      ChessDotCpp3.0 playing Black: 148 - 46 - 55  [0.705] 249
...      White vs Black: 208 - 197 - 95  [0.511] 500
Elo difference: 159.8 +/- 29.6, LOS: 100.0 %, DrawRatio: 19.0 %

Score of ChessDotCpp3.0 vs glaurung: 272 - 134 - 94  [0.638] 500
...      ChessDotCpp3.0 playing White: 131 - 67 - 53  [0.627] 251
...      ChessDotCpp3.0 playing Black: 141 - 67 - 41  [0.649] 249
...      White vs Black: 198 - 208 - 94  [0.490] 500
Elo difference: 98.4 +/- 28.3, LOS: 100.0 %, DrawRatio: 18.8 %

Score of ChessDotCpp3.0 vs zurichess: 286 - 237 - 277  [0.531] 800
...      ChessDotCpp3.0 playing White: 144 - 115 - 141  [0.536] 400
...      ChessDotCpp3.0 playing Black: 142 - 122 - 136  [0.525] 400
...      White vs Black: 266 - 257 - 277  [0.506] 800
Elo difference: 21.3 +/- 19.5, LOS: 98.4 %, DrawRatio: 34.6 %
```

### 3.1

Persistent NNUE accumulator

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -521  | -362  | -408  | -1116 |       | -412  | -356  | -522  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -33  |  -94  |  -80  |  -73  |  -92  | -132  | -120  |  -36  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  38   |  102  |  96   |  73   |  79   |  134  |  109  |  60   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  499  |  347  |  390  | 1098  |       |  415  |  352  |  496  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 20
Phase: 24
```

```
info depth 1 multipv 1 score cp 74 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 35 nodes 72 nps 72000 time 1 pv e2e4 b8c6
info depth 3 multipv 1 score cp 54 nodes 171 nps 171000 time 1 pv g1f3 c7c6 e2e4
info depth 4 multipv 1 score cp 19 nodes 653 nps 653000 time 1 pv e2e4 c7c6 g1f3 d7d5
info depth 5 multipv 1 score cp 25 nodes 1720 nps 1720000 time 1 pv d2d3 c7c5 e2e4 b8c6 f1e2
info depth 6 multipv 1 score cp 17 nodes 3935 nps 3935000 time 1 pv e2e4 d7d5 e4d5 d8d5 g1f3 b8c6
info depth 7 multipv 1 score cp 30 nodes 11738 nps 3912666 time 3 pv e2e4 b8c6 d2d3 d7d5 e4d5 c6b4 g1f3 d8d5
info depth 8 multipv 1 score cp 17 nodes 29003 nps 4833833 time 6 pv e2e4 e7e5 g1f3 d7d5 e4d5 e5e4 f1b5 b8d7 b5d7 d8d7
info depth 9 multipv 1 score cp 34 nodes 43352 nps 2890133 time 15 pv e2e4 e7e6 b1c3 d7d5 d2d4 d5e4 c3e4 g8f6 e4f6 d8f6
info depth 10 multipv 1 score cp 22 nodes 75466 nps 3430272 time 22 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 c6d4 f3d4 c5d4
info depth 11 multipv 1 score cp 41 nodes 112131 nps 3114750 time 36 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 b1c3
info depth 12 multipv 1 score cp 31 nodes 201613 nps 3733574 time 54 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1b5 d8e7
info depth 13 multipv 1 score cp 33 nodes 411190 nps 4421397 time 93 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 d4c5 f8c5 d2b3 c5e7 e4d5 d8d5 d1d5 e6d5
info depth 14 multipv 1 score cp 25 nodes 739688 nps 3934510 time 188 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 c5d4 e4d5 a7a6 d2b3 d8d5 d1d4 b8c6
info depth 15 multipv 1 score cp 35 nodes 1012206 nps 3039657 time 333 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 g8f6 e4e5 f6e4 f1e2 b8c6 c2c3 c5d4 c3d4
info depth 16 multipv 1 score cp 30 nodes 1509656 nps 3354791 time 450 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 g8f6 e4d5 e6d5 f1b5 b8d7 e1g1 f8e7 f1e1 e8g8 c2c3
info depth 17 multipv 1 score cp 30 nodes 2170362 nps 3244188 time 669 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 g1f3 c5d4 e4d5 d8d5 f1c4 d5c5 c2c3 d4c3 b2c3 g8f6 e1g1
info depth 18 multipv 1 score cp 27 nodes 3880794 nps 4042493 time 960 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 b8c6 f1b5 d8e7 b5e2 c6d4 f3d4 c5d4 d2b3 e7b4 d1d2 b4d2 c1d2
info depth 19 multipv 1 score cp 28 nodes 6018806 nps 3503379 time 1718 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 f8e7 g1f3 c7c5 f1e2 e8g8 e1g1 c5d4 c3d4 b8c6 d2b3
info depth 20 multipv 1 score cp 28 nodes 8881220 nps 3337549 time 2661 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 c7c6 e1g1 f8e7 c2c3 e8g8 f1e1 b8d7 c1g5 f8e8 b1d2 c6c5
info depth 21 multipv 1 score cp 20 nodes 17033546 nps 4338651 time 3926 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 f8e8 c1g5 b8d7 b1d2 c7c5 a2a3 d8b6 d2b3
info depth 22 multipv 1 score cp 22 nodes 24047016 nps 3179140 time 7564 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 f8e8 f1e1 e7d6 e1e8 d8e8 b1d2 b8d7 d1b3 c7c6 a2a3
info depth 23 multipv 1 score cp 28 nodes 36608681 nps 3429705 time 10674 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 a2a3 f8e7 f1e2 c5d4 c3d4 e8g8 e1g1 f7f6 e5f6 d7f6 f1e1
info depth 24 multipv 1 score cp 20 nodes 60889965 nps 3743849 time 16264 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 f1d3 f8e7 e1g1 d8b6 d1a4 c5d4 c3d4 e8g8 d2b3 a7a5 c1d2 e7b4 d2b4 c6b4
info depth 25 multipv 1 score cp 22 nodes 92034549 nps 3415518 time 26946 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 f1d3 f8e7 e1g1 d8b6 d1a4 c5d4 c3d4 e8g8 d2b3 f7f6 c1e3 e7b4 d3e2 f6e5 d4e5
```

```
Score of ChessDotCpp3.1 vs ChessDotCpp3.0: 482 - 75 - 443  [0.704] 1000
...      ChessDotCpp3.1 playing White: 249 - 42 - 210  [0.707] 501
...      ChessDotCpp3.1 playing Black: 233 - 33 - 233  [0.700] 499
...      White vs Black: 282 - 275 - 443  [0.503] 1000
Elo difference: 150.1 +/- 16.1, LOS: 100.0 %, DrawRatio: 44.3 %

Finished game 502 (wyldchess vs ChessDotCpp3.1): 0-1 {Black mates}
Score of ChessDotCpp3.1 vs wyldchess: 435 - 19 - 46  [0.916] 500
...      ChessDotCpp3.1 playing White: 214 - 10 - 26  [0.908] 250
...      ChessDotCpp3.1 playing Black: 221 - 9 - 20  [0.924] 250
...      White vs Black: 223 - 231 - 46  [0.492] 500
Elo difference: 415.0 +/- 46.7, LOS: 100.0 %, DrawRatio: 9.2 %

Score of ChessDotCpp3.1 vs glaurung: 336 - 70 - 89  [0.769] 495
...      ChessDotCpp3.1 playing White: 169 - 31 - 48  [0.778] 248
...      ChessDotCpp3.1 playing Black: 167 - 39 - 41  [0.759] 247
...      White vs Black: 208 - 198 - 89  [0.510] 495
Elo difference: 208.6 +/- 31.5, LOS: 100.0 %, DrawRatio: 18.0 %

Score of ChessDotCpp3.1 vs zurichess: 265 - 77 - 158  [0.688] 500
...      ChessDotCpp3.1 playing White: 133 - 47 - 71  [0.671] 251
...      ChessDotCpp3.1 playing Black: 132 - 30 - 87  [0.705] 249
...      White vs Black: 163 - 179 - 158  [0.484] 500
Elo difference: 137.4 +/- 26.2, LOS: 100.0 %, DrawRatio: 31.6 %

Score of ChessDotCpp3.1 vs texel: 132 - 210 - 158  [0.422] 500
...      ChessDotCpp3.1 playing White: 65 - 105 - 80  [0.420] 250
...      ChessDotCpp3.1 playing Black: 67 - 105 - 78  [0.424] 250
...      White vs Black: 170 - 172 - 158  [0.498] 500
Elo difference: -54.6 +/- 25.4, LOS: 0.0 %, DrawRatio: 31.6 %

Score of ChessDotCpp3.1 vs weiss2.0: 34 - 367 - 99  [0.167] 500
...      ChessDotCpp3.1 playing White: 22 - 185 - 43  [0.174] 250
...      ChessDotCpp3.1 playing Black: 12 - 182 - 56  [0.160] 250
...      White vs Black: 204 - 197 - 99  [0.507] 500
Elo difference: -279.2 +/- 32.9, LOS: 0.0 %, DrawRatio: 19.8 %
```

### 3.2

NNUE 128 width hidden layer 

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -558  | -402  | -456  | -1170 |       | -433  | -394  | -541  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -51  | -110  | -103  | -110  | -104  | -122  | -123  |  -66  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  48   |  89   |  85   |  78   |  99   |  115  |  109  |  54   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  475  |  344  |  377  | 1002  |       |  376  |  342  |  509  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 5
Phase: 24
```

```
info depth 1 multipv 1 score cp 43 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 18 nodes 69 nps 69000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 26 nodes 170 nps 170000 time 1 pv b1c3 e7e6 g1f3
info depth 4 multipv 1 score cp 4 nodes 723 nps 723000 time 1 pv c2c3 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 35 nodes 1800 nps 1800000 time 1 pv g1f3 g8f6 g2g3 d7d5 f1g2
info depth 6 multipv 1 score cp 11 nodes 4008 nps 2004000 time 2 pv g1f3 d7d5 g2g3 e7e6 f1g2 c8d7
info depth 7 multipv 1 score cp 28 nodes 5823 nps 1941000 time 3 pv g1f3 d7d5 g2g3 g8f6 f1g2 c7c6 c2c3
info depth 8 multipv 1 score cp 20 nodes 17603 nps 4400750 time 4 pv e2e4 d7d5 e4d5 d8d5 g1f3 c8f5 d2d4 d5e4 c1e3 e4c2 d1c2 f5c2
info depth 9 multipv 1 score cp 39 nodes 25999 nps 2363545 time 11 pv e2e4 c7c5 g1f3 b8c6 c2c3 e7e6 f1b5 g8f6 b5c6 b7c6
info depth 10 multipv 1 score cp 24 nodes 47280 nps 3152000 time 15 pv e2e4 c7c5 b1c3 b8c6 f1b5 a7a6 b5c6 d7c6 g1f3 g8f6
info depth 11 multipv 1 score cp 24 nodes 104728 nps 3878814 time 27 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 b8c6 f1e2 c8f5 c2c3
info depth 12 multipv 1 score cp 25 nodes 185281 nps 3368745 time 55 pv e2e4 c7c5 g1f3 g7g6 c2c3 f8g7 d2d4 c5d4 c3d4 g8f6 b1c3 b8c6
info depth 13 multipv 1 score cp 32 nodes 317612 nps 3343284 time 95 pv e2e4 e7e6 d2d4 d7d5 b1c3 d5e4 c3e4 g8f6 e4f6 d8f6 c2c3 b8d7 g1f3 f8e7
info depth 14 multipv 1 score cp 26 nodes 563277 nps 3498614 time 161 pv e2e4 c7c5 g1f3 e7e6 c2c3 f8e7 f1e2 b8c6 e1g1 d7d5 e4d5 e6d5 d2d4 c8g4 d4c5 e7c5
info depth 15 multipv 1 score cp 35 nodes 1135751 nps 4056253 time 280 pv e2e4 c7c5 g1f3 b8c6 f1b5 g7g6 e1g1 f8g7 d2d3 g8f6 b5c6 b7c6 c2c4 e8g8 e4e5
info depth 16 multipv 1 score cp 27 nodes 1661742 nps 2988744 time 556 pv e2e4 c7c5 g1f3 e7e6 c2c3 b8c6 f1b5 g8e7 e1g1 a7a6 b5a4 e7g6 d2d4 c5d4 c3d4 f8e7
info depth 17 multipv 1 score cp 34 nodes 2531043 nps 3117048 time 812 pv e2e4 c7c5 g1f3 b8c6 f1b5 g7g6 b5c6 b7c6 d2d3 f8g7 e1g1 g8f6 e4e5 f6d5 c2c4 d5b4 b1c3
info depth 18 multipv 1 score cp 20 nodes 4396023 nps 3530942 time 1245 pv e2e4 c7c5 g1f3 b8c6 f1b5 g7g6 e1g1 f8g7 d2d3 g8f6 c2c4 e8g8 b5c6 b7c6 e4e5 f6g4 f1e1 d7d6
info depth 19 multipv 1 score cp 21 nodes 11212862 nps 5150602 time 2177 pv e2e4 c7c5 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 g1f3 b8c6 d1b3 d6e5 d4e5 e7e6 b1c3 f8b4 f1b5
info depth 20 multipv 1 score cp 19 nodes 15086514 nps 2730096 time 5526 pv e2e4 c7c5 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 g1f3 b8c6 f1c4 d6e5 f3e5 e7e6 e5c6 b7c6 e1g1 f8d6
info depth 21 multipv 1 score cp 18 nodes 26666876 nps 3553214 time 7505 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 c2c4 g8f6 d2d3 a7a6 b5a4 g7g6 e1g1 f8g7 b1c3 e8g8 c1d2 f6h5 f1e1 e7e6 h2h3 d8c7
info depth 22 multipv 1 score cp 30 nodes 47740710 nps 3580105 time 13335 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 c5d4 f3d4 f8e7 f1b5 c8d7 e1g1 g8f6 b5e2 e8g8 c2c3 f8e8 f1e1 b8c6 d2f3 c6d4 f3d4
info depth 23 multipv 1 score cp 27 nodes 70859805 nps 2988478 time 23711 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 c5d4 f3d4 b8c6 d2f3 f8d6 f1b5 g8e7 e1g1 e8g8 d4c6 b7c6 b5a4 f8e8 f1e1
info depth 24 multipv 1 score cp 19 nodes 99941905 nps 2836035 time 35240 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 b8d7 f1e1 f8e8 e1e8 d8e8 b1c3 c7c6 d1e2 e8e2 c3e2 h7h6
info depth 25 multipv 1 score cp 19 nodes 130969005 nps 2636464 time 49676 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 b1d2 h7h6 g5h4 c7c5 d4c5 d6c5 d2b3 c5b6 c2c3 b8c6 f1e1
```

```
Score of ChessDotCpp3.2 vs ChessDotCpp3.1: 184 - 93 - 223  [0.591] 500
...      ChessDotCpp3.2 playing White: 95 - 50 - 105  [0.590] 250
...      ChessDotCpp3.2 playing Black: 89 - 43 - 118  [0.592] 250
...      White vs Black: 138 - 139 - 223  [0.499] 500
Elo difference: 63.9 +/- 22.7, LOS: 100.0 %, DrawRatio: 44.6 %

Score of ChessDotCpp3.2 vs zurichess: 316 - 66 - 118  [0.750] 500
...      ChessDotCpp3.2 playing White: 159 - 31 - 60  [0.756] 250
...      ChessDotCpp3.2 playing Black: 157 - 35 - 58  [0.744] 250
...      White vs Black: 194 - 188 - 118  [0.506] 500
Elo difference: 190.8 +/- 29.2, LOS: 100.0 %, DrawRatio: 23.6 %
```

### 3.3

Retrain network on `43M` fens generated by ChessDotCpp 3.2

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -514  | -347  | -391  | -1020 |       | -379  | -345  | -541  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -40  |  -82  |  -84  |  -62  |  -88  | -124  |  -86  |  -62  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  41   |  101  |  80   |  80   |  73   |  121  |  114  |  45   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  441  |  333  |  396  |  993  |       |  366  |  332  |  472  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 35
Phase: 24
```

```
info depth 1 multipv 1 score cp 100 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 60 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 41 nodes 163 nps 163000 time 1 pv e2e4 g8f6 f1d3
info depth 4 multipv 1 score cp 40 nodes 427 nps 427000 time 1 pv e2e4 d7d5 e4e5 b8d7
info depth 5 multipv 1 score cp 33 nodes 899 nps 899000 time 1 pv e2e4 d7d5 e4e5 b8d7 d1h5
info depth 6 multipv 1 score cp 21 nodes 3097 nps 3097000 time 1 pv e2e4 d7d5 e4e5 d5d4 g1e2 b8d7
info depth 7 multipv 1 score cp 26 nodes 7160 nps 2386666 time 3 pv g2g3 d7d5 b2b3 d5d4 f1g2 g8f6 e2e4 d4e3 f2e3
info depth 8 multipv 1 score cp 22 nodes 27100 nps 5420000 time 5 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 d2d4 e5d4 f3d4
info depth 9 multipv 1 score cp 41 nodes 33753 nps 2250200 time 15 pv e2e4 e7e5 d2d4 e5d4 d1d4 b8c6 d4d2 g8f6 b1c3
info depth 10 multipv 1 score cp 26 nodes 77471 nps 4077421 time 19 pv c2c4 g8f6 b1c3 d7d5 c4d5 f6d5 g1f3 d5c3 b2c3 c7c6
info depth 11 multipv 1 score cp 27 nodes 170230 nps 4255750 time 40 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 b1c3 c8g4 c4d5 g4f3 e2f3 c6d5
info depth 12 multipv 1 score cp 15 nodes 354007 nps 4265144 time 83 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6 e4e5 d8e7
info depth 13 multipv 1 score cp 23 nodes 553006 nps 3311413 time 167 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 c7c5 c4d5 e6d5 f1e2 c8f5 b1c3
info depth 14 multipv 1 score cp 26 nodes 896716 nps 3489167 time 257 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 d7d6 f1b5 c7c6 b5e2 g8f6 b1c3
info depth 15 multipv 1 score cp 30 nodes 1489595 nps 3598055 time 414 pv e2e4 e7e5 g1f3 d7d6 b1c3 g8f6 f1c4 f8e7 e1g1 c7c5 d2d3 b8c6 c4b3 e8g8 f1e1
info depth 16 multipv 1 score cp 31 nodes 2107751 nps 3019700 time 698 pv e2e4 e7e5 g1f3 d7d6 f1c4 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4 g8f6 b1c3 f8e7 e4e5 d6e5 d4e5
info depth 17 multipv 1 score cp 26 nodes 3080564 nps 3127476 time 985 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 f8c5 d4c6 d8f6 d1e2 d7c6 b1c3 c8e6 c1e3 c5e3 e2e3
info depth 18 multipv 1 score cp 15 nodes 8074994 nps 5595976 time 1443 pv d2d4 g8f6 g1f3 e7e6 e2e3 d7d5 f1e2 c7c5 e1g1 c5d4 e3d4 f8e7 c2c4 b8c6 c1f4 d5c4 b1c3 e8g8 e2c4
info depth 19 multipv 1 score cp 17 nodes 17902212 nps 4787967 time 3739 pv g1f3 d7d5 d2d4 g8f6 c2c4 c7c6 e2e3 g7g6 f1e2 f8g7 b1c3 e8g8 e1g1 c8g4 d1b3 b7b6 c4d5 c6d5 a2a3
info depth 20 multipv 1 score cp 27 nodes 29537747 nps 3596900 time 8212 pv e2e4 c7c5 c2c3 d7d6 d2d4 g8f6 b1d2 g7g6 g1f3 f8g7 f1e2 e8g8 e1g1 d8c7 a2a4 e7e5 d4e5 d6e5 e2b5 b8c6 b5c6 b7c6
info depth 21 multipv 1 score cp 24 nodes 34738663 nps 2539375 time 13680 pv e2e4 c7c5 c2c3 d7d6 d2d4 g8f6 b1d2 c5d4 c3d4 e7e6 g1f3 f8e7 f1e2 e8g8 e1g1 h7h6 e4e5 d6e5 d4e5 f6d5 f1e1
info depth 22 multipv 1 score cp 21 nodes 46081644 nps 2856713 time 16131 pv e2e4 c7c5 c2c3 d7d6 d2d4 g8f6 d4c5 b8c6 b1d2 d6c5 g1f3 e7e6 f1b5 c8d7 e1g1 f8e7 f1e1 e8g8 b5f1 d8c7 h2h3 a7a6
info depth 23 multipv 1 score cp 29 nodes 63424710 nps 2964464 time 21395 pv e2e4 c7c5 c2c3 d7d6 d2d4 g8f6 d4c5 b8c6 b1d2 d6c5 g1f3 e7e6 f1b5 c8d7 e1g1 f8e7 b5a4 e8g8 e4e5 f6d5 f1e1 d5b6 a4b3
info depth 24 multipv 1 score cp 18 nodes 108200129 nps 3681653 time 29389 pv e2e4 c7c5 c2c3 e7e5 f1c4 b8c6 d2d3 g8f6 g1f3 f8d6 a2a3 d6c7 e1g1 e8g8 c4a2 h7h6 f1e1 d7d6 h2h3 b7b5 d3d4 c8e6 a2e6 f7e6 d4c5 d6c5
info depth 25 multipv 1 score cp 16 nodes 282723633 nps 5636885 time 50156 pv c2c4 g8f6 d2d4 e7e6 g1f3 f8e7 b1c3 d7d5 c1f4 e8g8 e2e3 b8d7 c4d5 f6d5 c3d5 e6d5 f1e2 c7c6 e1g1 d7f6 h2h3 e7d6 f4d6 d8d6
```

```
Score of ChessDotCpp3.3 vs ChessDotCpp3.2: 325 - 208 - 467  [0.558] 1000
...      ChessDotCpp3.3 playing White: 174 - 103 - 223  [0.571] 500
...      ChessDotCpp3.3 playing Black: 151 - 105 - 244  [0.546] 500
...      White vs Black: 279 - 254 - 467  [0.512] 1000
Elo difference: 40.8 +/- 15.7, LOS: 100.0 %, DrawRatio: 46.7 %

Score of ChessDotCpp3.3 vs zurichess: 323 - 51 - 126  [0.772] 500
...      ChessDotCpp3.3 playing White: 169 - 25 - 56  [0.788] 250
...      ChessDotCpp3.3 playing Black: 154 - 26 - 70  [0.756] 250
...      White vs Black: 195 - 179 - 126  [0.516] 500
Elo difference: 211.9 +/- 29.2, LOS: 100.0 %, DrawRatio: 25.2 %

Score of ChessDotCpp3.3 vs texel: 188 - 146 - 166  [0.542] 500
...      ChessDotCpp3.3 playing White: 92 - 77 - 82  [0.530] 251
...      ChessDotCpp3.3 playing Black: 96 - 69 - 84  [0.554] 249
...      White vs Black: 161 - 173 - 166  [0.488] 500
Elo difference: 29.3 +/- 24.9, LOS: 98.9 %, DrawRatio: 33.2 %
```

### 3.4

Relative-style `12*64 -> 128 -> 1` network `43M` fens generated by ChessDotCpp 3.2

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -536  | -381  | -434  | -1237 |       | -421  | -377  | -542  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -40  | -108  | -105  | -109  | -115  | -170  | -142  |  -64  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  46   |  97   |  75   |  80   |  66   |  130  |  115  |  42   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  473  |  370  |  413  | 1017  |       |  412  |  361  |  502  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 5
Phase: 24
```

```
info depth 1 multipv 1 score cp 34 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 4 nodes 85 nps 85000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 11 nodes 184 nps 184000 time 1 pv b1c3 e7e5 e2e4
info depth 4 multipv 1 score cp 2 nodes 418 nps 418000 time 1 pv b1c3 e7e5 e2e4 g8f6
info depth 5 multipv 1 score cp 23 nodes 1999 nps 1999000 time 1 pv b1c3 g8f6 d2d4 d7d5 g1f3
info depth 6 multipv 1 score cp 32 nodes 4678 nps 2339000 time 2 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 7 multipv 1 score cp 28 nodes 9891 nps 2472750 time 4 pv e2e4 c7c5 g1f3 g7g6 d2d4 c5d4 d1d4
info depth 8 multipv 1 score cp 30 nodes 14053 nps 2007571 time 7 pv e2e4 c7c5 d2d3 g7g6 b1c3 f8g7 c1e3 g8f6 e3c5
info depth 9 multipv 1 score cp 23 nodes 42416 nps 4712888 time 9 pv g1f3 g8f6 g2g3 d7d5 f1g2 e7e6 d2d3 f8e7 e1g1
info depth 10 multipv 1 score cp 25 nodes 90784 nps 3631360 time 25 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4
info depth 11 multipv 1 score cp 23 nodes 133516 nps 2670320 time 50 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 d2d4 e5d4 f3d4 f8e7 d4c6 d7c6 d1d8 e7d8
info depth 12 multipv 1 score cp 17 nodes 249365 nps 3415958 time 73 pv e2e4 e7e6 b1c3 d7d5 d2d4 f8b4 e4d5 e6d5 g1f3 g8f6 c1g5 b8c6
info depth 13 multipv 1 score cp 28 nodes 409617 nps 3079827 time 133 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 d2d4 e5d4 f3d4 f8b4 d4c6 b7c6 e4e5
info depth 14 multipv 1 score cp 18 nodes 583124 nps 2712204 time 215 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 d2d4 e5d4 f3d4 f8b4 d4c6 d7c6 d1d8 e8d8 e4e5 b4c3 b2c3
info depth 15 multipv 1 score cp 22 nodes 1026208 nps 3375684 time 304 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1e2 g8f6 e1g1 e8g8 c2c3 c7c6 f1e1
info depth 16 multipv 1 score cp 23 nodes 1589156 nps 2987135 time 532 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 f8e8 c2c3 c7c6
info depth 17 multipv 1 score cp 17 nodes 2647424 nps 3212893 time 824 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 c1g5 d5e4 c3e4 b8d7 e4f6 d7f6 g1f3 h7h6 g5f6 d8f6 c2c3 f8e7
info depth 18 multipv 1 score cp 16 nodes 4176611 nps 3028724 time 1379 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 c1g5 d5e4 c3e4 b8d7 e4f6 d7f6 g1f3 f8e7 f1e2 e8g8 g5f6 e7f6 e1g1
info depth 19 multipv 1 score cp 17 nodes 6079932 nps 2780032 time 2187 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 b1c3 c5d4 f3d4 b8c6 c1e3
info depth 20 multipv 1 score cp 20 nodes 8753329 nps 2750024 time 3183 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 f8e8 c1f4 c7c6 c2c3 d8b6 d1b3 b8d7 b3b6 d7b6
info depth 21 multipv 1 score cp 17 nodes 14774875 nps 3216824 time 4593 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 c1f4 e8g8 e1g1 c7c5 d4c5 e7c5 b1c3 f8e8 c3a4 c5e7 f1e1
info depth 22 multipv 1 score cp 19 nodes 23744317 nps 3068534 time 7738 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 c7c5 e1g1 c5d4 f3d4 f8e7 b1d2 e8g8 f1e1 c8d7 d2f3 b8c6 d4c6 d7c6
info depth 23 multipv 1 score cp 18 nodes 36102258 nps 2877591 time 12546 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 c1f4 e8g8 e1g1 c7c5 d4c5 e7c5 b1c3 b8c6 f1e1 f8e8 e1e8 d8e8 d3e2 c5b4
info depth 24 multipv 1 score cp 18 nodes 54700840 nps 2867521 time 19076 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 h2h3 c7c5 d4c5 e7c5 b1c3 b8c6 f1e1 h7h6 c3a4 c5e7 c1f4 f8e8
info depth 25 multipv 1 score cp 21 nodes 138178730 nps 4783257 time 28888 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 h2h3 c7c5 d4c5 e7c5 b1c3 f8e8 f1e1 h7h6 c3a4 c5d6 e1e8 d8e8 c2c4 b8c6 c4d5 f6d5
```

```
Score of ChessDotCpp3.4 vs ChessDotCpp3.3: 316 - 185 - 499  [0.566] 1000
...      ChessDotCpp3.4 playing White: 159 - 76 - 266  [0.583] 501
...      ChessDotCpp3.4 playing Black: 157 - 109 - 233  [0.548] 499
...      White vs Black: 268 - 233 - 499  [0.517] 1000
Elo difference: 45.8 +/- 15.2, LOS: 100.0 %, DrawRatio: 49.9 %

Score of ChessDotCpp3.4 vs texel: 239 - 126 - 135  [0.613] 500
...      ChessDotCpp3.4 playing White: 117 - 66 - 67  [0.602] 250
...      ChessDotCpp3.4 playing Black: 122 - 60 - 68  [0.624] 250
...      White vs Black: 177 - 188 - 135  [0.489] 500
Elo difference: 79.9 +/- 26.5, LOS: 100.0 %, DrawRatio: 27.0 %
```

### 3.5

Concat both accumulators when computing nnue output

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -522  | -378  | -426  | -1184 |  -66  | -424  | -385  | -520  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -48  | -105  | -106  | -100  |  -94  | -136  | -119  |  -48  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  47   |  104  |  102  |  91   |  88   |  127  |  114  |  47   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  513  |  377  |  420  | 1180  |  67   |  420  |  381  |  512  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 21
Phase: 24
```

```
info depth 1 multipv 1 score cp 14 nodes 25 nps 25000 time 1 pv g2g3
info depth 2 multipv 1 score cp 20 nodes 80 nps 80000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 8 nodes 278 nps 278000 time 1 pv c2c4 e7e6 g1f3
info depth 4 multipv 1 score cp 18 nodes 612 nps 612000 time 1 pv d2d4 g8f6 c2c4 e7e6
info depth 5 multipv 1 score cp 17 nodes 922 nps 922000 time 1 pv d2d4 g8f6 c2c4 e7e6 g1f3
info depth 6 multipv 1 score cp 16 nodes 5105 nps 5105000 time 1 pv d2d4 d7d5 c2c4 d5c4 g1f3 g8f6
info depth 7 multipv 1 score cp 17 nodes 14233 nps 3558250 time 4 pv c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 g1f3
info depth 8 multipv 1 score cp 19 nodes 18809 nps 2089888 time 9 pv c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 g1f3 b8c6
info depth 9 multipv 1 score cp 22 nodes 55390 nps 4615833 time 12 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 b1c3
info depth 10 multipv 1 score cp 23 nodes 101225 nps 3163281 time 32 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 c4d5 e6d5 e2e3 c7c5
info depth 11 multipv 1 score cp 16 nodes 186930 nps 3279473 time 57 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 e2e3 e7e6 f1e2 d5c4 e2c4
info depth 12 multipv 1 score cp 17 nodes 376120 nps 3582095 time 105 pv c2c4 e7e5 g2g3 b8c6 f1g2 g8f6 e2e3 g7g6 b1c3 f8g7 g1e2 e8g8
info depth 13 multipv 1 score cp 24 nodes 910137 nps 4396797 time 207 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 b8c6 e5c6 d7c6 f1e2 c6c5 e2b5 c7c6
info depth 14 multipv 1 score cp 20 nodes 1242116 nps 2509325 time 495 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 b5c6 d7c6 d2d3 f8c5 e1g1 d8e7 b1d2 e8g8
info depth 15 multipv 1 score cp 27 nodes 1872625 nps 2774259 time 675 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 f6e4 b5c6 d7c6 f1e1 e4d6 f3e5 f8e7 d2d4
info depth 16 multipv 1 score cp 24 nodes 2965226 nps 2907084 time 1020 pv e2e4 e7e6 d2d4 d7d5 b1c3 f8b4 d1g4 g7g6 c1g5 f7f6 g5d2 e6e5 g4g3 e5d4 c3d5 b4d2 e1d2
info depth 17 multipv 1 score cp 17 nodes 4599631 nps 2848068 time 1615 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c4 c7c5 b1c3 b8c6 d4c5 e7c5 c4d5 f6d5
info depth 18 multipv 1 score cp 17 nodes 6095599 nps 2423697 time 2515 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 g7g6 e1g1 f8g7 c2c4 e8g8 b1c3 f8e8 c4d5 f6d5
info depth 19 multipv 1 score cp 20 nodes 9607670 nps 2887787 time 3327 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 f1d3 c7c5 c2c3 c5d4 c3d4 d8b6 g1e2 b8c6 d2f3 f8b4 e1f1 b4e7
info depth 20 multipv 1 score cp 16 nodes 14101873 nps 2689144 time 5244 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 b8c6 e1g1 c8e6 c4d5 f6d5 f1e1 d5b4
info depth 21 multipv 1 score cp 13 nodes 23055146 nps 2980626 time 7735 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 b8c6 e1g1 c8e6 c4d5 f6d5 a2a3 d5c3 b2c3
info depth 22 multipv 1 score cp 16 nodes 31244396 nps 2466013 time 12670 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 c8e6 c4d5 f6d5 e1g1 f8e8 f1e1 c7c5 c3d5 e6d5
info depth 23 multipv 1 score cp 15 nodes 61405567 nps 3553768 time 17279 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 b8c6 f1d3 d8b6 d4c5 b6c5 e1g1 e7g6 b2b4 c5b6 f1e1 f8e7 b4b5 c6a5 b1d2
info depth 24 multipv 1 score cp 20 nodes 154634969 nps 4490372 time 34437 pv c2c4 e7e6 g1f3 g8f6 g2g3 d7d5 f1g2 h7h6 e1g1 f8e7 d2d4 e8g8 b1c3 b8d7 c4d5 e6d5 f1e1 f8e8 e2e4 d5e4 f3d2 c7c5 d2e4 f6e4 c3e4 c5d4 d1d4
info depth 25 multipv 1 score cp 18 nodes 220097762 nps 2548961 time 86348 pv c2c4 g8f6 g1f3 g7g6 d2d4 f8g7 g2g3 e8g8 f1g2 c7c6 b1c3 d7d5 c4d5 c6d5 e1g1 b8c6 f3e5 h7h6 d1a4 c8d7 e5d7 d8d7 c1f4 e7e6
```

```
Score of ChessDotCpp3.5 vs ChessDotCpp3.4: 277 - 217 - 506  [0.530] 1000
...      ChessDotCpp3.5 playing White: 152 - 108 - 240  [0.544] 500
...      ChessDotCpp3.5 playing Black: 125 - 109 - 266  [0.516] 500
...      White vs Black: 261 - 233 - 506  [0.514] 1000
Elo difference: 20.9 +/- 15.1, LOS: 99.7 %, DrawRatio: 50.6 %

Score of ChessDotCpp3.5 vs wyldchess: 479 - 2 - 19  [0.977] 500
...      ChessDotCpp3.5 playing White: 241 - 2 - 7  [0.978] 250
...      ChessDotCpp3.5 playing Black: 238 - 0 - 12  [0.976] 250
...      White vs Black: 241 - 240 - 19  [0.501] 500
Elo difference: 651.3 +/- 82.4, LOS: 100.0 %, DrawRatio: 3.8 %

Score of ChessDotCpp3.5 vs glaurung: 826 - 64 - 110  [0.881] 1000
...      ChessDotCpp3.5 playing White: 419 - 28 - 54  [0.890] 501
...      ChessDotCpp3.5 playing Black: 407 - 36 - 56  [0.872] 499
...      White vs Black: 455 - 435 - 110  [0.510] 1000
Elo difference: 347.8 +/- 28.7, LOS: 100.0 %, DrawRatio: 11.0 %

Score of ChessDotCpp3.5 vs zurichess: 381 - 38 - 81  [0.843] 500
...      ChessDotCpp3.5 playing White: 192 - 12 - 46  [0.860] 250
...      ChessDotCpp3.5 playing Black: 189 - 26 - 35  [0.826] 250
...      White vs Black: 218 - 201 - 81  [0.517] 500
Elo difference: 292.0 +/- 35.1, LOS: 100.0 %, DrawRatio: 16.2 %

Score of ChessDotCpp3.5 vs texel: 238 - 118 - 144  [0.620] 500
...      ChessDotCpp3.5 playing White: 117 - 56 - 77  [0.622] 250
...      ChessDotCpp3.5 playing Black: 121 - 62 - 67  [0.618] 250
...      White vs Black: 179 - 177 - 144  [0.502] 500
Elo difference: 85.0 +/- 26.2, LOS: 100.0 %, DrawRatio: 28.8 %

Score of ChessDotCpp3.5 vs weiss2.0: 94 - 249 - 157  [0.345] 500
...      ChessDotCpp3.5 playing White: 57 - 121 - 72  [0.372] 250
...      ChessDotCpp3.5 playing Black: 37 - 128 - 85  [0.318] 250
...      White vs Black: 185 - 158 - 157  [0.527] 500
Elo difference: -111.4 +/- 25.9, LOS: 0.0 %, DrawRatio: 31.4 %
```

### 3.6

Change from 32 to 16 bit nnue accumulators

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -522  | -378  | -426  | -1184 |  -66  | -424  | -385  | -520  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -48  | -105  | -106  | -100  |  -94  | -136  | -119  |  -48  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  47   |  104  |  102  |  91   |  88   |  127  |  114  |  47   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  513  |  377  |  420  | 1180  |  67   |  420  |  381  |  512  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 21
Phase: 24
```

```
info depth 1 multipv 1 score cp 14 nodes 25 nps 25000 time 1 pv g2g3
info depth 2 multipv 1 score cp 20 nodes 80 nps 80000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 8 nodes 278 nps 278000 time 1 pv c2c4 e7e6 g1f3
info depth 4 multipv 1 score cp 18 nodes 612 nps 612000 time 1 pv d2d4 g8f6 c2c4 e7e6
info depth 5 multipv 1 score cp 17 nodes 922 nps 922000 time 1 pv d2d4 g8f6 c2c4 e7e6 g1f3
info depth 6 multipv 1 score cp 16 nodes 5105 nps 5105000 time 1 pv d2d4 d7d5 c2c4 d5c4 g1f3 g8f6
info depth 7 multipv 1 score cp 17 nodes 14233 nps 4744333 time 3 pv c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 g1f3
info depth 8 multipv 1 score cp 19 nodes 18809 nps 2351125 time 8 pv c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 g1f3 b8c6
info depth 9 multipv 1 score cp 22 nodes 55390 nps 5539000 time 10 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 b1c3
info depth 10 multipv 1 score cp 23 nodes 101225 nps 3615178 time 28 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 c4d5 e6d5 e2e3 c7c5
info depth 11 multipv 1 score cp 16 nodes 186930 nps 3738600 time 50 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 e2e3 e7e6 f1e2 d5c4 e2c4
info depth 12 multipv 1 score cp 17 nodes 376120 nps 4179111 time 90 pv c2c4 e7e5 g2g3 b8c6 f1g2 g8f6 e2e3 g7g6 b1c3 f8g7 g1e2 e8g8
info depth 13 multipv 1 score cp 24 nodes 910137 nps 5142016 time 177 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 b8c6 e5c6 d7c6 f1e2 c6c5 e2b5 c7c6
info depth 14 multipv 1 score cp 20 nodes 1242116 nps 2943402 time 422 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 b5c6 d7c6 d2d3 f8c5 e1g1 d8e7 b1d2 e8g8
info depth 15 multipv 1 score cp 27 nodes 1872625 nps 3234240 time 579 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 f6e4 b5c6 d7c6 f1e1 e4d6 f3e5 f8e7 d2d4
info depth 16 multipv 1 score cp 24 nodes 2965226 nps 3388829 time 875 pv e2e4 e7e6 d2d4 d7d5 b1c3 f8b4 d1g4 g7g6 c1g5 f7f6 g5d2 e6e5 g4g3 e5d4 c3d5 b4d2 e1d2
info depth 17 multipv 1 score cp 17 nodes 4599631 nps 3321033 time 1385 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c4 c7c5 b1c3 b8c6 d4c5 e7c5 c4d5 f6d5
info depth 18 multipv 1 score cp 17 nodes 6095599 nps 2831211 time 2153 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 g7g6 e1g1 f8g7 c2c4 e8g8 b1c3 f8e8 c4d5 f6d5
info depth 19 multipv 1 score cp 20 nodes 9607670 nps 3379412 time 2843 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 f1d3 c7c5 c2c3 c5d4 c3d4 d8b6 g1e2 b8c6 d2f3 f8b4 e1f1 b4e7
info depth 20 multipv 1 score cp 16 nodes 14101873 nps 3156193 time 4468 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 b8c6 e1g1 c8e6 c4d5 f6d5 f1e1 d5b4
info depth 21 multipv 1 score cp 13 nodes 23055146 nps 3502224 time 6583 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 b8c6 e1g1 c8e6 c4d5 f6d5 a2a3 d5c3 b2c3
info depth 22 multipv 1 score cp 16 nodes 31244396 nps 2896486 time 10787 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 c8e6 c4d5 f6d5 e1g1 f8e8 f1e1 c7c5 c3d5 e6d5
info depth 23 multipv 1 score cp 15 nodes 61405567 nps 4188932 time 14659 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 b8c6 f1d3 d8b6 d4c5 b6c5 e1g1 e7g6 b2b4 c5b6 f1e1 f8e7 b4b5 c6a5 b1d2
info depth 24 multipv 1 score cp 20 nodes 154634969 nps 5349395 time 28907 pv c2c4 e7e6 g1f3 g8f6 g2g3 d7d5 f1g2 h7h6 e1g1 f8e7 d2d4 e8g8 b1c3 b8d7 c4d5 e6d5 f1e1 f8e8 e2e4 d5e4 f3d2 c7c5 d2e4 f6e4 c3e4 c5d4 d1d4
info depth 25 multipv 1 score cp 18 nodes 220097762 nps 3008032 time 73170 pv c2c4 g8f6 g1f3 g7g6 d2d4 f8g7 g2g3 e8g8 f1g2 c7c6 b1c3 d7d5 c4d5 c6d5 e1g1 b8c6 f3e5 h7h6 d1a4 c8d7 e5d7 d8d7 c1f4 e7e6
```

```
Score of ChessDotCpp3.6 vs ChessDotCpp3.5: 244 - 170 - 586  [0.537] 1000
...      ChessDotCpp3.6 playing White: 129 - 87 - 284  [0.542] 500
...      ChessDotCpp3.6 playing Black: 115 - 83 - 302  [0.532] 500
...      White vs Black: 212 - 202 - 586  [0.505] 1000
Elo difference: 25.8 +/- 13.8, LOS: 100.0 %, DrawRatio: 58.6 %
```

### 3.7

Initialize nnue layers with biases

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -522  | -378  | -426  | -1184 |  -66  | -424  | -385  | -520  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -48  | -105  | -106  | -100  |  -94  | -136  | -119  |  -48  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  47   |  104  |  102  |  91   |  88   |  127  |  114  |  47   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  513  |  377  |  420  | 1180  |  67   |  420  |  381  |  512  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 21
Phase: 24
```

```
info depth 1 multipv 1 score cp 14 nodes 25 nps 25000 time 1 pv g2g3
info depth 2 multipv 1 score cp 20 nodes 80 nps 80000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 8 nodes 278 nps 278000 time 1 pv c2c4 e7e6 g1f3
info depth 4 multipv 1 score cp 18 nodes 612 nps 612000 time 1 pv d2d4 g8f6 c2c4 e7e6
info depth 5 multipv 1 score cp 17 nodes 922 nps 922000 time 1 pv d2d4 g8f6 c2c4 e7e6 g1f3
info depth 6 multipv 1 score cp 16 nodes 5105 nps 5105000 time 1 pv d2d4 d7d5 c2c4 d5c4 g1f3 g8f6
info depth 7 multipv 1 score cp 17 nodes 14233 nps 4744333 time 3 pv c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 g1f3
info depth 8 multipv 1 score cp 19 nodes 18809 nps 2351125 time 8 pv c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 g1f3 b8c6
info depth 9 multipv 1 score cp 22 nodes 55390 nps 5539000 time 10 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 b1c3
info depth 10 multipv 1 score cp 23 nodes 101225 nps 3749074 time 27 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 c4d5 e6d5 e2e3 c7c5
info depth 11 multipv 1 score cp 16 nodes 186930 nps 3894375 time 48 pv d2d4 g8f6 c2c4 c7c6 g1f3 d7d5 e2e3 e7e6 f1e2 d5c4 e2c4
info depth 12 multipv 1 score cp 17 nodes 376120 nps 4373488 time 86 pv c2c4 e7e5 g2g3 b8c6 f1g2 g8f6 e2e3 g7g6 b1c3 f8g7 g1e2 e8g8
info depth 13 multipv 1 score cp 24 nodes 910137 nps 5449922 time 167 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 b8c6 e5c6 d7c6 f1e2 c6c5 e2b5 c7c6
info depth 14 multipv 1 score cp 20 nodes 1242116 nps 3074544 time 404 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 b5c6 d7c6 d2d3 f8c5 e1g1 d8e7 b1d2 e8g8
info depth 15 multipv 1 score cp 27 nodes 1872625 nps 3368030 time 556 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 f6e4 b5c6 d7c6 f1e1 e4d6 f3e5 f8e7 d2d4
info depth 16 multipv 1 score cp 24 nodes 2965226 nps 3542683 time 837 pv e2e4 e7e6 d2d4 d7d5 b1c3 f8b4 d1g4 g7g6 c1g5 f7f6 g5d2 e6e5 g4g3 e5d4 c3d5 b4d2 e1d2
info depth 17 multipv 1 score cp 17 nodes 4599631 nps 3497818 time 1315 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c4 c7c5 b1c3 b8c6 d4c5 e7c5 c4d5 f6d5
info depth 18 multipv 1 score cp 17 nodes 6095599 nps 2985112 time 2042 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 g7g6 e1g1 f8g7 c2c4 e8g8 b1c3 f8e8 c4d5 f6d5
info depth 19 multipv 1 score cp 20 nodes 9607670 nps 3561034 time 2698 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 f1d3 c7c5 c2c3 c5d4 c3d4 d8b6 g1e2 b8c6 d2f3 f8b4 e1f1 b4e7
info depth 20 multipv 1 score cp 16 nodes 14101873 nps 3336142 time 4227 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 b8c6 e1g1 c8e6 c4d5 f6d5 f1e1 d5b4
info depth 21 multipv 1 score cp 13 nodes 23055146 nps 3714378 time 6207 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 b8c6 e1g1 c8e6 c4d5 f6d5 a2a3 d5c3 b2c3
info depth 22 multipv 1 score cp 16 nodes 31244396 nps 3071909 time 10171 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 c2c4 e8g8 b1c3 c8e6 c4d5 f6d5 e1g1 f8e8 f1e1 c7c5 c3d5 e6d5
info depth 23 multipv 1 score cp 15 nodes 61405567 nps 4450001 time 13799 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 b8c6 f1d3 d8b6 d4c5 b6c5 e1g1 e7g6 b2b4 c5b6 f1e1 f8e7 b4b5 c6a5 b1d2
info depth 24 multipv 1 score cp 20 nodes 154634969 nps 5651862 time 27360 pv c2c4 e7e6 g1f3 g8f6 g2g3 d7d5 f1g2 h7h6 e1g1 f8e7 d2d4 e8g8 b1c3 b8d7 c4d5 e6d5 f1e1 f8e8 e2e4 d5e4 f3d2 c7c5 d2e4 f6e4 c3e4 c5d4 d1d4
info depth 25 multipv 1 score cp 18 nodes 220097762 nps 3187928 time 69041 pv c2c4 g8f6 g1f3 g7g6 d2d4 f8g7 g2g3 e8g8 f1g2 c7c6 b1c3 d7d5 c4d5 c6d5 e1g1 b8c6 f3e5 h7h6 d1a4 c8d7 e5d7 d8d7 c1f4 e7e6
```

```
Score of ChessDotCpp3.7 vs ChessDotCpp3.6: 446 - 371 - 1183  [0.519] 2000
...      ChessDotCpp3.7 playing White: 230 - 163 - 608  [0.533] 1001
...      ChessDotCpp3.7 playing Black: 216 - 208 - 575  [0.504] 999
...      White vs Black: 438 - 379 - 1183  [0.515] 2000
Elo difference: 13.0 +/- 9.7, LOS: 99.6 %, DrawRatio: 59.2 %

Score of ChessDotCpp3.7 vs ChessDotCpp2.28: 771 - 54 - 175  [0.859] 1000
...      ChessDotCpp3.7 playing White: 398 - 26 - 77  [0.871] 501
...      ChessDotCpp3.7 playing Black: 373 - 28 - 98  [0.846] 499
...      White vs Black: 426 - 399 - 175  [0.513] 1000
Elo difference: 313.2 +/- 24.8, LOS: 100.0 %, DrawRatio: 17.5 %

Score of ChessDotCpp3.7 vs zurichess: 389 - 23 - 88  [0.866] 500
...      ChessDotCpp3.7 playing White: 201 - 8 - 41  [0.886] 250
...      ChessDotCpp3.7 playing Black: 188 - 15 - 47  [0.846] 250
...      White vs Black: 216 - 196 - 88  [0.520] 500
Elo difference: 324.2 +/- 35.5, LOS: 100.0 %, DrawRatio: 17.6 %

Score of ChessDotCpp3.7 vs texel: 283 - 73 - 144  [0.710] 500
...      ChessDotCpp3.7 playing White: 149 - 30 - 72  [0.737] 251
...      ChessDotCpp3.7 playing Black: 134 - 43 - 72  [0.683] 249
...      White vs Black: 192 - 164 - 144  [0.528] 500
Elo difference: 155.5 +/- 27.1, LOS: 100.0 %, DrawRatio: 28.8 %

Score of ChessDotCpp3.7 vs weiss2.0: 114 - 211 - 175  [0.403] 500
...      ChessDotCpp3.7 playing White: 46 - 115 - 89  [0.362] 250
...      ChessDotCpp3.7 playing Black: 68 - 96 - 86  [0.444] 250
...      White vs Black: 142 - 183 - 175  [0.459] 500
Elo difference: -68.3 +/- 24.8, LOS: 0.0 %, DrawRatio: 35.0 %
```

### 3.8

Retrain network on `50M` fens generated by ChessDotCpp 3.7

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -513  | -406  | -442  | -1092 |  -64  | -427  | -384  | -530  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -64  |  -99  | -101  |  -87  | -102  | -142  | -121  |  -58  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  63   |  97   |  97   |  82   |  98   |  137  |  121  |  62   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  512  |  405  |  443  | 1095  |  68   |  424  |  382  |  531  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 27
Phase: 24
```

```
info depth 1 multipv 1 score cp 16 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 26 nodes 79 nps 79000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 19 nodes 226 nps 226000 time 1 pv g2g3 g8f6 f1g2
info depth 4 multipv 1 score cp 25 nodes 460 nps 460000 time 1 pv g2g3 g7g6 f1g2 f8g7
info depth 5 multipv 1 score cp 18 nodes 867 nps 867000 time 1 pv g2g3 g7g6 d2d4 f8g7 f1g2
info depth 6 multipv 1 score cp 23 nodes 2482 nps 2482000 time 1 pv g2g3 d7d5 f1g2 g7g6 g1f3 f8g7
info depth 7 multipv 1 score cp 14 nodes 7837 nps 3918500 time 2 pv g1f3 g8f6 e2e3 g7g6 f1e2 f8g7 d2d4
info depth 8 multipv 1 score cp 21 nodes 10948 nps 2189600 time 5 pv g1f3 g8f6 d2d4 g7g6 g2g3 d7d5 f1g2 f8g7
info depth 9 multipv 1 score cp 18 nodes 16729 nps 2389857 time 7 pv g1f3 g8f6 c2c4 g7g6 d2d4 f8g7 g2g3 c7c6 f1g2
info depth 10 multipv 1 score cp 16 nodes 28713 nps 3190333 time 9 pv g1f3 g8f6 c2c4 g7g6 d2d4 f8g7 g2g3 e8g8 f1g2 f8e8
info depth 11 multipv 1 score cp 27 nodes 103396 nps 6893066 time 15 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 c6d4 d1d4 g8f6 b1c3
info depth 12 multipv 1 score cp 21 nodes 213559 nps 4358346 time 49 pv e2e4 e7e6 d2d4 c7c5 g1f3 c5d4 f3d4 g8f6 b1c3 b8c6 f1e2 c6d4 d1d4
info depth 13 multipv 1 score cp 22 nodes 474471 nps 4744710 time 100 pv e2e4 c7c5 g1f3 g7g6 c2c3 f8g7 d2d4 d7d5 e4e5 b8c6 f1e2 c5d4 c3d4
info depth 14 multipv 1 score cp 22 nodes 838416 nps 3810981 time 220 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 f1e1 f8e8
info depth 15 multipv 1 score cp 21 nodes 1302534 nps 3339830 time 390 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c5d4 c3d4 f8b4 b1c3 g8e7 f1d3 b8c6 g1f3 e8g8
info depth 16 multipv 1 score cp 19 nodes 2107070 nps 3477013 time 606 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 d1e2 d8e7 e2e7 d6e7 e1g1 e8g8 f1e1 f8e8
info depth 17 multipv 1 score cp 17 nodes 3833500 nps 3899796 time 983 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 f1e1
info depth 18 multipv 1 score cp 18 nodes 5680569 nps 3175276 time 1789 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8b6 g1f3 b8c6 f1d3 c5d4 c3d4 f8b4 b1c3 g8e7 c1e3 b4c3 b2c3 e8g8
info depth 19 multipv 1 score cp 25 nodes 8166501 nps 3084026 time 2648 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 d1e2 d8e7 e2e7 d6e7 c1f4 c7c6 b1c3 e8g8 e1g1 f8e8 a1e1
info depth 20 multipv 1 score cp 24 nodes 11289944 nps 2957805 time 3817 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 d1e2 d8e7 e2e7 d6e7 c1f4 c7c6 b1c3 f6h5 f4d2 c8g4 d3e2 e8g8
info depth 21 multipv 1 score cp 20 nodes 17266402 nps 3262736 time 5292 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 d1e2 c8e6 f3g5 d8d7 g5e6 d7e6 e1g1 b8c6 c2c3 e8g8 c1g5 a8e8 e2e6 e8e6
info depth 22 multipv 1 score cp 14 nodes 31289351 nps 3844372 time 8139 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 c7c5 c2c3 c5c4 d3c2 f8d6 d1e2 d8e7 e2e7 d6e7 e1g1 e8g8 f1e1 b8c6 c1f4 f8e8
info depth 23 multipv 1 score cp 22 nodes 50989995 nps 3452267 time 14770 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 c2c3 f8e8 c1g5 b8d7 f1e1 c7c5 g5h4 c5c4 d3e2 d8b6 b2b3
info depth 24 multipv 1 score cp 18 nodes 80144627 nps 3329371 time 24072 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 b1c3 b8c6 c3b5 c6b4 b5d6 d8d6 f1e1 b4d3 d1d3 c8d7 c1g5 f8e8
info depth 25 multipv 1 score cp 20 nodes 127136703 nps 3355947 time 37884 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 b1c3 f8e7 f1g2 e6e5 e1g1 d7d6 d2d3 g8f6 c3d5 e8g8 c2c3 h7h6 f1e1 b7b5 a2a3 f6d5 e4d5 c6a5
```

```
Score of ChessDotCpp3.8 vs ChessDotCpp3.7: 300 - 205 - 495  [0.547] 1000
...      ChessDotCpp3.8 playing White: 163 - 88 - 248  [0.575] 499
...      ChessDotCpp3.8 playing Black: 137 - 117 - 247  [0.520] 501
...      White vs Black: 280 - 225 - 495  [0.527] 1000
Elo difference: 33.1 +/- 15.3, LOS: 100.0 %, DrawRatio: 49.5 %

Score of ChessDotCpp3.8 vs texel: 288 - 83 - 129  [0.705] 500
...      ChessDotCpp3.8 playing White: 146 - 37 - 68  [0.717] 251
...      ChessDotCpp3.8 playing Black: 142 - 46 - 61  [0.693] 249
...      White vs Black: 192 - 179 - 129  [0.513] 500
Elo difference: 151.3 +/- 27.8, LOS: 100.0 %, DrawRatio: 25.8 %

Score of ChessDotCpp3.8 vs weiss2.0: 148 - 189 - 163  [0.459] 500
...      ChessDotCpp3.8 playing White: 75 - 99 - 76  [0.452] 250
...      ChessDotCpp3.8 playing Black: 73 - 90 - 87  [0.466] 250
...      White vs Black: 165 - 172 - 163  [0.493] 500
Elo difference: -28.6 +/- 25.1, LOS: 1.3 %, DrawRatio: 32.6 %
```
### 3.9

Manual AVX2 simd for nnue eval

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -513  | -406  | -442  | -1092 |  -64  | -427  | -384  | -530  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -64  |  -99  | -101  |  -87  | -102  | -142  | -121  |  -58  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  63   |  97   |  97   |  82   |  98   |  137  |  121  |  62   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  512  |  405  |  443  | 1095  |  68   |  424  |  382  |  531  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 27
Phase: 24
```

```
info depth 1 multipv 1 score cp 16 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 26 nodes 79 nps 79000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 19 nodes 226 nps 226000 time 1 pv g2g3 g8f6 f1g2
info depth 4 multipv 1 score cp 25 nodes 460 nps 460000 time 1 pv g2g3 g7g6 f1g2 f8g7
info depth 5 multipv 1 score cp 18 nodes 867 nps 867000 time 1 pv g2g3 g7g6 d2d4 f8g7 f1g2
info depth 6 multipv 1 score cp 23 nodes 2482 nps 2482000 time 1 pv g2g3 d7d5 f1g2 g7g6 g1f3 f8g7
info depth 8 multipv 1 score cp 21 nodes 10948 nps 2189600 time 5 pv g1f3 g8f6 d2d4 g7g6 g2g3 d7d5 f1g2 f8g7
info depth 9 multipv 1 score cp 18 nodes 16729 nps 2788166 time 6 pv g1f3 g8f6 c2c4 g7g6 d2d4 f8g7 g2g3 c7c6 f1g2
info depth 10 multipv 1 score cp 16 nodes 28713 nps 3190333 time 9 pv g1f3 g8f6 c2c4 g7g6 d2d4 f8g7 g2g3 e8g8 f1g2 f8e8
info depth 11 multipv 1 score cp 27 nodes 103396 nps 6893066 time 15 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 c6d4 d1d4 g8f6 b1c3
info depth 12 multipv 1 score cp 21 nodes 213559 nps 4358346 time 49 pv e2e4 e7e6 d2d4 c7c5 g1f3 c5d4 f3d4 g8f6 b1c3 b8c6 f1e2 c6d4 d1d4
info depth 13 multipv 1 score cp 22 nodes 474471 nps 4792636 time 99 pv e2e4 c7c5 g1f3 g7g6 c2c3 f8g7 d2d4 d7d5 e4e5 b8c6 f1e2 c5d4 c3d4
info depth 14 multipv 1 score cp 22 nodes 838416 nps 3845944 time 218 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 f1e1 f8e8
info depth 15 multipv 1 score cp 21 nodes 1302534 nps 3409774 time 382 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c5d4 c3d4 f8b4 b1c3 g8e7 f1d3 b8c6 g1f3 e8g8
info depth 17 multipv 1 score cp 17 nodes 3833500 nps 3968426 time 966 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 f1e1
info depth 18 multipv 1 score cp 18 nodes 5680569 nps 3225763 time 1761 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8b6 g1f3 b8c6 f1d3 c5d4 c3d4 f8b4 b1c3 g8e7 c1e3 b4c3 b2c3 e8g8
info depth 19 multipv 1 score cp 25 nodes 8166501 nps 3114607 time 2622 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 d1e2 d8e7 e2e7 d6e7 c1f4 c7c6 b1c3 e8g8 e1g1 f8e8 a1e1
info depth 20 multipv 1 score cp 24 nodes 11289944 nps 2977305 time 3792 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 d1e2 d8e7 e2e7 d6e7 c1f4 c7c6 b1c3 f6h5 f4d2 c8g4 d3e2 e8g8
info depth 21 multipv 1 score cp 20 nodes 17266402 nps 3293229 time 5243 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 d1e2 c8e6 f3g5 d8d7 g5e6 d7e6 e1g1 b8c6 c2c3 e8g8 c1g5 a8e8 e2e6 e8e6
info depth 22 multipv 1 score cp 14 nodes 31289351 nps 3887358 time 8049 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 c7c5 c2c3 c5c4 d3c2 f8d6 d1e2 d8e7 e2e7 d6e7 e1g1 e8g8 f1e1 b8c6 c1f4 f8e8
info depth 23 multipv 1 score cp 22 nodes 50989995 nps 3496057 time 14585 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 c2c3 f8e8 c1g5 b8d7 f1e1 c7c5 g5h4 c5c4 d3e2 d8b6 b2b3
info depth 24 multipv 1 score cp 18 nodes 80144627 nps 3375647 time 23742 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 b1c3 b8c6 c3b5 c6b4 b5d6 d8d6 f1e1 b4d3 d1d3 c8d7 c1g5 f8e8
info depth 25 multipv 1 score cp 20 nodes 127136703 nps 3402561 time 37365 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 b1c3 f8e7 f1g2 e6e5 e1g1 d7d6 d2d3 g8f6 c3d5 e8g8 c2c3 h7h6 f1e1 b7b5 a2a3 f6d5 e4d5 c6a5
```

```
Score of ChessDotCpp3.9 vs ChessDotCpp3.8: 394 - 396 - 1210  [0.499] 2000
...      ChessDotCpp3.9 playing White: 205 - 192 - 604  [0.506] 1001
...      ChessDotCpp3.9 playing Black: 189 - 204 - 606  [0.492] 999
...      White vs Black: 409 - 381 - 1210  [0.507] 2000
Elo difference: -0.3 +/- 9.6, LOS: 47.2 %, DrawRatio: 60.5 %
```

### 3.10

* `12*64 -> 256 -> 1` network trained on `50M` fens generated by ChessDotCpp 3.7 and `90M` fens generated by ChessDotCpp 3.8

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -492  | -387  | -451  | -1073 |  -85  | -419  | -391  | -516  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -53  | -115  | -101  | -117  | -110  | -133  | -122  |  -52  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  53   |  113  |  98   |  113  |  106  |  127  |  118  |  51   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  468  |  383  |  446  | 1017  |  91   |  413  |  387  |  494  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 21
Phase: 24
```

```
info depth 1 multipv 1 score cp 20 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 19 nodes 76 nps 76000 time 1 pv b1c3 b8c6
info depth 3 multipv 1 score cp 14 nodes 175 nps 175000 time 1 pv g1f3 d7d5 b1c3
info depth 4 multipv 1 score cp 29 nodes 406 nps 406000 time 1 pv d2d4 b8c6 g1f3 d7d5
info depth 5 multipv 1 score cp 21 nodes 834 nps 834000 time 1 pv d2d4 d7d5 g1f3 b8c6 b1c3
info depth 6 multipv 1 score cp 30 nodes 1955 nps 1955000 time 1 pv d2d4 d7d5 b1c3 e7e6 g1f3 b8c6
info depth 7 multipv 1 score cp 20 nodes 5706 nps 2853000 time 2 pv d2d4 e7e6 g1f3 f8e7 b1c3 d7d5 c1f4
info depth 8 multipv 1 score cp 20 nodes 28801 nps 5760200 time 5 pv e2e4 c7c5 b1c3 b8c6 g1f3 e7e6 d2d4 c5d4 f3d4
info depth 9 multipv 1 score cp 22 nodes 41760 nps 2456470 time 17 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3
info depth 10 multipv 1 score cp 25 nodes 58214 nps 2328560 time 25 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 c3a4 e7e5 f1b5 g8f6 b5c6 d7c6
info depth 11 multipv 1 score cp 20 nodes 94070 nps 2687714 time 35 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 c3a4 g8f6 a4c5 e7e6 d2d4 f8c5 d4c5 f6e4
info depth 12 multipv 1 score cp 16 nodes 256426 nps 4748629 time 54 pv g1f3 g8f6 c2c4 e7e6 e2e3 d7d5 c4d5 e6d5 f1e2 c7c5 d2d4 b8c6
info depth 13 multipv 1 score cp 19 nodes 413971 nps 2999789 time 138 pv g1f3 g8f6 c2c4 e7e6 e2e3 f8e7 f1e2 e8g8 e1g1 b7b6 d1c2 c7c5 d2d4
info depth 14 multipv 1 score cp 20 nodes 882771 nps 4030917 time 219 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 d2d4 c8f5 c2c4 e8g8
info depth 15 multipv 1 score cp 19 nodes 1244788 nps 2688526 time 463 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d8e7 e2e7 d6e7 e1g1 e8g8 c1f4
info depth 16 multipv 1 score cp 15 nodes 2224162 nps 3416531 time 651 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 f1d3 c7c5 e4d5 f6d5 c3d5 d8d5 g1f3 c5d4 e1g1 b8c6
info depth 17 multipv 1 score cp 19 nodes 3061249 nps 2643565 time 1158 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 c8e6 e1g1 e8g8 c1g5 f8e8 b1c3 c7c6
info depth 18 multipv 1 score cp 16 nodes 4627789 nps 2903255 time 1594 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d8e7 b1c3 e8g8 e2e7 d6e7 c1f4 c7c6 e1g1
info depth 19 multipv 1 score cp 13 nodes 7921912 nps 3281653 time 2414 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c8g4 c2c3 e7d6 b1d2 f8e8 e1e8 d8e8
info depth 20 multipv 1 score cp 14 nodes 16465391 nps 3974267 time 4143 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 d2d4 d7d5 f1g2 e8g8 e1g1 b8d7 b2b3 d5c4 b3c4 c7c5 e2e3 c5d4 e3d4
info depth 21 multipv 1 score cp 15 nodes 24548104 nps 2849129 time 8616 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 d2d4 d7d5 f1g2 e8g8 e1g1 b8d7 b1d2 b7b6 b2b3 c8b7 c1b2 f8e8 f3e5 c7c5 e5d7 d8d7 d4c5 b6c5
info depth 22 multipv 1 score cp 20 nodes 48056996 nps 3740426 time 12848 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 d2d4 d7d5 f1g2 e8g8 e1g1 b8d7 d1c2 c7c6 b2b3 b7b5 b1d2 b5c4 b3c4 c6c5 c4d5 e6d5
info depth 23 multipv 1 score cp 18 nodes 78390807 nps 3100411 time 25284 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c7c5 d4c5 b8c6 b1c3 e7c5 g5f6 d8f6 c3d5 f6b2 f1e1
info depth 24 multipv 1 score cp 21 nodes 96878032 nps 2337395 time 41447 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c7c5 d4c5 e7c5 b1c3 c8e6 c3a4 c5e7 g5h4 h7h6 a4c3 b8c6
info depth 25 multipv 1 score cp 22 nodes 131595484 nps 2570575 time 51193 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 b8c6 g1f3 c5d4 c3d4 g8e7 f1d3 c6b4 d3e2 e7f5 e1g1 b4c6 b1c3 f8e7 a2a3 e8g8 b2b4 b7b6 f1e1
```

```
Score of ChessDotCpp3.10 vs ChessDotCpp3.9: 388 - 135 - 477  [0.626] 1000
...      ChessDotCpp3.10 playing White: 206 - 58 - 236  [0.648] 500
...      ChessDotCpp3.10 playing Black: 182 - 77 - 241  [0.605] 500
...      White vs Black: 283 - 240 - 477  [0.521] 1000

Score of ChessDotCpp3.10 vs texel: 345 - 48 - 107  [0.797] 500
...      ChessDotCpp3.10 playing White: 175 - 23 - 53  [0.803] 251
...      ChessDotCpp3.10 playing Black: 170 - 25 - 54  [0.791] 249
...      White vs Black: 200 - 193 - 107  [0.507] 500
Elo difference: 237.6 +/- 31.1, LOS: 100.0 %, DrawRatio: 21.4 %

Score of ChessDotCpp3.10 vs weiss2.0: 289 - 216 - 245  [0.549] 750
...      ChessDotCpp3.10 playing White: 154 - 98 - 123  [0.575] 375
...      ChessDotCpp3.10 playing Black: 135 - 118 - 122  [0.523] 375
...      White vs Black: 272 - 233 - 245  [0.526] 750
Elo difference: 33.9 +/- 20.4, LOS: 99.9 %, DrawRatio: 32.7 %
```

### 3.11

Accumulator stack for nnue eval

```
info depth 1 multipv 1 score cp 20 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 19 nodes 76 nps 76000 time 1 pv b1c3 b8c6
info depth 3 multipv 1 score cp 14 nodes 175 nps 175000 time 1 pv g1f3 d7d5 b1c3
info depth 4 multipv 1 score cp 29 nodes 406 nps 406000 time 1 pv d2d4 b8c6 g1f3 d7d5
info depth 5 multipv 1 score cp 21 nodes 834 nps 834000 time 1 pv d2d4 d7d5 g1f3 b8c6 b1c3
info depth 6 multipv 1 score cp 30 nodes 1955 nps 1955000 time 1 pv d2d4 d7d5 b1c3 e7e6 g1f3 b8c6
info depth 7 multipv 1 score cp 20 nodes 5706 nps 2853000 time 2 pv d2d4 e7e6 g1f3 f8e7 b1c3 d7d5 c1f4
info depth 8 multipv 1 score cp 20 nodes 28801 nps 7200250 time 4 pv e2e4 c7c5 b1c3 b8c6 g1f3 e7e6 d2d4 c5d4 f3d4
info depth 9 multipv 1 score cp 22 nodes 41760 nps 2320000 time 18 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3
info depth 10 multipv 1 score cp 25 nodes 58214 nps 2328560 time 25 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 c3a4 e7e5 f1b5 g8f6 b5c6 d7c6
info depth 11 multipv 1 score cp 20 nodes 94070 nps 2687714 time 35 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 c3a4 g8f6 a4c5 e7e6 d2d4 f8c5 d4c5 f6e4
info depth 12 multipv 1 score cp 16 nodes 256426 nps 4579035 time 56 pv g1f3 g8f6 c2c4 e7e6 e2e3 d7d5 c4d5 e6d5 f1e2 c7c5 d2d4 b8c6
info depth 13 multipv 1 score cp 19 nodes 413971 nps 2759806 time 150 pv g1f3 g8f6 c2c4 e7e6 e2e3 f8e7 f1e2 e8g8 e1g1 b7b6 d1c2 c7c5 d2d4
info depth 14 multipv 1 score cp 20 nodes 882771 nps 3517015 time 251 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 d2d4 c8f5 c2c4 e8g8
info depth 15 multipv 1 score cp 19 nodes 1244788 nps 2246909 time 554 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d8e7 e2e7 d6e7 e1g1 e8g8 c1f4
info depth 16 multipv 1 score cp 15 nodes 2224162 nps 2840564 time 783 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 f1d3 c7c5 e4d5 f6d5 c3d5 d8d5 g1f3 c5d4 e1g1 b8c6
info depth 17 multipv 1 score cp 19 nodes 3061249 nps 2163426 time 1415 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 c8e6 e1g1 e8g8 c1g5 f8e8 b1c3 c7c6
info depth 18 multipv 1 score cp 16 nodes 4627789 nps 2385458 time 1940 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d8e7 b1c3 e8g8 e2e7 d6e7 c1f4 c7c6 e1g1
info depth 19 multipv 1 score cp 13 nodes 7921912 nps 2786462 time 2843 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c8g4 c2c3 e7d6 b1d2 f8e8 e1e8 d8e8
info depth 20 multipv 1 score cp 14 nodes 16465391 nps 3640369 time 4523 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 d2d4 d7d5 f1g2 e8g8 e1g1 b8d7 b2b3 d5c4 b3c4 c7c5 e2e3 c5d4 e3d4
info depth 21 multipv 1 score cp 15 nodes 24548104 nps 2663928 time 9215 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 d2d4 d7d5 f1g2 e8g8 e1g1 b8d7 b1d2 b7b6 b2b3 c8b7 c1b2 f8e8 f3e5 c7c5 e5d7 d8d7 d4c5 b6c5
info depth 22 multipv 1 score cp 20 nodes 48056996 nps 3510628 time 13689 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 d2d4 d7d5 f1g2 e8g8 e1g1 b8d7 d1c2 c7c6 b2b3 b7b5 b1d2 b5c4 b3c4 c6c5 c4d5 e6d5
info depth 23 multipv 1 score cp 18 nodes 78390807 nps 2948685 time 26585 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c7c5 d4c5 b8c6 b1c3 e7c5 g5f6 d8f6 c3d5 f6b2 f1e1
info depth 24 multipv 1 score cp 21 nodes 96878032 nps 2243118 time 43189 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c7c5 d4c5 e7c5 b1c3 c8e6 c3a4 c5e7 g5h4 h7h6 a4c3 b8c6
info depth 25 multipv 1 score cp 22 nodes 131595484 nps 2460418 time 53485 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 b8c6 g1f3 c5d4 c3d4 g8e7 f1d3 c6b4 d3e2 e7f5 e1g1 b4c6 b1c3 f8e7 a2a3 e8g8 b2b4 b7b6 f1e1
```

```
Score of ChessDotCpp3.11 vs ChessDotCpp3.10: 206 - 166 - 628  [0.520] 1000
...      ChessDotCpp3.11 playing White: 108 - 79 - 314  [0.529] 501
...      ChessDotCpp3.11 playing Black: 98 - 87 - 314  [0.511] 499
...      White vs Black: 195 - 177 - 628  [0.509] 1000
Elo difference: 13.9 +/- 13.1, LOS: 98.1 %, DrawRatio: 62.8 %
```

### 3.12

* Retrain same nnue arch with same data but using a different LR and schedule
* Change nnue L1 scaling to 16

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -539  | -415  | -490  | -1137 |  -62  | -455  | -414  | -562  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -41  | -124  | -105  | -125  | -119  | -157  | -143  |  -68  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  41   |  122  |  104  |  121  |  113  |  150  |  142  |  69   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  522  |  413  |  485  | 1143  |  65   |  452  |  410  |  551  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 24
Phase: 24
```

```
info depth 1 multipv 1 score cp 20 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 23 nodes 68 nps 68000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 15 nodes 237 nps 237000 time 1 pv a2a3 g8f6 g1f3
info depth 4 multipv 1 score cp 9 nodes 582 nps 582000 time 1 pv d2d4 c7c5 d4c5 g8f6
info depth 5 multipv 1 score cp 14 nodes 1459 nps 1459000 time 1 pv c2c4 e7e6 g1f3 f8e7 d2d4
info depth 6 multipv 1 score cp 29 nodes 3728 nps 1864000 time 2 pv e2e4 e7e5 g1f3 g8f6 d1e2 d7d5 e4d5
info depth 7 multipv 1 score cp 11 nodes 8582 nps 2860666 time 3 pv e2e4 e7e6 d2d4 c7c5 g1f3 d8b6 d4c5 f8c5
info depth 8 multipv 1 score cp 18 nodes 16043 nps 2673833 time 6 pv g1f3 e7e6 e2e3 c7c5 f1e2 g8f6 e1g1 f8e7
info depth 9 multipv 1 score cp 16 nodes 21590 nps 2159000 time 10 pv g1f3 e7e6 e2e3 f8e7 d2d4 g8f6 c2c4 e8g8 f1e2
info depth 10 multipv 1 score cp 20 nodes 35186 nps 2706615 time 13 pv g1f3 e7e6 e2e3 f8e7 d2d4 g8f6 c2c4 e8g8 f1e2 d7d5 c4d5 e6d5
info depth 11 multipv 1 score cp 27 nodes 92342 nps 4397238 time 21 pv e2e4 c7c5 g1f3 b8c6 d2d4 c5d4 f3d4 e7e6 b1c3 f8e7 f1e2
info depth 12 multipv 1 score cp 20 nodes 216704 nps 4249098 time 51 pv g1f3 e7e6 e2e3 f8e7 d2d4 g8f6 c2c4 e8g8 f1e2 d7d5 c4d5 e6d5
info depth 13 multipv 1 score cp 21 nodes 416562 nps 3752810 time 111 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 25 nodes 634978 nps 3052778 time 208 pv e2e4 e7e6 b1c3 d7d5 d2d4 g8f6 f1d3 c7c5 e4d5 e6d5 g1f3 b8c6 e1g1 c5d4
info depth 15 multipv 1 score cp 19 nodes 1008087 nps 3180085 time 317 pv e2e4 e7e6 b1c3 d7d5 d2d4 g8f6 f1d3 c7c5 e4d5 e6d5 g1f3 f8e7 d4c5 e8g8 e1g1 e7c5
info depth 16 multipv 1 score cp 15 nodes 1820025 nps 3315163 time 549 pv e2e4 e7e6 b1c3 d7d5 d2d4 g8f6 f1d3 c7c5 e4d5 e6d5 g1f3 b8c6 d4c5 f8c5 d1e2 d8e7 e1g1 e7e2 d3e2
info depth 17 multipv 1 score cp 22 nodes 2679957 nps 2704295 time 991 pv e2e4 e7e6 b1c3 d7d5 d2d4 g8f6 f1d3 c7c5 e4d5 c5d4 d3b5 c8d7 d5e6 f7e6 d1d4 b8c6 b5c6 d7c6 d4d8 a8d8
info depth 18 multipv 1 score cp 14 nodes 4562495 nps 3007577 time 1517 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1e2 g8f6 c2c4 d5c4 e1g1 c8e6 b1d2 e8g8 e2c4 e6c4 d2c4
info depth 19 multipv 1 score cp 19 nodes 6302777 nps 2455308 time 2567 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c2c4 d5c4 d3c4 f8e8 b1c3 b8c6 h2h3
info depth 20 multipv 1 score cp 20 nodes 9153597 nps 2647844 time 3457 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c2c4 d5c4 d3c4 f8e8 b1c3 c7c6 f1e1 e8e1 d1e1
info depth 21 multipv 1 score cp 12 nodes 14896475 nps 3027123 time 4921 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 b8c6 c2c3 c6e7 b1d2 e7g6 d2f1 f8e8 e1e8 d8e8
info depth 22 multipv 1 score cp 12 nodes 22958140 nps 2824574 time 8128 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 b1c3 c7c6 f1e1 b8d7 c3e2 f8e8 c2c3 d6c7 e2g3 e8e1 d1e1
info depth 23 multipv 1 score cp 17 nodes 55516094 nps 4389665 time 12647 pv g1f3 g8f6 g2g3 e7e6 f1g2 f8e7 e1g1 d7d5 d2d4 b8d7 f3d2 e8g8 c2c4 a8b8 b1c3 d5c4 d2c4 b7b5 c4e5 b5b4 e5d7 c8d7
info depth 24 multipv 1 score cp 18 nodes 98922856 nps 3115680 time 31750 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 e4d5 e6d5 f1d3 h7h6 g1f3 g8f6 e1g1 e8g8 f1e1 f8e8 c2c3 e7d6 h2h3 e8e1 d1e1 b8c6 d2b3
info depth 25 multipv 1 score cp 22 nodes 147277157 nps 2616260 time 56293 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 c8e6 f3g5 d8e7 g5e6 e7e6 c2c3 e8g8 e2e6 f7e6 e1g1 b8d7 c1e3 a7a5 b1d2 a5a4
```

```
Score of ChessDotCpp3.12 vs ChessDotCpp3.11: 238 - 186 - 576  [0.526] 1000
...      ChessDotCpp3.12 playing White: 133 - 81 - 287  [0.552] 501
...      ChessDotCpp3.12 playing Black: 105 - 105 - 289  [0.500] 499
...      White vs Black: 238 - 186 - 576  [0.526] 1000
Elo difference: 18.1 +/- 14.0, LOS: 99.4 %, DrawRatio: 57.6 %

Score of ChessDotCpp3.12 vs weiss2.0: 188 - 143 - 169  [0.545] 500
...      ChessDotCpp3.12 playing White: 88 - 74 - 88  [0.528] 250
...      ChessDotCpp3.12 playing Black: 100 - 69 - 81  [0.562] 250
...      White vs Black: 157 - 174 - 169  [0.483] 500
Elo difference: 31.4 +/- 24.8, LOS: 99.3 %, DrawRatio: 33.8 %
```

### 3.13

Retrain same arch with `+50M` fens generated on 3.11

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -533  | -427  | -470  | -1115 |  -65  | -444  | -420  | -539  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -57  | -117  | -120  | -121  | -117  | -144  | -125  |  -56  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  57   |  114  |  115  |  116  |  112  |  139  |  119  |  55   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  525  |  422  |  466  | 1111  |  66   |  438  |  417  |  534  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 20
Phase: 24
```

```
info depth 1 multipv 1 score cp 23 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 38 nodes 71 nps 71000 time 1 pv e2e4 b8c6
info depth 3 multipv 1 score cp 18 nodes 191 nps 191000 time 1 pv g1f3 e7e6 e2e4
info depth 4 multipv 1 score cp 18 nodes 569 nps 569000 time 1 pv e2e4 e7e6 f1e2 d7d5
info depth 5 multipv 1 score cp 18 nodes 1954 nps 1954000 time 1 pv g1f3 e7e6 d2d4 d7d5 e2e3
info depth 6 multipv 1 score cp 20 nodes 3408 nps 1704000 time 2 pv g1f3 g8f6 g2g3 e7e6 f1g2 f8e7
info depth 7 multipv 1 score cp 22 nodes 8003 nps 2667666 time 3 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 e5d4 f3d4
info depth 8 multipv 1 score cp 22 nodes 12361 nps 2060166 time 6 pv e2e4 e7e5 b1c3 b8c6 g1f3 g8f6 d2d4 e5d4 f3d4
info depth 9 multipv 1 score cp 23 nodes 40587 nps 5073375 time 8 pv e2e4 c7c5 g1f3 e7e6 c2c3 b8c6 d2d4 g8f6 e4e5
info depth 10 multipv 1 score cp 23 nodes 54294 nps 2171760 time 25 pv e2e4 c7c5 g1f3 e7e6 b1c3 f8e7 f1b5 b8c6 e1g1 g8f6 b5c6 b7c6
info depth 11 multipv 1 score cp 31 nodes 84533 nps 2641656 time 32 pv e2e4 c7c5 g1f3 e7e6 f1e2 f8e7 e1g1 b8c6 f1e1 g8f6 e4e5
info depth 12 multipv 1 score cp 16 nodes 184734 nps 3622235 time 51 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 c1g5 d5e4 c3e4 f8e7 g5f6 e7f6 e4f6 d8f6
info depth 13 multipv 1 score cp 27 nodes 324079 nps 3057349 time 106 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 f8e7 d4c6 b7c6
info depth 14 multipv 1 score cp 27 nodes 514524 nps 2874435 time 179 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 f8e7 d4c6 b7c6
info depth 15 multipv 1 score cp 20 nodes 1028952 nps 3728086 time 276 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c6 c2c3
info depth 16 multipv 1 score cp 23 nodes 1523717 nps 2864129 time 532 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 c8e6 e1g1 e8g8 f1e1 b8d7 c2c3
info depth 17 multipv 1 score cp 15 nodes 2858965 nps 3614367 time 791 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 d4c5 b8c6 b1c3 e7c5
info depth 18 multipv 1 score cp 26 nodes 4306728 nps 2966066 time 1452 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 b1d2 f8e8 f1e1 c7c5 d2b3 c5d4 f3d4
info depth 19 multipv 1 score cp 26 nodes 5856666 nps 2663331 time 2199 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 h2h3 f8e8 c2c3 c8d7
info depth 20 multipv 1 score cp 22 nodes 8970244 nps 2876000 time 3119 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 e7d6 c1g5 f8e8 e2e8 d8e8 e1e8 f6e8
info depth 21 multipv 1 score cp 21 nodes 13693628 nps 2859391 time 4789 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 c7c5 c2c3 c5d4 c3d4 f8e7 e1g1 e8g8 b1c3 b8c6 f1e1 c8g4 c1g5 g4f3 d1f3 c6d4
info depth 22 multipv 1 score cp 26 nodes 22638759 nps 3086402 time 7335 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 c1g5 f8e8 c2c3 b8d7 f1e1 h7h6 g5h4 e7d6 e2e8 d8e8 e1e8 f6e8
info depth 23 multipv 1 score cp 16 nodes 47913074 nps 3847203 time 12454 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 f1e2 g8f6 e1g1 f8e7 d2d4 c5d4 f3d4 e8g8 c1e3 c6d4 d1d4 d7d6 d4d2 c8d7 f1e1 d8c7 h2h3
info depth 24 multipv 1 score cp 17 nodes 149135036 nps 5717271 time 26085 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 c1g5 f8e8 h2h3 b8d7 f1e1 e7d6 e2e8 d8e8 e1e8 f6e8 b1c3 d7b6 a1e1
info depth 25 multipv 1 score cp 24 nodes 204476158 nps 2462826 time 83025 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 g2g3 b8c6 f1g2 f8e7 e1g1 e8g8 f1e1 b7b5 d2d4 c5d4 c3d4 c8b7 b1c3 d5c3 b2c3 d8c7 d4d5
```

```
Score of ChessDotCpp3.13 vs ChessDotCpp3.12: 237 - 188 - 575  [0.524] 1000
...      ChessDotCpp3.13 playing White: 119 - 89 - 292  [0.530] 500
...      ChessDotCpp3.13 playing Black: 118 - 99 - 283  [0.519] 500
...      White vs Black: 218 - 207 - 575  [0.505] 1000
Elo difference: 17.0 +/- 14.0, LOS: 99.1 %, DrawRatio: 57.5 %
```

### 3.14

`12*64 -> 512 -> 1` network trained on `200M` fens

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -513  | -414  | -464  | -1046 |  -95  | -438  | -410  | -535  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -68  | -127  | -117  | -115  | -122  | -169  | -144  |  -71  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  66   |  122  |  114  |  109  |  116  |  158  |  137  |  71   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  506  |  410  |  460  | 1051  |  88   |  434  |  406  |  530  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 23
Phase: 24
```

```
info depth 1 multipv 1 score cp 21 nodes 26 nps 26000 time 1 pv c2c4
info depth 2 multipv 1 score cp 28 nodes 82 nps 82000 time 1 pv e2e3 c7c6
info depth 3 multipv 1 score cp 18 nodes 236 nps 236000 time 1 pv d2d4 g8f6 e2e3
info depth 4 multipv 1 score cp 26 nodes 382 nps 382000 time 1 pv d2d4 g8f6 e2e3 e7e6
info depth 5 multipv 1 score cp 12 nodes 875 nps 437500 time 2 pv d2d4 g8f6 e2e3 e7e6 f1e2
info depth 6 multipv 1 score cp 12 nodes 2974 nps 991333 time 3 pv g2g3 d7d5 f1g2 e7e6 d2d4 c7c5
info depth 7 multipv 1 score cp 23 nodes 7456 nps 1864000 time 4 pv e2e4 c7c5 g1f3 e7e6 f1e2 f8e7 e1g1
info depth 8 multipv 1 score cp 20 nodes 11332 nps 1618857 time 7 pv e2e4 c7c5 g1f3 e7e6 f1e2 f8e7 e1g1 g8f6
info depth 9 multipv 1 score cp 18 nodes 25134 nps 2513400 time 10 pv e2e4 e7e6 d2d4 c7c5 d4d5 g8f6 d5e6 f7e6 e4e5
info depth 10 multipv 1 score cp 21 nodes 49791 nps 2766166 time 18 pv e2e4 e7e6 b1c3 d7d5 d2d4 f8b4 e4d5 e6d5 f1e2 g8f6
info depth 11 multipv 1 score cp 19 nodes 122763 nps 3720090 time 33 pv d2d4 e7e6 c2c4 f8e7 g1f3 g8f6 e2e3 d7d5 f1e2 d5c4 d1a4 b8d7 a4c4
info depth 12 multipv 1 score cp 20 nodes 176552 nps 2385837 time 74 pv d2d4 e7e6 c2c4 f8e7 g1f3 g8f6 e2e3 e8g8 f1e2 f8e8 e1g1 c7c5 d4c5 e7c5
info depth 13 multipv 1 score cp 20 nodes 283506 nps 2700057 time 105 pv d2d4 e7e6 c2c4 f8e7 g1f3 g8f6 e2e3 c7c5 d4c5 e8g8 f1e2 f8e8 e1g1 e7c5
info depth 14 multipv 1 score cp 20 nodes 505511 nps 3063703 time 165 pv d2d4 e7e6 c2c4 f8e7 g1f3 g8f6 e2e3 c7c5 d4c5 e8g8 f1e2 f8e8 e1g1 e7c5
info depth 15 multipv 1 score cp 17 nodes 1105230 nps 3746542 time 295 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 f1d3 c7c5 e4d5 e6d5 g1f3 c5d4 f3d4 b8c6 d4c6 b7c6
info depth 16 multipv 1 score cp 19 nodes 1690581 nps 2446571 time 691 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 f1d3 c7c5 e4d5 e6d5 g1f3 c5d4 f3d4 b8c6 d3b5 c8d7
info depth 17 multipv 1 score cp 21 nodes 2855246 nps 2740159 time 1042 pv e2e4 c7c5 g1f3 e7e6 c2c4 b8c6 f1e2 f8e7 b1c3 g8f6 e1g1 e8g8 d2d4 c5d4 f3d4 f8e8 d4c6 d7c6
info depth 18 multipv 1 score cp 22 nodes 3942336 nps 2107074 time 1871 pv e2e4 c7c5 g1f3 e7e6 c2c4 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 e6d5 d2d4 c5d4 f3d4 d5c4 c1e3 c8d7 e2c4
info depth 19 multipv 1 score cp 23 nodes 5768679 nps 2242005 time 2573 pv e2e4 c7c5 g1f3 e7e6 c2c4 b8c6 f1e2 g8f6 b1c3 e6e5 d2d3 f8e7 c3d5 e8g8 e1g1 d7d6 h2h3 f6d5 c4d5
info depth 20 multipv 1 score cp 21 nodes 10300479 nps 2710652 time 3800 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1 h7h6 c2c4 b8c6 c4d5 c6b4 b1c3 f6d5 c3d5 b4d5
info depth 21 multipv 1 score cp 23 nodes 14344298 nps 2202748 time 6512 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 c1g5 b8d7 b1c3 f8e8 a1e1 c7c6 g5h4 e7d6
info depth 22 multipv 1 score cp 19 nodes 23487011 nps 2552381 time 9202 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 c1g5 f8e8 c2c3 c7c5 g5f6 e7f6 e2c2 b8c6 d3h7 g8h8
info depth 23 multipv 1 score cp 20 nodes 46163145 nps 3078363 time 14996 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 g2g3 g8f6 f1g2 f8e7 e4e5 f6g4 d1e2 e8g8 e1g1 f7f6 e5f6 g4f6 d2d3 h7h6 c1f4 d7d5 a1e1
info depth 24 multipv 1 score cp 18 nodes 68588946 nps 2288663 time 29969 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 g2g3 g8f6 f1g2 f8e7 e4e5 f6g4 d1e2 e8g8 e1g1 f7f6 e5f6 g4f6 d2d3 d7d5 f1e1 h7h6 a2a3 c8d7
info depth 25 multipv 1 score cp 16 nodes 118597658 nps 2659557 time 44593 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 g2g3 g8f6 f1g2 f8e7 e4e5 f6g4 d1e2 e8g8 e1g1 g4h6 d2d3 h6f5 c3e4 b7b6 c2c3 c8b7 c1f4 d7d5 e5d6 f5d6
```

```
Score of ChessDotCpp3.14 vs ChessDotCpp3.13: 219 - 175 - 606  [0.522] 1000
...      ChessDotCpp3.14 playing White: 114 - 85 - 300  [0.529] 499
...      ChessDotCpp3.14 playing Black: 105 - 90 - 306  [0.515] 501
...      White vs Black: 204 - 190 - 606  [0.507] 1000
```

### 3.15

Retrain nnue using `+65M` fens and new LR schedule

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -571  | -441  | -503  | -950  | -119  | -489  | -437  | -581  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -65  | -133  | -116  | -134  | -132  | -161  | -144  |  -63  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  64   |  130  |  113  |  131  |  128  |  155  |  140  |  64   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  563  |  438  |  499  |  951  |  117  |  484  |  432  |  571  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 23
Phase: 24
```

```
info depth 1 multipv 1 score cp 19 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 22 nodes 81 nps 81000 time 1 pv c2c4 g8f6
info depth 3 multipv 1 score cp 13 nodes 242 nps 242000 time 1 pv g1f3 c7c5 c2c4
info depth 4 multipv 1 score cp 19 nodes 381 nps 381000 time 1 pv g1f3 c7c5 c2c4 g8f6
info depth 5 multipv 1 score cp 21 nodes 1120 nps 1120000 time 1 pv c2c4 c7c5 g2g3 g8f6 f1g2
info depth 6 multipv 1 score cp 17 nodes 3382 nps 3382000 time 1 pv d2d4 g8f6 g1f3 g7g6 c2c4 f8g7
info depth 7 multipv 1 score cp 20 nodes 6130 nps 2043333 time 3 pv d2d4 g8f6 g1f3 g7g6 c2c4 f8g7 b1c3
info depth 8 multipv 1 score cp 23 nodes 11821 nps 2364200 time 5 pv d2d4 g8f6 g1f3 g7g6 g2g3 f8g7 f1g2 e8g8
info depth 9 multipv 1 score cp 21 nodes 29112 nps 3234666 time 9 pv d2d4 d7d5 e2e3 e7e6 c2c4 g8f6 c4d5 e6d5 f1e2
info depth 10 multipv 1 score cp 19 nodes 88935 nps 4680789 time 19 pv c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 b1c3 g8f6 g1f3 b8c6
info depth 11 multipv 1 score cp 25 nodes 216509 nps 4085075 time 53 pv e2e4 c7c5 b1c3 b8c6 g1f3 g7g6 f1c4 f8g7 e1g1 e7e6 f1e1
info depth 12 multipv 1 score cp 17 nodes 335987 nps 2666563 time 126 pv g1f3 e7e6 c2c4 d7d5 e2e3 g8f6 d2d4 f8e7 f1e2 e8g8 c4d5 e6d5
info depth 13 multipv 1 score cp 26 nodes 662003 nps 3310015 time 200 pv e2e4 c7c5 g1f3 g7g6 f1c4 f8g7 e1g1 d7d6 f1e1 g8f6 d2d4 c5d4 f3d4
info depth 14 multipv 1 score cp 20 nodes 929492 nps 2161609 time 430 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 f8e7 e1g1 g8f6 d2d4 c5d4 f3d4 e8g8
info depth 15 multipv 1 score cp 23 nodes 1273324 nps 2034063 time 626 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 b8c6 c3c4 d5b4 a2a3 b4a6 d4c5 a6c5
info depth 16 multipv 1 score cp 17 nodes 2487140 nps 2892023 time 860 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 e3d2 c7c5 d4c5 d6c5
info depth 17 multipv 1 score cp 18 nodes 3351602 nps 1878700 time 1784 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8e7 f1d3 g8f6 e1g1 e8g8 h2h3 f8e8 f1e1 c7c6 c2c4
info depth 18 multipv 1 score cp 24 nodes 4938147 nps 2047324 time 2412 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 f8e7 e1g1 g8f6 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 c1e3 f8e8
info depth 19 multipv 1 score cp 18 nodes 8327022 nps 2437652 time 3416 pv e2e4 c7c5 g1f3 e7e6 b1c3 a7a6 g2g3 b7b5 f1g2 c8b7 d2d3 d7d6 e1g1 g8f6 a2a4 b5b4 c3e2 b8c6 f1e1
info depth 20 multipv 1 score cp 19 nodes 13336999 nps 2345998 time 5685 pv e2e4 c7c5 g1f3 e7e6 f1e2 d7d6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 f3e1 e8g8 e1c2 b8c6 d2d3 c6d4 h2h3 a7a6
info depth 21 multipv 1 score cp 20 nodes 19702216 nps 2207283 time 8926 pv e2e4 c7c5 g1f3 e7e6 g2g3 d7d6 d2d4 c5d4 f3d4 f8e7 f1g2 g8f6 e1g1 a7a6 h2h3 e8g8 c1e3 c8d7 b1c3 f8e8 f1e1
info depth 22 multipv 1 score cp 19 nodes 34133534 nps 2625252 time 13002 pv e2e4 c7c5 g1f3 e7e6 g2g3 d7d6 c2c4 g8f6 b1c3 e6e5 f1g2 f8e7 e1g1 e8g8 d2d3 b8c6 h2h3 h7h6 b2b3 a7a6 c1b2 c8e6
info depth 23 multipv 1 score cp 18 nodes 77765058 nps 3497259 time 22236 pv c2c4 e7e5 g2g3 g8f6 f1g2 c7c6 g1f3 d7d6 e1g1 f8e7 b1c3 e8g8 d1c2 c8g4 h2h3 g4h5 f1d1 f8e8 d2d4 d8c7 b2b3 b8d7 e2e3
info depth 24 multipv 1 score cp 20 nodes 157158058 nps 3062137 time 51323 pv c2c4 g8f6 g2g3 g7g6 d2d4 c7c5 g1f3 f8g7 d4d5 a7a6 a2a4 e8g8 f1g2 e7e6 e1g1 e6d5 c4d5 d7d6 b1c3 b8d7 f1e1 a8b8 e2e4 f8e8
info depth 25 multipv 1 score cp 20 nodes 245045863 nps 2303495 time 106380 pv e2e4 c7c5 g1f3 e7e6 g2g3 d7d6 f1g2 g8f6 e4e5 d6e5 f3e5 f6d7 e5f3 b8c6 e1g1 d7f6 d1e2 f8e7 c2c3 e8g8 d2d4 c5d4 f1d1 c8d7 f3d4 c6d4 d1d4
```

```
Score of ChessDotCpp3.15 vs ChessDotCpp3.14: 246 - 172 - 582  [0.537] 1000
...      ChessDotCpp3.15 playing White: 131 - 80 - 289  [0.551] 500
...      ChessDotCpp3.15 playing Black: 115 - 92 - 293  [0.523] 500
...      White vs Black: 223 - 195 - 582  [0.514] 1000
Elo difference: 25.8 +/- 13.9, LOS: 100.0 %, DrawRatio: 58.2 %

Score of ChessDotCpp3.15 vs texel: 392 - 39 - 69  [0.853] 500
...      ChessDotCpp3.15 playing White: 196 - 18 - 36  [0.856] 250
...      ChessDotCpp3.15 playing Black: 196 - 21 - 33  [0.850] 250
...      White vs Black: 217 - 214 - 69  [0.503] 500
Elo difference: 305.5 +/- 36.9, LOS: 100.0 %, DrawRatio: 13.8 %

Score of ChessDotCpp3.15 vs weiss2.0: 229 - 117 - 154  [0.612] 500
...      ChessDotCpp3.15 playing White: 123 - 51 - 77  [0.643] 251
...      ChessDotCpp3.15 playing Black: 106 - 66 - 77  [0.580] 249
...      White vs Black: 189 - 157 - 154  [0.532] 500
Elo difference: 79.2 +/- 25.7, LOS: 100.0 %, DrawRatio: 30.8 %
```

### 3.16

Node limited search, fix search aborting

```
Score of ChessDotCpp3.16 vs ChessDotCpp3.15: 163 - 159 - 678  [0.502] 1000
...      ChessDotCpp3.16 playing White: 76 - 77 - 347  [0.499] 500
...      ChessDotCpp3.16 playing Black: 87 - 82 - 331  [0.505] 500
...      White vs Black: 158 - 164 - 678  [0.497] 1000
Elo difference: 1.4 +/- 12.2, LOS: 58.8 %, DrawRatio: 67.8 %
```

### 3.17

More aggressive internal iterative deepening

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -571  | -441  | -503  | -950  | -119  | -489  | -437  | -581  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -65  | -133  | -116  | -134  | -132  | -161  | -144  |  -63  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  64   |  130  |  113  |  131  |  128  |  155  |  140  |  64   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  563  |  438  |  499  |  951  |  117  |  484  |  432  |  571  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 23
Phase: 24
```

```
info depth 1 multipv 1 score cp 19 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 21 nodes 113 nps 113000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 21 nodes 632 nps 632000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 18 nodes 897 nps 897000 time 1 pv d2d4 g8f6 g1f3 d7d5
info depth 5 multipv 1 score cp 16 nodes 1460 nps 1460000 time 1 pv d2d4 g8f6 g1f3 d7d5 c1f4
info depth 6 multipv 1 score cp 18 nodes 3515 nps 1757500 time 2 pv g1f3 g8f6 c2c4 c7c5 b1c3 b8c6
info depth 7 multipv 1 score cp 21 nodes 6972 nps 1743000 time 4 pv c2c4 c7c5 g1f3 g8f6 g2g3 d7d5 c4d5 d8d5
info depth 8 multipv 1 score cp 21 nodes 15333 nps 2555500 time 6 pv c2c4 c7c5 g2g3 d7d5 c4d5 d8d5 g1f3 g8f6
info depth 9 multipv 1 score cp 20 nodes 30183 nps 2515250 time 12 pv c2c4 e7e6 d2d4 g8f6 g2g3 c7c5 d4d5 e6d5 c4d5
info depth 10 multipv 1 score cp 19 nodes 55507 nps 2523045 time 22 pv c2c4 e7e6 g1f3 d7d5 c4d5 e6d5 g2g3 f8e7 f1g2 g8f6
info depth 11 multipv 1 score cp 28 nodes 179748 nps 4493700 time 40 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 c6d4 e1g1 g7g6 f1e1
info depth 12 multipv 1 score cp 19 nodes 250376 nps 2003008 time 125 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8d6 b1c3 c7c6 d1e2 g8e7 c1g5
info depth 13 multipv 1 score cp 18 nodes 360155 nps 2081820 time 173 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 d2d4 e8g8 f1e1
info depth 14 multipv 1 score cp 19 nodes 564813 nps 2259252 time 250 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 b8c6 g1f3 d8b6 f1e2 c5d4 c3d4 g8e7
info depth 15 multipv 1 score cp 16 nodes 1107895 nps 2915513 time 380 pv d2d4 g8f6 g1f3 d7d5 e2e3 e7e6 f1e2 f8e7 e1g1 e8g8 c2c4 d5c4 e2c4 c7c5 d4c5
info depth 16 multipv 1 score cp 16 nodes 1962271 nps 2695427 time 728 pv g1f3 d7d5 g2g3 c7c5 c2c4 d5d4 d2d3 g8f6 f1g2 b8c6 e1g1 e7e5 e2e3 f8e7 e3d4 c5d4
info depth 17 multipv 1 score cp 17 nodes 3215502 nps 2285360 time 1407 pv g1f3 d7d5 c2c4 d5d4 e2e3 c7c5 d2d3 g8f6 f1e2 g7g6 e3d4 c5d4 e1g1 f8g7 b1d2 e8g8 d2b3
info depth 18 multipv 1 score cp 18 nodes 5447114 nps 2441557 time 2231 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 g2g3 a7a5 f1g2 f8b4 b1c3 e8g8 e1g1 b8d7 c4d5 e6d5 a2a3 b4c3 b2c3
info depth 19 multipv 1 score cp 18 nodes 8320029 nps 2331193 time 3569 pv g1f3 g8f6 c2c4 c7c5 g2g3 g7g6 f1g2 f8g7 d2d4 c5d4 f3d4 e8g8 b1c3 d8c7 e1g1 c7c4 d4b5
info depth 20 multipv 1 score cp 18 nodes 11204416 nps 2143565 time 5227 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 g2g3 f8e7 f1g2 e8g8 e1g1 b8d7 d1c2 c7c6 b1d2 b7b5 c4c5 h7h6 e2e4 a7a5
info depth 21 multipv 1 score cp 20 nodes 14100945 nps 1999283 time 7053 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 e1g1 c7c6 d1c2 b8d7 b2b3 b7b5 f1c1 b5c4 b3c4 c8a6
info depth 22 multipv 1 score cp 19 nodes 19102801 nps 2172006 time 8795 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 e1g1 c7c6 d1c2 b8d7 b2b3 b7b5 c4c5 a7a5 b1c3 b5b4 c3a4
info depth 23 multipv 1 score cp 19 nodes 42523006 nps 3556624 time 11956 pv c2c4 g8f6 g1f3 e7e6 d2d4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 e1g1 c7c6 d1c2 b8d7 b2b3 b7b6 f1d1 c8a6 d2f4 a8c8 h2h3 h7h6
info depth 24 multipv 1 score cp 18 nodes 61684519 nps 2302348 time 26792 pv c2c4 g8f6 g1f3 e7e6 d2d4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 e1g1 c7c6 d1c2 b7b6 d2f4 d5c4 c2c4 c8a6 c4c2 f6d5 f4b8 a8b8
info depth 25 multipv 1 score cp 22 nodes 93816631 nps 2390658 time 39243 pv c2c4 g8f6 g1f3 e7e6 g2g3 d7d5 f1g2 f8e7 e1g1 d5d4 e2e3 c7c5 e3d4 c5d4 f3e5 e8g8 d2d3 a7a5 b1d2 f6d7 e5d7 b8d7 d2b3 e6e5 f1e1
```

```
Score of ChessDotCpp3.17 vs ChessDotCpp3.16: 467 - 326 - 1207  [0.535] 2000
...      ChessDotCpp3.17 playing White: 244 - 152 - 604  [0.546] 1000
...      ChessDotCpp3.17 playing Black: 223 - 174 - 603  [0.524] 1000
...      White vs Black: 418 - 375 - 1207  [0.511] 2000
Elo difference: 24.5 +/- 9.6, LOS: 100.0 %, DrawRatio: 60.4 %
```

### 3.18

Retrain same nnue architecture on `+135M` fens

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -557  | -434  | -499  | -934  | -109  | -474  | -425  | -558  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -77  | -146  | -124  | -137  | -139  | -167  | -143  |  -63  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  76   |  142  |  121  |  131  |  135  |  161  |  140  |  65   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  539  |  427  |  488  |  900  |  102  |  464  |  418  |  541  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 23
Phase: 24
```

```
info depth 1 multipv 1 score cp 34 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 32 nodes 71 nps 71000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 12 nodes 190 nps 190000 time 1 pv d2d4 g8f6 b1d2
info depth 4 multipv 1 score cp 20 nodes 516 nps 516000 time 1 pv c2c4 g8f6 g1f3 c7c5
info depth 5 multipv 1 score cp 20 nodes 1038 nps 1038000 time 1 pv c2c4 g8f6 d2d4 c7c5 d4d5
info depth 6 multipv 1 score cp 20 nodes 2419 nps 1209500 time 2 pv c2c4 g8f6 d2d4 a7a6 d4d5 a6a5
info depth 7 multipv 1 score cp 15 nodes 5158 nps 1719333 time 3 pv g2g3 g8f6 g1f3 d7d5 f1g2 c7c5 c2c4 d5c4
info depth 8 multipv 1 score cp 23 nodes 10239 nps 2559750 time 4 pv g1f3 g8f6 g2g3 d7d5 f1g2 g7g6 d2d4 f8g7
info depth 9 multipv 1 score cp 19 nodes 32647 nps 4080875 time 8 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1e2
info depth 10 multipv 1 score cp 25 nodes 43847 nps 2087952 time 21 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1e2 f8b4 c1d2
info depth 11 multipv 1 score cp 33 nodes 81979 nps 2927821 time 28 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6 e4e5 f6d5 b1c3 d5f4 d2d4 f4e2 d1e2
info depth 12 multipv 1 score cp 17 nodes 184738 nps 3622313 time 51 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1b5 c7c6 b5e2 g8f6 e1g1 f8e7 f1e1
info depth 13 multipv 1 score cp 17 nodes 299829 nps 2701162 time 111 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 f1e1 e8g8 d2d4
info depth 14 multipv 1 score cp 19 nodes 512086 nps 2909579 time 176 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 15 multipv 1 score cp 19 nodes 811936 nps 2715505 time 299 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 d8e7 d3e2 g8f6 e1g1 e8g8 c2c4 d5c4 e2c4
info depth 16 multipv 1 score cp 22 nodes 1552473 nps 3296121 time 471 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 d7d6 d4c6 b7c6 e1g1 f8e7
info depth 17 multipv 1 score cp 26 nodes 2321893 nps 2585626 time 898 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 f8e7 d4c6 b7c6 e4e5 f6d5 c3d5 c6d5
info depth 18 multipv 1 score cp 26 nodes 3070043 nps 2291076 time 1340 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 f8e7 d4c6 b7c6 e4e5 f6d5 c3d5 c6d5
info depth 19 multipv 1 score cp 31 nodes 4496258 nps 2537391 time 1772 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7 f1e1
info depth 20 multipv 1 score cp 18 nodes 7375967 nps 2830378 time 2606 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 c1e3 d7d5 e4d5 f6d5 c3d5 d8d5 d4c6 d5c6
info depth 21 multipv 1 score cp 20 nodes 10174557 nps 2367828 time 4297 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 c1e3 d7d5 e4d5 e6d5 f1e1 f8e8 h2h3
info depth 22 multipv 1 score cp 18 nodes 15549879 nps 2612546 time 5952 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 d2d4 c5d4 f3d4 f8e7 e1g1 e8g8 c1f4 d7d5 e4d5 f6d5 c3d5 d8d5 d4b5 a7a6 d1d5 e6d5
info depth 23 multipv 1 score cp 18 nodes 21228221 nps 2319770 time 9151 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 d2d4 c5d4 f3d4 f8e7 c1e3 d7d6 e1g1 e8g8 h2h3 c6d4 d1d4 c8d7 f1d1 d7c6 d1d2
info depth 24 multipv 1 score cp 19 nodes 52834766 nps 4246143 time 12443 pv g1f3 d7d5 g2g3 g8f6 f1g2 g7g6 d2d4 f8g7 e1g1 e8g8 c2c4 c7c6 b1d2 a7a5 b2b3 a5a4 f1e1 b8d7 c4d5 c6d5 c1a3 b7b5 a1c1 c8b7
info depth 25 multipv 1 score cp 23 nodes 77081962 nps 2483310 time 31040 pv g1f3 d7d5 g2g3 g8f6 f1g2 g7g6 d2d4 f8g7 e1g1 e8g8 c2c4 c7c6 b1d2 f8e8 b2b3 c8f5 c1b2 b8d7 e2e3 f6e4 a1c1 a8c8 f1e1 e7e6 a2a4 e4d2 d1d2
```

```
Score of ChessDotCpp3.18 vs ChessDotCpp3.17: 221 - 151 - 628  [0.535] 1000
...      ChessDotCpp3.18 playing White: 114 - 70 - 315  [0.544] 499
...      ChessDotCpp3.18 playing Black: 107 - 81 - 313  [0.526] 501
...      White vs Black: 195 - 177 - 628  [0.509] 1000
Elo difference: 24.4 +/- 13.1, LOS: 100.0 %, DrawRatio: 62.8 %

Score of ChessDotCpp3.18 vs weiss2.0: 233 - 111 - 156  [0.622] 500
...      ChessDotCpp3.18 playing White: 114 - 56 - 79  [0.616] 249
...      ChessDotCpp3.18 playing Black: 119 - 55 - 77  [0.627] 251
...      White vs Black: 169 - 175 - 156  [0.494] 500
Elo difference: 86.5 +/- 25.7, LOS: 100.0 %, DrawRatio: 31.2 %
```

### 3.19

SEE pruning in AB search

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -557  | -434  | -499  | -934  | -109  | -474  | -425  | -558  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -77  | -146  | -124  | -137  | -139  | -167  | -143  |  -63  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  76   |  142  |  121  |  131  |  135  |  161  |  140  |  65   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  539  |  427  |  488  |  900  |  102  |  464  |  418  |  541  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 23
Phase: 24
```

Before time reporting fix
```
info depth 1 multipv 1 score cp 34 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 32 nodes 71 nps 71000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 12 nodes 190 nps 190000 time 1 pv d2d4 g8f6 b1d2
info depth 4 multipv 1 score cp 21 nodes 645 nps 645000 time 1 pv e2e4 c7c5 f1e2 g8f6
info depth 5 multipv 1 score cp 7 nodes 1063 nps 1063000 time 1 pv e2e4 c7c5 f1e2 g8f6 e4e5
info depth 6 multipv 1 score cp 14 nodes 2850 nps 1425000 time 2 pv d2d4 d7d5 b1d2 c7c5 d4c5 g8f6
info depth 7 multipv 1 score cp 24 nodes 6631 nps 2210333 time 3 pv e2e4 c7c5 b1c3 e7e6 g1f3 g8f6 d2d4 c5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 14406 nps 2881200 time 5 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6
info depth 9 multipv 1 score cp 27 nodes 23437 nps 2343700 time 10 pv e2e4 e7e6 d2d4 d7d5 b1c3 d5e4 c3e4 g8f6 e4f6 d8f6
info depth 10 multipv 1 score cp 26 nodes 42359 nps 2647437 time 16 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 d7d5 e4d5 e6d5
info depth 11 multipv 1 score cp 22 nodes 79727 nps 2952851 time 27 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3
info depth 12 multipv 1 score cp 25 nodes 125433 nps 2508660 time 50 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6
info depth 13 multipv 1 score cp 21 nodes 269004 nps 3448769 time 78 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 e1g1 e8g8 b5c6 d7c6 f3e5 b4c3 d2c3 f6e4
info depth 14 multipv 1 score cp 19 nodes 635566 nps 3972287 time 160 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 15 multipv 1 score cp 23 nodes 920166 nps 2493674 time 369 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 f8e7 d4c6 b7c6 e4e5
info depth 16 multipv 1 score cp 19 nodes 1568128 nps 2975574 time 527 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 24 nodes 2171857 nps 2454075 time 885 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 c7c5 b1c3 b8c6 c1g5
info depth 18 multipv 1 score cp 22 nodes 3231620 nps 2633757 time 1227 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 h2h3 e8g8 e1g1 c7c5 d4c5 b8d7 c1e3 d7c5
info depth 19 multipv 1 score cp 23 nodes 4400809 nps 2407444 time 1828 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 f1e1 b8d7 h2h3 g4h5 b1d2
info depth 20 multipv 1 score cp 24 nodes 7250034 nps 2896537 time 2503 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 b1c3 b8c6 f1b5 d5c3 b2c3 c8d7 c1g5 d8a5
info depth 21 multipv 1 score cp 21 nodes 10465266 nps 2526621 time 4142 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 b1c3 d5c3 b2c3 d8c7 f1e2 d6e5 d4e5 b8c6 e1g1 c6e5 f3e5 c7e5
info depth 22 multipv 1 score cp 15 nodes 19323401 nps 3228099 time 5986 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2 f8b4 d1d3 e8g8 e1g1 f8e8 d4c6 d7c6 a2a3 b4c3 d3c3 f6e4
info depth 23 multipv 1 score cp 17 nodes 23950621 nps 2161608 time 11080 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 f8e7 c1f4 d7d6 f1b5 c8d7 d4b3 a7a6 b5e2 e6e5 f4e3 g8f6 h2h3 e8g8 e1g1
info depth 24 multipv 1 score cp 24 nodes 30378486 nps 2218865 time 13691 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 f8e7 c1f4 d7d6 f4g3 e6e5 d4c6 b7c6 f1c4 h7h5 h2h3 h5h4 g3h2 g8f6 e1g1 e8g8
info depth 25 multipv 1 score cp 21 nodes 99316468 nps 5734538 time 17319 pv c2c4 g8f6 g1f3 e7e6 d2d4 d7d5 g2g3 f8e7 f1g2 e8g8 e1g1 c7c6 b1c3 b8d7 f3d2 h7h6 b2b3 b7b6 e2e4 d5e4 d2e4 f6e4 c3e4 c8b7 c1b2
```

After time reporting fix:
```
info depth 1 multipv 1 score cp 34 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 32 nodes 71 nps 71000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 12 nodes 190 nps 190000 time 1 pv d2d4 g8f6 b1d2
info depth 4 multipv 1 score cp 21 nodes 645 nps 645000 time 1 pv e2e4 c7c5 f1e2 g8f6
info depth 5 multipv 1 score cp 7 nodes 1063 nps 1063000 time 1 pv e2e4 c7c5 f1e2 g8f6 e4e5
info depth 6 multipv 1 score cp 14 nodes 2850 nps 950000 time 3 pv d2d4 d7d5 b1d2 c7c5 d4c5 g8f6
info depth 7 multipv 1 score cp 24 nodes 6631 nps 1326200 time 5 pv e2e4 c7c5 b1c3 e7e6 g1f3 g8f6 d2d4 c5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 14406 nps 1440600 time 10 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6
info depth 9 multipv 1 score cp 27 nodes 23437 nps 1562466 time 15 pv e2e4 e7e6 d2d4 d7d5 b1c3 d5e4 c3e4 g8f6 e4f6 d8f6
info depth 10 multipv 1 score cp 26 nodes 42359 nps 1629192 time 26 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 d7d5 e4d5 e6d5
info depth 11 multipv 1 score cp 22 nodes 79727 nps 1696319 time 47 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3
info depth 12 multipv 1 score cp 25 nodes 125433 nps 1718260 time 73 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6
info depth 13 multipv 1 score cp 21 nodes 269004 nps 1793360 time 150 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 f8b4 e1g1 e8g8 b5c6 d7c6 f3e5 b4c3 d2c3 f6e4
info depth 14 multipv 1 score cp 19 nodes 635566 nps 1836895 time 346 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 15 multipv 1 score cp 23 nodes 920166 nps 1851440 time 497 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 b1c3 f8e7 d4c6 b7c6 e4e5
info depth 16 multipv 1 score cp 19 nodes 1568128 nps 1866819 time 840 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 24 nodes 2171857 nps 1867460 time 1163 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 c7c5 b1c3 b8c6 c1g5
info depth 18 multipv 1 score cp 22 nodes 3231620 nps 1848752 time 1748 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 h2h3 e8g8 e1g1 c7c5 d4c5 b8d7 c1e3 d7c5
info depth 19 multipv 1 score cp 23 nodes 4400809 nps 1850634 time 2378 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 f1e1 b8d7 h2h3 g4h5 b1d2
info depth 20 multipv 1 score cp 24 nodes 7250034 nps 1852333 time 3914 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 b1c3 b8c6 f1b5 d5c3 b2c3 c8d7 c1g5 d8a5
info depth 21 multipv 1 score cp 21 nodes 10465266 nps 1854228 time 5644 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 b1c3 d5c3 b2c3 d8c7 f1e2 d6e5 d4e5 b8c6 e1g1 c6e5 f3e5 c7e5
info depth 22 multipv 1 score cp 15 nodes 19323401 nps 1857840 time 10401 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2 f8b4 d1d3 e8g8 e1g1 f8e8 d4c6 d7c6 a2a3 b4c3 d3c3 f6e4
info depth 23 multipv 1 score cp 17 nodes 23950621 nps 1857933 time 12891 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 f8e7 c1f4 d7d6 f1b5 c8d7 d4b3 a7a6 b5e2 e6e5 f4e3 g8f6 h2h3 e8g8 e1g1
info depth 24 multipv 1 score cp 24 nodes 30378486 nps 1856648 time 16362 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 f8e7 c1f4 d7d6 f4g3 e6e5 d4c6 b7c6 f1c4 h7h5 h2h3 h5h4 g3h2 g8f6 e1g1 e8g8
info depth 25 multipv 1 score cp 21 nodes 99316468 nps 1851019 time 53655 pv c2c4 g8f6 g1f3 e7e6 d2d4 d7d5 g2g3 f8e7 f1g2 e8g8 e1g1 c7c6 b1c3 b8d7 f3d2 h7h6 b2b3 b7b6 e2e4 d5e4 d2e4 f6e4 c3e4 c8b7 c1b2
```

```
Score of ChessDotCpp3.19 vs ChessDotCpp3.18: 183 - 150 - 667  [0.516] 1000
...      ChessDotCpp3.19 playing White: 96 - 75 - 328  [0.521] 499
...      ChessDotCpp3.19 playing Black: 87 - 75 - 339  [0.512] 501
...      White vs Black: 171 - 162 - 667  [0.504] 1000
Elo difference: 11.5 +/- 12.4, LOS: 96.5 %, DrawRatio: 66.7 %

Score of ChessDotCpp3.19 vs weiss2.0: 506 - 189 - 305  [0.658] 1000
...      ChessDotCpp3.19 playing White: 268 - 82 - 151  [0.686] 501
...      ChessDotCpp3.19 playing Black: 238 - 107 - 154  [0.631] 499
...      White vs Black: 375 - 320 - 305  [0.527] 1000
Elo difference: 114.1 +/- 18.5, LOS: 100.0 %, DrawRatio: 30.5 %

Score of ChessDotCpp3.19 vs seer2.5: 35 - 277 - 188  [0.258] 500
...      ChessDotCpp3.19 playing White: 15 - 132 - 103  [0.266] 250
...      ChessDotCpp3.19 playing Black: 20 - 145 - 85  [0.250] 250
...      White vs Black: 160 - 152 - 188  [0.508] 500
Elo difference: -183.5 +/- 24.9, LOS: 0.0 %, DrawRatio: 37.6 %
```

### 3.20

* Fix move ordering bug with high MVVLVA moves being placed above TT move
* Begin implmeniting staged movegen

```
info depth 1 multipv 1 score cp 34 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 32 nodes 71 nps 71000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 12 nodes 190 nps 190000 time 1 pv d2d4 g8f6 b1d2
info depth 4 multipv 1 score cp 21 nodes 645 nps 645000 time 1 pv e2e4 c7c5 f1e2 g8f6
info depth 5 multipv 1 score cp 7 nodes 1060 nps 1060000 time 1 pv e2e4 c7c5 f1e2 g8f6 e4e5
info depth 6 multipv 1 score cp 14 nodes 3292 nps 1097333 time 3 pv d2d4 d7d5 b1d2 c7c5 d4c5 g8f6
info depth 7 multipv 1 score cp 20 nodes 6813 nps 1362600 time 5 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 13392 nps 1488000 time 9 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6
info depth 9 multipv 1 score cp 20 nodes 22019 nps 1572785 time 14 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7
info depth 10 multipv 1 score cp 26 nodes 43528 nps 1612148 time 27 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 f1e2 d7d5 e4d5 e6d5
info depth 11 multipv 1 score cp 29 nodes 77437 nps 1683413 time 46 pv e2e4 e7e6 g1f3 f8e7 f1e2 c7c5 e1g1 b8c6 d2d4 c5d4 f3d4
info depth 12 multipv 1 score cp 26 nodes 176227 nps 1694490 time 104 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 c1e3 f8e7
info depth 13 multipv 1 score cp 22 nodes 333965 nps 1739401 time 192 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 19 nodes 665628 nps 1770287 time 376 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 15 multipv 1 score cp 20 nodes 896693 nps 1786241 time 502 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 c7c5 d4c5 e7c5
info depth 16 multipv 1 score cp 20 nodes 1265810 nps 1777823 time 712 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 f1e2 c5d4 c3d4 e7c6 g1f3 f8e7 e1g1 e8g8
info depth 17 multipv 1 score cp 17 nodes 2058093 nps 1794326 time 1147 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 e7c6 f1e2 f8e7 e1g1 c5d4 c3d4 e8g8 b1c3
info depth 18 multipv 1 score cp 17 nodes 2748758 nps 1790721 time 1535 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 c5d4 c3d4 b8c6 f1d3 d8b6 d3c2 e7f5 c2f5 e6f5
info depth 19 multipv 1 score cp 27 nodes 4481583 nps 1772778 time 2528 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 e7c6 f1d3 f8e7 e1g1 b7b6 c1e3 e8g8 f1e1 c8a6 d3c2 c5d4 c3d4
info depth 20 multipv 1 score cp 23 nodes 6536344 nps 1760394 time 3713 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 b8d7 g1f3 g8e7 f1d3 e7g6 d3g6 h7g6
info depth 21 multipv 1 score cp 20 nodes 11038718 nps 1752733 time 6298 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 f8e7 d2d4 c5d4 f3d4 d7d6 c1e3 e8g8 h2h3 a7a6 f1e1 d8c7 d4c6 b7c6
info depth 22 multipv 1 score cp 17 nodes 16264144 nps 1744892 time 9321 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 d8b6 h2h3 d7d6 e1g1 f8e7 a1b1 e8g8 d2d3 f8d8 c1e3 d6d5 e4d5 e6d5
info depth 23 multipv 1 score cp 17 nodes 21331064 nps 1742591 time 12241 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 d8b6 d2d3 f8e7 e4e5 f6g4 c1f4 f7f6 e5f6 g4f6 e1g1 e8g8 f4g3 b6b2 c3b5
info depth 24 multipv 1 score cp 17 nodes 61824782 nps 1731980 time 35696 pv g1f3 g8f6 c2c4 c7c5 g2g3 b7b6 f1g2 c8b7 e1g1 g7g6 e2e3 f8g7 d2d4 e8g8 d4d5 b6b5 f1e1 b5c4 e3e4 e7e6 c1g5 h7h6 g5h4 d8b6
info depth 25 multipv 1 score cp 19 nodes 87520687 nps 1730683 time 50570 pv g1f3 g8f6 d2d4 e7e6 g2g3 d7d5 f1g2 f8e7 c2c4 e8g8 e1g1 c7c6 b2b3 b8d7 b1d2 b7b6 c1b2 c8b7 a1c1 a8c8 f1e1 d5c4 d2c4 c6c5 d4c5 e7c5
```

```
Score of ChessDotCpp3.20 vs ChessDotCpp3.19: 169 - 125 - 706  [0.522] 1000
...      ChessDotCpp3.20 playing White: 95 - 62 - 344  [0.533] 501
...      ChessDotCpp3.20 playing Black: 74 - 63 - 362  [0.511] 499
...      White vs Black: 158 - 136 - 706  [0.511] 1000
Elo difference: 15.3 +/- 11.6, LOS: 99.5 %, DrawRatio: 70.6 %

Score of ChessDotCpp3.20 vs weiss2.0: 241 - 100 - 159  [0.641] 500
...      ChessDotCpp3.20 playing White: 121 - 48 - 81  [0.646] 250
...      ChessDotCpp3.20 playing Black: 120 - 52 - 78  [0.636] 250
...      White vs Black: 173 - 168 - 159  [0.505] 500
Elo difference: 100.7 +/- 25.7, LOS: 100.0 %, DrawRatio: 31.8 %

Score of ChessDotCpp3.20 vs seer2.5: 45 - 268 - 187  [0.277] 500
...      ChessDotCpp3.20 playing White: 20 - 129 - 100  [0.281] 249
...      ChessDotCpp3.20 playing Black: 25 - 139 - 87  [0.273] 251
...      White vs Black: 159 - 154 - 187  [0.505] 500
Elo difference: -166.7 +/- 24.9, LOS: 0.0 %, DrawRatio: 37.4 %
```

### 3.21

Capture/non-capture staged movegen split

```
info depth 1 multipv 1 score cp 34 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 32 nodes 71 nps 71000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 12 nodes 190 nps 190000 time 1 pv d2d4 g8f6 b1d2
info depth 4 multipv 1 score cp 21 nodes 646 nps 646000 time 1 pv e2e4 c7c5 f1e2 g8f6
info depth 5 multipv 1 score cp 7 nodes 1061 nps 1061000 time 1 pv e2e4 c7c5 f1e2 g8f6 e4e5
info depth 6 multipv 1 score cp 14 nodes 2003 nps 1001500 time 2 pv e2e4 c7c5 g1e2 b8c6 d2d4 c5d4 e2d4
info depth 7 multipv 1 score cp 22 nodes 5312 nps 1328000 time 4 pv e2e4 e7e6 b1c3 d7d5 d2d4 d5e4 c3e4
info depth 8 multipv 1 score cp 26 nodes 10602 nps 1514571 time 7 pv e2e4 e7e6 d2d4 c7c5 g1f3 c5d4 f3d4 g8f6
info depth 9 multipv 1 score cp 20 nodes 19441 nps 1620083 time 12 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7
info depth 10 multipv 1 score cp 26 nodes 35632 nps 1696761 time 21 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 f1e2 d7d5 e4d5 e6d5
info depth 11 multipv 1 score cp 31 nodes 66078 nps 1738894 time 38 pv e2e4 e7e6 g1f3 c7c5 b1c3 d7d5 f1b5 b8c6 e1g1 g8f6 f1e1 d5d4 b5c6 b7c6
info depth 12 multipv 1 score cp 26 nodes 129182 nps 1819464 time 71 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 f1b5 g8e7 d2d4 c5d4 f3d4 e7g6
info depth 13 multipv 1 score cp 17 nodes 257724 nps 1881197 time 137 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1e2 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 19 nodes 458094 nps 1932886 time 237 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 15 multipv 1 score cp 19 nodes 736968 nps 1934299 time 381 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 d1e2 e7e2 e1e2 g8f6 c1g5 b8c6 g5f6 g7f6
info depth 16 multipv 1 score cp 32 nodes 1356263 nps 1962753 time 691 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 b8c6 f1e1 f8e8
info depth 17 multipv 1 score cp 26 nodes 1857354 nps 1973808 time 941 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 e7c6 f1e2 f8e7 e1g1 e8g8 c1e3 d8c7 f1e1
info depth 18 multipv 1 score cp 22 nodes 2880697 nps 1971729 time 1461 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d8e7 e2e7 d6e7 e1g1 c8g4 b1d2 e8g8 f1e1 b8c6
info depth 19 multipv 1 score cp 27 nodes 4614852 nps 1955445 time 2360 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 b8d7 b1c3 c7c6
info depth 20 multipv 1 score cp 21 nodes 7842714 nps 1951409 time 4019 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 h2h3 d7d5 e4d5 f6d5 d4c6 b7c6
info depth 21 multipv 1 score cp 24 nodes 10904303 nps 1950680 time 5590 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 f8e7 b1c3 e8g8 f1d3 d7d6 e5d6 e7d6 e1g1 b8c6 f1e1
info depth 22 multipv 1 score cp 16 nodes 27186297 nps 1959937 time 13871 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 g8f6 e1g1 a7a6 d2d4 c5d4 f3d4 d8c7 d4c6 b7c6 c1e3 f8e7 d1d2 d7d5 e3f4 e6e5
info depth 23 multipv 1 score cp 20 nodes 30857967 nps 1959360 time 15749 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 g8f6 e1g1 a7a6 d2d4 c5d4 f3d4 d8c7 d4c6 d7c6 d1d3 f8e7 a2a4 e8g8 d3g3 e6e5 c1e3
info depth 24 multipv 1 score cp 22 nodes 38499938 nps 1955304 time 19690 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 f8e7 g2g3 g8f6 f1g2 c6d4 d1d4 d7d6 e1g1 e8g8 f1d1 d8a5 a2a4 c8d7 d4d3 d7c6
info depth 25 multipv 1 score cp 18 nodes 47324318 nps 1953935 time 24220 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 f8e7 g2g3 g8f6 f1g2 c6d4 d1d4 d7d6 e1g1 e8g8 f1d1 d8c7 d4d3 h7h6 c1f4 e6e5 f4d2
```

```
Score of ChessDotCpp3.21 vs ChessDotCpp3.20: 497 - 449 - 2054  [0.508] 3000
...      ChessDotCpp3.21 playing White: 271 - 209 - 1020  [0.521] 1500
...      ChessDotCpp3.21 playing Black: 226 - 240 - 1034  [0.495] 1500
...      White vs Black: 511 - 435 - 2054  [0.513] 3000
Elo difference: 5.6 +/- 7.0, LOS: 94.1 %, DrawRatio: 68.5 %

Score of ChessDotCpp3.21 vs weiss2.0: 275 - 98 - 127  [0.677] 500
...      ChessDotCpp3.21 playing White: 146 - 38 - 67  [0.715] 251
...      ChessDotCpp3.21 playing Black: 129 - 60 - 60  [0.639] 249
...      White vs Black: 206 - 167 - 127  [0.539] 500
Elo difference: 128.6 +/- 27.5, LOS: 100.0 %, DrawRatio: 25.4 %

Score of ChessDotCpp3.21 vs seer2.5: 32 - 267 - 201  [0.265] 500
...      ChessDotCpp3.21 playing White: 14 - 136 - 100  [0.256] 250
...      ChessDotCpp3.21 playing Black: 18 - 131 - 101  [0.274] 250
...      White vs Black: 145 - 154 - 201  [0.491] 500
Elo difference: -177.2 +/- 24.0, LOS: 0.0 %, DrawRatio: 40.2 %
```

### 3.22

* Fix bad captures movepick
* First bad capture movepick

```
info depth 1 multipv 1 score cp 34 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 32 nodes 71 nps 71000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 12 nodes 190 nps 190000 time 1 pv d2d4 g8f6 b1d2
info depth 4 multipv 1 score cp 21 nodes 646 nps 646000 time 1 pv e2e4 c7c5 f1e2 g8f6
info depth 5 multipv 1 score cp 7 nodes 1061 nps 1061000 time 1 pv e2e4 c7c5 f1e2 g8f6 e4e5
info depth 6 multipv 1 score cp 14 nodes 2003 nps 1001500 time 2 pv e2e4 c7c5 g1e2 b8c6 d2d4 c5d4 e2d4
info depth 7 multipv 1 score cp 22 nodes 5312 nps 1328000 time 4 pv e2e4 e7e6 b1c3 d7d5 d2d4 d5e4 c3e4
info depth 8 multipv 1 score cp 26 nodes 10602 nps 1514571 time 7 pv e2e4 e7e6 d2d4 c7c5 g1f3 c5d4 f3d4 g8f6
info depth 9 multipv 1 score cp 20 nodes 19441 nps 1620083 time 12 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7
info depth 10 multipv 1 score cp 26 nodes 35636 nps 1696952 time 21 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 f1e2 d7d5 e4d5 e6d5
info depth 11 multipv 1 score cp 31 nodes 66085 nps 1739078 time 38 pv e2e4 e7e6 g1f3 c7c5 b1c3 d7d5 f1b5 b8c6 e1g1 g8f6 f1e1 d5d4 b5c6 b7c6
info depth 12 multipv 1 score cp 26 nodes 129206 nps 1819802 time 71 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 f1b5 g8e7 d2d4 c5d4 f3d4 e7g6
info depth 13 multipv 1 score cp 17 nodes 257785 nps 1854568 time 139 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1e2 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 19 nodes 458221 nps 1909254 time 240 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 15 multipv 1 score cp 19 nodes 737165 nps 1939907 time 380 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 d8e7 d1e2 e7e2 e1e2 g8f6 c1g5 b8c6 g5f6 g7f6
info depth 16 multipv 1 score cp 32 nodes 1324448 nps 1953463 time 678 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 b8c6 f1e1 f8e8
info depth 17 multipv 1 score cp 25 nodes 1970435 nps 1947070 time 1012 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 h2h3 f8e8 c1g5 c7c5 d4c5 e7c5
info depth 18 multipv 1 score cp 27 nodes 2661947 nps 1958754 time 1359 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 f1e1 b8d7 c2c3 c7c6
info depth 19 multipv 1 score cp 21 nodes 5132222 nps 1971656 time 2603 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 d1d4 a7a6 f1e2 g8f6 e1g1 b8c6 d4d3 f8e7 f1d1 e8g8 h2h3
info depth 20 multipv 1 score cp 25 nodes 6788483 nps 1966536 time 3452 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 d1d4 a7a6 f1e2 g8f6 e1g1 b8c6 d4d3 f8e7 f1d1 f6d7 h2h3 e8g8
info depth 21 multipv 1 score cp 25 nodes 9112260 nps 1964272 time 4639 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 d1d4 a7a6 f1e2 g8f6 e1g1 f8e7 f1d1 e8g8 c1g5 b8d7 e4e5 d6e5 f3e5
info depth 22 multipv 1 score cp 20 nodes 15151635 nps 1955554 time 7748 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d8b6 e1g1 d7d6 d2d3 f8e7 f3d2 e8g8 f1e1 b6d8 d2c4 c6d4 e4e5 d6e5 c4e5
info depth 23 multipv 1 score cp 19 nodes 22202374 nps 1958053 time 11339 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d7d6 d2d4 c5d4 f3d4 c6d4 d1d4 f8e7 e1g1 e8g8 e4e5 d6e5 d4e5 c8d7 e5e2
info depth 24 multipv 1 score cp 21 nodes 32627676 nps 1958796 time 16657 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d7d5 e4d5 e6d5 d2d4 c5d4 f3d4 c8g4 c3e2 c6d4 d1d4 f8e7 e2c3 g4e6 e1g1 e8g8
info depth 25 multipv 1 score cp 16 nodes 72910095 nps 1944684 time 37492 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d7d5 e4d5 e6d5 d2d4 f8e7 e1g1 e8g8 f1e1 h7h6 c1e3 c5c4 f3e5 c8e6 a2a3 a7a6 d1d2
```

```
Score of ChessDotCpp3.22 vs ChessDotCpp3.21: 753 - 727 - 3520  [0.503] 5000
...      ChessDotCpp3.22 playing White: 399 - 341 - 1759  [0.512] 2499
...      ChessDotCpp3.22 playing Black: 354 - 386 - 1761  [0.494] 2501
...      White vs Black: 785 - 695 - 3520  [0.509] 5000
Elo difference: 1.8 +/- 5.2, LOS: 75.0 %, DrawRatio: 70.4 %
```

### 3.23

Staged killer movegen

```
info depth 1 multipv 1 score cp 34 nodes 25 nps 25000 time 1 pv d2d4
info depth 2 multipv 1 score cp 32 nodes 71 nps 71000 time 1 pv d2d4 g8f6
info depth 3 multipv 1 score cp 12 nodes 190 nps 190000 time 1 pv d2d4 g8f6 b1d2
info depth 4 multipv 1 score cp 21 nodes 644 nps 644000 time 1 pv e2e4 c7c5 f1e2 g8f6
info depth 5 multipv 1 score cp 7 nodes 1059 nps 1059000 time 1 pv e2e4 c7c5 f1e2 g8f6 e4e5
info depth 6 multipv 1 score cp 14 nodes 2001 nps 1000500 time 2 pv e2e4 c7c5 g1e2 b8c6 d2d4 c5d4 e2d4
info depth 7 multipv 1 score cp 22 nodes 5414 nps 1082800 time 5 pv e2e4 e7e6 b1c3 d7d5 d2d4 d5e4 c3e4
info depth 8 multipv 1 score cp 26 nodes 10313 nps 1289125 time 8 pv e2e4 e7e6 d2d4 c7c5 g1f3 c5d4 f3d4 g8f6
info depth 9 multipv 1 score cp 20 nodes 19290 nps 1483846 time 13 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7
info depth 10 multipv 1 score cp 26 nodes 34881 nps 1661000 time 21 pv e2e4 e7e6 b1c3 c7c5 g1f3 b8c6 f1e2 d7d5 e4d5 e6d5
info depth 11 multipv 1 score cp 29 nodes 74103 nps 1723325 time 43 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 f1b5 c6d4 e4e5 d4b5 c3b5
info depth 12 multipv 1 score cp 27 nodes 126968 nps 1788281 time 71 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6 e4e5 f6d5 b1c3 d5f4 d2d4 f4g2 e1f1
info depth 13 multipv 1 score cp 17 nodes 310938 nps 1873120 time 166 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1e2 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 17 nodes 485773 nps 1897550 time 256 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 c2c3 c7c6 f1d3 f8e7 e1g1 e8g8
info depth 15 multipv 1 score cp 20 nodes 710712 nps 1915665 time 371 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 c2c3 f8e7 f1d3 e8g8 e1g1 c7c5 d4c5 e7c5
info depth 16 multipv 1 score cp 20 nodes 1136508 nps 1926284 time 590 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c2c4 g8f6 c4c5 d6e7 f1d3 e8g8 e1g1 f8e8
info depth 17 multipv 1 score cp 25 nodes 2269855 nps 1928508 time 1177 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4b5 d7d5 e4d5 f6d5 c3d5 e6d5 f1e2
info depth 18 multipv 1 score cp 22 nodes 3213572 nps 1931233 time 1664 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 h2h3 d7d5 e4d5 e6d5 d2d4 f8d6 d4c5 d6c5 e1g1 e8g8
info depth 19 multipv 1 score cp 26 nodes 4677377 nps 1931204 time 2422 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1c4 d7d6 d2d4 c5d4 c4d5 e6d5 e1g1 d6e5 f3e5 b8c6 f1e1
info depth 20 multipv 1 score cp 18 nodes 7081740 nps 1925432 time 3678 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 b8c6 b1c3 f8b4 c1d2 d7d6 c3d5 b4d2 d1d2 e6d5 f1e2 d6e5 f3e5
info depth 21 multipv 1 score cp 23 nodes 9463331 nps 1923832 time 4919 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 f8b4 c1d2 d7d6 d2b4 d5b4 f1b5 c8d7 b5d7 d8d7 b1c3 e8g8 a2a3 b4c6
info depth 22 multipv 1 score cp 23 nodes 15697074 nps 1903137 time 8248 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 b7c6 e1g1 d7d5 b1d2 f8e7 f1e1 d8c7 h2h3 e8g8 c2c4 f8e8
info depth 23 multipv 1 score cp 20 nodes 20964899 nps 1899854 time 11035 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 d7c6 e1g1 e6e5 h2h3 c8e6 c1e3 f8e7 a2a4 e8g8 d1e2 d8c7 f1d1
info depth 24 multipv 1 score cp 19 nodes 37671978 nps 1898310 time 19845 pv e2e4 c7c5 g1f3 e7e6 c2c4 b8c6 f1e2 g8f6 b1c3 e6e5 e1g1 g7g6 h2h3 f8g7 a1b1 e8g8 d2d3 d7d6 a2a3 f8e8 b2b4 b7b6 c1e3 c6d4
info depth 25 multipv 1 score cp 19 nodes 47259215 nps 1896817 time 24915 pv e2e4 c7c5 g1f3 e7e6 c2c4 b8c6 f1e2 g8f6 b1c3 e6e5 e1g1 g7g6 h2h3 d7d6 a2a3 f8g7 d2d3 h7h6 c1e3 e8g8 d1d2 g8h7 b2b4 b7b6 c3d5
```

```
Score of ChessDotCpp3.23 vs ChessDotCpp3.22: 381 - 358 - 1761  [0.505] 2500
...      ChessDotCpp3.23 playing White: 211 - 163 - 876  [0.519] 1250
...      ChessDotCpp3.23 playing Black: 170 - 195 - 885  [0.490] 1250
...      White vs Black: 406 - 333 - 1761  [0.515] 2500
Elo difference: 3.2 +/- 7.4, LOS: 80.1 %, DrawRatio: 70.4 %

Score of ChessDotCpp3.23 vs ChessDotCpp3.19: 158 - 123 - 719  [0.517] 1000
...      ChessDotCpp3.23 playing White: 85 - 62 - 354  [0.523] 501
...      ChessDotCpp3.23 playing Black: 73 - 61 - 365  [0.512] 499
...      White vs Black: 146 - 135 - 719  [0.505] 1000
Elo difference: 12.2 +/- 11.4, LOS: 98.2 %, DrawRatio: 71.9 %

Score of ChessDotCpp3.23 vs weiss2.0: 1025 - 388 - 587  [0.659] 2000
...      ChessDotCpp3.23 playing White: 521 - 188 - 291  [0.666] 1000
...      ChessDotCpp3.23 playing Black: 504 - 200 - 296  [0.652] 1000
...      White vs Black: 721 - 692 - 587  [0.507] 2000
Elo difference: 114.6 +/- 13.2, LOS: 100.0 %, DrawRatio: 29.3 %
```

### 3.24

Retrain same nnue arch on 550M fens

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -559  | -440  | -496  | -1087 | -107  | -491  | -430  | -577  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -65  | -136  | -118  | -131  | -140  | -170  | -149  |  -68  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  65   |  133  |  114  |  128  |  133  |  160  |  143  |  66   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  540  |  438  |  494  |  980  |  101  |  488  |  428  |  560  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 24
Phase: 24
```

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 294 nps 294000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 447 nps 447000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 15 nodes 1236 nps 1236000 time 1 pv d2d4 d7d5 b1d2 g8f6 g1f3
info depth 6 multipv 1 score cp 27 nodes 3345 nps 1672500 time 2 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 7 multipv 1 score cp 24 nodes 5439 nps 1359750 time 4 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2
info depth 8 multipv 1 score cp 28 nodes 10911 nps 1558714 time 7 pv e2e4 e7e6 g1f3 c7c5 f1e2 f8e7 e1g1 g8f6
info depth 9 multipv 1 score cp 21 nodes 31349 nps 1741611 time 18 pv g1f3 g8f6 g2g3 e7e6 f1g2 f8e7 e1g1 e8g8 c2c4
info depth 10 multipv 1 score cp 23 nodes 94493 nps 1852803 time 51 pv e2e4 e7e6 b1c3 d7d5 d2d4 g8f6 e4e5 f6d7 f1e2 c7c5
info depth 11 multipv 1 score cp 28 nodes 142998 nps 1881552 time 76 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 f1e1
info depth 12 multipv 1 score cp 27 nodes 229669 nps 1882532 time 122 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 f8e8 e1g1 d7d5
info depth 13 multipv 1 score cp 21 nodes 333223 nps 1893312 time 176 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 c7c6 b1c3 d5c4 e2c4
info depth 14 multipv 1 score cp 21 nodes 590745 nps 1936868 time 305 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 c7c6 e1g1 d7d5 b1c3 d5c4 e2c4
info depth 15 multipv 1 score cp 20 nodes 855677 nps 1922869 time 445 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 d5c4 b1d2 c7c5 d4c5
info depth 16 multipv 1 score cp 20 nodes 1185641 nps 1927871 time 615 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 d5c4 b1d2 c7c5 d4c5 b8d7
info depth 17 multipv 1 score cp 16 nodes 2161439 nps 1919572 time 1126 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 b1d2 c7c5 d4c5 b8d7 d2c4 d7c5
info depth 18 multipv 1 score cp 16 nodes 2765873 nps 1918081 time 1442 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 b1d2 c7c5 d4c5 b8d7 d2c4 d7c5
info depth 19 multipv 1 score cp 18 nodes 5835966 nps 1904067 time 3065 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 f1e1 g4h5 c2c4
info depth 20 multipv 1 score cp 27 nodes 9205068 nps 1894436 time 4859 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 f1d3 c7c5 e4e5 f6d7 c2c3 b8c6 e1g1 d8b6 d4c5 b6c7 f1e1 c6e5 f3e5 d7e5
info depth 21 multipv 1 score cp 23 nodes 14391408 nps 1884678 time 7636 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 d7c6 c1e3 e6e5 h2h3 f8e7 e1g1 c8e6 d1e2 e8g8 b1d2
info depth 22 multipv 1 score cp 20 nodes 19161735 nps 1885069 time 10165 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 d7c6 c1e3 e6e5 h2h3 f8e7 e1g1 c8e6 d1e2 e8g8 b1d2 f6d7
info depth 23 multipv 1 score cp 19 nodes 28445925 nps 1882838 time 15108 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 f3d4 a7a6 c1e3 g8f6 d1f3 d8c7 g2g4 b7b5 a2a3 c8b7 f1g2 f8e7 g4g5 f6d7 f3g3
info depth 24 multipv 1 score cp 23 nodes 40677602 nps 1877572 time 21665 pv e2e4 c7c5 g1f3 e7e6 c2c4 g8f6 e4e5 f6g8 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 f3d4 d6e5 d4c6 b7c6 b1d2 g8f6 d1a4 d8c7 f1e1 f8e7
info depth 25 multipv 1 score cp 22 nodes 53910650 nps 1878288 time 28702 pv e2e4 c7c5 g1f3 e7e6 c2c4 g8f6 e4e5 f6g8 d2d4 c5d4 d1d4 b8c6 d4e3 d7d5 c4d5 e6d5 f1b5 g8e7 e1g1 e7f5 e3d3 a7a6 b5c6 b7c6
```

```
Score of ChessDotCpp3.24 vs ChessDotCpp3.23: 558 - 437 - 1505  [0.524] 2500
...      ChessDotCpp3.24 playing White: 305 - 224 - 721  [0.532] 1250
...      ChessDotCpp3.24 playing Black: 253 - 213 - 784  [0.516] 1250
...      White vs Black: 518 - 477 - 1505  [0.508] 2500
Elo difference: 16.8 +/- 8.6, LOS: 100.0 %, DrawRatio: 60.2 %

Score of ChessDotCpp3.24 vs weiss2.0: 563 - 140 - 297  [0.712] 1000
...      ChessDotCpp3.24 playing White: 300 - 65 - 136  [0.735] 501
...      ChessDotCpp3.24 playing Black: 263 - 75 - 161  [0.688] 499
...      White vs Black: 375 - 328 - 297  [0.523] 1000
Elo difference: 156.8 +/- 19.0, LOS: 100.0 %, DrawRatio: 29.7 %

Score of ChessDotCpp3.24 vs seer2.5: 152 - 971 - 877  [0.295] 2000
...      ChessDotCpp3.24 playing White: 81 - 466 - 453  [0.307] 1000
...      ChessDotCpp3.24 playing Black: 71 - 505 - 424  [0.283] 1000
...      White vs Black: 586 - 537 - 877  [0.512] 2000
Elo difference: -151.1 +/- 11.5, LOS: 0.0 %, DrawRatio: 43.9 %
```

### 3.25

Remove plain futility pruning

```
Score of ChessDotCpp3.25 vs ChessDotCpp3.24: 328 - 313 - 1359  [0.504] 2000
...      ChessDotCpp3.25 playing White: 175 - 145 - 681  [0.515] 1001
...      ChessDotCpp3.25 playing Black: 153 - 168 - 678  [0.492] 999
...      White vs Black: 343 - 298 - 1359  [0.511] 2000
Elo difference: 2.6 +/- 8.6, LOS: 72.3 %, DrawRatio: 68.0 %
```

### 3.26

Fix a bug with en passant pseudolegal validation

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -559  | -440  | -496  | -1087 | -107  | -491  | -430  | -577  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -65  | -136  | -118  | -131  | -140  | -170  | -149  |  -68  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  65   |  133  |  114  |  128  |  133  |  160  |  143  |  66   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  540  |  438  |  494  |  980  |  101  |  488  |  428  |  560  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 24
Phase: 24
```

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 294 nps 294000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 447 nps 447000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 15 nodes 1236 nps 1236000 time 1 pv d2d4 d7d5 b1d2 g8f6 g1f3
info depth 6 multipv 1 score cp 27 nodes 3345 nps 1672500 time 2 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 7 multipv 1 score cp 24 nodes 5439 nps 1359750 time 4 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2
info depth 8 multipv 1 score cp 28 nodes 10925 nps 1560714 time 7 pv e2e4 e7e6 g1f3 c7c5 f1e2 f8e7 e1g1 g8f6
info depth 9 multipv 1 score cp 21 nodes 31388 nps 1652000 time 19 pv g1f3 g8f6 g2g3 e7e6 f1g2 f8e7 e1g1 e8g8 c2c4
info depth 10 multipv 1 score cp 23 nodes 94624 nps 1785358 time 53 pv e2e4 e7e6 b1c3 d7d5 d2d4 g8f6 e4e5 f6d7 f1e2 c7c5
info depth 11 multipv 1 score cp 28 nodes 143291 nps 1705845 time 84 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 f1e1
info depth 12 multipv 1 score cp 27 nodes 230259 nps 1610202 time 143 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 f8e8 e1g1 d7d5
info depth 13 multipv 1 score cp 21 nodes 334203 nps 1591442 time 210 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 c7c6 b1c3 d5c4 e2c4
info depth 14 multipv 1 score cp 21 nodes 593165 nps 1699613 time 349 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 c7c6 e1g1 d7d5 b1c3 d5c4 e2c4
info depth 15 multipv 1 score cp 20 nodes 859398 nps 1678511 time 512 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 d5c4 b1d2 c7c5 d4c5
info depth 16 multipv 1 score cp 20 nodes 1199106 nps 1713008 time 700 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 d5c4 b1d2 c7c5 d4c5 b8d7
info depth 17 multipv 1 score cp 16 nodes 1994423 nps 1681638 time 1186 pv d2d4 g8f6 c2c4 e7e6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 b1d2 c7c5 d4c5 b8d7 d2c4 d7c5
info depth 18 multipv 1 score cp 19 nodes 4021828 nps 1729818 time 2325 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 f1g2 d7d5 d2d4 e8g8 e1g1 b8d7 b2b3 d5c4 b3c4 c7c5 e2e3 b7b6
info depth 19 multipv 1 score cp 21 nodes 5537663 nps 1777740 time 3115 pv g1f3 g8f6 c2c4 e7e6 g2g3 f8e7 f1g2 d7d5 d2d4 e8g8 e1g1 b8d7 d1c2 c7c6 f1d1 b7b5 f3e5 c8b7 e5d7 d8d7
info depth 20 multipv 1 score cp 20 nodes 9061477 nps 1695635 time 5344 pv g1f3 d7d5 d2d4 e7e6 c2c4 f8e7 g2g3 g8f6 f1g2 e8g8 e1g1 b8d7 d1c2 c7c6 f1d1 a7a6 c1g5 d5c4 f3e5 d7b6 e5c4 b6c4 c2c4
info depth 21 multipv 1 score cp 24 nodes 24501092 nps 1740752 time 14075 pv g1f3 c7c5 e2e4 e7e6 b1c3 a7a6 d2d4 c5d4 f3d4 d7d6 g2g4 f8e7 f1g2 g8f6 f2f4 d6d5 e4d5 f6d5 c3d5 e7h4 e1f1 e6d5
info depth 22 multipv 1 score cp 19 nodes 35567531 nps 1747790 time 20350 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8b4 c1d2 b4e7 g2g3 e8g8 f1g2 c7c6 e1g1 d7d5 d1c2 b7b6 f3e5 c8b7 b1c3 b8d7 d2f4 d7e5 d4e5
info depth 23 multipv 1 score cp 20 nodes 45282743 nps 1748638 time 25896 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8e7 e1g1 h7h6 f1e1 e8g8 h2h3 a7a6 b1d2 c8f5 d3f5 e7f5 d2f1 b8d7 c2c3
info depth 24 multipv 1 score cp 21 nodes 87388439 nps 1732728 time 50434 pv d2d4 g8f6 g1f3 e7e6 c2c4 f8b4 c1d2 b4e7 b1c3 d7d5 d2f4 e8g8 e2e3 b8d7 c4d5 f6d5 c3d5 e6d5 f1e2 c7c6 e1g1 f8e8 h2h3 d7b6 d1c2
info depth 25 multipv 1 score cp 18 nodes 119654264 nps 1728583 time 69221 pv d2d4 g8f6 g1f3 e7e6 c2c4 b7b6 a2a3 c8b7 b1c3 d7d5 c4d5 f6d5 c3d5 d8d5 e2e3 c7c5 d1a4 b7c6 a4c2 f8e7 f1c4 d5h5 d4c5 c6f3 g2f3 h5f3
```

```
Score of ChessDotCpp3.26 vs ChessDotCpp3.25: 237 - 219 - 1044  [0.506] 1500
...      ChessDotCpp3.26 playing White: 126 - 89 - 536  [0.525] 751
...      ChessDotCpp3.26 playing Black: 111 - 130 - 508  [0.487] 749
...      White vs Black: 256 - 200 - 1044  [0.519] 1500
Elo difference: 4.2 +/- 9.7, LOS: 80.0 %, DrawRatio: 69.6 %
```

### 3.27

Improve repetition and 50 move detection on TT hits

```
Score of ChessDotCpp3.27 vs ChessDotCpp3.26: 249 - 245 - 1006  [0.501] 1500
...      ChessDotCpp3.27 playing White: 117 - 117 - 516  [0.500] 750
...      ChessDotCpp3.27 playing Black: 132 - 128 - 490  [0.503] 750
...      White vs Black: 245 - 249 - 1006  [0.499] 1500
Elo difference: 0.9 +/- 10.1, LOS: 57.1 %, DrawRatio: 67.1 %
```

### 3.28

Small improvement for TT returns

```
Score of ChessDotCpp3.28 vs ChessDotCpp3.27: 246 - 235 - 1019  [0.504] 1500
...      ChessDotCpp3.28 playing White: 125 - 117 - 507  [0.505] 749
...      ChessDotCpp3.28 playing Black: 121 - 118 - 512  [0.502] 751
...      White vs Black: 243 - 238 - 1019  [0.502] 1500
Elo difference: 2.5 +/- 9.9, LOS: 69.2 %, DrawRatio: 67.9 %

Score of ChessDotCpp3.28 vs weiss2.0: 540 - 149 - 311  [0.696] 1000
...      ChessDotCpp3.28 playing White: 272 - 85 - 142  [0.687] 499
...      ChessDotCpp3.28 playing Black: 268 - 64 - 169  [0.704] 501
...      White vs Black: 336 - 353 - 311  [0.491] 1000
Elo difference: 143.5 +/- 18.6, LOS: 100.0 %, DrawRatio: 31.1 %

Score of ChessDotCpp3.28 vs seer2.5: 87 - 514 - 399  [0.286] 1000
...      ChessDotCpp3.28 playing White: 42 - 262 - 197  [0.280] 501
...      ChessDotCpp3.28 playing Black: 45 - 252 - 202  [0.293] 499
...      White vs Black: 294 - 307 - 399  [0.493] 1000
Elo difference: -158.5 +/- 17.0, LOS: 0.0 %, DrawRatio: 39.9 %
```

### 3.29

No null move pruning with only pawns remaining

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -559  | -440  | -496  | -1087 | -107  | -491  | -430  | -577  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -65  | -136  | -118  | -131  | -140  | -170  | -149  |  -68  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  65   |  133  |  114  |  128  |  133  |  160  |  143  |  66   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  540  |  438  |  494  |  980  |  101  |  488  |  428  |  560  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 24
Phase: 24
```

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 294 nps 294000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 447 nps 447000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 15 nodes 1229 nps 1229000 time 1 pv d2d4 d7d5 b1d2 g8f6 g1f3
info depth 6 multipv 1 score cp 27 nodes 3311 nps 1103666 time 3 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 7 multipv 1 score cp 24 nodes 5405 nps 1351250 time 4 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2
info depth 8 multipv 1 score cp 28 nodes 10882 nps 1360250 time 8 pv e2e4 e7e6 g1f3 c7c5 f1e2 f8e7 e1g1 g8f6
info depth 9 multipv 1 score cp 19 nodes 21653 nps 1546642 time 14 pv e2e4 e7e6 g1f3 c7c5 f1e2 f8e7 d2d4 c5d4 d1d4
info depth 10 multipv 1 score cp 25 nodes 37424 nps 1627130 time 23 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 f1e2 f8e7 d2d4 c5d4 f3d4
info depth 11 multipv 1 score cp 28 nodes 77453 nps 1721177 time 45 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 f1e1
info depth 12 multipv 1 score cp 27 nodes 155668 nps 1789287 time 87 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8
info depth 13 multipv 1 score cp 22 nodes 295892 nps 1826493 time 162 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 22 nodes 440289 nps 1857759 time 237 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 e1g1 c7c6 f1e1 e8g8
info depth 15 multipv 1 score cp 23 nodes 841397 nps 1878118 time 448 pv e2e4 e7e6 c2c4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4
info depth 16 multipv 1 score cp 20 nodes 1824052 nps 1882406 time 969 pv d2d4 d7d5 g1f3 g8f6 c2c4 e7e6 e2e3 f8e7 f1e2 d5c4 e1g1 e8g8 b1d2 c7c5 d4c5 b8d7
info depth 17 multipv 1 score cp 20 nodes 3726575 nps 1897441 time 1964 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 22 nodes 4824279 nps 1904571 time 2533 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 b8c6 d4c5 e7c5
info depth 19 multipv 1 score cp 30 nodes 6697355 nps 1906448 time 3513 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 b8c6 d2f3 c5d4 c3d4 c6b4 d3e2 f8e7 c1d2
info depth 20 multipv 1 score cp 26 nodes 8867506 nps 1911512 time 4639 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 e4e5 c7c5 g1f3 c5d4 f1d3 d8c7 e1g1 b8c6 f1e1 f7f6 e5f6 g8f6 d2b3 e8g8 b3d4
info depth 21 multipv 1 score cp 26 nodes 10772543 nps 1907319 time 5648 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 e4e5 c7c5 g1f3 c5d4 f1d3 d8c7 e1g1 b8c6 f1e1 f7f6 e5f6 g8f6 d2b3 e8g8 b3d4
info depth 22 multipv 1 score cp 26 nodes 15647957 nps 1900407 time 8234 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 f1d3 c7c5 d4c5 e7c5 e1g1 e8g8 a2a3 c5e7 e4e5 f6d7 f1e1 b8c6 c2c4 d8c7 c4d5 e6d5
info depth 23 multipv 1 score cp 23 nodes 20802333 nps 1891293 time 10999 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 f1d3 c7c5 d4c5 e7c5 e1g1 e8g8 h2h3 b8c6 f1e1 c5b6 c2c3 e6e5 e4d5 d8d5 d1c2
info depth 24 multipv 1 score cp 21 nodes 27394307 nps 1885621 time 14528 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 f1d3 c7c5 d4c5 e7c5 e1g1 e8g8 h2h3 b8c6 f1e1 c5b6 c2c4 d5e4 d2e4 e6e5 e4c3 f8e8
info depth 25 multipv 1 score cp 28 nodes 47878740 nps 1847743 time 25912 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7 b5d7 b8d7 e1g1 f8e7 d4c5 d7c5 f1e1 e8g8 d2f1 f8e8 c1e3 e7d6 a2a3 c5e4 c2c3
```

```
Score of ChessDotCpp3.29 vs ChessDotCpp3.28: 306 - 241 - 953  [0.522] 1500
...      ChessDotCpp3.29 playing White: 163 - 114 - 474  [0.533] 751
...      ChessDotCpp3.29 playing Black: 143 - 127 - 479  [0.511] 749
...      White vs Black: 290 - 257 - 953  [0.511] 1500
Elo difference: 15.1 +/- 10.6, LOS: 99.7 %, DrawRatio: 63.5 %

Score of ChessDotCpp3.29 vs ChessDotCpp3.24: 171 - 149 - 680  [0.511] 1000
...      ChessDotCpp3.29 playing White: 94 - 68 - 337  [0.526] 499
...      ChessDotCpp3.29 playing Black: 77 - 81 - 343  [0.496] 501
...      White vs Black: 175 - 145 - 680  [0.515] 1000
Elo difference: 7.6 +/- 12.2, LOS: 89.1 %, DrawRatio: 68.0 %

Score of ChessDotCpp3.29 vs weiss2.0: 573 - 156 - 271  [0.709] 1000
...      ChessDotCpp3.29 playing White: 291 - 74 - 135  [0.717] 500
...      ChessDotCpp3.29 playing Black: 282 - 82 - 136  [0.700] 500
...      White vs Black: 373 - 356 - 271  [0.508] 1000
Elo difference: 154.3 +/- 19.4, LOS: 100.0 %, DrawRatio: 27.1 %

Score of ChessDotCpp3.29 vs seer2.5: 71 - 507 - 422  [0.282] 1000
...      ChessDotCpp3.29 playing White: 42 - 240 - 218  [0.302] 500
...      ChessDotCpp3.29 playing Black: 29 - 267 - 204  [0.262] 500
...      White vs Black: 309 - 269 - 422  [0.520] 1000
Elo difference: -162.4 +/- 16.6, LOS: 0.0 %, DrawRatio: 42.2 %
```

### 3.30

SEE pruning for captures in main search

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 296 nps 296000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 449 nps 449000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 15 nodes 787 nps 787000 time 1 pv d2d4 d7d5 b1d2 g8f6 g1f3
info depth 6 multipv 1 score cp 19 nodes 1793 nps 896500 time 2 pv d2d4 d7d5 g1f3 g8f6 b1d2 b8d7
info depth 7 multipv 1 score cp 17 nodes 7118 nps 1423600 time 5 pv c2c4 g8f6 b1c3 e7e6 d2d4 d7d5 g1f3 d5c4
info depth 8 multipv 1 score cp 22 nodes 14407 nps 1600777 time 9 pv d2d4 g8f6 g1f3 e7e6 c2c4 c7c5 d4d5 f8e7
info depth 9 multipv 1 score cp 27 nodes 31516 nps 1658736 time 19 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1e2 f8e7 g1f3
info depth 10 multipv 1 score cp 27 nodes 50001 nps 1724172 time 29 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 f8e7 d2d4 g8f6
info depth 11 multipv 1 score cp 28 nodes 72755 nps 1732261 time 42 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 f8e7 e1g1 g8f6 f1e1
info depth 12 multipv 1 score cp 36 nodes 145171 nps 1814637 time 80 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 f8e7 e1g1 g8f6 f1e1 b8c6
info depth 13 multipv 1 score cp 22 nodes 253248 nps 1862117 time 136 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 25 nodes 438145 nps 1856546 time 236 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1c3 b8c6
info depth 15 multipv 1 score cp 19 nodes 793687 nps 1858751 time 427 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 f1d3 c7c5 e4d5 e6d5 g1f3 c5d4 f3d4 b8c6 d3e2
info depth 16 multipv 1 score cp 20 nodes 1567428 nps 1848382 time 848 pv d2d4 g8f6 g1f3 e7e6 e2e3 d7d5 f1e2 f8e7 e1g1 e8g8 c2c4 d5c4 b1d2 c7c5 d4c5 b8d7
info depth 17 multipv 1 score cp 20 nodes 2568230 nps 1870524 time 1373 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8e7 g1f3 g8f6 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 20 nodes 3431573 nps 1842950 time 1862 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8e7 g1f3 g8f6 e1g1 e8g8 c1f4 c7c5 d4c5 e7c5 b1c3 f8e8
info depth 19 multipv 1 score cp 20 nodes 4450124 nps 1840415 time 2418 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 f8e8 f1e1 e8e1 f3e1 c7c5 d4c5 d6c5
info depth 20 multipv 1 score cp 22 nodes 6119721 nps 1840517 time 3325 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 c1f4 e7d6 f4g3 d6g3 h2g3 f8e8 f1e1 e8e1 d1e1
info depth 21 multipv 1 score cp 16 nodes 9583542 nps 1832767 time 5229 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 h2h3 b8d7 f1e1 h7h6 b1d2 d7b6 d2f1 f8e8 e1e8 d8e8
info depth 22 multipv 1 score cp 19 nodes 12450309 nps 1833624 time 6790 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 c1g5 c8g4 f1e1 h7h6 g5h4 g4h5 b1d2 c7c5 c2c4 b8c6 d4c5 d6c5 h4f6 d8f6 c4d5
info depth 23 multipv 1 score cp 18 nodes 29838409 nps 1836209 time 16250 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 f8e7 e1g1 g8f6 d2d4 c5d4 f3d4 e8g8 c1e3 d7d6 h2h3 c6d4 e3d4 a7a6 a2a4 d8c7 f1e1
info depth 24 multipv 1 score cp 17 nodes 73146878 nps 1831694 time 39934 pv c2c4 g8f6 g2g3 e7e6 d2d4 d7d5 g1f3 f8b4 c1d2 b4e7 f1g2 e8g8 e1g1 c7c6 d1c2 b8d7 f1c1 b7b6 b2b3 c8a6 a2a4 a8c8 a4a5 a6b7 f3e5
info depth 25 multipv 1 score cp 20 nodes 114299369 nps 1830254 time 62450 pv c2c4 g8f6 g1f3 c7c5 g2g3 g7g6 f1g2 f8g7 b1c3 d7d5 d2d4 c5d4 f3d4 e7e5 d1a4 b8d7 d4b5 d5d4 b5d6 e8f8 g2b7 c8b7 d6b7
```

```
Score of ChessDotCpp3.30 vs ChessDotCpp3.29: 261 - 237 - 1002  [0.508] 1500
...      ChessDotCpp3.30 playing White: 140 - 121 - 490  [0.513] 751
...      ChessDotCpp3.30 playing Black: 121 - 116 - 512  [0.503] 749
...      White vs Black: 256 - 242 - 1002  [0.505] 1500
Elo difference: 5.6 +/- 10.1, LOS: 85.9 %, DrawRatio: 66.8 %
```

### 3.31

Fix late move pruning quiet move counting for moves giving check

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 297 nps 297000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 455 nps 455000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 15 nodes 1000 nps 1000000 time 1 pv d2d4 d7d5 b1d2 g8f6 g1f3
info depth 6 multipv 1 score cp 23 nodes 3279 nps 1093000 time 3 pv e2e4 c7c5 f1e2 e7e6 g1f3 f8e7
info depth 7 multipv 1 score cp 22 nodes 4977 nps 1244250 time 4 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 d1d4
info depth 8 multipv 1 score cp 27 nodes 9860 nps 1408571 time 7 pv e2e4 b7b6 d2d4 c8b7 b1d2 d7d5 e4d5 d8d5
info depth 9 multipv 1 score cp 18 nodes 25511 nps 1594437 time 16 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 b1c3
info depth 10 multipv 1 score cp 25 nodes 39406 nps 1641916 time 24 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 f8e7 d2d4 c5d4 f3d4
info depth 11 multipv 1 score cp 24 nodes 62593 nps 1691702 time 37 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 26 nodes 115764 nps 1780984 time 65 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5 b1c3 d5c3 d2c3
info depth 13 multipv 1 score cp 22 nodes 231039 nps 1804992 time 128 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 23 nodes 355974 nps 1736458 time 205 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 c1g5 g8f6 f1e2 e8g8 e1g1 b8d7
info depth 15 multipv 1 score cp 23 nodes 576213 nps 1751407 time 329 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 16 multipv 1 score cp 28 nodes 1100519 nps 1783661 time 617 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 f1d3 e6e5 e1g1 f8e7
info depth 17 multipv 1 score cp 21 nodes 2032186 nps 1845763 time 1101 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c8g4 b1d2 b8d7 f1e1
info depth 18 multipv 1 score cp 22 nodes 2793160 nps 1865838 time 1497 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 b8c6 d4c5 e7c5
info depth 19 multipv 1 score cp 18 nodes 4534498 nps 1878416 time 2414 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 h2h3 c7c5 d4c5 e7c5 c1g5 f8e8 b1c3
info depth 20 multipv 1 score cp 24 nodes 6804633 nps 1879732 time 3620 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 d8d5 g1f3 g8f6 f1c4 d5d7 e1g1 c5d4 f1e1 f8e7 d2b3 e8g8 b3d4 d7c7
info depth 21 multipv 1 score cp 17 nodes 10294303 nps 1881956 time 5470 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 d8d5 g1f3 c5d4 f1c4 d5d7 e1g1 g8f6 f1e1 f8e7 d2b3 e8g8 d1d4 b8c6 d4d7 c8d7
info depth 22 multipv 1 score cp 20 nodes 13337475 nps 1883824 time 7080 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 f1d3 c7c5 d4c5 e7c5 e1g1 e8g8 a2a3 a7a5 h2h3 h7h6 e4e5 f6d7 d1e2 b8c6
info depth 23 multipv 1 score cp 20 nodes 29407636 nps 1869763 time 15728 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 f8e7 b1c3 d7c6 a2a4 g8f6 c1g5 e8g8 f3d2 f8e8 g5f6 e7f6
info depth 24 multipv 1 score cp 24 nodes 37717838 nps 1864082 time 20234 pv e2e4 c7c5 g1f3 e7e6 c2c3 b8c6 d2d4 d7d5 e4d5 e6d5 f1b5 f8d6 d4c5 d6c5 e1g1 g8e7 b1d2 e8g8 d2b3 c5b6 f1e1 a7a6 b5e2 e7g6
info depth 25 multipv 1 score cp 17 nodes 85024417 nps 1829977 time 46462 pv g1f3 g8f6 d2d4 c7c6 c2c4 d7d5 b1c3 d5c4 a2a4 c8f5 e2e3 e7e6 f1c4 f8b4 e1g1 e8g8 d1b3 d8e7 f3h4 f5g4 h2h3 g4h5 g2g4 f6g4 h3g4 e7h4 g4h5
```

```
Score of ChessDotCpp3.31 vs ChessDotCpp3.30: 283 - 244 - 973  [0.513] 1500
...      ChessDotCpp3.31 playing White: 145 - 120 - 485  [0.517] 750
...      ChessDotCpp3.31 playing Black: 138 - 124 - 488  [0.509] 750
...      White vs Black: 269 - 258 - 973  [0.504] 1500
Elo difference: 9.0 +/- 10.4, LOS: 95.5 %, DrawRatio: 64.9 %

Score of ChessDotCpp3.31 vs weiss2.0: 581 - 142 - 277  [0.720] 1000
...      ChessDotCpp3.31 playing White: 307 - 71 - 122  [0.736] 500
...      ChessDotCpp3.31 playing Black: 274 - 71 - 155  [0.703] 500
...      White vs Black: 378 - 345 - 277  [0.516] 1000
Elo difference: 163.6 +/- 19.4, LOS: 100.0 %, DrawRatio: 27.7 %
```

### 3.32

* No additional reductions if initial reduction is 0
* Allow killer reduction, instead lower reduction

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 286 nps 286000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 572 nps 572000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 14 nodes 1240 nps 1240000 time 1 pv d2d4 e7e6 g1f3 f8e7 b1d2
info depth 6 multipv 1 score cp 20 nodes 3216 nps 1072000 time 3 pv c2c4 c7c5 g1f3 e7e6 b1c3 f8e7
info depth 7 multipv 1 score cp 19 nodes 7393 nps 1478600 time 5 pv c2c4 c7c5 g2g3 e7e6 f1g2 f8e7 g1f3
info depth 8 multipv 1 score cp 26 nodes 21347 nps 1642076 time 13 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 f8e7
info depth 9 multipv 1 score cp 23 nodes 35139 nps 1673285 time 21 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8c7 e1g1 g8f6 b1c3
info depth 10 multipv 1 score cp 23 nodes 60471 nps 1778558 time 34 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 e4e5 f6d7 f1e2 c7c5
info depth 11 multipv 1 score cp 24 nodes 100418 nps 1825781 time 55 pv e2e4 e7e6 g1f3 c7c5 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 23 nodes 191428 nps 1895326 time 101 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 22 nodes 368682 nps 1940431 time 190 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 26 nodes 555830 nps 1971028 time 282 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 c1g5 e8g8 e1g1 c7c6
info depth 15 multipv 1 score cp 22 nodes 870130 nps 1991144 time 437 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 c2c3 f8e8 f1e1
info depth 16 multipv 1 score cp 18 nodes 1910490 nps 2006817 time 952 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c1g5 g8f6 f1d3 d8e7 d3e2 c7c6 e1g1 e8g8 f1e1
info depth 17 multipv 1 score cp 20 nodes 2572274 nps 2008020 time 1281 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 26 nodes 3298133 nps 2008607 time 1642 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c8g4 b1d2 b8c6 c2c3 f8e8
info depth 19 multipv 1 score cp 20 nodes 4559899 nps 2008766 time 2270 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 c7c5 d4c5 e7c5 b2b4 c5e7 f1e1
info depth 20 multipv 1 score cp 16 nodes 7044677 nps 1993964 time 3533 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 f1e1 c7c5 h2h3 g4h5
info depth 21 multipv 1 score cp 16 nodes 11636033 nps 1996231 time 5829 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8e7 c1g5 e8g8 e2e3 c7c6 f1d3 c8g4 e1g1 b8d7 g5f4 g4h5 h2h3
info depth 22 multipv 1 score cp 17 nodes 16254785 nps 1999604 time 8129 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 b4c3 b2c3 b8d7 e1g1 f8e8 f3d2
info depth 23 multipv 1 score cp 17 nodes 20399009 nps 1996379 time 10218 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 f8e8 e1g1 b4c3 b2c3 b8d7 f3d2 c7c6
info depth 24 multipv 1 score cp 15 nodes 37395619 nps 1990399 time 18788 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 b4c3 b2c3 b8d7 e1g1 d7b6 h2h3 c7c6 f3d2
info depth 25 multipv 1 score cp 26 nodes 74892799 nps 1989871 time 37637 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 e1g1 f8e7 b1c3 d7d6 a4c6 b7c6 d2d4 e5d4 f3d4 c8d7 h2h3 e8g8 f1e1 f8e8 d4e2 a6a5 c1e3 a5a4
```

```
Score of ChessDotCpp-no-additional-reductions-on-reduce vs ChessDotCpp3.31: 173 - 168 - 659  [0.502] 1000
...      ChessDotCpp-no-additional-reductions-on-reduce playing White: 79 - 79 - 343  [0.500] 501
...      ChessDotCpp-no-additional-reductions-on-reduce playing Black: 94 - 89 - 316  [0.505] 499
...      White vs Black: 168 - 173 - 659  [0.497] 1000
Elo difference: 1.7 +/- 12.6, LOS: 60.7 %, DrawRatio: 65.9 %

Score of ChessDotCpp3.32 vs ChessDotCpp3.31: 170 - 155 - 675  [0.507] 1000
...      ChessDotCpp3.32 playing White: 92 - 70 - 338  [0.522] 500
...      ChessDotCpp3.32 playing Black: 78 - 85 - 337  [0.493] 500
...      White vs Black: 177 - 148 - 675  [0.514] 1000
Elo difference: 5.2 +/- 12.3, LOS: 79.7 %, DrawRatio: 67.5 %
```

### 3.33

Fix bug with capture history downcasting

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 286 nps 286000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 572 nps 572000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 14 nodes 1240 nps 1240000 time 1 pv d2d4 e7e6 g1f3 f8e7 b1d2
info depth 6 multipv 1 score cp 20 nodes 3216 nps 1608000 time 2 pv c2c4 c7c5 g1f3 e7e6 b1c3 f8e7
info depth 7 multipv 1 score cp 19 nodes 7393 nps 1478600 time 5 pv c2c4 c7c5 g2g3 e7e6 f1g2 f8e7 g1f3
info depth 8 multipv 1 score cp 26 nodes 21347 nps 1778916 time 12 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 f8e7
info depth 9 multipv 1 score cp 23 nodes 35139 nps 1756950 time 20 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8c7 e1g1 g8f6 b1c3
info depth 10 multipv 1 score cp 23 nodes 60471 nps 1778558 time 34 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 e4e5 f6d7 f1e2 c7c5
info depth 11 multipv 1 score cp 24 nodes 100418 nps 1825781 time 55 pv e2e4 e7e6 g1f3 c7c5 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 23 nodes 191428 nps 1895326 time 101 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 22 nodes 368682 nps 1961074 time 188 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 26 nodes 555830 nps 1992222 time 279 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 c1g5 e8g8 e1g1 c7c6
info depth 15 multipv 1 score cp 22 nodes 870130 nps 2018863 time 431 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 c2c3 f8e8 f1e1
info depth 16 multipv 1 score cp 18 nodes 1910490 nps 2023824 time 944 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c1g5 g8f6 f1d3 d8e7 d3e2 c7c6 e1g1 e8g8 f1e1
info depth 17 multipv 1 score cp 20 nodes 2572274 nps 2008020 time 1281 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 26 nodes 3298133 nps 1973748 time 1671 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c8g4 b1d2 b8c6 c2c3 f8e8
info depth 19 multipv 1 score cp 20 nodes 4559899 nps 1983427 time 2299 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 c7c5 d4c5 e7c5 b2b4 c5e7 f1e1
info depth 20 multipv 1 score cp 16 nodes 7044677 nps 1976620 time 3564 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 f1e1 c7c5 h2h3 g4h5
info depth 21 multipv 1 score cp 16 nodes 11636033 nps 1990426 time 5846 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8e7 c1g5 e8g8 e2e3 c7c6 f1d3 c8g4 e1g1 b8d7 g5f4 g4h5 h2h3
info depth 22 multipv 1 score cp 17 nodes 16254785 nps 1981082 time 8205 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 b4c3 b2c3 b8d7 e1g1 f8e8 f3d2
info depth 23 multipv 1 score cp 17 nodes 20399009 nps 1979909 time 10303 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 f8e8 e1g1 b4c3 b2c3 b8d7 f3d2 c7c6
info depth 24 multipv 1 score cp 15 nodes 37395619 nps 1976512 time 18920 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 b4c3 b2c3 b8d7 e1g1 d7b6 h2h3 c7c6 f3d2
info depth 25 multipv 1 score cp 26 nodes 74892799 nps 1995704 time 37527 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 e1g1 f8e7 b1c3 d7d6 a4c6 b7c6 d2d4 e5d4 f3d4 c8d7 h2h3 e8g8 f1e1 f8e8 d4e2 a6a5 c1e3 a5a4
```

```
Score of ChessDotCpp3.33 vs ChessDotCpp3.32: 371 - 320 - 1309  [0.513] 2000
...      ChessDotCpp3.33 playing White: 195 - 157 - 647  [0.519] 999
...      ChessDotCpp3.33 playing Black: 176 - 163 - 662  [0.506] 1001
...      White vs Black: 358 - 333 - 1309  [0.506] 2000
Elo difference: 8.9 +/- 8.9, LOS: 97.4 %, DrawRatio: 65.5 %
```

### 3.34

Fix bug with qsearch capture history downcasting

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 286 nps 286000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 572 nps 572000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 14 nodes 1240 nps 1240000 time 1 pv d2d4 e7e6 g1f3 f8e7 b1d2
info depth 6 multipv 1 score cp 20 nodes 3216 nps 1072000 time 3 pv c2c4 c7c5 g1f3 e7e6 b1c3 f8e7
info depth 7 multipv 1 score cp 19 nodes 7393 nps 1478600 time 5 pv c2c4 c7c5 g2g3 e7e6 f1g2 f8e7 g1f3
info depth 8 multipv 1 score cp 26 nodes 21347 nps 1642076 time 13 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 f8e7
info depth 9 multipv 1 score cp 23 nodes 35139 nps 1673285 time 21 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8c7 e1g1 g8f6 b1c3
info depth 10 multipv 1 score cp 23 nodes 60471 nps 1778558 time 34 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 e4e5 f6d7 f1e2 c7c5
info depth 11 multipv 1 score cp 24 nodes 100418 nps 1825781 time 55 pv e2e4 e7e6 g1f3 c7c5 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 23 nodes 191428 nps 1914280 time 100 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 22 nodes 368682 nps 1950698 time 189 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 26 nodes 555830 nps 1992222 time 279 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 c1g5 e8g8 e1g1 c7c6
info depth 15 multipv 1 score cp 22 nodes 870130 nps 2023558 time 430 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 c2c3 f8e8 f1e1
info depth 16 multipv 1 score cp 18 nodes 1910490 nps 2056501 time 929 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c1g5 g8f6 f1d3 d8e7 d3e2 c7c6 e1g1 e8g8 f1e1
info depth 17 multipv 1 score cp 20 nodes 2572274 nps 2031812 time 1266 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 26 nodes 3298133 nps 2035884 time 1620 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c8g4 b1d2 b8c6 c2c3 f8e8
info depth 19 multipv 1 score cp 20 nodes 4559899 nps 2039310 time 2236 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c2c3 c7c5 d4c5 e7c5 b2b4 c5e7 f1e1
info depth 20 multipv 1 score cp 16 nodes 7044677 nps 2031337 time 3468 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 f1e1 c7c5 h2h3 g4h5
info depth 21 multipv 1 score cp 16 nodes 11636033 nps 2033915 time 5721 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8e7 c1g5 e8g8 e2e3 c7c6 f1d3 c8g4 e1g1 b8d7 g5f4 g4h5 h2h3
info depth 22 multipv 1 score cp 17 nodes 16254785 nps 2035410 time 7986 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 b4c3 b2c3 b8d7 e1g1 f8e8 f3d2
info depth 23 multipv 1 score cp 17 nodes 20399009 nps 2032178 time 10038 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 f8e8 e1g1 b4c3 b2c3 b8d7 f3d2 c7c6
info depth 24 multipv 1 score cp 15 nodes 37395619 nps 2029723 time 18424 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 c4d5 e6d5 b1c3 f8b4 c1g5 e8g8 e2e3 h7h6 g5h4 c8f5 f1e2 b4c3 b2c3 b8d7 e1g1 d7b6 h2h3 c7c6 f3d2
info depth 25 multipv 1 score cp 26 nodes 74892799 nps 2032975 time 36839 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 e1g1 f8e7 b1c3 d7d6 a4c6 b7c6 d2d4 e5d4 f3d4 c8d7 h2h3 e8g8 f1e1 f8e8 d4e2 a6a5 c1e3 a5a4
```

```
Score of ChessDotCpp3.34 vs ChessDotCpp3.33: 357 - 322 - 1321  [0.509] 2000
...      ChessDotCpp3.34 playing White: 195 - 147 - 659  [0.524] 1001
...      ChessDotCpp3.34 playing Black: 162 - 175 - 662  [0.493] 999
...      White vs Black: 370 - 309 - 1321  [0.515] 2000
Elo difference: 6.1 +/- 8.9, LOS: 91.0 %, DrawRatio: 66.0 %

Score of ChessDotCpp3.34 vs ChessDotCpp3.24: 196 - 142 - 662  [0.527] 1000
...      ChessDotCpp3.34 playing White: 105 - 62 - 333  [0.543] 500
...      ChessDotCpp3.34 playing Black: 91 - 80 - 329  [0.511] 500
...      White vs Black: 185 - 153 - 662  [0.516] 1000
Elo difference: 18.8 +/- 12.5, LOS: 99.8 %, DrawRatio: 66.2 %

Score of ChessDotCpp3.34 vs weiss2.0: 552 - 149 - 299  [0.702] 1000
...      ChessDotCpp3.34 playing White: 284 - 78 - 138  [0.706] 500
...      ChessDotCpp3.34 playing Black: 268 - 71 - 161  [0.697] 500
...      White vs Black: 355 - 346 - 299  [0.504] 1000
Elo difference: 148.4 +/- 18.9, LOS: 100.0 %, DrawRatio: 29.9 %

Score of ChessDotCpp3.34 vs seer2.5: 84 - 470 - 446  [0.307] 1000
...      ChessDotCpp3.34 playing White: 47 - 234 - 219  [0.313] 500
...      ChessDotCpp3.34 playing Black: 37 - 236 - 227  [0.301] 500
...      White vs Black: 283 - 271 - 446  [0.506] 1000
Elo difference: -141.4 +/- 16.1, LOS: 0.0 %, DrawRatio: 44.6 %
```

### 3.35

SEE pruning at depth 8

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 284 nps 284000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 568 nps 568000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 27 nodes 1775 nps 887500 time 2 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 6 multipv 1 score cp 27 nodes 2776 nps 925333 time 3 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 7 multipv 1 score cp 21 nodes 6396 nps 1279200 time 5 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8b6 b5c6 b6c6
info depth 8 multipv 1 score cp 22 nodes 12426 nps 1553250 time 8 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8b6 b5e2 g8f6
info depth 9 multipv 1 score cp 24 nodes 20760 nps 1596923 time 13 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 f8e7 b5c6 b7c6
info depth 10 multipv 1 score cp 26 nodes 35811 nps 1627772 time 22 pv e2e4 c7c5 g1f3 e7e6 b1c3 f8e7 d2d4 c5d4 f3d4 g8f6
info depth 11 multipv 1 score cp 28 nodes 73908 nps 1679727 time 44 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 f8e7 e1g1 g8f6 b5c6 b7c6
info depth 12 multipv 1 score cp 35 nodes 153780 nps 1727865 time 89 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 c6d4 e1g1 d4b5 c3b5 f8e7
info depth 13 multipv 1 score cp 27 nodes 254044 nps 1740027 time 146 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 g8e7 e1g1 a7a6 b5a4 e7g6 d2d4 c5d4 f3d4
info depth 14 multipv 1 score cp 27 nodes 384058 nps 1753689 time 219 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 g8e7 e1g1 a7a6 b5a4 e7g6 d2d4 c5d4 f3d4
info depth 15 multipv 1 score cp 19 nodes 923973 nps 1797612 time 514 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 f1d3 c7c5 e4d5 e6d5 g1f3 c5d4 f3d4 b8c6 d3e2
info depth 16 multipv 1 score cp 20 nodes 1353173 nps 1809054 time 748 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 17 multipv 1 score cp 20 nodes 1821773 nps 1823596 time 999 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 22 nodes 2620317 nps 1831109 time 1431 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 b8c6 d4c5 e7c5
info depth 19 multipv 1 score cp 20 nodes 3900759 nps 1820232 time 2143 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 b1d2 c8g4 c2c3 e7d6 d1b3 b8c6 b3b7
info depth 20 multipv 1 score cp 27 nodes 5963830 nps 1844673 time 3233 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 b8c6 e1g1 d8b6 d4c5 b6c7 f1e1 c6e5 f3e5 d7e5
info depth 21 multipv 1 score cp 27 nodes 8040819 nps 1856144 time 4332 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 b8c6 e1g1 d8b6 d4c5 b6c7 b2b4 e8g8 d2b3 c6e5 f3e5 d7e5
info depth 22 multipv 1 score cp 27 nodes 10369705 nps 1862040 time 5569 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 b8c6 e1g1 d8b6 d4c5 b6c7 b2b4 e8g8 d2b3 c6e5 f3e5 d7e5
info depth 23 multipv 1 score cp 20 nodes 14598818 nps 1867334 time 7818 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 b8c6 e1g1 a7a5 f1e1 e8g8 d3b1 b7b5 d1c2 g7g6 h2h3 c5d4 c3d4
info depth 24 multipv 1 score cp 21 nodes 32294473 nps 1885258 time 17130 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 a1b1 f8e7 e1g1 e8g8 a2a3 d7d6 b2b4 c6d4 d2d3 b7b6 h2h3 h7h6 c1e3 d4e2 d1e2
info depth 25 multipv 1 score cp 18 nodes 48324966 nps 1888874 time 25584 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 a1b1 f8e7 e1g1 e8g8 a2a3 d7d6 b2b4 c6d4 d2d3 b7b6 f1e1 c8d7 c1e3 h7h6 h2h3
```

```
Score of ChessDotCpp3.35 vs ChessDotCpp3.34: 1026 - 931 - 4043  [0.508] 6000
...      ChessDotCpp3.35 playing White: 536 - 464 - 2000  [0.512] 3000
...      ChessDotCpp3.35 playing Black: 490 - 467 - 2043  [0.504] 3000
...      White vs Black: 1003 - 954 - 4043  [0.504] 6000
Elo difference: 5.5 +/- 5.0, LOS: 98.4 %, DrawRatio: 67.4 %
```

### 3.36

Improve SEE pruning on qsearch

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 284 nps 284000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 562 nps 562000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 27 nodes 1758 nps 879000 time 2 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 6 multipv 1 score cp 27 nodes 2752 nps 917333 time 3 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5
info depth 7 multipv 1 score cp 21 nodes 6351 nps 1270200 time 5 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8b6 b5c6 b6c6
info depth 8 multipv 1 score cp 22 nodes 11973 nps 1496625 time 8 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8b6 b5e2 g8f6
info depth 9 multipv 1 score cp 24 nodes 20695 nps 1591923 time 13 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 f8e7 b5c6 b7c6
info depth 10 multipv 1 score cp 26 nodes 35307 nps 1681285 time 21 pv e2e4 c7c5 g1f3 e7e6 b1c3 f8e7 d2d4 c5d4 f3d4 g8f6
info depth 11 multipv 1 score cp 24 nodes 67164 nps 1767473 time 38 pv e2e4 c7c5 g1f3 b8c6 f1e2 e7e6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 28 nodes 136018 nps 1838081 time 74 pv e2e4 e7e5 g1f3 b8c6 b1c3 g8f6 f1b5 c6d4 f3e5 d4b5 c3b5 f6e4
info depth 13 multipv 1 score cp 22 nodes 288710 nps 1886993 time 153 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 23 nodes 463492 nps 1899557 time 244 pv e2e4 e7e6 g1f3 c7c5 f1e2 b8c6 c2c4 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4
info depth 15 multipv 1 score cp 20 nodes 941536 nps 1937316 time 486 pv g1f3 g8f6 d2d4 d7d5 e2e3 e7e6 c2c4 f8e7 f1e2 e8g8 e1g1 d5c4 b1d2 c7c5 d4c5
info depth 16 multipv 1 score cp 18 nodes 1452727 nps 1955218 time 743 pv g1f3 g8f6 d2d4 d7d5 e2e3 e7e6 f1e2 f8e7 e1g1 e8g8 c2c4 b8d7 d1c2 d5c4 e2c4 c7c5
info depth 17 multipv 1 score cp 22 nodes 2778595 nps 1936303 time 1435 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 c1g5 b8c6 c2c3 c8g4 b1d2
info depth 18 multipv 1 score cp 22 nodes 3573355 nps 1937828 time 1844 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 c1f4 c7c5 b1c3 b8c6 d4c5 e7c5
info depth 19 multipv 1 score cp 20 nodes 4983433 nps 1933811 time 2577 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1 c7c5 c2c3 d8c7 h2h3 b8c6 d4c5 e7c5
info depth 20 multipv 1 score cp 19 nodes 6955552 nps 1931024 time 3602 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8e7 f1d3 g8f6 e1g1 e8g8 b1c3 c8g4 c1f4 c7c6 h2h3 g4h5 f1e1 b8d7
info depth 21 multipv 1 score cp 16 nodes 10323948 nps 1930792 time 5347 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 g4h5 g5h4 b8d7 c2c4 d5c4 d2c4
info depth 22 multipv 1 score cp 16 nodes 13531427 nps 1930854 time 7008 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 c7c5 h2h3 g4h5 c4d5 c5d4
info depth 23 multipv 1 score cp 16 nodes 17863479 nps 1930560 time 9253 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 g5h4 c8g4 b1d2 h7h6 h2h3 g4h5 c2c4 d5c4 d2c4
info depth 24 multipv 1 score cp 18 nodes 34086968 nps 1916074 time 17790 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 c2c4 d5c4 d3c4 h7h6 g5h4 b8c6 h2h3 c6a5 c4d3 a5c6
info depth 25 multipv 1 score cp 29 nodes 54218694 nps 1919245 time 28250 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 f1d3 c7c5 d4c5 e7c5 e1g1 e8g8 h2h3 d8c7 a2a3 f8d8 e4e5 f6d7 f1e1 c5e7 d2b3 b8c6 c1f4
```

```
Score of ChessDotCpp3.36 vs ChessDotCpp3.35: 444 - 412 - 1644  [0.506] 2500
...      ChessDotCpp3.36 playing White: 240 - 198 - 812  [0.517] 1250
...      ChessDotCpp3.36 playing Black: 204 - 214 - 832  [0.496] 1250
...      White vs Black: 454 - 402 - 1644  [0.510] 2500
Elo difference: 4.4 +/- 8.0, LOS: 86.3 %, DrawRatio: 65.8 %
```

### 3.37

Improve base LMR

```
Score of ChessDotCpp3.37 vs weiss2.0: 574 - 139 - 287  [0.718] 1000
...      ChessDotCpp3.37 playing White: 301 - 58 - 141  [0.743] 500
...      ChessDotCpp3.37 playing Black: 273 - 81 - 146  [0.692] 500
...      White vs Black: 382 - 331 - 287  [0.525] 1000
Elo difference: 161.9 +/- 19.2, LOS: 100.0 %, DrawRatio: 28.7 %

Score of ChessDotCpp3.37 vs seer2.5: 144 - 723 - 633  [0.307] 1500
...      ChessDotCpp3.37 playing White: 83 - 330 - 337  [0.335] 750
...      ChessDotCpp3.37 playing Black: 61 - 393 - 296  [0.279] 750
...      White vs Black: 476 - 391 - 633  [0.528] 1500
Elo difference: -141.4 +/- 13.5, LOS: 0.0 %, DrawRatio: 42.2 %
```

### 3.38

Allow null move pruning at depth > 1

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 73 nps 73000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 292 nps 292000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 559 nps 559000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 15 nodes 1096 nps 1096000 time 1 pv d2d4 d7d5 b1d2 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 1862 nps 931000 time 2 pv d2d4 d7d5 b1d2 c8f5 g1f3 g8f6
info depth 7 multipv 1 score cp 11 nodes 6757 nps 1689250 time 4 pv d2d4 g8f6 c2c4 e7e6 e2e3 c7c5 g1f3 c5d4 e3d4
info depth 8 multipv 1 score cp 23 nodes 15201 nps 1689000 time 9 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 b7c6
info depth 9 multipv 1 score cp 27 nodes 20094 nps 1826727 time 11 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3
info depth 10 multipv 1 score cp 26 nodes 41518 nps 1887181 time 22 pv e2e4 c7c5 g1f3 e7e6 b1c3 f8e7 d2d4 c5d4 f3d4 g8f6
info depth 11 multipv 1 score cp 32 nodes 60276 nps 1883625 time 32 pv e2e4 c7c5 g1f3 e7e6 b1c3 f8e7 f1e2 b8c6 e1g1 g8f6 f1e1
info depth 12 multipv 1 score cp 26 nodes 104248 nps 1966943 time 53 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8e7 g1f3 c8g4 e1g1 g8f6
info depth 13 multipv 1 score cp 22 nodes 157154 nps 1989291 time 79 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8e7 g1f3 g8f6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 20 nodes 294321 nps 2058188 time 143 pv g1f3 g8f6 d2d4 e7e6 e2e3 f8e7 f1e2 d7d5 e1g1 e8g8 c2c4 d5c4 e2c4 c7c5
info depth 15 multipv 1 score cp 20 nodes 444849 nps 2098344 time 212 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 e2e3 d7d5 f1e2 d5c4 e1g1 e8g8 b1d2 c7c5 d4c5
info depth 16 multipv 1 score cp 23 nodes 669215 nps 2097852 time 319 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 e2e3 d7d5 f1e2 d5c4 e1g1 e8g8 b1d2 b8d7 d2c4 c7c5
info depth 17 multipv 1 score cp 20 nodes 1422149 nps 2135358 time 666 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8e7 g1f3 g8f6 c1f4 e8g8 e1g1 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 22 nodes 2015892 nps 2133219 time 945 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 f8e7 g1f3 g8f6 e1g1 e8g8 c1f4 c7c5 b1c3 b8c6 d4c5 e7c5
info depth 19 multipv 1 score cp 24 nodes 2842643 nps 2127726 time 1336 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c5d4 c3d4 c8d7 g1f3 b8c6 f1d3 d8b6 d3c2 c6b4 c2b3 g8e7 e1g1
info depth 20 multipv 1 score cp 17 nodes 4401016 nps 2121994 time 2074 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 c8g4 h2h3 g4h5 c2c4 d5c4 d3c4
info depth 21 multipv 1 score cp 22 nodes 5676976 nps 2116695 time 2682 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 c8g4 f1e1 b8d7 h2h3 g4h5 c2c4
info depth 22 multipv 1 score cp 23 nodes 7398955 nps 2113383 time 3501 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8d6 e1g1 e8g8 c1g5 c8g4 f1e1 g4h5 g5h4 b8d7 c2c4 c7c5 b1c3 d5c4 d3c4 h5f3 d1f3 c5d4
info depth 23 multipv 1 score cp 18 nodes 15491054 nps 2087743 time 7420 pv e2e4 c7c5 g1f3 e7e6 f1d3 b8c6 e1g1 f8e7 c2c3 d7d5 f1e1 g8f6 e4e5 f6d7 d3c2 e8g8 h2h3 a7a6 d2d4 c5d4 c3d4 c6b4 c1f4 b4c2 d1c2
info depth 24 multipv 1 score cp 27 nodes 22668034 nps 2085183 time 10871 pv e2e4 c7c5 g1f3 e7e6 c2c3 b8c6 d2d4 d7d5 e4d5 e6d5 f1b5 f8d6 e1g1 g8e7 d4c5 d6c5 b1d2 e8g8 d2b3 c5b6 f1e1 a7a6 b5e2 f8e8
info depth 25 multipv 1 score cp 18 nodes 35935751 nps 2081663 time 17263 pv e2e4 c7c5 g1f3 e7e6 c2c4 b8c6 b1c3 e6e5 d2d3 d7d6 f1e2 g8f6 e1g1 f8e7 h2h3 e8g8 a2a3 c6d4 f1e1 h7h6 b2b4 b7b6 a1b1 c8d7 c1e3
```

```
Score of ChessDotCpp3.38 vs ChessDotCpp3.37: 185 - 135 - 680  [0.525] 1000
...      ChessDotCpp3.38 playing White: 99 - 60 - 341  [0.539] 500
...      ChessDotCpp3.38 playing Black: 86 - 75 - 339  [0.511] 500
...      White vs Black: 174 - 146 - 680  [0.514] 1000
Elo difference: 17.4 +/- 12.2, LOS: 99.7 %, DrawRatio: 68.0 %

Score of ChessDotCpp3.38 vs ChessDotCpp3.24: 331 - 207 - 962  [0.541] 1500
...      ChessDotCpp3.38 playing White: 176 - 108 - 467  [0.545] 751
...      ChessDotCpp3.38 playing Black: 155 - 99 - 495  [0.537] 749
...      White vs Black: 275 - 263 - 962  [0.504] 1500
Elo difference: 28.8 +/- 10.5, LOS: 100.0 %, DrawRatio: 64.1 %

Score of ChessDotCpp3.38 vs weiss2.0: 551 - 134 - 315  [0.709] 1000
...      ChessDotCpp3.38 playing White: 278 - 65 - 157  [0.713] 500
...      ChessDotCpp3.38 playing Black: 273 - 69 - 158  [0.704] 500
...      White vs Black: 347 - 338 - 315  [0.504] 1000
Elo difference: 154.3 +/- 18.6, LOS: 100.0 %, DrawRatio: 31.5 %

Score of ChessDotCpp3.38 vs seer2.5: 142 - 662 - 696  [0.327] 1500
...      ChessDotCpp3.38 playing White: 78 - 332 - 341  [0.331] 751
...      ChessDotCpp3.38 playing Black: 64 - 330 - 355  [0.322] 749
...      White vs Black: 408 - 396 - 696  [0.504] 1500
Elo difference: -125.7 +/- 12.9, LOS: 0.0 %, DrawRatio: 46.4 %
```

### 3.39

Remove static evaluation pruning based on improving metric

```
info depth 1 multipv 1 score cp 20 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 multipv 1 score cp 23 nodes 69 nps 69000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 9 nodes 275 nps 275000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 20 nodes 487 nps 487000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 15 nodes 940 nps 940000 time 1 pv d2d4 d7d5 b1d2 g8f6 g1f3
info depth 6 multipv 1 score cp 24 nodes 1621 nps 810500 time 2 pv d2d4 d7d5 b1d2 c8f5 g1f3 g8f6
info depth 7 multipv 1 score cp 12 nodes 6662 nps 1665500 time 4 pv e2e3 g8f6 f1e2 e7e6 c2c4 f8e7 d2d4
info depth 8 multipv 1 score cp 21 nodes 16090 nps 1787777 time 9 pv e2e3 g8f6 g1f3 e7e6 c2c4 f8e7 f1e2 c7c5
info depth 9 multipv 1 score cp 27 nodes 32672 nps 1815111 time 18 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 f8e7 d2d4
info depth 10 multipv 1 score cp 23 nodes 44656 nps 1860666 time 24 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 e4e5 f6d7 f1e2 c7c5
info depth 11 multipv 1 score cp 28 nodes 71226 nps 1874368 time 38 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 f1e1
info depth 12 multipv 1 score cp 26 nodes 107868 nps 1926214 time 56 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 c8g4 e1g1 f8e7
info depth 13 multipv 1 score cp 22 nodes 162744 nps 1960771 time 83 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 23 nodes 242666 nps 1989065 time 122 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 d4c5 e7c5
info depth 15 multipv 1 score cp 20 nodes 479410 nps 2014327 time 238 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 d7d5 f1e2 d5c4 e1g1 c7c5 d4c5 e8g8 b1d2
info depth 16 multipv 1 score cp 22 nodes 735217 nps 2036612 time 361 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 d7d5 f1e2 d5c4 e1g1 c7c5 d4c5 b8d7 e2c4 d7c5 d1d8 e7d8
info depth 17 multipv 1 score cp 20 nodes 1391841 nps 2055895 time 677 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 b1c3 f8e8 d4c5 e7c5
info depth 18 multipv 1 score cp 22 nodes 1928843 nps 2062933 time 935 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 c1f4 c7c5 d4c5 e7c5 b1c3 b8c6
info depth 19 multipv 1 score cp 31 nodes 3200873 nps 2058439 time 1555 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 b8c6 g1e2 c5d4 c3d4 f8e7 e1g1 c6b4 d2f3 b4d3 d1d3
info depth 20 multipv 1 score cp 29 nodes 4131847 nps 2052581 time 2013 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 d8d5 g1f3 c5d4 f1c4 d5d8 e1g1 g8f6 d2b3 d8c7 d1e2 f8e7 f1e1 e8g8 b3d4
info depth 21 multipv 1 score cp 29 nodes 5038661 nps 2058276 time 2448 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 d8d5 g1f3 c5d4 f1c4 d5d8 e1g1 g8f6 d2b3 d8c7 d1e2 f8e7 f1e1 e8g8 b3d4
info depth 22 multipv 1 score cp 20 nodes 7514628 nps 2092045 time 3592 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 f1d3 c7c5 c2c3 b8c6 e1g1 d8b6 d4c5 b6c7 d3c2 c6e5 b2b4 e8g8 f3e5 d7e5
info depth 23 multipv 1 score cp 26 nodes 9585747 nps 2111863 time 4539 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 f1d3 c7c5 c2c3 b8c6 e1g1 d8b6 f1e1 e8g8 d4c5 b6c7 d1e2 d7c5 d3c2
info depth 24 multipv 1 score cp 20 nodes 19209458 nps 2148468 time 8941 pv e2e4 c7c5 g1f3 e7e6 b1c3 a7a6 g2g3 d7d6 f1g2 g8f6 e1g1 e6e5 d2d3 f8e7 f3h4 b8c6 h4f5 c8f5 e4f5 d8d7 c1g5 d7f5 g5f6 f5f6
info depth 25 multipv 1 score cp 19 nodes 27241914 nps 2149263 time 12675 pv e2e4 c7c5 g1f3 e7e6 b1c3 a7a6 d2d4 c5d4 f3d4 d7d6 g2g4 d8c7 c1e3 b7b5 f1g2 c8b7 e1g1 b8d7 h2h3 h7h6 f2f4 b5b4 c3a4 g8f6 c2c3
```

```
Score of ChessDotCpp3.39 vs ChessDotCpp3.38: 359 - 312 - 1426  [0.511] 2097
...      ChessDotCpp3.39 playing White: 202 - 149 - 697  [0.525] 1048
...      ChessDotCpp3.39 playing Black: 157 - 163 - 729  [0.497] 1049
...      White vs Black: 365 - 306 - 1426  [0.514] 2097
Elo difference: 7.8 +/- 8.4, LOS: 96.5 %, DrawRatio: 68.0 %
```

### 3.40

Reduce allocated time by best move node count instead of best move changes in iterative deepening

5+0.05
```
Score of ChessDotCpp3.40 vs ChessDotCpp3.39: 264 - 233 - 1003  [0.510] 1500
...      ChessDotCpp3.40 playing White: 132 - 104 - 514  [0.519] 750
...      ChessDotCpp3.40 playing Black: 132 - 129 - 489  [0.502] 750
...      White vs Black: 261 - 236 - 1003  [0.508] 1500
Elo difference: 7.2 +/- 10.1, LOS: 91.8 %, DrawRatio: 66.9 %

Score of ChessDotCpp3.40 vs weiss2.0: 618 - 130 - 252  [0.744] 1000
...      ChessDotCpp3.40 playing White: 325 - 61 - 115  [0.763] 501
...      ChessDotCpp3.40 playing Black: 293 - 69 - 137  [0.724] 499
...      White vs Black: 394 - 354 - 252  [0.520] 1000
Elo difference: 185.3 +/- 20.2, LOS: 100.0 %, DrawRatio: 25.2 %

Score of ChessDotCpp3.40 vs seer2.5: 93 - 448 - 459  [0.323] 1000
...      ChessDotCpp3.40 playing White: 50 - 215 - 235  [0.335] 500
...      ChessDotCpp3.40 playing Black: 43 - 233 - 224  [0.310] 500
...      White vs Black: 283 - 258 - 459  [0.512] 1000
Elo difference: -129.0 +/- 15.9, LOS: 0.0 %, DrawRatio: 45.9 %
```

60+0.6
```
Score of ChessDotCpp3.40 vs ChessDotCpp3.39: 11 - 12 - 77  [0.495] 100
...      ChessDotCpp3.40 playing White: 8 - 5 - 37  [0.530] 50
...      ChessDotCpp3.40 playing Black: 3 - 7 - 40  [0.460] 50
...      White vs Black: 15 - 8 - 77  [0.535] 100
Elo difference: -3.5 +/- 32.7, LOS: 41.7 %, DrawRatio: 77.0 %
```

```
Score of ChessDotCpp3.41 vs ChessDotCpp3.40: 170 - 190 - 684  [0.490] 1044
...      ChessDotCpp3.41 playing White: 102 - 84 - 336  [0.517] 522
...      ChessDotCpp3.41 playing Black: 68 - 106 - 348  [0.464] 522
...      White vs Black: 208 - 152 - 684  [0.527] 1044
Elo difference: -6.7 +/- 12.4, LOS: 14.6 %, DrawRatio: 65.5 %
```

### 3.41

Retrain same NNUE arch on 650M (+105M) FENs

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -614  | -466  | -520  | -1016 |  -99  | -506  | -467  | -624  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -73  | -131  | -129  | -142  | -165  | -177  | -139  |  -71  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  72   |  126  |  124  |  138  |  156  |  168  |  137  |  70   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  571  |  458  |  503  |  892  |  104  |  487  |  457  |  584  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 24
Phase: 24
```

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 269 nps 269000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 28 nodes 511 nps 511000 time 1 pv d2d4 g7g6 g1f3 g8f6
info depth 5 multipv 1 score cp 17 nodes 2072 nps 1036000 time 2 pv e2e4 d7d6 g2g3 d6d5 e4d5 d8d5
info depth 6 multipv 1 score cp 24 nodes 3750 nps 1250000 time 3 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7
info depth 7 multipv 1 score cp 17 nodes 7731 nps 1546200 time 5 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 d2d4 c5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 13412 nps 1676500 time 8 pv e2e4 c7c5 g1f3 g7g6 f1c4 f8g7 b1c3 g8f6
info depth 9 multipv 1 score cp 24 nodes 19815 nps 1801363 time 11 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 b1c3
info depth 10 multipv 1 score cp 29 nodes 30408 nps 1900500 time 16 pv e2e4 c7c5 g1f3 b8c6 f1e2 e7e6 b1c3 f8e7 d2d4 c5d4 f3d4
info depth 11 multipv 1 score cp 22 nodes 51433 nps 1836892 time 28 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 22 nodes 80518 nps 1872511 time 43 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 21 nodes 143160 nps 1961095 time 73 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4b5 d7d5 e4d5 e6d5
info depth 14 multipv 1 score cp 25 nodes 244617 nps 2005057 time 122 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 f1e1 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 multipv 1 score cp 23 nodes 422041 nps 2048742 time 206 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4c6 b7c6 e4e5 f6d5 c3e4
info depth 16 multipv 1 score cp 31 nodes 1016273 nps 2091096 time 486 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1c3 f8e8 f1e1 c7c6
info depth 17 multipv 1 score cp 23 nodes 1419382 nps 2099677 time 676 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 c2c3 b8c6 h2h3
info depth 18 multipv 1 score cp 29 nodes 2131385 nps 2099886 time 1015 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1d2 c7c5 f1e1 c5d4 f3d4 b8c6
info depth 19 multipv 1 score cp 29 nodes 2788766 nps 2098394 time 1329 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1d2 c7c5 d2b3 c5d4 b3d4 f8e8 c2c3
info depth 20 multipv 1 score cp 26 nodes 4197196 nps 2097549 time 2001 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 h2h3 f8e8 c2c4 b8c6 b1c3 c6b4 d3e2 c7c6
info depth 21 multipv 1 score cp 20 nodes 6317696 nps 2094032 time 3017 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 c2c3 b8d7 b1d2 g4h5 d1c2 h7h6 g5h4
info depth 22 multipv 1 score cp 21 nodes 8122033 nps 2089537 time 3887 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 f1e1 e8e1 d1e1 b8d7 b1d2 d7f8 h2h3 c7c6 g5h4
info depth 23 multipv 1 score cp 18 nodes 11173876 nps 2082735 time 5365 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 c2c3 b8d7 b1d2 c7c5 h2h3 g4h5 d1c2 h7h6 g5h4
info depth 24 multipv 1 score cp 19 nodes 19784571 nps 2072550 time 9546 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 d8d5 g1f3 c5d4 f1c4 d5d6 c4b3 b8c6 e1g1 g8f6 d2c4 d6d8 c1f4 f8e7 c4e5 c6e5 f4e5 e8g8 d1d4
info depth 25 multipv 1 score cp 20 nodes 29510835 nps 2064849 time 14292 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 b1d2 h7h6 g5h4 f8e8 c2c3 b8d7 d1c2 g4h5 f1e1 c7c6 h2h3
```

```
Score of ChessDotCpp3.41 vs ChessDotCpp3.40: 341 - 297 - 962  [0.514] 1600
...      ChessDotCpp3.41 playing White: 178 - 137 - 485  [0.526] 800
...      ChessDotCpp3.41 playing Black: 163 - 160 - 477  [0.502] 800
...      White vs Black: 338 - 300 - 962  [0.512] 1600
Elo difference: 9.6 +/- 10.7, LOS: 95.9 %, DrawRatio: 60.1 %
```

### 3.42

LMR speedup

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 269 nps 269000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 28 nodes 511 nps 511000 time 1 pv d2d4 g7g6 g1f3 g8f6
info depth 5 multipv 1 score cp 17 nodes 2072 nps 1036000 time 2 pv e2e4 d7d6 g2g3 d6d5 e4d5 d8d5
info depth 6 multipv 1 score cp 24 nodes 3750 nps 1250000 time 3 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7
info depth 7 multipv 1 score cp 17 nodes 7731 nps 1546200 time 5 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 d2d4 c5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 13412 nps 1676500 time 8 pv e2e4 c7c5 g1f3 g7g6 f1c4 f8g7 b1c3 g8f6
info depth 9 multipv 1 score cp 24 nodes 19815 nps 1651250 time 12 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 b1c3
info depth 10 multipv 1 score cp 29 nodes 30408 nps 1788705 time 17 pv e2e4 c7c5 g1f3 b8c6 f1e2 e7e6 b1c3 f8e7 d2d4 c5d4 f3d4
info depth 11 multipv 1 score cp 22 nodes 51433 nps 1904925 time 27 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 22 nodes 80518 nps 1963853 time 41 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 21 nodes 143160 nps 2016338 time 71 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4b5 d7d5 e4d5 e6d5
info depth 14 multipv 1 score cp 25 nodes 244617 nps 2073025 time 118 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 f1e1 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 multipv 1 score cp 23 nodes 422041 nps 2131520 time 198 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4c6 b7c6 e4e5 f6d5 c3e4
info depth 16 multipv 1 score cp 31 nodes 1016273 nps 2166893 time 469 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1c3 f8e8 f1e1 c7c6
info depth 17 multipv 1 score cp 23 nodes 1419382 nps 2170308 time 654 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1 c7c5 c2c3 b8c6 h2h3
info depth 18 multipv 1 score cp 29 nodes 2131385 nps 2163842 time 985 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1d2 c7c5 f1e1 c5d4 f3d4 b8c6
info depth 19 multipv 1 score cp 29 nodes 2788766 nps 2163511 time 1289 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 b1d2 c7c5 d2b3 c5d4 b3d4 f8e8 c2c3
info depth 20 multipv 1 score cp 26 nodes 4197196 nps 2155724 time 1947 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 h2h3 f8e8 c2c4 b8c6 b1c3 c6b4 d3e2 c7c6
info depth 21 multipv 1 score cp 20 nodes 6317696 nps 2157683 time 2928 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 c2c3 b8d7 b1d2 g4h5 d1c2 h7h6 g5h4
info depth 22 multipv 1 score cp 21 nodes 8122033 nps 2154385 time 3770 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 f1e1 e8e1 d1e1 b8d7 b1d2 d7f8 h2h3 c7c6 g5h4
info depth 23 multipv 1 score cp 18 nodes 11173876 nps 2148409 time 5201 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 c2c3 b8d7 b1d2 c7c5 h2h3 g4h5 d1c2 h7h6 g5h4
info depth 24 multipv 1 score cp 19 nodes 19784571 nps 2131958 time 9280 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 d8d5 g1f3 c5d4 f1c4 d5d6 c4b3 b8c6 e1g1 g8f6 d2c4 d6d8 c1f4 f8e7 c4e5 c6e5 f4e5 e8g8 d1d4
info depth 25 multipv 1 score cp 20 nodes 29510835 nps 2125834 time 13882 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 b1d2 h7h6 g5h4 f8e8 c2c3 b8d7 d1c2 g4h5 f1e1 c7c6 h2h3
```

```
Score of ChessDotCpp3.42 vs ChessDotCpp3.41: 254 - 238 - 1008  [0.505] 1500
...      ChessDotCpp3.42 playing White: 142 - 106 - 502  [0.524] 750
...      ChessDotCpp3.42 playing Black: 112 - 132 - 506  [0.487] 750
...      White vs Black: 274 - 218 - 1008  [0.519] 1500
Elo difference: 3.7 +/- 10.1, LOS: 76.5 %, DrawRatio: 67.2 %
```

### 3.43

More LMR for non-PV nodes

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 269 nps 269000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 28 nodes 511 nps 511000 time 1 pv d2d4 g7g6 g1f3 g8f6
info depth 5 multipv 1 score cp 17 nodes 1948 nps 974000 time 2 pv e2e4 d7d6 g2g3 d6d5 e4d5 d8d5
info depth 6 multipv 1 score cp 24 nodes 3388 nps 1129333 time 3 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7
info depth 7 multipv 1 score cp 17 nodes 9682 nps 1613666 time 6 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 d2d4 c5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 14340 nps 1593333 time 9 pv e2e4 c7c5 g1f3 g7g6 f1c4 f8g7 b1c3 g8f6
info depth 9 multipv 1 score cp 22 nodes 22654 nps 1742615 time 13 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4
info depth 10 multipv 1 score cp 29 nodes 30403 nps 1689055 time 18 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 f8e7 d2d4 c5d4 f3d4
info depth 11 multipv 1 score cp 22 nodes 53707 nps 1790233 time 30 pv e2e4 e7e5 g1f3 b8c6 f1b5 c6d4 b5c4 d4f3 d1f3 g8f6 b1c3 c7c6
info depth 12 multipv 1 score cp 21 nodes 82809 nps 1882022 time 44 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 b5c6 d7c6 f3e5 b4c3 b2c3 f6e4
info depth 13 multipv 1 score cp 20 nodes 146050 nps 1947333 time 75 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 f1e2 g7g6 d2d4 c5d4 f3d4 f8g7 d4b5
info depth 14 multipv 1 score cp 31 nodes 295681 nps 2025212 time 146 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 b8c6 b1d2 e4d2 c1d2 f8e7 e5f3 d7d5
info depth 15 multipv 1 score cp 23 nodes 443464 nps 2072261 time 214 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5 c3e4
info depth 16 multipv 1 score cp 29 nodes 768004 nps 2104120 time 365 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 f1b5 c8d7 b5d7 d8d7 e1g1 g8f6 f1e1 b8c6 d2d4 c5d4 f3d4 f8e7 d4c6 b7c6
info depth 17 multipv 1 score cp 22 nodes 1087437 nps 2111528 time 515 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 f3d4 g8f6 d1f3 f8e7 f3g3 e8g8 c1e3 b8c6 e1c1
info depth 18 multipv 1 score cp 30 nodes 1556247 nps 2120227 time 734 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 b5c6 d7c6 e1g1 g8f6 f1e1 f8e7
info depth 19 multipv 1 score cp 21 nodes 2325440 nps 2147220 time 1083 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7 b1c3
info depth 20 multipv 1 score cp 23 nodes 3231768 nps 2158829 time 1497 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 f8e7 e1g1 g8f6 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 d1d8 f8d8 c1e3 f6d7
info depth 21 multipv 1 score cp 21 nodes 4643399 nps 2155709 time 2154 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 f8e7 e1g1 g8f6 d2d4 c5d4 f3d4 e8g8 c1e3 c6d4 d1d4 d7d6 f1e1 c8d7 d4d2
info depth 22 multipv 1 score cp 14 nodes 9157734 nps 2138658 time 4282 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 g8e7 d4d1 a7a6 b5e2 e7g6 c1e3 f8e7 e1g1 e8g8
info depth 23 multipv 1 score cp 19 nodes 10639985 nps 2134400 time 4985 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 g8e7 d4d1 a7a6 b5e2 b7b5 c1e3 c8b7 h2h4 h7h6 e1g1 d8c7 f1e1
info depth 24 multipv 1 score cp 20 nodes 15311379 nps 2111040 time 7253 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 f3d4 a7a6 f2f4 b7b5 f1e2 c8b7 e2f3 b8d7 e1g1 f8e7 f1e1 d8b8 d1e2 g8f6 e4e5 d6e5 f4e5 b7f3 d4f3
info depth 25 multipv 1 score cp 15 nodes 29856485 nps 2075817 time 14383 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 f3e1 d7d6 f2f4 a7a6 f4f5 b7b5 c4b5 c6d4 b5a6 d6d5 e1c2 d5e4 d3e4 d4e2 d1e2 c8a6
```

```
Score of ChessDotCpp3.43 vs ChessDotCpp3.42: 180 - 151 - 669  [0.514] 1000
...      ChessDotCpp3.43 playing White: 92 - 75 - 335  [0.517] 502
...      ChessDotCpp3.43 playing Black: 88 - 76 - 334  [0.512] 498
...      White vs Black: 168 - 163 - 669  [0.502] 1000
Elo difference: 10.1 +/- 12.4, LOS: 94.5 %, DrawRatio: 66.9 %

Score of ChessDotCpp3.43 vs weiss2.0: 583 - 139 - 278  [0.722] 1000
...      ChessDotCpp3.43 playing White: 291 - 66 - 143  [0.725] 500
...      ChessDotCpp3.43 playing Black: 292 - 73 - 135  [0.719] 500
...      White vs Black: 364 - 358 - 278  [0.503] 1000
Elo difference: 165.8 +/- 19.4, LOS: 100.0 %, DrawRatio: 27.8 %
```

### 3.44

More LMR for PV nodes

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 192 nps 192000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 22 nodes 353 nps 353000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 1191 nps 595500 time 2 pv e2e4 g7g6 g1f3 f8g7 d2d4
info depth 6 multipv 1 score cp 21 nodes 2493 nps 1246500 time 2 pv d2d4 d7d5 g1f3 g8f6 b1d2 b8d7
info depth 7 multipv 1 score cp 17 nodes 5091 nps 1272750 time 4 pv g1f3 g8f6 b1c3 c7c5 e2e4 b8c6 d2d4 c5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 9323 nps 1553833 time 6 pv e2e4 c7c5 g1f3 g7g6 b1c3 f8g7 f1c4 g8f6
info depth 9 multipv 1 score cp 27 nodes 13836 nps 1537333 time 9 pv e2e4 c7c5 g1f3 g7g6 d2d4 c5d4 d1d4 g8f6 b1c3
info depth 10 multipv 1 score cp 18 nodes 27893 nps 1743312 time 16 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 f8c5 d4c6 b7c6
info depth 11 multipv 1 score cp 22 nodes 45918 nps 1766076 time 26 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 12 multipv 1 score cp 22 nodes 62768 nps 1793371 time 35 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 19 nodes 115570 nps 1864032 time 62 pv e2e4 c7c5 g1f3 e7e6 g2g3 d7d5 e4d5 e6d5 d2d4 b8c6 f1g2 c8g4 d1e2 d8e7
info depth 14 multipv 1 score cp 20 nodes 197562 nps 1936882 time 102 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 d2d4 e8g8 f1e1 c7c6
info depth 15 multipv 1 score cp 22 nodes 272394 nps 1973869 time 138 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 b8d7 f1e1
info depth 16 multipv 1 score cp 27 nodes 425153 nps 2024538 time 210 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 f1e1 b8d7
info depth 17 multipv 1 score cp 21 nodes 730065 nps 2097887 time 348 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 h2h3 f8e8 c1g5 b8d7 b1c3
info depth 18 multipv 1 score cp 17 nodes 1446669 nps 2149582 time 673 pv g1f3 g8f6 d2d4 d7d5 e2e3 e7e6 f1e2 f8e7 e1g1 e8g8 c2c4 d5c4 e2c4 c7c5 d4c5 e7c5 b1c3 b8c6
info depth 19 multipv 1 score cp 22 nodes 2499987 nps 2158883 time 1158 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 c8g4 b1d2 g4h5
info depth 20 multipv 1 score cp 17 nodes 3368690 nps 2169150 time 1553 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 g5h4 g4h5 f1e1 f8e8
info depth 21 multipv 1 score cp 18 nodes 4202978 nps 2172081 time 1935 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 c8g4 c2c3 b8d7 b1d2 h7h6 g5h4 c7c5 f1e1
info depth 22 multipv 1 score cp 16 nodes 7170106 nps 2161623 time 3317 pv g1f3 g8f6 c2c4 e7e6 g2g3 d7d5 d2d4 f8b4 c1d2 a7a5 a2a3 b4e7 f1g2 e8g8 d1c2 d5c4 c2c4 c7c5 d4c5 b8d7 e1g1 d7c5 f1d1
info depth 23 multipv 1 score cp 18 nodes 10349282 nps 2165121 time 4780 pv g1f3 g8f6 c2c4 e7e6 g2g3 d7d5 d2d4 f8b4 c1d2 a7a5 a2a3 b4e7 f1g2 e8g8 d1c2 d5c4 c2c4 c7c5 d4c5 b8d7 e1g1 d7c5 f3e5 d8b6
info depth 24 multipv 1 score cp 19 nodes 13540334 nps 2160921 time 6266 pv g1f3 g8f6 c2c4 e7e6 g2g3 d7d5 d2d4 f8b4 c1d2 a7a5 a2a3 b4e7 f1g2 e8g8 d1c2 c7c5 d4c5 d5d4 e1g1 b8c6 e2e3 e7c5 f1d1 d8b6 e3d4 c6d4 f3d4 c5d4
info depth 25 multipv 1 score cp 20 nodes 25471030 nps 2141682 time 11893 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 d2d4 e8g8 c2c4 c7c6 e1g1 d7d5 c4d5 c6d5 b1c3 b8c6 f3e5 f8e8 c1f4 c8f5 e2e3 a8c8 a1c1 c6e5 d4e5
```

```
Score of ChessDotCpp3.44 vs ChessDotCpp3.43: 159 - 138 - 703  [0.510] 1000
...      ChessDotCpp3.44 playing White: 78 - 69 - 353  [0.509] 500
...      ChessDotCpp3.44 playing Black: 81 - 69 - 350  [0.512] 500
...      White vs Black: 147 - 150 - 703  [0.498] 1000
Elo difference: 7.3 +/- 11.7, LOS: 88.8 %, DrawRatio: 70.3 %
```

### 3.45

Remove LMR reduction on killer moves

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 192 nps 192000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 22 nodes 353 nps 353000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 21 nodes 1191 nps 1191000 time 1 pv e2e4 g7g6 g1f3 f8g7 d2d4
info depth 6 multipv 1 score cp 21 nodes 2493 nps 1246500 time 2 pv d2d4 d7d5 g1f3 g8f6 b1d2 b8d7
info depth 7 multipv 1 score cp 17 nodes 5071 nps 1267750 time 4 pv g1f3 g8f6 b1c3 c7c5 e2e4 b8c6 d2d4 c5d4 f3d4
info depth 8 multipv 1 score cp 26 nodes 9291 nps 1548500 time 6 pv e2e4 c7c5 g1f3 g7g6 b1c3 f8g7 f1c4 g8f6
info depth 9 multipv 1 score cp 27 nodes 13756 nps 1528444 time 9 pv e2e4 c7c5 g1f3 g7g6 d2d4 c5d4 d1d4 g8f6 b1c3
info depth 10 multipv 1 score cp 29 nodes 19526 nps 1627166 time 12 pv e2e4 c7c5 g1f3 b8c6 f1e2 e7e6 b1c3 f8e7 d2d4 c5d4 f3d4
info depth 11 multipv 1 score cp 28 nodes 30856 nps 1815058 time 17 pv e2e4 c7c5 g1f3 b8c6 b1c3 g7g6 f1e2 f8g7 e1g1 g8f6 f1e1
info depth 12 multipv 1 score cp 27 nodes 48265 nps 1856346 time 26 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 c6d4 e4e5 d4b5 c3b5 f6d5
info depth 13 multipv 1 score cp 23 nodes 77769 nps 1896804 time 41 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 a7a6 b5c6 d7c6 f1e1
info depth 14 multipv 1 score cp 21 nodes 162145 nps 2001790 time 81 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4b5 d7d5 e4d5 e6d5
info depth 15 multipv 1 score cp 30 nodes 288498 nps 2031676 time 142 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 a7a6 b5c4 d5b6 c4b3 e7e6 f1e1
info depth 16 multipv 1 score cp 27 nodes 555203 nps 2087229 time 266 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 d8d7 e1g1 e7e6 f1e1 f8e7 a2a4 a7a6 b1c3 g8f6 d2d4 c5d4 d1d4
info depth 17 multipv 1 score cp 17 nodes 988503 nps 2116708 time 467 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 e1g1 e8g8 h2h3 b8c6 c2c3 f8e8 b1d2
info depth 18 multipv 1 score cp 18 nodes 1310621 nps 2127631 time 616 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c7c6 f1e1 c8g4 h2h3 g4h5
info depth 19 multipv 1 score cp 20 nodes 1888417 nps 2131396 time 886 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 e4d5 e6d5 f1d3 g8f6 g1f3 e8g8 e1g1 f8e8 f1e1 b8d7 c2c3 c7c5 h2h3
info depth 20 multipv 1 score cp 28 nodes 2925255 nps 2127458 time 1375 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 e8g8 e1g1 a7a5 d3b1 a5a4 f1e1 c5d4 f3d4
info depth 21 multipv 1 score cp 27 nodes 3697049 nps 2135787 time 1731 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 g1f3 g8f6 e4e5 f6d7 c2c3 c7c5 f1d3 e8g8 e1g1 a7a5 d3b1 a5a4 d1c2 g7g6 h2h3
info depth 22 multipv 1 score cp 25 nodes 5942472 nps 2140659 time 2776 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d3 g8f6 c2c3 e7e5 d3c2 f8e7 d2d4 e8g8 d4d5 b7b5 a2a4 c8b7 b1d2 d8c7 h2h3
info depth 23 multipv 1 score cp 23 nodes 8496014 nps 2136287 time 3977 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d3 g8f6 c2c3 e7e5 d3c2 f8e7 d2d4 e8g8 d4e5 d7e5 h2h3 f8e8 f1e1 e5g6 b1d2 c8d7
info depth 24 multipv 1 score cp 16 nodes 12704665 nps 2125592 time 5977 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d3 g8f6 c2c3 e7e5 d3c2 f8e7 d2d4 e8g8 h2h3 b7b5 a2a4 c8b7 d4d5 d7b6 c1e3 b6a4 c2a4 b5a4 d1a4
info depth 25 multipv 1 score cp 17 nodes 16224804 nps 2120335 time 7652 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d3 g8f6 c2c3 e7e5 d3c2 f8e7 d2d4 e8g8 h2h3 b7b5 c1e3 e5d4 c3d4 c8b7 b1d2 f8e8 f1e1 d6d5
```

```
Score of ChessDotCpp3.45 vs ChessDotCpp3.44: 179 - 133 - 688  [0.523] 1000
...      ChessDotCpp3.45 playing White: 95 - 62 - 343  [0.533] 500
...      ChessDotCpp3.45 playing Black: 84 - 71 - 345  [0.513] 500
...      White vs Black: 166 - 146 - 688  [0.510] 1000
Elo difference: 16.0 +/- 12.0, LOS: 99.5 %, DrawRatio: 68.8 %

Score of ChessDotCpp3.45 vs weiss2.0: 581 - 126 - 293  [0.728] 1000
...      ChessDotCpp3.45 playing White: 291 - 68 - 142  [0.723] 501
...      ChessDotCpp3.45 playing Black: 290 - 58 - 151  [0.732] 499
...      White vs Black: 349 - 358 - 293  [0.495] 1000
Elo difference: 170.6 +/- 19.2, LOS: 100.0 %, DrawRatio: 29.3 %

Score of ChessDotCpp3.45 vs seer2.5: 44 - 228 - 228  [0.316] 500
...      ChessDotCpp3.45 playing White: 21 - 102 - 125  [0.337] 248
...      ChessDotCpp3.45 playing Black: 23 - 126 - 103  [0.296] 252
...      White vs Black: 147 - 125 - 228  [0.522] 500
Elo difference: -134.1 +/- 22.5, LOS: 0.0 %, DrawRatio: 45.6 %
```

### 3.46

Improve PVS

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 211 nps 211000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 22 nodes 385 nps 385000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 multipv 1 score cp 14 nodes 782 nps 782000 time 1 pv g2g3 g8f6 g1f3 d7d5 f1g2
info depth 6 multipv 1 score cp 24 nodes 1183 nps 591500 time 2 pv g2g3 g8f6 g1f3 g7g6 f1g2 f8g7
info depth 7 multipv 1 score cp 15 nodes 1851 nps 925500 time 2 pv g2g3 g8f6 g1f3 g7g6 f1g2 f8g7 e1g1
info depth 8 multipv 1 score cp 24 nodes 3383 nps 1127666 time 3 pv g2g3 c7c5 g1f3 b8c6 f1g2 g7g6 e1g1 f8g7
info depth 9 multipv 1 score cp 14 nodes 6127 nps 1225400 time 5 pv g2g3 g8f6 g1f3 g7g6 f1g2 f8g7 e1g1 e8g8 f1e1
info depth 10 multipv 1 score cp 17 nodes 15275 nps 1697222 time 9 pv g1f3 g8f6 c2c4 g7g6 g2g3 f8g7 f1g2 c7c5 e1g1 e8g8
info depth 11 multipv 1 score cp 17 nodes 45121 nps 1961782 time 23 pv d2d4 d7d5 g1f3 g8f6 e2e3 e7e6 f1e2 f8e7 e1g1 e8g8 c2c4
info depth 12 multipv 1 score cp 19 nodes 99381 nps 2028183 time 49 pv g1f3 g8f6 c2c4 g7g6 d2d4 f8g7 e2e3 d7d6 f1e2 e8g8 e1g1 c7c5
info depth 13 multipv 1 score cp 33 nodes 229520 nps 2105688 time 109 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 e7g6 d2d4 e5d4 f3d4 f8c5 d4f5
info depth 14 multipv 1 score cp 25 nodes 273857 nps 2106592 time 130 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 d2d4 e5d4 f3d4 e7g6 c1e3 a7a6 b5e2 f8e7
info depth 15 multipv 1 score cp 21 nodes 379433 nps 2107961 time 180 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 f8c5 b5c6 d7c6 d2d3 f6g4 d1e1 e8g8 b1c3
info depth 16 multipv 1 score cp 30 nodes 561621 nps 2119324 time 265 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 b1d2 e4d2 c1d2 b8d7 f1e2 f8e7 e5f3 e8g8
info depth 17 multipv 1 score cp 27 nodes 723383 nps 2140186 time 338 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 f1d3 f8d6 b1d2 e4d2 c1d2 e8g8 e1g1 c7c5 c2c3 d6e5 d4e5
info depth 18 multipv 1 score cp 23 nodes 1352138 nps 2180867 time 620 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 c5d4 c3d4 b8c6 f1d3 d8b6 d2b3 f8e7
info depth 19 multipv 1 score cp 15 nodes 1967291 nps 2198090 time 895 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 f1d3 c5d4 c3d4 d8b6 d2b3 f8b4 c1d2 b4d2 d1d2
info depth 20 multipv 1 score cp 16 nodes 2653986 nps 2211655 time 1200 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 d2b3 d8c7 f1e2 f8e7 b3c5 d7c5 d4c5 e7c5
info depth 21 multipv 1 score cp 21 nodes 3631582 nps 2213029 time 1641 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 e7d6 c1g5 h7h6 g5h4 f8e8
info depth 22 multipv 1 score cp 16 nodes 7719455 nps 2196146 time 3515 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 b1c3 d7d5 c1f4 e8g8 e2e3 b8d7 c4d5 f6d5 c3d5 e6d5 f1e2 a7a5 e1g1 f8e8 d1c2 c7c6
info depth 23 multipv 1 score cp 23 nodes 13579903 nps 2186779 time 6210 pv g1f3 c7c5 e2e4 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 c2c3 e7e6 d2d4 c5d4 c3d4 f8e7 e4e5 f6d5 b1c3 d5c3 b2c3
info depth 24 multipv 1 score cp 23 nodes 16188536 nps 2183214 time 7415 pv g1f3 c7c5 e2e4 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 c2c3 e7e6 d2d4 c5d4 c3d4 f8e7 b1c3 e8g8 e4e5 f6e8 c1e3 a8c8 d1b3 d8c7
info depth 25 multipv 1 score cp 18 nodes 32272072 nps 2166347 time 14897 pv g1f3 c7c5 e2e4 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 e4e5 d6e5 f3e5 e7e6 d2d3 f8e7 d1f3 b7b6 b1c3 e8g8 c3e4 d7e8 c1g5 f6e4 g5e7 d8e7 e1e4
```

```
Score of ChessDotCpp3.46 vs ChessDotCpp3.45: 718 - 618 - 2664  [0.512] 4000
...      ChessDotCpp3.46 playing White: 388 - 293 - 1320  [0.524] 2001
...      ChessDotCpp3.46 playing Black: 330 - 325 - 1344  [0.501] 1999
...      White vs Black: 713 - 623 - 2664  [0.511] 4000
Elo difference: 8.7 +/- 6.2, LOS: 99.7 %, DrawRatio: 66.6 %

Score of ChessDotCpp3.46 vs weiss2.0: 1246 - 241 - 513  [0.751] 2000
...      ChessDotCpp3.46 playing White: 646 - 112 - 242  [0.767] 1000
...      ChessDotCpp3.46 playing Black: 600 - 129 - 271  [0.736] 1000
...      White vs Black: 775 - 712 - 513  [0.516] 2000
Elo difference: 192.0 +/- 14.3, LOS: 100.0 %, DrawRatio: 25.7 %

Score of ChessDotCpp3.46 vs seer2.5: 104 - 429 - 467  [0.338] 1000
...      ChessDotCpp3.46 playing White: 52 - 205 - 243  [0.347] 500
...      ChessDotCpp3.46 playing Black: 52 - 224 - 224  [0.328] 500
...      White vs Black: 276 - 257 - 467  [0.509] 1000
Elo difference: -117.2 +/- 15.7, LOS: 0.0 %, DrawRatio: 46.7 %
```

### 3.47

Improve LMR based on improvement metric

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 264 nps 264000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 28 nodes 471 nps 471000 time 1 pv d2d4 g7g6 g1f3 g8f6
info depth 5 multipv 1 score cp 17 nodes 1103 nps 1103000 time 1 pv g1f3 c7c5 g2g3 g8f6 f1g2
info depth 6 multipv 1 score cp 24 nodes 1814 nps 907000 time 2 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7
info depth 7 multipv 1 score cp 15 nodes 2604 nps 1302000 time 2 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1
info depth 8 multipv 1 score cp 27 nodes 6383 nps 1276600 time 5 pv g2g3 g7g6 f1g2 f8g7 e2e4 c7c5 g1f3 g8f6
info depth 9 multipv 1 score cp 20 nodes 10422 nps 1488857 time 7 pv g2g3 g7g6 f1g2 f8g7 d2d4 g8f6 e2e4 e8g8 g1e2
info depth 10 multipv 1 score cp 28 nodes 32666 nps 1814777 time 18 pv e2e4 e7e5 g1f3 b8c6 f1b5 c6d4 f3d4 e5d4 e1g1 g8f6
info depth 11 multipv 1 score cp 19 nodes 52554 nps 1876928 time 28 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 f1d3 d7d5 b1c3 e4f6 e1g1
info depth 12 multipv 1 score cp 21 nodes 83277 nps 1892659 time 44 pv e2e4 e7e5 g1f3 g8f6 b1c3 b8c6 f1b5 f8b4 b5c6 d7c6 f3e5 b4c3 b2c3 f6e4
info depth 13 multipv 1 score cp 29 nodes 158333 nps 1979162 time 80 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 d5c7 b5c6 d7c6 f1e1
info depth 14 multipv 1 score cp 28 nodes 285719 nps 2026375 time 141 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 c6d4 b5a4 b7b5 c3b5 d4b5 a4b5 f6e4
info depth 15 multipv 1 score cp 32 nodes 567201 nps 2092992 time 271 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 c6d4 b5a4 b7b5 c3b5 d4b5 a4b5 f6e4 e1g1
info depth 16 multipv 1 score cp 29 nodes 988776 nps 2144850 time 461 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 f1b5 c8d7 b5d7 d8d7 e1g1 g8f6 f1e1 b8c6 d2d4 c5d4 f3d4 f8e7 d4c6 b7c6
info depth 17 multipv 1 score cp 27 nodes 1465472 nps 2161463 time 678 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 d1d4 b8c6 f1b5 c8d7 b5c6 d7c6 e1g1 e6e5 d4d2
info depth 18 multipv 1 score cp 19 nodes 3077356 nps 2161064 time 1424 pv g1f3 g8f6 c2c4 g7g6 d2d4 f8g7 b1c3 d7d5 c4d5 f6d5 e2e4 d5c3 b2c3 e8g8 f1e2 c7c5 e1g1 b8c6
info depth 19 multipv 1 score cp 18 nodes 6481554 nps 2175018 time 2980 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 c8g4 f1e1 g8e7 h2h3 g4h5 c2c3 e7g6 d2d4 h5f3 d1f3 e5d4
info depth 20 multipv 1 score cp 21 nodes 8076130 nps 2168088 time 3725 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 f7f6 d2d4 e5d4 f1e1 f8b4 c1d2 b4c5 e4e5 g8e7 e5f6 g7f6
info depth 21 multipv 1 score cp 19 nodes 10745117 nps 2162865 time 4968 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 e1g1 f8e7 d2d4 e8g8 d4e5 f6e4 c2c4 e4c5 a4c2 d7d6 e5d6 e7d6 b1c3
info depth 22 multipv 1 score cp 22 nodes 13445569 nps 2156466 time 6235 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 e1g1 f8e7 d2d4 e8g8 d4e5 f6e4 c2c3 d7d5 e5d6 d8d6 b1d2 e4d2 c1d2 c8f5
info depth 23 multipv 1 score cp 21 nodes 17560215 nps 2148564 time 8173 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 e1g1 f6e4 a4c6 d7c6 f3e5 e4f6 f1e1 f8e7 b1c3 e8g8 d2d4
info depth 24 multipv 1 score cp 19 nodes 28503612 nps 2139268 time 13324 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 g8f6 b1c3 f8d6 d2d3 e8g8 e1g1 b7b5 a4b3 c6a5 c1g5 c8b7 g5h4 a5b3 a2b3 h7h6 f1e1 f8e8
info depth 25 multipv 1 score cp 19 nodes 59543653 nps 2131354 time 27937 pv c2c4 g8f6 g1f3 g7g6 b1c3 c7c5 d2d4 c5d4 f3d4 f8g7 e2e4 b8c6 c1e3 c6d4 e3d4 d7d6 f1e2 e8g8 e1g1 c8d7 d1c2 d7c6 f1d1 f8e8 b2b3
```

```
Score of ChessDotCpp3.47 vs ChessDotCpp3.46: 257 - 232 - 1011  [0.508] 1500
...      ChessDotCpp3.47 playing White: 143 - 109 - 498  [0.523] 750
...      ChessDotCpp3.47 playing Black: 114 - 123 - 513  [0.494] 750
...      White vs Black: 266 - 223 - 1011  [0.514] 1500
Elo difference: 5.8 +/- 10.0, LOS: 87.1 %, DrawRatio: 67.4 %
```

### 3.48

Improve null move depth reduction

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 264 nps 264000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 28 nodes 471 nps 471000 time 1 pv d2d4 g7g6 g1f3 g8f6
info depth 5 multipv 1 score cp 17 nodes 1103 nps 1103000 time 1 pv g1f3 c7c5 g2g3 g8f6 f1g2
info depth 6 multipv 1 score cp 24 nodes 1814 nps 907000 time 2 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7
info depth 7 multipv 1 score cp 15 nodes 2604 nps 1302000 time 2 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1
info depth 8 multipv 1 score cp 27 nodes 6383 nps 1595750 time 4 pv g2g3 g7g6 f1g2 f8g7 e2e4 c7c5 g1f3 g8f6
info depth 9 multipv 1 score cp 20 nodes 10185 nps 1697500 time 6 pv g2g3 g7g6 f1g2 f8g7 d2d4 g8f6 e2e4 e8g8 g1e2
info depth 10 multipv 1 score cp 36 nodes 54324 nps 1940142 time 28 pv e2e4 e7e5 g1f3 g8f6 b1c3 f8b4 f3e5 e8g8 f1e2 b4c3 d2c3 f6e4
info depth 11 multipv 1 score cp 24 nodes 71587 nps 1934783 time 37 pv e2e4 e7e5 g1f3 g8f6 f1e2 f6e4 f3e5 d8f6 e5f3 d7d5 e1g1
info depth 12 multipv 1 score cp 26 nodes 112037 nps 1931672 time 58 pv e2e4 e7e5 b1c3 g8f6 g1f3 b8c6 f1c4 f8c5 e1g1 e8g8 c4b3 g8h8
info depth 13 multipv 1 score cp 21 nodes 390478 nps 2077010 time 188 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 d7d5 f1e2 d5c4 e1g1 e8g8 e2c4
info depth 14 multipv 1 score cp 16 nodes 592740 nps 2109395 time 281 pv d2d4 g8f6 c2c4 e7e6 g1f3 f8e7 e2e3 b7b6 f1e2 e8g8 b1c3 c8b7 e1g1 c7c5 d4c5 e7c5
info depth 15 multipv 1 score cp 23 nodes 1250427 nps 2163368 time 578 pv e2e4 e7e6 g1f3 c7c5 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4c6 b7c6 e4e5 f6d5 c3e4
info depth 16 multipv 1 score cp 29 nodes 1631059 nps 2174745 time 750 pv e2e4 e7e6 g1f3 c7c5 c2c3 g8f6 e4e5 f6d5 f1c4 d5b6 c4e2 d7d6 e1g1 d6e5 f3e5 f8e7
info depth 17 multipv 1 score cp 24 nodes 2155944 nps 2168957 time 994 pv e2e4 e7e6 g1f3 c7c5 c2c3 g8f6 e4e5 f6d5 f1c4 d7d6 d2d4 d6e5 d4e5 f8e7 e1g1 e8g8 f1e1
info depth 18 multipv 1 score cp 21 nodes 4113530 nps 2153680 time 1910 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 e1g1 e8g8 b1c3 h7h6 c3d5 d7d6 d5f6 d8f6 c2c3 f6e7 h2h3
info depth 19 multipv 1 score cp 19 nodes 5618575 nps 2135528 time 2631 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 b1c3 h7h6 e1g1 e8g8 h2h3 a7a6 c3d5 c5a7 c1e3 f6d5 e4d5
info depth 20 multipv 1 score cp 21 nodes 6892380 nps 2133863 time 3230 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 d2d3 f8c5 b1c3 h7h6 e1g1 e8g8 a2a3 a7a6 c4a2 d7d6 c1e3 c8e6 a2e6 f7e6 e3c5 d6c5
info depth 21 multipv 1 score cp 31 nodes 11291032 nps 2127573 time 5307 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 b7b6 b1c3 d5c3 b2c3 d8c7 c1d2 f8e7 f1d3 c8a6 d3a6 b8a6
info depth 22 multipv 1 score cp 26 nodes 14553519 nps 2129263 time 6835 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 f1d3 b8c6 d3c2 f8e7 e1g1 e8g8 f1e1 e6e5 c2a4 d7d6 d2d4 c5d4 c3d4 e5d4 f3d4 c6d4 d1d4
info depth 23 multipv 1 score cp 26 nodes 16661969 nps 2125793 time 7838 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 f1d3 b8c6 d3c2 f8e7 e1g1 e8g8 f1e1 e6e5 c2a4 d7d6 d2d4 c5d4 c3d4 e5d4 f3d4 c6d4 d1d4
info depth 24 multipv 1 score cp 25 nodes 22229700 nps 2123383 time 10469 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 f1d3 b8c6 d3c2 f8e7 e1g1 e8g8 f1e1 e6e5 c2a4 d7d6 d2d4 c5d4 c3d4 e5d4 f3d4 c6d4 d1d4 d6d5
info depth 25 multipv 1 score cp 18 nodes 35836889 nps 2116268 time 16934 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 f1d3 d7d5 e4e5 f6d7 e1g1 b8c6 f1e1 f8e7 d3f1 d5d4 f1b5 e8g8 b5c6 b7c6 d2d3 d4c3 b1c3 c8a6 h2h3
```

```
Score of ChessDotCpp3.48 vs ChessDotCpp3.47: 538 - 482 - 1980  [0.509] 3000
...      ChessDotCpp3.48 playing White: 308 - 221 - 972  [0.529] 1501
...      ChessDotCpp3.48 playing Black: 230 - 261 - 1008  [0.490] 1499
...      White vs Black: 569 - 451 - 1980  [0.520] 3000
Elo difference: 6.5 +/- 7.2, LOS: 96.0 %, DrawRatio: 66.0 %
```

### 3.49

Less LMR on non-PV nodes

```
info depth 1 multipv 1 score cp 17 nodes 23 nps 23000 time 1 pv g1f3
info depth 2 multipv 1 score cp 24 nodes 65 nps 65000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 12 nodes 264 nps 264000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 28 nodes 471 nps 471000 time 1 pv d2d4 g7g6 g1f3 g8f6
info depth 5 multipv 1 score cp 17 nodes 1108 nps 1108000 time 1 pv g1f3 c7c5 g2g3 g8f6 f1g2
info depth 6 multipv 1 score cp 24 nodes 1824 nps 912000 time 2 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7
info depth 7 multipv 1 score cp 15 nodes 2637 nps 1318500 time 2 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1
info depth 8 multipv 1 score cp 26 nodes 7486 nps 1497200 time 5 pv e2e4 c7c5 g1f3 b8c6 f1b5 d8c7 b5c6 c7c6
info depth 9 multipv 1 score cp 21 nodes 13910 nps 1738750 time 8 pv e2e4 e7e5 g1f3 b8c6 f1c4 g8f6 e1g1 f6e4 f1e1
info depth 10 multipv 1 score cp 28 nodes 20454 nps 1704500 time 12 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 c6d4 f3d4 e5d4
info depth 11 multipv 1 score cp 32 nodes 52407 nps 1807137 time 29 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5a4 e7g6 f1e1
info depth 12 multipv 1 score cp 23 nodes 82707 nps 1879704 time 44 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 e1g1 a7a6 b5a4 e7g6 f1e1 f8c5
info depth 13 multipv 1 score cp 28 nodes 146911 nps 1933039 time 76 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 d2d3 c8g4 e1g1 g8f6 f1e1
info depth 14 multipv 1 score cp 28 nodes 364629 nps 2025716 time 180 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 f1b5 c6d4 b5a4 b7b5 c3b5 d4b5 a4b5 f6e4
info depth 15 multipv 1 score cp 21 nodes 705149 nps 2061839 time 342 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 b8c6 b1c3 g8f6 d4c6 b7c6 e4e5 f6d5 c3d5 c6d5
info depth 16 multipv 1 score cp 24 nodes 1033978 nps 2101581 time 492 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 b8c6 b1c3 g8f6 f1e2 f8e7 d4c6 b7c6 e4e5 f6d5 c3d5 c6d5
info depth 17 multipv 1 score cp 25 nodes 1600281 nps 2113977 time 757 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 b8c6 b1c3 g8f6 f1e2 f8b4 d4c6 b7c6 d1d4 d8a5 c1d2
info depth 18 multipv 1 score cp 21 nodes 2963197 nps 2124155 time 1395 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 d4c6 b7c6 f1d3 d7d5 e4d5 c6d5 e1g1 f8e7 c2c4 e8g8 c4d5 f6d5
info depth 19 multipv 1 score cp 27 nodes 3884824 nps 2124015 time 1829 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5a4 b7b5 a4b3 g8f6 e1g1 f8e7 f1e1 e8g8 c2c3 d7d5 e4d5 f6d5 f3e5 c6e5 e1e5
info depth 20 multipv 1 score cp 23 nodes 6830219 nps 2104844 time 3245 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8d6 f1d3 g8e7 e1g1 e8g8 f1e1 c8g4 b1d2 b8d7 c2c4 c7c6
info depth 21 multipv 1 score cp 20 nodes 10467509 nps 2095597 time 4995 pv e2e4 e7e6 d2d4 d7d5 b1d2 g8f6 e4e5 f6d7 c2c3 c7c5 g1f3 b8c6 d2b3 d8c7 f1e2 c5c4 b3d2 f8e7 e1g1 e8g8 f1e1
info depth 22 multipv 1 score cp 22 nodes 16856394 nps 2080265 time 8103 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a1b1 b7b6 a2a3 h7h6 c3d5 d7d6 b2b4 f6d5 c4d5
info depth 23 multipv 1 score cp 22 nodes 20825410 nps 2082541 time 10000 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a1b1 b7b6 a2a3 h7h6 c3d5 d7d6 b2b4 f6d5 c4d5
info depth 24 multipv 1 score cp 18 nodes 42401034 nps 2079399 time 20391 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a1b1 b7b6 a2a3 d7d6 b2b4 c6d4 f3d4 c5d4 c3b5 c8d7
info depth 25 multipv 1 score cp 20 nodes 51216083 nps 2078406 time 24642 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 f3e1 d7d6 e1c2 h7h6 f2f4 c6d4 f4f5 a7a6 c1e3 b7b5 h2h3
```

```
Score of ChessDotCpp3.49 vs ChessDotCpp3.48: 280 - 220 - 1000  [0.520] 1500
...      ChessDotCpp3.49 playing White: 152 - 108 - 489  [0.529] 749
...      ChessDotCpp3.49 playing Black: 128 - 112 - 511  [0.511] 751
...      White vs Black: 264 - 236 - 1000  [0.509] 1500
Elo difference: 13.9 +/- 10.1, LOS: 99.6 %, DrawRatio: 66.7 %

Score of ChessDotCpp3.49 vs weiss2.0: 613 - 114 - 273  [0.750] 1000
...      ChessDotCpp3.49 playing White: 313 - 54 - 133  [0.759] 500
...      ChessDotCpp3.49 playing Black: 300 - 60 - 140  [0.740] 500
...      White vs Black: 373 - 354 - 273  [0.509] 1000
Elo difference: 190.4 +/- 19.8, LOS: 100.0 %, DrawRatio: 27.3 %

Score of ChessDotCpp3.49 vs seer2.5: 108 - 390 - 502  [0.359] 1000
...      ChessDotCpp3.49 playing White: 58 - 194 - 248  [0.364] 500
...      ChessDotCpp3.49 playing Black: 50 - 196 - 254  [0.354] 500
...      White vs Black: 254 - 244 - 502  [0.505] 1000
Elo difference: -100.7 +/- 15.1, LOS: 0.0 %, DrawRatio: 50.2 %
```

Remove condition on root node for LMR

### 3.50

Retrain same NNUE arch on 1B FENs (+350M FENs)

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -586  | -470  | -519  | -990  | -145  | -508  | -475  | -600  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -60  | -123  | -117  | -138  | -141  | -167  | -140  |  -61  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  58   |  120  |  114  |  136  |  135  |  161  |  137  |  63   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  568  |  464  |  512  |  912  |  127  |  499  |  468  |  581  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 22
Phase: 24
```

```
info depth 1 multipv 1 score cp 19 nodes 24 nps 24000 time 1 pv d2d4
info depth 2 multipv 1 score cp 22 nodes 75 nps 75000 time 1 pv g1f3 g8f6
info depth 3 multipv 1 score cp 20 nodes 154 nps 154000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 21 nodes 333 nps 333000 time 1 pv d2d4 c7c5 d4c5 g8f6
info depth 5 multipv 1 score cp 27 nodes 689 nps 689000 time 1 pv d2d4 c7c5 d4c5 d8a5 c1d2 a5c5
info depth 6 multipv 1 score cp 18 nodes 2249 nps 1124500 time 2 pv d2d4 d7d5 g1f3 g8f6 c2c4 d5c4
info depth 7 multipv 1 score cp 17 nodes 5079 nps 1693000 time 3 pv g1f3 g8f6 e2e3 g7g6 f1e2 f8g7 d2d4
info depth 8 multipv 1 score cp 19 nodes 9307 nps 1861400 time 5 pv g1f3 g8f6 e2e3 c7c5 f1e2 e7e6 c2c4 f8e7
info depth 9 multipv 1 score cp 28 nodes 22429 nps 1869083 time 12 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4
info depth 10 multipv 1 score cp 24 nodes 41816 nps 1900727 time 22 pv e2e4 e7e6 d2d4 d7d5 b1c3 f8b4 d1g4 g7g6 e4e5 c7c5 d4c5
info depth 11 multipv 1 score cp 33 nodes 75653 nps 1939820 time 39 pv e2e4 e7e6 f1e2 c7c5 g1f3 b8c6 b1c3 f8e7 d2d4 c5d4 f3d4
info depth 12 multipv 1 score cp 24 nodes 146535 nps 2007328 time 73 pv e2e4 c7c5 g1f3 e7e6 c2c4 b8c6 b1c3 g8f6 d2d4 c5d4 f3d4 f8e7
info depth 13 multipv 1 score cp 20 nodes 256745 nps 2070524 time 124 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1e2 f8e7 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 27 nodes 375881 nps 2111691 time 178 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 b8c6
info depth 15 multipv 1 score cp 16 nodes 638274 nps 2149070 time 297 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c5d4 c3d4 g8e7 g1f3 e7c6 b1c3 f8e7 f1d3
info depth 16 multipv 1 score cp 20 nodes 949677 nps 2158356 time 440 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 g8e7 g1f3 b8c6 f1e2 e7g6 e1g1 f8e7 d4c5 e7c5
info depth 17 multipv 1 score cp 29 nodes 1817393 nps 2150760 time 845 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 g8f6 e1g1 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5
info depth 18 multipv 1 score cp 30 nodes 2474072 nps 2153239 time 1149 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 g8f6 d2d4 c5d4 f3d4 f8b4 d4c6 b7c6 e4e5 f6d5 c1d2 d5c3 b2c3
info depth 19 multipv 1 score cp 21 nodes 3947211 nps 2159305 time 1828 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 f3e5 c8d7 b5c6 b7c6 f1e1 g8f6 d2d4 e8g8
info depth 20 multipv 1 score cp 27 nodes 5281234 nps 2157366 time 2448 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 b8c6 d3b5 g8f6 b5c6 d7c6 d2d3 f6d7 a2a4 b7b6 a4a5 b6b5 c1e3 e8g8
info depth 21 multipv 1 score cp 23 nodes 7220176 nps 2160435 time 3342 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 b8c6 d3b5 g8f6 e4e5 f6d5 b1c3 e8g8 c3d5 e6d5 d2d4 c5d4 f3d4 c6e5 f1e1
info depth 22 multipv 1 score cp 28 nodes 9772331 nps 2148237 time 4549 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 b8c6 f1e1 d7d6 d3f1 g8f6 d2d4 c5d4 f3d4 c6d4 d1d4 e8g8 c2c4 c8d7 d4e3 d8c7
info depth 23 multipv 1 score cp 23 nodes 13506934 nps 2133122 time 6332 pv e2e4 c7c5 g1f3 e7e6 f1d3 g8f6 e4e5 f6d5 e1g1 d7d6 b1c3 d5b4 d3b5 b4c6 e5d6 f8d6 d2d4 c5d4 f3d4 e8g8 d4f3 d6e7 c1f4 a7a6
info depth 24 multipv 1 score cp 17 nodes 22340977 nps 2064976 time 10819 pv e2e4 c7c5 g1f3 e7e6 f1d3 g8f6 e4e5 f6d5 e1g1 d7d6 b1c3 d5b4 d3b5 b4c6 e5d6 f8d6 d2d4 c5d4 f3d4 e8g8 d4f3 h7h6 f1e1 a7a6 b5f1
info depth 25 multipv 1 score cp 21 nodes 31864051 nps 2010984 time 15845 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 f8e7 e1g1 e6e5 c3d5 e8g8 f1e1 d7d6 c2c3 h7h6 d2d4 c5d4 d5e7 d8e7 c3d4 c8e6
```

```
Score of ChessDotCpp3.50 vs ChessDotCpp3.49: 661 - 549 - 1790  [0.519] 3000
...      ChessDotCpp3.50 playing White: 348 - 258 - 894  [0.530] 1500
...      ChessDotCpp3.50 playing Black: 313 - 291 - 896  [0.507] 1500
...      White vs Black: 639 - 571 - 1790  [0.511] 3000
Elo difference: 13.0 +/- 7.9, LOS: 99.9 %, DrawRatio: 59.7 %

Score of ChessDotCpp3.50 vs weiss2.0: 660 - 93 - 247  [0.783] 1000
...      ChessDotCpp3.50 playing White: 347 - 43 - 110  [0.804] 500
...      ChessDotCpp3.50 playing Black: 313 - 50 - 137  [0.763] 500
...      White vs Black: 397 - 356 - 247  [0.520] 1000
Elo difference: 223.4 +/- 20.9, LOS: 100.0 %, DrawRatio: 24.7 %

Score of ChessDotCpp3.50 vs seer2.5: 1176 - 3939 - 4875  [0.362] 9990
...      ChessDotCpp3.50 playing White: 626 - 1866 - 2503  [0.376] 4995
...      ChessDotCpp3.50 playing Black: 550 - 2073 - 2372  [0.348] 4995
...      White vs Black: 2699 - 2416 - 4875  [0.514] 9990
Elo difference: -98.7 +/- 4.9, LOS: 0.0 %, DrawRatio: 48.8 %
Started game 9992 of 10000 (seer2.5 vs ChessDotCpp3.50)
```

### 3.51

NNUE arch with horizontal mirroring based on own king side, 12*64 -> 512 -> 1 with accumulator concatenation, trained on 1B fens

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -603  | -472  | -501  | -1024 | -145  | -508  | -471  | -636  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -82  | -139  | -124  | -155  | -152  | -171  | -152  |  -80  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  81   |  133  |  118  |  152  |  148  |  165  |  149  |  81   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  548  |  461  |  486  |  910  |  123  |  491  |  461  |  585  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 25
Phase: 24
```

```
info depth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 17 nodes 338 nps 338000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 40 nodes 684 nps 684000 time 1 pv e2e4 e7e6 e4e5 f8c5
info depth 5 multipv 1 score cp 21 nodes 1309 nps 1309000 time 1 pv e2e4 e7e6 f1e2 d7d5 e4d5 e6d5
info depth 6 multipv 1 score cp 27 nodes 2485 nps 1242500 time 2 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6
info depth 7 multipv 1 score cp 17 nodes 6147 nps 1536750 time 4 pv c2c4 g8f6 b1c3 e7e6 d2d4 d7d5 c4d5 e6d5
info depth 8 multipv 1 score cp 28 nodes 14594 nps 1824250 time 8 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 f8c5 d4c6 b7c6
info depth 9 multipv 1 score cp 24 nodes 27671 nps 1844733 time 15 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 c6d4 f3d4 c5d4
info depth 10 multipv 1 score cp 28 nodes 40938 nps 1860818 time 22 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7
info depth 11 multipv 1 score cp 28 nodes 69166 nps 1921277 time 36 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 d1e2 c6d4 f3d4 c5d4 e1g1
info depth 12 multipv 1 score cp 31 nodes 104812 nps 1905672 time 55 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 d7c6 d1e2 c8g4 e1g1 e7e6
info depth 13 multipv 1 score cp 24 nodes 190728 nps 1869882 time 102 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 f8b4 e4e5 f6d5 c1d2 d5c3 b2c3
info depth 14 multipv 1 score cp 25 nodes 314691 nps 1895728 time 166 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 multipv 1 score cp 24 nodes 509041 nps 1935517 time 263 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5 c3d5 c6d5
info depth 16 multipv 1 score cp 22 nodes 1334600 nps 2012971 time 663 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 18 nodes 2210925 nps 2028371 time 1090 pv e2e4 e7e6 d2d4 d7d5 b1c3 g8f6 c1g5 d5e4 c3e4 f8e7 e4f6 e7f6 g5f6 d8f6 c2c3 c7c5 d4c5 e8g8
info depth 18 multipv 1 score cp 30 nodes 3164359 nps 2021954 time 1565 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 c1f4 f8e8 b1c3 c7c5 f1e1
info depth 19 multipv 1 score cp 19 nodes 4581996 nps 2013179 time 2276 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 c8d7 c2c4 b8c6
info depth 20 multipv 1 score cp 22 nodes 7736805 nps 1995050 time 3878 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4b5 f8b4 a2a3 b4c3 b5c3 d7d5 e4d5 e6d5 f1e2 e8g8 e1g1
info depth 21 multipv 1 score cp 15 nodes 14306967 nps 1982123 time 7218 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 c8d7 e2d2 h7h6 g5h6 g7h6 d2h6
info depth 22 multipv 1 score cp 15 nodes 20862222 nps 1980653 time 10533 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 c8g4 h2h3 g4h5 b1d2 b8d7 d2f1 h7h6 c2c3 c7c5
info depth 23 multipv 1 score cp 21 nodes 26928781 nps 1976279 time 13626 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8a5 d4c5 a5c5 f1d3 c5c7 f2f4 f8c5 d1g4 g7g6 g4e2 g8e7 g1f3 c8d7 b1d2 c5b6 d2b3
info depth 24 multipv 1 score cp 21 nodes 35891691 nps 1965913 time 18257 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8a5 d4c5 a5c5 f1d3 c5c7 f2f4 a7a6 g1f3 f8c5 d1e2 g8e7 b1d2 c5a7 d2b3 c7b6 c1d2 c8d7
info depth 25 multipv 1 score cp 29 nodes 48969008 nps 1949092 time 25124 pv e2e4 e7e6 d2d4 d7d5 b1d2 f8e7 f1d3 c7c5 d4c5 g8f6 g1f3 d5e4 d2e4 f6e4 d3e4 d8d1 e1d1 e7c5 d1e2 b8c6 h1d1 f7f6 c1e3 c5e3 f2e3 c8d7
```

```
Score of ChessDotCpp3.51 vs ChessDotCpp3.50: 1165 - 1045 - 3290  [0.511] 5500
...      ChessDotCpp3.51 playing White: 617 - 489 - 1644  [0.523] 2750
...      ChessDotCpp3.51 playing Black: 548 - 556 - 1646  [0.499] 2750
...      White vs Black: 1173 - 1037 - 3290  [0.512] 5500
Elo difference: 7.6 +/- 5.8, LOS: 99.5 %, DrawRatio: 59.8 %

Score of ChessDotCpp3.51 vs weiss2.0: 661 - 91 - 248  [0.785] 1000
...      ChessDotCpp3.51 playing White: 332 - 47 - 121  [0.785] 500
...      ChessDotCpp3.51 playing Black: 329 - 44 - 127  [0.785] 500
...      White vs Black: 376 - 376 - 248  [0.500] 1000
Elo difference: 225.0 +/- 20.9, LOS: 100.0 %, DrawRatio: 24.8 %

Score of ChessDotCpp3.51 vs seer2.5: 212 - 587 - 701  [0.375] 1500
...      ChessDotCpp3.51 playing White: 114 - 288 - 349  [0.384] 751
...      ChessDotCpp3.51 playing Black: 98 - 299 - 352  [0.366] 749
...      White vs Black: 413 - 386 - 701  [0.509] 1500
Elo difference: -88.7 +/- 12.8, LOS: 0.0 %, DrawRatio: 46.7 %
```

### 3.52

Allow more time usage

```
Score of ChessDotCpp3.52 vs ChessDotCpp3.51: 273 - 210 - 1017  [0.521] 1500
...      ChessDotCpp3.52 playing White: 145 - 109 - 496  [0.524] 750
...      ChessDotCpp3.52 playing Black: 128 - 101 - 521  [0.518] 750
...      White vs Black: 246 - 237 - 1017  [0.503] 1500
Elo difference: 14.6 +/- 10.0, LOS: 99.8 %, DrawRatio: 67.8 %

60+0.6
Score of ChessDotCpp3.52 vs ChessDotCpp3.51: 15 - 10 - 75  [0.525] 100
...      ChessDotCpp3.52 playing White: 8 - 6 - 37  [0.520] 51
...      ChessDotCpp3.52 playing Black: 7 - 4 - 38  [0.531] 49
...      White vs Black: 12 - 13 - 75  [0.495] 100
Elo difference: 17.4 +/- 34.0, LOS: 84.1 %, DrawRatio: 75.0 %

Score of ChessDotCpp3.52 vs ChessDotCppOld2: 2439 - 800 - 3761  [0.617] 7000
...      ChessDotCpp3.52 playing White: 1240 - 376 - 1885  [0.623] 3501
...      ChessDotCpp3.52 playing Black: 1199 - 424 - 1876  [0.611] 3499
...      White vs Black: 1664 - 1575 - 3761  [0.506] 7000
Elo difference: 82.9 +/- 5.5, LOS: 100.0 %, DrawRatio: 53.7 %

Score of ChessDotCpp3.52 vs weiss2.0: 5320 - 721 - 1959  [0.787] 8000
...      ChessDotCpp3.52 playing White: 2694 - 361 - 946  [0.792] 4001
...      ChessDotCpp3.52 playing Black: 2626 - 360 - 1013  [0.783] 3999
...      White vs Black: 3054 - 2987 - 1959  [0.504] 8000
Elo difference: 227.5 +/- 7.4, LOS: 100.0 %, DrawRatio: 24.5 %

Score of ChessDotCpp3.52 vs seer2.5: 1306 - 3652 - 5042  [0.383] 10000
...      ChessDotCpp3.52 playing White: 688 - 1750 - 2562  [0.394] 5000
...      ChessDotCpp3.52 playing Black: 618 - 1902 - 2480  [0.372] 5000
...      White vs Black: 2590 - 2368 - 5042  [0.511] 10000
Elo difference: -83.1 +/- 4.8, LOS: 0.0 %, DrawRatio: 50.4 %
```

### 3.53

Fail-hard on static eval pruning

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -603  | -472  | -501  | -1024 | -145  | -508  | -471  | -636  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -82  | -139  | -124  | -155  | -152  | -171  | -152  |  -80  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  81   |  133  |  118  |  152  |  148  |  165  |  149  |  81   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  548  |  461  |  486  |  910  |  123  |  491  |  461  |  585  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 25
Phase: 24
```

```
info depth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 17 nodes 338 nps 338000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 40 nodes 683 nps 683000 time 1 pv e2e4 e7e6 e4e5 f8c5
info depth 5 multipv 1 score cp 15 nodes 1399 nps 1399000 time 1 pv e2e4 e7e6 f1e2 d8g5 e2f1
info depth 6 multipv 1 score cp 27 nodes 2608 nps 1304000 time 2 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6
info depth 7 multipv 1 score cp 22 nodes 4949 nps 1649666 time 3 pv e2e4 e7e6 f1e2 d7d5 e4d5 e6d5 g1f3
info depth 8 multipv 1 score cp 28 nodes 8118 nps 1623600 time 5 pv e2e4 e7e6 g1f3 f8e7 d2d4 d7d5 e4d5 e6d5
info depth 9 multipv 1 score cp 26 nodes 13409 nps 1676125 time 8 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1
info depth 10 multipv 1 score cp 21 nodes 25563 nps 1825928 time 14 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 11 multipv 1 score cp 21 nodes 42374 nps 1842347 time 23 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 12 multipv 1 score cp 27 nodes 79988 nps 1817909 time 44 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 16 nodes 208217 nps 1842628 time 113 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 18 nodes 357990 nps 1864531 time 192 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 f1e1
info depth 15 multipv 1 score cp 18 nodes 707598 nps 1881909 time 376 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 f8e8 b1c3 d5c4 e2c4
info depth 16 multipv 1 score cp 22 nodes 1074541 nps 1891797 time 568 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 19 nodes 1970962 nps 1895155 time 1040 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 c8e6 c2c4 e8g8 c4c5 d6e7 e1g1 b8c6
info depth 18 multipv 1 score cp 27 nodes 2987670 nps 1895729 time 1576 pv e2e4 e7e6 g1f3 c7c5 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 f3e1 e8g8 e1c2 d7d6 d2d3 c8e6
info depth 19 multipv 1 score cp 22 nodes 4486142 nps 1894485 time 2368 pv e2e4 e7e6 g1f3 c7c5 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 d2d4 g8f6 e1g1 f8d6 d4c5 d6c5 b1d2 e8g8 d2b3
info depth 20 multipv 1 score cp 24 nodes 6300517 nps 1893753 time 3327 pv e2e4 e7e6 g1f3 c7c5 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4b5 f8b4 a2a3 b4c3 b5c3 e8g8 f1d3 d7d5 e1g1 f8e8 f1e1
info depth 21 multipv 1 score cp 22 nodes 8709617 nps 1917995 time 4541 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 f8e8 b1d2 c7c5 c2c4 b8c6 c4d5 c6d4 f3d4 c5d4
info depth 22 multipv 1 score cp 25 nodes 14703468 nps 1940539 time 7577 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 a2a3 e8g8 a1b1 b7b6 d2d3 a8b8 f3e1 a7a6 e1c2 c6d4 c2d4 c5d4
info depth 23 multipv 1 score cp 22 nodes 20109284 nps 1957298 time 10274 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 a2a3 e8g8 a1b1 b7b6 d2d3 d7d6 h2h3 c8e6 c3d5 h7h6 c1d2
info depth 24 multipv 1 score cp 20 nodes 35766247 nps 1962052 time 18229 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 a2a3 e8g8 a1b1 b7b6 d2d3 d7d6 h2h3 h7h6 b2b4 c6d4 f3d4 c5d4
info depth 25 multipv 1 score cp 18 nodes 60784771 nps 1964347 time 30944 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a1b1 d7d6 f3e1 c6d4 e1c2 a7a6 a2a4 c8d7 b2b4 c5b4 b1b4 d4e2 d1e2
```

```
Score of ChessDotCpp3.53 vs ChessDotCpp3.52: 606 - 538 - 2356  [0.510] 3500
...      ChessDotCpp3.53 playing White: 316 - 260 - 1175  [0.516] 1751
...      ChessDotCpp3.53 playing Black: 290 - 278 - 1181  [0.503] 1749
...      White vs Black: 594 - 550 - 2356  [0.506] 3500
Elo difference: 6.8 +/- 6.6, LOS: 97.8 %, DrawRatio: 67.3 %
```

### 3.54

Improved static eval pruning to prune at depth < 6

```
info depth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 17 nodes 338 nps 338000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 40 nodes 683 nps 683000 time 1 pv e2e4 e7e6 e4e5 f8c5
info depth 5 multipv 1 score cp 15 nodes 1399 nps 1399000 time 1 pv e2e4 e7e6 f1e2 d8g5 e2f1
info depth 6 multipv 1 score cp 27 nodes 2608 nps 1304000 time 2 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6
info depth 7 multipv 1 score cp 22 nodes 4949 nps 1237250 time 4 pv e2e4 e7e6 f1e2 d7d5 e4d5 e6d5 g1f3
info depth 8 multipv 1 score cp 28 nodes 8118 nps 1623600 time 5 pv e2e4 e7e6 g1f3 f8e7 d2d4 d7d5 e4d5 e6d5
info depth 9 multipv 1 score cp 26 nodes 13412 nps 1676500 time 8 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1
info depth 10 multipv 1 score cp 21 nodes 25570 nps 1704666 time 15 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 11 multipv 1 score cp 21 nodes 42385 nps 1766041 time 24 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 12 multipv 1 score cp 27 nodes 80032 nps 1818909 time 44 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 16 nodes 208431 nps 1877756 time 111 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1
info depth 14 multipv 1 score cp 18 nodes 358399 nps 1896291 time 189 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 d8e7 c1e3 g8f6 e1g1 e8g8 f1e1
info depth 15 multipv 1 score cp 18 nodes 701460 nps 1916557 time 366 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 f8e8 b1c3 d5c4 e2c4
info depth 16 multipv 1 score cp 22 nodes 1113614 nps 1916719 time 581 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 e2e3 e8g8 f1e2 d7d5 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 25 nodes 1923013 nps 1915351 time 1004 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 b1d2 c7c5 d4c5 d6c5
info depth 18 multipv 1 score cp 28 nodes 2805027 nps 1923886 time 1458 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 b1d2 b8d7 c2c4 c7c6
info depth 19 multipv 1 score cp 27 nodes 4093750 nps 1899651 time 2155 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 h2h3 b8d7 f1e1 e8e1 d1e1 c7c6
info depth 20 multipv 1 score cp 21 nodes 5834417 nps 1908543 time 3057 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 b8d7 b1d2 h7h6 g5h4 f8e8 c2c4 c7c6
info depth 21 multipv 1 score cp 18 nodes 12181851 nps 1901631 time 6406 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 b8d7 b1d2 h7h6 g5h4 f8e8 h2h3 c7c5 c2c4
info depth 22 multipv 1 score cp 22 nodes 14040369 nps 1902746 time 7379 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 c7c5 c4d5 c5d4
info depth 23 multipv 1 score cp 18 nodes 20030841 nps 1924746 time 10407 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 b1d2 h7h6 g5h4 b8d7 c2c4 c7c5 c4d5 d8b6 d4c5 d7c5
info depth 24 multipv 1 score cp 19 nodes 29361166 nps 1947414 time 15077 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 g2g3 e8g8 f1g2 d7d5 e1g1 c7c6 b1c3 b8d7 b2b3 b7b6 d1d3 h7h6 f1d1 c8a6 e2e4 d5c4 b3c4 c6c5
info depth 25 multipv 1 score cp 23 nodes 45272657 nps 1957736 time 23125 pv g1f3 g8f6 d2d4 e7e6 c2c4 f8e7 g2g3 e8g8 f1g2 d7d5 e1g1 c7c6 b1c3 b8d7 b2b3 b7b6 d1d3 d5c4 b3c4 c8a6 f1d1 f6d5 a2a3 d5c3 d3c3
```

```
Score of ChessDotCpp3.54 vs ChessDotCpp3.53: 687 - 628 - 2685  [0.507] 4000
...      ChessDotCpp3.54 playing White: 359 - 308 - 1334  [0.513] 2001
...      ChessDotCpp3.54 playing Black: 328 - 320 - 1351  [0.502] 1999
...      White vs Black: 679 - 636 - 2685  [0.505] 4000
Elo difference: 5.1 +/- 6.2, LOS: 94.8 %, DrawRatio: 67.1 %

Score of ChessDotCpp3.54 vs weiss2.0: 644 - 97 - 259  [0.773] 1000
...      ChessDotCpp3.54 playing White: 346 - 46 - 109  [0.799] 501
...      ChessDotCpp3.54 playing Black: 298 - 51 - 150  [0.747] 499
...      White vs Black: 397 - 344 - 259  [0.526] 1000
Elo difference: 213.4 +/- 20.4, LOS: 100.0 %, DrawRatio: 25.9 %

Score of ChessDotCpp3.54 vs seer2.5: 163 - 353 - 484  [0.405] 1000
...      ChessDotCpp3.54 playing White: 92 - 170 - 237  [0.422] 499
...      ChessDotCpp3.54 playing Black: 71 - 183 - 247  [0.388] 501
...      White vs Black: 275 - 241 - 484  [0.517] 1000
Elo difference: -66.8 +/- 15.5, LOS: 0.0 %, DrawRatio: 48.4 %
```

### 3.55

Tune history gravity

```
info depth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 17 nodes 338 nps 338000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 40 nodes 683 nps 683000 time 1 pv e2e4 e7e6 e4e5 f8c5
info depth 5 multipv 1 score cp 15 nodes 1399 nps 1399000 time 1 pv e2e4 e7e6 f1e2 d8g5 e2f1
info depth 6 multipv 1 score cp 27 nodes 2600 nps 1300000 time 2 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6
info depth 7 multipv 1 score cp 22 nodes 4945 nps 1236250 time 4 pv e2e4 e7e6 f1e2 d7d5 e4d5 e6d5 g1f3
info depth 8 multipv 1 score cp 28 nodes 8219 nps 1369833 time 6 pv e2e4 e7e6 g1f3 f8e7 d2d4 d7d5 e4d5 e6d5
info depth 9 multipv 1 score cp 26 nodes 13368 nps 1485333 time 9 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1
info depth 10 multipv 1 score cp 21 nodes 25810 nps 1613125 time 16 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 11 multipv 1 score cp 21 nodes 41654 nps 1735583 time 24 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 12 multipv 1 score cp 27 nodes 73423 nps 1748166 time 42 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 25 nodes 133524 nps 1829095 time 73 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1b5 g8e7 e1g1 e7g6 d2d4 c5d4 f3d4
info depth 14 multipv 1 score cp 25 nodes 228143 nps 1870024 time 122 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 multipv 1 score cp 19 nodes 701806 nps 1901913 time 369 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 f8e8 d1c2 d5c4 e2c4
info depth 16 multipv 1 score cp 22 nodes 1096656 nps 1913884 time 573 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 25 nodes 2165997 nps 1908367 time 1135 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 b1d2 c7c5 d4c5 d6c5
info depth 18 multipv 1 score cp 31 nodes 2949953 nps 1900742 time 1552 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1 b8d7 c2c4 d5c4 d3c4 c7c6
info depth 19 multipv 1 score cp 27 nodes 4480161 nps 1900789 time 2357 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 h2h3 e7d6 c1g5 f8e8
info depth 20 multipv 1 score cp 17 nodes 6334118 nps 1886838 time 3357 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 c7c6 c4d5 c6d5
info depth 21 multipv 1 score cp 20 nodes 8287727 nps 1881436 time 4405 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 d7b6 f1e1 d5c4 d2c4 b6c4 d3c4
info depth 22 multipv 1 score cp 21 nodes 11413690 nps 1916334 time 5956 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 h7h6 h2h3 e7d6 e2c2 f8e8 e1e8 d8e8
info depth 23 multipv 1 score cp 21 nodes 14649312 nps 1932371 time 7581 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 e7d6 c1g5 c8g4 b1d2 g4h5 g5h4 f8e8
info depth 24 multipv 1 score cp 21 nodes 34223156 nps 1952262 time 17530 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 d5c4 c2c4 c7c5 d4c5 d7c5 f1d1 d8b6 b1c3 c8d7 f3e5 b6b2
info depth 25 multipv 1 score cp 23 nodes 44441118 nps 1959744 time 22677 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 h7h6 f1d1 c7c6 d2f4 d5c4 c2c4 d8b6 c4c2 f6d5 f4d2 a7a5
```

```
Score of ChessDotCpp3.55 vs ChessDotCpp3.54: 483 - 412 - 1615  [0.514] 2510
...      ChessDotCpp3.55 playing White: 253 - 180 - 821  [0.529] 1254
...      ChessDotCpp3.55 playing Black: 230 - 232 - 794  [0.499] 1256
...      White vs Black: 485 - 410 - 1615  [0.515] 2510
Elo difference: 9.8 +/- 8.1, LOS: 99.1 %, DrawRatio: 64.3 %

Score of ChessDotCpp3.55 vs seer2.5: 134 - 353 - 513  [0.391] 1000
...      ChessDotCpp3.55 playing White: 78 - 176 - 247  [0.402] 501
...      ChessDotCpp3.55 playing Black: 56 - 177 - 266  [0.379] 499
...      White vs Black: 255 - 232 - 513  [0.511] 1000
Elo difference: -77.3 +/- 15.0, LOS: 0.0 %, DrawRatio: 51.3 %
```

### 3.56

Staged movegen for qsearch

```
info depth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 17 nodes 338 nps 338000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 40 nodes 683 nps 683000 time 1 pv e2e4 e7e6 e4e5 f8c5
info depth 5 multipv 1 score cp 15 nodes 1399 nps 1399000 time 1 pv e2e4 e7e6 f1e2 d8g5 e2f1
info depth 6 multipv 1 score cp 27 nodes 2600 nps 1300000 time 2 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6
info depth 7 multipv 1 score cp 22 nodes 4945 nps 1236250 time 4 pv e2e4 e7e6 f1e2 d7d5 e4d5 e6d5 g1f3
info depth 8 multipv 1 score cp 28 nodes 8219 nps 1369833 time 6 pv e2e4 e7e6 g1f3 f8e7 d2d4 d7d5 e4d5 e6d5
info depth 9 multipv 1 score cp 26 nodes 13368 nps 1485333 time 9 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1
info depth 10 multipv 1 score cp 21 nodes 25810 nps 1518235 time 17 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 11 multipv 1 score cp 21 nodes 41654 nps 1602076 time 26 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 12 multipv 1 score cp 27 nodes 73423 nps 1668704 time 44 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 25 nodes 133524 nps 1756894 time 76 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1b5 g8e7 e1g1 e7g6 d2d4 c5d4 f3d4
info depth 14 multipv 1 score cp 25 nodes 228143 nps 1825144 time 125 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 multipv 1 score cp 19 nodes 701806 nps 1886575 time 372 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 f8e8 d1c2 d5c4 e2c4
info depth 16 multipv 1 score cp 22 nodes 1096656 nps 1874625 time 585 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 25 nodes 2165997 nps 1881839 time 1151 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 b1d2 c7c5 d4c5 d6c5
info depth 18 multipv 1 score cp 31 nodes 2949953 nps 1878950 time 1570 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1 b8d7 c2c4 d5c4 d3c4 c7c6
info depth 19 multipv 1 score cp 27 nodes 4480161 nps 1850541 time 2421 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 h2h3 e7d6 c1g5 f8e8
info depth 20 multipv 1 score cp 17 nodes 6334118 nps 1858602 time 3408 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 c7c6 c4d5 c6d5
info depth 21 multipv 1 score cp 20 nodes 8287727 nps 1869552 time 4433 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 d7b6 f1e1 d5c4 d2c4 b6c4 d3c4
info depth 22 multipv 1 score cp 21 nodes 11413690 nps 1906412 time 5987 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 h7h6 h2h3 e7d6 e2c2 f8e8 e1e8 d8e8
info depth 23 multipv 1 score cp 21 nodes 14649312 nps 1929826 time 7591 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 e7d6 c1g5 c8g4 b1d2 g4h5 g5h4 f8e8
info depth 24 multipv 1 score cp 21 nodes 34223156 nps 1949370 time 17556 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 d5c4 c2c4 c7c5 d4c5 d7c5 f1d1 d8b6 b1c3 c8d7 f3e5 b6b2
info depth 25 multipv 1 score cp 23 nodes 44441118 nps 1961127 time 22661 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 h7h6 f1d1 c7c6 d2f4 d5c4 c2c4 d8b6 c4c2 f6d5 f4d2 a7a5
```

```
Score of ChessDotCpp3.56 vs ChessDotCpp3.55: 429 - 401 - 1670  [0.506] 2500
...      ChessDotCpp3.56 playing White: 225 - 198 - 828  [0.511] 1251
...      ChessDotCpp3.56 playing Black: 204 - 203 - 842  [0.500] 1249
...      White vs Black: 428 - 402 - 1670  [0.505] 2500
Elo difference: 3.9 +/- 7.8, LOS: 83.4 %, DrawRatio: 66.8 %
```

### 3.57

Fix warnings, remove unused code

```
info depth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 multipv 1 score cp 17 nodes 338 nps 338000 time 1 pv d2d4 g8f6 g1f3
info depth 4 multipv 1 score cp 40 nodes 683 nps 683000 time 1 pv e2e4 e7e6 e4e5 f8c5
info depth 5 multipv 1 score cp 15 nodes 1399 nps 1399000 time 1 pv e2e4 e7e6 f1e2 d8g5 e2f1
info depth 6 multipv 1 score cp 27 nodes 2600 nps 1300000 time 2 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6
info depth 7 multipv 1 score cp 22 nodes 4945 nps 1236250 time 4 pv e2e4 e7e6 f1e2 d7d5 e4d5 e6d5 g1f3
info depth 8 multipv 1 score cp 28 nodes 8219 nps 1369833 time 6 pv e2e4 e7e6 g1f3 f8e7 d2d4 d7d5 e4d5 e6d5
info depth 9 multipv 1 score cp 26 nodes 13368 nps 1485333 time 9 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1
info depth 10 multipv 1 score cp 21 nodes 25810 nps 1720666 time 15 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 11 multipv 1 score cp 21 nodes 41654 nps 1735583 time 24 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 12 multipv 1 score cp 27 nodes 73423 nps 1790804 time 41 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 multipv 1 score cp 25 nodes 133524 nps 1880619 time 71 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1b5 g8e7 e1g1 e7g6 d2d4 c5d4 f3d4
info depth 14 multipv 1 score cp 25 nodes 228143 nps 1901191 time 120 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 multipv 1 score cp 19 nodes 701806 nps 1901913 time 369 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 f8e8 d1c2 d5c4 e2c4
info depth 16 multipv 1 score cp 22 nodes 1096656 nps 1917230 time 572 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 multipv 1 score cp 25 nodes 2165997 nps 1944342 time 1114 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 b1d2 c7c5 d4c5 d6c5
info depth 18 multipv 1 score cp 31 nodes 2949953 nps 1936935 time 1523 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1 b8d7 c2c4 d5c4 d3c4 c7c6
info depth 19 multipv 1 score cp 27 nodes 4480161 nps 1922815 time 2330 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 h2h3 e7d6 c1g5 f8e8
info depth 20 multipv 1 score cp 17 nodes 6334118 nps 1931133 time 3280 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 c7c6 c4d5 c6d5
info depth 21 multipv 1 score cp 20 nodes 8287727 nps 1940011 time 4272 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 d7b6 f1e1 d5c4 d2c4 b6c4 d3c4
info depth 22 multipv 1 score cp 21 nodes 11413690 nps 1943086 time 5874 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 h7h6 h2h3 e7d6 e2c2 f8e8 e1e8 d8e8
info depth 23 multipv 1 score cp 21 nodes 14649312 nps 1928048 time 7598 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 e7d6 c1g5 c8g4 b1d2 g4h5 g5h4 f8e8
info depth 24 multipv 1 score cp 21 nodes 34223156 nps 1916512 time 17857 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 d5c4 c2c4 c7c5 d4c5 d7c5 f1d1 d8b6 b1c3 c8d7 f3e5 b6b2
info depth 25 multipv 1 score cp 23 nodes 44441118 nps 1920449 time 23141 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 h7h6 f1d1 c7c6 d2f4 d5c4 c2c4 d8b6 c4c2 f6d5 f4d2 a7a5
```

```
Using chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   135
Best mates:    18

Using chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   142
Best mates:    62

Using chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   515
Best mates:    160

Using chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1437
Best mates:    379
```

```
Score of ChessDotCpp3.57 vs ChessDotCpp3.56: 510 - 519 - 1971  [0.498] 3000
...      ChessDotCpp3.57 playing White: 286 - 253 - 961  [0.511] 1500
...      ChessDotCpp3.57 playing Black: 224 - 266 - 1010  [0.486] 1500
...      White vs Black: 552 - 477 - 1971  [0.512] 3000
Elo difference: -1.0 +/- 7.3, LOS: 39.0 %, DrawRatio: 65.7 %

Score of ChessDotCpp3.57 vs igel3.1.0: 270 - 154 - 576  [0.558] 1000
...      ChessDotCpp3.57 playing White: 129 - 66 - 304  [0.563] 499
...      ChessDotCpp3.57 playing Black: 141 - 88 - 272  [0.553] 501
...      White vs Black: 217 - 207 - 576  [0.505] 1000
Elo difference: 40.5 +/- 14.0, LOS: 100.0 %, DrawRatio: 57.6 %

Score of ChessDotCpp3.57 vs berserk9: 5 - 377 - 118  [0.128] 500
...      ChessDotCpp3.57 playing White: 2 - 187 - 62  [0.131] 251
...      ChessDotCpp3.57 playing Black: 3 - 190 - 56  [0.124] 249
...      White vs Black: 192 - 190 - 118  [0.502] 500
Elo difference: -333.3 +/- 31.5, LOS: 0.0 %, DrawRatio: 23.6 %
```

### 3.58

Fix bug with mate distance, implement mate distance and seldepth in UCI

```
info depth 1 seldepth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 17 nodes 338 nps 338000 time 1 pv d2d4 g8f6 g1f3
info depth 4 seldepth 7 multipv 1 score cp 40 nodes 683 nps 683000 time 1 pv e2e4 e7e6 e4e5 f8c5
info depth 5 seldepth 9 multipv 1 score cp 15 nodes 1399 nps 1399000 time 1 pv e2e4 e7e6 f1e2 d8g5 e2f1
info depth 6 seldepth 10 multipv 1 score cp 27 nodes 2600 nps 1300000 time 2 pv e2e4 c7c5 g1f3 e7e6 f1e2 g8f6
info depth 7 seldepth 14 multipv 1 score cp 22 nodes 4945 nps 1648333 time 3 pv e2e4 e7e6 f1e2 d7d5 e4d5 e6d5 g1f3
info depth 8 seldepth 14 multipv 1 score cp 28 nodes 8219 nps 1643800 time 5 pv e2e4 e7e6 g1f3 f8e7 d2d4 d7d5 e4d5 e6d5
info depth 9 seldepth 16 multipv 1 score cp 26 nodes 13368 nps 1671000 time 8 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1
info depth 10 seldepth 15 multipv 1 score cp 21 nodes 25810 nps 1843571 time 14 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 11 seldepth 16 multipv 1 score cp 21 nodes 41654 nps 1811043 time 23 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 d7d5 e4d5 f6d5 c3d5 d8d5
info depth 12 seldepth 19 multipv 1 score cp 27 nodes 73423 nps 1835575 time 40 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1e2 f8e7 e1g1 d7d5 e4d5 e6d5
info depth 13 seldepth 21 multipv 1 score cp 25 nodes 133524 nps 1880619 time 71 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 f1b5 g8e7 e1g1 e7g6 d2d4 c5d4 f3d4
info depth 14 seldepth 22 multipv 1 score cp 25 nodes 228143 nps 1933415 time 118 pv e2e4 c7c5 g1f3 b8c6 b1c3 e7e6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 seldepth 23 multipv 1 score cp 19 nodes 701806 nps 1971365 time 356 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 f8e8 d1c2 d5c4 e2c4
info depth 16 seldepth 23 multipv 1 score cp 22 nodes 1096656 nps 1990301 time 551 pv d2d4 e7e6 c2c4 g8f6 g1f3 d7d5 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 seldepth 27 multipv 1 score cp 25 nodes 2165997 nps 1987153 time 1090 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 f8e8 b1d2 c7c5 d4c5 d6c5
info depth 18 seldepth 28 multipv 1 score cp 31 nodes 2949953 nps 1986500 time 1485 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1 b8d7 c2c4 d5c4 d3c4 c7c6
info depth 19 seldepth 28 multipv 1 score cp 27 nodes 4480161 nps 1974509 time 2269 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 h2h3 e7d6 c1g5 f8e8
info depth 20 seldepth 29 multipv 1 score cp 17 nodes 6334118 nps 1970176 time 3215 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 c7c6 c4d5 c6d5
info depth 21 seldepth 30 multipv 1 score cp 20 nodes 8287727 nps 1970453 time 4206 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 c8g4 b1d2 b8d7 c2c4 h7h6 g5h4 d7b6 f1e1 d5c4 d2c4 b6c4 d3c4
info depth 22 seldepth 32 multipv 1 score cp 21 nodes 11413690 nps 1965843 time 5806 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 h7h6 h2h3 e7d6 e2c2 f8e8 e1e8 d8e8
info depth 23 seldepth 32 multipv 1 score cp 21 nodes 14649312 nps 1962925 time 7463 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 e7d6 c1g5 c8g4 b1d2 g4h5 g5h4 f8e8
info depth 24 seldepth 36 multipv 1 score cp 21 nodes 34223156 nps 1932528 time 17709 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 d5c4 c2c4 c7c5 d4c5 d7c5 f1d1 d8b6 b1c3 c8d7 f3e5 b6b2
info depth 25 seldepth 38 multipv 1 score cp 23 nodes 44441118 nps 1930376 time 23022 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 d1c2 b8d7 e1g1 h7h6 f1d1 c7c6 d2f4 d5c4 c2c4 d8b6 c4c2 f6d5 f4d2 a7a5
```

```
Using chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   123
Best mates:    24

Using chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   127
Best mates:    85

Using chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   453
Best mates:    326

Using chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1270
Best mates:    901
```

```
Score of ChessDotCpp3.58 vs ChessDotCpp3.57: 353 - 364 - 1283  [0.497] 2000
...      ChessDotCpp3.58 playing White: 177 - 182 - 641  [0.497] 1000
...      ChessDotCpp3.58 playing Black: 176 - 182 - 642  [0.497] 1000
...      White vs Black: 359 - 358 - 1283  [0.500] 2000
Elo difference: -1.9 +/- 9.1, LOS: 34.1 %, DrawRatio: 64.1 %
```

### 3.59

Simplify LMR

```
info depth 1 seldepth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 17 nodes 283 nps 283000 time 1 pv d2d4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 22 nodes 393 nps 393000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 seldepth 8 multipv 1 score cp 18 nodes 787 nps 787000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 24 nodes 1478 nps 739000 time 2 pv g2g3 e7e6 g1f3 f8e7 f1g2 g8f6
info depth 7 seldepth 8 multipv 1 score cp 20 nodes 2390 nps 1195000 time 2 pv g2g3 e7e6 g1f3 f8e7 f1g2 g8f6 c2c4
info depth 8 seldepth 12 multipv 1 score cp 22 nodes 6967 nps 1393400 time 5 pv g1f3 e7e6 g2g3 f8e7 f1g2 c7c5 e1g1 g8f6
info depth 9 seldepth 17 multipv 1 score cp 25 nodes 26844 nps 1677750 time 16 pv e2e4 e7e6 g1f3 c7c5 f1e2 b8c6 e1g1 g8f6 e4e5
info depth 10 seldepth 18 multipv 1 score cp 28 nodes 38505 nps 1674130 time 23 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7
info depth 11 seldepth 18 multipv 1 score cp 27 nodes 72830 nps 1776341 time 41 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 d5c7 b5c6 d7c6
info depth 12 seldepth 19 multipv 1 score cp 27 nodes 130329 nps 1810125 time 72 pv e2e4 e7e5 g1f3 b8c6 b1c3 f8c5 f1c4 g8f6 e1g1 e8g8 c4b3 f8e8
info depth 13 seldepth 20 multipv 1 score cp 30 nodes 249118 nps 1873067 time 133 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 f8c5 d4c6 b7c6 f1e2 g8f6 b1c3
info depth 14 seldepth 21 multipv 1 score cp 33 nodes 439910 nps 1904372 time 231 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8e7 f1e2 e8g8 e1g1 c6d4 d1d4
info depth 15 seldepth 24 multipv 1 score cp 20 nodes 773666 nps 1868758 time 414 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6 b1c3 f8b4 d4c6 b7c6 d1d4 d8e7 f1e2
info depth 16 seldepth 26 multipv 1 score cp 26 nodes 1484702 nps 1851249 time 802 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 c1f4 e8g8 e1g1 c8g4 f1e1
info depth 17 seldepth 25 multipv 1 score cp 25 nodes 2132340 nps 1883692 time 1132 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 c7c5 e1g1 c5c4 f1e1 f8e7 d3f1 e8g8 h2h3 f8e8
info depth 18 seldepth 27 multipv 1 score cp 27 nodes 3523426 nps 1913865 time 1841 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 f8e7 d2d4 c5d4 c3d4 d7d6 e5d6 d8d6
info depth 19 seldepth 29 multipv 1 score cp 28 nodes 5302657 nps 1906059 time 2782 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 f8e7 d2d4 c5d4 c3d4 e8g8 b1c3 d5c3 b2c3
info depth 20 seldepth 30 multipv 1 score cp 22 nodes 7690639 nps 1916909 time 4012 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4 d7d6 f1e1 c6d4 d1d4 d8c7
info depth 21 seldepth 29 multipv 1 score cp 18 nodes 11571642 nps 1919330 time 6029 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4 d7d6 f1e1 c6d4 d1d4 d8c7 c1e3
info depth 22 seldepth 32 multipv 1 score cp 20 nodes 17086991 nps 1916871 time 8914 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4 d7d6 h2h3 c6d4 d1d4 c8d7 d4d3 d7c6
info depth 23 seldepth 32 multipv 1 score cp 19 nodes 27255229 nps 1911038 time 14262 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4 d7d6 f1e1 h7h6 d4c6 b7c6 c3a4 e6e5 c2c4
info depth 24 seldepth 36 multipv 1 score cp 23 nodes 40237685 nps 1902670 time 21148 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4 d7d6 f1e1 c6d4 d1d4 f8e8 e4e5 d6e5 d4e5 a7a6
info depth 25 seldepth 35 multipv 1 score cp 21 nodes 60327549 nps 1900319 time 31746 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4 d7d6 d4c6 b7c6 e4e5 d6e5 g2c6 c8a6 f1e1 d8d1 e1d1
```

```
Score of ChessDotCpp3.59 vs ChessDotCpp3.58: 182 - 146 - 672  [0.518] 1000
...      ChessDotCpp3.59 playing White: 94 - 72 - 334  [0.522] 500
...      ChessDotCpp3.59 playing Black: 88 - 74 - 338  [0.514] 500
...      White vs Black: 168 - 160 - 672  [0.504] 1000
Elo difference: 12.5 +/- 12.3, LOS: 97.7 %, DrawRatio: 67.2 %
```

### 3.60

Tune LMR

```
info depth 1 seldepth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 17 nodes 282 nps 282000 time 1 pv d2d4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 22 nodes 388 nps 388000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 seldepth 8 multipv 1 score cp 18 nodes 739 nps 739000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 24 nodes 1198 nps 1198000 time 1 pv g2g3 e7e6 g1f3 f8e7 f1g2 g8f6
info depth 7 seldepth 9 multipv 1 score cp 16 nodes 2891 nps 1445500 time 2 pv g1f3 g8f6 g2g3 g7g6 d2d4 f8g7 f1g2
info depth 8 seldepth 10 multipv 1 score cp 16 nodes 3959 nps 1319666 time 3 pv g1f3 g8f6 g2g3 g7g6 d2d4 f8g7 f1g2 e8g8
info depth 9 seldepth 14 multipv 1 score cp 35 nodes 15723 nps 1572300 time 10 pv e2e4 e7e6 g1f3 c7c5 f1e2 f8e7 d2d4 c5d4 d1d4
info depth 10 seldepth 18 multipv 1 score cp 28 nodes 24858 nps 1553625 time 16 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7
info depth 11 seldepth 17 multipv 1 score cp 30 nodes 51660 nps 1666451 time 31 pv e2e4 c7c6 g1f3 d7d5 e4d5 c6d5 f1e2 g8f6 e1g1 b8c6 f1e1
info depth 12 seldepth 19 multipv 1 score cp 18 nodes 105381 nps 1786118 time 59 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 d2d4 e8g8
info depth 13 seldepth 21 multipv 1 score cp 27 nodes 157678 nps 1855035 time 85 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8e7 e1g1 e8g8 f1e1
info depth 14 seldepth 22 multipv 1 score cp 27 nodes 247549 nps 1889687 time 131 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 c7c6
info depth 15 seldepth 23 multipv 1 score cp 18 nodes 558046 nps 1958056 time 285 pv d2d4 d7d5 c2c4 e7e6 e2e3 g8f6 g1f3 f8e7 f1e2 e8g8 e1g1 f8e8 b1c3 d5c4 e2c4
info depth 16 seldepth 22 multipv 1 score cp 22 nodes 811554 nps 1979400 time 410 pv d2d4 d7d5 c2c4 e7e6 e2e3 g8f6 g1f3 f8e7 f1e2 e8g8 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 seldepth 25 multipv 1 score cp 17 nodes 1524143 nps 1997566 time 763 pv d2d4 d7d5 c2c4 e7e6 e2e3 g8f6 g1f3 f8e7 f1e2 e8g8 e1g1 d5c4 b1d2 c7c5 d4c5 e7c5 d2c4
info depth 18 seldepth 28 multipv 1 score cp 16 nodes 2433409 nps 2021103 time 1204 pv d2d4 d7d5 c2c4 e7e6 e2e3 g8f6 g1f3 f8e7 f1e2 e8g8 e1g1 b8d7 b2b3 d5c4 b3c4 c7c5 f1e1 c5d4 e3d4
info depth 19 seldepth 29 multipv 1 score cp 21 nodes 4538074 nps 2024118 time 2242 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 b8c6 c2c3 c8g4 c1f4 f8e8
info depth 20 seldepth 31 multipv 1 score cp 19 nodes 5699040 nps 2016645 time 2826 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 c8d7 c2c3 c7c5 b1d2
info depth 21 seldepth 30 multipv 1 score cp 14 nodes 9196050 nps 1994804 time 4610 pv g1f3 g8f6 d2d4 e7e6 c2c4 d7d5 c1g5 d5c4 b1c3 c7c5 e2e3 c5d4 f3d4 f8e7 f1c4 e8g8 e1g1 c8d7 c4e2
info depth 22 seldepth 31 multipv 1 score cp 14 nodes 12653744 nps 1992715 time 6350 pv g1f3 g8f6 d2d4 e7e6 c2c4 d7d5 c1g5 d5c4 b1c3 c7c5 e2e3 b8c6 f1c4 c5d4 e3d4 f8e7 e1g1 e8g8 f1e1 h7h6 g5h4 d8a5
info depth 23 seldepth 34 multipv 1 score cp 22 nodes 19926634 nps 1979401 time 10067 pv g1f3 g8f6 d2d4 e7e6 c2c4 d7d5 g2g3 d5c4 f1g2 f8b4 c1d2 a7a5 d1c1 b4d2 c1d2 e8g8 b1a3 b7b6 f3e5 a8a7 e1g1 c8b7 g2b7 a7b7 a3c4
info depth 24 seldepth 34 multipv 1 score cp 20 nodes 26775692 nps 1977233 time 13542 pv g1f3 g8f6 d2d4 e7e6 c2c4 d7d5 g2g3 c7c6 f1g2 f8e7 e1g1 e8g8 b1d2 b7b6 b2b3 c8b7 c1b2 b8d7 f3e5 f8e8 e5d7 d8d7 e2e4 c6c5
info depth 25 seldepth 36 multipv 1 score cp 17 nodes 35840079 nps 1977601 time 18123 pv g1f3 g8f6 d2d4 e7e6 c2c4 d7d5 g2g3 c7c6 f1g2 f8e7 e1g1 e8g8 b1d2 b7b6 b2b3 c8b7 c1b2 b8d7 f3e5 d7e5 d4e5 f6d7 e2e4 f8e8 e4d5 c6d5 c4d5 b7d5 g2d5 e6d5
```

```
Score of ChessDotCpp3.60 vs ChessDotCpp3.59: 196 - 167 - 637  [0.514] 1000
...      ChessDotCpp3.60 playing White: 93 - 90 - 318  [0.503] 501
...      ChessDotCpp3.60 playing Black: 103 - 77 - 319  [0.526] 499
...      White vs Black: 170 - 193 - 637  [0.488] 1000
Elo difference: 10.1 +/- 13.0, LOS: 93.6 %, DrawRatio: 63.7 %
```

### 3.61

Reduce more on non-PV nodes

```
info depth 1 seldepth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 17 nodes 287 nps 287000 time 1 pv d2d4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 22 nodes 410 nps 410000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 seldepth 8 multipv 1 score cp 18 nodes 829 nps 829000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 23 nodes 1571 nps 785500 time 2 pv g2g3 g7g6 g1f3 g8f6 f1g2 f8g7
info depth 7 seldepth 9 multipv 1 score cp 16 nodes 3372 nps 1124000 time 3 pv g1f3 g8f6 d2d4 g7g6 g2g3 f8g7 f1g2
info depth 8 seldepth 12 multipv 1 score cp 21 nodes 4949 nps 1237250 time 4 pv g1f3 g8f6 d2d4 g7g6 g2g3 f8g7 f1g2 d7d5
info depth 9 seldepth 14 multipv 1 score cp 27 nodes 27780 nps 1736250 time 16 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 e4e5
info depth 10 seldepth 15 multipv 1 score cp 30 nodes 36249 nps 1726142 time 21 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5
info depth 11 seldepth 18 multipv 1 score cp 27 nodes 58014 nps 1812937 time 32 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5 c2c4
info depth 12 seldepth 18 multipv 1 score cp 31 nodes 100593 nps 1828963 time 55 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 d7c6 d1e2 c8g4 e1g1 e7e6
info depth 13 seldepth 19 multipv 1 score cp 24 nodes 184004 nps 1896948 time 97 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 f8e7 e1g1 e8g8 e4e5
info depth 14 seldepth 20 multipv 1 score cp 25 nodes 277802 nps 1929180 time 144 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 seldepth 21 multipv 1 score cp 24 nodes 429057 nps 1959164 time 219 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5 c3d5 c6d5
info depth 16 seldepth 25 multipv 1 score cp 21 nodes 1036389 nps 1981623 time 523 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 f8e8 e1e8 d8e8 b1c3
info depth 17 seldepth 24 multipv 1 score cp 25 nodes 1345199 nps 1995844 time 674 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 b1d2 c7c5 d4c5 d6c5
info depth 18 seldepth 26 multipv 1 score cp 28 nodes 1738940 nps 2008013 time 866 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 b1d2 b8d7 c2c4 c7c6
info depth 19 seldepth 29 multipv 1 score cp 23 nodes 2596323 nps 2009537 time 1292 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 b1d2 b8d7 f1e1 c7c6 c2c3 e8e1 d1e1
info depth 20 seldepth 28 multipv 1 score cp 21 nodes 3759161 nps 2016717 time 1864 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 b1d2 h7h6 g5h4 b8d7 c2c4 c7c6
info depth 21 seldepth 32 multipv 1 score cp 18 nodes 7187267 nps 1988729 time 3614 pv g1f3 g8f6 d2d4 d7d5 c2c4 e7e6 g2g3 b8d7 f1g2 f8e7 e1g1 e8g8 d1c2 c7c6 b2b3 b7b5 b1d2 c8a6 f3e5 b5c4 e5c6
info depth 22 seldepth 34 multipv 1 score cp 22 nodes 10136698 nps 1978664 time 5123 pv g1f3 g8f6 d2d4 d7d5 c2c4 e7e6 g2g3 f8e7 f1g2 e8g8 e1g1 c7c6 b1c3 b8d7 b2b3 b7b5 f3e5 d7e5 d4e5 f6d7 c4b5 d7e5
info depth 23 seldepth 36 multipv 1 score cp 19 nodes 13323709 nps 1972129 time 6756 pv g1f3 g8f6 d2d4 d7d5 c2c4 e7e6 g2g3 f8e7 f1g2 e8g8 e1g1 c7c6 b1c3 b7b6 b2b3 c8a6 f3e5 f6d7 e5d7 d8d7 d1d3 b6b5 c4b5 c6b5
info depth 24 seldepth 32 multipv 1 score cp 19 nodes 17277825 nps 1967413 time 8782 pv g1f3 g8f6 d2d4 d7d5 c2c4 e7e6 g2g3 f8e7 f1g2 e8g8 e1g1 c7c6 b1c3 b7b6 b2b3 c8a6 f3e5 f6d7 e5d7 d8d7 d1d3 b6b5 c4b5 c6b5
info depth 25 seldepth 37 multipv 1 score cp 21 nodes 23845368 nps 1957587 time 12181 pv g1f3 g8f6 d2d4 d7d5 c2c4 e7e6 g2g3 f8e7 f1g2 e8g8 e1g1 c7c6 b1d2 a7a5 f1e1 b7b6 d1c2 c8b7 e2e4 d5c4 d2c4 c6c5 d4c5 e7c5 e4e5
```

```
Score of ChessDotCpp3.61 vs ChessDotCpp3.60: 691 - 628 - 2681  [0.508] 4000
...      ChessDotCpp3.61 playing White: 364 - 296 - 1341  [0.517] 2001
...      ChessDotCpp3.61 playing Black: 327 - 332 - 1340  [0.499] 1999
...      White vs Black: 696 - 623 - 2681  [0.509] 4000
Elo difference: 5.5 +/- 6.2, LOS: 95.9 %, DrawRatio: 67.0 %
```

### 3.62

Remove LMR limiting

```
info depth 1 seldepth 1 multipv 1 score cp 23 nodes 24 nps 24000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 28 nodes 67 nps 67000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 17 nodes 292 nps 292000 time 1 pv d2d4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 22 nodes 410 nps 410000 time 1 pv d2d4 d7d5 g1f3 g8f6
info depth 5 seldepth 8 multipv 1 score cp 18 nodes 803 nps 803000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 24 nodes 1701 nps 850500 time 2 pv g2g3 e7e6 g1f3 f8e7 f1g2 g8f6
info depth 7 seldepth 10 multipv 1 score cp 20 nodes 3247 nps 1082333 time 3 pv g2g3 e7e6 f1g2 f8e7 c2c4 g8f6 g1f3
info depth 8 seldepth 13 multipv 1 score cp 19 nodes 8759 nps 1459833 time 6 pv g1f3 g8f6 c2c4 e7e6 g2g3 d7d5 c4d5 e6d5
info depth 9 seldepth 13 multipv 1 score cp 23 nodes 20592 nps 1716000 time 12 pv e2e4 c7c5 f1e2 b8c6 g1f3 e7e6 e1g1 f8e7 d2d4 c5d4 f3d4
info depth 10 seldepth 16 multipv 1 score cp 30 nodes 34613 nps 1730650 time 20 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5
info depth 11 seldepth 18 multipv 1 score cp 27 nodes 52988 nps 1766266 time 30 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 d5c7 b5c6 d7c6
info depth 12 seldepth 20 multipv 1 score cp 21 nodes 98216 nps 1853132 time 53 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 d2d4 f8e7 c2c3 e8g8
info depth 13 seldepth 20 multipv 1 score cp 18 nodes 185935 nps 1936822 time 96 pv g1f3 g8f6 e2e3 e7e6 d2d4 f8e7 f1e2 e8g8 c2c4 d7d5 e1g1 d5c4 e2c4
info depth 14 seldepth 23 multipv 1 score cp 18 nodes 245651 nps 1949611 time 126 pv g1f3 g8f6 e2e3 e7e6 d2d4 f8e7 f1e2 e8g8 c2c4 d7d5 e1g1 f8e8 b1c3 d5c4 e2c4
info depth 15 seldepth 24 multipv 1 score cp 19 nodes 513210 nps 1981505 time 259 pv d2d4 d7d5 g1f3 g8f6 c2c4 e7e6 e2e3 f8e7 f1e2 e8g8 e1g1 f8e8 d1c2 d5c4 e2c4
info depth 16 seldepth 22 multipv 1 score cp 22 nodes 705399 nps 1998297 time 353 pv d2d4 d7d5 g1f3 g8f6 c2c4 e7e6 e2e3 f8e7 f1e2 e8g8 e1g1 d5c4 e2c4 c7c5 d4c5 e7c5
info depth 17 seldepth 27 multipv 1 score cp 19 nodes 1508749 nps 2000993 time 754 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 f1e1 c8g4 c1g5 b8d7 b1d2
info depth 18 seldepth 28 multipv 1 score cp 25 nodes 1962489 nps 1996428 time 983 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 c7c5 c2c3 f8e7 d4c5 e7c5 e1g1 e8g8 f1e1 f8e8 e1e8 d8e8
info depth 19 seldepth 28 multipv 1 score cp 19 nodes 2770663 nps 2000478 time 1385 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 c7c5 c2c3 f8e7 d4c5 e7c5 e1g1 e8g8 c1g5 f8e8 b1d2
info depth 20 seldepth 32 multipv 1 score cp 14 nodes 4216175 nps 1993463 time 2115 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 e7d6 e2d1 c8g4 c1g5 b8d7 b1d2 f8e8
info depth 21 seldepth 30 multipv 1 score cp 15 nodes 5688599 nps 1986936 time 2863 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 d1e2 d6e7 e1g1 e8g8 f1e1 e7d6 c1g5 h7h6 g5h4 c8g4 b1d2 b8c6
info depth 22 seldepth 31 multipv 1 score cp 16 nodes 7504132 nps 1979982 time 3790 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 f1d3 g8f6 e1g1 e8g8 c1g5 b8d7 f1e1 f8e8 h2h3 c7c6 g5h4 e8e1 d1e1
info depth 23 seldepth 34 multipv 1 score cp 24 nodes 11831053 nps 1959432 time 6038 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 b8c6 d4c6 b7c6 f1d3 c8a6 c1e3 b6b7 d3a6 b7a6 g1f3
info depth 24 seldepth 31 multipv 1 score cp 23 nodes 15760707 nps 1958095 time 8049 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 b8c6 d4c6 b7c6 f1d3 f8c5 d1e2 a7a5 g1f3 c8a6 d3a6 b6a6 e2a6 a8a6
info depth 25 seldepth 33 multipv 1 score cp 23 nodes 19258650 nps 1954200 time 9855 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 b8c6 d4c6 b7c6 f1d3 f8c5 d1e2 a7a5 g1f3 c8a6 d3a6 b6a6 e2a6 a8a6
```

```
Score of ChessDotCpp3.62 vs ChessDotCpp3.61: 694 - 648 - 2658  [0.506] 4000
...      ChessDotCpp3.62 playing White: 368 - 291 - 1342  [0.519] 2001
...      ChessDotCpp3.62 playing Black: 326 - 357 - 1316  [0.492] 1999
...      White vs Black: 725 - 617 - 2658  [0.513] 4000
Elo difference: 4.0 +/- 6.2, LOS: 89.5 %, DrawRatio: 66.5 %
```

### 3.63

Retrain same NNUE arch on 1.65B FENs (+650M FENs)

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -602  | -467  | -513  | -1028 | -141  | -509  | -465  | -617  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -66  | -130  | -116  | -141  | -134  | -175  | -153  |  -69  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  64   |  124  |  110  |  134  |  127  |  164  |  150  |  68   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  548  |  453  |  487  |  887  |  119  |  483  |  452  |  565  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 25
Phase: 24
```

```
info depth 1 seldepth 1 multipv 1 score cp 24 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 36 nodes 83 nps 83000 time 1 pv d2d4 e7e6
info depth 3 seldepth 8 multipv 1 score cp 6 nodes 291 nps 291000 time 1 pv e2e4 c7c5 d2d4 c5d4 d1d4
info depth 4 seldepth 6 multipv 1 score cp 28 nodes 422 nps 422000 time 1 pv e2e4 c7c5 f1b5 d8c7
info depth 5 seldepth 9 multipv 1 score cp 11 nodes 1243 nps 1243000 time 1 pv e2e4 e7e5 d2d4 e5d4 d1d4
info depth 6 seldepth 13 multipv 1 score cp 21 nodes 3308 nps 1102666 time 3 pv c2c4 c7c5 g1f3 g8f6 b1c3 b8c6
info depth 7 seldepth 11 multipv 1 score cp 21 nodes 4654 nps 1551333 time 3 pv c2c4 c7c5 g1f3 g8f6 b1c3 b8c6 d2d4
info depth 8 seldepth 14 multipv 1 score cp 28 nodes 12704 nps 1588000 time 8 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 g8f6
info depth 9 seldepth 16 multipv 1 score cp 37 nodes 19659 nps 1638250 time 12 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4
info depth 10 seldepth 17 multipv 1 score cp 28 nodes 27984 nps 1749000 time 16 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 f8e7 b5c6 b7c6
info depth 11 seldepth 19 multipv 1 score cp 27 nodes 49410 nps 1764642 time 28 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 f8e7 d2d4 c5d4 f3d4
info depth 12 seldepth 20 multipv 1 score cp 26 nodes 93191 nps 1863820 time 50 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3 f8e7
info depth 13 seldepth 19 multipv 1 score cp 19 nodes 211360 nps 1957037 time 108 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 f1d3 g8f6 g1f3 f8e7 e1g1 e8g8 f1e1
info depth 14 seldepth 21 multipv 1 score cp 18 nodes 331270 nps 1960177 time 169 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c5d4 c3d4 g8e7 g1f3 e7c6 f1d3 f8e7
info depth 15 seldepth 23 multipv 1 score cp 24 nodes 552698 nps 2002528 time 276 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 f8e7 d2d4 c5d4 c3d4
info depth 16 seldepth 24 multipv 1 score cp 29 nodes 829557 nps 2008612 time 413 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 f8b4 b1d2 b8c6 f1d3 d7d6 e1g1 d6e5 d4e5
info depth 17 seldepth 25 multipv 1 score cp 33 nodes 1591138 nps 2001431 time 795 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4b5 d7d5 e4d5 f6d5 c3d5 e6d5 f1e2
info depth 18 seldepth 28 multipv 1 score cp 28 nodes 2266045 nps 2010687 time 1127 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 g8f6 e1g1 d7d6 d2d4 c5d4 f3d4 f8e7 d4c6 b7c6 c1f4 e8g8
info depth 19 seldepth 27 multipv 1 score cp 24 nodes 3217241 nps 2013292 time 1598 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 f8e7 e1g1 d5f4 d2d4 f4e2 d1e2 c5d4 c3d4 e8g8
info depth 20 seldepth 28 multipv 1 score cp 22 nodes 4435339 nps 2010579 time 2206 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 f8e7 e1g1 e8g8 d2d4 c5d4 f3d4 d8c7 d4f3 b8c6 c3c4 d5b6
info depth 21 seldepth 30 multipv 1 score cp 18 nodes 6844460 nps 2005996 time 3412 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 b1c3 b8c6 f1b5 f8e7 e5d6 d8d6 e1g1 e8g8 f1e1
info depth 22 seldepth 32 multipv 1 score cp 23 nodes 9703138 nps 2000647 time 4850 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 f8e7 d2d4 c5d4 f3d4 e8g8 c1e3 b7b6 f1e1 c6d4 d1d4 e7c5 d4d3 c5e3 d3e3
info depth 23 seldepth 31 multipv 1 score cp 20 nodes 12892206 nps 1994771 time 6463 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 g8f6 e1g1 f8e7 d2d4 c5d4 f3d4 e8g8 c1e3 b7b6 d4c6 d7c6 f2f4 c8b7 e4e5 f6d5 c3d5 c6d5
info depth 24 seldepth 34 multipv 1 score cp 21 nodes 19886111 nps 1873926 time 10612 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 d2d4 c5d4 f3d4 c6d4 d1d4 b7b6 b1c3 c8b7 c1e3 g8f6 e1c1 f8c5 d4d3 d8e7 e3g5 e8g8 d3d2 c5b4
info depth 25 seldepth 37 multipv 1 score cp 31 nodes 53878130 nps 1720082 time 31323 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 b8c6 b1c3 g8f6 c1f4 d7d6 f1b5 c8d7 b5c6 b7c6 e4e5 f6d5 c3d5 d6e5 f4e5 d8a5 c2c3 a5d5 d4f3 d5d1 a1d1
```

```
Score of ChessDotCpp3.63 vs ChessDotCpp3.62: 635 - 544 - 1821  [0.515] 3000
...      ChessDotCpp3.63 playing White: 345 - 260 - 896  [0.528] 1501
...      ChessDotCpp3.63 playing Black: 290 - 284 - 925  [0.502] 1499
...      White vs Black: 629 - 550 - 1821  [0.513] 3000
Elo difference: 10.5 +/- 7.8, LOS: 99.6 %, DrawRatio: 60.7 %
```

### 3.64

NNUE input bucketing based on king square. (2 x 6 x 64)x8 -> (512)x2 -> 1

```
+-------+-------+-------+-------+-------+-------+-------+-------+
|   r   |   n   |   b   |   q   |   k   |   b   |   n   |   r   |
| -596  | -455  | -539  | -1146 |  -53  | -512  | -460  | -616  | 8
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   p   |   p   |   p   |   p   |   p   |   p   |   p   |   p   |
|  -76  | -141  | -126  | -169  | -167  | -188  | -151  |  -75  | 7
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 6
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 5
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 4
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|       |       |       |       |       |       |       |       |
|       |       |       |       |       |       |       |       | 3
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   P   |   P   |   P   |   P   |   P   |   P   |   P   |   P   |
|  75   |  138  |  123  |  160  |  158  |  175  |  147  |  75   | 2
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
|   R   |   N   |   B   |   Q   |   K   |   B   |   N   |   R   |
|  587  |  455  |  536  | 1148  |  42   |  507  |  457  |  606  | 1
|       |       |       |       |       |       |       |       |
+-------+-------+-------+-------+-------+-------+-------+-------+
    A       B       C       D       E       F       G       H
Side: White
FEN: rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq -
Key: 5885741381098971863
Eval: 26
Phase: 24
```

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 1000 nodes
Total fens:    6566
Found mates:   127
Best mates:    25

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 10000 nodes
Total fens:    6566
Found mates:   135
Best mates:    95

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 100000 nodes
Total fens:    6566
Found mates:   484
Best mates:    323

1000000 nodes failed
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 20 nodes 1091 nps 1091000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 8 multipv 1 score cp 22 nodes 1718 nps 859000 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 8 multipv 1 score cp 33 nodes 2556 nps 1278000 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 10 multipv 1 score cp 30 nodes 7473 nps 1494600 time 5 pv e2e4 g7g6 g1f3 c7c5 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 13 multipv 1 score cp 28 nodes 12556 nps 1569500 time 8 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 g7g6 b5c6 b7c6
info depth 10 seldepth 14 multipv 1 score cp 33 nodes 19551 nps 1629250 time 12 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 32945 nps 1733947 time 19 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 36 nodes 59186 nps 1793515 time 33 pv e2e4 c7c5 g1f3 g7g6 b1c3 g8f6 e4e5 f6g4 d2d4 f8g7 f1e2 c5d4 d1d4
info depth 13 seldepth 20 multipv 1 score cp 25 nodes 101054 nps 1837345 time 55 pv e2e4 c7c5 g1f3 g7g6 b1c3 f8g7 d2d4 c5d4 f3d4 g8f6 c1e3 e8g8 f1e2
info depth 14 seldepth 20 multipv 1 score cp 29 nodes 180286 nps 1877979 time 96 pv e2e4 c7c5 g1f3 g7g6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 d1b3 d5c7 c3d4 b8c6
info depth 15 seldepth 22 multipv 1 score cp 30 nodes 288509 nps 1898085 time 152 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 511780 nps 1888487 time 271 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 739494 nps 1886464 time 392 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 26 multipv 1 score cp 33 nodes 1272540 nps 1893660 time 672 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 28 multipv 1 score cp 30 nodes 2194028 nps 1893035 time 1159 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 a1b1 e7e6 c1g5
info depth 20 seldepth 30 multipv 1 score cp 25 nodes 3526677 nps 1890979 time 1865 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 e4e5 d6e5 f3e5 g7g6 d1f3 d8c7 b1c3 f8g7 e5d7 f6d7
info depth 21 seldepth 30 multipv 1 score cp 27 nodes 4703684 nps 1887513 time 2492 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 d8c7 b1c3 e7e6 f1d1 a8c8 c1e3 b7b5 h2h3 g8f6 e4e5
info depth 22 seldepth 34 multipv 1 score cp 27 nodes 6009925 nps 1884579 time 3189 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 f1e1 d7b8 e3g5 e7e6
info depth 23 seldepth 34 multipv 1 score cp 27 nodes 7969125 nps 1880841 time 4237 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 d1d2 d7b8 c3d5 f6d5 c4d5
info depth 24 seldepth 35 multipv 1 score cp 20 nodes 13078512 nps 1872371 time 6985 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8c7
info depth 25 seldepth 38 multipv 1 score cp 18 nodes 36650333 nps 1833800 time 19986 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8a5 c1d2 h7h6 a2a4 a5c7 g1h1
```

```
Score of ChessDotCpp3.64 vs ChessDotCpp3.63: 1792 - 1425 - 5283  [0.522] 8500
...      ChessDotCpp3.64 playing White: 951 - 696 - 2603  [0.530] 4250
...      ChessDotCpp3.64 playing Black: 841 - 729 - 2680  [0.513] 4250
...      White vs Black: 1680 - 1537 - 5283  [0.508] 8500
Elo difference: 15.0 +/- 4.5, LOS: 100.0 %, DrawRatio: 62.2 %

Score of ChessDotCpp3.64 vs weiss2.0: 718 - 76 - 206  [0.821] 1000
...      ChessDotCpp3.64 playing White: 356 - 37 - 107  [0.819] 500
...      ChessDotCpp3.64 playing Black: 362 - 39 - 99  [0.823] 500
...      White vs Black: 395 - 399 - 206  [0.498] 1000
Elo difference: 264.6 +/- 22.7, LOS: 100.0 %, DrawRatio: 20.6 %

Score of ChessDotCpp3.64 vs seer2.5: 137 - 315 - 548  [0.411] 1000
...      ChessDotCpp3.64 playing White: 66 - 148 - 285  [0.418] 499
...      ChessDotCpp3.64 playing Black: 71 - 167 - 263  [0.404] 501
...      White vs Black: 233 - 219 - 548  [0.507] 1000
Elo difference: -62.5 +/- 14.4, LOS: 0.0 %, DrawRatio: 54.8 %
```

### 3.65

Fix bug with hitting max ply

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 1000 nodes
Total fens:    6566
Found mates:   127
Best mates:    25

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 10000 nodes
Total fens:    6566
Found mates:   135
Best mates:    95

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 100000 nodes
Total fens:    6566
Found mates:   484
Best mates:    323

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1341
Best mates:    935
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 20 nodes 1091 nps 1091000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 8 multipv 1 score cp 22 nodes 1718 nps 859000 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 8 multipv 1 score cp 33 nodes 2556 nps 1278000 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 10 multipv 1 score cp 30 nodes 7473 nps 1494600 time 5 pv e2e4 g7g6 g1f3 c7c5 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 13 multipv 1 score cp 28 nodes 12556 nps 1569500 time 8 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 g7g6 b5c6 b7c6
info depth 10 seldepth 14 multipv 1 score cp 33 nodes 19551 nps 1629250 time 12 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 32945 nps 1733947 time 19 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 36 nodes 59186 nps 1740764 time 34 pv e2e4 c7c5 g1f3 g7g6 b1c3 g8f6 e4e5 f6g4 d2d4 f8g7 f1e2 c5d4 d1d4
info depth 13 seldepth 20 multipv 1 score cp 25 nodes 101054 nps 1804535 time 56 pv e2e4 c7c5 g1f3 g7g6 b1c3 f8g7 d2d4 c5d4 f3d4 g8f6 c1e3 e8g8 f1e2
info depth 14 seldepth 20 multipv 1 score cp 29 nodes 180286 nps 1839653 time 98 pv e2e4 c7c5 g1f3 g7g6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 d1b3 d5c7 c3d4 b8c6
info depth 15 seldepth 22 multipv 1 score cp 30 nodes 288509 nps 1885679 time 153 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 511780 nps 1888487 time 271 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 739494 nps 1891289 time 391 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 26 multipv 1 score cp 33 nodes 1272540 nps 1902152 time 669 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 28 multipv 1 score cp 30 nodes 2194028 nps 1899591 time 1155 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 a1b1 e7e6 c1g5
info depth 20 seldepth 30 multipv 1 score cp 25 nodes 3526677 nps 1893009 time 1863 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 e4e5 d6e5 f3e5 g7g6 d1f3 d8c7 b1c3 f8g7 e5d7 f6d7
info depth 21 seldepth 30 multipv 1 score cp 27 nodes 4703684 nps 1886000 time 2494 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 d8c7 b1c3 e7e6 f1d1 a8c8 c1e3 b7b5 h2h3 g8f6 e4e5
info depth 22 seldepth 34 multipv 1 score cp 27 nodes 6009925 nps 1879276 time 3198 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 f1e1 d7b8 e3g5 e7e6
info depth 23 seldepth 34 multipv 1 score cp 27 nodes 7969125 nps 1877296 time 4245 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 d1d2 d7b8 c3d5 f6d5 c4d5
info depth 24 seldepth 35 multipv 1 score cp 20 nodes 13078512 nps 1864895 time 7013 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8c7
info depth 25 seldepth 38 multipv 1 score cp 18 nodes 36650333 nps 1832241 time 20003 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8a5 c1d2 h7h6 a2a4 a5c7 g1h1
```

```
Score of ChessDotCpp3.65 vs ChessDotCpp3.64: 827 - 828 - 3345  [0.500] 5000
...      ChessDotCpp3.65 playing White: 427 - 401 - 1673  [0.505] 2501
...      ChessDotCpp3.65 playing Black: 400 - 427 - 1672  [0.495] 2499
...      White vs Black: 854 - 801 - 3345  [0.505] 5000
Elo difference: -0.1 +/- 5.5, LOS: 49.0 %, DrawRatio: 66.9 %
```

### 3.66

Syzygy UCI option

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 20 nodes 1091 nps 1091000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 8 multipv 1 score cp 22 nodes 1718 nps 859000 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 8 multipv 1 score cp 33 nodes 2556 nps 852000 time 3 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 10 multipv 1 score cp 30 nodes 7473 nps 1245500 time 6 pv e2e4 g7g6 g1f3 c7c5 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 13 multipv 1 score cp 28 nodes 12556 nps 1395111 time 9 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 g7g6 b5c6 b7c6
info depth 10 seldepth 14 multipv 1 score cp 33 nodes 19551 nps 1503923 time 13 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 32945 nps 1568809 time 21 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 36 nodes 59186 nps 1599621 time 37 pv e2e4 c7c5 g1f3 g7g6 b1c3 g8f6 e4e5 f6g4 d2d4 f8g7 f1e2 c5d4 d1d4
info depth 13 seldepth 20 multipv 1 score cp 25 nodes 101054 nps 1684233 time 60 pv e2e4 c7c5 g1f3 g7g6 b1c3 f8g7 d2d4 c5d4 f3d4 g8f6 c1e3 e8g8 f1e2
info depth 14 seldepth 20 multipv 1 score cp 29 nodes 180286 nps 1733519 time 104 pv e2e4 c7c5 g1f3 g7g6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 d1b3 d5c7 c3d4 b8c6
info depth 15 seldepth 22 multipv 1 score cp 30 nodes 288509 nps 1791981 time 161 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 511780 nps 1808409 time 283 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 739494 nps 1821413 time 406 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 26 multipv 1 score cp 33 nodes 1272540 nps 1825738 time 697 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 28 multipv 1 score cp 30 nodes 2194028 nps 1798383 time 1220 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 a1b1 e7e6 c1g5
info depth 20 seldepth 30 multipv 1 score cp 25 nodes 3526677 nps 1785659 time 1975 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 e4e5 d6e5 f3e5 g7g6 d1f3 d8c7 b1c3 f8g7 e5d7 f6d7
info depth 21 seldepth 30 multipv 1 score cp 27 nodes 4703684 nps 1774305 time 2651 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 d8c7 b1c3 e7e6 f1d1 a8c8 c1e3 b7b5 h2h3 g8f6 e4e5
info depth 22 seldepth 34 multipv 1 score cp 27 nodes 6009925 nps 1781774 time 3373 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 f1e1 d7b8 e3g5 e7e6
info depth 23 seldepth 34 multipv 1 score cp 27 nodes 7969125 nps 1787200 time 4459 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 d1d2 d7b8 c3d5 f6d5 c4d5
info depth 24 seldepth 35 multipv 1 score cp 20 nodes 13078512 nps 1774801 time 7369 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8c7
info depth 25 seldepth 38 multipv 1 score cp 18 nodes 36650333 nps 1761781 time 20803 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8a5 c1d2 h7h6 a2a4 a5c7 g1h1
```

```
Score of ChessDotCpp3.66 vs ChessDotCpp3.65: 144 - 157 - 699  [0.493] 1000
...      ChessDotCpp3.66 playing White: 78 - 74 - 347  [0.504] 499
...      ChessDotCpp3.66 playing Black: 66 - 83 - 352  [0.483] 501
...      White vs Black: 161 - 140 - 699  [0.510] 1000
Elo difference: -4.5 +/- 11.8, LOS: 22.7 %, DrawRatio: 69.9 %
```

### 3.67

Improve TT on qsearch

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   126
Best mates:    24

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   131
Best mates:    90

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   485
Best mates:    329

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1346
Best mates:    940
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 20 nodes 1091 nps 1091000 time 1 pv g2g3 d7d5 f1g2 g8f6 g1f3
info depth 6 seldepth 8 multipv 1 score cp 22 nodes 1718 nps 859000 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 8 multipv 1 score cp 33 nodes 2556 nps 852000 time 3 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 10 multipv 1 score cp 30 nodes 7473 nps 1245500 time 6 pv e2e4 g7g6 g1f3 c7c5 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 13 multipv 1 score cp 28 nodes 12556 nps 1569500 time 8 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 g7g6 b5c6 b7c6
info depth 10 seldepth 14 multipv 1 score cp 33 nodes 19551 nps 1629250 time 12 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 32946 nps 1647300 time 20 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 36 nodes 59187 nps 1644083 time 36 pv e2e4 c7c5 g1f3 g7g6 b1c3 g8f6 e4e5 f6g4 d2d4 f8g7 f1e2 c5d4 d1d4
info depth 13 seldepth 20 multipv 1 score cp 25 nodes 101056 nps 1656655 time 61 pv e2e4 c7c5 g1f3 g7g6 b1c3 f8g7 d2d4 c5d4 f3d4 g8f6 c1e3 e8g8 f1e2
info depth 14 seldepth 20 multipv 1 score cp 29 nodes 180296 nps 1733615 time 104 pv e2e4 c7c5 g1f3 g7g6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 d1b3 d5c7 c3d4 b8c6
info depth 15 seldepth 22 multipv 1 score cp 30 nodes 288524 nps 1781012 time 162 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 511801 nps 1802116 time 284 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 739516 nps 1821467 time 406 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 26 multipv 1 score cp 33 nodes 1272566 nps 1787311 time 712 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 28 multipv 1 score cp 30 nodes 2194059 nps 1811774 time 1211 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 a1b1 e7e6 c1g5
info depth 20 seldepth 30 multipv 1 score cp 25 nodes 3526708 nps 1828257 time 1929 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 e4e5 d6e5 f3e5 g7g6 d1f3 d8c7 b1c3 f8g7 e5d7 f6d7
info depth 21 seldepth 30 multipv 1 score cp 27 nodes 4703718 nps 1828106 time 2573 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 d8c7 b1c3 e7e6 f1d1 a8c8 c1e3 b7b5 h2h3 g8f6 e4e5
info depth 22 seldepth 34 multipv 1 score cp 27 nodes 6009968 nps 1828405 time 3287 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 f1e1 d7b8 e3g5 e7e6
info depth 23 seldepth 34 multipv 1 score cp 27 nodes 7969168 nps 1823608 time 4370 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g7g6 c2c4 g8f6 d2d3 f8g7 b1c3 e8g8 h2h3 a7a6 c1e3 d8c7 d1d2 d7b8 c3d5 f6d5 c4d5
info depth 24 seldepth 35 multipv 1 score cp 20 nodes 13078572 nps 1792567 time 7296 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8c7
info depth 25 seldepth 38 multipv 1 score cp 18 nodes 36650526 nps 1795626 time 20411 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 d1e2 f8e8 f1d1 d8a5 c1d2 h7h6 a2a4 a5c7 g1h1
```

```
Score of ChessDotCpp3.67 vs ChessDotCpp3.66: 1612 - 1566 - 6822  [0.502] 10000
...      ChessDotCpp3.67 playing White: 840 - 735 - 3425  [0.510] 5000
...      ChessDotCpp3.67 playing Black: 772 - 831 - 3397  [0.494] 5000
...      White vs Black: 1671 - 1507 - 6822  [0.508] 10000
Elo difference: 1.6 +/- 3.8, LOS: 79.3 %, DrawRatio: 68.2 %
```

### 3.68

Reset killer heuristic for grandchildren nodes

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 16 nodes 1096 nps 1096000 time 1 pv g2g3 c7c6 f1g2 g8f6 g1f3
info depth 6 seldepth 7 multipv 1 score cp 22 nodes 1598 nps 799000 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 9 multipv 1 score cp 33 nodes 2377 nps 1188500 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 13 multipv 1 score cp 27 nodes 7663 nps 1277166 time 6 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d7d6 e5d6
info depth 9 seldepth 15 multipv 1 score cp 17 nodes 11784 nps 1473000 time 8 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 g8f6 e1g1
info depth 10 seldepth 16 multipv 1 score cp 29 nodes 18164 nps 1513666 time 12 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 f8e7 d2d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 30134 nps 1674111 time 18 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 29 nodes 46676 nps 1667000 time 28 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2 f8g7
info depth 13 seldepth 20 multipv 1 score cp 31 nodes 82104 nps 1710500 time 48 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3 f8g7 f1e2
info depth 14 seldepth 21 multipv 1 score cp 24 nodes 209103 nps 1802612 time 116 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 seldepth 24 multipv 1 score cp 25 nodes 410800 nps 1833928 time 224 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c2c4 g8f6 c4c5 d6e7 f1d3 e8g8 e1g1
info depth 16 seldepth 23 multipv 1 score cp 21 nodes 730475 nps 1858715 time 393 pv e2e4 e7e6 d2d4 d7d5 e4e5 c8d7 g1f3 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 g8e7
info depth 17 seldepth 25 multipv 1 score cp 30 nodes 1122480 nps 1867687 time 601 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 27 multipv 1 score cp 22 nodes 1800665 nps 1854443 time 971 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 19 seldepth 27 multipv 1 score cp 22 nodes 2546317 nps 1843821 time 1381 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 20 seldepth 30 multipv 1 score cp 27 nodes 4887052 nps 1824207 time 2679 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 f1e1 a7a6 c1f4 d7d5 e4d5 e6d5
info depth 21 seldepth 29 multipv 1 score cp 20 nodes 6790538 nps 1820519 time 3730 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d7d5 e4d5 e6d5 d2d4 c8g4 c1e3 c5d4 e3d4 f8b4 e1g1 e8g8 d4f6 d8f6 c3d5 f6b2
info depth 22 seldepth 32 multipv 1 score cp 28 nodes 9832183 nps 1787344 time 5501 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 f8e7 e1g1 d7d5 e4d5 f6d5 f1e1 e8g8 c2c3 c8d7 b1d2 d8c7 d3c2 b8c6
info depth 23 seldepth 34 multipv 1 score cp 24 nodes 14590338 nps 1780829 time 8193 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 d2d4 c5d4 d1d4 e7e5 d4d3 f8e7 c1g5 d7e6 g5f6 e7f6 b1c3 e8g8 c3d5 e6d5 d3d5
info depth 24 seldepth 35 multipv 1 score cp 23 nodes 21018654 nps 1770290 time 11873 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 b7b5 f3d2 b5b4
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 51567696 nps 1791478 time 28785 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 f8e8 f3d2 a8c8 f1d1
```

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   123
Best mates:    24

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   136
Best mates:    97

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   501
Best mates:    337

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1334
Best mates:    927
```

```
Score of ChessDotCpp3.68 vs ChessDotCpp3.67: 1661 - 1497 - 6842  [0.508] 10000
...      ChessDotCpp3.68 playing White: 902 - 736 - 3362  [0.517] 5000
...      ChessDotCpp3.68 playing Black: 759 - 761 - 3480  [0.500] 5000
...      White vs Black: 1663 - 1495 - 6842  [0.508] 10000
Elo difference: 5.7 +/- 3.8, LOS: 99.8 %, DrawRatio: 68.4 %
```

### 3.69

Transposition table prefetching

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 16 nodes 1096 nps 1096000 time 1 pv g2g3 c7c6 f1g2 g8f6 g1f3
info depth 6 seldepth 7 multipv 1 score cp 22 nodes 1598 nps 1598000 time 1 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 9 multipv 1 score cp 33 nodes 2377 nps 1188500 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 13 multipv 1 score cp 27 nodes 7663 nps 1532600 time 5 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d7d6 e5d6
info depth 9 seldepth 15 multipv 1 score cp 17 nodes 11784 nps 1683428 time 7 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 g8f6 e1g1
info depth 10 seldepth 16 multipv 1 score cp 29 nodes 18164 nps 1651272 time 11 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 f8e7 d2d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 30134 nps 1674111 time 18 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 29 nodes 46676 nps 1795230 time 26 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2 f8g7
info depth 13 seldepth 20 multipv 1 score cp 31 nodes 82104 nps 1824533 time 45 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3 f8g7 f1e2
info depth 14 seldepth 21 multipv 1 score cp 24 nodes 209103 nps 1918376 time 109 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 seldepth 24 multipv 1 score cp 25 nodes 410800 nps 1956190 time 210 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c2c4 g8f6 c4c5 d6e7 f1d3 e8g8 e1g1
info depth 16 seldepth 23 multipv 1 score cp 21 nodes 730475 nps 1984986 time 368 pv e2e4 e7e6 d2d4 d7d5 e4e5 c8d7 g1f3 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 g8e7
info depth 17 seldepth 25 multipv 1 score cp 30 nodes 1122480 nps 2008014 time 559 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 27 multipv 1 score cp 22 nodes 1800665 nps 2016422 time 893 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 19 seldepth 27 multipv 1 score cp 22 nodes 2546317 nps 2017683 time 1262 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 20 seldepth 30 multipv 1 score cp 27 nodes 4887052 nps 2003711 time 2439 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 f1e1 a7a6 c1f4 d7d5 e4d5 e6d5
info depth 21 seldepth 29 multipv 1 score cp 20 nodes 6790538 nps 1990776 time 3411 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d7d5 e4d5 e6d5 d2d4 c8g4 c1e3 c5d4 e3d4 f8b4 e1g1 e8g8 d4f6 d8f6 c3d5 f6b2
info depth 22 seldepth 32 multipv 1 score cp 28 nodes 9832183 nps 1969982 time 4991 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 f8e7 e1g1 d7d5 e4d5 f6d5 f1e1 e8g8 c2c3 c8d7 b1d2 d8c7 d3c2 b8c6
info depth 23 seldepth 34 multipv 1 score cp 24 nodes 14590338 nps 1962913 time 7433 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 d2d4 c5d4 d1d4 e7e5 d4d3 f8e7 c1g5 d7e6 g5f6 e7f6 b1c3 e8g8 c3d5 e6d5 d3d5
info depth 24 seldepth 35 multipv 1 score cp 23 nodes 21018654 nps 1948336 time 10788 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 b7b5 f3d2 b5b4
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 51567696 nps 1950145 time 26443 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 f8e8 f3d2 a8c8 f1d1
```

```
Score of ChessDotCpp3.69 vs ChessDotCpp3.68: 1172 - 990 - 4838  [0.513] 7000
...      ChessDotCpp3.69 playing White: 625 - 470 - 2405  [0.522] 3500
...      ChessDotCpp3.69 playing Black: 547 - 520 - 2433  [0.504] 3500
...      White vs Black: 1145 - 1017 - 4838  [0.509] 7000
Elo difference: 9.0 +/- 4.5, LOS: 100.0 %, DrawRatio: 69.1 %
```

### 3.70

Earlier TT prefetching, TT prefetching in qsearch

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 16 nodes 1096 nps 1096000 time 1 pv g2g3 c7c6 f1g2 g8f6 g1f3
info depth 6 seldepth 7 multipv 1 score cp 22 nodes 1598 nps 1598000 time 1 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 9 multipv 1 score cp 33 nodes 2377 nps 1188500 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 13 multipv 1 score cp 27 nodes 7663 nps 1532600 time 5 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d7d6 e5d6
info depth 9 seldepth 15 multipv 1 score cp 17 nodes 11784 nps 1683428 time 7 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 g8f6 e1g1
info depth 10 seldepth 16 multipv 1 score cp 29 nodes 18164 nps 1651272 time 11 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 f8e7 d2d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 30134 nps 1772588 time 17 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 29 nodes 46676 nps 1867040 time 25 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2 f8g7
info depth 13 seldepth 20 multipv 1 score cp 31 nodes 82104 nps 1909395 time 43 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3 f8g7 f1e2
info depth 14 seldepth 21 multipv 1 score cp 24 nodes 209103 nps 2010605 time 104 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 seldepth 24 multipv 1 score cp 25 nodes 410800 nps 2043781 time 201 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c2c4 g8f6 c4c5 d6e7 f1d3 e8g8 e1g1
info depth 16 seldepth 23 multipv 1 score cp 21 nodes 730475 nps 2051896 time 356 pv e2e4 e7e6 d2d4 d7d5 e4e5 c8d7 g1f3 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 g8e7
info depth 17 seldepth 25 multipv 1 score cp 30 nodes 1122480 nps 2070996 time 542 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 27 multipv 1 score cp 22 nodes 1800665 nps 2084103 time 864 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 19 seldepth 27 multipv 1 score cp 22 nodes 2546317 nps 2087145 time 1220 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 20 seldepth 30 multipv 1 score cp 27 nodes 4887052 nps 2064660 time 2367 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 f1e1 a7a6 c1f4 d7d5 e4d5 e6d5
info depth 21 seldepth 29 multipv 1 score cp 20 nodes 6790538 nps 2058986 time 3298 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d7d5 e4d5 e6d5 d2d4 c8g4 c1e3 c5d4 e3d4 f8b4 e1g1 e8g8 d4f6 d8f6 c3d5 f6b2
info depth 22 seldepth 32 multipv 1 score cp 28 nodes 9832183 nps 2038603 time 4823 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 f8e7 e1g1 d7d5 e4d5 f6d5 f1e1 e8g8 c2c3 c8d7 b1d2 d8c7 d3c2 b8c6
info depth 23 seldepth 34 multipv 1 score cp 24 nodes 14590338 nps 2031231 time 7183 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 d2d4 c5d4 d1d4 e7e5 d4d3 f8e7 c1g5 d7e6 g5f6 e7f6 b1c3 e8g8 c3d5 e6d5 d3d5
info depth 24 seldepth 35 multipv 1 score cp 23 nodes 21018654 nps 2017145 time 10420 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 b7b5 f3d2 b5b4
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 51567696 nps 2014914 time 25593 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 f8e8 f3d2 a8c8 f1d1
```

```
Score of ChessDotCpp3.70 vs ChessDotCpp3.69: 491 - 422 - 2087  [0.511] 3000
...      ChessDotCpp3.70 playing White: 264 - 197 - 1040  [0.522] 1501
...      ChessDotCpp3.70 playing Black: 227 - 225 - 1047  [0.501] 1499
...      White vs Black: 489 - 424 - 2087  [0.511] 3000
Elo difference: 8.0 +/- 6.8, LOS: 98.9 %, DrawRatio: 69.6 %

Score of ChessDotCpp3.70 vs weiss2.0: 707 - 92 - 201  [0.807] 1000
...      ChessDotCpp3.70 playing White: 354 - 38 - 107  [0.817] 499
...      ChessDotCpp3.70 playing Black: 353 - 54 - 94  [0.798] 501
...      White vs Black: 408 - 391 - 201  [0.508] 1000
Elo difference: 249.1 +/- 22.5, LOS: 100.0 %, DrawRatio: 20.1 %

Score of ChessDotCpp3.70 vs seer2.5: 164 - 303 - 533  [0.430] 1000
...      ChessDotCpp3.70 playing White: 98 - 142 - 260  [0.456] 500
...      ChessDotCpp3.70 playing Black: 66 - 161 - 273  [0.405] 500
...      White vs Black: 259 - 208 - 533  [0.525] 1000
Elo difference: -48.6 +/- 14.7, LOS: 0.0 %, DrawRatio: 53.3 %
```

### 3.71

Store move picker in ply state

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 16 nodes 1096 nps 1096000 time 1 pv g2g3 c7c6 f1g2 g8f6 g1f3
info depth 6 seldepth 7 multipv 1 score cp 22 nodes 1598 nps 1598000 time 1 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 9 multipv 1 score cp 33 nodes 2377 nps 1188500 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 13 multipv 1 score cp 27 nodes 7663 nps 1532600 time 5 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d7d6 e5d6
info depth 9 seldepth 15 multipv 1 score cp 17 nodes 11784 nps 1683428 time 7 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 g8f6 e1g1
info depth 10 seldepth 16 multipv 1 score cp 29 nodes 18164 nps 1816400 time 10 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 f8e7 d2d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 30134 nps 1883375 time 16 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 18 multipv 1 score cp 29 nodes 46676 nps 1944833 time 24 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2 f8g7
info depth 13 seldepth 20 multipv 1 score cp 31 nodes 82104 nps 2052600 time 40 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3 f8g7 f1e2
info depth 14 seldepth 21 multipv 1 score cp 24 nodes 209103 nps 2091030 time 100 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 e4e5 f6d5
info depth 15 seldepth 24 multipv 1 score cp 25 nodes 410800 nps 2128497 time 193 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 f8d6 c2c4 g8f6 c4c5 d6e7 f1d3 e8g8 e1g1
info depth 16 seldepth 23 multipv 1 score cp 21 nodes 730475 nps 2148455 time 340 pv e2e4 e7e6 d2d4 d7d5 e4e5 c8d7 g1f3 c7c5 c2c3 d8a5 b1d2 c5d4 d2b3 a5b6 b3d4 g8e7
info depth 17 seldepth 25 multipv 1 score cp 30 nodes 1122480 nps 2166949 time 518 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 27 multipv 1 score cp 22 nodes 1800665 nps 2130964 time 845 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 19 seldepth 27 multipv 1 score cp 22 nodes 2546317 nps 2143364 time 1188 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 e7e6 c2c4 g8f6 d2d4 c5d4 d1d4 f8e7 e4e5 d6e5 f3e5
info depth 20 seldepth 30 multipv 1 score cp 27 nodes 4887052 nps 2142504 time 2281 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 f1e1 a7a6 c1f4 d7d5 e4d5 e6d5
info depth 21 seldepth 29 multipv 1 score cp 20 nodes 6790538 nps 2086827 time 3254 pv e2e4 c7c5 g1f3 e7e6 g2g3 b8c6 f1g2 g8f6 b1c3 d7d5 e4d5 e6d5 d2d4 c8g4 c1e3 c5d4 e3d4 f8b4 e1g1 e8g8 d4f6 d8f6 c3d5 f6b2
info depth 22 seldepth 32 multipv 1 score cp 28 nodes 9832183 nps 2011905 time 4887 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 f8e7 e1g1 d7d5 e4d5 f6d5 f1e1 e8g8 c2c3 c8d7 b1d2 d8c7 d3c2 b8c6
info depth 23 seldepth 34 multipv 1 score cp 24 nodes 14590338 nps 2040036 time 7152 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 d2d4 c5d4 d1d4 e7e5 d4d3 f8e7 c1g5 d7e6 g5f6 e7f6 b1c3 e8g8 c3d5 e6d5 d3d5
info depth 24 seldepth 35 multipv 1 score cp 23 nodes 21018654 nps 2012317 time 10445 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 b7b5 f3d2 b5b4
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 51567696 nps 2030943 time 25391 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 d2d4 c5d4 d1d4 e7e5 d4d3 h7h6 c1e3 g8f6 c2c4 f8e7 b1c3 e8g8 h2h3 f8e8 f3d2 a8c8 f1d1
```

```
core of ChessDotCpp3.71 vs ChessDotCpp3.70: 532 - 426 - 2042  [0.518] 3000
...      ChessDotCpp3.71 playing White: 284 - 198 - 1019  [0.529] 1501
...      ChessDotCpp3.71 playing Black: 248 - 228 - 1023  [0.507] 1499
...      White vs Black: 512 - 446 - 2042  [0.511] 3000
Elo difference: 12.3 +/- 7.0, LOS: 100.0 %, DrawRatio: 68.1 %
```

### 3.72

Do not set improving if in check

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 333 nps 333000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 19 nodes 544 nps 544000 time 1 pv c2c4 g7g6 g1f3 f8g7
info depth 5 seldepth 7 multipv 1 score cp 16 nodes 1096 nps 1096000 time 1 pv g2g3 c7c6 f1g2 g8f6 g1f3
info depth 6 seldepth 7 multipv 1 score cp 22 nodes 1598 nps 1598000 time 1 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7
info depth 7 seldepth 9 multipv 1 score cp 33 nodes 2377 nps 1188500 time 2 pv g2g3 g8f6 f1g2 g7g6 g1f3 f8g7 e1g1
info depth 8 seldepth 13 multipv 1 score cp 27 nodes 7663 nps 1532600 time 5 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d7d6 e5d6
info depth 9 seldepth 15 multipv 1 score cp 17 nodes 11784 nps 1683428 time 7 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 g8f6 e1g1
info depth 10 seldepth 16 multipv 1 score cp 29 nodes 18073 nps 1807300 time 10 pv e2e4 c7c5 b1c3 e7e6 g1f3 b8c6 f1e2 f8e7 d2d4 g8f6
info depth 11 seldepth 16 multipv 1 score cp 24 nodes 30119 nps 1882437 time 16 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 g8f6 f1e2
info depth 12 seldepth 16 multipv 1 score cp 24 nodes 44310 nps 1926521 time 23 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 f1e2 f8g7 e1g1 g8f6 d2d4 c5d4 f3d4
info depth 13 seldepth 20 multipv 1 score cp 31 nodes 96287 nps 1965040 time 49 pv e2e4 c7c5 b1c3 g7g6 g1f3 b8c6 d2d4 c5d4 f3d4 f8g7 c1e3 g8f6 f1e2
info depth 14 seldepth 21 multipv 1 score cp 30 nodes 206995 nps 2069950 time 100 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 15 seldepth 22 multipv 1 score cp 30 nodes 290288 nps 2103536 time 138 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 492316 nps 2149851 time 229 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 28 nodes 956853 nps 2102973 time 455 pv e2e4 c7c5 g1f3 d7d6 c2c3 g8f6 d1c2 g7g6 d2d4 d8c7 f1d3 f8g7 e1g1 e8g8 f1e1 c5d4 c3d4 c7c2 d3c2
info depth 18 seldepth 26 multipv 1 score cp 24 nodes 1506305 nps 2074800 time 726 pv e2e4 c7c5 g1f3 d7d6 b1c3 g8f6 d2d4 c5d4 f3d4 b8c6 f1e2 g7g6 e1g1 f8g7 c1e3 e8g8 h2h3 c8d7
info depth 19 seldepth 27 multipv 1 score cp 23 nodes 2460577 nps 2087003 time 1179 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 c2c3 e7e6 d2d4 c5d4 c3d4 f8e7 e4e5 f6d5 b1c3 d5c3 b2c3
info depth 20 seldepth 28 multipv 1 score cp 22 nodes 3655979 nps 2116953 time 1727 pv e2e4 c7c5 g1f3 d7d6 f1b5 b8d7 e1g1 a7a6 b5d7 c8d7 f1e1 g8f6 e4e5 d6e5 f3e5 e7e6 d1f3 d8c7 e5d7 c7d7 b1c3 f8e7
info depth 21 seldepth 32 multipv 1 score cp 27 nodes 5129355 nps 2044382 time 2509 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 g7g6 h2h3 f8g7 c2c4 e8g8 b1c3 a7a6 c1e3 f8e8 a1b1 e7e6 f1e1
info depth 22 seldepth 34 multipv 1 score cp 24 nodes 7009903 nps 2023060 time 3465 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 g7g6 h2h3 f8g7 c2c4 e8g8 b1c3 a7a6 c1e3 f8e8 d1d2 e7e6 d3d4 c5d4 f3d4
info depth 23 seldepth 33 multipv 1 score cp 24 nodes 8778552 nps 2040100 time 4303 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 g7g6 h2h3 f8g7 c2c4 e8g8 b1c3 a7a6 c1e3 f8e8 a2a4 d7b8 d3d4 c5d4 f3d4
info depth 24 seldepth 37 multipv 1 score cp 23 nodes 14570411 nps 2014992 time 7231 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 g1h1 d8c7 a1b1 d7b8 a2a3 b8c6 c1e3 f6d7
info depth 25 seldepth 35 multipv 1 score cp 24 nodes 18576288 nps 2010856 time 9238 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c2c4 f8e7 h2h3 a7a6 b1c3 e8g8 a1b1 f8e8 a2a3 d8c7 c1e3 d7b8 b2b4 f6d7 f1e1
```

```
Score of ChessDotCpp3.72 vs ChessDotCpp3.71: 689 - 606 - 2705  [0.510] 4000
...      ChessDotCpp3.72 playing White: 368 - 286 - 1346  [0.520] 2000
...      ChessDotCpp3.72 playing Black: 321 - 320 - 1359  [0.500] 2000
...      White vs Black: 688 - 607 - 2705  [0.510] 4000
Elo difference: 7.2 +/- 6.1, LOS: 98.9 %, DrawRatio: 67.6 %
```

---
## Switch opening book from noob_4moves to UHO_XXL_+0.90_+1.19
---

### 3.73

Fix double main history updating

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 4 multipv 1 score cp 12 nodes 297 nps 297000 time 1 pv g2g3 g8f6 f1g2
info depth 4 seldepth 5 multipv 1 score cp 14 nodes 445 nps 445000 time 1 pv g2g3 e7e5 f1g2 g8f6
info depth 5 seldepth 6 multipv 1 score cp 1 nodes 1006 nps 1006000 time 1 pv e2e4 e7e5 g2g3 g8f6 f1g2
info depth 6 seldepth 7 multipv 1 score cp 8 nodes 1557 nps 1557000 time 1 pv e2e4 e7e5 b1c3 g8f6 f1c4 f8c5
info depth 7 seldepth 11 multipv 1 score cp 10 nodes 3124 nps 1562000 time 2 pv b1c3 g8f6 e2e4 c7c5 g2g3 d7d5 e4d5 f6d5
info depth 8 seldepth 14 multipv 1 score cp 28 nodes 8540 nps 1708000 time 5 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 b1c3 c6d4 f3e5 d4b5 c3b5 f6e4
info depth 9 seldepth 15 multipv 1 score cp 29 nodes 13542 nps 1692750 time 8 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 28 nodes 19729 nps 1793545 time 11 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b1c3 g7g6 b5c6 b7c6
info depth 11 seldepth 16 multipv 1 score cp 30 nodes 29671 nps 1854437 time 16 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 18 multipv 1 score cp 33 nodes 49628 nps 1908769 time 26 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 d7d5 e4d5 e6d5
info depth 13 seldepth 19 multipv 1 score cp 30 nodes 87162 nps 1936933 time 45 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 g8e7 e1g1 e7g6 f1e1 f8e7 b5c6 b7c6
info depth 14 seldepth 22 multipv 1 score cp 25 nodes 150050 nps 2027702 time 74 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 d4b5 f8c5 c1f4 e8g8
info depth 15 seldepth 21 multipv 1 score cp 24 nodes 300049 nps 2113021 time 142 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1e2 g8f6 e1g1 f8e7 d2d4 c5d4 f3d4 e8g8 d4b5
info depth 16 seldepth 22 multipv 1 score cp 26 nodes 570862 nps 2138059 time 267 pv e2e4 c7c5 g1f3 e7e6 b1c3 a7a6 g2g3 b7b5 f1g2 c8b7 d2d4 c5d4 f3d4 b5b4 c3a4 g8f6
info depth 17 seldepth 26 multipv 1 score cp 32 nodes 1080190 nps 2151772 time 502 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8e7 e1g1 e8g8 h2h3 f8e8 f1e1 b8d7 b1c3
info depth 18 seldepth 26 multipv 1 score cp 18 nodes 1838458 nps 2173118 time 846 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 c7c5 d3b5 c8d7 b5d7 d8d7 e1g1 c5d4 f1e1 f8e7 f3d4 e8g8 b1c3
info depth 19 seldepth 27 multipv 1 score cp 25 nodes 2392538 nps 2173059 time 1101 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 c7c5 d3b5 c8d7 b5d7 d8d7 e1g1 c5d4 f3d4 f8e7 c1g5 e8g8 b1c3
info depth 20 seldepth 29 multipv 1 score cp 27 nodes 3351056 nps 2167565 time 1546 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 c7c5 c2c3 c5c4 d3c2 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1f4
info depth 21 seldepth 33 multipv 1 score cp 16 nodes 5509437 nps 2145419 time 2568 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 c8d7 c2c4 h7h6 g5h4 c7c5
info depth 22 seldepth 33 multipv 1 score cp 16 nodes 7052171 nps 2137021 time 3300 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 f8e8 h2h3 b8d7 f1e1 e8e1 d1e1 c7c6 b1d2
info depth 23 seldepth 32 multipv 1 score cp 18 nodes 10153860 nps 2125127 time 4778 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 c8g4 h2h3 g4h5 g2g4 h5g6 f1e1 b8d7 b1c3
info depth 24 seldepth 33 multipv 1 score cp 19 nodes 13559970 nps 2114450 time 6413 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 c8g4 h2h3 g4h5 b1d2 c7c5 d4c5 d6c5 d2b3 c5e7
info depth 25 seldepth 33 multipv 1 score cp 23 nodes 18321714 nps 2111769 time 8676 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 f8e8 b1d2 c7c5 d4c5 d6c5 f1e1 e8e1 d1e1 c8e6 c2c3 b8c6
```

```
Score of ChessDotCpp3.73 vs ChessDotCpp3.72: 236 - 227 - 537  [0.504] 1000
...      ChessDotCpp3.73 playing White: 206 - 31 - 264  [0.675] 501
...      ChessDotCpp3.73 playing Black: 30 - 196 - 273  [0.334] 499
...      White vs Black: 402 - 61 - 537  [0.670] 1000
Elo difference: 3.1 +/- 14.6, LOS: 66.2 %, DrawRatio: 53.7 %
```

### 3.74

Penalize continuation history for failed moves

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 4 multipv 1 score cp 12 nodes 295 nps 295000 time 1 pv g2g3 g8f6 f1g2
info depth 4 seldepth 5 multipv 1 score cp 14 nodes 421 nps 421000 time 1 pv g2g3 e7e5 f1g2 g8f6
info depth 5 seldepth 6 multipv 1 score cp 21 nodes 859 nps 859000 time 1 pv c2c4 g8f6 b1c3 e7e5 g1f3
info depth 6 seldepth 10 multipv 1 score cp 26 nodes 1760 nps 880000 time 2 pv c2c4 g7g6 b1c3 g8f6 d2d4 f8g7
info depth 7 seldepth 10 multipv 1 score cp 33 nodes 3452 nps 1150666 time 3 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1
info depth 8 seldepth 12 multipv 1 score cp 29 nodes 6910 nps 1382000 time 5 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d5f4
info depth 9 seldepth 12 multipv 1 score cp 15 nodes 9633 nps 1605500 time 6 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 e1g1
info depth 10 seldepth 14 multipv 1 score cp 23 nodes 15207 nps 1689666 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 e1g1 d5f4
info depth 11 seldepth 16 multipv 1 score cp 21 nodes 22346 nps 1718923 time 13 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 g7g6 e1g1 f8g7 f1e1
info depth 12 seldepth 18 multipv 1 score cp 40 nodes 46127 nps 1845080 time 25 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5 e1g1 g7g6
info depth 13 seldepth 17 multipv 1 score cp 36 nodes 63614 nps 1871000 time 34 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5 e1g1 d7d6 e5d6 e7d6
info depth 14 seldepth 20 multipv 1 score cp 33 nodes 103218 nps 1947509 time 53 pv e2e4 c7c5 g1f3 g7g6 f1c4 f8g7 e1g1 b8c6 f1e1 g8f6 c2c3 e8g8 d2d4 c5d4 c3d4
info depth 15 seldepth 20 multipv 1 score cp 39 nodes 171640 nps 2019294 time 85 pv e2e4 c7c5 g1f3 g7g6 c2c3 f8g7 d2d4 c5d4 c3d4 d7d5 f1b5 c8d7 b5d7 d8d7 e4e5 b8c6 e1g1
info depth 16 seldepth 22 multipv 1 score cp 26 nodes 286394 nps 2060388 time 139 pv e2e4 c7c5 g1f3 g7g6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 f8g7 b1c3 d5c3 b2c3 d7d6
info depth 17 seldepth 24 multipv 1 score cp 30 nodes 580639 nps 2119120 time 274 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 25 multipv 1 score cp 33 nodes 850055 nps 2130463 time 399 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 25 multipv 1 score cp 28 nodes 1248241 nps 2141065 time 583 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 d2d4 g8f6 e1g1 f8e7 c1g5 e8g8 g5f6 e7f6 d4c5
info depth 20 seldepth 28 multipv 1 score cp 24 nodes 1815223 nps 2148192 time 845 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5 f6d7 d1d4 f8e8
info depth 21 seldepth 29 multipv 1 score cp 23 nodes 2678346 nps 2149555 time 1246 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 f1e1 f8e8 d4c6 d7c6 e4e5 f6d7 d1d4
info depth 22 seldepth 34 multipv 1 score cp 25 nodes 3633522 nps 2153836 time 1687 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 d1d8 f8d8 c1e3 g8f8 f1d1 c8d7
info depth 23 seldepth 31 multipv 1 score cp 23 nodes 5099875 nps 2128495 time 2396 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 f1e1 d7d6 h2h3 c6d4 d1d4 a7a6 a2a4 c8d7 c1f4
info depth 24 seldepth 36 multipv 1 score cp 23 nodes 7093286 nps 2119296 time 3347 pv e2e4 c7c5 g1f3 e7e6 b1c3 d7d6 d2d4 c5d4 f3d4 g8f6 c1e3 b8c6 d1d2 f8e7 f2f4 f6g4 e3g1 c6d4 g1d4 e6e5 d4g1 e8g8 e1c1 e5f4 d2f4
info depth 25 seldepth 35 multipv 1 score cp 25 nodes 9417082 nps 2105787 time 4472 pv e2e4 c7c5 g1f3 e7e6 b1c3 a7a6 d2d4 c5d4 f3d4 d8c7 d1f3 g8f6 f3g3 d7d6 f1d3 b8d7 e1g1 f8e7 g3g7 h8g8 g7h6 d7e5 h6e3 c8d7 a2a4
```

```
Score of ChessDotCpp3.74 vs ChessDotCpp3.73: 233 - 227 - 540  [0.503] 1000
...      ChessDotCpp3.74 playing White: 202 - 28 - 270  [0.674] 500
...      ChessDotCpp3.74 playing Black: 31 - 199 - 270  [0.332] 500
...      White vs Black: 401 - 59 - 540  [0.671] 1000
Elo difference: 2.1 +/- 14.6, LOS: 61.0 %, DrawRatio: 54.0 %
```

Noob 4 moves:
```
Score of ChessDotCpp3.74 vs weiss2.0: 688 - 86 - 226  [0.801] 1000
...      ChessDotCpp3.74 playing White: 352 - 39 - 109  [0.813] 500
...      ChessDotCpp3.74 playing Black: 336 - 47 - 117  [0.789] 500
...      White vs Black: 399 - 375 - 226  [0.512] 1000
Elo difference: 241.9 +/- 21.7, LOS: 100.0 %, DrawRatio: 22.6 %

Score of ChessDotCpp3.74 vs seer2.5: 180 - 270 - 550  [0.455] 1000
...      ChessDotCpp3.74 playing White: 87 - 133 - 281  [0.454] 501
...      ChessDotCpp3.74 playing Black: 93 - 137 - 269  [0.456] 499
...      White vs Black: 224 - 226 - 550  [0.499] 1000
Elo difference: -31.4 +/- 14.4, LOS: 0.0 %, DrawRatio: 55.0 %
```

### 3.75

Lower reverse futility pruning threshold if improving

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 4 multipv 1 score cp 12 nodes 295 nps 295000 time 1 pv g2g3 g8f6 f1g2
info depth 4 seldepth 5 multipv 1 score cp 14 nodes 421 nps 421000 time 1 pv g2g3 e7e5 f1g2 g8f6
info depth 5 seldepth 6 multipv 1 score cp 21 nodes 856 nps 856000 time 1 pv c2c4 g8f6 b1c3 e7e5 g1f3
info depth 6 seldepth 10 multipv 1 score cp 26 nodes 1755 nps 877500 time 2 pv c2c4 g7g6 b1c3 g8f6 d2d4 f8g7
info depth 7 seldepth 10 multipv 1 score cp 33 nodes 3428 nps 1142666 time 3 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1
info depth 8 seldepth 12 multipv 1 score cp 29 nodes 6840 nps 1368000 time 5 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d5f4
info depth 9 seldepth 12 multipv 1 score cp 15 nodes 9488 nps 1581333 time 6 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 e1g1
info depth 10 seldepth 15 multipv 1 score cp 23 nodes 15175 nps 1686111 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 e1g1 d5f4
info depth 11 seldepth 16 multipv 1 score cp 21 nodes 30290 nps 1781764 time 17 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 g7g6 e1g1 f8g7 f1e1
info depth 12 seldepth 17 multipv 1 score cp 28 nodes 42098 nps 1830347 time 23 pv e2e4 c7c5 g1f3 b8c6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 f1e2 d5c7 c3d4
info depth 13 seldepth 22 multipv 1 score cp 31 nodes 71168 nps 1923459 time 37 pv e2e4 c7c5 g1f3 b8c6 b1c3 g8f6 f1b5 c6d4 e4e5 d4b5 c3b5 f6d5 e1g1
info depth 14 seldepth 23 multipv 1 score cp 32 nodes 156473 nps 1955912 time 80 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 f8e7 d2d4 c5d4 c3d4
info depth 15 seldepth 21 multipv 1 score cp 30 nodes 215317 nps 2012308 time 107 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 291644 nps 2039468 time 143 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 454286 nps 2064936 time 220 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 25 multipv 1 score cp 32 nodes 669891 nps 2080406 time 322 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 f8e7 e1g1 d5f4 d2d4 f4e2 d1e2 c5d4 f1d1 d4c3 b1c3
info depth 19 seldepth 26 multipv 1 score cp 23 nodes 1205872 nps 2089899 time 577 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1c4 d7d6 d2d4 f8e7 c4d5 e6d5 e5d6 e7d6 d4c5 d6c5 e1g1
info depth 20 seldepth 28 multipv 1 score cp 26 nodes 1850815 nps 2103198 time 880 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 d2d4 c5d4 c3d4 d7d6 b1c3 d5c3 b2c3 d6e5 f3e5 b8d7 e5f3 f8e7
info depth 21 seldepth 29 multipv 1 score cp 23 nodes 2702408 nps 2107962 time 1282 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 f1d3 d7d5 e4e5 f6d7 e1g1 d8c7 f1e1 b8c6 d3b5 f8e7 d2d4 e8g8 b5a4 c5d4 c3d4
info depth 22 seldepth 31 multipv 1 score cp 20 nodes 4216291 nps 2110255 time 1998 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 f1d3 d7d5 e4e5 f6d7 e1g1 d8c7 f1e1 b8c6 d3b5 a7a6 b5c6 b7c6 d2d3 f8e7 c3c4 e8g8
info depth 23 seldepth 30 multipv 1 score cp 23 nodes 5635740 nps 2102103 time 2681 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 b7c6 e1g1 d7d5 b1d2 f8e7 b2b3 e8g8 c1b2 f6d7 c2c4 c8a6 f1e1
info depth 24 seldepth 35 multipv 1 score cp 30 nodes 10756216 nps 2072888 time 5189 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 b7c6 e1g1 d7d5 b1d2 f8e7 b2b3 e8g8 c1b2 c8b7 f1e1 d8c7
info depth 25 seldepth 33 multipv 1 score cp 28 nodes 12921177 nps 2070369 time 6241 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 b7c6 e1g1 d7d5 b1d2 f8e7 b2b3 e8g8 c1b2 c8b7 d1e2 f6d7 c2c4 a7a5 f1d1
```

```
Score of ChessDotCpp3.75 vs ChessDotCpp3.74: 2356 - 2261 - 5383  [0.505] 10000
...      ChessDotCpp3.75 playing White: 2054 - 301 - 2645  [0.675] 5000
...      ChessDotCpp3.75 playing Black: 302 - 1960 - 2738  [0.334] 5000
...      White vs Black: 4014 - 603 - 5383  [0.671] 10000
Elo difference: 3.3 +/- 4.6, LOS: 91.9 %, DrawRatio: 53.8 %
```

### 3.76

More LMR adjustment based on move history

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   108
Best mates:    22

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   134
Best mates:    96

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   466
Best mates:    320

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1391
Best mates:    944
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 4 multipv 1 score cp 12 nodes 295 nps 295000 time 1 pv g2g3 g8f6 f1g2
info depth 4 seldepth 5 multipv 1 score cp 14 nodes 421 nps 421000 time 1 pv g2g3 e7e5 f1g2 g8f6
info depth 5 seldepth 6 multipv 1 score cp 21 nodes 856 nps 856000 time 1 pv c2c4 g8f6 b1c3 e7e5 g1f3
info depth 6 seldepth 10 multipv 1 score cp 26 nodes 1755 nps 877500 time 2 pv c2c4 g7g6 b1c3 g8f6 d2d4 f8g7
info depth 7 seldepth 10 multipv 1 score cp 33 nodes 3428 nps 1142666 time 3 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1
info depth 8 seldepth 12 multipv 1 score cp 29 nodes 6843 nps 1368600 time 5 pv e2e4 c7c5 g1f3 g8f6 e4e5 f6d5 f1e2 d5f4
info depth 9 seldepth 12 multipv 1 score cp 15 nodes 9476 nps 1579333 time 6 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 e1g1
info depth 10 seldepth 15 multipv 1 score cp 23 nodes 15138 nps 1682000 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 e4e5 f6d5 e1g1 d5f4
info depth 11 seldepth 16 multipv 1 score cp 21 nodes 21636 nps 1664307 time 13 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 g7g6 e1g1 f8g7 f1e1
info depth 12 seldepth 16 multipv 1 score cp 24 nodes 31635 nps 1757500 time 18 pv e2e4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 g7g6 e1g1 f8g7 d2d4 c5d4 f3d4
info depth 13 seldepth 19 multipv 1 score cp 31 nodes 59880 nps 1871250 time 32 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1e3 f8g7 f1e2
info depth 14 seldepth 20 multipv 1 score cp 32 nodes 100596 nps 1934538 time 52 pv e2e4 c7c5 g1f3 g7g6 c2c3 f8g7 d2d4 d7d5 e4d5 d8d5 d4c5 d5c5 c1e3 c5a5
info depth 15 seldepth 21 multipv 1 score cp 30 nodes 188292 nps 2003106 time 94 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 39 nodes 307658 nps 2024065 time 152 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 d2d4 c5d4 f3d4 g8f6 d4c6 b7c6 b1d2 f8e7 e4e5 f6d5
info depth 17 seldepth 23 multipv 1 score cp 30 nodes 456006 nps 2063375 time 221 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 26 multipv 1 score cp 33 nodes 701382 nps 2087446 time 336 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 28 multipv 1 score cp 25 nodes 1235418 nps 2093928 time 590 pv e2e4 c7c5 g1f3 e7e6 f1d3 g7g6 c2c3 g8e7 d3c2 d7d5 e4d5 e7d5 d2d4 f8g7 d4c5 e8g8 e1g1 b8d7 f1e1 d7c5
info depth 20 seldepth 28 multipv 1 score cp 30 nodes 1923120 nps 2099475 time 916 pv e2e4 c7c5 g1f3 e7e6 f1d3 g7g6 c2c3 f8g7 d3c2 d7d5 e4d5 e6d5 d2d4 c5d4 e1g1 b8c6 f1e1 g8e7 c1g5 c8g4 c3d4
info depth 21 seldepth 28 multipv 1 score cp 30 nodes 2458808 nps 2105143 time 1168 pv e2e4 c7c5 g1f3 e7e6 f1d3 g7g6 c2c3 f8g7 d3c2 d7d5 e4d5 e6d5 d2d4 c5d4 e1g1 b8c6 c1g5 g8e7 f1e1 c8g4 c3d4
info depth 22 seldepth 30 multipv 1 score cp 28 nodes 3685659 nps 2092935 time 1761 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 d7d5 e4d5 f6d5 e1g1 f8e7 f1e1 e8g8 c2c3 c8d7 b1d2 d8c7 d3c2 b8c6
info depth 23 seldepth 31 multipv 1 score cp 22 nodes 5716539 nps 2087852 time 2738 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 d7d5 e4d5 f6d5 e1g1 f8e7 f1e1 e8g8 h2h3 d5f6 c2c3 a7a6 b1d2 d8c7 d2f3
info depth 24 seldepth 31 multipv 1 score cp 24 nodes 7346138 nps 2087564 time 3519 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 d7d5 e4d5 f6d5 e1g1 f8e7 f1e1 e8g8 h2h3 e7f6 c2c3 c8d7 d3e4 d8c7 e4d5 e6d5
info depth 25 seldepth 38 multipv 1 score cp 17 nodes 17369517 nps 2081677 time 8344 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 f8e8 c2c3 c8g4 b1d2 c7c5 d4c5 d6c5 f1e1 e8e1 d1e1 b8c6
info depth 26 seldepth 37 multipv 1 score cp 24 nodes 19888750 nps 2081937 time 9553 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 f8e8 c2c3 b8d7 b1d2 c7c6 d1c2 d7f8 f1e1 e8e1 a1e1 c8g4 h4g3
info depth 27 seldepth 36 multipv 1 score cp 20 nodes 24904774 nps 2078168 time 11984 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 c7c6 b1d2 c8g4 h2h3 g4h5 c2c4 g7g5 h4g3 d6g3 f2g3 d8c7 c4d5 c7g3
info depth 28 seldepth 40 multipv 1 score cp 23 nodes 43733722 nps 2064859 time 21180 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 f8e7 f1d3 g8f6 e1g1 e8g8 f1e1 h7h6 b1d2 e7d6 h2h3 b8c6 a2a3 c6e7 c2c4 c7c6 c4c5 d6c7 d2f1 a7a5 f1g3 f8e8
info depth 29 seldepth 40 multipv 1 score cp 17 nodes 61224031 nps 2058019 time 29749 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 f1e1 b8d7 b1d2 e8e1 d1e1 c7c6 h2h3 h7h6 g5h4 d8b6 a1b1 b6a5 c2c4 a5a2 c4c5 d6c7
info depth 30 seldepth 41 multipv 1 score cp 21 nodes 81932982 nps 2051812 time 39932 pv e2e4 e7e6 d2d4 d7d5 e4d5 e6d5 g1f3 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 f1e1 b8d7 b1d2 e8e1 d1e1 c7c6 h2h3 h7h6 g5h4 d8b6 a1b1 b6c7 c2c4 d5c4 d3c4 d6f8 e1e2
```

```
Score of ChessDotCpp3.76 vs ChessDotCpp3.75: 736 - 672 - 1592  [0.511] 3000
...      ChessDotCpp3.76 playing White: 648 - 87 - 765  [0.687] 1500
...      ChessDotCpp3.76 playing Black: 88 - 585 - 827  [0.334] 1500
...      White vs Black: 1233 - 175 - 1592  [0.676] 3000
Elo difference: 7.4 +/- 8.5, LOS: 95.6 %, DrawRatio: 53.1 %

Score of ChessDotCpp3.76 vs weiss2.0: 721 - 61 - 218  [0.830] 1000
...      ChessDotCpp3.76 playing White: 359 - 30 - 111  [0.829] 500
...      ChessDotCpp3.76 playing Black: 362 - 31 - 107  [0.831] 500
...      White vs Black: 390 - 392 - 218  [0.499] 1000
Elo difference: 275.5 +/- 22.5, LOS: 100.0 %, DrawRatio: 21.8 %

Score of ChessDotCpp3.76 vs seer2.5: 174 - 284 - 542  [0.445] 1000
...      ChessDotCpp3.76 playing White: 87 - 132 - 281  [0.455] 500
...      ChessDotCpp3.76 playing Black: 87 - 152 - 261  [0.435] 500
...      White vs Black: 239 - 219 - 542  [0.510] 1000
Elo difference: -38.4 +/- 14.5, LOS: 0.0 %, DrawRatio: 54.2 %
```

### 3.77

Reduce LMR multiplier

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   110
Best mates:    22

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   134
Best mates:    92

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   474
Best mates:    342

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1384
Best mates:    959
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 4 multipv 1 score cp 12 nodes 311 nps 311000 time 1 pv g2g3 g8f6 f1g2
info depth 4 seldepth 5 multipv 1 score cp 14 nodes 439 nps 439000 time 1 pv g2g3 e7e5 f1g2 g8f6
info depth 5 seldepth 6 multipv 1 score cp 21 nodes 930 nps 930000 time 1 pv c2c4 g8f6 b1c3 e7e5 g1f3
info depth 6 seldepth 9 multipv 1 score cp 27 nodes 2100 nps 1050000 time 2 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6
info depth 7 seldepth 9 multipv 1 score cp 22 nodes 4584 nps 1528000 time 3 pv c2c4 g7g6 d2d4 f8g7 b1c3 g8f6 g1f3
info depth 8 seldepth 11 multipv 1 score cp 16 nodes 7787 nps 1557400 time 5 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1 e8g8
info depth 9 seldepth 11 multipv 1 score cp 14 nodes 10350 nps 1478571 time 7 pv g1f3 g8f6 g2g3 g7g6 f1g2 f8g7 e1g1 e8g8 f1e1
info depth 10 seldepth 15 multipv 1 score cp 33 nodes 24122 nps 1723000 time 14 pv e2e4 c7c5 g1f3 g7g6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6
info depth 11 seldepth 14 multipv 1 score cp 32 nodes 34032 nps 1791157 time 19 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6 e4e5 f6d5 d2d4 c5d4 d1d4
info depth 12 seldepth 17 multipv 1 score cp 40 nodes 61371 nps 1805029 time 34 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5 e1g1 g7g6
info depth 13 seldepth 19 multipv 1 score cp 39 nodes 98228 nps 1889000 time 52 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 b5c6 b7c6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 14 seldepth 19 multipv 1 score cp 30 nodes 174258 nps 1957955 time 89 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 f1b5 g8e7 e1g1 e7g6 f1e1 f8e7 b5c6 b7c6
info depth 15 seldepth 22 multipv 1 score cp 30 nodes 284630 nps 1990419 time 143 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 429519 nps 2016521 time 213 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 665183 nps 2034198 time 327 pv e2e4 c7c5 g1f3 e7e6 c2c3 g8f6 e4e5 f6d5 f1e2 b8c6 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 26 multipv 1 score cp 23 nodes 1404001 nps 2043669 time 687 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 f1e2 g8f6 e1g1 f8e7 f1e1 e8g8 d2d4 f8e8 c2c4 d5c4 c1g5 b8c6 e2c4
info depth 19 seldepth 28 multipv 1 score cp 18 nodes 2302606 nps 2037704 time 1130 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 h7h6 h2h3 c7c6 b1d2 b8d7 c2c3
info depth 20 seldepth 29 multipv 1 score cp 24 nodes 3099903 nps 2036729 time 1522 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 c8d7 e2d2 h7h6 g5h4
info depth 21 seldepth 32 multipv 1 score cp 22 nodes 4619686 nps 2021744 time 2285 pv e2e4 e7e6 c2c4 c7c5 b1c3 b8c6 g1f3 e6e5 g2g3 d7d6 f1g2 f8e7 e1g1 g8f6 d2d3 a8b8 h2h3 e8g8 f3e1 f6e8 e1c2
info depth 22 seldepth 32 multipv 1 score cp 20 nodes 6473435 nps 2013510 time 3215 pv e2e4 e7e6 c2c4 c7c5 b1c3 b8c6 g1f3 e6e5 g2g3 g8f6 f1g2 g7g6 e1g1 f8g7 a1b1 d7d6 d2d3 e8g8 f3e1 f6e8 e1c2 e8c7
info depth 23 seldepth 32 multipv 1 score cp 20 nodes 8355951 nps 2015424 time 4146 pv e2e4 e7e6 c2c4 c7c5 b1c3 b8c6 g1f3 g8f6 f1e2 e6e5 e1g1 f8e7 d2d3 e8g8 f3e1 d7d6 f2f4 e5f4 c1f4 a7a6 g1h1 c6d4 e1c2
info depth 24 seldepth 33 multipv 1 score cp 20 nodes 11033531 nps 2014520 time 5477 pv e2e4 e7e6 c2c4 c7c5 b1c3 b8c6 g1f3 g8f6 f1e2 e6e5 e1g1 f8e7 d2d3 e8g8 f3e1 d7d6 f2f4 c8d7 f4f5 c6d4 e1c2 d7c6 g1h1 a7a6 c2d4 c5d4
info depth 25 seldepth 36 multipv 1 score cp 20 nodes 13461398 nps 2011866 time 6691 pv e2e4 e7e6 c2c4 c7c5 b1c3 b8c6 g1f3 g8f6 f1e2 e6e5 e1g1 f8e7 d2d3 e8g8 f3e1 d7d6 f2f4 c8d7 f4f5 c6d4 e1c2 d7c6 c1d2 f8e8 c2e3
info depth 26 seldepth 37 multipv 1 score cp 24 nodes 22089433 nps 1993991 time 11078 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7 b5d7 b8d7 e1g1 f8e7 d4c5 d7c5 d2b3 c5e4 f1e1 e8g8 c2c3 e7d6 c1e3 d8c7 h2h3 f8e8
info depth 27 seldepth 37 multipv 1 score cp 19 nodes 30654676 nps 1996787 time 15352 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7 b5d7 b8d7 e1g1 f8e7 d4c5 d7c5 d2b3 c5e4 c2c3 e8g8 c1f4 f8e8 d1c2 e7d6 f4d6 d8d6 f1e1
info depth 28 seldepth 40 multipv 1 score cp 20 nodes 39404078 nps 1990909 time 19792 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7 b5d7 b8d7 e1g1 f8e7 d4c5 d7c5 d2b3 c5e4 f1e1 e8g8 h2h3 d8c7 c1e3 f8e8 c2c3 h7h6 a1c1 e7d6
info depth 29 seldepth 40 multipv 1 score cp 20 nodes 54576384 nps 1986980 time 27467 pv e2e4 e7e6 c2c4 c7c5 g1f3 b8c6 f1e2 g8f6 b1c3 e6e5 a2a3 d7d6 d2d3 f8e7 e1g1 e8g8 h2h3 c6d4 b2b4 b7b6 g1h1 h7h6 f3d4 c5d4 c3d5 f6d5 c4d5 g8h7 c1d2
info depth 30 seldepth 41 multipv 1 score cp 24 nodes 79663330 nps 1989742 time 40037 pv e2e4 e7e6 d2d4 d7d5 b1d2 c7c5 e4d5 e6d5 g1f3 g8f6 f1b5 c8d7 b5d7 b8d7 e1g1 f8e7 d4c5 d7c5 d2b3 c5e4 f1e1 e8g8 c1e3 f8e8 d1d3 e4d6 c2c3 d6c4 d3c2 d8c7 a1d1 c4e3 e1e3
```

```
Score of ChessDotCpp3.77 vs ChessDotCpp3.76: 755 - 645 - 1600  [0.518] 3000
...      ChessDotCpp3.77 playing White: 644 - 94 - 762  [0.683] 1500
...      ChessDotCpp3.77 playing Black: 111 - 551 - 838  [0.353] 1500
...      White vs Black: 1195 - 205 - 1600  [0.665] 3000
Elo difference: 12.7 +/- 8.5, LOS: 99.8 %, DrawRatio: 53.3 %
```

### 3.78

* Full null move pruning
* Fix bug with penalizing best move for history updates

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   109
Best mates:    24

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   132
Best mates:    95

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   495
Best mates:    342

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1396
Best mates:    982
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 548 nps 548000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 868 nps 868000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1575 nps 787500 time 2 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4873 nps 1218250 time 4 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11645 nps 1663571 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 11 multipv 1 score cp 29 nodes 14881 nps 1653444 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 26 nodes 21852 nps 1680923 time 13 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6
info depth 11 seldepth 17 multipv 1 score cp 30 nodes 34914 nps 1745700 time 20 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 18 multipv 1 score cp 21 nodes 60550 nps 1834848 time 33 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e4e5 f6d5
info depth 13 seldepth 20 multipv 1 score cp 24 nodes 97588 nps 1913490 time 51 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 b1c3 b8c6 e1g1 g8f6 d2d4 c5d4 f3d4
info depth 14 seldepth 22 multipv 1 score cp 21 nodes 187409 nps 1993712 time 94 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e2b5 e8g8 b5c6 b7c6
info depth 15 seldepth 22 multipv 1 score cp 30 nodes 306308 nps 2028529 time 151 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 22 multipv 1 score cp 37 nodes 469136 nps 2057614 time 228 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d5f4 d2d4 f4e2 d1e2 c5d4 f3d4 c6d4 c3d4
info depth 17 seldepth 26 multipv 1 score cp 35 nodes 753782 nps 2082270 time 362 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 e1g1 e7c5 d4c6 d7c6
info depth 18 seldepth 26 multipv 1 score cp 37 nodes 1127537 nps 2103613 time 536 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d5f4 d2d4 f4e2 d1e2 c5d4 f3d4 c6d4 c3d4
info depth 19 seldepth 29 multipv 1 score cp 20 nodes 2035220 nps 2109036 time 965 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 f8e8 e1e8 d8e8 b1d2 c7c6 h2h3 b8d7
info depth 20 seldepth 29 multipv 1 score cp 25 nodes 3672016 nps 2100695 time 1748 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 f8e7 d2d4 c5d4 f3d4 d7d6 e1g1 g8f6 h2h3 e8g8 f1e1 a8b8 c1e3 c8d7
info depth 21 seldepth 28 multipv 1 score cp 25 nodes 4660362 nps 2100208 time 2219 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 b1c3 f8e7 d2d4 c5d4 f3d4 d7d6 e1g1 g8f6 h2h3 e8g8 f1e1 a8b8 c1e3 c8d7 d4c6 b7c6
info depth 22 seldepth 31 multipv 1 score cp 28 nodes 6233989 nps 2099693 time 2969 pv e2e4 c7c5 g1f3 e7e6 f1e2 d7d6 d2d4 c5d4 f3d4 g8f6 e2f3 f8e7 e1g1 e8g8 c2c4 a7a6 b1c3 d8c7 f3e2 b8c6 d4c6 b7c6
info depth 23 seldepth 39 multipv 1 score cp 22 nodes 9296095 nps 2092772 time 4442 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c1f4 a7a6 c2c4 f8e7 b1c3 e8g8 d1e2 f8e8 h2h3 f6h5 f4c1 h5f6 f1d1
info depth 24 seldepth 36 multipv 1 score cp 22 nodes 11980010 nps 2091482 time 5728 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c1f4 a7a6 c2c4 f8e7 b1c3 e8g8 d1e2 f8e8 h2h3 d8c7 f1c1 d7b8 d3d4 c5d4 f3d4
info depth 25 seldepth 37 multipv 1 score cp 18 nodes 25430234 nps 2074413 time 12259 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 g8f6 d2d3 e7e6 c1f4 a7a6 c2c4 f8e7 b1c3 e8g8 d1e2 h7h6 h2h3 d7b8 f1d1 b8c6 d3d4 c5d4 f3d4
info depth 26 seldepth 37 multipv 1 score cp 22 nodes 30869904 nps 2073614 time 14887 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 c2c4 g8f6 b1c3 e7e6 e1g1 f8e7 d2d4 c5d4 f3d4 e8g8 b2b3 a7a6 c1b2 f8e8 d1e2 e7f8 a1d1 d8c7 h2h3 h7h6
info depth 27 seldepth 39 multipv 1 score cp 22 nodes 50646367 nps 2064502 time 24532 pv g1f3 g8f6 c2c4 e7e6 g2g3 d7d5 d2d4 d5c4 d1a4 b8d7 f1g2 c7c5 a4c4 a7a6 c4c2 b7b5 f3e5 f6d5 e1g1 c5d4 c2c6 c8b7 c6b7 d7e5 b1d2 f8e7 d2b3 e8g8 g2d5 e6d5 b3d4
info depth 28 seldepth 38 multipv 1 score cp 22 nodes 66514274 nps 2060094 time 32287 pv g1f3 g8f6 c2c4 e7e6 g2g3 d7d5 d2d4 d5c4 d1a4 b8d7 f1g2 c7c5 a4c4 a7a6 c4c2 b7b5 f3e5 f6d5 e1g1 c5d4 c2c6 c8b7 c6b7 d7e5 b1d2 f8e7 d2b3 e8g8 g2d5 e6d5 b3d4
info depth 29 seldepth 41 multipv 1 score cp 16 nodes 150127798 nps 2055306 time 73044 pv d2d4 g8f6 g1f3 g7g6 c2c4 f8g7 b1c3 d7d5 d1b3 d5c4 b3c4 e8g8 e2e4 c8e6 d4d5 e6c8 f1e2 c7c6 e1g1 c6d5 e4d5 e7e6 d5e6 c8e6 c4h4 f6d7 h4g3
info depth 30 seldepth 45 multipv 1 score cp 24 nodes 242058060 nps 2062912 time 117338 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 c2c4 g8f6 b1c3 e7e6 e1g1 f8e7 d2d4 c5d4 f3d4 e8g8 b2b3 a7a6 c1b2 f8e8 d1e2 h7h6 a1d1 e7f8 h2h3 a8c8 d4c2 d8c7
```

```
Score of ChessDotCpp3.78 vs ChessDotCpp3.77: 712 - 649 - 1639  [0.510] 3000
...      ChessDotCpp3.78 playing White: 624 - 80 - 796  [0.681] 1500
...      ChessDotCpp3.78 playing Black: 88 - 569 - 843  [0.340] 1500
...      White vs Black: 1193 - 168 - 1639  [0.671] 3000
Elo difference: 7.3 +/- 8.4, LOS: 95.6 %, DrawRatio: 54.6 %
```

### 3.79

Move history pruning

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 548 nps 548000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 868 nps 868000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1575 nps 787500 time 2 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4873 nps 1218250 time 4 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11644 nps 1663428 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 11 multipv 1 score cp 29 nodes 14880 nps 1653333 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 26 nodes 21846 nps 1680461 time 13 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6
info depth 11 seldepth 17 multipv 1 score cp 30 nodes 33504 nps 1675200 time 20 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 17 multipv 1 score cp 35 nodes 55099 nps 1836633 time 30 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1 f8g7 b5c6 d7c6
info depth 13 seldepth 23 multipv 1 score cp 33 nodes 119549 nps 1897603 time 63 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 e5f7 e8f7 d1h5 g7g6 h5d5 f7g7 d5e4 b8c6 d2d4
info depth 14 seldepth 20 multipv 1 score cp 26 nodes 181768 nps 1913347 time 95 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 d8f6 d2d4 e5d4 e4e5 f6e7 d1d4
info depth 15 seldepth 24 multipv 1 score cp 30 nodes 275543 nps 1940443 time 142 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8c5 e1g1 g8f6 b1c3 e8g8 f1e1 d7d6 c3a4 f6d7 a4c5 d7c5
info depth 16 seldepth 27 multipv 1 score cp 23 nodes 553191 nps 1934234 time 286 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 d2d3 f8d6 e1g1 a7a6 b5c6 d7c6 f1e1 e8g8 c1g5 f8e8
info depth 17 seldepth 27 multipv 1 score cp 30 nodes 1178881 nps 1955026 time 603 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c2c3 f8e8 c1g5 c7c6 f1e1
info depth 18 seldepth 25 multipv 1 score cp 19 nodes 1726077 nps 1968160 time 877 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 h7h6 h2h3 b8c6 c2c3 f8e8
info depth 19 seldepth 27 multipv 1 score cp 20 nodes 2532733 nps 1977153 time 1281 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 c2c3 b8d7 b1d2 h7h6 g5h4
info depth 20 seldepth 28 multipv 1 score cp 20 nodes 3264829 nps 1989536 time 1641 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 c2c3 c8g4 h2h3 g4h5 b1d2 c7c6
info depth 21 seldepth 31 multipv 1 score cp 19 nodes 4774645 nps 1996089 time 2392 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 f8e8 b1d2 h7h6 g5h4 c8g4 f1e1 e8e1 d1e1 b8d7
info depth 22 seldepth 32 multipv 1 score cp 16 nodes 6914728 nps 1990422 time 3474 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 b8d7 c2c3 c7c5 e2d1 d8b6 b1d2 b6b2
info depth 23 seldepth 36 multipv 1 score cp 24 nodes 8661861 nps 1990774 time 4351 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 b8d7 c2c3 h7h6 g5h4 e7f8 e2c2 e8e1 f3e1
info depth 24 seldepth 34 multipv 1 score cp 18 nodes 11602189 nps 1982602 time 5852 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 b8d7 c2c3 e7d6 e2e8 d8e8 e1e8 f6e8 b1d2 d7b6 a1e1
info depth 25 seldepth 35 multipv 1 score cp 25 nodes 17319644 nps 1975099 time 8769 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 b8d7 b1d2 e7f8 e2e8 d8e8 e1e8 f6e8 a1e1 d7f6
info depth 26 seldepth 39 multipv 1 score cp 18 nodes 39083038 nps 1980291 time 19736 pv g1f3 g8f6 d2d4 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 e1g1 b8d7 d1c2 c7c6 f1c1 f8e8 b2b3 b7b6 d2f4 c8b7 b1c3 e7a3 c1b1 a7a5 e2e4 d5e4 c3e4 f6e4 c2e4
info depth 27 seldepth 39 multipv 1 score cp 21 nodes 50549989 nps 1985233 time 25463 pv g1f3 g8f6 d2d4 e7e6 c2c4 d7d5 g2g3 f8b4 c1d2 b4e7 f1g2 e8g8 e1g1 b8d7 d1c2 c7c6 f1c1 f8e8 e2e3 b7b6 c4d5 c6d5 b1c3 c8a6 c2a4 a6c4 d2e1 d8b8
info depth 28 seldepth 40 multipv 1 score cp 17 nodes 100245605 nps 1993152 time 50295 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 g2g3 f8b4 c1d2 b4e7 f1g2 c7c6 e1g1 e8g8 d1c2 b7b6 c4d5 c6d5 f1c1 c8b7 c2a4 a7a6 f3e5 f6d7 e5d3 b6b5 a4b3 d7b6 e2e3
info depth 29 seldepth 40 multipv 1 score cp 19 nodes 121417573 nps 1994997 time 60861 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 g2g3 f8b4 c1d2 b4e7 f1g2 c7c6 e1g1 b8d7 d1c2 e8g8 f1c1 b7b6 c2a4 c8b7 c4d5 c6d5 d2f4 a7a6 c1c7 b6b5 a4a5 a8c8 e2e3 c8c7 f4c7
info depth 30 seldepth 43 multipv 1 score cp 18 nodes 173076326 nps 1987623 time 87077 pv g1f3 d7d5 d2d4 g8f6 c2c4 e7e6 g2g3 f8b4 c1d2 b4e7 f1g2 c7c6 e1g1 b8d7 d1c2 e8g8 f1c1 b7b6 c2a4 c8b7 c4d5 c6d5 d2f4 a7a6 c1c7 b6b5 a4a5 a8c8 e2e3 h7h6 b1d2
```

```
Score of ChessDotCpp3.79 vs ChessDotCpp3.78: 496 - 448 - 1056  [0.512] 2000
...      ChessDotCpp3.79 playing White: 438 - 55 - 507  [0.692] 1000
...      ChessDotCpp3.79 playing Black: 58 - 393 - 549  [0.333] 1000
...      White vs Black: 831 - 113 - 1056  [0.679] 2000
Elo difference: 8.3 +/- 10.4, LOS: 94.1 %, DrawRatio: 52.8 %

Score of ChessDotCpp3.79 vs weiss2.0: 735 - 58 - 207  [0.839] 1000
...      ChessDotCpp3.79 playing White: 379 - 23 - 99  [0.855] 501
...      ChessDotCpp3.79 playing Black: 356 - 35 - 108  [0.822] 499
...      White vs Black: 414 - 379 - 207  [0.517] 1000
Elo difference: 286.1 +/- 23.0, LOS: 100.0 %, DrawRatio: 20.7 %

Score of ChessDotCpp3.79 vs seer2.5: 184 - 251 - 565  [0.467] 1000
...      ChessDotCpp3.79 playing White: 101 - 118 - 281  [0.483] 500
...      ChessDotCpp3.79 playing Black: 83 - 133 - 284  [0.450] 500
...      White vs Black: 234 - 201 - 565  [0.516] 1000
Elo difference: -23.3 +/- 14.2, LOS: 0.1 %, DrawRatio: 56.5 %
```

### 3.80

Allow storing mate values in the TT

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   108
Best mates:    24

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   133
Best mates:    97

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566                                                    
Found mates:   480                                                     
Best mates:    339

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1392
Best mates:    980
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 548 nps 548000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 868 nps 868000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1575 nps 787500 time 2 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4873 nps 1218250 time 4 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11644 nps 1663428 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 11 multipv 1 score cp 29 nodes 14880 nps 1488000 time 10 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 26 nodes 21846 nps 1560428 time 14 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6
info depth 11 seldepth 17 multipv 1 score cp 30 nodes 33504 nps 1675200 time 20 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 17 multipv 1 score cp 35 nodes 55099 nps 1777387 time 31 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1 f8g7 b5c6 d7c6
info depth 13 seldepth 23 multipv 1 score cp 33 nodes 119549 nps 1867953 time 64 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 e5f7 e8f7 d1h5 g7g6 h5d5 f7g7 d5e4 b8c6 d2d4
info depth 14 seldepth 20 multipv 1 score cp 26 nodes 181768 nps 1913347 time 95 pv e2e4 e7e5 g1f3 b8c6 f1b5 a7a6 b5c6 d7c6 e1g1 d8f6 d2d4 e5d4 e4e5 f6e7 d1d4
info depth 15 seldepth 24 multipv 1 score cp 30 nodes 275543 nps 1940443 time 142 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8c5 e1g1 g8f6 b1c3 e8g8 f1e1 d7d6 c3a4 f6d7 a4c5 d7c5
info depth 16 seldepth 27 multipv 1 score cp 23 nodes 553192 nps 1961673 time 282 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 d2d3 f8d6 e1g1 a7a6 b5c6 d7c6 f1e1 e8g8 c1g5 f8e8
info depth 17 seldepth 27 multipv 1 score cp 30 nodes 1167030 nps 1984744 time 588 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c2c3 f8e8 c1g5 c7c6 f1e1
info depth 18 seldepth 27 multipv 1 score cp 19 nodes 1671506 nps 1989888 time 840 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 h7h6 h2h3 b8c6 c2c3 f8e8
info depth 19 seldepth 27 multipv 1 score cp 16 nodes 2372616 nps 1990449 time 1192 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 f1e1 h7h6 h2h3 f8e8 e1e8 d8e8 c2c3 c8d7
info depth 20 seldepth 28 multipv 1 score cp 18 nodes 3369389 nps 2009176 time 1677 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 c8g4 h2h3 g4h5 c2c4 d5c4 d3c4
info depth 21 seldepth 29 multipv 1 score cp 15 nodes 4999263 nps 2016645 time 2479 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 e1g1 e8g8 c1g5 h7h6 g5h4 f8e8 h2h3 b8d7 b1d2 c7c5 c2c3
info depth 22 seldepth 31 multipv 1 score cp 20 nodes 8029125 nps 2005776 time 4003 pv e2e4 c7c5 g1f3 e7e6 f1d3 g7g6 c2c3 f8g7 d3c2 d7d5 e4d5 e6d5 d2d4 c5d4 f3d4 b8c6 c1e3 g8e7 e1g1 e8g8 f1e1 c6d4 e3d4
info depth 23 seldepth 30 multipv 1 score cp 23 nodes 10193492 nps 2003437 time 5088 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 b7c6 e1g1 d7d5 b1d2 f8e7 c2c4 e8g8 b2b3 f6d7 c1b2 c8a6 f1e1
info depth 24 seldepth 37 multipv 1 score cp 23 nodes 15752371 nps 1986427 time 7930 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 e7e6 c2c4 f8e7 b1c3 g8f6 h2h3 a7a6 d2d3 e8g8 g1h1 d8c7 c1e3 d7b8 a1b1 b8c6 a2a3 f6d7
info depth 25 seldepth 36 multipv 1 score cp 17 nodes 20414873 nps 1990723 time 10255 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 e7e6 c2c4 f8e7 b1c3 g8f6 h2h3 a7a6 d2d3 e8g8 c1f4 d8c7 g1h1 d7b8 a2a3 f6d7 a1b1 d7e5 f4g3 e5f3 d1f3
info depth 26 seldepth 36 multipv 1 score cp 17 nodes 25964730 nps 1993147 time 13027 pv e2e4 c7c5 g1f3 d7d6 f1b5 c8d7 b5d7 b8d7 e1g1 e7e6 c2c4 f8e7 b1c3 g8f6 h2h3 a7a6 d2d3 e8g8 c1f4 d8c7 g1h1 d7b8 a1b1 f6h5 f4h2 b8c6 a2a3 e7f6
info depth 27 seldepth 39 multipv 1 score cp 23 nodes 46636868 nps 1989203 time 23445 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 f1d3 b8c6 d4c6 b7c6 c1f4 c8a6 e1g1 a6d3 d1d3 d7d5 e4d5 c6d5 c2c4 a8c8 c4d5 f6d5 f4g3 f8e7 f1e1
info depth 28 seldepth 40 multipv 1 score cp 26 nodes 62586609 nps 1989023 time 31466 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4b5 d7d6 c1f4 e6e5 f4g5 a7a6 b5a3 b7b5 g5f6 d8f6 c3d5 f6d8 f1e2 c8b7 e1g1 c6e7 c2c4 e7d5 c4d5
info depth 29 seldepth 42 multipv 1 score cp 26 nodes 83840039 nps 1987154 time 42191 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4b5 d7d6 c1f4 e6e5 f4g5 a7a6 b5a3 b7b5 g5f6 d8f6 c3d5 f6d8 f1e2 c8b7 e1g1 c6e7 c2c4 e7d5 c4d5
info depth 30 seldepth 39 multipv 1 score cp 27 nodes 103631971 nps 1978426 time 52381 pv e2e4 c7c5 g1f3 e7e6 d2d4 c5d4 f3d4 g8f6 b1c3 b8c6 d4b5 d7d6 c1f4 e6e5 f4g5 a7a6 b5a3 b7b5 c3d5 f8e7 g5f6 e7f6 f1e2 e8g8 e1g1 c6d4 c2c3 d4e2 d1e2 f6g5 a3c2
```

```
Score of ChessDotCpp3.80 vs ChessDotCpp3.79: 1173 - 1069 - 2758  [0.510] 5000
...      ChessDotCpp3.80 playing White: 994 - 152 - 1354  [0.668] 2500
...      ChessDotCpp3.80 playing Black: 179 - 917 - 1404  [0.352] 2500
...      White vs Black: 1911 - 331 - 2758  [0.658] 5000
Elo difference: 7.2 +/- 6.4, LOS: 98.6 %, DrawRatio: 55.2 %

Score of ChessDotCpp3.80 vs weiss2.0: 725 - 65 - 210  [0.830] 1000
...      ChessDotCpp3.80 playing White: 376 - 29 - 95  [0.847] 500
...      ChessDotCpp3.80 playing Black: 349 - 36 - 115  [0.813] 500
...      White vs Black: 412 - 378 - 210  [0.517] 1000
Elo difference: 275.5 +/- 22.8, LOS: 100.0 %, DrawRatio: 21.0 %

Score of ChessDotCpp3.80 vs seer2.5: 550 - 772 - 1678  [0.463] 3000
...      ChessDotCpp3.80 playing White: 272 - 369 - 859  [0.468] 1500
...      ChessDotCpp3.80 playing Black: 278 - 403 - 819  [0.458] 1500
...      White vs Black: 675 - 647 - 1678  [0.505] 3000
Elo difference: -25.8 +/- 8.2, LOS: 0.0 %, DrawRatio: 55.9 %
```

### 3.81

Simplify qsearch SEE pruning

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 1000 nodes
Total fens:    6566
Found mates:   108
Best mates:    25

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 10000 nodes
Total fens:    6566
Found mates:   127
Best mates:    93

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 100000 nodes
Total fens:    6566
Found mates:   487
Best mates:    344

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2-old.exe with 1000000 nodes
Total fens:    6566
Found mates:   1403
Best mates:    1011
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 549 nps 549000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 869 nps 869000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1577 nps 1577000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4905 nps 1635000 time 3 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11774 nps 1682000 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 12 multipv 1 score cp 29 nodes 15018 nps 1668666 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 20 nodes 23672 nps 1690857 time 14 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6 e4e5 f6d5
info depth 11 seldepth 19 multipv 1 score cp 30 nodes 41568 nps 1807304 time 23 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 16 multipv 1 score cp 21 nodes 68300 nps 1897222 time 36 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e4e5 f6d5
info depth 13 seldepth 21 multipv 1 score cp 27 nodes 110380 nps 1936491 time 57 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 c2c4 a8b8 f1e1 g8f6 b1c3
info depth 14 seldepth 21 multipv 1 score cp 22 nodes 220548 nps 2023376 time 109 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 b1c3 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 seldepth 23 multipv 1 score cp 30 nodes 378528 nps 2068459 time 183 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 584199 nps 2093903 time 279 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 916454 nps 2101958 time 436 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 29 multipv 1 score cp 33 nodes 1514068 nps 2105796 time 719 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 27 multipv 1 score cp 28 nodes 2325537 nps 2102655 time 1106 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 e1g1 g8f6 d2d4 f8e7 c1g5 e8g8 g5f6 e7f6 d4c5
info depth 20 seldepth 29 multipv 1 score cp 24 nodes 3593714 nps 2106514 time 1706 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5 f6d7 d1d4 f8e8
info depth 21 seldepth 31 multipv 1 score cp 23 nodes 5053111 nps 2098468 time 2408 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e7c5 f1e1 c8e6 b5c6 b7c6 b1c3 e8g8 c3a4 c5e7
info depth 22 seldepth 34 multipv 1 score cp 29 nodes 7100662 nps 2089659 time 3398 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 23 seldepth 32 multipv 1 score cp 29 nodes 8599117 nps 2087671 time 4119 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 24 seldepth 39 multipv 1 score cp 22 nodes 12066203 nps 2080021 time 5801 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 17668660 nps 2069414 time 8538 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2 c8d7
info depth 26 seldepth 37 multipv 1 score cp 21 nodes 22950536 nps 2062042 time 11130 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 h2h3 h7h6 c1e3 c8d7 f1d1
info depth 27 seldepth 37 multipv 1 score cp 22 nodes 28294345 nps 2062119 time 13721 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 d4e2 d1e2 c8d7 f1d1
info depth 28 seldepth 41 multipv 1 score cp 25 nodes 37438122 nps 2060435 time 18170 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 a7a6 c1e3 c8d7 d1d2 d7c6
info depth 29 seldepth 41 multipv 1 score cp 19 nodes 61697102 nps 2051646 time 30072 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1f4 d7d6 d4b3 e6e5 f4g5 f8e7 g5f6 e7f6 f1c4 e8g8 e1g1 a8b8
info depth 30 seldepth 44 multipv 1 score cp 22 nodes 101486734 nps 2038786 time 49778 pv e2e4 c7c5 g1f3 d7d6 b1c3 e7e5 h2h3 f8e7 f1c4 g8f6 e1g1 e8g8 d2d3 b8c6 a2a3 c6d4 c3d5 c8e6 d5e7 d8e7 f3d4 c5d4 c4e6 f7e6 c2c3 d4c3 b2c3 e7c7 d1b3 f8f7 f1e1
```

```
Score of ChessDotCpp3.81 vs ChessDotCpp3.80: 352 - 344 - 804  [0.503] 1500
...      ChessDotCpp3.81 playing White: 306 - 48 - 397  [0.672] 751
...      ChessDotCpp3.81 playing Black: 46 - 296 - 407  [0.333] 749
...      White vs Black: 602 - 94 - 804  [0.669] 1500
Elo difference: 1.9 +/- 12.0, LOS: 61.9 %, DrawRatio: 53.6 %
```

### 3.82

Fix mate flags in TT

```
Score of ChessDotCpp3.82 vs ChessDotCpp3.81: 220 - 213 - 567  [0.503] 1000
...      ChessDotCpp3.82 playing White: 181 - 21 - 300  [0.659] 502
...      ChessDotCpp3.82 playing Black: 39 - 192 - 267  [0.346] 498
...      White vs Black: 373 - 60 - 567  [0.656] 1000
Elo difference: 2.4 +/- 14.2, LOS: 63.2 %, DrawRatio: 56.7 %
```

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 549 nps 549000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 869 nps 869000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1577 nps 788500 time 2 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4905 nps 1635000 time 3 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11774 nps 1682000 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 12 multipv 1 score cp 29 nodes 15018 nps 1668666 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 20 nodes 23672 nps 1820923 time 13 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6 e4e5 f6d5
info depth 11 seldepth 19 multipv 1 score cp 30 nodes 41568 nps 1889454 time 22 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 16 multipv 1 score cp 21 nodes 68300 nps 1897222 time 36 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e4e5 f6d5
info depth 13 seldepth 21 multipv 1 score cp 27 nodes 110380 nps 1971071 time 56 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 c2c4 a8b8 f1e1 g8f6 b1c3
info depth 14 seldepth 21 multipv 1 score cp 22 nodes 220548 nps 2042111 time 108 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 b1c3 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 seldepth 23 multipv 1 score cp 30 nodes 378528 nps 2079824 time 182 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 584199 nps 2101435 time 278 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 916454 nps 2111645 time 434 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 29 multipv 1 score cp 33 nodes 1514068 nps 2114620 time 716 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 27 multipv 1 score cp 28 nodes 2325537 nps 2123778 time 1095 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 e1g1 g8f6 d2d4 f8e7 c1g5 e8g8 g5f6 e7f6 d4c5
info depth 20 seldepth 29 multipv 1 score cp 24 nodes 3593714 nps 2116439 time 1698 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5 f6d7 d1d4 f8e8
info depth 21 seldepth 31 multipv 1 score cp 23 nodes 5053111 nps 2117816 time 2386 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e7c5 f1e1 c8e6 b5c6 b7c6 b1c3 e8g8 c3a4 c5e7
info depth 22 seldepth 34 multipv 1 score cp 29 nodes 7100662 nps 2110779 time 3364 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 23 seldepth 32 multipv 1 score cp 29 nodes 8599117 nps 2111767 time 4072 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 24 seldepth 39 multipv 1 score cp 22 nodes 12066203 nps 2100296 time 5745 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 17668660 nps 2096423 time 8428 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2 c8d7
info depth 26 seldepth 37 multipv 1 score cp 21 nodes 22950536 nps 2093644 time 10962 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 h2h3 h7h6 c1e3 c8d7 f1d1
info depth 27 seldepth 37 multipv 1 score cp 22 nodes 28294345 nps 2094636 time 13508 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 d4e2 d1e2 c8d7 f1d1
info depth 28 seldepth 41 multipv 1 score cp 25 nodes 37438122 nps 2095495 time 17866 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 a7a6 c1e3 c8d7 d1d2 d7c6
info depth 29 seldepth 41 multipv 1 score cp 19 nodes 61697102 nps 2090576 time 29512 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1f4 d7d6 d4b3 e6e5 f4g5 f8e7 g5f6 e7f6 f1c4 e8g8 e1g1 a8b8
info depth 30 seldepth 44 multipv 1 score cp 22 nodes 101486734 nps 2076837 time 48866 pv e2e4 c7c5 g1f3 d7d6 b1c3 e7e5 h2h3 f8e7 f1c4 g8f6 e1g1 e8g8 d2d3 b8c6 a2a3 c6d4 c3d5 c8e6 d5e7 d8e7 f3d4 c5d4 c4e6 f7e6 c2c3 d4c3 b2c3 e7c7 d1b3 f8f7 f1e1
```

```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   109
Best mates:    25

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   124
Best mates:    93

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   482
Best mates:    338

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1415
Best mates:    1001
```

### 3.83

Simplify nnue accumulator resets

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 549 nps 549000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 869 nps 869000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1577 nps 1577000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4905 nps 1635000 time 3 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11774 nps 1682000 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 12 multipv 1 score cp 29 nodes 15018 nps 1668666 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 20 nodes 23672 nps 1820923 time 13 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6 e4e5 f6d5
info depth 11 seldepth 19 multipv 1 score cp 30 nodes 41568 nps 1889454 time 22 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 16 multipv 1 score cp 21 nodes 68300 nps 1897222 time 36 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e4e5 f6d5
info depth 13 seldepth 21 multipv 1 score cp 27 nodes 110380 nps 1971071 time 56 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 c2c4 a8b8 f1e1 g8f6 b1c3
info depth 14 seldepth 21 multipv 1 score cp 22 nodes 220548 nps 2023376 time 109 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 b1c3 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 seldepth 23 multipv 1 score cp 30 nodes 378528 nps 2057217 time 184 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 584199 nps 2079000 time 281 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 916454 nps 2101958 time 436 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 29 multipv 1 score cp 33 nodes 1514068 nps 2114620 time 716 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 27 multipv 1 score cp 28 nodes 2325537 nps 2117975 time 1098 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 e1g1 g8f6 d2d4 f8e7 c1g5 e8g8 g5f6 e7f6 d4c5
info depth 20 seldepth 29 multipv 1 score cp 24 nodes 3593714 nps 2115193 time 1699 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5 f6d7 d1d4 f8e8
info depth 21 seldepth 31 multipv 1 score cp 23 nodes 5053111 nps 2101085 time 2405 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e7c5 f1e1 c8e6 b5c6 b7c6 b1c3 e8g8 c3a4 c5e7
info depth 22 seldepth 34 multipv 1 score cp 29 nodes 7100662 nps 2089659 time 3398 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 23 seldepth 32 multipv 1 score cp 29 nodes 8599117 nps 2092242 time 4110 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 24 seldepth 39 multipv 1 score cp 22 nodes 12066203 nps 2086134 time 5784 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 17668660 nps 2074760 time 8516 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2 c8d7
info depth 26 seldepth 37 multipv 1 score cp 21 nodes 22950536 nps 2069480 time 11090 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 h2h3 h7h6 c1e3 c8d7 f1d1
info depth 27 seldepth 37 multipv 1 score cp 22 nodes 28294345 nps 2071176 time 13661 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 d4e2 d1e2 c8d7 f1d1
info depth 28 seldepth 41 multipv 1 score cp 25 nodes 37438122 nps 2071494 time 18073 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 a7a6 c1e3 c8d7 d1d2 d7c6
info depth 29 seldepth 41 multipv 1 score cp 19 nodes 61697102 nps 2065244 time 29874 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1f4 d7d6 d4b3 e6e5 f4g5 f8e7 g5f6 e7f6 f1c4 e8g8 e1g1 a8b8
info depth 30 seldepth 44 multipv 1 score cp 22 nodes 101486734 nps 2051107 time 49479 pv e2e4 c7c5 g1f3 d7d6 b1c3 e7e5 h2h3 f8e7 f1c4 g8f6 e1g1 e8g8 d2d3 b8c6 a2a3 c6d4 c3d5 c8e6 d5e7 d8e7 f3d4 c5d4 c4e6 f7e6 c2c3 d4c3 b2c3 e7c7 d1b3 f8f7 f1e1
```

```
Score of ChessDotCpp3.83 vs ChessDotCpp3.82: 224 - 229 - 547  [0.497] 1000
...      ChessDotCpp3.83 playing White: 193 - 42 - 264  [0.651] 499
...      ChessDotCpp3.83 playing Black: 31 - 187 - 283  [0.344] 501
...      White vs Black: 380 - 73 - 547  [0.653] 1000
Elo difference: -1.7 +/- 14.5, LOS: 40.7 %, DrawRatio: 54.7 %
```

### 3.84

Optimize pin detection

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 549 nps 549000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 869 nps 869000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1577 nps 788500 time 2 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4905 nps 1635000 time 3 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11774 nps 1682000 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 12 multipv 1 score cp 29 nodes 15018 nps 1668666 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 20 nodes 23672 nps 1820923 time 13 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6 e4e5 f6d5
info depth 11 seldepth 19 multipv 1 score cp 30 nodes 41568 nps 1889454 time 22 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 16 multipv 1 score cp 21 nodes 68300 nps 1951428 time 35 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e4e5 f6d5
info depth 13 seldepth 21 multipv 1 score cp 27 nodes 110380 nps 2006909 time 55 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 c2c4 a8b8 f1e1 g8f6 b1c3
info depth 14 seldepth 21 multipv 1 score cp 22 nodes 220548 nps 2061196 time 107 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 b1c3 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 seldepth 23 multipv 1 score cp 30 nodes 378528 nps 2102933 time 180 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 584199 nps 2109021 time 277 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 916454 nps 2121421 time 432 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 29 multipv 1 score cp 33 nodes 1514068 nps 2141538 time 707 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 27 multipv 1 score cp 28 nodes 2325537 nps 2149294 time 1082 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 e1g1 g8f6 d2d4 f8e7 c1g5 e8g8 g5f6 e7f6 d4c5
info depth 20 seldepth 29 multipv 1 score cp 24 nodes 3593714 nps 2153213 time 1669 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5 f6d7 d1d4 f8e8
info depth 21 seldepth 31 multipv 1 score cp 23 nodes 5053111 nps 2153008 time 2347 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e7c5 f1e1 c8e6 b5c6 b7c6 b1c3 e8g8 c3a4 c5e7
info depth 22 seldepth 34 multipv 1 score cp 29 nodes 7100662 nps 2145215 time 3310 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 23 seldepth 32 multipv 1 score cp 29 nodes 8599117 nps 2149241 time 4001 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 24 seldepth 39 multipv 1 score cp 22 nodes 12066203 nps 2141296 time 5635 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 17668660 nps 2134411 time 8278 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2 c8d7
info depth 26 seldepth 37 multipv 1 score cp 21 nodes 22950536 nps 2130177 time 10774 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 h2h3 h7h6 c1e3 c8d7 f1d1
info depth 27 seldepth 37 multipv 1 score cp 22 nodes 28294345 nps 2131400 time 13275 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 d4e2 d1e2 c8d7 f1d1
info depth 28 seldepth 41 multipv 1 score cp 25 nodes 37438122 nps 2130555 time 17572 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 a7a6 c1e3 c8d7 d1d2 d7c6
info depth 29 seldepth 41 multipv 1 score cp 19 nodes 61697102 nps 2124263 time 29044 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1f4 d7d6 d4b3 e6e5 f4g5 f8e7 g5f6 e7f6 f1c4 e8g8 e1g1 a8b8
info depth 30 seldepth 44 multipv 1 score cp 22 nodes 101486734 nps 2112326 time 48045 pv e2e4 c7c5 g1f3 d7d6 b1c3 e7e5 h2h3 f8e7 f1c4 g8f6 e1g1 e8g8 d2d3 b8c6 a2a3 c6d4 c3d5 c8e6 d5e7 d8e7 f3d4 c5d4 c4e6 f7e6 c2c3 d4c3 b2c3 e7c7 d1b3 f8f7 f1e1
```

```
Score of ChessDotCpp3.84 vs seer2.5: 182 - 259 - 559  [0.462] 1000
...      ChessDotCpp3.84 playing White: 92 - 127 - 281  [0.465] 500
...      ChessDotCpp3.84 playing Black: 90 - 132 - 278  [0.458] 500
...      White vs Black: 224 - 217 - 559  [0.503] 1000
Elo difference: -26.8 +/- 14.3, LOS: 0.0 %, DrawRatio: 55.9 %
```

## 3.85 ChessDotCpp classical

Classical:
```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   99
Best mates:    21

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   132
Best mates:    81

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   531
Best mates:    332

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1468
Best mates:    958
```

NNUE:
```
Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000 nodes
Total fens:    6566
Found mates:   109
Best mates:    25

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 10000 nodes
Total fens:    6566
Found mates:   124
Best mates:    93

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 100000 nodes
Total fens:    6566
Found mates:   482
Best mates:    338

Using C:/shared/cdcpp/out/chessdotcpp_x86-64-avx2.exe with 1000000 nodes
Total fens:    6566
Found mates:   1415
Best mates:    1001
```

Classical:
```
info depth 1 seldepth 1 multipv 1 score cp 41 nodes 22 nps 22000 time 1 pv b1c3
info depth 2 seldepth 2 multipv 1 score cp 25 nodes 72 nps 72000 time 1 pv e2e3 b8c6
info depth 3 seldepth 3 multipv 1 score cp 24 nodes 174 nps 174000 time 1 pv b1c3 d7d5 e2e3
info depth 4 seldepth 7 multipv 1 score cp 9 nodes 534 nps 534000 time 1 pv g1f3 d7d5 e2e3 e7e6
info depth 5 seldepth 8 multipv 1 score cp 25 nodes 1136 nps 1136000 time 1 pv d2d4 d7d5 b1c3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 15 nodes 1871 nps 935500 time 2 pv d2d4 d7d5 g1f3 g8f6 e2e3 e7e6
info depth 7 seldepth 11 multipv 1 score cp 22 nodes 3847 nps 1282333 time 3 pv e2e3 e7e6 g1f3 d7d5 d2d4 g8f6 f1b5 c8d7
info depth 8 seldepth 17 multipv 1 score cp 20 nodes 11169 nps 1861500 time 6 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 g8f6
info depth 9 seldepth 15 multipv 1 score cp 35 nodes 13649 nps 1706125 time 8 pv e2e4 e7e5 g1f3 b8c6 d2d4 e5d4 f3d4 c6d4 d1d4
info depth 10 seldepth 18 multipv 1 score cp 27 nodes 23696 nps 1822769 time 13 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 d7d5 d4c6 b7c6
info depth 11 seldepth 17 multipv 1 score cp 27 nodes 32886 nps 1934470 time 17 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 d7d5 d4c6 b7c6
info depth 12 seldepth 20 multipv 1 score cp 33 nodes 56355 nps 1943275 time 29 pv e2e4 c7c5 g1f3 e7e6 c2c3 b8c6 d2d4 c5d4 c3d4 f8b4 b1c3 d7d5 e4d5 e6d5
info depth 13 seldepth 21 multipv 1 score cp 21 nodes 110605 nps 1975089 time 56 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 c5d4 c3d4 f8b4 c1d2 b8c6 g1f3 g8e7
info depth 14 seldepth 22 multipv 1 score cp 24 nodes 158536 nps 2006784 time 79 pv e2e4 e7e6 d2d4 d7d5 e4e5 c7c5 c2c3 b8c6 g1f3 c8d7 c1g5 f8e7 g5e7 g8e7 d4c5
info depth 15 seldepth 21 multipv 1 score cp 25 nodes 225861 nps 2016616 time 112 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 b1c3 e8g8 e1g1 f8e8 f1e1
info depth 16 seldepth 23 multipv 1 score cp 32 nodes 373656 nps 2041836 time 183 pv e2e4 d7d5 e4d5 c7c6 d5c6 b8c6 g1f3 e7e5 b1c3 g8f6 f1d3 f8c5 e1g1 e8g8 f1e1 f8e8
info depth 17 seldepth 25 multipv 1 score cp 22 nodes 799954 nps 2051164 time 390 pv e2e4 e7e5 g1f3 b8c6 f1b5 f8d6 e1g1 a7a6 b5c6 d7c6 d2d4 e5d4 d1d4 g8f6 e4e5 c6c5 d4d1
info depth 18 seldepth 27 multipv 1 score cp 26 nodes 1135485 nps 2049611 time 554 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8f6 e1g1 a7a6 b5c6 d7c6 d2d3 f8d6 h2h3 h7h6 b1c3 e8g8 c1d2 f8e8
info depth 19 seldepth 30 multipv 1 score cp 23 nodes 1622957 nps 2038890 time 796 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 b1d2 f8d6 d2e4 d5e4 f1c4 d6e5 d4e5 d8d1 e1d1 b8c6 c4d5 c6e5 d5e4
info depth 20 seldepth 30 multipv 1 score cp 23 nodes 2218432 nps 2042755 time 1086 pv e2e4 e7e5 g1f3 g8f6 f3e5 f6e4 d2d4 d7d5 b1d2 f8d6 d2e4 d5e4 c1f4 e8g8 d1h5 d6e5 d4e5 g7g6 h5h6 b8c6
info depth 21 seldepth 33 multipv 1 score cp 16 nodes 3869923 nps 2040022 time 1897 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8d6 e1g1 e8g8 d4f5 d6e5 d1h5 d7d6 c3d5 c8f5 h5f5
info depth 22 seldepth 33 multipv 1 score cp 16 nodes 5405154 nps 2035839 time 2655 pv e2e4 e7e5 g1f3 b8c6 f1b5 g8e7 b1c3 a7a6 b5c6 e7c6 d2d4 e5d4 f3d4 f8d6 e1g1 e8g8 d4f5 d6e5 d1h5 d7d6 c3d5 c8f5 h5f5
info depth 23 seldepth 36 multipv 1 score cp 25 nodes 9346664 nps 2031000 time 4602 pv d2d4 d7d5 g1f3 g8f6 c2c4 e7e6 b1c3 a7a6 e2e3 c7c5 c4d5 e6d5 f1d3 b8c6 e1g1 f8d6 d4c5 d6c5 c1d2 c6b4 d3e2 e8g8 a1c1
info depth 24 seldepth 37 multipv 1 score cp 25 nodes 14104095 nps 2036398 time 6926 pv d2d4 g8f6 g1f3 e7e6 c2c4 f8e7 b1c3 d7d5 c4d5 e6d5 c1f4 e8g8 e2e3 c7c5 d4c5 b8c6 a1c1 c8f5 f3d4 c6d4 e3d4 f8e8 f1d3
info depth 25 seldepth 37 multipv 1 score cp 28 nodes 18733445 nps 2034695 time 9207 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 a7a6 c4d5 e6d5 c1f4 f8d6 f4d6 d8d6 e2e3 c8f5 f1d3 f5d3 d1d3 b8c6 a2a3 e8g8 e1g1 f8e8 a1c1
info depth 26 seldepth 38 multipv 1 score cp 30 nodes 31343454 nps 2023202 time 15492 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 a7a6 e2e3 c7c5 c4d5 e6d5 f1d3 c5c4 d3c2 f8d6 e1g1 e8g8 h2h3 b8c6 c3e2 h7h6 c1d2 c6b4 d2b4 d6b4
info depth 27 seldepth 39 multipv 1 score cp 22 nodes 45955066 nps 2021958 time 22728 pv d2d4 g8f6 g1f3 e7e6 c2c4 d7d5 b1c3 a7a6 c4d5 e6d5 c1f4 f8d6 f4d6 d8d6 e2e3 c8f5 f1d3 f5d3 d1d3 b8d7 e1g1 e8g8 a1c1 c7c6 h2h3 f8e8 c3e2
info depth 28 seldepth 41 multipv 1 score cp 20 nodes 110496756 nps 2034181 time 54320 pv d2d4 d7d5 c2c4 c7c6 c4d5 c6d5 c1f4 b8c6 g1f3 c8f5 e2e3 e7e6 f1d3 f8b4 b1c3 f5d3 d1d3 a8c8 e1g1 g8f6 h2h3 e8g8 c3e2 b4e7 a2a3 f6e4 a1c1
info depth 29 seldepth 44 multipv 1 score cp 30 nodes 149237890 nps 2027633 time 73602 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 c8e6 c2c3 h7h6 g5f4 b8c6 e2d2 f6e4 d2c2 e7d6 f4d6 e4d6
info depth 30 seldepth 42 multipv 1 score cp 24 nodes 182846965 nps 2026656 time 90221 pv e2e4 e7e6 g1f3 d7d5 e4d5 e6d5 d2d4 g8f6 f1d3 f8d6 d1e2 d6e7 e1g1 e8g8 f1e1 f8e8 c1g5 c8e6 c2c3 h7h6 g5f4 b8c6 e2c2 e7d6 f4d6 d8d6 b1d2 e6d7 h2h3 a7a6 a2a3
```

NNUE:
```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 549 nps 549000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 869 nps 869000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1577 nps 1577000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4905 nps 1635000 time 3 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11774 nps 1682000 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 12 multipv 1 score cp 29 nodes 15018 nps 1668666 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 20 nodes 23672 nps 1820923 time 13 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6 e4e5 f6d5
info depth 11 seldepth 19 multipv 1 score cp 30 nodes 41568 nps 1807304 time 23 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 16 multipv 1 score cp 21 nodes 68300 nps 1897222 time 36 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e4e5 f6d5
info depth 13 seldepth 21 multipv 1 score cp 27 nodes 110380 nps 1936491 time 57 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 c2c4 a8b8 f1e1 g8f6 b1c3
info depth 14 seldepth 21 multipv 1 score cp 22 nodes 220548 nps 2004981 time 110 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 b1c3 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 seldepth 23 multipv 1 score cp 30 nodes 378528 nps 2046097 time 185 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 584199 nps 2049821 time 285 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 916454 nps 2045656 time 448 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 29 multipv 1 score cp 33 nodes 1514068 nps 2051582 time 738 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 27 multipv 1 score cp 28 nodes 2325537 nps 2050738 time 1134 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 e1g1 g8f6 d2d4 f8e7 c1g5 e8g8 g5f6 e7f6 d4c5
info depth 20 seldepth 29 multipv 1 score cp 24 nodes 3593714 nps 2041882 time 1760 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5 f6d7 d1d4 f8e8
info depth 21 seldepth 31 multipv 1 score cp 23 nodes 5053111 nps 2030177 time 2489 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e7c5 f1e1 c8e6 b5c6 b7c6 b1c3 e8g8 c3a4 c5e7
info depth 22 seldepth 34 multipv 1 score cp 29 nodes 7100662 nps 2015515 time 3523 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 23 seldepth 32 multipv 1 score cp 29 nodes 8599117 nps 2014788 time 4268 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 24 seldepth 39 multipv 1 score cp 22 nodes 12066203 nps 2007687 time 6010 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 17668660 nps 1992631 time 8867 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2 c8d7
info depth 26 seldepth 37 multipv 1 score cp 21 nodes 22950536 nps 1991715 time 11523 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 h2h3 h7h6 c1e3 c8d7 f1d1
info depth 27 seldepth 37 multipv 1 score cp 22 nodes 28294345 nps 1989057 time 14225 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 d4e2 d1e2 c8d7 f1d1
info depth 28 seldepth 41 multipv 1 score cp 25 nodes 37438122 nps 1991389 time 18800 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 a7a6 c1e3 c8d7 d1d2 d7c6
info depth 29 seldepth 41 multipv 1 score cp 19 nodes 61697102 nps 1983319 time 31108 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1f4 d7d6 d4b3 e6e5 f4g5 f8e7 g5f6 e7f6 f1c4 e8g8 e1g1 a8b8
info depth 30 seldepth 44 multipv 1 score cp 22 nodes 101486734 nps 1968323 time 51560 pv e2e4 c7c5 g1f3 d7d6 b1c3 e7e5 h2h3 f8e7 f1c4 g8f6 e1g1 e8g8 d2d3 b8c6 a2a3 c6d4 c3d5 c8e6 d5e7 d8e7 f3d4 c5d4 c4e6 f7e6 c2c3 d4c3 b2c3 e7c7 d1b3 f8f7 f1e1
```

```
Score of ChessDotCpp3.85-classical vs ChessDotCpp2.28: 404 - 97 - 499  [0.653] 1000
...      ChessDotCpp3.85-classical playing White: 204 - 48 - 248  [0.656] 500
...      ChessDotCpp3.85-classical playing Black: 200 - 49 - 251  [0.651] 500
...      White vs Black: 253 - 248 - 499  [0.502] 1000
Elo difference: 110.2 +/- 15.2, LOS: 100.0 %, DrawRatio: 49.9 %

Score of ChessDotCpp3.85-classical vs ChessDotCpp3.85: 7 - 933 - 60  [0.037] 1000
...      ChessDotCpp3.85-classical playing White: 2 - 465 - 33  [0.037] 500
...      ChessDotCpp3.85-classical playing Black: 5 - 468 - 27  [0.037] 500
...      White vs Black: 470 - 470 - 60  [0.500] 1000
Elo difference: -566.2 +/- 44.2, LOS: 0.0 %, DrawRatio: 6.0 %

Score of ChessDotCpp3.85-classical vs glaurung2.2: 672 - 163 - 165  [0.754] 1000
...      ChessDotCpp3.85-classical playing White: 336 - 84 - 80  [0.752] 500
...      ChessDotCpp3.85-classical playing Black: 336 - 79 - 85  [0.757] 500
...      White vs Black: 415 - 420 - 165  [0.497] 1000
Elo difference: 195.0 +/- 22.1, LOS: 100.0 %, DrawRatio: 16.5 %

Score of ChessDotCpp3.85-classical vs texel: 212 - 491 - 297  [0.360] 1000
...      ChessDotCpp3.85-classical playing White: 109 - 234 - 158  [0.375] 501
...      ChessDotCpp3.85-classical playing Black: 103 - 257 - 139  [0.346] 499
...      White vs Black: 366 - 337 - 297  [0.514] 1000
Elo difference: -99.6 +/- 18.5, LOS: 0.0 %, DrawRatio: 29.7 %

Score of ChessDotCpp3.85-classical vs weiss2.0: 56 - 775 - 169  [0.141] 1000
...      ChessDotCpp3.85-classical playing White: 29 - 393 - 78  [0.136] 500
...      ChessDotCpp3.85-classical playing Black: 27 - 382 - 91  [0.145] 500
...      White vs Black: 411 - 420 - 169  [0.495] 1000
Elo difference: -314.6 +/- 25.1, LOS: 0.0 %, DrawRatio: 16.9 %

Score of ChessDotCpp3.85 vs ChessDotCpp3.84: 480 - 461 - 1059  [0.505] 2000
...      ChessDotCpp3.85 playing White: 413 - 69 - 518  [0.672] 1000
...      ChessDotCpp3.85 playing Black: 67 - 392 - 541  [0.338] 1000
...      White vs Black: 805 - 136 - 1059  [0.667] 2000
Elo difference: 3.3 +/- 10.4, LOS: 73.2 %, DrawRatio: 52.9 %
```

### 3.86

* Search on separate thread, implement UCI stop command
* Fix lazy SMP timeouts

```
info depth 1 seldepth 1 multipv 1 score cp 26 nodes 25 nps 25000 time 1 pv e2e4
info depth 2 seldepth 4 multipv 1 score cp 27 nodes 70 nps 70000 time 1 pv e2e4 g8f6
info depth 3 seldepth 5 multipv 1 score cp 12 nodes 346 nps 346000 time 1 pv c2c4 g8f6 g1f3
info depth 4 seldepth 6 multipv 1 score cp 34 nodes 549 nps 549000 time 1 pv c2c4 e7e6 g1f3 g8f6
info depth 5 seldepth 7 multipv 1 score cp 24 nodes 869 nps 869000 time 1 pv c2c4 e7e6 g2g3 g8f6 g1f3
info depth 6 seldepth 9 multipv 1 score cp 28 nodes 1577 nps 788500 time 2 pv c2c4 e7e6 g2g3 g8f6 g1f3 d7d5
info depth 7 seldepth 10 multipv 1 score cp 22 nodes 4905 nps 1226250 time 4 pv c2c4 g7g6 b1c3 f8g7 d2d4 g8f6 g1f3
info depth 8 seldepth 12 multipv 1 score cp 30 nodes 11774 nps 1682000 time 7 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6
info depth 9 seldepth 12 multipv 1 score cp 29 nodes 15018 nps 1668666 time 9 pv e2e4 c7c5 g1f3 b8c6 f1e2 g7g6 e1g1 g8f6 e4e5
info depth 10 seldepth 14 multipv 1 score cp 20 nodes 23672 nps 1820923 time 13 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 g8f6 e4e5 f6d5
info depth 11 seldepth 19 multipv 1 score cp 30 nodes 41568 nps 1889454 time 22 pv e2e4 c7c5 g1f3 b8c6 f1b5 g8f6 e4e5 f6d5 e1g1 g7g6 f1e1
info depth 12 seldepth 16 multipv 1 score cp 21 nodes 68300 nps 1951428 time 35 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 e4e5 f6d5
info depth 13 seldepth 21 multipv 1 score cp 27 nodes 110380 nps 1971071 time 56 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 c2c4 a8b8 f1e1 g8f6 b1c3
info depth 14 seldepth 21 multipv 1 score cp 22 nodes 220548 nps 2061196 time 107 pv e2e4 c7c5 g1f3 g7g6 f1e2 f8g7 e1g1 b8c6 f1e1 g8f6 b1c3 d7d6 d2d4 e8g8 d4c5 d6c5
info depth 15 seldepth 23 multipv 1 score cp 30 nodes 378528 nps 2114681 time 179 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 16 seldepth 23 multipv 1 score cp 30 nodes 584199 nps 2139923 time 273 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 17 seldepth 26 multipv 1 score cp 30 nodes 916454 nps 2161448 time 424 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5
info depth 18 seldepth 29 multipv 1 score cp 33 nodes 1514068 nps 2166048 time 699 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 g8f6 e4e5 f6d5 e1g1 d7d6 d2d4 c5d4 c3d4 d6e5 f3e5 f8e7
info depth 19 seldepth 27 multipv 1 score cp 28 nodes 2325537 nps 2165304 time 1074 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c3 d7d5 e4d5 e6d5 e1g1 g8f6 d2d4 f8e7 c1g5 e8g8 g5f6 e7f6 d4c5
info depth 20 seldepth 29 multipv 1 score cp 24 nodes 3593714 nps 2163584 time 1661 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 e1g1 g8f6 b1c3 f8e7 d2d4 c5d4 f3d4 e8g8 d4c6 d7c6 e4e5 f6d7 d1d4 f8e8
info depth 21 seldepth 31 multipv 1 score cp 23 nodes 5053111 nps 2158526 time 2341 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e7c5 f1e1 c8e6 b5c6 b7c6 b1c3 e8g8 c3a4 c5e7
info depth 22 seldepth 34 multipv 1 score cp 29 nodes 7100662 nps 2145215 time 3310 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 23 seldepth 32 multipv 1 score cp 29 nodes 8599117 nps 2142815 time 4013 pv e2e4 c7c5 g1f3 e7e6 f1d3 f8e7 e1g1 d7d5 e4d5 e6d5 d3b5 b8c6 d2d4 g8f6 d4c5 e8g8 b5c6 b7c6 c1e3 f6e4 b2b4 a7a5 c2c3 a5b4 c3b4
info depth 24 seldepth 39 multipv 1 score cp 22 nodes 12066203 nps 2133722 time 5655 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2
info depth 25 seldepth 37 multipv 1 score cp 19 nodes 17668660 nps 2120833 time 8331 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 b4c5 b6c5 b1b2 c8d7
info depth 26 seldepth 37 multipv 1 score cp 21 nodes 22950536 nps 2112336 time 10865 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 d4e2 d1e2 b7b6 h2h3 h7h6 c1e3 c8d7 f1d1
info depth 27 seldepth 37 multipv 1 score cp 22 nodes 28294345 nps 2111518 time 13400 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 d4e2 d1e2 c8d7 f1d1
info depth 28 seldepth 41 multipv 1 score cp 25 nodes 37438122 nps 2105512 time 17781 pv e2e4 c7c5 g1f3 e7e6 f1e2 b8c6 c2c4 g8f6 b1c3 e6e5 e1g1 f8e7 d2d3 e8g8 a2a3 d7d6 a1b1 c6d4 b2b4 b7b6 h2h3 h7h6 g1h1 a7a6 c1e3 c8d7 d1d2 d7c6
info depth 29 seldepth 41 multipv 1 score cp 19 nodes 61697102 nps 2092562 time 29484 pv e2e4 c7c5 g1f3 e7e6 b1c3 b8c6 d2d4 c5d4 f3d4 g8f6 c1f4 d7d6 d4b3 e6e5 f4g5 f8e7 g5f6 e7f6 f1c4 e8g8 e1g1 a8b8
info depth 30 seldepth 44 multipv 1 score cp 22 nodes 101486734 nps 2078623 time 48824 pv e2e4 c7c5 g1f3 d7d6 b1c3 e7e5 h2h3 f8e7 f1c4 g8f6 e1g1 e8g8 d2d3 b8c6 a2a3 c6d4 c3d5 c8e6 d5e7 d8e7 f3d4 c5d4 c4e6 f7e6 c2c3 d4c3 b2c3 e7c7 d1b3 f8f7 f1e1
```

```
Score of ChessDotCpp3.86 vs ChessDotCpp3.85: 685 - 706 - 1609  [0.496] 3000
...      ChessDotCpp3.86 playing White: 592 - 92 - 816  [0.667] 1500
...      ChessDotCpp3.86 playing Black: 93 - 614 - 793  [0.326] 1500
...      White vs Black: 1206 - 185 - 1609  [0.670] 3000
Elo difference: -2.4 +/- 8.5, LOS: 28.7 %, DrawRatio: 53.6 %

Score of ChessDotCpp3.86-2CPU vs ChessDotCpp3.86: 1456 - 797 - 2747  [0.566] 5000
...      ChessDotCpp3.86-2CPU playing White: 1265 - 63 - 1172  [0.740] 2500
...      ChessDotCpp3.86-2CPU playing Black: 191 - 734 - 1575  [0.391] 2500
...      White vs Black: 1999 - 254 - 2747  [0.674] 5000
Elo difference: 46.1 +/- 6.4, LOS: 100.0 %, DrawRatio: 54.9 %

Score of ChessDotCpp3.86-4CPU vs ChessDotCpp3.86: 106 - 37 - 157  [0.615] 300
...      ChessDotCpp3.86-4CPU playing White: 87 - 3 - 60  [0.780] 150
...      ChessDotCpp3.86-4CPU playing Black: 19 - 34 - 97  [0.450] 150
...      White vs Black: 121 - 22 - 157  [0.665] 300
Elo difference: 81.4 +/- 27.0, LOS: 100.0 %, DrawRatio: 52.3 %

Score of ChessDotCpp3.86-12CPU vs ChessDotCpp3.86: 43 - 8 - 49  [0.675] 100
...      ChessDotCpp3.86-12CPU playing White: 37 - 0 - 13  [0.870] 50
...      ChessDotCpp3.86-12CPU playing Black: 6 - 8 - 36  [0.480] 50
...      White vs Black: 45 - 6 - 49  [0.695] 100
Elo difference: 127.0 +/- 48.7, LOS: 100.0 %, DrawRatio: 49.0 %
```
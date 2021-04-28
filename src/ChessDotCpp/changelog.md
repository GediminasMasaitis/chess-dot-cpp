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
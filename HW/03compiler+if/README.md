# Compiler+if

## 語法

```
PROG = STMTS
BLOCK = { STMTS }
STMTS = STMT*
STMT = WHILE | BLOCK | ASSIGN
WHILE = while (E) STMT
IF = if (E) STMT (else STMT)?
ASSIGN = id '=' E;
E = F (op E)*
F = (E) | Number | Id
```
## 測試檔(if.c)
````
a = 3;
b = 5;
if (a > b) t = a;
else t = b;

````
## 執行結果
````
C:\Users\user\Desktop\系統程式\sp108b\HW\03compiler+if>compiler test/if.c
a = 3;
b = 5;
if (a > b) t = a;
else t = b;

========== lex ==============
token=a
token==
token=3
token=;
token=b
token==
token=5
token=;
token=if
token=(
token=a
token=>
token=b
token=)
token=t
token==
token=a
token=;
token=else
token=t
token==
token=b
token=;
========== dump ==============
0:a
1:=
2:3
3:;
4:b
5:=
6:5
7:;
8:if
9:(
10:a
11:>
12:b
13:)
14:t
15:=
16:a
17:;
18:else
19:t
20:=
21:b
22:;
============ parse =============
t0 = 3
a = t0
t1 = 5
b = t1
t2 = a
t3 = b
t4 = t2 > t3
if T4 is false goto L0
t5 = a
t = t5
goto L1
(L0)
t6 = b
t = t6
(L1)
````

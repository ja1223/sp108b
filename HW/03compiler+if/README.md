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
## if語法的程式碼
````
// IF = if (E) STMT (else STMT)?
void IF() {
  int elseBegin = nextLabel();//產生else開始的標記
  int End = nextLabel();//產生結束的標記
  skip("if");
  skip("(");
  int e = E();//a > b
  emit("if T%d is false goto L%d\n", e, elseBegin); //如果a不大於b就跳到else開始的標籤
  skip(")");
  STMT();//t = a
  emit("goto L%d\n", End);//跳到結束的標籤
  if (isNext("else")) {
    skip("else");
    emit("(L%d)\n", elseBegin);//else開始的標記
    STMT();//t = b
  }
  emit("(L%d)\n", End);//結束的標記
}
````
## 測試檔(if.c)
````
a = 3;
b = 5;
if (a > b) t = a;
else t = b;

````
## 執行方法
````
用mingw32-make編譯1個以上的C語言檔案 :

C:\Users\user\Desktop\系統程式\sp108b\HW\03compiler+if>compiler gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler

執行test資料夾中的if.c :

C:\Users\user\Desktop\系統程式\sp108b\HW\03compiler+if>compiler ./compiler test/if.c
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
## 中間碼解釋
````
中間碼                                                                 測試檔               
t0 = 3
a = t0                      a = 3                                     a = 3;
t1 = 5
b = t1                      b = 5                                     b = 5;
t2 = a
t3 = b
t4 = t2 > t3                t4 就是 a > b
if t4 is false goto L0      如果 t4 是錯誤的(a不大於b)跳到 L0 的標記; 
                            t4 是正確的(a 大於 b)就繼續執行
t5 = a                    
t = t5                      t = a                                     if (a > b) t = a;
goto L1                     跳到 L1 的標記
(L0)                        L0 的標記                             
t6 =b
t = t6                      t = b                                     else t = b;          
(L1)                        L1 的標記(程式結束)                              
````

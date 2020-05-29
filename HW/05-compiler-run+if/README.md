# Compiler-run+if

## if語法的程式碼(用compiler+if進行修改)
````
// IF = if (E) STMT (else STMT)?
void IF() {
  int elseBegin = nextLabel();//產生else開始的標記
  int End = nextLabel();//產生結束的標記
  skip("if");
  skip("(");
  int e = E();//a > b
  //emit("if T%d is false goto L%d\n", e, elseBegin); //如果a不大於b就跳到else開始的標籤
  irEmitIfNotGoto(e, elseBegin);
  skip(")");
  STMT();//t = a
  //emit("goto L%d\n", End);//跳到結束的標籤
  irEmitGoto(End);
  irEmitLabel(elseBegin);
  if (isNext("else")) {
    skip("else");
    //emit("(L%d)\n", elseBegin);//else開始的標記
     
    STMT();//t = b
  }
  //emit("(L%d)\n", End);//結束的標記
  irEmitLabel(End);
}
````
## 測試檔(if.c)
````
a = 3;
b = 5;
if (a > b)
  t = a;
else
  t = b;

````
## 執行方法
````
1. 用mingw32-make編譯1個以上的C語言檔案 :

  C:\Users\user\Desktop\系統程式\sp108b\HW\03compiler+if>compiler gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler

2. 執行test資料夾中的if.c :

  C:\Users\user\Desktop\系統程式\sp108b\HW\05-compiler-run+if>./compiler test/if.c -ir -run
````  
## 參數
````
-ir：印出中間碼
-run：執行
````
## 執行結果
````
C:\Users\user\Desktop\系統程式\sp108b\HW\05-compiler-run+if>./compiler test/if.c -ir -run
=======irDump()==========
00: t1 = 3
01: a = t1
02: t1 = 5
03: b = t1
04: t2 = a
05: t3 = b
06: t4 = t2 > t3
07: ifnot t4 goto L1
08: t1 = a
09: t = t1
10: goto L2
11: (L1)
12: t1 = b
13: t = t1
14: (L2)
===================irRun()=======================
00: t1 = 3 (3)
01: a = t1 (3)
02: t1 = 5 (5)
03: b = t1 (5)
04: t2 = a (3)
05: t3 = b (5)
06: t4 = t2 > t3 (0)
07: ifnot t4 (0) goto L1 (11)
11: (L1) (11)
12: t1 = b (5)
13: t = t1 (5)
14: (L2) (14)
````


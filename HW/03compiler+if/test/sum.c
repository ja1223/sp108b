
s=0;
i=1;
while (i < 11) {
  s = s + i;
  i = i + 1;
}

/*
t0 = 0
s = t0               s=0
t1 = 1
i = t1               i=1
(L0)
t2 = i
t3 = 11
t4 = t2 < t3         t4 = i < 11
if not T4 goto L1    goto L1
t5 = s
t6 = i
t7 = t5 + t6         
s = t7               s = s + i
t8 = i
t9 = 1
t10 = t8 + t9
i = t10              i = i + 1
goto L0              goto L0
(L1)
*/
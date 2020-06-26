//寫a的b次方的函式

int power(int a,int b)
{   int i=1;
    for(;i<b;i++)
    {
      a=a*a;
    }
    return a;
}
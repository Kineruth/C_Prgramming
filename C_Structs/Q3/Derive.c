
//Created by Kineret Ruth on 14-Jan-18.
#include <stdio.h>
#include <stdlib.h>

typedef struct MyClass
{
    int m_x;
    void (*add)();
}MyClass;

void add(MyClass* class,int y)
{
    if(class==NULL)
     exit(1);
    class->m_x = class->m_x+y;
}

MyClass* init(int x)
{
    MyClass* class = (MyClass*)malloc(sizeof(MyClass));
    class->m_x = x;
    class->add = &add;
    return class;
}

void printValue(MyClass* class)
{
    printf("m_x is: %d\n", class->m_x );
}


typedef struct Derive
{
    MyClass* class;
    
}Derive;

void add2(Derive* d, int y)
{
    if(d==NULL)
        exit(1);
    d->class->m_x = d->class->m_x^y;
}

void printVal(Derive* d)
{
    printf("m_x is: %d\n", d->class->m_x );
}

Derive* init2(int x)
{
    Derive* d = (Derive*)malloc(sizeof(Derive));
    d->class = (MyClass*)malloc(sizeof(MyClass));
    d->class->m_x = x;
    d->class->add= &add2;
    return d;
}

int main()
{
  Derive* d =  init2(15);
  add2( d, 10);
  printVal(d);
  return 0;
}
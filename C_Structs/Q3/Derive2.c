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


typedef struct Derive2
{
    MyClass* class;
    int m_y;
    
}Derive2;

void add3(Derive2* d, int y)
{
    if(d==NULL)
        exit(1);
    d->class->m_x = d->class->m_x+y;
    d->m_y =  d->m_y +y;
}

void printVal(Derive2* d)
{
    printf("m_x is: %d\n", d->class->m_x );
    printf("m_y is: %d\n", d->m_y );
}

Derive2* init3(int x, int y)
{
    Derive2* d = (Derive2*)malloc(sizeof(Derive2));
    d->class = (MyClass*)malloc(sizeof(MyClass));
    d->class->m_x = x;
    d->m_y = y;
    d->class->add= &add3;
    return d;
}

int main()
{
  Derive2* d =  init3(20,10);
  add3( d, 10);
  printVal(d);
  return 0;
}

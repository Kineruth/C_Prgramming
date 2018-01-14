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

int main()
{
   MyClass* class =  init(20);
   add(class,30);
   printValue(class);
   return 0;
}



//#include <iostream>

#include <stdio.h>
#include <malloc.h>

char buf[2000];
void MemoryDump(int start, int length); // 함수의 원형 Prototype

int main(int argc, char *argv[])    // PointerSample 10000 500: // Command Line 명령어
                                    // 10000:  Start Memory 주소
                                    // 500: Dump 할 Memory 크기
{
    int start = 0x09000000;
    int length = 500;

    char c = 'A';
    int i = 1;
    float a = 2.0;
    double d = 3.14;
    void* p = malloc(100);  // (void*) buf // 0x00000000 그저 주소일뿐..

    *(double *)p = d;

    MemoryDump((int)buf, length);
   /* printf("c = %8c [0x%x08]\n", c, &c);
    printf("i = %8d [0x%x08]\n", i, &i);
    printf("a = %8f [0x%x08]\n", a, &a);
    printf("d = %8f [0x%x08]\n", d, &d);
    printf("p = %8f [0x%x08]\n", *(double *)p, p);*/

    return 0;
}

void MemoryDump(int start, int length) {
    char* cp = buf; // (char *)start;
    //void* vp = (void*)start;
    int i = 0;  // index 변수 초기값

    while (i < length) {  // 수행조건 i < length
        //char* cp = (char*)vp;
        //char c = *cp;
        unsigned char c = *((char*)cp+i++);
        //i++;
        printf("%02x ", c);
    }

}
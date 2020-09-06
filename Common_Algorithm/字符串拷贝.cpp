// strcpy: 从 src 拷贝到 dst
// 1. 如果 dst 落在 src 中间，那么从前往后赋值的话，dst 就会覆盖掉 src
// 的内容，出现问题，因此需要从后往前 copy
// 2. 如果 dst 不落在中间，那么有以下几种情况
// 2.1 如果落在左侧或者右侧，且没有 overlapping
// (右侧不可能有)，那么两个方向复制都ok 2.2
// 如果在左侧，有重复，那么就需要从前往后复制 综上，对于条件
// 2，我们一致的从前往后复制即可
char* strcpy(char* dst, char* src)  //内存重叠
{
    assert((dst != NULL && src != NULL));
    char* ret = dst;
    int size = strlen(src) + 1;
    if (dst >= src &&
        dst < src + size)  //这个dst的内存在src的范围内，即出现可内存重叠
    {
        dst = dst + size - 1;
        src = src + size - 1;
        while (size--) {
            *dst-- = *src--;  //将src的值从后向前赋值，赋给dst
        }
    } else {
        while (size--) {
            *dst++ = *src++;
        }
    }
    return ret;
}

// ----------------手写memcpy------------------------他和strcpy的区别是
// strcpy和memcpy主要有以下3方面的区别。
// 1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
// 2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
// 3、用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy

void* mymemcpy(void* dst, const void* src, size_t size) {
    if (dst == NULL || src == NULL) return NULL;

    char* pdst =
        (char*)dst;  // 感觉是因为char为一个字节，所以一个字节一个字节的拷贝
    const char* psrc = (const char*)src;
    if (pdst > psrc && pdst < psrc + size) {
        pdst = pdst + size - 1;
        psrc = psrc + size - 1;
        while (size--) *pdst-- = *psrc--;
    } else {
        while (size--) *pdst++ = *psrc++;
    }
    return dst;
}

// ----------------手写strcat------------------------
char* mystrcat(char* dst, char* src) {
    char* res = dst;
    while (*dst != '\0') ++dst;
    while (*src != '\0') {
        *dst++ = *src++;
    }
    *dst = '\0';  //添加结束符，不然后面有乱码！
    return res;
}


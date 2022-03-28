#ifndef MY_STRING_GUARD
#define MY_STRING_GUARD

int strLen(const char *str)
{
    if (str == nullptr) {
        return -1;
    }

    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }
    return length;
}

void strCpy(const char *src, char *dest)
{
    if (src == nullptr || dest == nullptr) {
        return;
    }

    int index = 0;
    while (src[index] != '\0') {
        dest[index] = src[index];
        ++index;
    }
    dest[index] = '\0';
}

int strCmp(const char *strA, const char *strB)
{
    if (strA == nullptr || strB == nullptr) {
        return -2;
    }

    int lengthA = strLen(strA);
    int lengthB = strLen(strB);

    for (int i = 0; i <= lengthA || i <= lengthB; ++i) {
        if (strA[i] > strB[i]) {
            return 1;
        }
        else if (strA[i] < strB[i]) {
            return -1;
        }
    }

    return 0;
}

#endif // MY_STRING_GUARD

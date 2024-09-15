#include <stdio.h>

// 정수부 2진수 변환
void int_Bin(unsigned int n) {
    int binInt[32];
    int i = 0;
    while (n > 0) {
        binInt[i++] = n % 2;
        n = n / 2;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binInt[j]);
    }
}

// 소수부 2진수 변환
void frac_Bin(double frac, int lim) {
    int binFrac[32];
    for (int i = 0; i < lim; i++) {
        frac *= 2;
        binFrac[i] = (int)frac;
        if (frac >= 1) frac -= (int)frac;
    }
    for (int i = 0; i < lim; i++) {
        printf("%d", binFrac[i]);
    }
}

// 정수부 16진수 변환
void int_Hex(unsigned int n) {
    int hexInt[8];
    int i = 0;
    while (n > 0) {
        hexInt[i++] = n % 16;
        n = n / 16;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (hexInt[j] < 10) printf("%d", hexInt[j]);
        else printf("%c", 'A' + (hexInt[j] - 10));
    }
}

// 소수부 16진수 변환
void frac_Hex(double frac, int lim) {
    int hexFrac[8];
    for (int i = 0; i < lim; i++) {
        frac *= 16;
        hexFrac[i] = (int)frac;
        if (frac >= 1) frac -= (int)frac;
    }
    for (int i = 0; i < lim; i++) {
        if (hexFrac[i] < 10) printf("%d", hexFrac[i]);
        else printf("%c", 'A' + (hexFrac[i] - 10));
    }
}

// IEEE 754 변환
void IEEE754(float num) {
    unsigned int* p = (unsigned int*)&num; 
    unsigned int n = *p;


    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
        if (i == 31 || i == 23) printf(" ");
    }
    printf("\n");
}

int main() {
    double num;


    printf("10진수 입력: ");
    scanf_s("%lf", &num);

    unsigned int intPart = (unsigned int)num;   //정수부
    double fracPart = num - (double)intPart;     //소수부

    printf("2진수로 변환한 값: ");
    if (intPart == 0) printf("0");
    else int_Bin(intPart);
    printf(".");
    frac_Bin(fracPart, 20);      //소수점 아래 20자리
    printf("\n");

    printf("16진수로 변환한 값: ");
    if (intPart == 0) printf("0");
    else int_Hex(intPart);
    printf(".");
    frac_Hex(fracPart, 5);       //소수점 아래 5자리
    printf("\n");

    printf("IEEE 754 Standard의 format으로 표현한 32비트 값: ");
    IEEE754((float)num);

    return 0;
}
#include <stdio.h>

// ������ 2���� ��ȯ
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

// �Ҽ��� 2���� ��ȯ
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

// ������ 16���� ��ȯ
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

// �Ҽ��� 16���� ��ȯ
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

// IEEE 754 ��ȯ
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


    printf("10���� �Է�: ");
    scanf_s("%lf", &num);

    unsigned int intPart = (unsigned int)num;   //������
    double fracPart = num - (double)intPart;     //�Ҽ���

    printf("2������ ��ȯ�� ��: ");
    if (intPart == 0) printf("0");
    else int_Bin(intPart);
    printf(".");
    frac_Bin(fracPart, 20);      //�Ҽ��� �Ʒ� 20�ڸ�
    printf("\n");

    printf("16������ ��ȯ�� ��: ");
    if (intPart == 0) printf("0");
    else int_Hex(intPart);
    printf(".");
    frac_Hex(fracPart, 5);       //�Ҽ��� �Ʒ� 5�ڸ�
    printf("\n");

    printf("IEEE 754 Standard�� format���� ǥ���� 32��Ʈ ��: ");
    IEEE754((float)num);

    return 0;
}
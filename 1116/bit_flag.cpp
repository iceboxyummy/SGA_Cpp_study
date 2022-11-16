// 2������, bool��� ����, ��Ʈ����

#include<iostream>

int main() {

    /*
    1.
        int a = 123;
        a = 0;
        a = a ? a  : ?�� ���� �����ڰ� ���� a = 0; ���� ������ �ɱ�?
    */

    {
        std::cout << "===========1. a = 0 ===========" << std::endl;

        int a = 123;
        std::cout << "������ : " << a << std::endl;

        a = a ^ a;
        std::cout << "������ : " << a << std::endl;
    }

    // 2. temp�� ������� �ʰ� swap�ϱ�
    {
        std::cout << "======== 2. swap �ϱ� =========" << std::endl;

        int a = 123;
        int b = 456; 

        std::cout << "swap �� : " << "a = " << a << " b = " << b << std::endl;

        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        std::cout << "swap �� : " << "a = " << a << " b = " << b << std::endl;
    }

    // 3. % ��������ʰ� ¦�� / Ȧ�� �Ǵ��ϱ�
    {
        std::cout << "======== 3. Ȧ/¦ �Ǵ� ========" << std::endl;

        int a = 0;

        std::cout << "���ڸ� �Է��ϼ��� : ";
        std::cin >> a;
        
        if (a & 1)
            std::cout << "Ȧ���Դϴ�." << std::endl;
        else
            std::cout << "¦���Դϴ�." << std::endl;
    }

    // 4. ���迬���� ������� �ʰ� ���� / ��� �Ǵ��ϱ�.
    {
        std::cout << "======= 4. +/- �Ǵ��ϱ� =======" << std::endl;

        int a = 0;
        int x = 0b10000000'00000000'00000000'00000000;

        std::cout << "���ڸ� �Է��ϼ��� : ";
        std::cin >> a;

        if (a&x)
            std::cout << "�����Դϴ�." << std::endl;
        else
            std::cout << "����Դϴ�." << std::endl;
    }

    // 5. �ݺ��� ������� �ʰ� 2�� �¼� Ȯ���ϱ�.
    {
        std::cout << "===== 5. 2�� �¼� �Ǵ��ϱ� =====" << std::endl;

        int a = -1;

        std::cout << "���ڸ� �Է��ϼ��� : ";
        std::cin >> a;

        if (a&(a-1))
            std::cout << "2�� �¼��� �ƴմϴ�." << std::endl;
        else
            std::cout << "2�� �¼��Դϴ�." << std::endl;
    }
    
    // 6. + / - ������� �ʰ� �빮��<->�ҹ��� �ٲٱ�
    {
        std::cout << "===== 6. �빮�� <-> �ҹ��� =====" << std::endl;

        char a = 0;

        std::cout << "���ĺ��� �Է��ϼ��� : ";
        std::cin >> a;
        
        a = a ^ 32;
        
        std::cout << "�빮��<->�ҹ��� : " << a << std::endl;
    }

    return 0;
}
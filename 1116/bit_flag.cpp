// 2진수와, bool대수 문제, 비트연산

#include<iostream>

int main() {

    /*
    1.
        int a = 123;
        a = 0;
        a = a ? a  : ?에 무슨 연산자가 들어가야 a = 0; 보다 빠르게 될까?
    */

    {
        std::cout << "===========1. a = 0 ===========" << std::endl;

        int a = 123;
        std::cout << "연산전 : " << a << std::endl;

        a = a ^ a;
        std::cout << "연산후 : " << a << std::endl;
    }

    // 2. temp를 사용하지 않고 swap하기
    {
        std::cout << "======== 2. swap 하기 =========" << std::endl;

        int a = 123;
        int b = 456; 

        std::cout << "swap 전 : " << "a = " << a << " b = " << b << std::endl;

        a = a ^ b;
        b = a ^ b;
        a = a ^ b;

        std::cout << "swap 후 : " << "a = " << a << " b = " << b << std::endl;
    }

    // 3. % 사용하지않고 짝수 / 홀수 판단하기
    {
        std::cout << "======== 3. 홀/짝 판단 ========" << std::endl;

        int a = 0;

        std::cout << "숫자를 입력하세요 : ";
        std::cin >> a;
        
        if (a & 1)
            std::cout << "홀수입니다." << std::endl;
        else
            std::cout << "짝수입니다." << std::endl;
    }

    // 4. 관계연산자 사용하지 않고 음수 / 양수 판단하기.
    {
        std::cout << "======= 4. +/- 판단하기 =======" << std::endl;

        int a = 0;
        int x = 0b10000000'00000000'00000000'00000000;

        std::cout << "숫자를 입력하세요 : ";
        std::cin >> a;

        if (a&x)
            std::cout << "음수입니다." << std::endl;
        else
            std::cout << "양수입니다." << std::endl;
    }

    // 5. 반복문 사용하지 않고 2의 승수 확인하기.
    {
        std::cout << "===== 5. 2의 승수 판단하기 =====" << std::endl;

        int a = -1;

        std::cout << "숫자를 입력하세요 : ";
        std::cin >> a;

        if (a&(a-1))
            std::cout << "2의 승수가 아닙니다." << std::endl;
        else
            std::cout << "2의 승수입니다." << std::endl;
    }
    
    // 6. + / - 사용하지 않고 대문자<->소문자 바꾸기
    {
        std::cout << "===== 6. 대문자 <-> 소문자 =====" << std::endl;

        char a = 0;

        std::cout << "알파벳을 입력하세요 : ";
        std::cin >> a;
        
        a = a ^ 32;
        
        std::cout << "대문자<->소문자 : " << a << std::endl;
    }

    return 0;
}
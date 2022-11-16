/*
   아래의 클래스는 들어온 템플릿 인자에 따라 데이터를 8개 생성해주는 클래스이다.

   여기서 문제가 생기는데 bool형을 만들 시 공간을 낭비하게 된다.
   -> bool형은 1바이트 크기만으로도 8가지를 표현할 수 있지만 아래와
   같이 생성될 경우 1바이트 * 8의 크기를 가진다.

   아래의 클래스를 템플릿 특수화로 bool형일시
   1바이트를 가지고 8개의 불값을 처리할 수 있게 만들어보자
*/

#include<iostream>

template <class T>
class Storage8
{
public:
	void Set(int index, const T& value)
	{
		arr[index] = value;
	}

	const T& Get(int index) { return arr[index]; }

private:
	T arr[8];
};

template <>
class Storage8<bool>
{
public:
	Storage8(): bit(0){}
	void Bit(int index, const bool& OnOff)
	{
		if (OnOff == true)
		{
			bit |= 1 << (7 - index);
		}
		else
			bit &= ~(1 << (7 - index));
	}

	const bool& Get(int index) 
	{ 
		bool isOn = true;
		isOn = (bit & 1 << (7 - index));
		return isOn; 
	}

private:
	unsigned char bit;
};

int main() {
	Storage8<bool> bitflag;

	for (int i = 0; i < 8; i++)
		std::cout << i << "번째 비트 : " << bitflag.Get(i) << std::endl;
	std::cout << std::endl;

	std::cout << " 2 3 5 7 ON " << std::endl;

	bitflag.Bit(2, true);
	bitflag.Bit(3, true);
	bitflag.Bit(5, true);
	bitflag.Bit(7, true);

	for (int i = 0; i < 8; i++)
		std::cout << i << "번째 비트 : " << bitflag.Get(i) << std::endl;
	std::cout << std::endl;

	std::cout << " 2 3 4 OFF " << std::endl;

	bitflag.Bit(2, false);
	bitflag.Bit(3, false);
	bitflag.Bit(4, false);


	for (int i = 0; i < 8; i++)
		std::cout << i << "번째 비트 : " << bitflag.Get(i) << std::endl;

	return 0;
}

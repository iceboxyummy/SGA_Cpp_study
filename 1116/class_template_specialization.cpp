/*
   �Ʒ��� Ŭ������ ���� ���ø� ���ڿ� ���� �����͸� 8�� �������ִ� Ŭ�����̴�.

   ���⼭ ������ ����µ� bool���� ���� �� ������ �����ϰ� �ȴ�.
   -> bool���� 1����Ʈ ũ�⸸���ε� 8������ ǥ���� �� ������ �Ʒ���
   ���� ������ ��� 1����Ʈ * 8�� ũ�⸦ ������.

   �Ʒ��� Ŭ������ ���ø� Ư��ȭ�� bool���Ͻ�
   1����Ʈ�� ������ 8���� �Ұ��� ó���� �� �ְ� ������
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
		std::cout << i << "��° ��Ʈ : " << bitflag.Get(i) << std::endl;
	std::cout << std::endl;

	std::cout << " 2 3 5 7 ON " << std::endl;

	bitflag.Bit(2, true);
	bitflag.Bit(3, true);
	bitflag.Bit(5, true);
	bitflag.Bit(7, true);

	for (int i = 0; i < 8; i++)
		std::cout << i << "��° ��Ʈ : " << bitflag.Get(i) << std::endl;
	std::cout << std::endl;

	std::cout << " 2 3 4 OFF " << std::endl;

	bitflag.Bit(2, false);
	bitflag.Bit(3, false);
	bitflag.Bit(4, false);


	for (int i = 0; i < 8; i++)
		std::cout << i << "��° ��Ʈ : " << bitflag.Get(i) << std::endl;

	return 0;
}

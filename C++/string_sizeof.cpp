/*************************************************************************
	> File Name: string_sizeof.cpp
	> Author: Tokey
	> Mail: TokeyRoad@163.com 
	> Created Time: 2020年05月13日 星期三 10时05分08秒
 ************************************************************************/

#include <iostream>
#include <string>

class zooanimal{
public:
	zooanimal();
	virtual ~zooanimal();

	virtual void rotate();
private:
	int m_loc;
	std::string m_name;
};

int main(){
	const int a = sizeof(zooanimal);
	const int b = sizeof(std::string);
	std::string strinfo("123456789");
	const int c = sizeof(strinfo);
	std::cout << a << "||" << b << "||" << c << std::endl;
	return 0;
}

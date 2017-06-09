#include <iostream>
#include <vector>

int main(int argc, char** argv)
{
	std::vector<int> v;
	for (auto& i : v)
	{
		std::cout << i << std::endl;
	}
	return 0;
}

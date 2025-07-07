#include <iostream>
#include "../../Source/Engine/Math/Math.h"
#include "../../Source/Engine/Core/Random.h"

#define NAME "Amia\n"

int main()
{
	//const float deg = viper::RadToDeg(viper::pi);
	//viper::math::min(5, 3);
	//std::cout << viper::math::clamp(10, 0, 5) << std::endl;

	std::cout << NAME;
	std::cout << "Hello, World!\n";
	std::cout << viper::math::pi << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << viper::random::getRandomFloat() << std::endl;
	}
}



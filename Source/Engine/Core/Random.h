#pragma once
#include <cstdlib>
namespace viper {
	namespace random {
		/// <summary>
		/// Generates a random integer value.
		/// </summary>
		/// <returns>A psuedo-random integer value.</returns>
		inline int getRandomInt() { return rand(); }

		/// <summary>
		/// Generates a random integer value in the range [0, max).
		/// </summary>
		/// <param name="max"></param>
		/// <returns></returns>
		inline int getRandomInt(int max) { return rand() % max; }

		/// <summary>
		/// 
		/// </summary>
		/// <param name="min"></param>
		/// <param name="max"></param>
		/// <returns></returns>
		inline int getRandomInt(int min, int max) { return min + getRandomInt(max - min); }

		inline float getRandomFloat() { return rand() / (float)RAND_MAX; }
		inline float getRandomFloat(float max) { return getRandomFloat() * max; }
		inline float getRandomFloat(float min, float max) { return min + getRandomFloat(max - min); }
	}
}
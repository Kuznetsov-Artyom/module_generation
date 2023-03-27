#ifndef GENERATION_MODULE
#define GENERATION_MODULE


#include <random>
#include <limits>
#include <stdexcept>


namespace genRandData
{
	template<typename T>
	class IntegerGenerator
	{
	private:
		std::mt19937_64 gen{ std::random_device{}() };
		std::uniform_int_distribution<T> dist;

	private:
		void checkRange(const T& min, const T& max)
		{
			if (min > max)
				throw std::logic_error{ "minRange > maxRange" };
		}

	public:
		IntegerGenerator(const T& min, const T& max) : dist{ min, max }{}

		T getMin() noexcept(noexcept(dist.min())) { return dist.min(); }
		T getMax() noexcept(noexcept(dist.max())) { return dist.max(); }

		void setRange(const T& min, const T& max)
		{
			checkRange(min, max);
			dist = std::uniform_int_distribution<T>(min, max);
		}

		T operator()() { return dist(gen); }
	};



	template<typename T>
	class DoubleGenerator
	{
	private:
		std::mt19937_64 gen{ std::random_device{}() };
		std::uniform_real_distribution<T> dist;

	private:
		void checkRange(const T& min, const T& max)
		{
			if (min > max)
				throw std::logic_error{ "minRange > maxRange" };
		}

	public:
		DoubleGenerator(const T& min, const T& max) : dist{ min, max } {}

		T getMin() noexcept(noexcept(dist.min())) { return dist.min(); }
		T getMax() noexcept(noexcept(dist.max())) { return dist.max(); }

		void setRange(const T& min, const T& max)
		{
			checkRange(min, max);
			dist = std::uniform_int_distribution<T>(min, max);
		}

		T operator()() { return dist(gen); }
	};


} // namespace genRandData


#endif // GENERATION_MODULE
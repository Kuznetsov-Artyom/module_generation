#ifndef GENERATION_MODULE
#define GENERATION_MODULE


#include <random>
#include <climits>
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
		void checkRange(const T& min, const T& max);

	public:
		IntegerGenerator(const T& min, const T& max) : dist{ min, max } {}

		T getMin() noexcept(noexcept(dist.min())) { return dist.min(); }
		T getMax() noexcept(noexcept(dist.max())) { return dist.max(); }

		void setRange(const T& min, const T& max);

		T operator()() { return dist(gen); }
	};

	template<typename T>
	inline void IntegerGenerator<T>::checkRange(const T& min, const T& max)
	{
		if (min > max)
			throw std::logic_error{ "minRange > maxRange" };
	}

	template<typename T>
	inline void IntegerGenerator<T>::setRange(const T& min, const T& max)
	{
		checkRange(min, max);
		dist = std::uniform_int_distribution<T>(min, max);
	}




	template<typename T>
	class DoubleGenerator
	{
	private:
		std::mt19937_64 gen{ std::random_device{}() };
		std::uniform_real_distribution<T> dist;

	private:
		void checkRange(const T& min, const T& max);

	public:
		DoubleGenerator(const T& min, const T& max) : dist{ min, max } {}

		T getMin() noexcept(noexcept(dist.min())) { return dist.min(); }
		T getMax() noexcept(noexcept(dist.max())) { return dist.max(); }

		void setRange(const T& min, const T& max);

		T operator()() { return dist(gen); }
	};

	template<typename T>
	inline void DoubleGenerator<T>::checkRange(const T& min, const T& max)
	{
		if (min > max)
			throw std::logic_error{ "minRange > maxRange" };
	}

	template<typename T>
	inline void DoubleGenerator<T>::setRange(const T& min, const T& max)
	{
		checkRange(min, max);
		dist = std::uniform_int_distribution<T>(min, max);
	}




	template<typename T>
	class CharGenerator
	{
	private:
		T minRange;
		T maxRange;

	private:
		void checkRange(const T& min, const T& max);

	public:
		CharGenerator(const T& min, const T& max) : minRange{ min }, maxRange{ max }
		{
			checkRange(min, max);
		}

		T getMin() const noexcept { return minRange; }
		T getMax() const noexcept { return maxRange; }

		void setRange(const T& min, const T& max);

		T operator()() { return minRange + rand() % (maxRange - minRange + 1); }
	};

	template<typename T>
	inline void CharGenerator<T>::checkRange(const T& min, const T& max)
	{
		if (min > max)
			throw std::logic_error{ "minRange > maxRange" };
	}

	template<typename T>
	inline void CharGenerator<T>::setRange(const T& min, const T& max)
	{
		checkRange(min, max);

		minRange = min;
		maxRange = max;
	}


} // namespace genRandData


#endif // GENERATION_MODULE
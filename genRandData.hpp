#ifndef _GEN_RAND_DATA_
#define _GEN_RAND_DATA_

#include <cstdint>
#include <random>
#include <stdexcept>

namespace genRandData {

template <typename T>
bool checkRange(const T& min, const T& max) {
  return min <= max;
}

template <typename T, typename... Args>
struct is_any_of {
  static constexpr bool value =
      std::disjunction<std::is_same<T, Args>...>::value;
};

template <typename T>
struct is_integral_t {
  static constexpr bool value =
      std::is_integral<T>::value &&
      !is_any_of<T, int8_t, uint8_t, char, bool>::value;
};

template <typename T>
struct is_float_point_t {
  static constexpr bool value = std::is_floating_point<T>::value;
};

template <typename T>
struct is_char_t {
  static constexpr bool value = is_any_of<T, char, int8_t, uint8_t>::value;
};

template <typename T, typename Enable = void>
class Generator {};

/////////////////////// INTEGER TYPES ///////////////////////

template <typename T>
class Generator<T, typename std::enable_if<is_integral_t<T>::value>::type> {
 private:
  std::mt19937_64 gen{std::random_device{}()};
  std::uniform_int_distribution<T> dist;

 public:
  Generator(const T& min, const T& max) : dist{min, max} {}

  T getMin() noexcept(noexcept(dist.min())) { return dist.min(); }
  T getMax() noexcept(noexcept(dist.max())) { return dist.max(); }

  void setRange(const T& min, const T& max) {
    if (!checkRange(min, max)) {
      throw std::logic_error{"minRange > maxRange"};
    }

    dist = std::uniform_int_distribution<T>(min, max);
  }

  T operator()() { return dist(gen); }
};

/////////////////////// DOUBLE TYPES ///////////////////////

template <typename T>
class Generator<T, typename std::enable_if<is_float_point_t<T>::value>::type> {
 private:
  std::mt19937_64 gen{std::random_device{}()};
  std::uniform_real_distribution<T> dist;

 public:
  Generator(const T& min, const T& max) : dist{min, max} {}

  float getMin() noexcept(noexcept(dist.min())) { return dist.min(); }
  float getMax() noexcept(noexcept(dist.max())) { return dist.max(); }

  void setRange(const T& min, const T& max) {
    if (!checkRange(min, max)) {
      throw std::logic_error{"minRange > maxRange"};
    }

    dist = std::uniform_real_distribution<T>(min, max);
  }

  float operator()() { return dist(gen); }
};

/////////////////////// CHAR TYPES ///////////////////////

template <typename T>
class Generator<T, typename std::enable_if<is_char_t<T>::value>::type> {
 private:
  T mMinRange;
  T mMaxRange;

 public:
  Generator(const T& min, const T& max) : mMinRange{min}, mMaxRange{max} {
    if (!checkRange(min, max)) {
      throw std::logic_error{"minRange > maxRange"};
    }
  }

  int8_t getMin() const noexcept { return mMinRange; }
  int8_t getMax() const noexcept { return mMaxRange; }

  void setRange(const T& min, const T& max) {
    if (!checkRange(min, max)) {
      throw std::logic_error{"minRange > maxRange"};
    }

    mMinRange = min;
    mMaxRange = max;
  }

  int8_t operator()() {
    return mMinRange + rand() % (mMaxRange - mMinRange + 1);
  }
};

}  // namespace genRandData

#endif  // _GEN_RAND_DATA_
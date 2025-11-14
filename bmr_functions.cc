#include <limits>
#include <thread>
#include <chrono>
#include <algorithm>

#include "bmr.h"

BMR::BMR(double weight, double height, int age) noexcept
    : weight_{weight}, height_{height}, age_{age} {}

BMR::~BMR() {
  weight_ = 0;
  height_ = 0;
  age_ = 0;
}

const double BMR::GetWeight() const {
  return weight_;
}

const double BMR::GetHeight() const {
  return height_;
}

const int BMR::GetAge() const {
  return age_;
}

MAN::MAN(double weight, double height, int age) noexcept
    : BMR(weight, height, age) {}

MAN::~MAN() {}

double MAN::CalculateBMR() {
  return (4.536 * weight_) + (15.88 * height_) - (5 * age_) + 5;
}

WOMAN::WOMAN(double weight, double height, int age) noexcept
      : BMR(weight, height, age) {}

WOMAN::~WOMAN() {}

double WOMAN::CalculateBMR() {
  return (4.356 * weight_) + (15.88 * height_) - (5 * age_) - 161;
}

template <typename data>
data PromptForInput(const std::string& prompt) {
  data input;
  while (true) {
    TypeWriter(prompt);
    std::cin >> input;
    if (!std::cin) {
      std::cin.clear();
      std::cout << "\033[1;31m<< Please Try Again >>\033[0m\n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else if (input < 0) {
      std::cout << "\033[1;31m<< Value Cannot Be Less Than 0 >>\033[0m\n";
      continue;
    }
    return input;
  }
}

bool CanCompute(char letter) {
  return (letter == 'm') || (letter == 'w');
}

void SpinnerLoader(int duration_milli) {
  static const char* spinner{"|/-\\"};
  int load_length = 4;
  std::cout << "\033[1;34mCalculating BMR---";

  for (int count = 0; count < (duration_milli / 100); count++) {
    std::cout << '\b' << spinner[count % load_length] << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << "\b\033[0m\n";
}

void TypeWriter(const std::string& text, int delay_milli) {
  std::for_each(text.cbegin(), text.cend(), [&](char value) {
    std::cout << value << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(delay_milli));
  });
}

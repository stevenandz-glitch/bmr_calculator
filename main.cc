#include <iostream>
#include <string>
#include <cctype>

#include "bmr_functions.cc"

int main() {
  std::cout << "\033[1;36m=== BMR CALCULATOR ===\033[0m\n";
  BMR* parent_bmr = nullptr;
  const char gender{char(std::tolower(PromptForInput<char>("\033[38;5;212;1mPlease enter gender[m/w]: \033[0m")))};

  if (CanCompute(gender)) {
    double weight{PromptForInput<double>("\033[38;5;212;1mEnter weight in pounds: \033[0m")};
    double height{PromptForInput<double>("\033[38;5;212;1mEnter height in inches: \033[0m")};
    int age{PromptForInput<int>("\033[38;5;212;1mEnter age in years: \033[0m")};
    std::string_view calorie_text{" calories per day."};

    TypeWriter("\033[1;36mLet's See Your BMR\033[0m\n");
    if (gender == 'm') {
        parent_bmr = new MAN(weight, height, age);
        SpinnerLoader();
        std::cout << "\033[1;92mYour BMR is: " << parent_bmr->CalculateBMR()
                  << calorie_text << "\033[0m\n";
    } else {
        parent_bmr = new WOMAN(weight, height, age);
        SpinnerLoader();
        std::cout << "\033[1;92mYour BMR is: " << parent_bmr->CalculateBMR()
                  << calorie_text << "\033[0m\n";
    }

  } else {
    std::cout << "\033[1;31m<< Gender Could Not Be Found >>\033[0m\n";
  }

  delete parent_bmr;
  return 0;
}
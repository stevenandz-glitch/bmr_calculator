#ifndef BMR_H
#define BMR_H

class ABSTRACTBMR {
 public:
  virtual double CalculateBMR() = 0;
};

class BMR : public ABSTRACTBMR {
 public:
  BMR() = default;
  explicit BMR(double weight, double height, int age) noexcept;
  ~BMR();

  const double GetWeight() const;
  const double GetHeight() const;
  const int GetAge() const;

 protected:
  double weight_;
  double height_;
  int age_;
};

class MAN : public BMR {
 public:
  MAN() = default;
  explicit MAN(double weight, double height, int age) noexcept;
  ~MAN();
  double CalculateBMR();
};

class WOMAN : public BMR {
 public:
  WOMAN() = default;
  explicit WOMAN(double weight, double height, int age) noexcept;
  ~WOMAN();
  double CalculateBMR();
};

template <typename data>
data PromptForInput(const std::string& prompt);
bool CanCompute(char letter);
void SpinnerLoader(int duration_milli = 2000);
void TypeWriter(const std::string& text, int delay_milli = 40);

#endif
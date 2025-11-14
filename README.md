# BMR Calculator
This is an object oriented program that calculates the basal metabolic rate of a male or female. The formula I used for both male and female equation is the Miflin-St Jeor equation in which I used the function as an abstraction. The primary focus I had for when creating this program is the use of abstraction, inheritence, pointers, and polymorphism.

1. ## The Abstraction
For the use of abstraction, I decided to create an abstract function to calculate the bmr called `CalculateBMR()` which is made virtual and of type double. When I set it equal to 0, this means the function has to be used in any way as long as it returns a double.
```cpp
class ABSTRACTBMR {
 public:
  virtual double CalculateBMR() = 0;
};
```

2. ## Inheritence
After creating the `ABSTRACTBMR` class, I then exercised inheritence by making my base class, `BMR` inherit the virual function. `BMR` has to to use the function, however I decided to create child classes for each male and female respectivally. With that, they each inherit the `CalculateBMR()` function and I am allowed to create separate calculations for each. 
```cpp
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
```

3. ## Pointers


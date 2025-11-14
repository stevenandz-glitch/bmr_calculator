# BMR Calculator
This is an object oriented program that calculates the basal metabolic rate of a male or female. The formula I used for both male and female equation is the Miflin-St Jeor equation in which I used the function as an abstraction. The primary focus I had for when creating this program is the use of abstraction, inheritence, pointers, and polymorphism.

## 1. The Abstraction
For the use of abstraction, I decided to create an abstract function to calculate the bmr called `CalculateBMR()` which is made virtual and of type double. When I set it equal to 0, this means the function has to be used in any way as long as it returns a double.
```cpp
class ABSTRACTBMR {
 public:
  virtual double CalculateBMR() = 0;
};
```

## 2. Inheritence
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

## 3. Pointers
In the main function of the program, I decided to add some pointer flare. As my first exposer to pointer, I thought it best to use raw pointers to understand its usage. Here, I instantiated a `BMR` pointer in the global scope and assign it as a *`nullptr`*. This allows me to define it in a later block of code such as in my *`if-else`* statments. Since the pointer is raw, I would have to use the *`new`* and *`delete`* keywords to manually allocate to the heap and clean the resources used.
```cpp
BMR* parent_bmr = nullptr;
parent_bmr = new MAN(weight, height, age);
delete parent_bmr;
```

## 4. Polymorphism
In the code snippet from above, you can see that I create a `MAN` object after using the *`new`* keyword. This allocates memory from the heap to create a that object, however, in what was presented earlier, `MAN` is inherited from `BMR`. Therefore, a pointer of the base class `BMR` is assigned to its child object `MAN`. The same logic can be applied to the `WOMAN` class that is also inherited from `BMR`. This principle allows the base class to call member functions or variables from its child class(es), which allows for a class-relative defintion for inherited member functions. 
```cpp
BMR* parent_bmr = new MAN(weight, height, age);
parent_bmr->CalculateBMR();
parent_bmr = new WOMAN(weight, height, age);
parent_bmr->CalculateBMR();
```

## SAMPLE OUTPUT
1. Complile: *`g++ -o main main.cc`*
2. Run: *`./main`*
```
=== BMR CALCULATOR ===
Please enter gender[m/w]: m
Enter weight in pounds: 170
Enter height in inches: 69
Enter age in years: 23
Let's See Your BMR
Calculating BMR--\
Your BMR is: 1756.84 calories per day.
```





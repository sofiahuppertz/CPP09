# Module 09 - STL

## Introduction

This is the final C++ module, where we will integrate all the previous knowledge to solve more complex problems.

The main goal of this module is to dive deeper into the Standard Template Library (STL) and explore its containers 🧐.

Let's recap what we've learned in the previous modules:

***Classes, Namespaces, Overloading, “const” and “static” keywords, Inheritance, Dynamic Memory Allocation with “new” and “delete”, Switch Statements, Arrays of Function Pointers (instead of if/else blocks 🤢), References&, Streams<<, Exceptions, Templates, Type Casting, Polymorphism, Containers, and Iterators.***

Take a moment to appreciate all that you’ve learned. 😮‍💨

In this final module, the aim is to utilize these concepts as much as you can. I will explore the exercises, highlighting how these C++ concepts were applied to solve them.

## Exercises

### Ex00- Bitcoin Exchange

This exercise is about processing, storing and extracting information from input files. 

Since we are coding in an object-oriented paradigm, we will implement classes.

I created two classes: `DatesAndPrices` and `Date`. The `Date` class processes and stores dates conveniently for operations such as comparisons. This abstraction allows the `DatesAndPrices` class to focus on handling historical exchange rates databases (e.g., Bitcoin Exchange).

**DateAndPrices Class**

The `DatesAndPrices` class is designed using the Orthodox Canonical Form. Its constructor takes a string argument, "database," since an instance without information would be useless. This database is parsed and stored in a constant `std::map` (from the STL). Essentially, an instance of `DatesAndPrices` corresponds to a table of dates and prices for a currency like Bitcoin.

The class has two public member functions: `pricesForDate` and `printFees`. The key function is `printFees`, which processes a request from a file containing dates and values. It attempts to print the fees for an amount of currency on a given date. If the request is invalid, it prints a descriptive error. Errors can include out-of-range values or invalid dates. The `Date` class abstracts date complexity from the `DatesAndPrices` class. The `pricesForDate` function returns the price of 1 unit of currency on a given date. It is used by `printFees`. While `pricesForDate` could be private, I made it public for greater class flexibility.

**Date Class**

The `Date` class represents a date. It also follows the Orthodox Canonical Form and has two constructors: one that takes a string in the format "YYYY-MM-DD" and a default constructor that initializes the date to today. Upon construction, the `Date` class validates the date. I used a switch statement to validate the month, accounting for variations in the number of days (28 or 29 in February, 30 or 31 in other months).

```cpp
bool Date::_isValidDate(void) const
{
  if (_year < 0 || _month < 1 || _month > 12 || _day < 1) {
    return false;
  }
  int maxDay;
  switch (_month) {
    case 2:
      maxDay = 28;
      if (_year % 4 == 0 && (_year % 100 != 0 || _year % 400 == 0))
        maxDay = 29;
      break;
    case 4: case 6: case 9: case 11: maxDay = 30; break;
    default: maxDay = 31; break;
  }
  return _day <= maxDay;
}

```

Once the `Date` object is constructed, we can call `isInRange()` to determine whether a given date falls within a specified chronological period (e.g., ensuring the user isn’t asking for the price of Ethereum before it existed).

The `DatesAndPrices` class includes a constant `Date` that is initialized to the earliest date in the database. After validating the date, the `printFees()` function calls `isInRange()` for every requested date to ensure it falls within the valid range—from the earliest date in the database to today.

For testing, we are provided with a Bitcoin history database. However, I also wanted to include other currencies to create more instances of `DatesAndPrices`. To achieve this, I searched for Ethereum and Dogecoin historical data on Kaggle. Here is the final result:

<p align="center">
  <img src="./../images/mod09_ex00.png" alt="Console Output" width="700"/>
</p>

And, thanks to OOP 😏, the main is a simple as this: 

```cpp
int main ( void )
{
    try 
    {
        std::cout << "\t\t Bitcoin exchange fees: " << std::endl << std::endl;
        DatesAndPrices bitcoin(BITCOIN);
        bitcoin.printFees("static/input.csv");
        
        std::cout << std::endl << std::endl;
        std::cout << "\t\t Ethereum exchange fees: " << std::endl << std::endl;
        DatesAndPrices ether(ETHEREUM);
        ether.printFees("static/input.csv");

        std::cout << std::endl << std::endl;
        std::cout << "\t\t Doge coin exchange fees: " << std::endl << std::endl;
        DatesAndPrices doge(DOGE);
        doge.printFees("static/input.csv");
    } 
    catch (std::exception &e) 
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}
```

### Ex01 - Reverse Polish Notation

Reverse Polish Notation is a way of writing math equations where the operators (like +, -, *, /) come after the numbers instead of between them.

For example, instead of writing 2 + 3, in Reverse Polish Notation, we would write it as 2 3 +. You can read more about it [here](https://www.notion.so/4bd023993b944376bdb30408ffca7519?pvs=21).

**Purely Static Class for RPN Calculation**

For this exercise, I created a purely static class, which cannot be instantiated. This design choice aligns with most C++ math libraries, which consist of static functions offering methods for trigonometry, statistics, and other mathematical operations without needing an object.

The `RPN` class offers one function: `double RPN::calc(const std::string&)`, which calculates an expression written in Reverse Polish Notation.

**Implementation Details**

- **Stack Utilization**: I used a stack to manage terms, employing `push()`, `top()`, and `pop()` to add terms, retrieve the top term, and remove terms, respectively. When an operator is encountered, the relevant terms are popped from the stack, the operation is performed, and the result is pushed back onto the stack.
- **Function Pointers and Map**: An interesting feature is a map containing function pointers to the four basic operations (-, +, *, /) with their corresponding operator as a char key. This approach allows the use of STL methods to find operators, avoiding an extensive and cumbersome if/else statement.

```cpp
void RPN::performOperation ( std::string const &op, std::stack<double> &nums ) {
  
  double a, b;
  std::map <std::string, double(*)(double, double)> operations;
  operations["+"] = &RPN::add;
  operations["-"] = &RPN::sub;
  operations["*"] = &RPN::mlt;
  operations["/"] = &RPN::div;

  if (nums.size() < 2)
    throw RPN::execErrorException();
  b = nums.top();
  nums.pop();
  a = nums.top();
  nums.pop();

  if (operations.find(op) != operations.end())
    nums.push(operations[op](a, b));
}
```

This function is called inside the calc() public method. You can see both some of the stack interaction and the map to store operations. 

### Ex02- PmergeMe (Ford Johnson Algorithm)

Finally, let's talk about the Ford-Johnson Algorithm, also known as Merge Insertion Sort. [This post](https://www.linkedin.com/posts/nerraou_ford-johnson-merge-insertion-sort-activity-7076577075712675840-AJ1l) really helped me understand it.

### Steps of the Algorithm

1. **Pairing and Sorting**: Pair up consecutive indices and sort each pair in ascending order.
2. **Merge Sort Pairs**: Sort these pairs based on the first (larger) value in each pair.
3. **Generate Sequences**: Create a sorted sequence with the larger numbers from each pair and another sequence with the smaller ones.
4. **Jacobsthal Sequence**: Generate a Jacobsthal sequence for insertion.
5. **Insertion Sort**: Use the Jacobsthal sequence to perform insertion sort.

**Implementation Strategy**

We need to implement this algorithm for two different types of containers and compare their execution speeds. To avoid writing the same algorithm twice, violating the DRY (Don’t Repeat Yourself) principle, I decided to go with a template class approach.

**Template Class Design**

I created a template class with two templates (T and U). This class handles both a container of integers and a container of pairs of integers. The abstract template class `FJA<T, U>` implements the core algorithm. Then, I made specialized classes, `PmergeMeVector` and `PmergeMeDeque`, which inherit from `FJA` and are instantiated with `vector`, `deque`, `vector<pair>`, and `deque<pair>`, respectively.

Since inheriting from `FJA` is simple, I also added a `PmergeMeList` class for fun, showing that this approach can be extended to any container. To make sure the code works for all container types, even those without random access iterators, I used iterator methods like `std::distance()`, `std::next()`, and `std::advance()`.

```
template <class T, class U>
typename T::iterator FJA<T, U>::binarySearch(int value, typename T::iterator left, typename T::iterator right)
{
  typename T::iterator mid;
  while (std::distance(left, right) > 1)
  {
    mid = left;
    std::advance(mid, std::distance(left, right) / 2);
    if (value >*mid)
      left = mid;
    else
      right = mid;
  }
  if (value > *left)
    return std::next(left);
  return left;
}

```

## Resources

If you'd like to dive deeper into my code, you can find my GitHub repository [here](https://github.com/sofiahuppertz/42-CPP-modules/tree/main/mod09).

Thanks for reading!

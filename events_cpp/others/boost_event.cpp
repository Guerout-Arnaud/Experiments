#include <iostream>
#include <functional>
#include <boost/signals2.hpp>

void func()
{
    std::cout << "func" << std::endl;
}

void func1()
{
    std::cout << "func1" << std::endl;
}

int test(int i, int j)
{
    std::cout << "test " << i << ", " << j << std::endl;
    return (i + j);
}

// class AEvent {
//     public:
//         A(void) {
//         }
//         ~A(void) {
//         }

//     private:
//         boost::signals2::signal<T> _signal;
// };


int main(int argc, char **argv)
{
// Signal with no arguments and a void return value
  boost::signals2::signal<void()> sig;
  boost::signals2::signal<int (int, int)> sig2;

  // Connect a HelloWorld slot
  sig.connect(func1);
  sig.connect(func);
  sig2.connect(test);

  // Call all of the slots
  sig();
  int rtn = sig2(10, 12).value();
  std::cout << "rtn: " << rtn << std::endl;
}
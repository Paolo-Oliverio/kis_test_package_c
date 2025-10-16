#include "../include/kis_test_package_c/kis_test_package_c.hpp"
#include <kis_test_package_b/kis_test_package_b.hpp>
#include <iostream>

namespace kis{
namespace test_package_c{

void hello() {
    test_package_b::hello();
    std::cout << "Hello from kis_test_package_c!" << std::endl;
}

}
}
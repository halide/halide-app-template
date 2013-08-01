#include <Halide.h>

using namespace Halide;

int main(int argc, char **argv) {

    Var x("x"), y("y");
    Func f("f"), g("g");
    
    f(x, y) = x+y;
    g(x, y) = f(x-1, y) + f(x+1, y);
    
    Image<int32_t> im = g.realize(100, 100);

    return 0;
}

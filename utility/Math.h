#include <cmath>

#define PI 3.141592

namespace Math {

    double VelocityToAngle(double xv, double yv) {
        return atan2(xv, yv) * (180 / PI);
    }
}
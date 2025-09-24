#include "template.hpp"

using Point = complex<double>;

double dot(const Point& a, const Point& b) { return (std::conj(a) * b).real(); }

Point projection(const Point& p0, const Point& p1, const Point& p) {
  Point base = p1 - p0, hyp = p - p0;
  double t = dot(base, hyp) / norm(base);
  return p0 + t * base;
}

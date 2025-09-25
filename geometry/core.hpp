#pragma once
#include "template.hpp"

using Point = complex<double>;

struct Line {
  Point a, b;
  Line() = default;
  Line(const Point& _a, const Point& _b) : a(_a), b(_b) {}
};

constexpr double eps = 1.0e-9;

double dot(const Point& a, const Point& b) { return (conj(a) * b).real(); }
double cross(const Point& a, const Point& b) { return (conj(a) * b).imag(); }

Point projection(const Point& p0, const Point& p1, const Point& p) {
  Point base = p1 - p0, hyp = p - p0;
  double t = dot(base, hyp) / norm(base);
  return p0 + t * base;
}

Point reflection(const Point& p0, const Point& p1, const Point& p) {
  Point proj = projection(p0, p1, p);
  return 2.0 * proj - p;
}

constexpr int COUNTER_CLOCKWISE = 1;
constexpr int CLOCKWISE = -1;
constexpr int ONLINE_BACK = 2;
constexpr int ONLINE_FRONT = -2;
constexpr int ON_SEGMENT = 0;

int ccw(const Point& p0, const Point& p1, const Point& p2) {
  Point a = p1 - p0, b = p2 - p0;
  if (eps < cross(a, b)) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -eps) return CLOCKWISE;
  if (dot(a, b) < -eps) return ONLINE_BACK;
  if (norm(a) < norm(b))
    return ONLINE_FRONT;
  else
    return ON_SEGMENT;
}

bool is_parallel(const Line& l0, const Line& l1) {
  return abs(cross(l0.b - l0.a, l1.b - l1.a)) < eps;
}

bool is_orthogonal(const Line& l0, const Line& l1) {
  return abs(dot(l0.b - l0.a, l1.b - l1.a)) < eps;
}

bool has_intersection(Line s0, Line s1) {
  rep(_, 2) {
    if (0 < ccw(s0.a, s0.b, s1.a) * ccw(s0.a, s0.b, s1.b)) {
      return false;
    }
    swap(s0, s1);
  }
  return true;
}

Point cross_point(const Line& l0, const Line& l1) {
  double d0 = cross(l0.b - l0.a, l1.b - l1.a),
         d1 = cross(l0.b - l0.a, l0.b - l1.a);
  if (abs(d0) < eps && abs(d1) < eps) {
    return l1.a;
  }
  return l1.a + d1 / d0 * (l1.b - l1.a);
}

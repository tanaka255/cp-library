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
  return 2.0 * projection(p0, p1, p) - p;
}

constexpr int COUNTER_CLOCKWISE = 1, CLOCKWISE = -1, ONLINE_BACK = 2,
              ONLINE_FRONT = -2, ON_SEGMENT = 0;

int ccw(const Point& p0, const Point& p1, const Point& p2) {
  Point a = p1 - p0, b = p2 - p0;
  if (eps < cross(a, b)) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -eps) return CLOCKWISE;
  if (dot(a, b) < -eps) return ONLINE_BACK;
  if (norm(a) < norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool is_parallel(const Line& l0, const Line& l1) {
  return abs(cross(l0.b - l0.a, l1.b - l1.a)) < eps;
}

bool is_orthogonal(const Line& l0, const Line& l1) {
  return abs(dot(l0.b - l0.a, l1.b - l1.a)) < eps;
}

bool has_intersection(Line s0, Line s1) {
  return ccw(s0.a, s0.b, s1.a) * ccw(s0.a, s0.b, s1.b) <= 0 &&
         ccw(s1.a, s1.b, s0.a) * ccw(s1.a, s1.b, s0.b) <= 0;
}

Point cross_point(const Line& l0, const Line& l1) {
  double d0 = cross(l0.b - l0.a, l1.b - l1.a),
         d1 = cross(l0.b - l0.a, l0.b - l1.a);
  if (abs(d0) < eps && abs(d1) < eps) return l1.a;
  return l1.a + d1 / d0 * (l1.b - l1.a);
}

double distance_between_point_and_segment(const Point& p, const Line& s) {
  if (dot(s.b - s.a, p - s.a) < eps) return abs(p - s.a);
  if (dot(s.a - s.b, p - s.b) < eps) return abs(p - s.b);
  return abs(cross(s.b - s.a, p - s.a)) / abs(s.b - s.a);
}

double distance_between_segments(const Line& s0, const Line& s1) {
  if (has_intersection(s0, s1)) return 0.0;
  double ret = numeric_limits<double>::max();
  chmin(ret, distance_between_point_and_segment(s0.a, s1));
  chmin(ret, distance_between_point_and_segment(s0.b, s1));
  chmin(ret, distance_between_point_and_segment(s1.a, s0));
  chmin(ret, distance_between_point_and_segment(s1.b, s0));
  return ret;
}

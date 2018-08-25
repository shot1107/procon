#include <bits/stdc++.h>
using namespace std;

#define int long long

#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
#define PI 3.141592653589793238

struct Point3D {
  double x, y, z;
  Point3D() {}
  Point3D(double x, double y, double z) :
    x(x), y(y), z(z) {}
  Point3D operator+(Point3D p) {
    return Point3D(x+p.x, y+p.y, z+p.z);
  }
  Point3D operator-(Point3D p) {
    return Point3D(x-p.x, y-p.y, z-p.z);
  }
  Point3D operator*(double k) {
    return Point3D(x*k, y*k, z*k);
  }
  Point3D operator/(double k) {
    return Point3D(x/k, y/k, z/k);
  }
  Point3D operator*(Point3D p) {
    return Point3D(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
  }
  double operator^(Point3D p) {
    return x*p.x + y*p.y + z*p.z;
  }
  double norm() {
    return x*x + y*y + z*z;
  }
  double abs() {
    return sqrt(norm());  
  }
  bool operator<(const Point3D &p) const {
    if ( x != p.x ) return x < p.x;
    if ( y != p.y ) return y < p.y;
    return z < p.z;    
  }
  bool operator==(const Point3D &p) const {
    return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS && fabs(z-p.z)<EPS;
  }
};

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  
  
  return 0;
}

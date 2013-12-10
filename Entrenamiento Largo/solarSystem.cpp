# include <bits/stdc++.h>
# define PI acos(0.0)
using namespace std;

double a1,b1,t1,a2,b2,t,e2;

#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

const double INF = 1e100;
const double EPS = 1e-12;
const double N = 100000.0;


struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
};

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) { 
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}



double myFun(double angle1, double angle2){
    double delta = (angle2 -angle1)/N;
    while(angle1 < angle2){
        area
    }
    
}

double elipseAt(double x){
    return (b2/a2)*sqrt((a2*a2) - (x*x));
}

int main(){
    int cont = 0;
    while(cin >> a1 >> b1 >> t1 >> a2 >> b2 >> t and (a1 + b1 + t1 + a2 + b2 + t)){
    
        double t2 = t1*sqrt((a2/a1)*(a2/a1)*(a2/a1));
        double c2 = sqrt(a2*a2 - b2*b2);
        e2 = sqrt(1 - (b2*b2/a2*a2));
        double totalarea = PI*a2*b2;
        double sectionPerDay = totalarea/t2;
        target = ((t <= t2)? t:t%t2)*sectionPerDay;//if the time to determine the position of p2 is greater than t2 then the time is t%t2.
        double low = 0.0;
        double high = 2.0*PI;
        
        while(true){
            double val = (low + ((high - low)/2.0));
            double eval = myFun(low,val);
            if(eval < target)high = val;
            else low = val;
        }
        
        //computing the solution after finding the angle which subtends the area that i'm looking for
        double A = ((tan(val)*tan(val)) + ((b2*b2)/(a2*a2)));
        double B = 2.0*tan(val)*tan(val)*c2;
        double C = ((tan(val)*tan(val)*c2*c2)) - (b2*b2);
        double X1 = (-B + sqrt(B*B - (4.0*A*C)))/(2.0*A);//compunting the possible values of x, must be two.
        double X2 = (-B - sqrt(B*B - (4.0*A*C)))/(2.0*A);
        
        //computing the positive values of y
        double Y1 = elipseAt(X1);
        double Y2 = elipseAt(X2);
        
        double Y11 = -elipseAt(X1);
        double Y22 = -elipseAt(X2);
        
        PT ans;
        
        if(val > 0.0 && val < PI){
            PT p1 = PT(X1, Y1);
            PT p2 = PT(X2, Y2);
            PT focus = PT(-c2,0.0);
            p1 = p1 - focus;
            p2 = p2 - focus;
            PT mio1 = PT(X1, 0.0);
            PT mio2 = PT(X2, 0.0);
            if(dot(RotateCCW(mio1, val), p1) < EPS) ans = PT(X1, Y1);
            else if(dot(RotateCCW(mio2, val), p2) < EPS) ans = PT(X2, Y2);
        }
        else if(val > PI && val < 2.0*PI){
            PT p1 = PT(X1, Y11);
            PT p2 = PT(X2, Y22);
            PT focus = PT(-c2,0.0);
            p1 = p1 - focus;
            p2 = p2 - focus;
            PT mio1 = PT(X1, 0.0);
            PT mio2 = PT(X2, 0.0);
            if(dot(RotateCCW(mio1, val), p1) < EPS) ans = PT(X1, Y11);
            else if(dot(RotateCCW(mio2, val), p2) < EPS) ans = PT(X2, Y22);
        }
        cout<<"Solar System "<<cont++<<": "<<ans.x<<" "<<ans.y<<endl;
    }
    return 0;
}

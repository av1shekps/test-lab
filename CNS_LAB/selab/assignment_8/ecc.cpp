#include <bits/stdc++.h>
#include <random>
#include "gmp.h"
#include "gmpxx.h"

using namespace std;

//Global declarations : 
mpz_class q,A,B;


struct point
{
	mpz_class x=-1,y=-1;
	// (-1,-1) denotes point at inf
};

mpz_class inverse(mpz_class a, mpz_class& n) {
    mpz_class r = 1;

    for(size_t i=1; i<n; i++){
    	if( (a*i)%n == 1){
    		r = i;
    		return r;
    	}
    }

    return r;
}

point addition(point a, point b) {
	point ans;

	if(a.x==b.x && a.y==b.y) {
		if(a.y == 0){
			return ans;
		}
		// Point doubling
		mpz_class m = ((3*a.x*a.x + A) * inverse(2*a.y,q))%q;
		ans.x = (m*m-2*a.x+q)%q;
		ans.y = ((m*(a.x-ans.x+q))%q-a.y+q)%q;
		return ans;
	}

	if(a.x == b.x) return ans; // x1=x2, y1!=y2, line parallel to Y-axis

	mpz_class m = ((b.y-a.y+q)*(inverse(b.x-a.x+q,q)))%q;
	ans.x = (m*m-a.x-b.x+2*q)%q;
	ans.y = ((m*(a.x-ans.x+q))%q-a.y+q)%q;
	return ans;
}

point doubling(point a) {
	return addition(a,a);
}




int main () {

	cout << "y^2 = x^3 + ax + b mod q\n\n";
	cout<<"q = "; cin>>q;
	cout<<"a = "; cin>>A;
	cout<<"b = "; cin>>B;

	cout<<"Enter 2 points P,Q such that Q = kP\n";
	point p,q;
	cout<<"Enter co-ordinates of P : "; cin>>p.x>>p.y;
	cout<<"Enter co-ordinates of Q : "; cin>>q.x>>q.y;

	vector<point> points(1000);
	points[0] = points[1] = p;

	for(size_t i=2; i<20; i++){
		points[i] = addition(p,points[i-1]);

		if(q.x == points[i].x && q.y == points[i].y){
			cout<<"k = "<<i<<"\n\n";
			return 0;
		}
	}

	return 0;
}

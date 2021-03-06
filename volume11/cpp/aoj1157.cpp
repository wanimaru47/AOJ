#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-10
#define EQ(a,b) (abs(a - b) < EPS)
#define EQV(a,b) ( EQ((a).real(), (b).real()) && EQ((a).imag(), (b).imag()))

using namespace std;

typedef complex<double> P;

//外積
double cross (P a, P b) {return (a.real() * b.imag() - a.imag() * b.real());}

//内積
double dot (P a, P b) {return (a.real() * b.real() + a.imag() * b.imag());}

//直行
bool is_orthogonal(P a1, P a2, P b1, P b2) {return EQ( dot(a1 - a2, b1 - b2), 0.0);}

//平行
bool is_parallel(P a1, P a2, P b1, P b2) {return EQ( cross(a1 - a2, b1 - b2), 0.0);}

//直線上
bool is_point_on_vector(P a, P b, P c) {return EQ( cross(a - c, c - b), 0.0);}

//線分上
bool is_point_on_line (P a, P b, P c) {return (abs(a - c) + abs(c - b) < abs(a - b) + EPS);}

//角度　線分の距離は小数点以下３桁まで
double angle (P a, P b, P p) {return (acos(dot(a-p,b-p) / (abs(a-p) * abs(b-p))) * 180.0 / M_PI);}

// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
bool is_intersected_ls(P a1, P a2, P b1, P b2) {
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < -EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < -EPS );
}

// a1,a2を通る直線とb1,b2を通る直線の交差判定
bool is_intersected_l(P a1, P a2, P b1, P b2) {return !EQ( cross(a1-a2, b1-b2), 0.0 );}

// 点a,bを通る直線と点cとの距離
double distance_l_p(P a, P b, P c) {return abs(cross(b-a, c-a)) / abs(b-a);}

// a1,a2を通る直線とb1,b2を通る直線の交点計算
P intersection_l(P a1, P a2, P b1, P b2) {
    P a = a2 - a1; P b = b2 - b1;
    return a1 + a * cross(b, b1-a1) / cross(b, a);
}

// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(P a, P b, P c) {
    if ( dot(b-a, c-a) < EPS ) return fabs(c-a);
    if ( dot(a-b, c-b) < EPS ) return fabs(c-b);
    return fabs(cross(b-a, c-a)) / fabs(b-a);
}

/***************************************
 *
 * 2点を通る直線とある点からの垂線との交点
 *
 * a, b を直線
 * p    をある点
 *
 ***************************************/
P crossNormalVector (P a, P b, P p) {
    double t = dot(b-a, p-a) / (abs(b-a) * abs(b - a));
    return a + t * (b - a);
}

double calc (double h, double r) {
    if (h > r) h = r;
    return (r * r + h * h) / (2 * h);
}

int main ()
{
    int n;
    while (cin >> n, n) {
        double sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        P s(sx, sy), e(ex, ey);

        double res_h = 1000.;
        while (n--) {
            // cout << "Count # " << n << endl;
            
            double minx, miny, maxx, maxy;
            double h;
            cin >> minx >> miny >> maxx >> maxy >> h;

            vector<P> v = { P(minx, miny), P(minx, maxy), P(maxx, maxy), P(maxx, miny)};

            if (minx <= s.real() && s.real() <= maxx && miny <= s.imag() && s.imag() <= maxy) res_h = 0.;
            if (minx <= e.real() && e.real() <= maxx && miny <= e.imag() && e.imag() <= maxy) res_h = 0.;

            for (int i = 0; i < 4; i++) {
                int anf = (i + 1) % 4; // , bfr = (i + 4 - 1) % 4;
                int now = i;

                if (is_intersected_ls(e, s, v[now], v[anf])) res_h = 0.;
                // if (is_intersected_ls(e, s, v[now], v[bfr])) res_h = 0.;
                
                // cout << "DBG > " << min(v[now].real(), v[anf].real()) << " " << max(v[now].real(), v[anf].real()) << endl;
                // cout << "      " << min(v[now].imag(), v[anf].imag()) << " " << max(v[now].imag(), v[anf].imag()) << endl;
                res_h = min(res_h, calc(h, distance_ls_p(v[now], v[anf], s)));
                // res_h = min(res_h, calc(h, distance_ls_p(v[now], v[bfr], s)));
                res_h = min(res_h, calc(h, distance_ls_p(v[now], v[anf], e)));
                // res_h = min(res_h, calc(h, distance_ls_p(v[now], v[bfr], e)));
                // res_h = min(res_h, calc(h, min(abs(minx - s.real()), abs(maxx - s.real()))));
                // res_h = min(res_h, calc(h, min(abs(miny - s.imag()), abs(maxy - s.imag()))));
                res_h = min(res_h, calc(h, distance_ls_p(s, e, v[now])));
                res_h = min(res_h, calc(h, distance_ls_p(s, e, v[anf])));
                // res_h = min(res_h, calc(h, distance_ls_p(s, e, v[bfr])));
            }
        }

        printf("%.4f\n", res_h);
    }

    return 0;
}

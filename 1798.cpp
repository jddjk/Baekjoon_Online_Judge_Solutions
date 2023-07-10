#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265

double toRadian(double degree) {
    return degree * PI / 180.0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(2);

    double radius, height, d1, angle1, d2, angle2;
    while (cin >> radius >> height >> d1 >> angle1 >> d2 >> angle2) {
        double R = sqrt(height * height + radius * radius);
        double T = 2.0 * PI * radius / R;

        angle2 = abs(angle1 - angle2);
        if (angle2 > 180.0)
            angle2 = 360.0 - angle2;

        double shortest_distance = sqrt(
            (d1 * d1 + d2 * d2) - 2 * d1 * d2 * cos(toRadian(angle2) * T / (2.0 * PI))
        );

        cout << shortest_distance << "\n";
    }

    return 0;
}

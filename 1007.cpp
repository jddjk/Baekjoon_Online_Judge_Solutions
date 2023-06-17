#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const int MAX_N = 20;
int selected[MAX_N];
double const INF = 1e18;
double min_distance;
int test_cases, num_points, half;
int coordinates_x[MAX_N], coordinates_y[MAX_N];
int sum_x, sum_y;

double power(double base, int exponent) {
    double result = 1;
    for(int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

void find_min_distance(int total, int left, int idx)
{
    if (left == 0)
    {
        int temp_x = sum_x;
        int temp_y = sum_y;
        for (int i = 0; i < idx; i++)
        {
            temp_x -= 2 * coordinates_x[selected[i]];
            temp_y -= 2 * coordinates_y[selected[i]];
        }
        double distance = sqrt(power(temp_x, 2) + power(temp_y, 2));
        if (distance < min_distance) min_distance = distance;
    }
    else if (total < left) return;
    else
    {
        selected[left - 1] = total - 1;
        find_min_distance(total - 1, left - 1, idx);
        find_min_distance(total - 1, left, idx);
    }
}

int main(void)
{
    cin >> test_cases;
    for (int i = 0; i < test_cases; i++)
    {
        sum_x = 0;
        sum_y = 0;
        min_distance = INF;
        cin >> num_points;
        for (int j = 0; j < num_points; j++)
        {
            cin >> coordinates_x[j] >> coordinates_y[j];
            sum_x += coordinates_x[j];
            sum_y += coordinates_y[j];
        }
        half = num_points / 2;
        find_min_distance(num_points, half, half);
        cout << fixed << setprecision(12) << min_distance << "\n";
    }

    return 0;
}

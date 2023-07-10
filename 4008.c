#include <stdio.h>
#include <stdlib.h>
#define INF 1e10
#define ll long long

typedef struct Line {
    ll m, b;
    double x;
} Line;

double intersect(Line a, Line b) {
    return (double)(b.b - a.b) / (a.m - b.m);
}

void addLine(Line *lines, ll m, ll b, int *size) {
    Line a = {m, b, -INF};
    while ((*size) > 0 && intersect(lines[(*size) - 1], a) <= lines[(*size) - 1].x) {
        (*size)--;
    }
    if ((*size) > 0) {
        a.x = intersect(lines[(*size) - 1], a);
    }
    lines[(*size)++] = a;
}

ll query(Line *lines, ll x, int *size, int *ptr) {
    while ((*ptr) < (*size) - 1 && lines[(*ptr) + 1].x < x) {
        (*ptr)++;
    }
    return lines[*ptr].m * x + lines[*ptr].b;
}

ll f(ll x, ll A, ll B, ll C) {
    return A * x * x + B * x + C;
}

int main() {
    int N, size = 0, ptr = 0;
    ll A, B, C;
    scanf("%d", &N);
    scanf("%lld %lld %lld", &A, &B, &C);

    ll *a = (ll*)malloc((N+1) * sizeof(ll));
    ll *pre = (ll*)malloc((N+1) * sizeof(ll));
    ll *dp = (ll*)malloc((N+1) * sizeof(ll));
    Line *lines = (Line*)malloc((N+1) * sizeof(Line));

    for (int i = 1; i <= N; ++i) scanf("%lld", &a[i]);
    for (int i = 1; i <= N; ++i) pre[i] = pre[i - 1] + a[i];

    dp[1] = f(pre[1], A, B, C);
    addLine(lines, -2 * A * pre[1], A * pre[1] * pre[1] - B * pre[1] + dp[1], &size);

    for (int i = 2; i <= N; ++i) {
        dp[i] = f(pre[i], A, B, C);
        if (size > 0) dp[i] = (ll)fmax(dp[i], query(lines, pre[i], &size, &ptr) + f(pre[i], A, B, C));
        addLine(lines, -2 * A * pre[i], A * pre[i] * pre[i] - B * pre[i] + dp[i], &size);
    }

    printf("%lld\n", dp[N]);

    free(a);
    free(pre);
    free(dp);
    free(lines);
    return 0;
}

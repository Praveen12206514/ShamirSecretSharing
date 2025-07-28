#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef long long ll;

ll interpolateConstantTerm(const vector< pair<ll, ll> >& points) {
    ll result = 0;
    int k = points.size();

    for (int i = 0; i < k; ++i) {
        ll xi = points[i].first;
        ll yi = points[i].second;

        ll num = 1, den = 1;
        for (int j = 0; j < k; ++j) {
            if (i == j) continue;
            ll xj = points[j].first;
            num *= -xj;
            den *= (xi - xj);
        }

        result += yi * (num / den);
    }

    return result;
}

int main() {
    // Test Case 1
    vector< pair<ll, ll> > test1;
    test1.push_back(make_pair(1LL, 4LL));
    test1.push_back(make_pair(2LL, 7LL));
    test1.push_back(make_pair(3LL, 12LL));

    ll secret1 = interpolateConstantTerm(test1);
    cout << "Secret from Test Case 1: " << secret1 << endl;

    // Test Case 2
    vector< pair<ll, ll> > test2;
    test2.push_back(make_pair(1LL, 81936557197480841LL));
    test2.push_back(make_pair(2LL, 13894389926600291LL));
    test2.push_back(make_pair(3LL, 481897046875904444LL));
    test2.push_back(make_pair(4LL, 101452116366057823LL));
    test2.push_back(make_pair(5LL, 1224950156486721939LL));
    test2.push_back(make_pair(6LL, 17034884422207411849LL)); // made it signed to match type
    test2.push_back(make_pair(7LL, 9940795082943253465LL));

    ll secret2 = interpolateConstantTerm(test2);
    cout << "Secret from Test Case 2: " << secret2 << endl;

    return 0;
}


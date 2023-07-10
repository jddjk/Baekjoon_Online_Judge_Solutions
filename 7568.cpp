#include <iostream>
#include <vector>
using namespace std;

struct Person {
    int weight;
    int height;
};

vector<int> calculateRank(vector<Person>& people) {
    vector<int> ranks(people.size(), 1);

    for (int i = 0; i < people.size(); i++) {
        for (int j = 0; j < people.size(); j++) {
            if (people[i].weight < people[j].weight && people[i].height < people[j].height) {
                ranks[i]++;
            }
        }
    }

    return ranks;
}

int main() {
    int N;
    cin >> N;

    vector<Person> people(N);
    for (int i = 0; i < N; i++) {
        cin >> people[i].weight >> people[i].height;
    }

    vector<int> ranks = calculateRank(people);

    for (int i = 0; i < ranks.size(); i++) {
        cout << ranks[i] << " ";
    }
    cout << endl;

    return 0;
}

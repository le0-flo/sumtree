#include <iostream>
#include <numeric>
#include <cstring>
#include <vector>

int get_beauty(std::vector<std::vector<bool>> links, std::vector<int> values, std::vector<bool> line, int previous, int current, int a, int b, int n) {
    int temp, tot = 0;

    if (current == b) return values.at(current);

    for (int i=0; i<n; i++) {
        if (line.at(i) && i != previous) {
            temp = get_beauty(links, values, links.at(i), current, i, a, b, n);
            if (temp > 0) tot += values.at(current) + temp;
        }
    }

    return tot;
}

int main() {

    int n, a, b, t;
    std::cin >> n;

    std::vector<int> values(n);
    std::vector<std::vector<bool>> links(n, std::vector<bool>(n, 0));

    for (int i=0; i<n; i++) {
        std::cin >> values.at(i);
    }

    for (int i=0; i<n-1; i++) {
        std::cin >> a >> b;
        links.at(a-1).at(b-1) = true;
        links.at(b-1).at(a-1) = true;
    }

    std::cout << "\nConnection matrix\n";

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            std::cout << links.at(i).at(j) << (j<n-1 ? ", " : "\n");
        }
    }

    std::cout << std::endl;

    int tot = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            else if ((int)std::gcd(values.at(i), values.at(j)) != 1 && i < j) {
                tot += get_beauty(links, values, links.at(i), i, i, i, j, n);
                std::cout << "(" << i+1 << "," << j+1 << "): gcd(" << values.at(i) << "," << values.at(j) << ") = " << (int)std::gcd(values.at(i), values.at(j)) << " | Beauty: " << get_beauty(links, values, links.at(i), i, i, i, j, n) << std::endl;
            }
        }
    }

    std::cout << "\n\nRisultato: " << tot << std::endl;

    return 0;
}

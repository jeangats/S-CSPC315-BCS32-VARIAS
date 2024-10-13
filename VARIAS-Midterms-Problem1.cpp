# Problem 1: Mathematical Foundations

#include <iostream>
#include <vector>
#include <cmath>

int main() {
    // INPUT

    // A vector of pairs representing the delivery points
    std::vector<std::pair<int, int>> NpointsList;

    // N as the total number of delivery points in 2D space
    int N;
    std::cout << "Enter total number of delivery points: ";
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int x, y;
        std::cout << "Enter x and y coordinates of delivery point " << i + 1 << ": ";
        char comma; // to consume the comma
        std::cin >> x >> comma >> y;
        NpointsList.emplace_back(x, y);
    }

    // Computes the total distance traveled for the sequence of points
    double TotalDistance = 0;
    for (int i = 0; i < N - 1; ++i) {
        int x1 = NpointsList[i].first;
        int y1 = NpointsList[i].second;
        int x2 = NpointsList[i + 1].first;
        int y2 = NpointsList[i + 1].second;

        // Using Pythagorean theorem to calculate the distance between two delivery points
        double d = std::sqrt(std::pow(x2 - x1, 2) + std::pow(y2 - y1, 2));

        // Adding each distance between each point together to get the total distance traveled for the sequence of points
        TotalDistance += d;
    }

    // Calculates the sum of the first N natural numbers using summation formulas
    int SumN = (N * (N + 1)) / 2;

    // OUTPUT
    std::cout << "Total distance for the sequence of delivery points: ";
    for (const auto& point : NpointsList) {
        std::cout << "(" << point.first << ", " << point.second << ") ";
    }
    std::cout << ": " << TotalDistance << std::endl;
    std::cout << "Sum of the first " << N << " natural numbers: " << SumN << std::endl;

    return 0;
}


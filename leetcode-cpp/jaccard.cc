#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <set>
#include <unordered_set>

#include <vector>
float Jaccard(std::vector<int> labels_a, std::vector<int> labels_b) {
    std::vector<int> inter_sect;
    std::set_intersection(labels_a.begin(), labels_a.end(), labels_b.begin(), labels_b.end(), inter_sect);
    int inter_sect_number = inter_sect.size();
    int union_sect_number = labels_a.size() + labels_b.size() - inter_sect_number;
    return (float) inter_sect_number / (float) union_sect_number;
}

void SortGroups(std::vector<std::vector<int>> group) {
    for (auto &labels : group) {
        std::sort(labels.begin(), labels.end());
    }
}

int main(int argc, char *argv[]) {
    int n = 0;
    std::cin >> n;
    float result = 1.0f;
    //std::vector<std::unordered_set<int>> groups;
    std::vector<std::vector<int>> groups;
    std::vector<std::vector<int>> jaccard_memory;
    for (int i = 0; i < n; ++i) {
        int number;
        std::cin >> number;
        //std::unordered_set<int> labels;
        std::vector<int> labels(number);
        for (int j = 0; j < number; ++j) {
            int value = 0;
            std::cin >> value;
            //labels.insert(value);
            labels[i] = value;
        }
        groups.push_back(labels);
    }
    SortGroups(groups);
    for (int i = 0; i < groups.size(); ++i) {
        std::vector<int> jaccard_list;
        auto labels_a = groups[i];
        for (int j = i + 1; j < groups.size(); ++j) {
            auto lables_b = groups[j];
            jaccard_list.push_back(Jaccard(labels_a, lables_b));
        }
    }

    std::cout << std::fixed << std::setprecision(4) << result;
}
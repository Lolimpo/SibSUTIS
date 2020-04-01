#include <iostream>
#include <vector>
#include <algorithm>
int item_n, bp_n;

int solve(std::vector<int> &m, std::vector<int> &c){
    int n = m.size();
    std::vector<int> backpack(bp_n + 1);
    backpack[0] = 0;
    for(int w = 1; w <= bp_n; w++){
        backpack[w] = backpack[w - 1];
        for(int i = 0; i < n; i++){
            if(m[i] <= w){
                backpack[w] = std::max(backpack[w], backpack[w - m[i]] + c[i]);
                std::cout << "BackPack " << w << " maximal cost: " << backpack[w] << std::endl;
            }
        }
    }
    for(int i = 0; i < backpack.size(); i++){
        std::cout << "F[" << i << "] = " << backpack[i] << std::endl;
    }
    return backpack[bp_n];
}

int main(){
    int temp = 0;
    std::vector<int> m, c;
    std::cout << "Enter your number of items: " << std::endl;
    std::cin >> item_n;
    std::cout << "Enter backpack's maximum weight: " << std::endl;
    std::cin >> bp_n;
    m.resize(item_n), c.resize(item_n);
    std::cout << "Enter item's mass and cost: " << std::endl;
    for(int i = 0; i < item_n; i++){
            std::cin >> m[i] >> c[i];
    }
    int ans = solve(m, c);
    std::cout << "Maximal cost for " << bp_n << " kg backpack: " << ans << std::endl;
    while(ans){
        if(ans % c[item_n - 1])
            a
    }
    return 0;
}
//3 8 5 13 8 23
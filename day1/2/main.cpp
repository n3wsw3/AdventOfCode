#include <fstream>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> input;
    std::ifstream is("../input.in");
    int x;
    while (is >> x)
    {
        input.push_back(x);
    }

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 0; j < input.size(); j++)
        {
            for (int k = 0; k < input.size(); k++)
            {
                if (input[i] + input[j] + input[k] == 2020)
                {
                    std::cout << "Answer: " << input[i] * input[j] * input[k] << std::endl;
                    return 0;
                }
            }
        }
    }
}
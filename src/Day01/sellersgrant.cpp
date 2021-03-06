#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <set>

int problemOne(std::ifstream* inputFile)
{    
    std::string line;
    int sum = 0;

    while (getline(*inputFile, line))
    {
        sum += std::stoi(line);
    }   
    return sum;
}

int problemTwo(std::ifstream* inputFile)
{
    std::string line;
    int sum = 0;
    std::set<int, std::less<int>> repeatedSums;
    std::set<int, std::less<int>>::iterator it;
    
    repeatedSums.insert(sum);

    
    while (true)
    {
        if (!getline(*inputFile, line))
        {
            inputFile->clear();
            inputFile->seekg(0,std::ios::beg);
            continue;
        }
        sum += std::stoi(line);

        it = repeatedSums.find(sum);
        if (it != repeatedSums.end())
        {
            return sum;
        }
        else
        {
            if (repeatedSums.size() == repeatedSums.max_size())
            {
                std::cout << "Set has reached maximum size capacity." << std::endl; 
                return 0;
            }
            repeatedSums.insert(sum);
        }
    }   

    for (std::set<int,std::less<int>>::iterator itr = repeatedSums.begin(); itr != repeatedSums.end(); ++itr) 
    { 
        std::cout << '\t' << *itr; 
    } 

    std::cout << "No repeated sums." << std::endl;
    return 0;
}

void printAnswer(int answer)
{
    std::cout << "Sum = " << answer << std::endl;
}


int main(int argc, char const *argv[])
{
    std::string filename = "inputs/Day01/sellersgrant.txt";
    std::ifstream inputFile;
    inputFile.open(filename);
    if (inputFile.is_open())
    {
        printAnswer(problemOne(&inputFile));

        inputFile.clear();
        inputFile.seekg(0,std::ios::beg);
        
        printAnswer(problemTwo(&inputFile));
    }
    else
    {
        std::cout << "Unable to open file: " << filename;
        return -1;
    }

    inputFile.close();
    return 0;
}

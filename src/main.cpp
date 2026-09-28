#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

std::string GetPharse()
{
    std::string pharse;
    std::cout << "Enter a pharse (Please do not enter a number) "<< std::endl;
    std::cout << "Enter the pharse : ";
    //Used to get whole pharse
    std::getline(std::cin,pharse);
    return pharse;
}

int main ()
{
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::string GuessPharse;
    std::vector<unsigned char>characters = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
        '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', 
        '.', '/', ':', ';', '<', '=', '>', '?', '@', '[', '\\', ']', '^', 
        '_', '`', '{', '|', '}', '~',' '
    };

    std::vector<float>ErrorLists;
    std::vector<float>WeightLists;
    std::vector<float>BiasLists;
    //to check if finished
    bool finished{};
    //the learning rate
    float LearningRate       = 0.001f;
    //Min Index
    int minindex             = 0;
    //max index
    int maxindex             = characters.size() - 1;
    std::string TargetPharse = GetPharse();
    //Random Index Generator
    std::uniform_int_distribution Index{minindex,maxindex};
    std::cout << maxindex << std::endl;
    //The first guess
    //it doesnt know anything expect the length of the pharse
    //so we just make it get a gibberish thing
    for (int pharsemaker = 0;pharsemaker < TargetPharse.length() ;pharsemaker ++)
        {
            //Defaluting to zero for now
            //errors,weight,bias for each neuron
            float weight{};
            float bias{};
            float error{};
            //Getting the first gibberish code to start from !
            GuessPharse += characters[Index(gen)];
            //Storing in vector to use them later to adjust the guess
            ErrorLists.push_back(error);
            BiasLists.push_back(bias);
            WeightLists.push_back(weight);
        }

    for(int trainingreps = 1;GuessPharse != TargetPharse ;trainingreps ++)
    {
        std::cout << "Training : " << trainingreps << std::endl;
        std::cout << "" << std::endl;
        //Current GuessPharse
        std::cout << "GuessPharse : " << GuessPharse << std::endl;
        std::cout << "" << std::endl;

        for (int letterindex = 0;letterindex < TargetPharse.length();letterindex ++)
        {
            //printing every index of GuessPharse,TargetPharse and their int value
            std::cout << "GuessPharse["                  << static_cast<int>(letterindex) << "] : "      << GuessPharse[letterindex] << std::endl; 
            std::cout << "TargetPharse["                 << static_cast<int>(letterindex) << "] : "      << TargetPharse[letterindex] << std::endl; 
            std::cout << "GuessPharse Integer Value : "  << static_cast<int>(GuessPharse[letterindex])   << std::endl; 
            std::cout << "TargetPharse Integer Value : " << static_cast<int>(TargetPharse[letterindex])  << std::endl; 
            //using the formulas to change weight and bias
            //Asjusting the weight and bias using error
            ErrorLists[letterindex]   = TargetPharse[letterindex] - GuessPharse[letterindex];
            WeightLists[letterindex] += ErrorLists[letterindex] * LearningRate * GuessPharse[letterindex];
            BiasLists[letterindex]   += ErrorLists[letterindex] * LearningRate;
            std::cout << "" << std::endl;
            //printing the information
            std::cout << "Error : "                   << ErrorLists[letterindex] << std::endl;
            std::cout << "The new adjusted weight : " << WeightLists[letterindex] << std::endl;
            std::cout << "The new adjusted bias : "   << BiasLists[letterindex]   << std::endl;
            std::cout << "Adjusted GuessPharse["                 << static_cast<int>(letterindex) << "] : "      << GuessPharse[letterindex] << std::endl; 
            std::cout << "" << std::endl;
        }
        GuessPharse = "";
        for (int iteratorvalue = 0; iteratorvalue < TargetPharse.length(); iteratorvalue ++)
        {
            //The new adjusted char
            char PredictionChar         = WeightLists[iteratorvalue] * BiasLists[iteratorvalue] + BiasLists[iteratorvalue];
            //Adding to guess pharse
            GuessPharse                 += PredictionChar;
        }
        std::cout << "" << std::endl;
        std::cout << "New GuessPharse : "  << GuessPharse  << std::endl;

        if(GuessPharse == TargetPharse)
        {
            //If we get the correct pharse
            std::cout << "The Network has guessed the pharse !!" << std::endl;
            std::cout << "" << std::endl;
            std::cout << "It took " << trainingreps << " attempts to guess the pharse!!" << std::endl; 
            std::cout << "GuessPharse : "  << GuessPharse  << std::endl;
            std::cout << "TargetPharse : " << TargetPharse << std::endl;
            //activing finished so it can break the loop
            finished = true;
            break;
        }
        if(finished)
        {
            //breaking the loop
            break;
        }
    }
    return 0;
}
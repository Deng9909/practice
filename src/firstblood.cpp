#include <iostream>
#include <vector>
#include <stdlib.h>
#include <chrono>

using namespace std;

int numberOfExercise;
bool degreeOfDifficulty;
const bool hard = true;
const bool easy = false;
vector<int> userAnswer;
vector<int> trueAnswer;
vector<double> timeConsume;
vector<int> intValueFirst;
vector<int> intvalueSecond;
vector<int> factor;
vector<unsigned int> mathType;
const unsigned int add = 0;
const unsigned int sub = 1;
const unsigned int multi = 2;
const unsigned int divi = 3;


void startUI()
{
    //输入用户的题目数量并进行非法输入处理
    cout << "please enter the number of exercises" << endl;
    cin >> numberOfExercise;
    while(cin.fail() || numberOfExercise <= 0)
    {
        cin.clear();
        cout << "please enter the numer of exerices correctly" << endl;
    }
    cout << numberOfExercise << " exercises will be provided " << endl;

    cout << "please determine the difficulty: enter 0 means easy and 1 means hard" << endl;
    cin >> degreeOfDifficulty;
    if(degreeOfDifficulty)
        cout << "-->difficult model!" << endl;
    else
        cout << "-->easy model!" << endl;
}

void startPractice()
{
    userAnswer.resize(numberOfExercise);
    intValueFirst.resize(numberOfExercise);
    intvalueSecond.resize(numberOfExercise);
    trueAnswer.resize(numberOfExercise);
    mathType.resize(numberOfExercise);
    timeConsume.resize(numberOfExercise);
    srand((int)time(NULL));
    for (size_t i = 0; i < numberOfExercise;i++){
        // cout << rand() << endl;
        trueAnswer[i] = rand() % 100;
    }
    
    if (degreeOfDifficulty==hard){
        for (size_t i = 0; i < numberOfExercise;i++){
            mathType[i] = rand() % 4;
        }
    }
    else if(degreeOfDifficulty==easy){
        for (size_t i = 0; i < numberOfExercise;i++){
            mathType[i] = rand() % 2;
        }
    }
    for (size_t i = 0; i < numberOfExercise;i++){
        if(mathType[i]==add||mathType[i]==sub){
            intValueFirst[i] = rand() % trueAnswer[i];
            
            if(mathType[i]==add){
                intvalueSecond[i] = trueAnswer[i] - intValueFirst[i];
            }
            else if(mathType[i]==sub)
            {
                intvalueSecond[i] = intValueFirst[i] + trueAnswer[i];
            }
        }
        else if(mathType[i]==multi||mathType[i]==divi){
            for (int j = 1; j <= trueAnswer[i];j++){
                if(trueAnswer[i]%j==0){
                    
                    factor.push_back(j);
                    std::cout << factor.size() << std::endl;
                }
            }
            int factorChooseOrder = rand() % factor.size();
            intValueFirst[i] = factor[factorChooseOrder-1];
            factor.clear();
            if(mathType[i]==multi){
               intvalueSecond[i] = trueAnswer[i] / intValueFirst[i];
            }
            else if(mathType[i]==divi){
                intvalueSecond[i] = intValueFirst[i] * trueAnswer[i];
                }    
        }
        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
        switch(mathType[i])
        {
        case 0://add
            cout << intValueFirst[i] << "+" << intvalueSecond[i] << "=";
            break;
        case 1://sub
            cout << intvalueSecond[i] << "-" << intValueFirst[i] << "=";
            break;
        case 2: // multi
            cout << intvalueSecond[i] << "*" << intValueFirst[i] << "=";
            break;
        case 3://divi
            cout << intvalueSecond[i] << "/" << intValueFirst[i] << "=";
            break;
        default:break;
        }
        cin >> userAnswer[i];
}

    


int main(int argc,char* argv[])
{
    startUI();
    startPractice();
    cout << "练习已结束，等待答案" << endl;
}









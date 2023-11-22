#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void main1(){
    string keresendoszo = "berry";
    vector<string> fruits {"melon", "strawberry", "raspberry","apple", "banana", "walnut", "lemon"};
    auto berry = std::find_if(fruits.begin(), fruits.end(), [keresendoszo](const string &i)
    {return i.find(keresendoszo) != string::npos;});
    cout << (berry - fruits.begin());
}

void main2(){
    vector<int>numbers {2, 4, 6, 8, 10};
    cout << std::all_of(numbers.begin(), numbers.end(), [](int i){
        return (i & 1) == 0;
    });
}

void main3(){
    vector<int>numbers {2, 4 , 6, 8, 10};
    for_each(numbers.begin(), numbers.end(), [](int &i){
        i = i + 2;
    });
    for_each(numbers.begin(), numbers.end(), [](int &i){
        cout << i << ' ';
    });
}

void main4(){
    vector<string> months {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    cout << count_if(months.begin(), months.end(), [](const string &month){
        return month.length() == 5;
    });
}

void main5(){
    vector<float> numbers{3, 3.5, 7, 1.2, 78, 4.5};
    std::sort(numbers.begin(), numbers.end(), [](float a, float b){
        return a > b;
    });
    for (float i : numbers) {
        cout << i << ' ';
    }
}

void main6(){
    vector<float> numbers{3, 3.5, 7, 1.2, 78, 4.5};
    //greater<float> g;
    std::sort(numbers.begin(), numbers.end(), greater());
    for (float i : numbers) {
        cout << i << ' ';
    }
}

void main7(){
    vector<pair<string, float>> months{
            {"Januar", 8},
            {"Februar", 5},
            {"Marcius", 12.4}};
    std::sort(months.begin(), months.end(), [](const pair<string, float> &a, const pair<string, float> &b){
        return  a.second < b.second;
    });
}

void main8(){
    vector <float> numbers{2, -4, -5.6, 5, 6, -8.6};
    sort(numbers.begin(), numbers.end(), [](float a, float b) {
        return abs(a) < abs(b);
    });
    for(float p : numbers){
        cout << p << ' ';
    }
}

void main9(){
    vector<string> months {"January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"};
    for_each(months.begin(), months.end(),[](string &i){
        i[0] = ::tolower(i[0]);
    });
    for (const string& p : months) {
        cout << p << ' ';
    }
}

int main() {
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    shuffle(abc.begin(), abc.end(), random_device());
    char inv[256] = {0};
    std::for_each(abc.begin(), abc.end(),[&inv, &abc](char i){
        inv[i] = abc.find(i);
        inv[::tolower(i)] = abc.find(i);
    });
    cout << abc;
    return 0;
}
#include <iostream>
using namespace std;
int main() {
    double weightLbs, heightIn, weightKg, heightM;
    string weightStatus;

    cout<<"Please enter weight (in pounds): ";
    cin>>weightLbs;

    cout<<"Please enter height (in inches): ";
    cin>>heightIn;

    weightKg = weightLbs*0.453592;
    heightM = heightIn*0.0254;
    double bmi = weightKg/(heightM*heightM);

    if(bmi < 18.5){
        weightStatus = "Underweight";
    } else if(bmi >= 18.5 && bmi < 25){
        weightStatus = "Normal";
    } else if(bmi >= 25 && bmi < 30){
        weightStatus = "Overweight";
    } else if(bmi >= 30){
        weightStatus = "Obese";
    }

    cout<<"The weight status is: "<<weightStatus;

    return 0;
}




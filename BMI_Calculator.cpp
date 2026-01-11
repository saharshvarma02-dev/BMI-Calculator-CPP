#include <iostream>
using namespace std;

double bmi, weight, height;
class Weight{
    public:
        void displayWeight(){
            cout << "Enter weight in kilograms: ";
            cin >> weight;
        }
        double getWeight() const {
            return weight;
        }
};

class Height{
    public:
        void displayHeight(){
            cout << "Enter height in meters: ";
            cin >> height;
        }
        double getHeight() const {
            return height;
        }
};

class BMI_category{
    public:
        void displayBMICategory(){
            double bmiValue = bmi;
            if(bmiValue < 18.5){
                cout << "You're in the Underweight category" << endl;
            } else if(bmiValue >= 18.5 && bmiValue < 24.9){
                cout << "You're in the Normal weight category" << endl;
            } else if(bmiValue >= 25 && bmiValue < 29.9){
                cout << "You're in the Overweight category" << endl;
            } else if (bmiValue >= 30){
                cout << "You're in the Obesity category" << endl;
            }
        }
};

class NormalBMi {
    public:
        void displayNormalBMIRange(){
            if (bmi >= 18.5 && bmi <= 24.9){
                return;
            }
            else if (bmi < 18.5){
                double weightToGain = (18.5 - bmi) * (height * height);
                cout << "You need to gain at least " << weightToGain << " kg to reach the normal BMI range." << endl;
            } else if (bmi > 24.9){
                double weightToLose1 = (bmi - 24.9) * (height * height);
                cout << "You need to lose at least " << weightToLose1 << " kg to reach the normal BMI range." << endl;
            } else {
                double weightToLose2 = (bmi - 24.9) * (height * height);
                cout << "You need to lose at least " << weightToLose2 << " kg to reach the normal BMI range." << endl;  
            }
        }
};

class BMI_Calculator : public Weight, public Height, public BMI_category, public NormalBMi {
    public:
        void calculateBMI(){
            displayWeight();
            displayHeight();
            bmi = getWeight() / (getHeight() * getHeight());
            cout << "Your BMI is: " << bmi << endl;
            displayBMICategory();
            displayNormalBMIRange();
        }
};

int main(){
    BMI_Calculator bmiCalc;
    bmiCalc.calculateBMI();
    return 0;
}
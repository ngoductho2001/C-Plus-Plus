#include<stdio.h>
#include<stdint.h>
#include<math.h>

class Fraction{
    private:
        int tuSo;
        int mauSo;
    public:
        Fraction(int tuSo = 1, int mauSo = 1);
        int get_tuSo();
        int get_mauSo();
};

class Calculation{
    private:
        Fraction Number1;
        Fraction Number2;
        Fraction Number3;
        typedef enum{
            hai_so_hang,
            ba_so_hang
        }so_hang;
        so_hang sh;
    public:
        Calculation(Fraction Number1, Fraction Number2);
        Calculation(Fraction Number1, Fraction Number2, Fraction Number3);
        void Summation();
        void Subtraction();
        void Multiplication();
        void Division();
};

Fraction::Fraction(int tuSo, int mauSo){
    Fraction::tuSo = tuSo;
    Fraction::mauSo = mauSo;
}

int Fraction::get_tuSo(){
    return Fraction::tuSo;
}

int Fraction::get_mauSo(){
    return Fraction::mauSo;
}

Calculation::Calculation(Fraction Number1, Fraction Number2){
    Calculation::Number1 = Number1;
    Calculation::Number2 = Number2;
    Calculation::sh = hai_so_hang;
}

Calculation::Calculation(Fraction Number1, Fraction Number2, Fraction Number3){
    Calculation::Number1 = Number1;
    Calculation::Number2 = Number2;
    Calculation::Number3 = Number3;
    Calculation::sh = ba_so_hang;
}

void Calculation::Summation() {
    if(Calculation::sh == hai_so_hang){
        int tuSo1 = Calculation::Number1.get_tuSo();
        int mauSo1 = Calculation::Number1.get_mauSo();
        int tuSo2 = Calculation::Number2.get_tuSo();
        int mauSo2 = Calculation::Number2.get_mauSo();
        int chungMauSo = mauSo1 * mauSo2;
        int tongTuSo = tuSo1 * mauSo2 + tuSo2 * mauSo1;
        printf("Result of Summation is: %d/%d\n", tongTuSo, chungMauSo);
    } else     
    if(Calculation::sh == ba_so_hang){
        int tuSo1 = Calculation::Number1.get_tuSo();
        int mauSo1 = Calculation::Number1.get_mauSo();
        int tuSo2 = Calculation::Number2.get_tuSo();
        int mauSo2 = Calculation::Number2.get_mauSo();
        int tuSo3 = Calculation::Number3.get_tuSo();
        int mauSo3 = Calculation::Number3.get_mauSo();
        int chungMauSo = mauSo1 * mauSo2 * mauSo3;
        int tongTuSo = tuSo1 * mauSo2 * mauSo3 + tuSo2 * mauSo1 * mauSo3 + tuSo3 * mauSo1 * mauSo2;
        printf("Result is Summation: %d/%d\n", tongTuSo, chungMauSo);
    }

}

void Calculation::Subtraction(){
    int tuSo1 = Calculation::Number1.get_tuSo();
    int mauSo1 = Calculation::Number1.get_mauSo();
    int tuSo2 = Calculation::Number2.get_tuSo();
    int mauSo2 = Calculation::Number2.get_mauSo();
    int chungMauSo = mauSo1 * mauSo2;
    int tongTuSo = tuSo1 * mauSo2 - tuSo2 * mauSo1;
    printf("Result is Subtraction: %d/%d\n", tongTuSo, chungMauSo);
}

void Calculation::Multiplication(){
    int tuSo1 = Calculation::Number1.get_tuSo();
    int mauSo1 = Calculation::Number1.get_mauSo();
    int tuSo2 = Calculation::Number2.get_tuSo();
    int mauSo2 = Calculation::Number2.get_mauSo();
    printf("Result is Multiplication: %d/%d\n", tuSo1 * tuSo2, mauSo1 * mauSo2);  
}

void Calculation::Division(){
    int tuSo1 = Calculation::Number1.get_tuSo();
    int mauSo1 = Calculation::Number1.get_mauSo();
    int tuSo2 = Calculation::Number2.get_tuSo();
    int mauSo2 = Calculation::Number2.get_mauSo();
    printf("Result is Division: %d/%d\n", tuSo1 * mauSo2, mauSo1 * tuSo2);
}


int main(){
    int tuSo1, mauSo1, tuSo2, mauSo2, tuSo3, mauSo3;
    printf("phep tinh 2 so hang:");
    scanf("%d %d %d %d", &tuSo1, &mauSo1, &tuSo2, &mauSo2);
    Fraction Number1(tuSo1, mauSo1);
    Fraction Number2(tuSo2, mauSo2);
    Calculation test1(Number1, Number2);
    test1.Summation();
    test1.Multiplication();
    printf("phep tinh 3 so hang:");
    scanf("%d %d %d %d %d %d", &tuSo1, &mauSo1, &tuSo2, &mauSo2, &tuSo3, &mauSo3);
    Fraction Number3(tuSo3, mauSo3);
    Calculation test2(Number1, Number2, Number3);
    test2.Summation();
    
}

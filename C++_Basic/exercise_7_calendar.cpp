#include<stdio.h>
#include<stdint.h>

using namespace std;

class Calendar{
    private:
        int8_t date;
        int8_t month;
        int16_t year;
    public:
        Calendar();
        void setCalendar();
        void checkHoliday();
        void caclulateAge();
};

Calendar::Calendar(){
    this -> date = 0;
    this -> month = 0;
    this -> year = 0;
}

void Calendar::setCalendar(){
    printf("Enter the current date:");
    scanf("%d", &(this -> date));
    printf("Enter the current month:");
    scanf("%d", &(this -> month));
    printf("Enter the current year:");
    scanf("%d", &(this -> year));

}

void Calendar::caclulateAge(){
    int16_t year;
    printf("Enter your year of birth:");
    scanf("%d", &year);
    printf("Your age: %d", (this -> year - year));
}

void Calendar::checkHoliday(){
    int date, month;
    printf("Enter the date you want to check: ");
    scanf("%d", &date);
    printf("Enter the month you want to check: ");
    scanf("%d", &month);
    if(date == 1 && month == 1){
        printf("Holiday TET\n");
    }else if(date == 30 && month == 4){
        printf("Holiday Southern Liberation\n");
    }else if(date == 1 && month == 5){
        printf("Holiday International labor\n");
    }else if(date == 2 && month == 9){
        printf("Holiday National\n");
    }else {
        printf("Normal Day\n");
    }
}

int main(){
    Calendar calendar;
    // calendar.setCalender();
    // calendar.caclulateAge();
    calendar.checkHoliday();
}



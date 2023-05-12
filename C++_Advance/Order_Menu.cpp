#include<stdio.h>
#include<stdint.h>
#include<vector>
#include<string>

using namespace std;

class Dish{
    private:
        int id;
        string name;
        int price;
    public:
        Dish();
        void setDish();
        void setID();
        void setID(int id);
        void setName();
        void setName(string name);
        void setPrice();
        void setPrice(int price);
        int getID();
        string getName();
        int getPrice();

};

Dish::Dish(){
    this -> id = 0;
    this -> name = " ";
    this -> price = 0;
}

void Dish::setDish(){
    static int countID = 0;
    this -> id = countID;
    countID++;
    printf("Enter name dish:\n");
    scanf("%s",&(this -> name));
    printf("Enter price dish:\n");
    scanf("%d",&(this -> price));
}

void Dish::setID(int id){
    this -> id = id;
}

void Dish::setName(string name){
    this -> name = name;
}

void Dish::setPrice(int price){
    this -> price = price;
}

int Dish::getID(){
    return this -> id;
}

string Dish::getName(){
    return this -> name;
}

int Dish::getPrice(){
    return this -> price;
}

void Dish::setID(){
    int id;
    this -> id = id;
    scanf("%d",&(this -> id));
}

void Dish::setName(){
    printf("Enter name dish:\n");
    scanf("%s",&(this -> name));
}

void Dish::setPrice(){
    printf("Enter price dish:\n");
    scanf("%d",&(this -> price));
}



class Management{
    private:
        vector<Dish> databaseDish;
        int totalTable;
    public:
        void setTables();
        void addDish();
        void updateDish();
        void deleteDish();
        void showDishs();
};

void Management::addDish(){
    Dish dish;
    dish.setDish();
    this -> databaseDish.push_back(dish);
}

void Management::updateDish(){
    int temporaryID,choice;
    printf("Enter ID of dish you want to update:\n");
    scanf("%d",&temporaryID);
    printf("What do you want to change:\n 1.Name\t2.Price\n");
    scanf("%d",&choice);
    for(int i =0; i < databaseDish.size(); i++){
        if(databaseDish[i].getID() == temporaryID){
            if(choice == 1){
                databaseDish[i].setName();
            } else if(choice == 2){
                databaseDish[i].setPrice();
            }
        }
    }
}

void Management::deleteDish(){
    int temporaryID;
    printf("Enter ID of Dish you want to delete:\n");
    scanf("%d",&temporaryID);
    for(int i = 0; i < databaseDish.size(); i++){
        if(databaseDish[i].getID() == temporaryID){
            databaseDish.erase(databaseDish.begin()+ i);
        }
    }
}

void Management::showDishs(){
    printf("-----This is dish of restaurant------\nID\t STT\t Dish\t Price\n");
    for(int i = 0; i < databaseDish.size(); i++){
        printf("STT:%d\t ID:%d\t Dish:%s\t Price:%d\n",i+1,databaseDish[i].getID(), databaseDish[i].getName().c_str(), databaseDish[i].getPrice());
    }
}

void Management::setTables(){
    printf("Enter number of table:\n");
    scanf("%d", &this ->totalTable);
}


class Staff{

};

class Restaurant{
    public:
        Management management;
        Staff staff;
        Restaurant();
};

Restaurant::Restaurant(){
    int loop1 = 1;
    do
    {
        printf("Choice:\n 1.Management\t 2.Staff\t 3.Exit\n");
        int choice = 0;
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            printf("==============\n1.AddDish\n2.UpdateDish\n3.DeleteDish\n4.ShowDishs\n5.Exit\n");
            int choice_1 = 0;
            scanf("%d",&choice_1);
            switch
            (choice_1)
            {
            case 1:
                {
                    int loopAddDish = 1;
                    do
                    {
                        this -> management.addDish();
                        printf("1.Continue addDish\n2.Exit\n");
                        int temporaryChoice = 0;
                        scanf("%d",&temporaryChoice);
                        if(temporaryChoice == 2){
                            loopAddDish = 0;
                        }   
                    } while (loopAddDish);    
                    break;
                }
            case 2:
                this -> management.updateDish();
                break;
            case 3:
                this -> management.deleteDish();
                break;
            case 4:
                this -> management.showDishs();
                break;
            case 5:
                break;
            default:
                break;
            }
        }

        case 2:
        {

        }
        
        case 3:
            loop1 = 0;
        default:
            break;
        }
    } while (loop1);    
}

int main(int argc, char const *argv[])
{
    Restaurant restaurant;
    return 0;
}


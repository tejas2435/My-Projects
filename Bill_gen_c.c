#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100


struct MenuItem {
    char name[50];
    int price;
};

int Starter(struct MenuItem items[], int maxItems);
int Soup(struct MenuItem items[], int maxItems, int startersCount);
int Sabji(struct MenuItem items[], int maxItems, int startersCount, int soupsCount);
int Roti(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount);
int Rice(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount);
int Dal(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount);
int Papad(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount , int dalCount);
int Beverages(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount,int dalCount,int papadCount);
int Dessert(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount,  int dalCount,int papadCount, int beveragesCount);


int main() {
    struct MenuItem items[MAX_ITEMS];
    int totalItemCount = 0;

    // Call option1 for starters
    int startersCount =Starter(items, MAX_ITEMS);
    totalItemCount += startersCount;

    // Call option2 for soups
    int soupsCount = Soup(items, MAX_ITEMS, startersCount);
    totalItemCount += soupsCount;
    
     // Call option3 for additional food items (Sabjis)
    int sabjiCount = Sabji(items, MAX_ITEMS, startersCount, soupsCount);
    totalItemCount += sabjiCount;
    
      // Call option4 for Rotis
    int rotiCount = Roti(items, MAX_ITEMS, startersCount, soupsCount, sabjiCount);
    totalItemCount += rotiCount;
    
    // Call option5 for Rice
    int riceCount = Rice(items, MAX_ITEMS, startersCount, soupsCount, sabjiCount, rotiCount);
    totalItemCount += riceCount;
    // Call option6 for Dal
    int dalCount = Dal(items, MAX_ITEMS, startersCount, soupsCount, sabjiCount, rotiCount, riceCount);
    totalItemCount += dalCount;
    // Call option7 for Papad
    int papadCount = Papad(items, MAX_ITEMS, startersCount, soupsCount, sabjiCount, rotiCount, riceCount , dalCount);
    totalItemCount += papadCount;
     // Call option8 for Beverages
    int beveragesCount = Beverages(items, MAX_ITEMS, startersCount, soupsCount, sabjiCount, rotiCount, riceCount,dalCount, papadCount);
    totalItemCount += beveragesCount;
     // Call option9 for Desserts
    int dessertsCount = Dessert(items, MAX_ITEMS, startersCount, soupsCount, sabjiCount, rotiCount, riceCount,dalCount, papadCount,  beveragesCount);
    totalItemCount += dessertsCount;

       
    // Display all ordered items
    printf("\n\t\tYou ordered:\n ------------------------------------------- \n");
    float total = 0.0;
 
    // Display starters
    printf("\n\n Starters :\n");
    for(int i = 0; i < startersCount; i++){
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }
        
      // Display soups
    printf("\n\n Soups :\n");
    for(int i = startersCount; i < startersCount + soupsCount; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }
      // (Sabjis)
    printf("\n\n Sabjis:\n");
    for (int i = startersCount + soupsCount; i < startersCount + soupsCount + sabjiCount; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }
      // Display Rotis
    printf("\n\n Rotis :\n");
    for (int i = startersCount + soupsCount + sabjiCount; i < startersCount + soupsCount + sabjiCount + rotiCount; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }
      // Display Rice
    printf("\n\n Rice :\n");
    for (int i = startersCount + soupsCount + sabjiCount  + rotiCount ; i < startersCount + soupsCount + sabjiCount + rotiCount + riceCount ; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }
     // Display Dal
    printf("\n\n Dal :\n");
    for (int i = startersCount + soupsCount + sabjiCount + rotiCount + riceCount; i < startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }
    // Display Papad
    printf("\n\n Papad :\n");
    for (int i = startersCount + soupsCount + sabjiCount + rotiCount + riceCount+dalCount; i < startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount+papadCount; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
         total += items[i].price;
    }
     // Display Beverages
    printf("\n\n Beverages :\n");
    for (int i = startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount + papadCount; i < startersCount + soupsCount + sabjiCount + rotiCount + riceCount + papadCount +dalCount+ beveragesCount; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }
     // Display Desserts
    printf("\n\n Desserts :\n");
    for (int i = startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount+ papadCount + beveragesCount; i < startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount + papadCount + beveragesCount + dessertsCount; i++) {
        printf("%s \t- \t%drs\n", items[i].name, items[i].price);
        total += items[i].price;
    }

    printf("\n\n\t\tFinal Bill\n ------------------------------------------- \n  Sub Total\t:\t%.1frs\n", total);
    // printf("\tGst \t: \t18%\n");
    printf("\tGst \t: \t18%%\n");
    total += 18 * total / 100;
    printf("Total Amount \t:\t%.1frs \n(Inc. Taxes)", total);

    return 0;
}

int Starter(struct MenuItem items[], int maxItems) {
    struct MenuItem item;
    int s, quantity;
    int itemCount = 0;

    printf("\n\n Starters :\n");
    printf("1. Hara Bhara Kabab - 120rs\n");
    printf("2. Chilli Paneer - 200rs\n");
    printf("3. Dry Manchurian - 80rs\n");
    printf("4. Garlic Bread - 150rs\n");

    printf("\n\nEnter the number of starters you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order for Starter %d: ", i + 1);
        scanf("%d", &s);

        switch (s) {
            case 1:
                strcpy(item.name, "Hara Bhara Kabab");
                item.price = 120;
                break;
            case 2:
                strcpy(item.name, "Chilli Paneer");
                item.price = 200;
                break;
            case 3:
                strcpy(item.name, "Dry Manchurian");
                item.price = 80;
                break;
            case 4:
                strcpy(item.name, "Garlic Bread");
                item.price = 150;
                break;
            default:
                strcpy(item.name, "Invalid choice");
                item.price = 0;
                break;
        }

        if (s >= 1 && s <= 4) {
            // Only add valid choices to the array
            if (itemCount < maxItems) {
                items[itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}

int Soup(struct MenuItem items[], int maxItems, int startersCount) {
    struct MenuItem item;
    int s, quantity;
    int itemCount = 0;

    printf("\n\n Soups :\n");
    printf("1. Tomato Soup - 100rs\n");
    printf("2. Hot and Sour Soup - 150rs\n");
    printf("3. Manchow Soup - 120rs\n");

    printf("\n\nEnter the number of soups you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order for Soup %d: ", i + 1);
        scanf("%d", &s);

        switch (s) {
            case 1:
                strcpy(item.name, "Tomato Soup");
                item.price = 100;
                break;
            case 2:
                strcpy(item.name, "Hot and Sour Soup");
                item.price = 150;
                break;
            case 3:
                strcpy(item.name, "Manchow Soup");
                item.price = 120;
                break;
            default:
                strcpy(item.name, "Invalid choice");
                item.price = 0;
                break;
        }

        if (s >= 1 && s <= 3) {
            // Only add valid choices to the array
            if (startersCount + itemCount < maxItems) {
                items[startersCount + itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}

int Sabji(struct MenuItem items[], int maxItems, int startersCount, int soupsCount) {
    struct MenuItem item;
    int s, quantity;
    int itemCount = 0;

    printf("\n\n Sabjis:\n");
    printf("1. Veg Mix - 180rs\n");
    printf("2. Paneer Tikka Masala - 200rs\n");
    printf("3. Paneer Hydrabadi - 230rs\n");
    printf("4. Paneer Kofta - 300rs\n");

    printf("\n\nEnter the number of Sabjis you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order for Sabji %d: ", i + 1);
        scanf("%d", &s);

        switch (s) {
            case 1:
                strcpy(item.name, "Veg Mix");
                item.price = 180;
                break;
            case 2:
                strcpy(item.name, "Paneer Tikka Masala");
                item.price = 200;
                break;
            case 3:
                strcpy(item.name, "Paneer Hydrabadi");
                item.price = 230;
                break;
            case 4:
                strcpy(item.name, "Paneer Kofta");
                item.price = 300;
                break;
            default:
                printf("Invalid choice in Additional Food Items (Sabjis)\n");
                strcpy(item.name, "Invalid choice");
                item.price = 0;
        }

        if (s >= 1 && s <= 4) {
            // Only add valid choices to the array
            if (startersCount + soupsCount + itemCount < maxItems) {
                items[startersCount + soupsCount + itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}


int Roti(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount) {
    struct MenuItem item;
    int r, quantity;
    int itemCount = 0;

    printf("\n\n Rotis :\n");
    printf("1. Plain Chapati - 20rs\n");
    printf("2. Tandori Roti - 30rs\n");
    printf("3. Naan - 60rs\n");
    printf("4. Paratha - 80rs\n");

    printf("\n\nEnter the number of Rotis you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order number for Roti %d: ", i + 1);
        scanf("%d", &r);

        switch (r) {
            case 1:
                strcpy(item.name, "Plain Chapati");
                item.price = 20;
                break;
            case 2:
                strcpy(item.name, "Tandori Roti");
                item.price = 30;
                break;
            case 3:
                strcpy(item.name, "Naan");
                item.price = 60;
                break;
            case 4:
                strcpy(item.name, "Paratha");
                item.price = 80;
                break;
            default:
                printf("Invalid choice in Rotis\n");
                strcpy(item.name, "Invalid choice");
                item.price = 0;
        }

        if (r >= 1 && r <= 4) {
            // Only add valid choices to the array
            if (startersCount + soupsCount + sabjiCount + itemCount < maxItems) {
                items[startersCount + soupsCount + sabjiCount + itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}
int Rice(struct MenuItem items[], int maxItems,int startersCount, int soupsCount, int sabjiCount,int rotiCount) {
    struct MenuItem item;
    int R, quantity;
    int itemCount = 0;

    printf("\n\n Rice:\n");
    printf("1. Plain Rice - 120rs\n");
    printf("2. Jeera Rice - 150rs\n");
    printf("3. Pullao - 180rs\n");
    printf("4. Biryani - 200rs\n");

    printf("\n\nEnter the number of Rice you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order number for Rice %d: ", i + 1);
        scanf("%d", &R);

        switch (R) {
            case 1:
                strcpy(item.name, "Plain Rice");
                item.price = 120;
                break;
            case 2:
                strcpy(item.name, "Jeera Rice");
                item.price = 150;
                break;
            case 3:
                strcpy(item.name, "Pullao");
                item.price = 180;
                break;
            case 4:
                strcpy(item.name, "Biryani");
                item.price = 200;
                break;
            default:
                printf("Invalid choice in Rice\n");
                strcpy(item.name, "Invalid choice");
                item.price = 0;
        }

        if (R >= 1 && R <= 4) {
            // Only add valid choices to the array
            if (startersCount + soupsCount + sabjiCount  + rotiCount + itemCount < maxItems) {
                items[startersCount + soupsCount + sabjiCount  + rotiCount + itemCount ] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
} 

int Dal(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount) {
    int D, quantity;
    int itemCount = 0;

    printf("\n\n Dal :\n");
    printf("1. Dal Fry - 130rs\n");
    printf("2. Dal Tadka - 150rs\n");
    printf("3. Indian Curry - 180rs\n");
    printf("4. Dal Makhani - 140rs\n");
    printf("\n\nEnter the number of Dal  you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order for Dall %d: ", i + 1);
        scanf("%d", &D);

        struct MenuItem item;  // Declare the struct inside the loop
        switch (D) {
            case 1:
                strcpy(item.name, "Dal Fry");
                item.price = 130;
                break;
            case 2:
                strcpy(item.name, "Dal Tadka");
                item.price = 150;
                break;
            case 3:
                strcpy(item.name, "Indian Curry");
                item.price = 180;
                break;
            case 4:
                strcpy(item.name, "Dal Makhani");
                item.price = 140;
                break;
            default:
                printf("Invalid choice in Dall\n");
                strcpy(item.name, "Invalid choice");
                item.price = 0;
        }

        if (D >= 1 && D <= 4) {
            // Only add valid choices to the array
            if (startersCount + soupsCount + sabjiCount + rotiCount + riceCount + itemCount < maxItems) {
                items[startersCount + soupsCount + sabjiCount + rotiCount + riceCount + itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}
int Papad(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount , int dalCount) {
    int P, quantity;
    int itemCount = 0;

    printf("\n\n Papad :\n");
    printf("1. Plain Papad - 20rs\n");
    printf("2. Rosted papad - 30rs\n");
    printf("3. Masala papad - 40rs\n");

    printf("\n\nEnter the number of Papads you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order for Papad %d: ", i + 1);
        scanf("%d", &P);

        struct MenuItem item;  // Declare the struct inside the loop
        switch (P) {
            case 1:
                strcpy(item.name, "Plain Papad");
                item.price = 20;
                break;
            case 2:
                strcpy(item.name, "Rosted papad");
                item.price = 30;
                break;
            case 3:
                strcpy(item.name, "Masala papad");
                item.price = 40;
                break;
            default:
                printf("Invalid choice in Papad\n");
                strcpy(item.name, "Invalid choice");
                item.price = 0;
        }

        if (P >= 1 && P <= 3) {
            // Only add valid choices to the array
            if (startersCount + soupsCount + sabjiCount + rotiCount + riceCount +dalCount + itemCount < maxItems) {
                items[startersCount + soupsCount + sabjiCount + rotiCount + riceCount +  dalCount+itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}
int Beverages(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount,int dalCount,int papadCount) {
    int b, quantity;
    int itemCount = 0;

    printf("\n\n Beverages :\n");
    printf("1. Butter milk - 20rs\n");
    printf("2. Soda or Soft Drinks - 50rs\n");
    printf("3. Alcoholic Beverages - 3000rs\n");
    printf("4. Orange juices - 80rs\n");
    printf("\n\nEnter the number of Beverages you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order for Beverages %d: ", i + 1);
        scanf("%d", &b);

        struct MenuItem item;  // Declare the struct inside the loop
        switch (b) {
            case 1:
                strcpy(item.name, "Butter milk");
                item.price = 20;
                break;
            case 2:
                strcpy(item.name, "Soda or Soft Drinks");
                item.price = 50;
                break;
            case 3:
                strcpy(item.name, "Alcoholic Beverages");
                item.price = 3000;
                break;
            case 4:
                strcpy(item.name, "Orange juices");
                item.price = 80;
                break;
            default:
                printf("Invalid choice in Beverages\n");
                strcpy(item.name, "Invalid choice");
                item.price = 0;
        }

        if (b >= 1 && b <= 4) {
            // Only add valid choices to the array
            if (startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount+ papadCount + itemCount < maxItems) {
                items[startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount+ papadCount  + itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}
int Dessert(struct MenuItem items[], int maxItems, int startersCount, int soupsCount, int sabjiCount, int rotiCount, int riceCount,  int dalCount ,int papadCount, int beveragesCount) {
    int d, quantity;
    int itemCount = 0;

    printf("\n\n Desserts :\n");
    printf("1. Browny - 150rs\n");
    printf("2. Faluda - 150rs\n");
    printf("3. Rasmalai - 450rs\n");
    printf("4. Angur rabadi - 350rs\n");
    printf("\n\nEnter the number of Desserts you want to order: ");
    scanf("%d", &quantity);

    for (int i = 0; i < quantity; i++) {
        printf("\nEnter the order for Desserts %d: ", i + 1);
        scanf("%d", &d);

        struct MenuItem item;  // Declare the struct inside the loop
        switch (d) {
            case 1:
                strcpy(item.name, "Browny");
                item.price = 150;
                break;
            case 2:
                strcpy(item.name, "Faluda");
                item.price = 150;
                break;
            case 3:
                strcpy(item.name, "Rasmalai");
                item.price = 450;
                break;
            case 4:
                strcpy(item.name, "Angur rabadi");
                item.price = 350;
                break;
            default:
                printf("Invalid choice in Desserts\n");
                strcpy(item.name, "Invalid choice");
                item.price = 0;
        }

        if (d >= 1 && d <= 4) {
            // Only add valid choices to the array
            if (startersCount + soupsCount + sabjiCount + rotiCount + riceCount + dalCount + papadCount + beveragesCount + itemCount < maxItems) {
                items[startersCount + soupsCount + sabjiCount + rotiCount + riceCount +dalCount + papadCount   + beveragesCount + itemCount] = item;
                itemCount++;
            } else {
                printf("Maximum limit of items reached\n");
                break;
            }
        }
    }

    return itemCount;
}





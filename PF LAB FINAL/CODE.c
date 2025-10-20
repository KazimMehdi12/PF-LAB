#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>

float totalPrice = 0;

typedef struct login{
	char name[50];
	char password[50];
}login;

typedef struct datastoring{
	char name[50];
	char password[50];
	float total[5];
	int date[5][3];	
} data;

// ------------------->Discount<----------------------
int discountofbulk(int Price){
	if (Price >= 10000){
		printf("\n		congratulations, you got 10% discount... \n");
		return Price -(Price*0.10);
	}
	
	else if (Price > 1000){
		printf("\n		congratulations, you got rs 100 discount... \n");
		return Price - 100;
	}

	return Price;
	
}
// ------------------->Payment System<----------------------
int paymentsystem(){
	int choice;
printf("\n\n\n			   ----->PAYMENT SYSTEM<-----\n\n\n");
	while(1){
	printf("\n	   1. card payment\n");
	printf("\n	   2. pay in cash\n");
	printf("\n	   3. pay online\n");
	printf("\n	   4. exit\n");
	printf("\n	   enter a number to continue... ");
	scanf("%d", &choice);
	
	switch(choice){
		case 1:
			printf("\n	   transaction complete...\n");
			Sleep(1000);
printf("\n			   ----->THANK YOU<-----\n\n\n");

			Sleep(1000);
			return 0;
		case 2:
			printf("\n	   transaction complete...\n");
			Sleep(1000);
printf("\n			   ----->THANK YOU<-----\n\n\n");
			Sleep(1000);
			return 0;
		case 3:
			printf("\n	   transaction complete...\n");
			Sleep(1000);
printf("\n			   ----->THANK YOU<-----\n\n\n");
			Sleep(1000);
			return 0;
		case 4:
printf("\n			   ----->ORDER CANCELLED<-----\n\n\n");
			Sleep(10);
			return 1;
		default:
			printf("\n	   invalid choice...\n");
			break;
		}
	}
}

// ------------------->Admin Checking<----------------------
void adminchecking(){
		printf("	--------------->RECORD<----------------	\n\n");
	system("cls");
	data copy;
	FILE * ptr=fopen("FastFood.txt","a+");
	if(ptr == NULL){
printf("\n			   ----->no record found<-----\n\n\n");
	}
	while(fscanf(ptr,"%s %s  %f  %f  %f  %f  %f %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",copy.name,copy.password,&copy.total[0],&copy.total[1],&copy.total[2],
		&copy.total[3],&copy.total[4],&copy.date[0][0],&copy.date[0][1],&copy.date[0][2],&copy.date[1][0],
		&copy.date[1][1],&copy.date[1][2],&copy.date[2][0],&copy.date[2][1],&copy.date[2][2],&copy.date[3][0],&copy.date[3][1],&copy.date[3][2],
		&copy.date[4][0],&copy.date[4][1],&copy.date[4][2]) != EOF) {
			printf("User Name: %s ", copy.name);
			printf("User Password: %s \n", copy.password);
		
		if(copy.total[0] != 0){
			printf("Order is 1  %.1f \n",copy.total[0]);
			printf("Day of order 1 is : %d %d %d\n",copy.date[0][0],copy.date[0][1],copy.date[0][2]);
		}
		
		if(copy.total[1] != 0){
			printf("Order is 2  %.1f \n",copy.total[1]);
			printf("Day of order 2 is : %d %d %d\n",copy.date[1][0],copy.date[1][1],copy.date[1][2]);
		}
		
		if(copy.total[2] != 0){
			printf("Order is 3  %.1f \n",copy.total[2]);
			printf("Day of order 3 is : %d %d %d\n",copy.date[2][0],copy.date[2][1],copy.date[2][2]);
		}
		
		if(copy.total[3] != 0){
			printf("Order is 4  %.1f \n",copy.total[3]);
			printf("Day of order 4 is : %d %d %d\n",copy.date[3][0],copy.date[3][1],copy.date[3][2]);
		}
		
		if(copy.total[4] != 0){
			printf("Order is 5  %.1f \n",copy.total[4]);
			printf("Day of order 5 is : %d %d %d\n",copy.date[4][0],copy.date[4][1],copy.date[4][2]);
		}
	}
	Sleep(5000);
}

// ------------------->Storing Order Detail<----------------------
void storing(char str[], char password[], float totalPrice) {
    data copy;
    int found = 0, stored = 0;

    FILE *ptr = fopen("FastFood.txt", "a+");
    FILE *ptr2 = fopen("CopyFastFood.txt", "w");

    if (ptr == NULL || ptr2 == NULL) {
        printf("\nError: Could not open file(s).\n");
        if (ptr) fclose(ptr);
        if (ptr2) fclose(ptr2);
        return;
    }

    time_t current_time = time(NULL);
    struct tm *local_time = localtime(&current_time);
    int year = local_time->tm_year + 1900;
    int month = local_time->tm_mon + 1;
    int date = local_time->tm_mday;

    while (fscanf(ptr, "%s %s %f %f %f %f %f %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
                  copy.name, copy.password,
                  &copy.total[0], &copy.total[1], &copy.total[2],
                  &copy.total[3], &copy.total[4],
                  &copy.date[0][0], &copy.date[0][1], &copy.date[0][2],
                  &copy.date[1][0], &copy.date[1][1], &copy.date[1][2],
                  &copy.date[2][0], &copy.date[2][1], &copy.date[2][2],
                  &copy.date[3][0], &copy.date[3][1], &copy.date[3][2],
                  &copy.date[4][0], &copy.date[4][1], &copy.date[4][2]) != EOF) {
        if (strcmp(copy.name, str) == 0 && strcmp(copy.password, password) == 0) {
            stored = 1;
            for (int i = 0; i < 5; i++) {
                if (copy.total[i] == 0) {
                    copy.total[i] = totalPrice;
                    copy.date[i][0] = date;
                    copy.date[i][1] = month;
                    copy.date[i][2] = year;
                    found = 1;
                    break;
                }
            }

            if (found==0) {
                for (int i = 1; i < 5; i++) {
                    copy.total[i - 1] = copy.total[i];
                    copy.date[i - 1][0] = copy.date[i][0];
                    copy.date[i - 1][1] = copy.date[i][1];
                    copy.date[i - 1][2] = copy.date[i][2];
                }
                copy.total[4] = totalPrice;
                copy.date[4][0] = date;
                copy.date[4][1] = month;
                copy.date[4][2] = year;
            }
        }
        fprintf(ptr2, "%s %s %.2f %.2f %.2f %.2f %.2f %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n",
                copy.name, copy.password,
                copy.total[0], copy.total[1], copy.total[2],
                copy.total[3], copy.total[4],
                copy.date[0][0], copy.date[0][1], copy.date[0][2],
                copy.date[1][0], copy.date[1][1], copy.date[1][2],
                copy.date[2][0], copy.date[2][1], copy.date[2][2],
                copy.date[3][0], copy.date[3][1], copy.date[3][2],
                copy.date[4][0], copy.date[4][1], copy.date[4][2]);
    }

    if (stored==0) {
        strcpy(copy.name, str);
        strcpy(copy.password, password);
        for (int i = 1; i < 5; i++) {
            copy.total[i] = 0;
            copy.date[i][0] = copy.date[i][1] = copy.date[i][2] = 0;
        }
        copy.total[0] = totalPrice;
        copy.date[0][0] = date;
        copy.date[0][1] = month;
        copy.date[0][2] = year;

        fprintf(ptr2, "%s %s %.2f %.2f %.2f %.2f %.2f %d %d %d\n",
                copy.name, copy.password,
                copy.total[0], copy.total[1], copy.total[2],
                copy.total[3], copy.total[4],
                copy.date[0][0], copy.date[0][1], copy.date[0][2]);
    }

    fclose(ptr);
    fclose(ptr2);

    remove("FastFood.txt");
    rename("CopyFastFood.txt", "FastFood.txt");
}

// ------------------->Printing Menu of Fast Food Restaurant<----------------------
void Menufast() {
	system("cls");
	
		printf("           *********************************************\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *            ----->fast food<-----          *\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *********************************************\n\n\n");

	
    printf("\n		  ----------- \n");
    printf("\n	        | OUR MENU IS |\n");
    printf("\n	          ----------- \n");
    printf("\n		1. burger\n");
    printf("\n		2. BBQ\n");
    printf("\n		3. pizza\n");
    printf("\n		4. poll\n");
    printf("\n		5. juice\n");
    printf("\n		6. ice Cream\n");
    printf("\n		7. exit\n");

}

// ------------------->Selecting Item<----------------------
void selectItem(const char* itemName, float pricePerUnit) {
    int quantity;
    printf("\n		enter quantity for %s: ", itemName);
    scanf("%d", &quantity);
    
	if (quantity > 0) {
        float itemTotal = quantity * pricePerUnit;
        totalPrice += itemTotal;
		system("cls");
        printf("	   YOUR TOTAL BILL IS : %.2f \n\n\n",itemTotal);
    }
	
	else {
        printf("\n	   invalid quantity...\n");
    }
    
    return ;
}

// ------------------->Printing Burger Menu<----------------------
void BurgerMenu() {
	system("cls");
printf("\n			   ----->BURGER MENU<-----\n\n\n");
    
	int choice;
        printf("\n	   1. zinger Burger - 450\n");
        printf("\n	   2. chicken Burger - 400\n");
        printf("\n	   3. cheese Burger - 370\n");
        printf("\n	   4. veggie Burger - 350\n");
        printf("\n	   5. back to main menu\n");
        printf("\n	   enter a number to continue... ");
        scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Zinger Burger", 450);
            break;
        case 2:
            selectItem("Chicken Burger", 400);
            break;
        case 3:
            selectItem("Cheese Burger", 370);
            break;
        case 4:
            selectItem("Veggie Burger", 350);
            break;
        case 5:
            return;
        default:
            printf("\n		invalid choice...\n");
    }
}

// ------------------->Printing BARBQ Menu<----------------------
void BarBQMenu() {
	system("cls");
    
	int choice;
printf("\n			   ----->BBQ MENU<-----\n\n\n");
    printf("\n		1. chicken tikka - 540 \n");
    printf("\n		2. beef kebab - 500 \n");
    printf("\n		3. fried fish - 1200 \n");
    printf("\n		4. back to main menu\n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Chicken Tikka", 540);
            break;
        case 2:
            selectItem("Beef Kebab", 500);
            break;
        case 3:
            selectItem("Fried Fish", 1200);
            break;
        case 4:
            return;
        default:
            printf("		invalid choice... \n");
    }
}

// ------------------->Printing Pizza Menu<----------------------
void PizzaMenu() {
	system("cls");
    int choice;
printf("\n			   ----->PIZZA MENU<-----\n\n\n");
    
    printf("\n		1. chicken fatjita - 1200 \n");
    printf("\n		2. chicken tikka  - 1100 \n");
    printf("\n		3. BBQ chicken - 1150 \n");
    printf("\n		4. achari - 1000 \n");
    printf("\n		5. back to main menu\n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Chicken Fatjita Pizza", 1200);
            break;
        case 2:
            selectItem("Chicken Tikka Pizza", 1100);
            break;
        case 3:
            selectItem("BBQ Chicken Pizza", 1150);
            break;
        case 4:
            selectItem("Achari Pizza", 1000);
            break;
        case 5:
            return;
        default:
            printf("\n		invalid choice...\n");
    }
}

// ------------------->Printing Roll Menu<----------------------
void RollMenu() {
	system("cls");
    
	int choice;
printf("\n			   ----->ROLL MENU<-----\n\n\n");
    printf("\n		1. chicken roll - 170 \n");
    printf("\n		2. beef roll - 350 \n");
    printf("\n		3. zinger roll - 250 \n");
    printf("\n		4. back to ain menu\n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Chicken Roll", 170);
            break;
        case 2:
            selectItem("Beef Roll", 350);
            break;
        case 3:
            selectItem("Zinger Roll", 250);
            break;
        case 4:
            return;
        default:
            printf("\n		invalid choice...\n");
    }
}

// ------------------->Printing Juice Menu<----------------------
void JuiceMenu() {
	system("cls");
    int choice;
    
printf("\n			   ----->JUICE MENU<-----\n\n\n");
    printf("\n		1. orange juice - 150 \n");
    printf("\n		2. apple juice - 170 \n");
    printf("\n		3. mango juice - 150 \n");
    printf("\n		4. pineapple juice - 200 \n");
    printf("\n		5. back to main menu\n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Orange Juice", 150);
            break;
        case 2:
            selectItem("Apple Juice", 170);
            break;
        case 3:
            selectItem("Mango Juice", 150);
            break;
        case 4:
            selectItem("Pineapple Juice", 200);
            break;
        case 5:
            return;
        default:
            printf("\n		invalid choice...\n");
    }
}

// ------------------->Printing ICECREAM Menu<----------------------
void IceCreamMenu() {
	system("cls");
    int choice;
    
printf("\n			   ----->ICECREAM MENU<-----\n\n\n");
    printf("\n		1. chocolate - 150 \n");
    printf("\n		2. vanilla - 170 \n");
    printf("\n		3. strawberry - 150 \n");
    printf("\n		4. mango - 200 \n");
    printf("\n		5. back to main menu\n");
    printf("\n		enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Chocolate Ice Cream", 150);
            break;
        case 2:
            selectItem("Vanilla Ice Cream", 170);
            break;
        case 3:
            selectItem("Strawberry Ice Cream", 150);
            break;
        case 4:
            selectItem("Mango Ice Cream", 200);
            break;
        case 5:
            return;
        default:
            printf("\n		invalid choice....\n");
    }
}

// ------------------->Printing Fast Food<----------------------
void fastfood(char str[],char password[]){
	system("cls");
	int choice;
	int c;
    
	while(1){
        Menufast();
        printf("\n		enter a number to continue... ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                BurgerMenu();
                break;
            case 2:
                BarBQMenu();
                break;
            case 3:
                PizzaMenu();
                break;
            case 4:
                RollMenu();
                break;
            case 5:
                JuiceMenu();
                break;
            case 6:
                IceCreamMenu();
                break;
            case 7:
            	totalPrice = discountofbulk(totalPrice);
                printf("\n	   TOTAL ORDER PRICE : %.2f\n", totalPrice);
                c = paymentsystem();
				if(c == 0)storing(str,password,totalPrice);
				
				return ;
            default:
                printf("\n		invalid choice... try again...\n\n\n");
        } 
    }
    return ;
}

// ------------------->Printing Menu of Restaurant Desi<----------------------
void Menudesi() {
	system("cls");
	
		printf("           *********************************************\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *               ----->desi food<-----       *\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *********************************************\n\n\n");
    
    printf("\n	     ----------- \n");
    printf("\n	   | OUR MENU IS |\n");
    printf("\n             ----------- \n");
    printf("\n		1. karahi \n");
    printf("\n		2. BBQ\n");
    printf("\n		3. daal \n");
    printf("\n		4. paratha \n");
    printf("\n		5. juice\n");
    printf("\n		6. ice Cream\n");
    printf("\n		7. exit \n");
}

// ------------------->Printing Karachi Menu<----------------------
void KarahiMenu() {
    int choice;
    system("cls");
    
printf("\n			   ------>KARAHI MENU<------\n\n\n");
    printf("\n		1. special karahi - 1200 \n");
    printf("\n		2. motton karahi - 1750 \n");
    printf("\n		3. beef karahi - 1950 \n");
    printf("\n		4. chicken karahi -1400 \n");
    printf("\n		5. back to main menu \n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Special Karahi", 1200);
            break;
        case 2:
            selectItem("Motton Karahi", 1750);
            break;
        case 3:
            selectItem("Beef Karahi ", 1950);
            break;
        case 4:
            selectItem("Chicken Karahi", 1400);
            break;
        case 5:
            return;
        default:
            printf("\n		invalid choice... \n");
    }
}

// ------------------->Printing BAR BQ Menu of Desi<----------------------
void BarBQMenudesi() {
    int choice;
    system("cls");
    

printf("\n			   ------>BBQ MENU<------\n\n\n");
    printf("\n		1. chicken tikka - 320 \n");
    printf("\n		2. reshmi kebab - 190 \n");
    printf("\n		3. chicken behari boti - 300 \n");
    printf("\n		4. back to main menu\n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Chicken Tikka", 320);
            break;
        case 2:
            selectItem("Reshmi Kebab", 190);
            break;
        case 3:
            selectItem(" Chicken Behari Boti", 300);
            break;
        case 4:
            return;
        default:
            printf("\n		invalid choice... \n");
    }
}

// ------------------->Printing DAAL Menu<----------------------
void DaalMenu() {
    int choice;
    system("cls");
    
printf("\n			   ----->DAAL MENU<-----\n\n\n");
    printf("\n		1. 1KG channa daal - 850 \n");
    printf("\n		2. 1KG masoor daal - 950 \n");
    printf("\n		3. 1KG moong daal - 920 \n");
    printf("\n		4. 1KG anda daal - 1050 \n");
    printf("\n		5. back to main menu \n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Channa Daal", 850);
            break;
        case 2:
            selectItem("Masoor Daal", 950);
            break;
        case 3:
            selectItem("Moong Daal",920);
            break;
        case 4:
            selectItem("Anda Daal", 1050);
            break;
        case 5:
            return;
        default:
            printf("Invalid choice \n");
    }
}

// ------------------->Printing Paratha Menu<----------------------
void ParathaMenu() {
    int choice;
    system("cls");
    
printf("\n			   ----->PARATHA MENU<-----\n\n\n");
    printf("\n		1. simple paratha - 50 \n");
    printf("\n		2. aloo paratha - 100 \n");
    printf("\n		3. lachaa paratha - 90 \n");
    printf("\n		4. back to main menu \n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Simple Paratha", 50);
            break;
        case 2:
            selectItem("Aloo Paratha", 100);
            break;
        case 3:
            selectItem("Lachaa Paratha", 90);
            break;
        case 4:
            return;
        default:
            printf("\n		invalid choice... \n");
    }
}

// ------------------->Printing Juice Menu of Desi<----------------------
void JuiceMenudesi() {
    int choice;
    system("cls");
    
printf("\n			   ----->JUICE MENU<-----\n\n\n");
    printf("\n		1. banana juice - 160 \n");
    printf("\n		2. apple juice - 180 \n");
    printf("\n		3. pineapple juice - 200 \n");
    printf("\n		4. peach juice - 250 \n");
    printf("\n		5. back to main menu\n");
    printf("\n		enter a number to continue... ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Banana Juice", 160);
            break;
        case 2:
            selectItem("Apple Juice", 180);
            break;
        case 3:
            selectItem("Pineapple Juice", 200);
            break;
        case 4:
            selectItem("Peach Juice", 250);
            break;
        case 5:
            return;
        default:
            printf("\n		invalid choice... \n");
    }
}

// ------------------->Printing Icecream Menu of Desi<----------------------
void IceCreamMenudesi() {
    int choice;
    system("cls");
    
printf("\n			   ----->ICECREAM MENU<-----\n\n\n");
    printf("\n		1. chocolate - 150 \n");
    printf("\n		2. butter pecan - 210 \n");
    printf("\n		3. strawberry - 150 \n");
    printf("\n		4. cherry - 190 \n");
    printf("\n		5. back to main menu\n");
    printf("\n		enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            selectItem("Chocolate Ice Cream", 150);
            break;
        case 2:
            selectItem("Butter Pecan ", 210);
            break;
        case 3:
            selectItem("Strawberry Ice Cream", 150);
            break;
        case 4:
            selectItem("Cherry Ice Cream", 190);
            break;
        case 5:
            return;
        default:
            printf("\n		invalid choice... \n");
    }
}

// ------------------->Printing Desi Food<----------------------
void desifood(char str[],char password[]){
	int choice;
	int c;
	
	system("cls");
    
	while(1){
        Menudesi();
        printf("\n	   enter a number to continue... ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                KarahiMenu();
                break;
            case 2:
                BarBQMenudesi();
                break;
            case 3:
                DaalMenu();
                break;
            case 4:
                ParathaMenu();
                break;
            case 5:
                JuiceMenudesi();
                break;
            case 6:
                IceCreamMenudesi();
                break;
            case 7:
            	totalPrice = discountofbulk(totalPrice);
                printf("\nTotal Order Prize : %.2f\n", totalPrice);
                c = paymentsystem();
				if(c == 0)storing(str,password,totalPrice);
                return ;
            default:
                printf("\n	   invalid choice... try again... \n\n\n");
        } 
    }
    return;
}

// ------------------->Printing Start System<----------------------
void continuous(char str[],char password[]){
	int num;
	system("cls");

		printf("           *********************************************\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *               ----->home<-----            *\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *********************************************\n\n\n");
	do{
	printf("\n	   1. fast food\n");
	printf("\n	   2. desi food\n");
	printf("\n	   3. back to welcome screen\n");
	printf("\n	   enter a number to continue... ");
	scanf("%d", &num);
	
		if( num == 1){
			fastfood(str,password);
			return ;
		}
	
		else if( num == 2){
			desifood(str,password);
			return ;
		}

		else if( num == 3){
			return ;
		}

		else {
			printf("\n	   invalid option!...\n");
		}
	}while(1);
}


// ------------------->Printing Admin Login<----------------------
void adminlogin(){
	system("cls");
	login str;
				   
printf("\n			   ------>ADMIN LOGIN<------\n\n\n");
	printf("	   [username is admin123]\n");
	printf("	   admin username: ");
	scanf(" %49s", str.name);
	getchar();
	
	if(strcmp(str.name,"admin123") !=0 ) {
		printf("\n	   incorrect username, access denied...\n");
		return ;
	}

	printf("	   [password is 765626]\n");	
	printf("	   enter password: ");
	scanf(" %s", str.password);
	
	if(strcmp(str.password, "765626") == 0){
printf("\n			   ------>ADMIN LOGIN SUCCESFUL<------\n\n\n");
			adminchecking();
		return ;
	}
	printf("\n	   incorrect password, access denied...\n");
	
	return ;
}

// ------------------->Checking User<----------------------
int checkuser(char str[], char password[]){
	login check;
	FILE *ptr=fopen("login.txt","a+");
	
	if (ptr == NULL) {
        	printf("\n	   error, file doesn't exist...\n");
        	return 0;
        }
    
	while(fscanf(ptr, "%s %s", check.name, check.password) != EOF){
    		if (strcmp(check.name, str) == 0 || strcmp(check.password, password) == 0) {
    			printf("\n	   username or password already exists...\n");
        			return 1;
		}		
	}	
	fclose(ptr);

	return 0;	
}

// ------------------->Printing Add User<----------------------
void adduser(){
	system("cls");
	login str;
	int c=0;
				   
printf("\n			   ----->ADD USER<-----\n\n\n");
	do{
		printf("\n	   create username[without space]: ");
		scanf("%49s", str.name);
		getchar();
		printf("\n 	   create Password[without spaces]: ");
		scanf("%49s", str.password);
		c = checkuser(str.name,str.password);//Checking if user exist with same user name
	}while(c == 1);
	
	FILE *ptr=fopen("login.txt","a");
	
	if (ptr == NULL) {
        printf("Error\n");
        return;
    }
	
	fprintf(ptr,"\n%s  %s",str.name,str.password);
	fclose(ptr);
	
	return ;
	
}

// ------------------->Printing Change Password<----------------------
void changepassword(){
    system("cls");
    printf("\n\t\t\t----->CHANGE PASSWORD<-----\n\n");

    login str, str2;
    int found = 0;
    char change[50];

    printf("\n\tEnter username: ");
    scanf("%49s", str.name);

    printf("\n\tEnter your current password: ");
    scanf("%49s", str.password);

    FILE *ptr = fopen("login.txt", "r");
    if (ptr == NULL) {
        printf("\n\tError: File doesn't exist...\n");
        return;
    }

    FILE *ptr2 = fopen("copy.txt", "w");
    if (ptr2 == NULL) {
        printf("\n\tError: Unable to create temporary file...\n");
        fclose(ptr);
        return;
    }

    while (fscanf(ptr, "%49s %49s", str2.name, str2.password) != EOF) {
        if (strcmp(str2.name, str.name) == 0 && strcmp(str2.password, str.password) == 0) {
            found = 1;
            printf("\n\tEnter new password: ");
            scanf("%49s", change);
            strcpy(str2.password, change);
        }
        fprintf(ptr2, "%s %s\n", str2.name, str2.password);
    }

    fclose(ptr);
    fclose(ptr2);

    if (found) {
        remove("login.txt");
        rename("copy.txt", "login.txt");
        printf("\n\tPassword changed successfully...\n");
        Sleep(1000);
    } else {
        printf("\n\tRecord not found...\n");
        Sleep(1000);
        remove("copy.txt");
    }

	return ;

}

// ------------------->Printing Find User<----------------------
void finduser(){
	system("cls");
	login str,str2;
	int found=0;
printf("			   ----->FIND USER<-----\n\n\n");
	printf("\n	   enter username: ");
	scanf("%49s", str.name);
	
	printf("\n	   enter password: ");
	scanf("%49s", str.password);
	
	
	FILE *ptr=fopen("login.txt","a+");
	 if (ptr == NULL) {
        printf("Error\n");
        return;
    }
    int num;
	
	while(fscanf(ptr,"%s  %s",str2.name,str2.password) != EOF){
		if (strcmp(str2.name, str.name) == 0 && strcmp(str2.password, str.password) == 0) {
            found = 1;
            system("cls");
printf("\n			   ----->USER AVAILABLE<-----\n\n\n");
        	    printf("\n	   1. change password\n");
		    printf("\n	   2. Place an order\n");
		    printf("\n	   enter a number to continue...");
	            scanf("%d", &num);
        	    if(num==1){
	            	fclose(ptr);
            		changepassword();
			return;
		    }else if(num == 2){
			continuous(str.name,str.password);
		    }
	            break;
        	}
	}
	
	if(found==0){
		printf("\n	   error, user unavailable...\n");
		Sleep(1000);
	}
	
	fclose(ptr);
	return ;
}


// ------------------->Main Function<----------------------
int main(){
	login str;
	int num;
	// Printing the loading system at start
	int i,j;
	int a=177,b=219; 
	printf("\t\t\t\t         ");
	
	for(j=0;j<20;j++)
		printf("%c",a);
	printf("]\r");
	printf("\t\t\t\tLoading [");
	
	for(i=0;i<20;i++){
		Sleep(100);
		printf("%c", b);
	}
	
	printf("]\n\n");
	// BackGround Color
	system("COLOR f8");
	
	do{
		system("cls");
		printf("           *********************************************\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *             ----->WELCOME<-----           *\n");
		printf("           *    -----------------------------------    *\n");
		printf("           *********************************************\n\n\n");
				   
		printf("\n	   1. admin Login\n");
		printf("\n           2. customer Registration\n");
		printf("\n           3. customer Login\n");
		printf("\n           4. exit\n\n\n");
		printf("\n	   enter a number to continue... ");
		scanf("%d", &num);
		printf("\n");
		if(num==1){
			adminlogin();
		}
		else if(num==2){
			adduser();
			printf("\n	   added Succesfully...\n");
			Sleep(1000);
		}
		else if(num==3){
			finduser();
		}
		else if(num==4){

			printf("\n	   exiting, please wait...!\n");
printf("\n			   ----->THANK YOU!<-----\n\n\n");
			return 0;
		}
		else {
			printf("\n	   invalid option...\n");
			return 0;
		}
	}while(1);
	
	return 0;
}

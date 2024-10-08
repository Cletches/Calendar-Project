#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int dayList[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// Function to determine if a year is a leap year
int isLeapYear(int year) {
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
        return 1;
    }
    return 0;
}



// Function to return the number of digits in a year
int yearLength(int year) {
    int yearL = 0;
    if (year < 10) yearL = 1;
    else if (year < 100) yearL = 2;
    else if (year < 1000) yearL = 3;
    else if (year < 10000) yearL = 4;
    else yearL = 0;
    return yearL;
}



// Function to calculate the starting day of the month (Sunday = 0)
int date(int month, int day, int year) {
    if (isLeapYear(year)) dayList[1] = 29;
    else dayList[1] = 28;

    int acc_days = 0;

    // Add up all the days in the years since 1753
    for (int i = 1753; i < year; i++) {
        if (isLeapYear(i)) acc_days += 366;
        else acc_days += 365;
    }

    // Add up all the days in the months of the current year
    for (int i = 0; i < month - 1; i++) {
        acc_days += dayList[i];
    }

    // Add the days in the current month
    acc_days += day;
    return acc_days % 7;
}




// Function to print a month with proper formatting and correct number of days
int printMonth(int month, int year) {
    // Adjust February days for leap year
    if (isLeapYear(year)) {
        dayList[1] = 29;
    } else {
        dayList[1] = 28;
    } 


    char *mon = months[month - 1];
    int length = strlen(mon); // Month name length
    int yearL = yearLength(year); // Year length
    int spaces = (20 - (length + yearL)) / 2; // Centering the month-year header

    // Print the month and year header
    for (int i = 0; i < spaces; i++) printf(" ");
    printf("%s %d\n", mon, year);

    // Print the days of the week
    printf("Su Mo Tu We Th Fr Sa\n");

    // Calculate the starting day of the month
    int startDay = date(month,1, year);

    // Print leading spaces for the first week
    for (int i = 0; i < startDay; i++) {
        printf("   ");
    }

    // Print the days of the month
    for (int day = 1; day <= dayList[month - 1]; day++) {
        printf("%2d ", day);
        if ((day + startDay) % 7 == 0) {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}



// Function to find the current month
int findCurrentMonth(){
    //returns current month in integer form
    time_t timenow;

    struct tm *current;

    //check the time function documentation
    time (&timenow);

    //returns address to struct tim, so tm needs to be address
    current = localtime (&timenow);

    int currentMonth = current->tm_mon+1;
    return currentMonth;

}




// Function to find the current year
int findCurrentYear(){
    //returns current year in integer form
    time_t timenow;

    struct tm *current;

    //check the time function documentation
    time (&timenow);

    //returns address to struct tim, so tm needs to be address
    current = localtime (&timenow);

    int currentYear = current->tm_year+1900;
    return currentYear;
}



// Function to match the first three letters of a month string
int firstThreeLetters(char *str) {
    for (int i = 0; i < 12; i++) {
        if (strncmp(str, months[i], 3) == 0) {
            printMonth(i + 1, findCurrentYear());
            return 0;
        }
    }
    printf("Error in the month\n");
    return -1;
}



// Function to handle both three-letter month abbreviation and year
int firstThreeLettersAndYear(char *str, int year) {
    for (int i = 0; i < 12; i++) {
        if (strncmp(str, months[i], 3) == 0) {
            printMonth(i + 1, year);
            return 0;
        }
    }
    printf("Error in the month \n");
    return -1;
}




int main(int argc, char *argv[]) {
 // When the input is one like (cal)   
    if (argc == 1) {
        printMonth(findCurrentMonth(), findCurrentYear());
    } 

// When the input is two 
    else if (argc == 2) {
        // Only year is provided
        int year = atoi(argv[1]);
        if (year > 0) {
            for (int i = 1; i <= 12; i++) {
                printMonth(i, year);
            }
        } else {
            printf("Invalid year input.\n");
        }
    } 


// When the input is three
    else if (argc == 3) {
        if (strcmp(argv[1], "-m") == 0) {
            if (atoi(argv[2]) > 0 && atoi(argv[2]) <= 12) {
                // Month number is provided
                printMonth(atoi(argv[2]), findCurrentYear());
            } else if (!atoi(argv[2])) {
                // Three-letter month abbreviation
                firstThreeLetters(argv[2]);
            }
        } else {
            int month = atoi(argv[1]);
            int year = atoi(argv[2]);
            if (month > 0 && month <= 12 && year > 0) {
                printMonth(month, year);
            } else {
                printf("Invalid input.\n");
            }
        }
    }


// When the input    
    else if(argc == 4){
    if (strcmp(argv[1],"-m") == 0 && !atoi(argv[2]) && atoi(argv[3]) <= 9999){
        int year = atoi(argv[3]);
        firstThreeLettersAndYear(argv[2],year);

    }
    else if(strcmp(argv[1],"-m") == 0 && atoi(argv[2]) <= 12 && atoi(argv[3]) <= 9999){
        int year=  atoi(argv[3]);
        int month = atoi(argv[2]);
        printMonth(month,year);
    }

}
    // } else if (argc == 4) {
    //     if (strcmp(argv[1], "-m") == 0 && !atoi(argv[2])) {
    //         int year = atoi(argv[3]);
    //         firstThreeLettersAndYear(argv[2], year);
    //     }
    // } else {
    //     printf("Invalid input.\n");
    // }
    return 0;
}

# Calendar-Project
Calendar Program (cal.c)
Overview
This is a simplified version of the cal program, which prints out the Gregorian calendar, assuming it
has been in use since year 1. The program handles leap years and includes functionality to print the
calendar for any specified month or year.
Features
- Calendar Display: The program prints out a monthly or yearly calendar.
- Leap Year Calculation: Correctly determines leap years.
- User Input: Allows users to input a specific month and year to generate the corresponding
calendar.
- Historical Gregorian Calendar: Assumes the Gregorian calendar has been in use since year 1 for
simplicity.
Program Usage
Compiling the Program:
To compile the program, use a C compiler such as gcc. Run the following command in your
terminal:
gcc -o cal cal.c
Running the Program:
Once compiled, you can run the program by typing:
./cal [month] [year]
- If no arguments are provided, the program will default to printing the current month's calendar.
- If a specific month and year are provided, the program will print the calendar for that month.
Example:
./cal 10 2024
This command will print the calendar for October 2024.
Leap Year Logic
The program follows the leap year rules:
1. A year is a leap year if it is divisible by 4.
2. However, if the year is divisible by 100, it is not a leap year unless it is also divisible by 400.
File Structure
- cal.c: The main C source file containing the implementation of the calendar program.
- cal.txt: (optional) A manual page file that describes the program and its usage, similar to the man
pages for Unix-based commands.
Future Improvements
- Enhance User Input: Allow for more robust input handling and error checking.
- Additional Calendar Formats: Add support for displaying calendars in different formats (e.g., yearly
view).
- Historical Accuracy: Implement historically accurate calendar transitions, including shifts from the
Julian to Gregorian calendar.



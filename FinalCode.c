#include <stdio.h>
#include <conio.h>

int main(void) {
    //para sa menu variables//
    int Choice;
    char Again;
    char Invalidinput[100];

    //para sa pattern generator variables//
    int Size;
    int Shape;
    int Row;
    int Column;
    int Section;
    int Treewidth;
    int Sectionheight;
    int Starcount;
    int Spaces;

    //para sa Pascal's triangle variables//
    int Rows;
    int Triangle[15][15];
    int Valueaboveleft;
    int Valueabove;

    //para sa grade calculator variables//
    double Prelimgrade;
    double Midtermgrade;
    double Prefinalgrade;
    double Finalgrade;
    double Total;
    double Average;

    //para sa palindrome variables//
    char Word[100];
    int Length;
    int Index;
    int Ispalindrome;

    do {
        printf("MENU CONSOLE APPLICATION\n");
        printf("1. Pattern Generator\n");
        printf("2. Pascal's Triangle\n");
        printf("3. Grade Calculator and Evaluator\n");
        printf("4. Palindrome Checker\n");

        do {
            printf("Enter choice (1-4): ");
            if (scanf("%d", &Choice) != 1) {
                scanf("%99s", Invalidinput);
                Choice = 0;
                printf("Invalid input. Enter a number from 1 to 4.\n");
            } else if (Choice < 1 || Choice > 4) {
                printf("Invalid input. Enter a number from 1 to 4.\n");
            }
        } while (Choice < 1 || Choice > 4);

        if (Choice == 1) {
            // mao ni sa pattern generator //
            printf("1. Right triangle\n");
            printf("2. Square\n");
            printf("3. Isosceles triangle\n");
            printf("4. Inverted right triangle\n");
            printf("5. Christmas tree\n");

            do {
                printf("Choose a shape (1-5): ");
                if (scanf("%d", &Shape) != 1) {
                    scanf("%99s", Invalidinput);
                    Shape = 0;
                    printf("Invalid input. Enter a number from 1 to 5.\n");
                } else if (Shape < 1 || Shape > 5) {
                    printf("Invalid input. Enter a number from 1 to 5.\n");
                }
            } while (Shape < 1 || Shape > 5);

            do {
                printf("Enter the pattern size (1-20): ");
                if (scanf("%d", &Size) != 1) {
                    scanf("%99s", Invalidinput);
                    Size = 0;
                    printf("Invalid input. Enter a number from 1 to 20.\n");
                } else if (Size < 1 || Size > 20) {
                    printf("Invalid input. Enter a number from 1 to 20.\n");
                }
            } while (Size < 1 || Size > 20);

            if (Shape == 1) {
                for (Row = 1; Row <= Size; Row++) {
                    for (Column = 1; Column <= Row; Column++) {
                        printf("*");
                    }
                    printf("\n");
                }
            } else if (Shape == 2) {
                for (Row = 1; Row <= Size; Row++) {
                    for (Column = 1; Column <= Size; Column++) {
                        printf("*");
                    }
                    printf("\n");
                }
            } else if (Shape == 3) {
                for (Row = 1; Row <= Size; Row++) {
                    for (Column = 1; Column <= Size - Row; Column++) {
                        printf(" ");
                    }
                    for (Column = 1; Column <= 2 * Row - 1; Column++) {
                        printf("*");
                    }
                    printf("\n");
                }
            } else if (Shape == 4) {
                for (Row = Size; Row >= 1; Row--) {
                    for (Column = 1; Column <= Row; Column++) {
                        printf("*");
                    }
                    printf("\n");
                }
            } else {
                Treewidth = 2 * (Size + 2) - 1;

                for (Section = 1; Section <= 3; Section++) {
                    Sectionheight = Size + Section - 1;
                    for (Row = 1; Row <= Sectionheight; Row++) {
                        Starcount = 2 * Row - 1;
                        Spaces = (Treewidth - Starcount) / 2;
                        for (Column = 1; Column <= Spaces; Column++) {
                            printf(" ");
                        }
                        for (Column = 1; Column <= Starcount; Column++) {
                            printf("*");
                        }
                        printf("\n");
                    }
                }
                for (Row = 1; Row <= 2; Row++) {
                    for (Column = 1; Column <= (Treewidth - 3) / 2; Column++) {
                        printf(" ");
                    }
                    printf("***\n");
                }
            }

        } else if (Choice == 2) {
            //mao ni sa Pascal triangle //
            do {
                printf("Enter the number of rows (1-15): ");
                if (scanf("%d", &Rows) != 1) {
                    scanf("%99s", Invalidinput);
                    Rows = 0;
                    printf("Invalid input. Enter a number from 1 to 15.\n");
                } else if (Rows < 1 || Rows > 15) {
                    printf("Invalid input. Enter a number from 1 to 15.\n");
                }
            } while (Rows < 1 || Rows > 15);

            for (Row = 0; Row < 15; Row++) {
                for (Column = 0; Column < 15; Column++) {
                    Triangle[Row][Column] = 0;
                }
            }

            for (Row = 0; Row < Rows; Row++) {
                for (Column = 0; Column <= Row; Column++) {
                    if (Column == 0 || Column == Row) {
                        Triangle[Row][Column] = 1;
                    } else {
                        Valueaboveleft = Triangle[Row - 1][Column - 1];
                        Valueabove = Triangle[Row - 1][Column];
                        Triangle[Row][Column] = Valueaboveleft + Valueabove;
                    }
                }
            }

            for (Row = 0; Row < Rows; Row++) {
                for (Column = 0; Column < Rows - Row - 1; Column++) {
                    printf("   ");
                }
                for (Column = 0; Column <= Row; Column++) {
                    printf("%6d", Triangle[Row][Column]);
                }
                printf("\n");
            }

        } else if (Choice == 3) {
            // mao ni sa GRADE CALCULATOR AND EVALUATOR //
            do {
                printf("Enter Prelim grade (1.00-5.00): ");
                if (scanf("%lf", &Prelimgrade) != 1) {
                    scanf("%99s", Invalidinput);
                    Prelimgrade = 0.0;
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                } else if (Prelimgrade < 1.0 || Prelimgrade > 5.0) {
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                }
            } while (Prelimgrade < 1.0 || Prelimgrade > 5.0);

            do {
                printf("Enter Midterm grade (1.00-5.00): ");
                if (scanf("%lf", &Midtermgrade) != 1) {
                    scanf("%99s", Invalidinput);
                    Midtermgrade = 0.0;
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                } else if (Midtermgrade < 1.0 || Midtermgrade > 5.0) {
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                }
            } while (Midtermgrade < 1.0 || Midtermgrade > 5.0);

            do {
                printf("Enter Pre-Final grade (1.00-5.00): ");
                if (scanf("%lf", &Prefinalgrade) != 1) {
                    scanf("%99s", Invalidinput);
                    Prefinalgrade = 0.0;
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                } else if (Prefinalgrade < 1.0 || Prefinalgrade > 5.0) {
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                }
            } while (Prefinalgrade < 1.0 || Prefinalgrade > 5.0);

            do {
                printf("Enter Final grade (1.00-5.00): ");
                if (scanf("%lf", &Finalgrade) != 1) {
                    scanf("%99s", Invalidinput);
                    Finalgrade = 0.0;
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                } else if (Finalgrade < 1.0 || Finalgrade > 5.0) {
                    printf("Invalid input. Enter a grade from 1.00 to 5.00.\n");
                }
            } while (Finalgrade < 1.0 || Finalgrade > 5.0);

            Total = Prelimgrade + Midtermgrade + Prefinalgrade + Finalgrade;
            Average = Total / 4.0;
            printf("Average grade: %.2f\n", Average);
            if (Average <= 1.00) {
                printf("Evaluation: A+ or A (Excellent/PASS)\n");
            } else if (Average <= 1.50) {
                printf("Evaluation: A or A- (Very Good/PASS)\n");
            } else if (Average <= 2.00) {
                printf("Evaluation: B+ or B (Good/PASS)\n");
            } else if (Average <= 2.50) {
                printf("Evaluation: B- or C+ (Satisfactory/PASS)\n");
            } else if (Average <= 3.00) {
                printf("Evaluation: C or C- (Fair/PASS)\n");
            } else if (Average <= 4.00) {
                printf("Evaluation: Conditional / Incomplete / FAILED\n");
            } else {
                printf("Evaluation: F (Fail)\n");
            }

        } else {
            // mao ni sa PALINDROME CHECKER //
            Length = 0;          // mo reset every time ang branch mo run //
            Ispalindrome = 1;    // assume true hangtud ma mismatch //

            printf("Enter a single word (up to 99 characters): ");
            scanf("%99s", Word);
            while (getchar() != '\n'); // i clear bisag unsa nga characters sa line

            while (Word[Length] != '\0') {
                Length++;
            }
            for (Index = 0; Index < Length / 2; Index++) {
                if (Word[Index] != Word[Length - 1 - Index]) {
                    Ispalindrome = 0;
                    break;
                }
            }

            if (Ispalindrome) {
                printf("%s is a palindrome.\n", Word);
            } else {
                printf("%s is not a palindrome.\n", Word);
            }
        }

        do {
            printf("\nDo you want to try another operation? (Y/N): ");
            scanf(" %c", &Again);
            while (getchar() != '\n'); // Discard the rest of the input line, asta ang leftover nga newline

            if (Again != 'Y' && Again != 'y' && Again != 'N' && Again != 'n') {
                printf("Invalid input. Enter Y or N.\n");
            }
        } while (Again != 'Y' && Again != 'y' && Again != 'N' && Again != 'n');

        printf("\n------------------------------------\n\n");
    } while (Again == 'Y' || Again == 'y');

    printf("Thank you for using our program.\n");
    printf("Press Enter or any key to exit...");
    getch();
    return 0;
}

#include <iostream>
#include <string>

using namespace std;


bool isLeapYear(short Year)
{
    return (Year % 400 == 0 || (Year % 4 == 0 && Year % 100 != 0));
}


short ReadDay()
{
    short day;
    cout << "Enter a Day (1-31): ";
    cin >> day;
    return day;
}

short ReadMonth()
{
    short month;
    cout << "Enter a Month (1-12): ";
    cin >> month;
    return month;
}


short ReadYear()
{
    short year;
    cout << "Enter a Year: ";
    cin >> year;
    return year;
}


string NameMonth(short month)
{
    string arrMonths[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };
    return arrMonths[month - 1];
}


short NumberOfDaysInAMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    short NumberOfDays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];
}


short DayOfWeekOrder(short year, short month, short day)
{
    short a = (14 - month) / 12;
    short y = year - a;
    short m = month + (12 * a) - 2;

    return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
}


void PrintMonthCalendar(short year, short currentMonth, short targetMonth, short targetDay)
{
    short NumberOfDays = NumberOfDaysInAMonth(currentMonth, year);
    short current = DayOfWeekOrder(year, currentMonth, 1);

    printf("\n_______________%s_______________\n\n", NameMonth(currentMonth).c_str());
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
   
    for (i = 0; i < current; i++)
        printf("     ");

    for (short j = 1; j <= NumberOfDays; j++)
    {

        if (currentMonth == targetMonth && j > targetDay)
        {
            break;
        }

        printf("%5d", j);


        if (++i == 7)
        {
            i = 0;
            cout << "\n";
        }
    }
    cout << "\n_________________________________\n";
}

void PrintCalendarGridUpToDate(short year, short targetMonth, short targetDay)
{
    printf("\n=================================");
    printf("\n   Calendar Range - Year %d", year);
    printf("\n=================================\n");

    for (short m = 1; m <= targetMonth; m++)
    {
        PrintMonthCalendar(year, m, targetMonth, targetDay);
    }
}

int main()
{
    short year = ReadYear();
    short month = ReadMonth();
    short day = ReadDay();

    PrintCalendarGridUpToDate(year, month, day);

    system("pause>0");
    return 0;
}
//Name: Mathavan A/L Krishnan
//ID: 1201101510
//Date: 14/9/2021
//Program Description: MTRS, Movie Ticket Reservation System
// class - Movie, Menu, Member, Customer
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int counter, selection_movie;
const int WIDTH = 77, MAXMOVIES = 15;

class Movie
{
    public:
        string name, day, time1, time2, time3;
};

using MOVIE = Movie[MAXMOVIES];
vector<string> movie_name(25);
vector<string> showtime1(25);
vector<string> showtime2(25);
vector<string> showtime3(25);

void movie_booking();

void title()
{
    const int WIDTH = 88;
    const int WIDTH1 =  18;
    const string heading =  "MOVIE TICKET RESERVATION SYSTEM (MTRS)" ;
    cout << "\n\n ";
         for(int i = 0; i < WIDTH1; i++){
                    cout << ' ';
            }
         for(int i = 0; i < WIDTH; i++){
                cout << '*';
            }
    cout << "\n\n";
    cout << "                                            " << heading;
    cout << "\n\n ";
         for(int i = 0; i < WIDTH1; i++){
                    cout << ' ';
            }
         for(int i = 0; i < WIDTH; i++){
                cout << '*';
            }
    cout << "\n\n";
}

bool CompareNames(Movie movie1, Movie movie2)
{
    if (movie2.name > movie1.name)
        return true;  // <--- Means to swap.
        return false;  // <--- Means do nothing.
}

int ReadFile(MOVIE& movies, int& movieCount)
{
    string file_name = "Movies.txt";  // <--- Put File name here.
    int i;
    ifstream movies_file("Movies.txt");

    if (!movies_file){
        cout << "\n File " << "\"" << file_name << "\"" << " did not open." << endl;
    }

    while (getline(movies_file, movies[i].name, '|')){
        getline(movies_file, movies[i].day, '|');
        getline(movies_file, movies[i].time1, '|');
        getline(movies_file, movies[i].time2, '|');
        getline(movies_file, movies[i].time3);
        movies_file.clear();

        i++;
    }

    movieCount = i;

    return 0;
}

void showmovielist(MOVIE& movies, const int movieCount)
{
    system("CLS");

    ifstream movie("Movies.txt");

    int count = 0;
    string line;
    title();
    cout << "\n " << string(WIDTH, '=') << "\n";
    cout << "| SERIAL |" << string(55, ' ') << "|  SHOWTIME  | " << '\n';
    cout << "| NUMBER |                 MOVIE NAME                    |  DAY  |  AVAILABLE | " << '\n';
    cout << ' ' << string(WIDTH, '=') << "\n";

    int j = 1;
    int i = 1;

    sort(movies, movies + movieCount, CompareNames);
    int idx;
    for (idx = 1; idx < movieCount; idx++)
    {
        if (movies[idx+1].name == movies[idx].name)
        {
            cout <<
                "    (" << idx  << ") " <<
                std::left << string(3, ' ') <<
                std::setw(45) << movies[idx].name << "    " <<
                std::setw(7) << movies[idx].day <<
                "(" << j << ") " <<
                movies[idx].time1  << "\n" <<
                string(67, ' ') << "(" << j + 1 << ") " <<
                movies[idx].time2 << "\n" <<
                string(67, ' ') << "(" << j + 2 << ") " <<
                movies[idx].time3 << "\n";
        }

        else
        {
            cout <<
                "    (" << idx  << ") " <<
                std::left << string(3, ' ') <<
                std::setw(45) << movies[idx].name << "    " <<
                std::setw(7) << movies[idx].day <<
                "(" << j << ") " <<
                movies[idx].time1 << "\n" <<
                string(67, ' ') << "(" << j + 1 << ") " <<
                movies[idx].time2 << "\n" <<
                string(67, ' ') << "(" << j + 2 << ") " <<
                movies[idx].time3 << "\n";

            cout << ' ' << string(WIDTH, '=') << "\n";

        }

         movie_name[i] = movies[idx].name;
         showtime1[i] = movies[idx].time1;
         showtime2[i] = movies[idx].time2;
         showtime3[i] = movies[idx].time3;
         i = i + 1;
         j = 1;
    }
     counter = idx;
}

void time_checking(int time[], int i)
{
    while(!cin >> time[i])
    {
        cout << endl;
        cout << " Enter a valid time: " ;
        cin.clear();
        cin.ignore(25,'\n');
        cin >> time[i];
    }

    while((time[i] > 2400) || (time[i] < 0))
    {
        cout << endl;
        cout << " You have entered a wrong time for movie. Enter again!!"<< endl;
        cout << " Enter the time for " << i << " show  (HHMM): ";
        cin >> time[i];
    }
}

void add_movie()
{
    system("CLS");
    char name [25], day[25];
    int time[3] = {}, i = 0;
    fstream movie;
    movie.open("Movies.txt",ios::app);

    title();
    cout << "Adding new movie!!" << endl << endl;

    cin.ignore();
    cout << " Enter the movie name: ";
    cin.getline(name,25);
    cout << " Enter the day of the showtime: ";
    cin.getline(day,25);
    cout << " Enter the time for First show  (HHMM): ";
    cin >> time[0];
    time_checking(time, i);
    i = 1;

    cout << " \nEnter the time for Second show (HHMM): ";
    cin >> time[1];
    time_checking(time, i);
    i = 2;

    cout << "\n Enter the time for Third show  (HHMM): ";
    cin >> time[2];
    time_checking(time, i);

    movie << name << '|' << time[0] << '|' << time[1] << '|' << time[2];
    cout << endl << endl;
    cout << "You are done, Manager!";
    movie.close();
}

delete_movie()
{
    fstream movie, temp;
    int lines, movieCount{}, readStatus{} ;
    char selection_movie1, name [25], time1[25], time2[25], time3[25];
    movie.open("Movies.txt",ios::in);
    temp.open("temp.txt",ios::out);

    MOVIE movies;
    if (readStatus = ReadFile(movies, movieCount)){
        return readStatus;
    }
    showmovielist(movies, movieCount);

    cout << "/n Enter the serial number of the movie that you want to delete [1,2,3...] : ";
    cin >> selection_movie1;

    string noLines;
    ifstream file("Movies.txt");
    while (!file.eof())
    {
        getline(file, noLines);
        lines++;
    }

    while((selection_movie1 <= '0') || (selection_movie1 > lines))
    {
        cout << "\n"
             << "Sorry! You have entered a wrong selection. Please try again.\n\n"
             << "Please select a movie: ";
        cin >> selection_movie1;
    }

    selection_movie = static_cast<int>(selection_movie1);
    int i = 0;
    while(i++ , i <= lines){
        movie.getline(name,25,'|');
        movie.getline(time1,25,'|');
        movie.getline(time2,25,'|');
        movie.getline(time3,25);

        if (i == selection_movie){
            continue;
        }
        else{
            temp << name << '|' << time1 << '|' << time2 << '|' << time3 <<'\n';
        }
    }

    temp.close();
    movie.close();
    movie.open("Movies.txt",ios::out);
    temp.open("temp.txt",ios::in);

    int y = 0;
    do
    {
        temp.getline(name,25,'|');
        temp.getline(time1,25,'|');
        temp.getline(time2,25,'|');
        temp.getline(time3,25);
        movie << name << '|' << time1 << '|' << time2 << '|' << time3 << '\n';
        y = y + 1;
    }while (y <= lines);

    temp.close();
    movie.close();
    remove("temp.txt");
    cout << "\n done !!! \n";

}

update_movie()
{
    fstream movie, temp;
    int lines, movieCount{}, readStatus{};
    char selection_movie1, name [25], time1[25], time2[25], time3[25];
    movie.open("Movies.txt",ios::in);
    temp.open("temp.txt",ios::out);

    MOVIE movies;
    if (readStatus = ReadFile(movies, movieCount))
        return readStatus;
    showmovielist(movies, movieCount);

    cin.ignore();
    cout << endl;
    cout << "Enter the serial number of the movie that you want to update [1,2,3...]: ";
    cin >> selection_movie1;

    char count = '0';
    string line;

    ifstream file("Movies.txt");
    while (!file.eof())
    {
        getline(file, line);
        count++;
    }

    lines = count - 50 ;

    while((selection_movie1 <= '0') || (selection_movie1 > count))
    {
        cout << endl;
        cout << "Sorry! You have entered a wrong selection. Please try again." << endl << endl;
        cout << "Please select a movie: ";
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cin >> selection_movie1;
    }

    selection_movie = (selection_movie1 - 48);

    cout << endl;

    int i = 0;
    while(i++ , i <= count)
    {
        movie.getline(name,25,'|');
        movie.getline(time1,25,'|');
        movie.getline(time2,25,'|');
        movie.getline(time3,25);

        if (i == selection_movie)
        {
            int time[3] = {}, x = 0;
            cout << " Enter the time for First show  (HHMM): ";
            cin >> time[0];
            time_checking(time, x);
            i = 1;

            cout << " \nEnter the time for Second show (HHMM): ";
            cin >> time[1];
            time_checking(time, x);
            i = 2;

            cout << "\n Enter the time for Third show  (HHMM): ";
            cin >> time[2];
            time_checking(time, x);
            temp << name << '|' << time[0] << '|' << time[1] << '|' << time[2] << '\n';
        }

        else
        {
            temp << name << '|' << time1 << '|' << time2 << '|' << time3 << '\n';
        }

    }
    temp.close();
    movie.close();

    movie.open("Movies.txt",ios::out);
    temp.open("temp.txt",ios::in);

    int y = 0;
    do
    {
        temp.getline(name,25,'|');
        temp.getline(time1,25,'|');
        temp.getline(time2,25,'|');
        temp.getline(time3,25);
        movie << name << '|' << time1 << '|' << time2 << '|' << time3 << '\n';
        y = y + 1;
    }while (y <= lines);

    temp.close();
    movie.close();

    cout << "\n You have done editing the showtime manager!!! \n";
    remove("temp.txt");
}

void management()
{
    {
        system("CLS");
        title();
        string userName;
        string userPassword;
        int loginAttempt = 0;

        cout << endl << endl;
        while (loginAttempt < 5)
        {
            cout << "Please enter your user name: ";
            cin >> userName;
            cout << "Please enter your user password: ";
            cin >> userPassword;

            if (userName == "Mathavan" && userPassword == "MTRS")
            {
                cout << "Welcome Mathavan!" << endl;
                break;
            }
            else if (userName == "Sofea" && userPassword == "MTRS")
            {
                cout << "Welcome Sofea!" << endl;
                break;
            }
            else if (userName == "Nicole" && userPassword == "MTRS")
            {
                cout << "Welcome Nicole!" << endl;
                break;
            }
            else if (userName == "Weishan" && userPassword == "MTRS")
            {
                cout << "Welcome Weishan!" << endl;
                break;
            }
            else if (userName == "ChowWei" && userPassword == "MTRS")
            {
                cout << "Welcome Chow ChowWei!" << endl;
                break;
            }
            else
            {
                cout << "Invalid login attempt. Please try again.\n" << '\n';
                loginAttempt++;
            }
        }
        if (loginAttempt == 5)
        {
            cout << "Too many login attempts! The program will now terminate.";
        }

        bool flag=true;
        while (flag)
        {
            system("CLS");
            title();
            cout << endl << endl << endl;
            cout << "                                          (1) Enter a new movie " << endl << endl << endl;
            cout << "                                          (2) Update the showtime for a movie" << endl << endl << endl;
            cout << "                                          (3) Delete a movie " << endl << endl << endl;

            char c;
            cout << "Enter your selection manager: ";
            cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            cin >> c;

            switch (c)
            {
                case '1' :
                    add_movie();
                    break;
                case '2':
                    update_movie();
                    break;
                case '3':
                    delete_movie();
                    break;

                default :
                    cout << endl;
                    cout << "Please input a correct selection\n";
                    cout << "If you continue to use program press ' y ',if no please press any input to restart\n ";
            }

                cout << " if you continue to use program press ' y ' \n ";
                char f;
                cin >> f;
                if(f!='y')
                {
                    flag=false;
                }
        }

    }
}

payment(float pay)
{
    char resp;
    int ticket_num, card_num, ccv;
    string card_type;
    cout << " Select the payment method: " << endl;
    cout << "                 (A) CASH  " << endl;
    cout << "                 (B) DEBIT CARD " << endl;
    cout << "                 (C) CREDIT CARD " << endl << endl;
    cout << " Your option [A, B, C] :  ";
    cin >> resp;
    while((resp != 'A') && (resp != 'a') && (resp != 'B') && (resp != 'b') && (resp != 'C') && (resp != 'c') )
    {
        cout << " Please select a correct option [ a, b, c] : ";
        cin >> resp;
    }

    system("ClS");
    title();
    if (resp == 'A' || resp == 'a'){
        cout << " You have selected to pay on cash" << endl;
        cout << " The amount you need to pay is : RM " << pay << endl << endl;
        ticket_num = rand() % 9999999999 + 10000000000;
        cout << "                                              --------------------------------------                               "    << endl;
        cout << "                                             |               " << ticket_num << "             |"                         << endl;
        cout << "                                              --------------------------------------" << endl << endl;
        cout << " This is your ticket number !!! " << endl;
        cout << " Please show this ticket number to the employee " << endl;
        cout << " Thank you !!!" << endl;
    }

    if (resp == 'B' || resp == 'b'){
        card_type = "debit card";
    }

    if (resp == 'C' || resp == 'c'){
       card_type = "credit card";
    }

     cout << "You have selected " << card_type << " to pay !!" << endl << endl;
     cout << "The amount you need to pay is : RM " << pay << endl << endl;
     cout << "Enter your " << card_type << " number: " ;
     cin >> card_num;
     cout << "\n Enter your CCV : " ;
     cin >> ccv;

}

member_login(char name[25], char icno[25],char email [40], char phone_number[25],char  acc_num[25], char password[25], char month[25], char year[25], char validity[25])
{
     string pass_input, line, accno_input1, acc_num1, password1, accno_input;
     int login_attempt = 0, count = 0 , account;
     fstream member;
     member.open("Membership.txt",ios::in);
     char dummy, resp, current_year[25];

     acc_num:
     cout << "                                          Enter your account number : ";
     cin >> accno_input;

     ifstream file("Membership.txt");
     while (!file.eof())
     {
        getline(file, line);
        count++;
     }

    int i = 0;
    while(i <= count)
    {
        member.getline(name,25,'|');
        member.getline(icno,25,'|');
        member.getline(email,40,'|');
        member.getline(phone_number,25, '|');
        member.getline(acc_num,25, '|');
        member.getline(password,25,'|' );
        member.getline(month,25,'|' );
        member.getline(validity,25);

        acc_num1 = acc_num;

        if (acc_num1 == accno_input)
        {
            account = 1;
            break;
        }

        i = i + 1;
    }
    member.close();

    if ( account != 1 )
    {
        cout << endl;
        cout << "                                  Your account not found !!!"<< endl;
        cout << "                                  Please try again !!" << endl << endl;
        cout << "                                  PLEASE ENTER ANY KEY TO CONTINUE >>> ";
        cin >> dummy;
        goto acc_num;
    }
            password1 = password;
            cout << endl;
            cout << "                                          Enter your account password : ";
            cin >> pass_input;

            for (login_attempt = 1 ; login_attempt <= 2 ; login_attempt ++)
            {
                if (pass_input == password1)
                {
                    cout << "Login Successful !!!";
                    break;
                }

                cout << endl;
                cout << "Login Failed. Attempt " << login_attempt  << " of 3" << endl;
                cout << "Please re-enter Password: " ;
                cin >> pass_input;

                if (pass_input == password1)
                {
                    cout << "Login Successful !!!";
                    break;
                }

            }

            if ( login_attempt == 3)
            {
                cout << endl;
                cout << "Login Failed. Attempt 3 of 3";

                return i;
            }
}

string email_input(int email_length)
{
    string email;
    int valid_email = 0;
    char temp;
    cout << "                  Enter your email address: ";
    cin >> email;
    cout << endl;

    email_length = email.length();

    for (int i=0; i<email.length(); ++i)
    {
        temp = email.at(i);
        if (temp == '@' )
        {
            valid_email = 1;
        }
    }

    while (valid_email != 1)
    {
        cout << "               Enter a valid email address: ";
        cin.ignore();
        cin >> email;
        cout << endl;

        for (int i=0; i<email.length(); ++i)
        {
          temp = email.at(i);
          if (temp == '@' )
          {
             valid_email = 1;
          }
        }
    }
    return email;
}

string phone_input(int phone_length)
{
    string phone_number;
    cout << "                  Enter your phone number : ";
    cin >> phone_number;

    phone_length = phone_number.length();

    while (phone_length != 10)
    {
       cout << endl;
       cout << "                Enter a valid phone number: ";
       cin >> phone_number;
       phone_length = phone_number.length();
    }
    return phone_number;
}

void member_info()
{
    fstream member;
    member.open("Membership.txt",ios::in);
    int login_attempt = 0, count = 0 , account, length, email_length, phone_length, name_length;
    string pass_input, line, accno_input1, acc_num1, password1, accno_input, icno1;
    char resp,dummy, current_year[25], name[25], icno[25], email [40], phone_number[25], acc_num[25], password[25], month[25], year[25], validity[25] ;

    member_info:
    system("CLS");
    title();
    cout << "\t\t\tMEMBER INFORMATION\t\t\t\n"
         << "\t\t\t--------------------\t\t\t\n\n";
    int i = member_login(name, icno, email, phone_number, acc_num, password, month, year, validity);
    system("CLS");
    title();
    icno1 = icno;
    int gender = (icno1.at(11));
    gender = gender % 2;

    cout << " \n---------------------------------------------------------------------------------------------------------------------------------- "
         << "\n|\t\t\t\t\t\t|\n" ;

    if (gender == 1){
        cout << "|\tHello Mr ";
    }else{
        cout << "|\tHello Ms ";
    }

    cout << name << " ," << setw(50)
         << "\n\t\t\t\n|"
         << "|\t\t\t\t\t\t\t\t|\n" ;

    i = 5;
    // birthday

    int y = length ;
    cout << setw(50 - length)
         << "\t\t|\n"
         << "|\t\t\t\t|\n"
         << "|\t\tYour Email Address : " << email;

    y = email_length;
    cout << setw(50 - name_length)
         << "\t\t|\n"
         << "|\t\t\t\t\t|\n"
         << "|\t\tYour Phone Number : " << phone_number;
    y = phone_length ;
    cout << setw(50 - phone_length)
         << "\t\t\t|\n"
         << "|\t\t\t\t\t|\n";

    cout << "|\t\tYour Account Validity : " << month << " - " << validity
         << setw(25) << "|"
         << "|\t\t\t\t\t|\n"
         << " ---------------------------------------------------------------------------------------------------------------------------------- \n\n";
}

void member_reg()
{
    fstream member;
    member.open("Membership.txt",ios::app);
    string icno, name, email, phone_number;
    int length, name_length, valid_email = 0, email_length, phone_length, acc_num;
    char temp, resp;

    system("CLS");
    title();

    cout << "\t\t\t\WELCOME TO THIS CINEMA !!\t\t\t\n\n";
    cout << "\t\t\tWe are glad on your interest to be a part of our family\t\t\n\n\n";
    cout << "\t\tEnter your name: ";
    cin >> name;
    cout << endl;
    cout << "\t\tEnter your Identification Number(IC) without dash (-) : ";
    cin >> icno;

    name_length = name.length();
    length = icno.length();

    while (length != 12){
        cout << endl;
        cout << "\tEnter a valid IC Number: ";
        cin >> icno;
        length = icno.length();
    }

    int gender = (icno.at(11));
    gender = gender % 2;
    cout << endl ;
    email = email_input(email_length);
    phone_number = phone_input(phone_length);

    details:
    system("CLS");
    title();
    cout << "\n----------------------------------------------------------------------------------------------------------------------------------\n"
         << "|\t\t\t\t\t\t|\n";

    member_info();
    cout << " ----------------------------------------------------------------------------------------------------------------------------------\n\n"
         << "\t\t\tWOULD YOU LIKE TO CONFIRM YOUR DETAILS [Y/N] : ";
    cin >> resp;
    resp = tolower(resp);

    while ((resp != 'y') && (resp != 'n') ){
            cout << "\nEnter a valid response: ";
            cin >> resp;
        }

    if (resp == 'n'){
        system("CLS");
        title();
        cout << "\n\t\tWHICH DATA YOU WOULD LIKE TO CHANGE :\t\t\n\n"
             << "\t\t\t(A) NAME\n\n"
             << "\t\t\t(B) IDENTIFICATION NUMBER\n\n"
             << "\t\t\t(C) EMAIL ADDRESS\t\n\n"
             << "\t\t\t(D) PHONE NUMBER\t\n\n"
             << "\t\t\tEnter your response:\t" ;
        cin >> resp;
        resp = tolower(resp);

        while ((resp != 'a') &&  (resp != 'b') && (resp != 'c') && (resp != 'd') ){
              cout << "\nEnter a valid response: ";
              cin >> resp;
        }

        cout << endl << endl;
        if (resp == 'a'){
                cout << "Enter your name: ";
                cin >> name;
                goto details;
            }

        else if (resp == 'b'){
            cout << "Enter your Identification Number: ";
            cin >> icno;
            length = icno.length();

            while (length != 12){
            cout << "\n\t\tEnter a valid IC Number: ";
            cin >> icno;
            length = icno.length();
            }

            int gender = (icno.at(11));
            gender = gender % 2;
            goto details;
        }

        else if (resp == 'c'){
            email = email_input(email_length);
            goto details;
        }

        else{
            phone_number = phone_input(phone_length);
            goto details;
        }
    }

    else{
        time_t t = time(NULL);
        tm* timePtr = localtime(&t);
        string password, password_1;
        system("CLS");
        title();
        acc_num = rand() % 9999999999 + 10000000000;
        cout << "\n\t\t\tYour Account Number is : \t\t\n"
             << "\t\t--------------------------------------\t\t"
             << "\t\t\t|\t" << acc_num << "\t\t|\n"
             << "\t\t\t--------------------------------------\n\n"
             << "  You are required to set a password for your account: \n\n"
             << "  ENTER YOUR PASSWORD : ";
        cin >> password;
        cout << "\n  REENTER YOUR PASSWORD :";
        cin >> password_1;

        while (password_1 != password){
            cout << "\nYour password does not match !!"
                 << "\nPlease reenter your password: ";
            cin >> password_1;
        }

        cout << "\t\t\tYou are done with your account registration !!\n"
             << "\t\t\tNO FEES FOR NEW MEMBERS \n"
             << "\t\t\tOne point will be given for each ringgit in purchase\n"
             << "\t\t\tThere are alot of exciting rewards that you can claim using the points\n";
        member << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num  <<  '|' << password << '|' << timePtr->tm_mon + 1  << '|' << timePtr->tm_year + 1900 + 1 << '\n' << endl;
        member.close();
    }
}

void member_renew()
{
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);
    fstream member;
    fstream temp;
    member.open("Membership.txt",ios::in);
    temp.open("temp.txt",ios::out);
    int login_attempt = 0, count = 0 , account, extend, pay_amount, acc_renew;
    string pass_input, line, accno_input1, acc_num1, password1, accno_input;
    char dummy, resp, current_year[25], name[25], icno[25], email [40], phone_number[25], acc_num[25], password[25], month[25], year[25], validity[25] ;

    renew_membership:
    string data = "renew membership";
    system("CLS");
    title();
    cout << "\t\tRENEW MEMBERSHIP\t\t\n"
         << " \t\t------------------\t\t\n\n";
    int i = member_login(name, icno, email, phone_number, acc_num, password, month, year, validity);
    system("CLS");
    title();

    temp << timePtr->tm_year + 1900;
    temp.close();
    temp.open("temp.txt",ios::in);
    temp.getline(current_year,25);
    temp.close();
    remove("temp.txt");

    renew_membership1:
    cout << " Hello " << name << " ,\n\n"
         << " Your account is valid until " << month << " - " << validity << endl << endl;

    if ((validity <= current_year) && (((month[0] - 48) < (timePtr->tm_mon + 1)))){
        cout << " YOUR ACCOUNT HAS EXPIRED !!!\n\n" ;
    }

    cout << " Select an option to extend your membership :- \n\n"
         << "\t\t---------------\t\t----------------\t\t---------------\n"
         << "\t\t/ (a) 1 years  /\t/  (b) 3 years  /\t/ (c) 5 years  /\n"
         << "\t\t---------------\t\t----------------\t\t----------------\n\n"
         << " Your selection [ a, b, c] = ";
    cin >> resp;
    resp = tolower(resp);

    while((resp != 'a') && (resp != 'b') && (resp != 'c')){
        cout << " Please select a correct option [ a, b, c] : ";
        cin >> resp;
    }

    if (resp == 'a'){
        extend = 1;
    }else if (resp == 'b'){
        extend = 3;
    }
    else{
        extend = 5;
    }

    system("CLS");
    title();
    cout << " You have selected " << extend << " years to extend your membership !!!\n" << endl;
    int y = 0;
    member.open("Membership.txt",ios::in);
    temp.open("temp.txt",ios::out);

    while(y++, y <= count)
        {
            member.getline(name,25,'|');
            member.getline(icno,25,'|');
            member.getline(email,40,'|');
            member.getline(phone_number,25, '|');
            member.getline(acc_num,25, '|');
            member.getline(password,25,'|' );
            member.getline(month,25,'|' );
            member.getline(validity,25);

            if(y == (i + 1)){
                if (((month[0] - 48) >= (timePtr->tm_mon + 1)) && (validity <= current_year)){
                     int validity1 = validity[3] - 48 + extend ;
                     temp << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num <<  '|' << password << '|' << month << '|' << validity[0] <<  validity[1] <<  validity[2] <<  validity1 << '\n';
                }else if((validity <= current_year) && (((month[0] - 48) < (timePtr->tm_mon + 1)))){
                     int current_year1 = current_year[3] - 48 + extend ;
                     temp << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num <<  '|' << password << '|' << timePtr->tm_mon + 1 << '|' << current_year[0] <<  current_year[1] <<  current_year[2] <<  current_year1 << '\n';
                }else{
                     temp << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num <<  '|' << password << '|' << month << '|' << validity << '\n';
                }
            }
        }

    member.close();
    temp.close();
    cout << "\n Do you want to change the years to be extended [Y/N]: ";
    cin >> resp;
    resp = tolower(resp);

    if (resp == 'y'){
        goto renew_membership1;
    }

    if (extend == 1){
        pay_amount = 10;
    }else if(extend == 3){
        pay_amount = 20;
    }else if(extend == 5){
        pay_amount = 30;
    }

    cout << endl;
    payment(pay_amount);
    temp.open("temp.txt",ios::in);
    member.open("Membership.txt",ios::out);
    y = 0;

    while(y++, y <= count)
        {
            temp.getline(name,25,'|');
            temp.getline(icno,25,'|');
            temp.getline(email,40,'|');
            temp.getline(phone_number,25, '|');
            temp.getline(acc_num,25, '|');
            temp.getline(password,25,'|' );
            temp.getline(month,25,'|' );
            temp.getline(validity,25);
            member << name << '|' << icno << '|' << email << '|' << phone_number <<  '|' << acc_num <<  '|' << password << '|' << month << '|' << validity << '\n';
        }

    remove ("temp.txt");
    cout << " You are done our beloved customer !!!";
}

void membership()
{
    char resp;
    system("CLS");
    title();
    cout << "\n\t\t========================\t==========================\t==========================\t\t\n"
         << "\t\t* (A) NEW MEMBER *\t*\t(B) RENEW MEMBERSHIP  *\t\t* (C) MEMBER INFORMATION *\t\n"
         << "\t\t========================\t==========================\t==========================\n\n"
         << "\t\t\t\t\t\t\t Input :" ;
    cin >> resp;
    resp = tolower(resp);

    while ((resp != 'a') && (resp != 'b') && (resp != 'c'))
    {
        cout << "\nEnter a valid response: ";
        cin >> resp;
    }

    if (resp == 'a'){
        system("CLS");
        member_reg();
    }else if (resp == 'b'){
        system("CLS");
        member_renew();
    }else{
        member_info();
    }
}

class Menu {
    public:
        string name;
        double price {};
        size_t qty {};
};

enum {FOOD = 0, DRINK, MAXTYPE = DRINK};

using Men = vector<Menu>;
using Menus = Men[MAXTYPE + 1];

int getInt(const string& prm)
{
	int i {};

	while ((cout << prm) && (!(cin >> i) || cin.peek() != '\n'))
    {
		cout << "Not an integer\n";
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return i;
}

void read(istream& is, Men& vm)
{
	for (Menu m; getline(is >> ws, m.name, '|') >> m.price; vm.push_back(m));
}

void display(const Menus& m)
{
	cout << setw(134) << setfill('-') << '\n';
	cout << "|                                                            SNACKS AND DRINKS                                                      | \n";
	cout << setw(134) << setfill('-') << '\n';
	cout << "|                      SNACKS AVALABLE                   |   PRICE   |                    DRINKS AVAILABLE              |   PRICE   |\n";
	cout << setw(134) << setfill('-') << '\n';
	cout << "|                                                        |           |                                                  |           |\n";

	auto& Food {m[FOOD]};
	auto& Drink {m[DRINK]};

	cout << std::setfill(' ') << std::left;

	for (size_t e = 0, lst = std::max(Food.size(), Drink.size()); e < lst; ++e) {
		if (e < Food.size())
			cout << "|(" << setw(2) << std::right << e + 1 << std::left << ".) " << setw(50) << Food[e].name << '|' << setw(11) << setprecision(2) << std::fixed << Food[e].price;
		else
			cout << '|' << setw(56) << ' ' << '|' << setw(11) << ' ';

		if (e < Drink.size())
			cout << "|(" << setw(2) << std::right << e + 1 << std::left << ".) " << setw(44) << Drink[e].name << '|' << setw(11) << setprecision(2) << std::fixed << Drink[e].price << "|\n";
		else
			cout << '|' << setw(50) << ' ' << '|' << setw(11) << ' ' << "|\n";
	}
}

void add(const Menus& m, Men& order)
{
	int types {};

	do {
		do {
			types = getInt("[Food = 1, Drink = 2, Receipt = 0] : ");
		} while ((types < 0 || types > 2) && (cout << "Invalid option\n"));

		if (types) {
			int opt {};

			do {
				opt = getInt("Enter menu number: ");
			} while ((opt < 1 || opt > m[types - 1].size()) && (cout << "Invalid menu number\n"));

			const int qty {getInt("Enter quantity: ")};

			order.push_back(m[types - 1][opt - 1]);
			order.back().qty = qty;
		}
	} while (types);
}

float receipt(const Men& order)
{
	double total {};

	cout << "\nReceipt\n\n";
	cout << setw(25) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << "Total\n";

	for (const auto& [nam, prce, qty] : order) {
		cout << setw(25) << nam << setw(10) << std::fixed << setprecision(2) << prce << setw(10) << qty << setw(10) << prce * qty << '\n';
		total += prce * qty;
	}

	cout << "\nTotal is " << total << '\n';
	return total;
}

void food_drinks()
{
    float pay;
    system("CLS");
    title();
	ifstream foodfs("food.txt");
	ifstream drinkfs("drink.txt");
	if (!foodfs || !drinkfs)
    {
		cout << "Cannot open input files\n";
		return;
	}

	Menus menus {};
	Men order;

	read(foodfs, menus[FOOD]);
	read(drinkfs, menus[DRINK]);
	display(menus);
	add(menus, order);
	pay = receipt(order);
	payment(pay);
}

void ticket_cancel(){
//    string seat_cancel;
//    system("CLS");
//    title();
//    cout << "\t\t\t\t\t\tTICKET CANCELLATION\n\n";
//    cout << "Enter the seat no to be cancelled : ";
//    cin >> seat_cancel;
    cout << "UNDER DEVELOPMENT" << endl;

}


int main()
{
    time_t now = time(0);
    char* dt = ctime(&now);
    char selection_role;
    system("CLS");
    title();
    cout << "                  The local date and time is: " << dt << endl;
    cout <<
    "                  ========================        ==========================        ======================\n"
    "                  * (A)  MOVIE BOOKING   *        * (B) TICKET CANCELATION *        * (C) SNACKS & DRINKS *\n"
    "                  ========================        ==========================        ======================\n\n"
    "                  ========================        ==========================        ======================\n"
    "                  * (D)    MEMBERSHIP    *        * (E)     EMPLOYEES      *        * (F)   MANAGEMENT   *\n"
    "                  *=======================        ==========================        ======================\n\n"
    "                  ========================\n"
    "                  * (G)  Quit            *\n"
    "                  *=======================\n\n";

    while (true)
    {
        cout << "                                                       SELECT AN OPTION: ";
        cin >> selection_role;
        cin.ignore(10000, '\n');
        selection_role = tolower(selection_role);
        if (selection_role >= 'a' && selection_role <= 'g') break;
        cout << "                                         You have entered a wrong selection. Try again.\n\n";
    }

    if (selection_role == 'a'){
       movie_booking();
    }else if (selection_role == 'b'){ //ADDED
        ticket_cancel();
    }else if (selection_role == 'e'){
        management();
    }else if (selection_role == 'd'){
        membership();
    }else if (selection_role == 'c'){
        food_drinks();
    }
}

void movie_booking()
{
    string customer,phone_number1, email1;
    fstream movie;
    movie.open("Movies.txt",ios::in);
    int seat_price, lines, valid_email, phone_length, email_length, select_movie, selection_show;
    char seat_row,seat_column,response,r,r2,pay_res,reuse_response,seat_type, name[25], icno[25], email [40], phone_number[25], acc_num[25], password[25], month[25], year[25], validity[25], temp;
    float remaining = 0,cash = 0;

    movies:
    system("CLS");
    title();
    cout <<"\n\t\t\t*************************\n"
         <<"\t\t\t*    (A) MEMBER LOGIN   * \n"
         <<"\t\t\t************************* \n\n\n"
         <<"\t\t\t************************* \n"
         <<"\t\t\t*    (B) GUEST LOGIN    * \n"
         <<"\t\t\t************************* \n\n\n";

    while (true)
    {
        cout << "\t\t\tSELECT AN OPTION: ";
        cin >> response;
        cin.ignore(10000, '\n');
        response = tolower(response);
        if (response >= 'a' && response <= 'b')
        break;
        cout << "\t\t\tYou have entered a wrong selection. Try again.\n\n";
    }

    if (response =='a'){
        system("CLS");
        title();
        cout << "\t\t\tMEMBER LOGIN\t\t\t\n"
             << "\t\t\t------------------\t\t\t\n\n";
        int i = member_login(name, icno, email, phone_number, acc_num, password, month, year, validity);
    }

    if (response =='b'){
        system("CLS");
        title();
        cout << " You have selected guest mode !!\n\n"
             << "                  Enter your name : ";
        cin >> name;
        cout << endl;
        email1 = email_input(email_length);
        for (int j = 0; j < sizeof(email); j++){
              email[j] = email1[j];
        }
        phone_number1 = phone_input(phone_length);

        for (int j = 0; j < sizeof(phone_number); j++){
              phone_number[j] = phone_number1[j];
            }
    }

    int movieCount{}, readStatus{};
    MOVIE movies;
   // if (readStatus = ReadFile(movies, movieCount))           // check the error
    //{
      //  return readStatus;
    //}

    showmovielist(movies, movieCount);
    cout << endl << endl;
    int p = sizeof(movie_name)/sizeof(movie_name[0]);

    cout << " Please select a movie [1,2,3....]: ";
    cin >> select_movie;
    cout << endl;

    while(!cin >> select_movie){
            cout << " TRY AGAIN [1,2,3....]: ";
            cin.clear();
            cin.ignore(25,'\n');
            cin >> select_movie;
        }

    while ((select_movie > counter - 1) || (select_movie < 1 )){
          cout << " TRY AGAIN [1,2,3....]: ";
          cin >> select_movie;
        }

    cout << "============== You have selected " << movie_name[select_movie] << ".=====================\n"
         << "\nWhich show you want to select for [SHOW(1) / SHOW(2) / SHOW(3)]: ";
    cin >> selection_show;

    while(!cin >> selection_show){
        cout << " TRY AGAIN [1,2,3....]: ";
        cin.clear();
        cin.ignore(25,'\n');
        cin >> selection_show;
    }

    while((selection_show > 3) || (selection_show < 1 )){
        cout << " TRY AGAIN [1,2,3....]: ";
        cin >> selection_show;
    }

    if (selection_show == 1){
           cout << "============== You have selected " << showtime1[select_movie] << ".=====================" << endl;
    }else if (selection_show == 2){
           cout << "============== You have selected " << showtime2[select_movie] << ".=====================" << endl;
    }else{
           cout << "============== You have selected " << showtime3[select_movie] << ".=====================" << endl;
    }

    cout << "\nWould you wish to [B]ack, [P]roceed or [R]eselect? :";
    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    cin >> r;
    r = tolower(r);

    while ( r != 'b' && r != 'p' && r != 'r')
        {
            cout << "\nSorry! You have entered a wrong selection. Please try again.\n\n";
            cout << "Would you wish to [B]ack, [P]roceed or [R]eselect? :";
            cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            cin >> r;
        }

    if (r != 'b'){
        if (r != 'p'){
              int i = 0;
              select_movie = 0;
              selection_show = i;
              system("CLS");
              goto movies;
        }else{
            system("CLS");
            goto seats;
        }
    }
    else{
        int i = 0;
        selection_show = i;
        system("CLS");
        goto movies;
    }
    cout << endl;

    seats:
    cout << "____________________________________________________________________________________\n"
         << "\t\t\tSCREEN\t\t\t\n"
         << "____________________________________________________________________________________\n\n\n"
         << "[A,1]          [A,2]          [A,3]          [A,4]          [A,5]          [A,6]\n\n"
         << "[B,1]          [B,2]          [B,3]          [B,4]          [B,5]          [B,6]\n\n"
         << "[C,1]          [C,2]          [C,3]          [C,4]          [C,5]          [C,6]\n\n"
         << "[D,1]          [D,2]          [D,3]          [D,4]          [D,5]          [D,6]\n\n"
         << "[E,1]          [E,2]          [E,3]          [E,4]          [E,5]          [E,6]\n\n\n\n"
         << "Enter the row of seat you would like to book for [ROW : A,B,C...]: ";
    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    cin >> seat_row ;
    seat_row = tolower(seat_row);

    while(seat_row != 'a' && seat_row != 'b' && seat_row != 'c' && seat_row != 'd' && seat_row != 'e')
        {
            cout << "Sorry! You have entered a wrong selection. Please try again." << endl << endl;
            cout << "Enter the row of seat you would like to book for [ROW : A,B,C...]: ";
            cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
            cin >> seat_row ;
        }

    cout << "\nEnter the column of seat you would like to book for [COLUMN : 1,2,3...]:  ";
    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    cin >> seat_column;

    while(seat_column < '1' || seat_column > '6')
    {
        cout << "Sorry! You have entered a wrong selection. Please try again.\n\n" ;
        cout << "Enter the column of seat you would like to book for [COLUMN : 1,2,3...]:  ";
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cin >> seat_column;
    }

    cout << "\n\nYour selection of seat is : (" << seat_row << "," << seat_column << ")"
         << "\nThere are two types of seats available:  (A) DELUXE (RM 18) \n"
         << "\t\t\t(B) NORMAL (RM 13)\n\n\n"
         << "Do you want further explanation about the type of seats available in our cinemas before selecting it? (Y/N) :" ;

    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    cin >> response;
    response = tolower(response);

    while (response != 'y' && response != 'n' )
    {
        cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
             << "Do you want further explanation about the type of seats available in our cinemas before selecting it? (Y/N) :" ;
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cin >> response;
    }

    if ( response == 'Y'){
        cout << "\n- 'DELUXE' seats provides a unique experience to the customers where they will be provided with food during the showtime."
             << "\n- 'NORMAL' seats does not include the special privileges.\n";
     }

    cout << "Please select the type of seat (A/B): ";
    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    cin >> seat_type;
    seat_type = tolower(seat_type);

    while (seat_type != 'a' && seat_type != 'b')
    {
        cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
             << "Please select the type of seat (A/B): ";
        cin >> seat_type;
    }

    if (seat_type == 'a')
        seat_price = 18.00;

    else
        seat_price = 13.00;

    cout << "Would you wish to [B]ack, [P]roceed or [R]eselect?\n" ;
    cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
    cin >> r2;

    while (r2 != 'b' && r2 != 'p' && r2 != 'r' )
    {
        cout << "Sorry! You have entered a wrong selection. Please try again.\n\n"
             << "Would you wish to [B]ack, [P]roceed or [R]eselect? :";
        cin >> r2;
    }

    if ((r2 != 'b'))
            if ((r2 != 'p')){
                char seat_row = 0,seat_column = 0,response = 0,seat_type = 0;
                int i = 0;
                selection_show = i;
                system("CLS");
                goto seats;
            }else{
                system("CLS");
                goto receipt;
            }
    else{
       char seat_row = 0,seat_column = 0,response = 0,seat_type = 0 ;
       system("CLS");
       goto movies;
    }
    cout << endl;

    receipt:
    system("CLS");
    cout << "=========================================================\n"
         << "=                         RECEIPT                       =\n"
         << "---------------------------------------------------------\n"
         << "=                       MOVIE TICKET                    =\n"
         << "=========================================================\n\n"
         << "\nTo Mr/Ms " << customer << ",\n"
         << "\nSeat selected : (" << seat_row << "," << seat_column << ")\n"
         << "\nPrice of seat : " << "RM " << seat_price << endl << endl;
    cout << "---------------------------------------------------------" << endl
         << left << setw(15) << "\nAmount to PAY : RM " << seat_price << endl
         << "\nCash          : " << "RM ";
    cin >> cash;

    while (cash < seat_price)
    {
        cout << "\nSorry! Your cash is insufficient, please pay the sufficient amount of cash! \n"
             << "\nCash : " << "RM ";
        cin >> cash;
    }

    remaining = cash - seat_price;
    cout << fixed << setprecision(2) << "\nThe change is RM " << remaining << ", Thank you!\n"
         << "\nDo you wish to use it again, [Y]es or [N]o ?\n"
         << "\nResponse : ";
    cin >> reuse_response;
    reuse_response = tolower(reuse_response);

    while (reuse_response != 'y' && reuse_response != 'n')
    {
        cout << "\nWrong selection. Enter Again !!"
             << "\nResponse : ";
        cin >> reuse_response;
    }

    if (reuse_response == 'y' ){
        char seat_row = 0,seat_column = 0,response = 0,seat_type = 0,MTRS_response = 0 ;
        system("CLS");
        main();
    }
}


/*
*Kalp Upadhayay

*ENPM702: Fall 2025
*Dr. Kootbally

* Assignment 1: Robot Simulator
* Due Date: September 23, 2025 - 11:59pm

*Description:
* This program is a robot simulator that allows the user to move the robot forward, turn left, turn right, display current robot position. 
* Robot position consists of X, Y coordinates and orientation angle. All processing and output is done through strings and text.
*/

#include <iostream>
#include <cmath>
#include <iomanip>


//Setting math constants: PI and degree to radians conversion
constexpr double PI{3.14159};
constexpr double DEGREES_TO_RADIANS{PI/180};

int main(){

    //Setting Menu options as constants
    const int MENU_MOVE_FORWARD{1};
    const int MENU_TURN_LEFT{2};
    const int MENU_TURN_RIGHT{3};
    const int MENU_GET_ROBOT_STATUS{4};
    const int MENU_EXIT{5};

    //Setting other constants needed for calculations and conditions
    const double MAX_DEGREES{360.0};
    const double ZERO_CONSTANT{0.0};

    //Declaring and initializing all robot state variables to 0.0
    double robot_x_position{0.0};       //current robot X position
    double robot_y_position{0.0};       //current robot Y position
    double robot_orientation_deg{0.0};  //current robot orientation in degrees

    //Variable Initializations - to be used and replaced later
    double change_in_x{};              //change in position X when moving forward
    double change_in_y{};              //change in position Y when moving forward
    double degree_to_turn_left{};      //amount of degrees to turn left
    double degree_to_turn_right{};     //amount of degrees to turn right
    double robot_orientation_rad{};    //current robot orientation in radians

    //Controls main menu loop
    bool display_menu{true};

    //User menu selection variable - to be set depending on user input
    int user_menu_selection{};

    while(display_menu){

        //Initializating move forward distance
        double distance_to_move_forward{};

        //Displaying Menu Options
        std::cout << "-----Robot Menu----- \n";
        std::cout << "1. Move Forward \n";
        std::cout << "2. Turn Left \n";
        std::cout << "3. Turn Right \n";
        std::cout << "4. Get Robot Status \n";
        std::cout << "5. Exit \n";
        std::cout << "--------------------\n";

        //Prompting User to enter selection
        std::cout << "Enter Your Selection:";
        std::cin >> user_menu_selection;

        //Displaying User's Selection -------------------------------------------------------------------------Optional/Debugging Purpose
        //std::cout << "Your selection is: " << user_menu_selection << "\n";  

        //Checks if previous input failed. If so it will clear it and then ignore 1000 characters, stops when newline seen
        if(std::cin.fail() || std::cin.peek() != '\n'){
            std::cin.clear();
            std::cin.ignore(1000, '\n');

            //Re-prompting user
            std::cout << "Invalid Input: Please enter numbers only \n";
            std::cout <<"\n";
            continue;
        }

        //--------Move Forward----------------------------------------------------------------------------------------------------------
        if(user_menu_selection == MENU_MOVE_FORWARD){

            //Prompting for User Input
            std::cout << "Enter distance to move forward:";
            std::cin >> distance_to_move_forward;

            //Validating to make sure it is positive double
            while(std::cin.fail() || distance_to_move_forward <= ZERO_CONSTANT || std::cin.peek() != '\n'){

                std::cin.clear(); 
                std::cin.ignore(1000, '\n');

                std::cout << "Invalid Input. Please make sure it is a positive number: ";
                std::cin >> distance_to_move_forward;

            }

            std::cout << "Your Entered Value is: " << distance_to_move_forward << "\n";

            //Converting robot orientation from degrees to radians
            robot_orientation_rad = robot_orientation_deg * DEGREES_TO_RADIANS;

            //Calculating the change in X and Y using Trig functions and newly converted orientation in radians
            change_in_x = distance_to_move_forward * (cos(robot_orientation_rad));
            change_in_y = distance_to_move_forward * (sin(robot_orientation_rad));

            //Updating robot positions
            robot_x_position += change_in_x;
            robot_y_position +=change_in_y;

            //std::cout << "New X Position: " << robot_x_position << "  New Y Position: " << robot_y_position << "\n";
            std::cout << "Robot moved " << distance_to_move_forward << " meters. New Position: (" << std::fixed << std::setprecision(2) << robot_x_position 
                        << ", " << std::fixed << std::setprecision(2) << robot_y_position << ") \n";
            std::cout << " \n";

        //-------Turn Left ------------------------------------------------------------------------------------------------------------
        }else if(user_menu_selection == MENU_TURN_LEFT){
            
            //Prompt for ange in degrees
            std::cout << "Enter an angle to turn left in degrees: ";
            std::cin >> degree_to_turn_left;

            //Validate to make sure positive double
            while(std::cin.fail() || degree_to_turn_left <= ZERO_CONSTANT || std::cin.peek() != '\n'){

                std::cin.clear(); 
                std::cin.ignore(1000, '\n');

                std::cout << "Invalid Input. Please make sure it is a positive number: ";
                std::cin >> degree_to_turn_left;

            }

            //Adding angle to Robot Orientation Degree
            //Loops acts like modulus operator 
            while(degree_to_turn_left >= MAX_DEGREES){
                degree_to_turn_left -= MAX_DEGREES;
            }
            robot_orientation_deg +=degree_to_turn_left;

            std::cout << "Robot turned left by " << std::fixed << std::setprecision(2) << degree_to_turn_left << ". New Orientation: " 
                        << std::fixed << std::setprecision(2) << robot_orientation_deg << " degrees \n";
            std::cout << " \n";

        // -----------Turn Right -------------------------------------------------------------------------------------------------------
        }else if(user_menu_selection == MENU_TURN_RIGHT){
            
            //Prompt for degrees to turn right
            std::cout << "Enter an angle to turn right in degrees: ";
            std::cin >> degree_to_turn_right;

            //Validate to make sure positive double
            while(std::cin.fail() || degree_to_turn_right <= ZERO_CONSTANT || std::cin.peek() != '\n'){

                std::cin.clear(); 
                std::cin.ignore(1000, '\n');

                std::cout << "Invalid Input. Please make sure it is a positive number: ";
                std::cin >> degree_to_turn_right;

            }

            //Loops acts like modulus operator --- takes care of angles above 360 
            while(degree_to_turn_right >= MAX_DEGREES){
                degree_to_turn_right -= MAX_DEGREES;
            }

            robot_orientation_deg -= degree_to_turn_right;

            //Ensures that current orientation is a positive angle ---- takes care of angles below 0 degrees
            while(robot_orientation_deg < ZERO_CONSTANT){
                robot_orientation_deg += MAX_DEGREES;
            }

            std::cout << "Robot turned right by " << std::fixed << std::setprecision(2) << degree_to_turn_right << ". New Orientation: " 
                        << std::fixed << std::setprecision(2) << robot_orientation_deg << " degrees \n";
            std::cout << " \n";
        
        //--------Getting Robot Status--------------------------------------------------------------------------------------------------------
        }else if(user_menu_selection == MENU_GET_ROBOT_STATUS){
            
            std::cout << "Robot Status \n";
            std::cout << "Position: (" << std::fixed << std::setprecision(2) << robot_x_position << ", " << std::fixed << std::setprecision(2)  << robot_y_position << ") \n";
            std::cout << "Orintation: " << robot_orientation_deg << " degrees \n";
            std::cout <<" \n";
        
        //--------Exiting Program-------------------------------------------------------------------------------------------------------------
        }else if(user_menu_selection == MENU_EXIT){

            display_menu = false; // //Exiting Loop
            std::cout << "Exiting Robot Simulator. Goodbye! \n";
        
        // User entered an incorrect value and will go back to loop
        }else{
            std::cout << "Input Out of Range: Please enter value between 1-5 \n";
            std::cout <<"\n";
        }
    }
    return 0;
}
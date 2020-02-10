// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>
#include <math.h>

typedef struct Student {
    int id;
    char *f_name;
    char *l_name;
    int n_assignments;
    double *grades;
} Student;

void calculateStudentAverage(void *object, double *avg);

int main(int argc, char **argv)
{
    Student *student;
    double average = 0;

    //holder variables for the strings:
    int in_id;          //inputted id number
    char *first;        //inputted first name
    char *last;         //inputted last name
    char *assignments;	//inputted assignment number
    int assign;			//numerical assignment count
    //std::string assignments;

    first = (char*)malloc((129)*sizeof(char));
    last = (char*)malloc((129)*sizeof(char));
    assignments = (char*)malloc((129)*sizeof(char));

    //Student id: 
    std::cout << "Please enter the student's id number: ";
    std::cin >> in_id;
    student->id = in_id;

    //Student First name:
    std::cout << "Please enter the student's first name: ";
    std::cin >> first;
    student->f_name = first;

    //Student Last name:
    std::cout << "Please enter the student's last name: ";
    std::cin >> last;
    student->l_name = last;

    //Number of Assignments:
    bool ask = true;	//loop flag for asking for the assignment
    bool check = true;	//loop flag for checking for letters in the input
    int index = 0;		//indexing variable for letters in the input

    //asking loop:
    while(ask)
    {
        std::cout << "Please enter how many assignments were graded: ";
        std::cin >> assignments;

        //check for letters in the input
        while(check)
        {
            if((assignments[index] >= 65 && assignments[index] <= 90) || (assignments[index] >= 96 && assignments[index] <= 122))
            {
                //ascii values of a characters (a-z) & (A-Z)
                std::cout << "Sorry, I cannot understand your answer\n";
                std::cout << "Please enter how many assignments were graded: ";
                std::cin >> assignments;
                //reset the index counter: 
                index = 0;		
            }
            else if (assignments[index+1] == '\0')
            {
            	/* end the loop if there haven't been any issues and we're at the end 
            		of the string: */ 
            	check = false;
            }
            else
            {
            	index+=1;
            }
        } 
        
        //if theres less than one assignment:
        if(atoi(assignments) < 1)
        {
            std::cout << "Sorry, I cannot understand your answer\n";
        }

        //input is all good:
        else
        {
            ask = false;
            assign = atoi(assignments);
        }
    }
    
    student->n_assignments = assign; 
    std::cout <<"\n";

    //Ask for grades: 
    student->grades = new double [assign];
    double grade;
    for(int i = 0; i < assign; i ++)
    {
        bool reask = true; 
        std::cout << "Please enter grade for assignment " << i << ": ";
        std::cin >> grade; 

        while(reask)
        {
        	//error checking for grades:
            if(grade > 1000.00 || grade <= 0)
            {
                std::cout << "Sorry, I cannot understand your answer\n";
                std::cout << "Please enter grade for assignment " << i << ": ";
                std::cin >> grade; 
            }

            //input is all good:
            else 
            {
                reask = false;
            }  
        }
        
        student->grades[i] = grade;
    }    

    //call to the average:
    calculateStudentAverage(student,&average);

    std::cout << "\nStudent: " << student->f_name << " " << student->l_name << " [" << student->id << "]" <<std::endl;
    std::cout <<"  Average grade: " << average <<std::endl;

    return 0;
}

void calculateStudentAverage(void *object, double *avg)
{
    double add = 0;
    Student *hold; 

    //used for rounding: 
    double scale = 0.1;


    //need to cast the object back to what it was: 
    hold = (Student*)(object);
    
    for(int i =0; i< hold->n_assignments; i ++)
    {
        add += hold->grades[i];
    } 

    //for rounding: 
    *avg = add / hold->n_assignments;
    *avg = floor(*avg / scale + 0.5) * scale;
}

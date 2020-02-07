// compile: g++ -std=c++11 -o pointers pointers.cpp
#include <iostream>
#include <string>

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
    double average;

    //holder variables for the strings:
    int in_id;          //inputted id number
    char *first;        //inputted first name
    char *last;         //inputted last name
    int assignments;    //inputted assignment number

    first = (char*)malloc((129)*sizeof(char));
    last = (char*)malloc((129)*sizeof(char));

    // Sequence of user input -> store in fields of `student`
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
    bool ask = true;
    while(ask)
    {
        std::cout << "Please enter how many assignments were graded: ";
        std::cin >> assignments;
       /* if(std::cin.fail())
        {
            std::cout << "Sorry, I cannot understand your answer\n";
        }    */
        if(assignments < 1)
        {
            std::cout << "Sorry, I cannot understand your answer\n";
        }
        else
        {
            ask = false;
        }
    }
    
    student->n_assignments = assignments; 
    std::cout <<"\n";

    //Ask for grades: 
    student->grades = new double [assignments];
    double grade;
    for(int i = 0; i < assignments; i ++)
    {
        bool reask = true; 
        std::cout << "Please enter grade for assignment " << i << ": ";
        std::cin >> grade; 

        while(reask)
        {
            if(grade > 100.00 || grade <= 0)
            {
                std::cout << "Sorry, I cannot understand your answer\n";
                std::cout << "Please enter grade for assignment " << i << ": ";
                std::cin >> grade; 
            }
            else 
            {
                reask = false;
            }  
        }
        
        student->grades[i] = grade;
    }    

    // Call `CalculateStudentAverage(???, &average)`
    calculateStudentAverage(student->grades,&average);
    // Output `average`

    return 0;
}

void calculateStudentAverage(void *object, double *avg)
{
    double calc; 
    
    std::cout << "size of object: " << sizeof(object) << "\n";

    // Code to calculate and store average grade

    //when the average is calculated, we are editing the average value
    //that is passed, which is the double average defined within main
    //rather than returning a value to be stored within the variable 
    //in main



    //post math = 
    // *avg = calc;
}

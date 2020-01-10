#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <time.h>
#include <functional>

using namespace std;

#define MAX_ROWS 3
#define MAX_COLS 10
#define MAX_STUDENTS 30

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define NOTHING 0
#define APPLEPIE 1
#define BEEF 2
#define CURRY 3

typedef int MEALTYPE;

class Fmart; // this line is used to identify Fmart as a type name, since class Player and class Student have pointers to Fmart.

int randInt(int min, int max);

class Player 
{
public:

    //constructor
    Player(Fmart* fp) :m_fp(fp), m_row(2), m_col(1), m_lives(3), m_mealInHand(NOTHING){}
    
    //destructor
    ~Player(){}

    //accessors
    int row() const             {return m_row;}
    int col() const             {return m_col;}
    int lives() const           {return m_lives;}
    MEALTYPE mealInHand() const { return m_mealInHand; }

    //mutators
    void pickup(MEALTYPE meal)  { m_mealInHand = meal; }
    void move(int dir);

    void deliver();
    void decLife()             { m_lives--; }

private:
    int m_row;
    int m_col;
    int m_lives;
    MEALTYPE m_mealInHand;
    Fmart* m_fp;
};

class Student{
public:
    //constructor
    Student(Fmart* fp, int row, int col): m_fp(fp), m_row(row), m_col(col), m_type(randInt(1, 3)) {};

    //destructor
    ~Student() {};

    //accessors
    int row() const { return m_row; }
    int col() const { return m_col; }
    MEALTYPE typeWanted() const {return m_type;}
    //mutators
    void moveForward(MEALTYPE playeraction);   

private:
    int m_row;
    int m_col;
    Fmart* m_fp;
    MEALTYPE m_type;
};

class Fmart{
public:
    //constructor
    Fmart();
    
    //destructor
    ~Fmart();

    //accessors
    Player* getPlayer() const { return m_player; }
    int numberOfStudents() const { return m_numStudents; }
    bool studentAt(int row, int col) const;
    // modified by madoka
    MEALTYPE mealTypeAt(int row, int col);
    // ends here

    //mutators
    bool addStudent();
    // modified by madoka, params.
    bool deleteStudent(int row, int col);
    // ends here
    void display();
    void play();
    
private:
    Player* m_player;
    Student* m_students[MAX_STUDENTS];
    int m_numStudents;
};

//---------------------------Implementions of Fmart-------------------------------------//

Fmart::Fmart()  
{
    // TODO: add a new player, initialize student list & number of students.
    // YOUR CODE HERE
    m_player = new Player(this);
    for (int i = 0; i < MAX_STUDENTS; i++)
        m_students[i] = nullptr;
    m_numStudents = 0;
}

Fmart::~Fmart()
{
    // TODO: delete students and player.
    // YOUR CODE HERE
    delete m_player;
    for (int i = 0; i < MAX_STUDENTS; i++)
        if (m_students[i] != nullptr)
            delete m_students[i];
}


bool Fmart::studentAt(int row, int col) const
{
    // TODO: check if there is a student at (row, col), if so, return true, else return false.
    // YOUR CODE HERE
    for(int i = 0; i < m_numStudents; i++)
        if(m_students[i]->row() == row && m_students[i]->col() == col) return true;
    return false;
}

/**
 * To get the type of lunch of student at (row, col) want, returns the mealtype.
 * If there are  no students at (row, col), return -1.)
 */
MEALTYPE Fmart::mealTypeAt(int row, int col)
{
    for(int i = 0; i < m_numStudents; i++)
        if(m_students[i]->row() == row && m_students[i]->col() == col) return m_students[i]->typeWanted();
    return -1;
}

bool Fmart::addStudent()
{
     // TODO: add a new student at the rightmost column
    // If (1, 10), (2, 10), (3, 10) are all filled with student, just do nothing and return false
    // If Student number is greater than MAX_STUDENTS, just do nothing and return false.
    // You will need `randInt` to get a random row 
    // YOUR CODE HERE
    if(m_numStudents >= MAX_STUDENTS) 
        return false;
    if (studentAt(1, MAX_COLS) && studentAt(2, MAX_COLS) && studentAt(3, MAX_COLS))
        return false;

    int rndrow = randInt(1,3);    
    // modified by madoka
    if (studentAt(rndrow, MAX_COLS))
    {
        for (int i = 1; i <= MAX_ROWS; i++)
        {
            if (!studentAt(i, MAX_COLS))
            {
                rndrow = i;
                break;                 
            }
        }
    }
    // solve infinite recursion, ends here

    m_students[m_numStudents] = new Student(this, rndrow, MAX_COLS);
    m_numStudents++;
    return true;
}

bool Fmart::deleteStudent(int row, int col)
{
    // TODO: remove a student at position (row, col).
    // i.e. remove it from the array `m_students`
    // If there is no student at this position, just return false.
    // Otherwise, return true.
    // YOUR CODE HERE
    for (int i = 0; i < m_numStudents; i++)
    {
        if (m_students[i] != nullptr && m_students[i]->row() == row && m_students[i]->col() == col)
        {
            delete m_students[i];
            m_numStudents--;
            for(int j = i; j < m_numStudents; j++)
                m_students[j] = m_students[j + 1];
            m_students[m_numStudents] = nullptr;
            return true;
        }
    }
    return false;
}

/** Display the game grid
 * It will display grids, players and students.
 */
void Fmart::display()
{
    char** disp = new char* [3];
    for (int i = 0; i < 3; i++)
    {
        disp[i] = new char[10];
        for (int j = 0; j < 10; j++)
            disp[i][j] ='.';
    }

    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        if(m_students[i] == nullptr) 
            continue;
        int srow = m_students[i]->row();
        int scol = m_students[i]->col();
        if(m_students[i]->typeWanted() == m_player->mealInHand())
            disp[srow-1][scol-1] = '@';
        else
            disp[srow-1][scol-1] = 'S';                
    }

    int prow = m_player->row();
    int pcol = m_player->col();

    switch(m_player->mealInHand())
    {
        case APPLEPIE:
            disp[prow-1][pcol-1] = 'A';
            break;
        case BEEF:
            disp[prow-1][pcol-1] = 'B';
            break;
        case CURRY:
            disp[prow-1][pcol-1] = 'C';
            break;
        case NOTHING:                
            disp[prow-1][pcol-1] = 'P';
            break;
        default:
            break;
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 10; j++)
            cout << disp[i][j];
        cout << endl;
    }

    for (int i = 0; i < 3; i++)
        delete[] disp[i];
    delete[] disp;
}

/*  This is the main part of the game. You will NOT need to modify this */
void Fmart::play()
{
    addStudent();
    while (m_player->lives() > 0)
    {
        display();
        cout << "make a move (a, b, c, u, d, g): " << endl;

        // modified by madoka
        char option, unuse;
        scanf("%c%c", &option, &unuse);
        // solve '\n' problem, ends here

        MEALTYPE pOption = NOTHING;
        switch(option){
            case 'a':
                m_player->pickup(APPLEPIE);
                pOption = APPLEPIE;
                break;
            case 'b':
                m_player->pickup(BEEF);
                pOption = BEEF;
                break;
            case 'c':
                m_player->pickup(CURRY);
                pOption = CURRY;
                break;
            case 'u':
                m_player->move(UP);
                break;
            case 'd':
                m_player->move(DOWN);
                break;
            case 'g':
                m_player->deliver();
                break;
            default:
                continue;
        }
        for (int i = 0; i < m_numStudents; i++)
            m_students[i]->moveForward(pOption);
            
        addStudent();
    }
}

//---------------------------Implementions of Student -------------------------------------//
void Student::moveForward(MEALTYPE playeraction)
{
    // TODO: 
    // If the meal in player's hand is the same as this student wants,
    // He will not move, just do nothing and returns.
    // Else, move this student forward for one step.
    // If he moves to the first column, player's lives will be declined by 1.
    // YOUR CODE HERE
    if(playeraction == m_type)
        return;
    else
    {
        if(m_fp->studentAt(m_row, m_col-1))
            return;
        else
        {
            if (--m_col == 1)
                m_fp->getPlayer()->decLife();  
        }
    }
}

//---------------------------Implementions of Player -------------------------------------//
void Player::deliver()
{
    // TODO:
    // Send the meal to left-most student in that row.
    // If (1) He doesn't want this meal 
    //    (2) No student at this row
    //    (3) Player has no meal in his hand.
    // just do nothing and returns.
    // If success, set player's hand to NOTHING
    if(m_mealInHand != NOTHING)
    {
        int i;
        for (i = 1; i < MAX_COLS + 1; i++)
        {
            if (m_fp->studentAt(m_row, i))
                break;
        }
        // if no student in that row
        if (i == MAX_COLS + 1) return;
        MEALTYPE wanted = m_fp->mealTypeAt(m_row, i);
        if (wanted == m_mealInHand)
        {
            m_fp->deleteStudent(m_row, i);
            m_mealInHand = NOTHING;
        }
    }
}

/* Move the player upwards of downwards. You will NOT need to to modify this */
void Player::move(int dir) 
{
    if(dir == UP)
    {
        if(m_row != 1) m_row--;            
    }
    else if(dir == DOWN)
    {
        if(m_row != 3) m_row++;
    }
}

// ------------------------------Helper functions--------------------------------------//
int randInt(int min, int max)
{
    if (max < min)
		swap(max, min);
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(19260817);
    Fmart f;
    f.play();
}
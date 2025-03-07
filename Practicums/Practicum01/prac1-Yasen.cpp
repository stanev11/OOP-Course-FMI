// prac1-Yasen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>

//3
struct ComplexNum {
    int realPart;
    int imPart;
};
ComplexNum AdditionCompl(const ComplexNum& c1, const ComplexNum& c2)
{
    return ComplexNum{ c1.realPart + c2.realPart,c1.imPart + c2.imPart };
}
void PrintComplexNum(const ComplexNum& c)
{
    std::cout << c.realPart << "+" << c.imPart << "i"<<std::endl;
}

//4
struct Point {
    int x;
    int y;
};
Point GetPoint()
{
    Point p;
    std::cin >> p.x >> p.y;
    return p;
}
void PrintPoint(const Point& p)
{
    std::cout << "(" << p.x << "," << p.y << ")" << std::endl;
}
size_t GetDistanceBetweenPoints(const Point& p1, const Point& p2)
{
    int x = p2.x - p1.x;
    int y = p2.y - p1.y;
    return sqrt(pow(x, 2) + pow(y, 2));
}
int GetDistanceToCenter(const Point& p)
{
    return GetDistanceBetweenPoints(p, { 0,0 });
}

//4.bonus
enum Quadrant {
    First = 1,
    Second,
    Third,
    Forth
};
int GetQuadrant(const Point& p)
{
    return (p.x > 0) ? (p.y > 0) ? Quadrant::First : Quadrant::Forth : (p.y > 0) ? Quadrant::Second : Quadrant::Third;
}
enum PositionRelativeToCircle
{
    Inner,
    OnContour,
    Outside
};
int PointPositionRelativeToCircle(const Point& p, const int r, const Point& center)
{
    int distance = GetDistanceBetweenPoints(p, center);
    if (distance > r) return PositionRelativeToCircle::Outside;
    else if (distance == r) return PositionRelativeToCircle::OnContour;
    return PositionRelativeToCircle::Inner;
}

//5
struct Student {
    char name[32];
    char fn[32];
    double grate;
};
struct Group {
    Student* stds;
    double GPA;
    int n;
};
void PrintGroupStds(const Group* g)
{
    for (int i = 0; i < g->n; i++)
    {
        Student current = g->stds[i];
        std::cout << "Student " << i + 1 << ": " << current.name << ", " << current.fn << ", " << current.grate << std::endl;
    }
}
Group* GetGroup()
{
    int n;
    std::cout << "Enter number of students in this group: ";
    std::cin >> n;
    Student* stds = new Student[n];
    double avg=0;
    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter student's name: ";
        std::cin >> stds[i].name;
        std::cout << "Enter student's fn: ";
        std::cin >> stds[i].fn;
        std::cout << "Enter student's grate: ";
        std::cin >> stds[i].grate;
        avg += stds[i].grate;
    }
    Group* g = new Group{ stds,avg / n,n};
    return g;
}
void PrintStudent(const Student& std)
{
    std::cout << std.name << "," << std.fn << "," << std.grate<<std::endl;
}
int CountOfScholarshipsAndPrint(const Group* g, const double minGrate)
{
    int counter = 0;
    bool* getScholarship = new bool[g->n + 1] {0};
    for (int i = 0; i < g->n; i++)
    {
        if ((*g).stds[i].grate - minGrate >= DBL_EPSILON)
        {
            getScholarship[i] = true;
            counter++;
        }
    }

    for (int i = 0; i < g->n; i++)
    {
        if (getScholarship[i])
        {
            for (int j = i+1; j < g->n; j++)
            {
                if (getScholarship[j] && g->stds[i].grate > g->stds[j].grate) {
                    Student temp = g->stds[i];
                    g->stds[i] = g->stds[j];
                    g->stds[j] = temp;
                }
            }
        }
    }
    PrintGroupStds(g);
    return counter;
}
bool IsStudentInGroup(const Group& g, const char FN[32])
{
    for (int i = 0; i < g.n; i++)
    {
        if (g.stds[i].fn == FN) return true;
    }
    return false;
}

//6
char* ReadCharArr()
{
    const int MAX_SIZE = 1024;
    char buffer[MAX_SIZE];
    std::cin.getline(buffer, MAX_SIZE, '\n');
    int len = strlen(buffer);
    char* res = new char[len + 1];
    res[len] = '\0';
    for (int i = 0; i < len; i++)
    {
        res[i] = buffer[i];
    }
    return res;
}
enum ErrorCode
{
    InvalidError,
    NullptrError,
    EmptyTextError,
    NoError
};
struct Pair {
    ErrorCode error;
    int num;
};
Pair ConvertToNum(const char* str)
{
    int number = 0;
    while (*str)
    {
        char symbol = *str;
        if ('0' <= symbol && symbol <= '9')
        {
            number *= 10;
            number += (symbol - '0');
        }
        else
        {
            return Pair{ ErrorCode::InvalidError };
        }
        str++;
    }
    return Pair{ ErrorCode::NoError,number };

}
Pair ParseCharArrToNum(const char* str)
{
    if (!str)
    {
        return Pair{ ErrorCode::NullptrError };
    }
    int len = strlen(str);
    if (len == 0)
    {
        return Pair{ ErrorCode::EmptyTextError };
    }
    return ConvertToNum(str);
}
const char* GetErrorDescrp(ErrorCode errorName)
{
    switch (errorName)
    {
    case InvalidError: return "Text mustn't contain invalid symbols!";
        break;
    case NullptrError: return "Text cannot be nullptr!";
        break;
    case EmptyTextError:return "Text cannot be empty!";
        break;
    case NoError: return "Everything is fine!";
        break;
    default:
        break;
    }
}
bool isError(ErrorCode e)
{
    if (e == ErrorCode::NoError) return false;
    return true;
}

//7
int** ReadMatrix(const int rows,const int cols)
{
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
    return matrix;
}
void PrintMatrix(int** matrix,const int rows, const int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << matrix[i][j]<<" ";
        }
        std::cout << std::endl;
    }
}
int** TransposeMatrix(int** matrix, const int rows, const int cols)
{
    int transpRows = cols;
    int transpCols = rows;
    int** transposed = new int*[cols];
    for (int i = 0; i < cols; i++)
    {
        transposed[i] = new int[rows];
    }
    int currentRow = 0;
    int currentCol = 0;
    for (int i = 0; i < transpRows; i++)
    {
        currentRow = 0;
        for (int j = 0; j < transpCols; j++)
        {
            transposed[i][j] = matrix[currentRow++][currentCol];
        }
        currentCol++;
    }
    return transposed;
}
void swapRows(int*& row1, int*& row2)
{
    int* temp = row1;
    row1 = row2;
    row2 = temp;
}
void swapRowsInMatrix(int** matrix, const int rows, const int cols)
{
    for (int i = 0; i < rows/2; i++)
    {
        swapRows(matrix[i], matrix[rows - i - 1]);
    }
}

int main()
{
   /* char* str = ReadCharArr();
    Pair res = ParseCharArrToNum(str);
    if (isError(res.error))
    {
        std::cout << GetErrorDescrp(res.error)<<std::endl;
    }
    else
    {
        std::cout << res.num;
    }
    delete[] str;*/
}

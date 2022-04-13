#include <iostream>
#include <string>
#include <vector>
using namespace std;


namespace zich{

    class Matrix{
        
        vector <vector<double>> vector_matrix;
        int row;
        int col;

        public:

            //constructors
            Matrix(vector<double> vector_matrix,int row,int col);
            Matrix(const Matrix& copy_matrix);

            //deconstructor
            ~Matrix(){}

            //getters
            int getRow() const{
                return this->row;
            }

            int getCol() const{
                return this->col;
            }

            vector<vector<double>> get_vector_matrix() const{
                return this->vector_matrix;
            }


            //comparison operators
            bool operator < (const Matrix& other) const;
            bool operator > (const Matrix& other) const;
            bool operator >= (const Matrix& other) const;
            bool operator <= (const Matrix& other) const;
            bool operator == (const Matrix& other) const;
            bool operator != (const Matrix& other) const;

            //Arithmetic operators
            Matrix operator + (const Matrix& other);
            Matrix operator += (double num);
            void operator += (const Matrix& other);
            Matrix operator - (const Matrix& other);
            Matrix operator -= (double num);
            void operator -= (const Matrix& other);
            Matrix operator * (const Matrix& other);
            Matrix operator * (const double scale);
            void operator *= (double scale);
            void operator *= (const Matrix& other);
        
            

            //unary operators
            Matrix operator + ();
            Matrix operator - ();

            //increment operators
            Matrix& operator ++ ();
            Matrix& operator -- ();
            Matrix operator ++ (int);
            Matrix operator -- (int);


            //friend operators
            friend Matrix operator * ( double scale , const Matrix& other);
            friend Matrix operator * (const Matrix& other , double scale);
            friend ostream& operator << (std::ostream& output, const Matrix& output_matrix);
            friend istream& operator >> (std::istream& input , Matrix& input_matrix);
            




    };



}
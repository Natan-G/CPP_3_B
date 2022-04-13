#include "Matrix.hpp"
#include <iostream>

using namespace std;
using namespace zich;


bool check_argument(vector<double>& vec , int row , int col){
    if(row < 1 || col < 1 || row*col != vec.size()){
        return false;
    }
    return true;    
}


bool check_arguments_2matrix(int mat1_row , int mat1_col , int mat2_row , int mat2_col){
    if((mat1_row != mat2_row) || (mat1_col != mat2_col))
        return false;

    return true;    
}

//helpful for comparison operators
double Matrix_sum(const Matrix& mat){
    double sum=0;
    for(size_t i=0 ; i<mat.getRow() ; i++){
        for(size_t j=0 ; j<mat.getCol() ; j++){
            sum += mat.get_vector_matrix()[i][j];
        }
    }
    return sum;
}


//constructor
Matrix::Matrix(vector<double> vec , int row , int col){
    
    bool flag = check_argument(vec , row , col);
    if(!flag){
        throw invalid_argument("negative rows or cols are not allow");
    }

    this->row = row;
    this->col = col;

    size_t push_index = 0;

    for(size_t i=0 ; i<row ; i++ ){
        vector<double> temp;
        for(size_t j=0 ; j<col ; j++){
            temp.push_back(vec.at(j));
            push_index++;
        }
        this->vector_matrix.push_back(temp);   
    }
}


//comparison operators
bool Matrix::operator < (const Matrix& other) const{
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    
    if(!flag){
        throw runtime_error("cannot comprasion matrix with diffirent rows or cols!");
    }

    double this_sum = Matrix_sum(*this);
    double other_sum = Matrix_sum(other);

    if(this_sum < other_sum){
        return true;
    }
    return false;    
}

bool Matrix::operator > (const Matrix& other) const{
   bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    
    if(!flag){
        throw runtime_error("cannot comprasion matrix with diffirent rows or cols!");
    }

    double this_sum = Matrix_sum(*this);
    double other_sum = Matrix_sum(other);

    if(this_sum > other_sum){
        return true;
    }
    return false;
}

bool Matrix::operator >= (const Matrix& other) const{
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    
    if(!flag){
        throw runtime_error("cannot comprasion matrix with diffirent rows or cols!");
    }

    double this_sum = Matrix_sum(*this);
    double other_sum = Matrix_sum(other);

    if(this_sum >= other_sum){
        return true;
    }
    return false;
}

bool Matrix::operator <= (const Matrix& other) const{
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    
    if(!flag){
        throw runtime_error("cannot comprasion matrix with diffirent rows or cols!");
    }

    double this_sum = Matrix_sum(*this);
    double other_sum = Matrix_sum(other);

    if(this_sum <= other_sum){
        return true;
    }
    return false;
}

bool Matrix::operator == (const Matrix& other) const{
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    if(!flag){
        throw runtime_error("cannot comprasion matrix with diffirent rows or cols!");
    }

    for(size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            if(vector_matrix[i][j] != other.get_vector_matrix()[i][j]){
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator != (const Matrix& other) const{
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    if(!flag){
        throw runtime_error("cannot comprasion matrix with diffirent rows or cols!");
    }

    for(size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            if(vector_matrix[i][j] == other.get_vector_matrix()[i][j]){
                return false;
            }
        }
    }
    return true;
}

//Arithmetic operators
Matrix Matrix::operator + (const Matrix& other){
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    if(!flag){
        throw runtime_error("cannot operate matrix with diffirent rows or cols!");
    }

    Matrix new_matrix(*this);

    for(size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            new_matrix.vector_matrix[i][j] += other.vector_matrix[i][j];
        }
    }

    return new_matrix;
}

Matrix Matrix::operator+=(double num){
     for(size_t i = 0; i < row; i++){
            for(size_t j = 0; j < col; j++){
                vector_matrix[i][j]+= num;
            }
        }
    return *this;
}
    
void Matrix::operator += (const Matrix& other){
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    if(!flag){
        throw runtime_error("cannot operate matrix with diffirent rows or cols!");
    }
    for (size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            this->vector_matrix[i][j] += other.vector_matrix[i][j];
        }
    }
}

    
Matrix Matrix::operator - (const Matrix& other){
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    if(!flag){
        throw runtime_error("cannot operate matrix with diffirent rows or cols!");
    }

    Matrix new_matrix(*this);

    for(size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            new_matrix.vector_matrix[i][j] -= other.vector_matrix[i][j];
        }
    }

    return new_matrix;
}
    
void Matrix::operator -= (const Matrix& other){
    bool flag = check_arguments_2matrix(this->row , this->col , other.getRow() , other.getCol());
    if(!flag){
        throw runtime_error("cannot operate matrix with diffirent rows or cols!");
    }
    for (size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            this->vector_matrix[i][j] -= other.vector_matrix[i][j];
        }
    }
}

Matrix Matrix::operator -= (double num){
     for(size_t i = 0; i < row; i++){
        for(size_t j = 0; j < col; j++){
            vector_matrix[i][j] -= num;
        }
    }
    return *this;
}


Matrix Matrix::operator * (const Matrix& other){
    if(this->row != other.row){
        throw runtime_error("must have the same rows!");
    }

    vector<double> vec (size_t(this->row*other.col) , 0);
    Matrix multi_matrix(vec , row , other.col);

    for(size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<other.col ; j++){
            for(size_t k=0 ; k<other.row ; k++){
                multi_matrix.vector_matrix[i][j] = vector_matrix[i][k]*other.vector_matrix[k][j];
            }
        }
    }
    
    return multi_matrix;
}

void Matrix::operator*=(const double scalar){
    for(size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            vector_matrix[i][j]*=scalar;
        }
    }
}


//unary operators
Matrix Matrix::operator + (){
    vector<double> temp;
    for (size_t i = 0; i<row; i++ ) {
        for (size_t j = 0; j < col; j++){
            temp.push_back(vector_matrix[i][j]);
        }
    }
    
    Matrix new_matrix(temp, row, col);
    return new_matrix;
}
    
Matrix Matrix::operator - (){
    vector<double> vec;
    for(size_t i=0 ; i<row ; i++){
        for(size_t j=0 ; j<col ; j++){
            vec.push_back(-1*vector_matrix[i][j]);
        }
    }
    Matrix new_matrix(vec , row , col);
    return new_matrix;
}

//increment operators
Matrix& Matrix::operator ++ (){
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            vector_matrix[i][j] += 1;
        }
    }
    return *this;
}
    
Matrix& Matrix::operator -- (){
     for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            vector_matrix[i][j] -= 1;
        }
    }
    return *this;
}

Matrix Matrix::operator ++ (int){
    Matrix temp = *this;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            vector_matrix[i][j] += 1;
        }
    }
    return temp;
}

Matrix Matrix::operator -- (int){
    Matrix temp = *this;
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            vector_matrix[i][j] -= 1;
        }
    }
    return temp;
}

//friend operators
zich::Matrix zich::operator*(double scale, const Matrix &other){
        Matrix new_matrix(other); 
        for(size_t i = 0; i < other.row; i++){
            for(size_t j = 0; j < other.col; j++){
                new_matrix.vector_matrix[i][j] *= scale;
            }
        }
    return new_matrix;
    }

zich::Matrix zich::operator*(const Matrix &other, double scale){
    Matrix mat(other); 
    for(size_t i = 0; i < other.row; i++){
        for(size_t j = 0; j < other.col; j++){
            mat.vector_matrix[i][j] *= scale;
        }
    }
    return mat;
}

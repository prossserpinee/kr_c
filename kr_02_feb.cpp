#include <iostream>

int** memory_2dim(int** array, unsigned rows, unsigned columns) { /* функция оосвобождает память под массив */
 for (unsigned i{}; i < rows; i++) {
 
  array[i] = new int[columns];
 }
 return array;
}
 
int** randfill(int** array, unsigned rows, unsigned columns) { /* функция заполняет массив рандомными числами */
 for (unsigned i{}; i < rows; i++) {
 
  for (unsigned j{}; j < columns; j++) {
 
   array[i][j] = 10 + rand() % 50;
 
  }
 }
 return array;
}

int poboch_2dim(int** array, unsigned rows, unsigned columns) { /* функция вычисляет сумму элементов */
 int sum = 0;
 for (int i = 0; i < rows ; i++) {
  for (int j = 0; j < columns; j++) {
    
   if (columns - 1 - j == i)
   {
    sum += array[i][j];
   }
  }
 }
 return sum;
}
 
int** demo_2dim(int** array, unsigned rows, unsigned columns) { /* функция выводит двумерный массив */
 for (unsigned i{}; i < rows; i++)
 {
  for (unsigned j{}; j < columns; j++)
  {
   std::cout << array[i][j] << "\t";
  }
  std::cout << std::endl;
 }
 return 0;
}
 
void dlt_2dim(int** array, unsigned rows) { /* функция освобождает память после работы с массивом */
 for (unsigned i{}; i < rows; i++)
 {
  delete[] array[i];
 }
 delete[] array;
}


struct Account /* структура аккаунта, сам аккаунт состоит из почты, пароля и имени пользователя */
{
    std::string email;
    std::string password;
    std::string username;
};

void addAccount()
{
    Account newAccount;
    std::cout << "Enter your email: " << std::endl;
    std::cin >> newAccount.email;
    std::cout << "Enter your password: " << std::endl;
    std::cin >> newAccount.password;
    std::cout << "Enter your username: " << std::endl;
    std::cin >> newAccount.username;
}

void deleteAccount()
{
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

}

void updateAccount()
{
    std::string username;
    std::cout << "Enter your username: ";
    std::cin >> username;

}

  
int main()
{
    /* Task 1*/
    srand(time_t(NULL)); /* функция, позволяющая создавать рандомные значения */
     
    unsigned rows, columns; /* строки и столбцы */
    std::cout << "Enter number of rows" << std::endl;
    std::cin >> rows;
    std::cout << "Enter number of columns" << std::endl;
    std::cin >> columns;
     
    int** array4{ new int* [rows] {} };
     
    array4 = memory_2dim(array4, rows, columns); /* освобождение памяти */
     
    array4 = randfill(array4, rows, columns); /* заполнение рандомными числами */
     
    std::cout << "Result for Task4:" << std::endl;
     
    std::cout << "Pobochnaya matrix: " << poboch_2dim(array4, rows, columns) << std::endl;
     
    demo_2dim(array4, rows, columns);
     
    dlt_2dim(array4, rows);

    
    /* Task 2*/
    int choice;
    while (true)
    {
        std::cout << "1: add account" << std:: endl;
        std::cout << "2: delete account" << std::endl;
        std::cout << "3: update account" << std::endl;
        std::cout << "4: all accounts" << std:: endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
    }
    
    switch (choice)
    {
        case 1:
            addAccount();
            break;
        case 2:
            deleteAccount();
            break;
        case 3:
            updateAccount();
            break;
        case 4:
            allAccounts();
            break;
        default:
            std::cout << "Enter a number from 1 to 4" << std::endl;
    }
    
    return 0;
}

        
   
     


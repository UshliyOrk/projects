#include <stdio.h>
#include <stdlib.h>
#include <iso646.h>
#include "sqlite3.h"
#include <time.h>
#include <string.h>
#include <math.h>

int createDB(sqlite3 *db);
int insertDB (sqlite3 *db, unsigned long long cardNumber, char *name, char *surname, int deposit);
int removeDB (sqlite3 *db, unsigned long long cardNumber);

int main(void)
{
    srand(time(NULL));
    sqlite3 *db;        //указатель на базу данных
    // createDB(db); 
    sqlite3_open("bank.db", &db);
    
    for (int i = 0; i < 10; i++)
    {
        unsigned long long card = 0;
        for (int i = 0; i < 16; i++) card += (rand()%9+1)* pow(10, i);
        insertDB(db, card, "user", "user", rand());
    }
    removeDB(db, 5827553183822154);
    return 0;
}

int createDB(sqlite3 *db)
{
    char *erm = 0;      // сообщение об ошибке
    int rc = sqlite3_open("bank.db", &db);      // состояние
    if (rc != SQLITE_OK )
    {
        sqlite3_close(db);
        return 1;
    }
    
    char *sql = "DROP TABLE IF EXISTS accounts;"
                "CREATE TABLE accounts(id INTEGER PRIMARY KEY AUTOINCREMENT, cardNumber BIGINT UNIQUE NOT NULL, name TEXT, surname TEXT, deposit INTEGER);";
    
    rc = sqlite3_exec(db, sql, 0, 0, &erm);     // база sqlКод фуекцияОбрВызоыва АргФункОбрВ сообщение об ошибке
    if (rc != SQLITE_OK )
    {
        printf("SQL error: %s\n", erm);
        sqlite3_free(erm);      // очищаем ресурсы
        sqlite3_close(db);
        return 1;
    }
    printf("base created\n");
    sqlite3_free(erm);
    sqlite3_close(db);
    return 0; 
}

int insertDB (sqlite3 *db, unsigned long long cardNumber, char *name, char *surname, int deposit)
{
    char *erm = 0;      // сообщение об ошибке
    int rc = sqlite3_open("bank.db", &db);      // состояние
    if (rc != SQLITE_OK )
    {
        sqlite3_close(db);
        return 1;
    }
    char sql[500];
    sprintf(sql, "INSERT INTO accounts (cardNumber, name, surname, deposit) VALUES (%llu, '%s', '%s', %d)", cardNumber, name, surname, deposit);
    
    rc = sqlite3_exec(db, sql, 0, 0, &erm);     // база sqlКод фуекцияОбрВызоыва АргФункОбрВ сообщение об ошибке

    if (rc != SQLITE_OK )
    {
        if (not(strcmp(erm, "UNIQUE constraint failed: accounts.cardNumber")))
        {
            printf("cardNumber alredy taken\n");
            sqlite3_free(erm);      // очищаем ресурсы
            sqlite3_close(db);
            return 1;
        }
        printf("SQL error: %s\n", erm);
        sqlite3_free(erm);      // очищаем ресурсы
        sqlite3_close(db);
        return 2;
    }
    sqlite3_close(db);
    sqlite3_free(erm);
    return 0;
}

int removeDB (sqlite3 *db, unsigned long long cardNumber)
{
    char *erm = 0;      // сообщение об ошибке
    int rc = sqlite3_open("bank.db", &db);      // состояние
    if (rc != SQLITE_OK )
    {
        sqlite3_close(db);
        return 1;
    }
    char sql[100];
    sprintf(sql, "DELETE FROM accounts WHERE cardNumber = %llu", cardNumber);

    rc = sqlite3_exec(db, sql, 0, 0, &erm);
    if (rc != SQLITE_OK)
    {
        printf("SQL error: %s\n", erm);
        sqlite3_close(db);
        sqlite3_free(erm);
        return 1;
    }
    printf("succesfully delete user: %llu\n", cardNumber);
    return 0;
}

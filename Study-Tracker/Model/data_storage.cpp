#include "data_storage.h"
#include <sqlite3/sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>

DataStorage::DataStorage(const std::string& default_dir, const std::string& default_time) {
    for (int attempts = 0; attempts < kMaxInitRetries; attempts++) {
        try {
            // Daily data to store
            // Date | Passed
            // Start Time
            // Time
            // Vod Directory
            // Directory
            SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

            // TODO: Remove this when all the code is ready to have persistent data
            db.exec("DROP TABLE IF EXISTS daily_data");
            db.exec("DROP TABLE IF EXISTS vod_directory");
            db.exec("DROP TABLE IF EXISTS start_time");

            // Begin transaction
            SQLite::Transaction transaction(db);

            db.exec("CREATE TABLE daily_data (date DATE PRIMARY KEY, passed BIT)");
            db.exec("CREATE TABLE vod_directory (directory VARCHAR(100) UNIQUE)");
            db.exec("CREATE TABLE start_time (time TIME UNIQUE)");

            // TODO: Change this to use prepared statements
            int nb = db.exec("INSERT OR IGNORE INTO vod_directory(directory) VALUES(\"" + default_dir + "\")");
            nb = db.exec("INSERT OR IGNORE INTO start_time(time) VALUES(\"" + default_time + "\");");
            //int nb = db.exec("INSERT INTO static_data VALUES (\"" + kDefaultStartTime + "\", \"" + kDefaultVodDirectory + "\")");
            //std::cout << "INSERT INTO test VALUES (NULL, \"test\")\", returned " << nb << std::endl;

            // Commit transaction
            transaction.commit();
            break;
        } catch (std::exception& e) {
            std::cout << "Attempt " << (attempts + 1) << std::endl;
            std::cout << "exception: " << e.what() << std::endl;
        }
    }
}

// TODO: Make this be a boolean on pass/fail
void DataStorage::SetStartTime(const std::string& start_time) {
    try { // TODO: Make this retry
        SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // Begin transaction
        SQLite::Transaction transaction(db);

        db.exec("CREATE TABLE IF NOT EXISTS daily_data (date DATE PRIMARY KEY, passed BIT)");
        db.exec("CREATE TABLE IF NOT EXISTS vod_directory (directory VARCHAR(100) UNIQUE)");
        db.exec("CREATE TABLE IF NOT EXISTS start_time (time TIME UNIQUE)");

        //int nb = db.exec("INSERT OR IGNORE INTO start_time(time) VALUES(" + start_time + ")");
        //int nb = db.exec("UPDATE static_data SET start_time = \"" + start_time + "\"");
        std::cout << start_time << std::endl;

        // Commit transaction
        transaction.commit();
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
}

std::string DataStorage::GetStartTime() const
{
    for (int attempts = 0; attempts < kMaxInitRetries; attempts++) {
        try {
            SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

            // Compile a SQL query, containing one parameter (index 1)
            SQLite::Statement query(db, "SELECT time FROM start_time");

            // Loop to execute the query step by step, to get rows of result
            while (query.executeStep())
            {
                std::string start_time = query.getColumn(0);

                return start_time;
            }
            break;
        }
        catch (std::exception& e) {
            std::cout << "Attempt " << (attempts + 1) << std::endl;
            std::cout << "exception: " << e.what() << std::endl;
        }
    }
}

void DataStorage::SetVodDirectory(const std::string& dir)
{
}

std::string DataStorage::GetVodDirectory() const
{
    // TODO: Prob change the number of retries for the different methods?
    for (int attempts = 0; attempts < kMaxInitRetries; attempts++) {
        try {
            SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

            // Compile a SQL query, containing one parameter (index 1)
            SQLite::Statement query(db, "SELECT directory FROM vod_directory");

            // Loop to execute the query step by step, to get rows of result
            while (query.executeStep())
            {
                std::string vod_directory = query.getColumn(0);

                return vod_directory;
            }
            break;
        }
        catch (std::exception& e) {
            std::cout << "Attempt " << (attempts + 1) << std::endl;
            std::cout << "exception: " << e.what() << std::endl;
        }
    }
}

void DataStorage::SetTodaysPerformance(const bool passed)
{
}

const int DataStorage::GetPassStreak() const
{
    return 0;
}

const int DataStorage::GetTotalTestCount() const
{
    return 0;
}

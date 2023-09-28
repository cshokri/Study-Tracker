#include "data_storage.h"
#include <sqlite3/sqlite3.h>
#include <SQLiteCpp/SQLiteCpp.h>

DataStorage::DataStorage() {
    for (int attempts = 0; attempts < kMaxInitRetries; attempts++) {
        try {
            // Daily data to store
            // Date | Passed
            // Static data
            // Start Time | Vod Directory
            SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

            db.exec("DROP TABLE IF EXISTS daily_data");
            db.exec("DROP TABLE IF EXISTS static_data");

            // Begin transaction
            SQLite::Transaction transaction(db);

            db.exec("CREATE TABLE daily_data (date DATE PRIMARY KEY, passed BIT)");
            db.exec("CREATE TABLE static_data (start_time TIME, vod_directory VARCHAR(100))");

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

void DataStorage::SetStartTime(const std::string& start_time) {
    try { // TODO: Make this retry
        SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);

        // Begin transaction
        SQLite::Transaction transaction(db);

        db.exec("CREATE TABLE IF NOT EXISTS daily_data (date DATE PRIMARY KEY, passed BIT)");
        db.exec("CREATE TABLE IF NOT EXISTS static_data (start_time TIME, vod_directory VARCHAR(100))");

        int nb = db.exec("UPDATE static_data SET start_time = \"" + start_time + "\"");
        std::cout << "INSERT INTO test VALUES (NULL, \"test\")\", returned " << nb << std::endl;

        // Commit transaction
        transaction.commit();
    } catch (std::exception& e) {
        std::cout << "exception: " << e.what() << std::endl;
    }
}

std::string DataStorage::GetStartTime() const
{
    return std::string();
}

void DataStorage::SetVodDirectory(const std::string& dir)
{
}

std::string DataStorage::GetVodDirectory() const
{
    return std::string();
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

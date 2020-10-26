#ifndef ENTRY_H
#define ENTRY_H
#include <string>

using std::string;

class Entry
{
    public:
        Entry();
        int getId() { return id; };
        void setId(int val) { id = val; };
        int getUserId() { return userId; };
        void setUserId(int val) { userId = val; };
        int getType() { return type; };
        void setType(int val) { type = val; };
        string getDescription() { return description; };
        void setDescription(string val) { description = val; };
        int getAmount() { return amount; };
        void setAmount(int val) { amount = val; };
        time_t getDate() { return date; };
        void setDate(time_t val) { date = val; };

    protected:

    private:
        int id;
        int userId;
        int type;
        string description;
        int amount;
        time_t date;
};

#endif // ENTRY_H

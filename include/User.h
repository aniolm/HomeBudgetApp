#ifndef USER_H
#define USER_H
#include <string>


using std::string;

class User
{
    public:
        User();
        virtual ~User();

        int getId() { return id; }
        void setId(int val) { id = val; }
        string getName() { return name; }
        void setName(string val) { name = val; }
        string getSurname() { return surname; }
        void setSurname(string val) { surname = val; }
        string getUsername() { return username; }
        void setUsername(string val) { username = val; }
        string getPassword() { return password; }
        void setPassword(string val) { password = val; }

    protected:

    private:
        int id;
        string name;
        string surname;
        string username;
        string password;
};

#endif // USER_H

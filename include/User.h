#ifndef USER_H
#define USER_H


class User
{
    public:
        User();
        virtual ~User();

        int GetId() { return id; }
        void SetId(int val) { id = val; }
        string GetName() { return name; }
        void SetName(string val) { name = val; }
        string GetSurname() { return surname; }
        void SetSurname(string val) { surname = val; }
        string GetUsername() { return username; }
        void SetUsername(string val) { username = val; }
        string GetPassword() { return password; }
        void SetPassword(string val) { password = val; }

    protected:

    private:
        int id;
        string name;
        string surname;
        string username;
        string password;
};

#endif // USER_H

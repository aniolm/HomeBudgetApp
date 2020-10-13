#include "UserFile.h"

UserFile::UserFile(string userFileName):USER_FILE_NAME(userFileName)
{

}



void UserFile::appendUserToFile(User user)
{
    CMarkup xml;
    xml.Load( USER_FILE_NAME );

    xml.AddElem( "USER" );
    xml.IntoElem();
    xml.AddElem("ID", user.getId());
    xml.AddElem( "NAME", user.getName());
    xml.AddElem( "SURNAME", user.getSurname());
    xml.AddElem("USERNAME", user.getUsername());
    xml.AddElem( "PASSWORD", user.getPassword());
    xml.Save( USER_FILE_NAME );

    return;
}

vector <User> UserFile::loadUsersFromFile()
{
    vector <User> users;
    User user;
    CMarkup xml;
    xml.Load( USER_FILE_NAME );

    while ( xml.FindElem("USER" ))
    {
    xml.IntoElem();
    xml.FindElem( "ID" );
    user.setId(  atoi( MCD_2PCSZ(xml.GetData()) ) );
    xml.FindElem( "NAME" );
    user.setName( xml.GetData() );
    xml.FindElem( "SURNAME" );
    user.setSurname( xml.GetData() );
    xml.FindElem( "USERNAME" );
    user.setUsername( xml.GetData() );
    xml.FindElem( "PASSWORD" );
    user.setPassword( xml.GetData() );
    xml.OutOfElem();
    users.push_back(user);
    }

    return users;

}

void UserFile::updateUserData(string field , string newData, int userId)
{
    CMarkup xml;
    xml.Load( USER_FILE_NAME );
    int xmlId = 0;
    while ( xml.FindElem("USER" ))
    {
    xml.IntoElem();
    xml.FindElem( "ID" );
    xmlId = atoi( MCD_2PCSZ(xml.GetData())) ;
    if (xmlId==userId)
    {
        xml.FindElem( field );
        xml.SetData( newData);
    }

    xml.OutOfElem();

    }
    xml.Save( USER_FILE_NAME );
    return;
}


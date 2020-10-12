#include "UserFile.h"

UserFile::UserFile()
{
    //ctor
}

UserFile::~UserFile()
{
    //dtor
}

void UserFile::appendUserToFile(User user)
{
    CMarkup xml;
    xml.Load( "UserFile.xml" );

    xml.AddElem( "USER" );
    xml.IntoElem();
    xml.AddElem("ID", user.getId());
    xml.AddElem( "NAME", user.getName());
    xml.AddElem( "SURNAME", user.getSurname());
    xml.AddElem("USERNAME", user.getUsername());
    xml.AddElem( "PASSWORD", user.getPassword());
    xml.Save( "UserFile.xml" );

    return;
}


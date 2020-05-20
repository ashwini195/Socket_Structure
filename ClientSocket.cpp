// Implementation of the ClientSocket class

#include "ClientSocket.h"
#include "SocketException.h"
#include <cstring>
#include <iostream>
#include <string>





ClientSocket::ClientSocket ( std::string host, int port )
{
  if ( ! Socket::create() )
    {
      throw SocketException ( "Could not create client socket." );
    }

  if ( ! Socket::connect ( host, port ) )
    {
      throw SocketException ( "Could not bind to port." );
    }

//for (int i = 0; i < count; ++i)
//{
  /* code */
}

ClientSocket& ClientSocket::operator << ( char* s ) 
{
 std::cout << " in client_socket.cpp insertion overload\n" <<std::endl;
 MSG* temp1 = new MSG;
 deserialize(s, temp1);
 printMsg(temp1);

  if ( ! Socket::send ( s ) )
    {
      throw SocketException ( "Could not write to socket." );
    }

  return *this;

}


ClientSocket& ClientSocket::operator >> ( char* s ) 
{



  if ( ! Socket::recv ( s ) )
    {
      throw SocketException ( "Could not read from socket." );
    }
 std::cout << " in client_socket.cpp extraction  overload\n" <<std::endl;
 MSG* temp1 = new MSG;
 deserialize(s, temp1);
 printMsg(temp1);
  return *this;
}
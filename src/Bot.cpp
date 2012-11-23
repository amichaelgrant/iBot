/* 
 * File:   Bot.cpp
 * Author: grant
 * 
 * Created on November 23, 2012, 3:00 PM
 */

#include <iostream>

#include "Bot.h"

Bot::Bot() {
    
    JID jid("michael.grant@10.0.0.19");
    client = new Client( jid, "123456" );

    client->registerMessageHandler( this );
    client->registerConnectionListener(this);
    client->registerPresenceHandler(this);

    client->connect(true);

}

Bot::Bot(const Bot& orig) {
}

Bot::~Bot() {
}

void Bot::init(){
    
}

void Bot::onConnect() {
    std::cout << "ConnectionListener::onConnect()" << endl;
}

void Bot::onDisconnect(ConnectionError e) {
    std::cout << "ConnectionListener::onDisconnect() " << e << endl;
}

bool Bot::onTLSConnect(const CertInfo& info) {
    std::cout << "ConnectionListener::onTLSConnect()" << endl;
    std::cout<<info.server<<endl;
    return true;
}

void Bot::handlePresence(const Presence& presence){
    std::cout<< "Another Bot has reported its presence"<<endl;
    std::cout<< presence.id()<<endl;
}

void Bot::handleLog( LogLevel level, LogArea area, const std::string& message )
{
    //printf("log: level: %d, area: %d, %s\n", level, area, message.c_str() );
    std::cout<<"Log: level: " <<level;
    std::cout<<"Area : "<<area;
    std::cout<<"Message: "<< message <<endl;
}

void Bot::handleMessage(const Message msg, MessageSession* session){
    std::cout<<"Received Message From:"<<msg.from()<<endl;
    std::cout<<"Message Body :"<<msg.body()<<endl;
    std::cout<<"Message Subject :"<<msg.subject()<<endl;
}

//void Bot::handleDataForm(const JID& from, const DataForm& form)
/* 
 * File:   Bot.h
 * Author: grant
 *
 * Created on November 23, 2012, 3:00 PM
 */

#ifndef BOT_H
#define	BOT_H
#include <iostream>
#include <gloox/gloox.h>
#include <gloox/messagehandler.h>
#include <gloox/message.h>
#include <gloox/connectionhandler.h>
#include <gloox/connectionlistener.h>
#include <gloox/registrationhandler.h>
#include <gloox/registration.h>
#include <gloox/tlshandler.h>
#include <gloox/presencehandler.h>
#include <gloox/rostermanager.h>
#include <gloox/client.h>

using namespace gloox;
using namespace std;

class Bot : public 
    RegistrationHandler,
    ConnectionListener,
    MessageHandler,
    TLSHandler,
    PresenceHandler,
    LogHandler
{

public:
    void init();
    void handleMessage( const Message msg, MessageSession *session = 0);
    void handleRegistrationFields(const JID& from,int fields, std::string instructions);
    void handleRegistrationResult(const JID& from, RegistrationResult regResult);
    void handleAlreadyRegistered(const JID& from);
    void handleDataForm(const JID& from, const DataForm& form);

    void handleLog(LogLevel level, LogArea area, const std::string& message);

    void onConnect();
    void onDisconnect(ConnectionError e);
    bool onTLSConnect(const CertInfo& info);

    void handlePresence(const Presence& presence);
public:
    Bot();
    Bot(const Bot& orig);
    virtual ~Bot();

private:
    Client *client;
};

#endif	/* BOT_H */


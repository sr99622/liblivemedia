/*******************************************************************************
* ProxyServer.h
*
* copyright 2024 Stephen Rhodes
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the
* Free Software Foundation; either version 3 of the License, or (at your
* option) any later version. (See <http://www.gnu.org/copyleft/lesser.html>.)
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for
* more details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA
*
*******************************************************************************/

#ifndef PROXY_SERVER_H
#define PROXY_SERVER_H

#define DEBUG

#include "liveMedia.hh"
#include "BasicUsageEnvironment.hh"
#include "GroupsockHelper.hh"
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <thread>

namespace liblivemedia
{

class MyClientConnection: public GenericMediaServer::ClientConnection {
public:
    struct sockaddr_storage* addr() { return &fClientAddr; }

};

class MyRTSPServer: public RTSPServer {
public:
    static MyRTSPServer* createNew(UsageEnvironment& env, Port ourPort = 554,
			       UserAuthenticationDatabase* authDatabase = NULL,
			       unsigned reclamationSeconds = 65) {
                    return (MyRTSPServer*) RTSPServer::createNew(env, ourPort, authDatabase, reclamationSeconds);
                   }

    std::vector<std::string> iterateClients() {
        std::cout << "iterate clients" << std::endl;
        std::vector<std::string> result;
        HashTable::Iterator* iter = HashTable::Iterator::create(*fClientSessions);
        RTSPServer::RTSPClientSession* clientSession;
        char const* key; // dummy
        
        while ((clientSession = (RTSPServer::RTSPClientSession*)(iter->next(key))) != NULL) {
                // do something with clientSession
                result.push_back(std::string("clientSession->fTrackId"));
        }
        delete iter; 
        return result;  
    }

    std::vector<std::string> iterateConnections() {
        std::cout << "iterate connections" << std::endl;
        std::vector<std::string> result;
        HashTable::Iterator* iter = HashTable::Iterator::create(*fClientConnections);
        RTSPServer::RTSPClientConnection* clientConnection;
        char const* key; // dummy
        
        while ((clientConnection = (RTSPServer::RTSPClientConnection*)(iter->next(key))) != NULL) {
                // do something with clientSession
                result.push_back(std::string("clientConnection"));
                struct sockaddr_storage* fClientAddr = ((MyClientConnection*)clientConnection)->addr();
                struct sockaddr_in* funk = (struct sockaddr_in*)fClientAddr;

                char *s = inet_ntoa(funk->sin_addr);
                printf("IP address: %s\n", s);

        }
        delete iter; 
        return result;  
    }

    std::vector<std::string> iterateMedia() {
        std::vector<std::string> result;
        GenericMediaServer::ServerMediaSessionIterator *iter = new GenericMediaServer::ServerMediaSessionIterator(*this);
        ServerMediaSession *sms = NULL;
        while((sms = (ServerMediaSession *)iter->next()) != NULL)  {
            if (sms) {
                std::cout << sms->streamName() << " : " << sms->numSubsessions() << std::endl;
                ServerMediaSubsessionIterator *sub_iter = new ServerMediaSubsessionIterator(*sms);
                ServerMediaSubsession* smsb = NULL;
                while ((smsb = sub_iter->next()) != NULL) {
                    if (smsb) {
                        std::cout << "FOUND SUB SESSION" << std::endl;
                    }
                }
                result.push_back(sms->streamName());
            }
            /*
            if (sms)  {
                if(strcmp(sms->streamName(), streamName) == 0)  {
                    m_rtspServer ->deleteServerMediaSession(sms);
                }
            }
            */
        }
        delete iter;
        return result;
    }        
            
};

class ProxyServer
{

public:
    UsageEnvironment* env = nullptr;
    TaskScheduler* scheduler = nullptr;
    MyRTSPServer* rtspServer = nullptr;
    char watchVariable = 0;
    bool running = false;

    std::map<std::string, std::string> uris;

    ~ProxyServer()
    {
        if (env) free(env);
        if (scheduler) free(scheduler);
        if (rtspServer) free(rtspServer);
    }

    ProxyServer(const std::string& ip, int port)
    {
        if (ip.length())
            ReceivingInterfaceAddr = inet_addr(ip.c_str());

        scheduler = BasicTaskScheduler::createNew();
        env = BasicUsageEnvironment::createNew(*scheduler);

        rtspServer = MyRTSPServer::createNew(*env, port, nullptr);
        if (!rtspServer) {
            port = 8554;
            rtspServer = MyRTSPServer::createNew(*env, port, nullptr);
        }
        if (!rtspServer) {
            throw std::runtime_error("Unable to create rtsp server");
        }
    }

    void addURI(const std::string& uri, const std::string& name, const std::string& username, const std::string& password)
    {
        ServerMediaSession* sms = ProxyServerMediaSession::createNew(*env, rtspServer, 
                                                                    uri.c_str(), name.c_str(), 
                                                                    username.c_str(), password.c_str(), 0, 0);

        rtspServer->addServerMediaSession(sms);
        std::string proxy = rtspServer->rtspURL(sms);
        uris[uri] = proxy;
        //rtspServer->iterateMedia();
    }

    std::vector<std::string> iterateMedia()
    {
        return rtspServer->iterateMedia();
    }

    std::vector<std::string> iterateClients()
    {
        return rtspServer->iterateClients();
    }

    std::vector<std::string> iterateConnections()
    {
        return rtspServer->iterateConnections();
    }

    std::string getRootURI() const 
    {
        return std::string(rtspServer->rtspURLPrefix());
    }

    void start()
    {
        running = true;
        std::thread thread([&]() { loop(); });
        thread.detach();
    }

    void loop()
    {
        watchVariable = 0;
        env->taskScheduler().doEventLoop(&watchVariable);
    }

    void stop()
    {
        watchVariable = ~0;
        running = false;
    }

    std::string getProxyURI(const std::string& uri) const
    {
        std::string result;

        for (auto element :uris) {
            if (element.first == uri) {
                result = element.second;
                break;
            }
        }

        return result;
    }
};

}

#endif // PROXY_SERVER_H


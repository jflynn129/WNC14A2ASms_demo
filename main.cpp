/* =====================================================================
   Copyright © 2016, Avnet (R)

   Contributors:
     * James M Flynn, www.em.avnet.com 
 
   Licensed under the Apache License, Version 2.0 (the "License"); 
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, 
   software distributed under the License is distributed on an 
   "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, 
   either express or implied. See the License for the specific 
   language governing permissions and limitations under the License.

    @file          WNCInterface.cpp
    @version       1.0
    @date          Sept 2016

======================================================================== */

// Touch to work-around mbed tag.

#include "mbed.h"
#include "WNC14A2AInterface.h"

#define MBED_PLATFORM

Serial pc(USBTX,USBRX);

void msg_rcvd( IOTSMS* msg ) {
  pc.printf("msg_rcvd called, msg from: '%s'\n", msg->number.c_str());
  pc.printf("msg_rcvd from: '%s'\n", msg->date.c_str());
  pc.printf("msg_rcvd at '%s'\n", msg->time.c_str());
  pc.printf("msg_rcvd contained '%s'\n\n", msg->msg.c_str());
}
    
int main() {
    int cnt=0;
    char buf[80];
    char nbr[25];
    string dest = "5277";

    IOTSMS **mp;
    IOTSMS ma[5];
    mp = (IOTSMS**)&ma;

    WNC14A2AInterface wnc;
    wnc.doDebug(0);

    pc.baud(9600);    
    pc.printf("\nSTARTING WNC SMS Test\n");
    
    cnt=wnc.getSMS( mp ); 
    wnc.connect();

    pc.printf(" WNC Initialized\n"); 

    wnc.sms_start();
    strncpy(nbr, wnc.getSMSnbr(), 25);  //get our IotSMS number
    pc.printf("My number: ");
    pc.printf("%s\n", nbr);

    pc.printf("-->Pausing 30 seconds then check for SMS received from the console\n");
    wait(30);
    cnt=wnc.getSMS( mp ); 
    pc.printf("Checked, there are %d SMS messages\n",cnt);
    for( int i=0; i<cnt; i++ ) {
        pc.printf("Msg #%02d:\n",i+1);
        pc.printf("msg from: '%s'\n", mp[i]->number.c_str());
        pc.printf(" on date: '%s'\n", mp[i]->date.c_str());
        pc.printf(" at time: '%s'\n", mp[i]->time.c_str());
        pc.printf("     msg: '%s'\n", mp[i]->msg.c_str());
        }
    pc.printf("\n");

    pc.printf("Start Monitoring thread to check every 10 seconds for incomming messages\n");
    wnc.sms_attach(msg_rcvd);   //Attach the function we want called when an SMS arrives
    wnc.sms_listen(10);         //and check for SMS messages every 10 seconds
    cnt = 1;

    while( 1 ) {
      pc.printf("sending SMS #%d to %s", cnt, dest.c_str() );
      sprintf(buf, "SMS #%d", cnt++);
      pc.printf("..GO;\n");
      wnc.sendIOTSms(dest.c_str(), buf);
      pc.printf("wait 60 seconds and check for incomming SMS msgs...\n");
      wait(60);
      }
}


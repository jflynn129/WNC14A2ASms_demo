WNC 14A2A Data Module Networking Library
========================================
 
This example shows how to use the WNC14A2A Network API that has been updated to support ARMmbed v5 with SMS messages. The example uses the AT&T IoT Kit which is sold by [[http://cloudconnectkits.org/product/att-cellular-iot-starter-kit|Avnet]]. 

__**NOTE:**__ Using SMS messages in conjunction with the AT&T IoT Kit are not standard SMS messages.  These messages are intended to send messages between IoT devices and services such as FLOW (https://flow.att.com/).  The SMS capability does not allow for interaction with a standard cellular phone number, instead, it uses a 15 digit MSIDN.  This 15 digit MSIDN is displayed to the user when the program starts.

1. Launch [[https://mbed.org/compiler/|mbed online compiler]] in your browser

2. Right clicking on "My Programs", the select "Import Program", followed by "From URL ..."

This will bring up a dialog for you to select the Source URL:. Enter [[https://github.com/jflynn129/WNC14A2ASms_demo]] ensuring Import As: Program is selected. Once "main.cpp" has been imported you will have a new entry in "My Programs" titled WNC14A2A_socket_example

3. Right click on the WNC14A2A_socket_example and again "Import Prgram" followed by "From URL ...". This time import the ARMmbed v5.x O/S from [[https://github.com/ARMmbed/mbed-os]]

4. Right click on the WNC14A2A_socket_example and again "Import Prgram" followed by "From URL ...". This time import the WNC14A2AInterface from [[https://github.com/jflynn129/WNC14A2AInterface]]

5. As a final step, click on the WNC14A2A_socket_example and again "Import Prgram" folloed by "From URL ..." then select [[https://developer.mbed.org/teams/Avnet/code/WncControllerK64F/]]. The library (which will blso ring includes the WncController class which implements the AT commands necessary to control the WNC14A2A module.

With all the components in-place, simply execute the **Compile** button.  There will be 225 warning and 
1 info message generated which is expected.  Copy the resulting 'WNC14A2A_socket_exampleK64F.bin' program
to your connect kit.

=Discussion=
SMS is provided in the WNC14A2AInterface class.  It provides APIs to:
* Start the SMS interface **sms_start()**.  This allows the WNC14A2A to begin processing SMS messages.
* getSMS is called to retrieve a SMS message that has been sent to the device.
* sendIOTSms allows the user to send an SMS message to another device on the IoT network.
* getSMSnbr will return the SMS ID/Number for this device
* sms_listen() is called so that the device will begin monitoring for incomming SMS messages at a user
specified interval.  If a call-back function is attached, it will be called when a message is received.  If 
a call-back function is not registered, nothing will be done with the SMS message.  The WNC14A2A can store a 
maximum of 3 messages.
* sms_attach() specifies the function that is to be called when an SMS message is received

Monitoring for an SMS is performed by starting a thread that executes at a user defined interval.  If no interval is
specified, 30 seconds is assumed.

==Expected execution outcome==

Once the program is compiled and downloaded to the IoT Kit, perform the following steps:

1. Using a terminal program such as Hyperterm or Putty, connect to the Kit (select comm parameters of 115200-N81)

2. Press the `reset` button, then you should see the program start running! When it runs, the output will look similar to:

<<code title=Sample Ouput>>
=Sample Output=

STARTING WNC SMS Test

Toggling Wakeup...

Toggling complete.

 WNC Initialized

 SMS Initialized

get my number: 882350201419599

sending SMS #1 to 5277..GO; waiting...

msg_rcvd called, msg from: '5277'

msg_rcvd from: '16/11/14'

msg_rcvd at '13:17:20-32'

msg_rcvd contained '"16/11/14,13:17:20-32",0'

sending SMS #2 to 5277..GO; msg_rcvd called, msg from: '5277'

msg_rcvd from: '16/11/14'

msg_rcvd at '13:17:41-32'

msg_rcvd contained '"16/11/14,13:17:41-32",0'

waiting...

sending SMS #3 to 5277..GO; waiting...

msg_rcvd called, msg from: '5277'

msg_rcvd from: '16/11/14'

msg_rcvd at '13:18:02-32'

msg_rcvd contained '"16/11/14,13:18:02-32",0'

.

.

.

sending SMS #64 to 5277..GO; waiting...

msg_rcvd called, msg from: '5277'

msg_rcvd from: '16/11/14'

msg_rcvd at '13:39:43-32'

msg_rcvd contained '"16/11/14,13:39:43-32",0'

msg_rcvd called, msg from: '5277'

msg_rcvd from: '16/11/14'

msg_rcvd at '13:39:46-32'

msg_rcvd contained 'This is a test...'


<</code>>

The message received at *13:39:46-32* was sent from the AT&T SIM Control Center to show receipt of an SMS.


WNC FIRWARE VERSION
===================
 
The WNCInterface class currently supports the following version(s):
* MPSS: M14A2A_v11.21.162331 APSS: M14A2A_v11.27.162331
 
 
License
=======
This library is released under the    Licensed under the Apache License, Version 2.0 (the "License"); you may not use this 
file except in compliance with the License and may obtain a copy of the License at
 
    http://www.apache.org/licenses/LICENSE-2.0
 
Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an 
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific 
language governing permissions and limitations under the License.
 
 

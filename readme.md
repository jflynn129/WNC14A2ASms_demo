WNC 14A2A Data Module Networking Library
========================================
 
The WDCInterface Library is an updated version that is compatible with the latest ARMmbed version--Mbed v5.  This API is 
implemented in C++ specifically for a Wistron NeWeb Corporation (WNC) M14A2A Series data module.  The WNC14A2AInterface
library implements and uses a WDC Controller class for communicating with the WNC device via a series of AT commands. 
This interface class is used in the AT&T Cellular IoT Starter Kit which is sold by Avnet 
(http://cloudconnectkits.org/product/att-cellular-iot-starter-kit) and can be used seamlessly for mbed v5 devices.
is a drop-in replacement for an EthernetInterface class.
 
Occasionally, the WNC Data Module will encounter internal failures that cause the device to cease communicating. To prevent
the system from unexpectedly hanging, the WNCInterface class has implemented three user configuration settings as described 
below:
 
1. Configure the WNCInterface for (1) debug enabled OR (2) disabled.  The default/current setting is debug enabled. When
debug is enabled, it opens stdio over the USB using the OpenSDA (serial over USB running at 115200-N81).
 
2. Configure the WNCInterface to either (1) Hang by executing a 'while(true)' loop when the error occurs OR (2) Have the 
WNCInterface return a Failure (-1) for the current and all subsequent calls.  The default/current setting is to
Hange execution.
 
3. Configure the WNCInterface to either (1) Display the failure location to the debug port OR (2) display nothing when
the error occurs.  The default/current setting is to display the failure location.
 
To create the complete WNCInterface class, you must also install the WncController class.  This is the hardware abstraction
layer utilized by WNCInterface to communicate wiht the hardware.  It is installed within the WNCInterface class from: 
https://developer.mbed.org/users/fkellermavnet/code/WncControllerK64F/
 
To demonstrate the use of the WDCInterface, a series of example programs have been developed.  Links to these examples
are provided below.
 
**NOTE**: This library/class is specific to the AT&T Cellular IoT Starter Kit which uses a FRDM-K64F.  The users mbed.org 
compiler should be configured to use the FRDM-K64F platform.
 
Example Programs
================
 
Import the example programs below and follow the README.md in each to run the example program.
 
  * https://github.com/jflynn129/WNCInterface_HTTP
  * https://github.com/jflynn129/WNCInterface_M2Xdemo
  * https://github.com/jflynn129/WNCInterface_M2XMQTTdemo
  * https://github.com/jflynn129/WNCInterface_MQTT_hivemq
 
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
 
 
            

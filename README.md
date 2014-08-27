design2-transceiver
===================

BlackChat Wireless Communication Client
By Russell Crowe & Patrick Lloyd

###Premise:
In many situations it is necessary to sent text communication and transfer files discretely between two computers. With the recent exposure of warrantless government wiretapping protecting one's privacy more difficult than ever. The purpose of BlackChat is to create a secure, discrete, and plausibly deniable point-to-point communication system for text (and maybe files?) between two or more computers. Ideally this will be entered in the TI Innovation Challenge for the 2014 year.

###TODO:
1) Primary research
  * Frequencies on which to operate
    * Low power / low frequencies most desirable but may require excessively large antennae
    * 900 MHz / 2.4 GHz ISM bands worth looking into
  * Legality of transferring encrypted messages over those bands
  * Can we use TI's monolithic RF solutions or would we need to design our own?
 
2) High level system design
  * Functional blocks
    * Text communication first priority
    * Linux support first priority
    * Will it support file transfer?
    * Discovery / networking / group chat?
    * Audio recording & transmission?
  * Power requrements
  * Size constraints
    * Rev. 1 -- big; make sure device functions as advertised
    * Subsequent revs -- Focus effort on decreasing size
  
3) Hardware design
  * Stress adequate analog design component
  * Part selection
    * Mostly TI components for contest
    * Alpha rev vs. final rev part sizes
      * Large, easy to solder parts in prototyping stage
      * Ideally use same part with smaller package in Final
  
4) Software design
  * Firmware side
    * Packet encryption
    * USB <--> USART functionality
    * Transmission protocol (error checking & correction, etc.)
    * Broadcasting and discovery
  * Interface side
    * Linux toolchains for MSP
    * High focus on Linux compatibility
    * Terminal (Bash) or C++ (stdout) application with expandability to a GUI, time permitting

5) Implementation and Testing
  * [Not Applicable]

6) Revisions & Compromises
  * [Not Applicable]

# MQTT Subscribe in C using libmosquitto

This program use C language to communicate with MQTT protocol. 
libmosquitto is the library being used. 
This is based on single.c from libmosquitto example

NOTE: I'm using QT Creator, so you might want to edit the CMakeLists.txt little bit

## install libmosquitto
1. (recomended) you can check the tutorial from this site https://mosquitto.org/blog/2012/11/making-mosquitto-packages-for-debian-yourself/
2. choose yout mosquitto version from http://mosquitto.org/files/source
3. download your mosquitto
4. install the dependencies using
```bash
sudo apt-get install build-essential python quilt libwrap0-dev libssl-dev devscripts python-setuptools
```
5. extract your mosquitto, then goto your extracted directory. open terminal in this directory
6. create a build directory, then goto your directory
```bash
mkdir build
cd build
```
7. configure your installation, you can change your prefix (installation folder) in this step, by default it is in  /usr/local/
```bash
ccmake ..
```
8. make and install mosquitto, if you have 8 cores use -j8
```bash
make -j8
make install
sudo sh -c 'echo "<your_installation_directory>" > /etc/ld.so.conf.d/mosquitto-<your_mosquitto_version>.conf'
sudo ldconfig
```
8. dont forget to add " -L/<your_installation_directory>/lib -lmosquittopp -lmosquitto " to your project

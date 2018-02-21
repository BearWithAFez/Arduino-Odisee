UnoArduSimV1.2 README

When you first run UnoArduSim.exe, you will see a default set of I/O devices (one of each of the "big" I/O devices, and several of each of the "small" I/O devices), and a dummy "simple.ino" default program which you can immediately run.

You can use the Configure menu to adjust the set of I/O devices, and from the provided dialog "Save" that configuration for next time (as a named text file). That file name will be automatically added to the myArduPrefs.txt file that gets loaded at the next program startup -- to go back to the default startup configuration, delete the IODevs line in the myArduPrefs.txt file (or just delete that entire file).

When ready, you can load and try out the provided ItchyAndScratchy.ino demo program -- that program needs to have a particular set of I/O devices attached, so use "Configure->IO Devices" and "Load" the myUnoDevs_ItchyAndScratchy.txt file. That will load the devices (with pre-set pin connections) that are needed by the ItchyAndScratchy.ino program. Run it and you'll see that I'm a big fan of the Simpsons!

